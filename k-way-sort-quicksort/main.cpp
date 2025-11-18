#include <iostream>
#include "pedido.cpp"
#include "benchmarking.hpp"
#include "sortings.hpp"
#include "kwaysort.hpp"
using namespace std;

typedef pedido dataType;

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);
    cout << "### Sorting an array of "<<
        MAX_N << " random structs ###\n";

    cout << "\n-- Introsort (std::sort) --\n";
    testSortingMethod<dataType>(stl_introsort<dataType>);
    cout << "\n-- std::stable_sort --\n";
    testSortingMethod<dataType>(stl_mergesort<dataType>);
    cout << "\n-- std::sort_heap --\n";
    testSortingMethod<dataType>(stl_heapsort<dataType>);

    cout << "\n-- Quicksort (2-way) --\n";
    testSortingMethod<dataType>(quicksort<dataType>);
    cout << "\n-- Merge Sort (2-way) --\n";
    testSortingMethod<dataType>(mergesort<dataType>);
    cout << "\n-- Heapsort (2-way) --\n";
    testSortingMethod<dataType>(heapsort<dataType>);

    /*
    Descomente as linhas correspondentes ao seu algoritmo
    e implemente-o em kwaysort.cpp.
    Baseie-se nos algoritmos 2-way em sortings.cpp.
    */

    // cout << "\n-- K-Way Quicksort --\n";
    // testKWaySortingMethod<dataType>(kway_quicksort<dataType>);

    // cout << "\n-- K-Way Merge Sort --\n";
    // testKWaySortingMethod<dataType>(kway_mergesort<dataType>);

    // cout << "\n-- K-Way Heapsort --\n";
    // testKWaySortingMethod<dataType>(kway_heapsort<dataType>);

    return 0;
}
