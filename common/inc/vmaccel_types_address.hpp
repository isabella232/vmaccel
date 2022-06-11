/******************************************************************************

Copyright (c) 2019-2020 VMware, Inc.
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

#ifndef _VMACCEL_TYPES_ADDRESS_HPP_
#define _VMACCEL_TYPES_ADDRESS_HPP_ 1

static void Constructor(VMAccelAddress &obj) {
   obj.addr.addr_len = 0;
   obj.addr.addr_val = NULL;
   obj.port = 0;
   obj.resourceType = 0;
}

static void Destructor(VMAccelAddress &obj) {
   free(obj.addr.addr_val);
   obj.addr.addr_val = NULL;
}

static void DeepCopy(VMAccelAddress &lhs, const VMAccelAddress &rhs) {
   if (&lhs != &rhs) {
      if (lhs.addr.addr_len != 0) {
         free(lhs.addr.addr_val);
      }
      lhs.addr.addr_len = rhs.addr.addr_len;
      if (rhs.addr.addr_len != 0) {
         lhs.addr.addr_val = (char *)malloc(rhs.addr.addr_len * sizeof(char));
         if (lhs.addr.addr_val != NULL) {
            memcpy(lhs.addr.addr_val, rhs.addr.addr_val,
                   rhs.addr.addr_len * sizeof(char));
         }
      } else {
         lhs.addr.addr_val = NULL;
      }
      lhs.port = rhs.port;
      lhs.resourceType = rhs.resourceType;
   }
}

static void Move(VMAccelAddress &lhs, VMAccelAddress &rhs) {
   if (&lhs != &rhs) {
      lhs.addr.addr_len = rhs.addr.addr_len;
      /*
       * The following line causes a Valgrind warning:
       *
       *   Conditional jump or move depends on uninitialised value(s)
       *
       * This is avoided by memset of objects for VMAccelObject to zero on
       * construction.
       */
      free(lhs.addr.addr_val);
      lhs.addr.addr_val = rhs.addr.addr_val;
      lhs.port = rhs.port;
      lhs.resourceType = rhs.resourceType;
      memset(&rhs, 0, sizeof(rhs));
   }
}

#endif /* defined _VMACCEL_TYPES_ADDRESS_HPP_ */
