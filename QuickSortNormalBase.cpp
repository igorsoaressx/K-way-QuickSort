#include <iostream>
using namespace std;

// Função para particionar o array
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivô
    int i = low - 1;       // índice do menor elemento

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1); // retorna a posição final do pivô
}

// Função QuickSort recursiva
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);  // esquerda
        quickSort(arr, pi + 1, high); // direita
    }
}

int main()
{
    int arr[] = {25, 15, 30, 10, 20};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    cout << "Array ordenado: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

/* Escolhe um pivô no array (um elemento que será referência).

Reorganiza o array (particionamento) de forma que:

Elementos menores que o pivô fiquem à esquerda

Elementos maiores que o pivô fiquem à direita

Aplica o QuickSort recursivamente nas duas partes (esquerda e direita).

Repete até que todos os subarrays tenham 1 elemento — neste ponto, o array está ordenado.

Diferente do Merge Sort, a ordenação acontece durante o particionamento, não depois.
*/