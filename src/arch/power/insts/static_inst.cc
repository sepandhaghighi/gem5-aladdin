/*
 * Copyright (c) 2009 The University of Edinburgh
 * Copyright (c) 2013 Advanced Micro Devices, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met: redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer;
 * redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution;
 * neither the name of the copyright holders nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Authors: Timothy M. Jones
 */

#include "arch/power/insts/static_inst.hh"
#include "cpu/reg_class.hh"

using namespace PowerISA;

void
PowerStaticInst::printReg(std::ostream &os, int reg) const
{
    RegIndex rel_reg;

    switch (regIdxToClass(reg, &rel_reg)) {
      case IntRegClass:
        ccprintf(os, "r%d", rel_reg);
        break;
      case FloatRegClass:
        ccprintf(os, "f%d", rel_reg);
        break;
      case MiscRegClass:
        switch (rel_reg) {
          case 0: ccprintf(os, "cr"); break;
          case 1: ccprintf(os, "xer"); break;
          case 2: ccprintf(os, "lr"); break;
          case 3: ccprintf(os, "ctr"); break;
          default: ccprintf(os, "unknown_reg");
            break;
        }
    }
}

std::string
PowerStaticInst::generateDisassembly(Addr pc,
                                       const SymbolTable *symtab) const
{
    std::stringstream ss;

    ccprintf(ss, "%-10s ", mnemonic);

    return ss.str();
}
