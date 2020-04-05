//  This file is part of Outbreak
//  Copyright (C) Nathan Rizik, 2020.
//  Released under GNU General Public License v3; see LICENSE

#include <iostream>

#include "base/vector.h"
#include "config/command_line.h"

// This is the main function for the NATIVE version of Outbreak.

int main(int argc, char* argv[])
{
  emp::vector<std::string> args = emp::cl::args_to_strings(argc, argv);

  std::cout << "Hello, world!" << std::endl;
}
