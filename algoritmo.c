#include <stdio.h>

void dual_pivot_quicksort(int arr[], int left, int right, int *comparisons, int *swaps) {
    if (right <= left) {
        return;
    }

    // escolhendo os dois pivôs aleatórios
    if (arr[left] > arr[right]) {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        (*swaps)++;
    }
    (*comparisons)++;
    int p = arr[left];
    int q = arr[right];

    // particionando a lista com base nos pivôs
    int l = left + 1;
    int g = right - 1;
    int k = l;
    while (k <= g) {
        if (arr[k] < p) {
            int temp = arr[k];
            arr[k] = arr[l];
            arr[l] = temp;
            l++;
            (*swaps)++;
        } else if (arr[k] >= q) {
            while (arr[g] > q && k < g) {
                g--;
                (*comparisons)++;
            }
            int temp = arr[k];
            arr[k] = arr[g];
            arr[g] = temp;
            g--;
            (*swaps)++;
            if (arr[k] < p) {
                temp = arr[k];
                arr[k] = arr[l];
                arr[l] = temp;
                l++;
                (*swaps)++;
            }
        }
        k++;
        (*comparisons)++;
    }

    // colocando os pivôs em suas posições finais
    l--;
    g++;
    int temp = arr[left];
    arr[left] = arr[l];
    arr[l] = temp;
    (*swaps)++;
    temp = arr[right];
    arr[right] = arr[g];
    arr[g] = temp;
    (*swaps)++;

    // chamando a função recursivamente para as sub-listas
    dual_pivot_quicksort(arr, left, l - 1, comparisons, swaps);
    if (arr[l] < arr[g]) {
        dual_pivot_quicksort(arr, l + 1, g - 1, comparisons, swaps);
    }
    dual_pivot_quicksort(arr, g + 1, right, comparisons, swaps);
}