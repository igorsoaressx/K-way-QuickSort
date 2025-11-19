#ifndef KWAYSORT_HPP
#define KWAYSORT_HPP

#include <vector>
#include <algorithm> // Para std::swap

// Função auxiliar de partição (Algoritmo padrão Divide sempre em 2 partes, ignorando os K)
template <typename T>
int partition_standard(std::vector<T> &v, int p, int r) {
    T pivot = v[r]; // O pivô é o último elemento
    int i = p - 1;  // Índice do menor elemento

    for (int j = p; j < r; j++) {
        // Se o elemento atual é menor que o pivô
        if (v[j] < pivot) {
            i++;
            std::swap(v[i], v[j]);
        }
    }
    std::swap(v[i + 1], v[r]); // Coloca o pivô no lugar certo
    return i + 1;
}

template <typename T>
void kway_quicksort(const int K, std::vector<T> &v, int p, int r) {
    if (p < r) {
        //Particiona o vetor
        int pi = partition_standard(v, p, r);

        // Ordena recursivamente as duas metades
        kway_quicksort(K, v, p, pi - 1);
        kway_quicksort(K, v, pi + 1, r);
    }
}

template <typename T>
void kway_mergesort(const int K, std::vector<T> &v, int p, int r) {}

template <typename T>
void kway_heapsort(const int K, std::vector<T> &v, int p, int r) {}

#endif // KWAYSORT_HPP