// Created by Samvel Khalatyan on Jan 18, 2014
// Copyright (c) 2014 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a license that can be found in
// the LICENSE file.

#include <cstdlib>

#include "interface/tools.h"

std::vector<int> srch::int_arguments(const int &argc, char *argv[])
{
    std::vector<int> v;

    for(int i {1}; argc > i; ++i)
        v.push_back(std::atoi(argv[i]));

    return v;
}

