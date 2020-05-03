/**
 * @author      : nathan (nathan@$HOSTNAME)
 * @file        : Genome
 * @created     : Sunday May 03, 2020 15:53:32 PDT
 */

#ifndef GENOME_H
#define GENOME_H

#include <utility>

class Genome{
public:
  Genome() = default;
  void Tick(){}

private:
  std::pair<size_t, size_t> position; 
};


#endif /* end of include guard GENOME_H */

