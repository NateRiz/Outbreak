/**
 * @author      : nathan (nathan@$HOSTNAME)
 * @file        : InstructionLibrary
 * @created     : Sunday Jun 14, 2020 16:12:52 PDT
 */

#ifndef INSTRUCTIONLIBRARY_H

#define INSTRUCTIONLIBRARY_H

#include "Config.h"


class InstructionLibrary{
  public:
    static InstructionLibrary* Instance()
    {
      static InstructionLibrary* singleton = new InstructionLibrary();
      return singleton;
    }
   
    void CreateInstLib()
    {
      AddDefaultInstructions();
      AddCustomInstructions();
    }

    Config::inst_lib_t& GetInstLib()
    {
      return inst_lib;
    }
    
  private:
    
    InstructionLibrary()=default;

    void AddDefaultInstructions()
    {
      inst_lib.AddInst("Nop", [](Config::hardware_t & hw, const Config::inst_t & inst) { ; }, "No operation!");
      inst_lib.AddInst("Inc", sgp::inst_impl::Inst_Inc<Config::hardware_t, Config::inst_t>, "Increment!");
      inst_lib.AddInst("Dec", sgp::inst_impl::Inst_Dec<Config::hardware_t, Config::inst_t>, "Decrement!");
      inst_lib.AddInst("Not", sgp::inst_impl::Inst_Not<Config::hardware_t, Config::inst_t>, "Logical not of ARG[0]");
      inst_lib.AddInst("Add", sgp::inst_impl::Inst_Add<Config::hardware_t, Config::inst_t>, "");
      inst_lib.AddInst("Sub", sgp::inst_impl::Inst_Sub<Config::hardware_t, Config::inst_t>, "");
      inst_lib.AddInst("Mult", sgp::inst_impl::Inst_Mult<Config::hardware_t, Config::inst_t>, "");
      inst_lib.AddInst("Div", sgp::inst_impl::Inst_Div<Config::hardware_t, Config::inst_t>, "");
      inst_lib.AddInst("Mod", sgp::inst_impl::Inst_Mod<Config::hardware_t, Config::inst_t>, "");
      inst_lib.AddInst("TestEqu", sgp::inst_impl::Inst_TestEqu<Config::hardware_t, Config::inst_t>, "");
      inst_lib.AddInst("TestNEqu", sgp::inst_impl::Inst_TestNEqu<Config::hardware_t, Config::inst_t>, "");
      inst_lib.AddInst("TestLess", sgp::inst_impl::Inst_TestLess<Config::hardware_t, Config::inst_t>, "");
      inst_lib.AddInst("TestLessEqu", sgp::inst_impl::Inst_TestLessEqu<Config::hardware_t, Config::inst_t>, "");
      inst_lib.AddInst("TestGreater", sgp::inst_impl::Inst_TestGreater<Config::hardware_t, Config::inst_t>, "");
      inst_lib.AddInst("TestGreaterEqu", sgp::inst_impl::Inst_TestGreaterEqu<Config::hardware_t, Config::inst_t>, "");
      inst_lib.AddInst("SetMem", sgp::inst_impl::Inst_SetMem<Config::hardware_t, Config::inst_t>, "");
      inst_lib.AddInst("Close", sgp::inst_impl::Inst_Close<Config::hardware_t, Config::inst_t>, "", {Config::inst_prop_t::BLOCK_CLOSE});
      inst_lib.AddInst("Break", sgp::inst_impl::Inst_Break<Config::hardware_t, Config::inst_t>, "");
      inst_lib.AddInst("Call", sgp::inst_impl::Inst_Call<Config::hardware_t, Config::inst_t>, "");
      inst_lib.AddInst("Return", sgp::inst_impl::Inst_Return<Config::hardware_t, Config::inst_t>, "");
      inst_lib.AddInst("CopyMem", sgp::inst_impl::Inst_CopyMem<Config::hardware_t, Config::inst_t>, "");
      inst_lib.AddInst("SwapMem", sgp::inst_impl::Inst_SwapMem<Config::hardware_t, Config::inst_t>, "");
      inst_lib.AddInst("InputToWorking", sgp::inst_impl::Inst_InputToWorking<Config::hardware_t, Config::inst_t>, "");
      inst_lib.AddInst("WorkingToOutput", sgp::inst_impl::Inst_WorkingToOutput<Config::hardware_t, Config::inst_t>, "");
      inst_lib.AddInst("WorkingToGlobal", sgp::inst_impl::Inst_WorkingToGlobal<Config::hardware_t, Config::inst_t>, "");
      inst_lib.AddInst("GlobalToWorking", sgp::inst_impl::Inst_GlobalToWorking<Config::hardware_t, Config::inst_t>, "");
      inst_lib.AddInst("Fork", sgp::inst_impl::Inst_Fork<Config::hardware_t, Config::inst_t>, "");
      inst_lib.AddInst("Terminate", sgp::inst_impl::Inst_Terminate<Config::hardware_t, Config::inst_t>, "");
      inst_lib.AddInst("If", sgp::lfp_inst_impl::Inst_If<Config::hardware_t, Config::inst_t>, "", {Config::inst_prop_t::BLOCK_DEF});
      inst_lib.AddInst("While", sgp::lfp_inst_impl::Inst_While<Config::hardware_t, Config::inst_t>, "", {Config::inst_prop_t::BLOCK_DEF});
      inst_lib.AddInst("Countdown", sgp::lfp_inst_impl::Inst_Countdown<Config::hardware_t, Config::inst_t>, "", {Config::inst_prop_t::BLOCK_DEF});
      inst_lib.AddInst("Routine", sgp::lfp_inst_impl::Inst_Routine<Config::hardware_t, Config::inst_t>, "");
    }
    
    void AddCustomInstructions(){}
    
    Config::inst_lib_t inst_lib;
    
};



#endif /* end of include guard INSTRUCTIONLIBRARY_H */

