/******************************************************************************

Copyright (c) 2016-2022 VMware, Inc.
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

    1. Redistributions of source code must retain the above copyright notice,
       this list of conditions and the following disclaimer.

    2. Redistributions in binary form must reproduce the above copyright
       notice, this list of conditions and the following disclaimer in the
       documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

******************************************************************************/

#if !defined(_VMACCEL_MANAGER_H_)
#define _VMACCEL_MANAGER_H_

#include <stdbool.h>
#include "vmaccel_rpc.h"

/*
 * Functions exported to the C interface from C++.
 */
#ifdef __cplusplus
extern "C" {
#endif

unsigned int vmaccel_manager_poweron();
unsigned int vmaccel_manager_poweroff();
VMAccelAllocateStatus *vmaccel_manager_register(VMAccelDesc *desc);
VMAccelStatus *vmaccel_manager_unregister(VMAccelId id);
VMAccelAllocateStatus *vmaccel_manager_alloc(VMAccelDesc *desc);
VMAccelStatus *vmaccel_manager_free(VMAccelId id);
bool vmaccel_manager_wait_for_fence(VMAccelId id);

#ifdef __cplusplus
}
#endif

#endif /* defined _VMACCEL_MANAGER_H_ */
