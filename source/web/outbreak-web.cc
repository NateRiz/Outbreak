//  This file is part of Outbreak
//  Copyright (C) Nathan Rizik, 2020.
//  Released under GNU General Public License v3; see LICENSE

#include <iostream>

#include "web/web.h"

namespace UI = emp::web;

UI::Document doc("emp_base");

int main()
{
  doc << "<h1>Hello, browser!</h1>";
  std::cout << "Hello, console!" << std::endl;

}
