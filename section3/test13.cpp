// Copyright (c) 2020 by Chrono
//
// g++ test13.cpp -std=c++11 -o a.out;./a.out
// g++ test13.cpp -std=c++14 -o a.out;./a.out
// g++ test13.cpp -std=c++14 -I../common -o a.out;./a.out

#include <cassert>

#include <iostream>

#include <array>
#include <vector>
#include <algorithm>

using namespace std;

void case1()
{
    vector<int> v = {1,3,1,7,5};

    auto n1 = std::count(
        begin(v), end(v), 1
    );

    int n2 = 0;
    for(auto x : v) {
        if (x == 1) {
            n2++;
        }
    }

    assert(n1 == n2);

    auto n = std::count_if(
        begin(v), end(v),
        [](auto x) {
            return x > 2;
        }
    );

    assert(n == 3);
}

void case2()
{
    vector<int> v = {1,2,3,4,5};

    auto iter1 = v.begin();
    auto iter2 = v.end();

    auto iter3 = std::begin(v);
    auto iter4 = std::end(v);

    assert(iter1 == iter3);
    assert(iter2 == iter4);
}

void case3()
{
    array<int, 5> arr = {0,1,2,3,4};

    auto b = begin(arr);
    auto e = end(arr);

    assert(distance(b, e) == 5);

    auto p = next(b);
    assert(distance(b, p) == 1);
    assert(distance(p, b) == -1);

    advance(p, 2);
    assert(*p == 3);
    assert(p == prev(e, 2));

}

void case4()
{
#if 1
    vector<int> v = {3,5,1,7,10};

    for(const auto& x : v) {
        cout << x << ",";
    }
#endif
    cout << endl;

#if 1
    auto print = [](const auto& x)
    {
        cout << x << ",";
    };

    for_each(cbegin(v), cend(v), print);
#endif
    cout << endl;

#if 1
    for_each(
        cbegin(v), cend(v),
        [](const auto& x)
        {
            cout << x << ",";
        }
    );
#endif
    cout << endl;
}

void case5()
{
    vector<int> v = {3,5,1,7,10,99,42};

    auto print = [](const auto& x)
    {
        cout << x << ",";
    };

    // total sort
    std::sort(begin(v), end(v));
    for_each(cbegin(v), cend(v), print);
    cout << endl;

    // top3
    std::partial_sort(
        begin(v), next(begin(v), 3), end(v));
    for_each(cbegin(v), cend(v), print);
    cout << endl;

    // best3
    std::nth_element(
        begin(v), next(begin(v), 3), end(v));
    for_each(cbegin(v), cend(v), print);
    cout << endl;

    // Median
    auto mid_iter =
        next(begin(v), v.size()/2);
    std::nth_element( begin(v), mid_iter, end(v));
    for_each(cbegin(v), cend(v), print);
    cout << "median is " << *mid_iter << endl;

    // partition
    auto pos = std::partition(
        begin(v), end(v),
        [](const auto& x)
        {
            return x > 9;
        }
    );
    for_each(begin(v), pos, print);
    cout << endl;
    for_each(cbegin(v), cend(v), print);
    cout << endl;

    // min/max
    auto value = std::minmax_element(
        cbegin(v), cend(v)
    );
    cout << *value.first << ","
         << *value.second << endl;
}

int main()
{
    case1();
    case2();
    case3();
    case4();
    case5();

    using namespace std;

    cout << "algorithm demo" << endl;
}