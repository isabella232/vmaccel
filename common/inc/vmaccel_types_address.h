/******************************************************************************

Copyright (c) 2016-2019 VMware, Inc.
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

#ifndef _VMACCEL_TYPES_ADDRESS_H_
#define _VMACCEL_TYPES_ADDRESS_H_ 1

#include <arpa/inet.h>
#include <assert.h>
#include <string.h>

#include "log_level.h"

#if DEBUG_ACCEL_ADDRESS
inline void Log_VMAccelAddress(const char *prefix, const VMAccelAddress *addr) {
   char str[256];

   if (VMAccelAddressOpaqueAddrToString(addr, str, sizeof(str))) {
      Log("%s addr=<%s>\n", prefix, str);
   } else {
      Log("%s addr=n/a\n", prefix);
   }
   Log("%s port=%u\n", prefix, addr->port);
   Log("%s resourceTypeMask=%u\n", prefix, addr->resourceTypeMask);
}
#endif

#endif /* defined _VMACCEL_TYPES_ADDRESS_H_ */
