// Created by Samvel Khalatyan on Jan 18, 2014
// Copyright (c) 2014 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a license that can be found in
// the LICENSE file.

#include <algorithm>
#include <chrono>
#include <random>
#include <vector>

#include "gtest/gtest.h"
#include "interface/binary.h"
#include "interface/tools.h"

using IntVector = std::vector<int>;
using IntIterator = typename std::vector<int>::const_iterator;

IntIterator (*search)(const IntVector &, const int &) = srch::binary;

TEST(BinarySearch, EmptyVector)
{
    IntVector v;

    EXPECT_EQ(v.end(), search(v, 10));
}

TEST(BinarySearch, VectorWithOneElement)
{
    IntVector v {10};

    EXPECT_EQ(v.begin(), search(v, 10));
}

TEST(BinarySearch, VectorWithSeveralElements)
{
    IntVector v {10, 2, 5, 33};
    std::sort(v.begin(), v.end());

    EXPECT_EQ(std::find(v.begin(), v.end(), 10), search(v, 10));
    EXPECT_EQ(std::find(v.begin(), v.end(), 5), search(v, 5));
    EXPECT_EQ(std::find(v.begin(), v.end(), 33), search(v, 33));
}

TEST(BinarySearch, RandomVector)
{
    std::default_random_engine e{
        std::chrono::system_clock::now().time_since_epoch().count()};
    std::uniform_int_distribution<int> d{0, 100};

    IntVector v(std::uniform_int_distribution<int>{0, 20}(e));
    for(auto &x:v)
        x = d(e);
    std::sort(v.begin(), v.end());

    for(IntIterator iter {v.begin()}; v.end() != iter; ++iter)
        EXPECT_EQ(*iter, *search(v, *iter)); // iters should be the same by val
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
