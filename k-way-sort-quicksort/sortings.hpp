#ifndef SORTINGS_HPP
#define SORTINGS_HPP

#include <utility> // pair
#include <chrono>
using namespace std;

template <typename T>
inline void stl_introsort(vector<T> &v, int p, int r){
    sort(v.begin() + p, v.begin() + r+1);
}

template <typename T>
inline void stl_mergesort(vector<T> &v, int p, int r){
    stable_sort(v.begin() + p, v.begin() + r+1);
}

template <typename T>
inline void stl_heapsort(vector<T> &v, int p, int r){
    make_heap(v.begin() + p, v.begin() + r+1);
    sort_heap(v.begin() + p, v.begin() + r+1);
}

template <typename T>
int median_of_three(vector<T>& v, int l, int r) {
    int m = l + (r - l) / 2;
    if (v[r] < v[l]) swap(v[l], v[r]);
    if (v[m] < v[l]) swap(v[m], v[l]);
    if (v[r] < v[m]) swap(v[r], v[m]);
    swap(v[m], v[r]);
    return r;
}

template <typename T>
pair<int, int> partition_dutch(vector<T>& v, int l, int r) {
    T pivot = v[r];
    int low = l, mid = l, high = r;
    while (mid <= high) {
        if (v[mid] < pivot) swap(v[low++], v[mid++]);
        else if (v[mid] == pivot) mid++;
        else swap(v[mid], v[high--]);
    }
    return {low, high};
}

template <typename T>
void quicksort(vector<T>& v, int l, int r) {
    if (l >= r) return;
    median_of_three(v, l, r);
    auto [low, high] = partition_dutch(v, l, r);
    quicksort(v, l, low - 1);
    quicksort(v, high + 1, r);
}

template <typename T>
void merge(vector<T> &v, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    vector<T> L(n1);
    vector<T> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = v[p + i];
    for (int j = 0; j < n2; j++)
        R[j] = v[q + 1 + j];

    int i = 0, j = 0, k = p;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            v[k++] = L[i++];
        } else {
            v[k++] = R[j++];
        }
    }

    while (i < n1) {
        v[k++] = L[i++];
    }
    while (j < n2) {
        v[k++] = R[j++];
    }
}

template <typename T>
void mergesort(vector<T> &v, int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        mergesort(v, p, q);
        mergesort(v, q + 1, r);
        merge(v, p, q, r);
    }
}

template <typename T>
void heapify(vector<T> &v, int p, int r, int i) {
    int largest = i;          // indice do maior
    int left  = 2 * (i - p) + 1 + p; // filho esquerdo
    int right = 2 * (i - p) + 2 + p; // filho direito

    if (left <= r && v[left] > v[largest])
        largest = left;
    if (right <= r && v[right] > v[largest])
        largest = right;

    if (largest != i) {
        swap(v[i], v[largest]);
        heapify(v, p, r, largest);
    }
}

template <typename T>
void heapsort(vector<T> &v, int p, int r) {
    int n = r - p + 1;
    // constroi max-heap
    for (int i = p + (n / 2) - 1; i >= p; i--) {
        heapify(v, p, r, i);
    }
    // extrai elementos do heap
    for (int i = r; i > p; i--) {
        swap(v[p], v[i]);
        heapify(v, p, i - 1, p);
    }
}

#endif // SORTINGS_HPP
