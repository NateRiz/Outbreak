/**
 * @author      : nathan (nathan@$HOSTNAME)
 * @file        : Config
 * @created     : Sunday May 03, 2020 16:31:59 PDT
 */

#ifndef CONFIG_H

#define CONFIG_H

#include "tools/BitSet.h"
#include "tools/Range.h"
#include "EventLibrary.h"
#include "SignalGPBase.h"
#include "impls/SignalGPToy.h"
#include "impls/SignalGPLinearProgram.h"
#include "impls/SignalGPLinearFunctionsProgram.h"
#include "utils/InstructionLibrary.h"
#include "utils/linear_program_instructions_impls.h"
#include "utils/linear_functions_program_instructions_impls.h"
#include "utils/MemoryModel.h"
#include "utils/LinearFunctionsProgram.h"

class Config{
public:
  Config()=default;

  static constexpr size_t POPULATION_SIZE = 1000;
  static constexpr size_t MAX_GENERATIONS = 10000;
  static constexpr size_t TICKS_PER_UPDATE = 20;
  static constexpr size_t TAG_WIDTH = 16;
  static constexpr int RANDOM_SEED = 1;
  
  static constexpr size_t NUM_FUNC_TAGS = 1;
  static constexpr size_t MIN_NUM_FUNC = 2;
  static constexpr size_t MAX_NUM_FUNC = 32;
  static constexpr size_t NUM_INST_TAGS = 1;
  static constexpr size_t NUM_INST_ARGS = 3;
  static constexpr size_t MIN_ARG_VAL = 0;
  static constexpr size_t MAX_ARG_VAL = 3;
  static constexpr size_t MIN_INST_CNT = 1;
  static constexpr size_t MAX_INST_CNT = 16;

  using mem_model_t = sgp::SimpleMemoryModel;
  using tag_t = emp::BitSet<Config::TAG_WIDTH>;
  using arg_t = int;
  using matchbin_t = emp::MatchBin<size_t, emp::HammingMetric<Config::TAG_WIDTH>, emp::RankedSelector<>, emp::AdditiveCountdownRegulator<>>;
  using hardware_t = sgp::LinearFunctionsProgramSignalGP<mem_model_t, tag_t, arg_t, matchbin_t>;
  using inst_lib_t = typename hardware_t::inst_lib_t;
  using program_t = typename hardware_t::program_t;
  using inst_t = typename hardware_t::inst_t;
  using inst_prop_t = typename hardware_t::InstProperty;
};


#endif /* end of include guard CONFIG_H */

