/**
 * @author      : nathan (nathan@$HOSTNAME)
 * @file        : OutbreakWorld
 * @created     : Sunday May 03, 2020 16:45:26 PDT
 */

#ifndef OUTBREAKWORLD_H

#define OUTBREAKWORLD_H

#include <vector>
#include <iostream>
using std::vector;
#include "Config.h"
#include "Genome.h"
#include "InstructionLibrary.h"


class OutbreakWorld{
public:
  OutbreakWorld():
    random(emp::Random(Config::RANDOM_SEED))
  {
    InstructionLibrary::Instance()->CreateInstLib();
  };
  void Start()
  {
    ResetPopulation();
    while(generation < Config::MAX_GENERATIONS || Config::MAX_GENERATIONS == 0)
    {
      Tick();break;
    }
  }


private:
  void Tick()
  {
    ++generation;
    for (auto g : genomes)
    {
      for(size_t t = 0; t < Config::TICKS_PER_UPDATE; ++t)
      {
        g.Tick();
        g.PrintProgram();
      } 
    }
  }
  void ResetPopulation()
  {
    genomes.clear();
    for(size_t i = 0; i < Config::POPULATION_SIZE; ++i)
    {
      genomes.emplace_back(random);
    }
  }


  emp::Random random;
  std::vector<Genome> genomes;
  size_t generation = 0;
};




#endif /* end of include guard OUTBREAKWORLD_H */

