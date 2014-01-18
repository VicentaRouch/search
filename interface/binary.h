// Created by Samvel Khalatyan on Jan 18, 2014
// Copyright (c) 2014 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a license that can be found in
// the LICENSE file.

#ifndef SEARCH_BINARY
#define SEARCH_BINARY

#include <vector>

#include "interface/tools.h"

namespace srch
{
    // it is assumed that vector is sorted
    template<typename T>
    typename std::vector<T>::const_iterator binary(const std::vector<T> &,
                                                   const T &);

    template<typename T>
    typename std::vector<T>::const_iterator
        binary(const typename std::vector<T>::const_iterator &from,
               const typename std::vector<T>::const_iterator &to,
               const T &val,
               const typename std::vector<T>::const_iterator &last);
}

template<typename T>
typename std::vector<T>::const_iterator srch::binary(const std::vector<T> &v,
                                                     const T &val)
{
    if (not v.empty())
        return binary(v.begin(), v.end(), val, v.end());

    return v.end();
}

template<typename T>
typename std::vector<T>::const_iterator
    srch::binary(const typename std::vector<T>::const_iterator &f,
                 const typename std::vector<T>::const_iterator &t,
                 const T &val,
                 const typename std::vector<T>::const_iterator &l)
{
    if (1 == (t - f))
    {
        if (val == *f)
            return f;
        else
            return l;
    }
    else
    {
        typename std::vector<T>::const_iterator pivot {f + (t - f) / 2};
        if (val == *pivot)
            return pivot;
        else if (val < *pivot)
            return binary(f, pivot, val, l);
        else
            return binary(pivot, t, val, l);
    }
}

#endif
