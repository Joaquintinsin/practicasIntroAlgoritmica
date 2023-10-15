#include <stdio.h>
#include <stdlib.h>
#define NMAX 50

/**
* Intercambia 2 valores enteros
**/
void swap(int* a, int* b) {
        int aux = *a;
        *a = *b;
        *b = aux;
}

/**
* Ordena un arreglo arr de NMAX elementos utilizando bubblesort.
**/
void bubbleSort(int arr[]) {
        int begin = 0;
        for (int end = NMAX; end > begin; end--) {
                for (int i = 0; i < end-1; i++) {
                        if (arr[i] > arr[i+1]) {
                               swap(&arr[i], &arr[i+1]);
                        }
                }
        }
}

/**
* Modifica el arreglo arr, quedando [<pivot,pivot,>pivot].
* devuelve la posicion del pivote.
**/
int partition(int arr[], int min, int max) {
        int i = max + 1;
        int pivot = arr[min];
        for (int j = max; j > min; j--) {
                if (arr[j] > pivot) {
                        swap(&arr[--i], &arr[j]);
                }
        }
        swap(&arr[--i], &arr[min]);
        return i;
}


/**
* Ordena un arreglo utilizando quicksort.
* @pre: min = 0 && max = NMAX-1
**/

void quickSort(int arr[], int min, int max) {
        int pivotPlace =  partition(arr,min,max);
        if (pivotPlace > min) {
                quickSort(arr, min, pivotPlace-1);
        }
        if (pivotPlace < max) {
                quickSort(arr, pivotPlace+1, max);
        }
}

void insertionSort(int arr[]) {
        int aux;
        int i = 1;
        while(i < NMAX) {
                aux = arr[i];
                int j = i -1;
                while(j >= 0 && arr[j] > aux) {
                        arr[j+1] = arr[j];
                        j--;
                }
                arr[j+1] = aux;
                i++;
        }
}

/**
* Muestra un arreglo de NMAX elementos.
**/
void mostrar(int arr[]) {
        printf("[");
        for (int i = 0; i < NMAX; i++) {
                printf( "%d ", arr[i]);
        }
        printf("]\n");
}

/**
* Genera un arreglo de NMAX elementos con numeros pseudoaleatorios.
**/
void genArray(int arr[], int seed) {
        srand(seed);
        for (int i = 0; i < NMAX; i++) {
                arr[i] = rand() % 100;
        }
}


int main() {
        int a[NMAX];
        printf("Bubblesort:\n");
        genArray(a,1234);
        mostrar(a);
        bubbleSort(a);
        mostrar(a);
        printf("Quicksort:\n");
        genArray(a,1234);
        mostrar(a);
        quickSort(a,0,NMAX-1);
        mostrar(a);
        printf("InsertionSort:\n");
        genArray(a,1234);
        mostrar(a);
        insertionSort(a);
        mostrar(a);
        return 0;
}
