/**
 * @author      : nathan (nathan@$HOSTNAME)
 * @file        : OutbreakWorld
 * @created     : Sunday May 03, 2020 16:45:26 PDT
 */

#ifndef OUTBREAKWORLD_H

#define OUTBREAKWORLD_H

#include <vector>
using std::vector;

#include "Config.h"
#include "Genome.h"

class OutbreakWorld{
public:
  OutbreakWorld()=default;
  void Start(){}

private:
  std::vector<Genome> genomes{Config::POPULATION_SIZE};
};




#endif /* end of include guard OUTBREAKWORLD_H */

