#ifndef BENCHMARKING_HPP
#define BENCHMARKING_HPP

#include "randoms.hpp"
#include <iostream>
#include <cassert>
#include <algorithm> // stable_sort(), random_shuffle()
#include <chrono>
#include <vector>
using namespace std;
#define ALL(x) (x).begin(), (x).end()

// st int MAX_N = 1123456
const int MAX_N = 200000;
const int MAX_K = 7;

enum inputType {
    allRandom = 0, allEqual = 1, allSorted = 2, allReverse = 3
};

template <typename T>
void fillRange(vector<T> &v, inputType input){
    if(input == allEqual){
        fill(ALL(v), randomValue<T>());
        cout << "Equal elements:  ";
        return;
    }
    int n = (int)v.size();
    for(int i = 0; i < n; i++){
        v[i] = randomValue<T>();
    }
    if(input == allRandom){
        cout << "Random elements: ";
        return;
    }
    stable_sort(ALL(v));
    if(input == allSorted){
        cout << "Sorted input:   ";
        return;
    }
    if(input == allReverse){
        reverse(ALL(v));
        cout << "Reversed input: ";
    }
}

template <typename T>
inline void fillRange(vector<T> &v){
    fillRange(ALL(v), allRandom);
}

template <typename T>
void testSortingMethod(
void (*sortingMethod)(vector<T>&, int, int)){
    int n = MAX_N;
    vector<T> v(n);
    using namespace chrono;
    for(int inType = 0; inType < 4; ++inType){
        fillRange(v, (inputType)inType);
        auto started = high_resolution_clock::now();
        sortingMethod(v, 0, (int)v.size()-1);
        auto finished = high_resolution_clock::now();

        assert(is_sorted(ALL(v)));

        auto elapsed =
            duration_cast<milliseconds>(finished-started).count();
        cout << fixed << setprecision(3)
            << ((double)elapsed / (double)1000.0) << "s\n";
    }
}

template <typename T>
void testKWaySortingMethod(
void (*kWaySortingMethod)(const int, vector<T>&, int, int)){
    int n = MAX_N;
    vector<T> v(n);
    using namespace chrono;
    for(int k = 3; k <= MAX_K; k += 2){
        cout << "-- " << k << "-way version --\n";
        for(int inType = 0; inType < 4; ++inType){
            fillRange(v, (inputType)inType);
            auto started = high_resolution_clock::now();
            kWaySortingMethod(k, v, 0, (int)v.size()-1);
            auto finished = high_resolution_clock::now();

            assert(is_sorted(ALL(v)));

            auto elapsed =
                duration_cast<milliseconds>(finished-started).count();
            cout << fixed << setprecision(3)
                << ((double)elapsed / (double)1000.0) << "s\n";
        }
    }
}

#endif // BENCHMARKING_HPP
