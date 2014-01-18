// Created by Samvel Khalatyan on Jan 18, 2014
// Copyright (c) 2014 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a license that can be found in
// the LICENSE file.

#include <chrono>
#include <random>
#include <vector>

#include "interface/tools.h"
#include "interface/estd_tty.h"
#include "interface/linear.h"

template<typename T>
void run(std::vector<T> &v)
{
    using namespace std;
    using srch::operator<<;

    if (v.empty())
        cout << "empty list" << endl;
    else
    {
        cout << v << endl;

        cout << "-- search for random values in range [0-100]" << endl;
        for(int i {0}; 10 > i; ++i)
        {
            std::default_random_engine e{
                std::chrono::system_clock::now().time_since_epoch().count()};
            std::uniform_int_distribution<int> d{0, 100};

            const int value = d(e);
            if (v.end() != srch::linear(v, value))
                cout << estd::bold;

            cout << value << estd::reset << ' ';
        }
        cout << endl;
    }
}

int main(int argc, char *argv[])
{
    auto args = srch::int_arguments(argc, argv);
    if (args.empty())
    {
        // create a random vector of ints
        //
        std::default_random_engine e{
            std::chrono::system_clock::now().time_since_epoch().count()};
        std::uniform_int_distribution<int> d{0, 100};

        auto index = std::bind(d, e);

        args.resize(std::uniform_int_distribution<int>{0, 20}(e));
        for(auto &x:args)
            x = index();
    }

    run(args);
}
