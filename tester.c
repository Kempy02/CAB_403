#include "dbl_vector.h"
#include <stdio.h>
#include <stdlib.h>

void test_dv_init() {
    dbl_vector_t vec;
    dv_init(&vec);  // Initialize the vector

    // Test if initialization was correct
    printf("Initial size = %zu\n", vec.size);
    printf("Initial capacity = %zu\n", vec.capacity);
    printf("Data pointer is %sNULL\n", vec.data ? "not " : "");

    // Free allocated memory to prevent memory leaks
    free(vec.data);
}

int main() {
    test_dv_init();
    return 0;
}