// Created by Samvel Khalatyan on Jan 18, 2014
// Copyright (c) 2014 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a license that can be found in
// the LICENSE file.

#ifndef SEARCH_LINEAR
#define SEARCH_LINEAR

#include <vector>

#include "interface/tools.h"

namespace srch
{
    template<typename T>
    typename std::vector<T>::const_iterator linear(const std::vector<T> &,
                                                   const T &);
}

template<typename T>
typename std::vector<T>::const_iterator srch::linear(const std::vector<T> &v,
                                                     const T &val)
{
    if (not v.empty())
        for(typename std::vector<T>::const_iterator iter {v.begin()};
                v.end() != iter;
                ++iter)
        {
            if (*iter == val)
                return iter;
        }

    return v.end();
}

#endif
