/**
 * @author      : nathan (nathan@$HOSTNAME)
 * @file        : Genome
 * @created     : Sunday May 03, 2020 15:53:32 PDT
 */

#ifndef GENOME_H
#define GENOME_H

#include <utility>
#include "InstructionLibrary.h"
#include "Config.h"

class Genome{
public:
  Genome(emp::Random& random): 
    random(random)
  {
    ResetProgram();
  }
  void Tick(){}
  void ResetProgram()
  {
    program = Config::program_t(sgp::GenRandLinearFunctionsProgram<Config::hardware_t, Config::TAG_WIDTH>(
          random
          , InstructionLibrary::Instance()->GetInstLib()
          , {Config::MIN_NUM_FUNC, Config::MAX_NUM_FUNC}
          , Config::NUM_FUNC_TAGS
          , {Config::MIN_INST_CNT, Config::MAX_INST_CNT}
          , Config::NUM_INST_TAGS
          , Config::NUM_INST_ARGS
          , {Config::MIN_ARG_VAL, Config::MAX_ARG_VAL}));
  }

  std::pair<size_t, size_t> GetPosition () const 
  {
    return position;
  }

  void PrintProgram()
  {
    program.Print(std::cout, InstructionLibrary::Instance()->GetInstLib()); 
  }

private:
  std::pair<size_t, size_t> position = {0, 0}; 
  Config::program_t program;
  emp::Random random;
};


#endif /* end of include guard GENOME_H */

