// Created by Samvel Khalatyan on Jan 18, 2014
// Copyright (c) 2014 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a license that can be found in
// the LICENSE file.

#ifndef SEARCH_TOOLS
#define SEARCH_TOOLS

#include <iostream>
#include <vector>

namespace srch
{
    template<typename T>
    std::ostream &operator <<(std::ostream &, const std::vector<T> &);

    std::vector<int> int_arguments(const int &argc, char *argv[]);
}

template<typename T>
std::ostream &srch::operator <<(std::ostream &os, const std::vector<T> &v)
{
    for(const auto &x:v)
    {
        os << x;
        if (&x != &v.back())
            os << ' ';
    }

    return os;
}

#endif
