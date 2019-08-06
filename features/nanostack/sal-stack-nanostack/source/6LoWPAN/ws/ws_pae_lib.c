/*
 * Copyright (c) 2018-2019, Arm Limited and affiliates.
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "nsconfig.h"
#include <string.h>
#include "ns_types.h"
#include "ns_list.h"
#include "ns_trace.h"
#include "nsdynmemLIB.h"
#include "fhss_config.h"
#include "NWK_INTERFACE/Include/protocol.h"
#include "6LoWPAN/ws/ws_config.h"
#include "Security/kmp/kmp_addr.h"
#include "Security/kmp/kmp_api.h"
#include "Security/protocols/sec_prot_certs.h"
#include "Security/protocols/sec_prot_keys.h"
#include "6LoWPAN/ws/ws_pae_timers.h"
#include "6LoWPAN/ws/ws_pae_lib.h"

#ifdef HAVE_WS

#define TRACE_GROUP "wspl"

void ws_pae_lib_kmp_list_init(kmp_list_t *kmp_list)
{
    ns_list_init(kmp_list);
}

kmp_entry_t *ws_pae_lib_kmp_list_add(kmp_list_t *kmp_list, kmp_api_t *kmp)
{
    // Already in list
    kmp_entry_t *entry = ws_pae_lib_kmp_list_entry_get(kmp_list, kmp);
    if (entry) {
        return entry;
    }

    entry = ns_dyn_mem_alloc(sizeof(kmp_entry_t));
    if (!entry) {
        return NULL;
    }
    entry->kmp = kmp;
    entry->timer_running = false;

    ns_list_add_to_end(kmp_list, entry);

    return entry;
}

int8_t ws_pae_lib_kmp_list_delete(kmp_list_t *kmp_list, kmp_api_t *kmp)
{
    kmp_entry_t *entry = ws_pae_lib_kmp_list_entry_get(kmp_list, kmp);

    if (entry) {
        ns_list_remove(kmp_list, entry);
        kmp_api_delete(entry->kmp);
        ns_dyn_mem_free(entry);
        return 0;
    }

    return -1;
}

kmp_api_t *ws_pae_lib_kmp_list_type_get(kmp_list_t *kmp_list, kmp_type_e type)
{
    ns_list_foreach(kmp_entry_t, cur, kmp_list) {
        if (kmp_api_type_get(cur->kmp) == type) {
            return cur->kmp;
        }
    }

    return 0;
}

void ws_pae_lib_kmp_list_free(kmp_list_t *kmp_list)
{
    ns_list_foreach_safe(kmp_entry_t, cur, kmp_list) {
        kmp_api_delete(cur->kmp);
        ns_dyn_mem_free(cur);
    }
}

kmp_entry_t *ws_pae_lib_kmp_list_entry_get(kmp_list_t *kmp_list, kmp_api_t *kmp)
{
    ns_list_foreach(kmp_entry_t, cur, kmp_list) {
        if (cur->kmp == kmp) {
            return cur;
        }
    }

    return 0;
}

void ws_pae_lib_kmp_timer_start(kmp_list_t *kmp_list, kmp_entry_t *entry)
{
    if (ns_list_get_first(kmp_list) != entry) {
        ns_list_remove(kmp_list, entry);
        ns_list_add_to_start(kmp_list, entry);
    }
    entry->timer_running = true;
}

void ws_pae_lib_kmp_timer_stop(kmp_list_t *kmp_list, kmp_entry_t *entry)
{
    if (ns_list_get_last(kmp_list) != entry) {
        ns_list_remove(kmp_list, entry);
        ns_list_add_to_end(kmp_list, entry);
    }
    entry->timer_running = false;
}

bool ws_pae_lib_kmp_timer_update(kmp_list_t *kmp_list, uint16_t ticks, ws_pae_lib_kmp_timer_timeout timeout)
{
    if (ns_list_is_empty(kmp_list)) {
        return false;
    }

    bool timer_running = false;

    ns_list_foreach_safe(kmp_entry_t, entry, kmp_list) {
        if (entry->timer_running) {
            timeout(entry->kmp, ticks);
            timer_running = true;
        } else {
            break;
        }
    }

    return timer_running;
}

void ws_pae_lib_supp_list_init(supp_list_t *supp_list)
{
    ns_list_init(supp_list);
}

supp_entry_t *ws_pae_lib_supp_list_add(supp_list_t *supp_list, const kmp_addr_t *addr)
{
    supp_entry_t *entry = ns_dyn_mem_alloc(sizeof(supp_entry_t));

    if (!entry) {
        return NULL;
    }

    ws_pae_lib_supp_init(entry);
    memset(&entry->addr, 0, sizeof(kmp_addr_t));
    entry->addr.type = KMP_ADDR_EUI_64_AND_IP;
    kmp_address_copy(&entry->addr, addr);

    ns_list_add_to_end(supp_list, entry);

    return entry;
}

int8_t ws_pae_lib_supp_list_remove(supp_list_t *supp_list, supp_entry_t *supp)
{
    ns_list_remove(supp_list, supp);

    ws_pae_lib_supp_delete(supp);

    ns_dyn_mem_free(supp);
    return 0;
}

supp_entry_t *ws_pae_lib_supp_list_entry_eui_64_get(const supp_list_t *supp_list, const uint8_t *eui_64)
{
    ns_list_foreach(supp_entry_t, cur, supp_list) {
        if (memcmp(cur->addr.eui_64, eui_64, 8) == 0) {
            return cur;
        }
    }

    return 0;
}

void ws_pae_lib_supp_list_delete(supp_list_t *supp_list)
{
    ns_list_foreach_safe(supp_entry_t, entry, supp_list) {
        ws_pae_lib_supp_list_remove(supp_list, entry);
    }
}

bool ws_pae_lib_supp_list_timer_update(supp_list_t *active_supp_list, supp_list_t *inactive_supp_list, uint16_t ticks, ws_pae_lib_kmp_timer_timeout timeout)
{
    bool timer_running = false;

    ns_list_foreach_safe(supp_entry_t, entry, active_supp_list) {
        bool running = ws_pae_lib_supp_timer_update(entry, ticks, timeout);
        if (running) {
            timer_running = true;
        } else {
            ws_pae_lib_supp_list_to_inactive(active_supp_list, inactive_supp_list, entry);
        }
    }

    return timer_running;
}

void ws_pae_lib_supp_list_slow_timer_update(supp_list_t *supp_list, timer_settings_t *timer_settings, uint16_t seconds)
{
    ns_list_foreach(supp_entry_t, entry, supp_list) {
        if (sec_prot_keys_pmk_lifetime_decrement(&entry->sec_keys, timer_settings->pmk_lifetime, seconds)) {
            tr_info("PMK and PTK expired, eui-64: %s, system time: %"PRIu32"", trace_array(entry->addr.eui_64, 8), protocol_core_monotonic_time / 10);
        }
        if (sec_prot_keys_ptk_lifetime_decrement(&entry->sec_keys, timer_settings->ptk_lifetime, seconds)) {
            tr_info("PTK expired, eui-64: %s, system time: %"PRIu32"", trace_array(entry->addr.eui_64, 8), protocol_core_monotonic_time / 10);
        }
    }

}

void ws_pae_lib_supp_init(supp_entry_t *entry)
{
    ws_pae_lib_kmp_list_init(&entry->kmp_list);
    memset(&entry->addr, 0, sizeof(kmp_addr_t));
    memset(&entry->sec_keys, 0, sizeof(sec_prot_keys_t));
    entry->ticks = 0;
    entry->retry_ticks = 0;
    entry->active = true;
    entry->access_revoked = false;
}

void ws_pae_lib_supp_delete(supp_entry_t *entry)
{
    ws_pae_lib_kmp_list_free(&entry->kmp_list);
}

bool ws_pae_lib_supp_timer_update(supp_entry_t *entry, uint16_t ticks, ws_pae_lib_kmp_timer_timeout timeout)
{
    // Updates KMP timers and calls timeout callback
    bool keep_timer_running = ws_pae_lib_kmp_timer_update(&entry->kmp_list, ticks, timeout);

    // If KMPs are not active updates supplicant timer
    if (!keep_timer_running) {
        if (entry->ticks > ticks) {
            keep_timer_running = true;
            entry->ticks -= ticks;
        } else {
            entry->ticks = 0;
            entry->retry_ticks = 0;
        }
    }

    // Updates retry timer
    if (entry->retry_ticks > ticks) {
        entry->retry_ticks -= ticks;
    } else {
        if (entry->retry_ticks > 0) {
            tr_info("EAP-TLS max ongoing delay timeout eui-64: %s", trace_array(entry->addr.eui_64, 8));
        }
        entry->retry_ticks = 0;
    }

    return keep_timer_running;
}

void ws_pae_lib_supp_timer_ticks_set(supp_entry_t *entry, uint32_t ticks)
{
    entry->ticks = ticks;
}

void ws_pae_lib_supp_list_to_active(supp_list_t *active_supp_list, supp_list_t *inactive_supp_list, supp_entry_t *entry)
{
    if (entry->active) {
        return;
    }

    tr_debug("PAE: to active, eui-64: %s", trace_array(entry->addr.eui_64, 8));

    ns_list_remove(inactive_supp_list, entry);
    ns_list_add_to_start(active_supp_list, entry);

    entry->active = true;
    entry->ticks = 0;

    // Adds relay address data
    entry->addr.type = KMP_ADDR_EUI_64_AND_IP;
}

void ws_pae_lib_supp_list_to_inactive(supp_list_t *active_supp_list, supp_list_t *inactive_supp_list, supp_entry_t *entry)
{
    if (!entry->active) {
        return;
    }

    tr_debug("PAE: to inactive, eui-64: %s", trace_array(entry->addr.eui_64, 8));

    if (entry->access_revoked) {
        tr_info("Access revoked; deleted, eui-64: %s", trace_array(entry->addr.eui_64, 8));
        ws_pae_lib_supp_list_remove(active_supp_list, entry);
        return;
    }

    ns_list_remove(active_supp_list, entry);
    ns_list_add_to_start(inactive_supp_list, entry);

    entry->active = false;
    entry->ticks = 0;

    // Removes relay address data
    entry->addr.type = KMP_ADDR_EUI_64;
    entry->addr.port = 0;
    memset(entry->addr.relay_address, 0, 16);
}

uint16_t ws_pae_lib_supp_list_kmp_count(supp_list_t *supp_list, kmp_type_e type)
{
    uint16_t kmp_count = 0;

    ns_list_foreach(supp_entry_t, entry, supp_list) {
        ns_list_foreach(kmp_entry_t, kmp_entry, &entry->kmp_list) {
            if (kmp_api_type_get(kmp_entry->kmp) == type) {
                kmp_count++;
            }
        }
    }

    return kmp_count;
}

supp_entry_t *ws_pae_lib_supp_list_entry_retry_timer_get(supp_list_t *supp_list)
{
    supp_entry_t *retry_supp = NULL;

    ns_list_foreach(supp_entry_t, entry, supp_list) {
        // Finds entry with shortest timeout i.e. oldest one
        if (entry->retry_ticks > 0) {
            if (!retry_supp || retry_supp->retry_ticks > entry->retry_ticks) {
                retry_supp = entry;
            }
        }
    }

    return retry_supp;
}

#endif /* HAVE_WS */
