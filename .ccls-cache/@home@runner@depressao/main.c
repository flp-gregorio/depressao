#include "algoritmo.h"
#include <stdio.h>

int main() {
    int a[] = {1, 234, 345, 342, 5634, 523, 52, 564, 6, 345, 2, 345, 23};
    int n = sizeof(a) / sizeof(a[0]);
    int comparisons = 0;
    int swaps = 0;

    dual_pivot_quicksort(a, 0, n - 1, &comparisons, &swaps);

    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    printf("Number of comparisons: %d\n", comparisons);
    printf("Number of swaps: %d\n", swaps);

    return 0;
}