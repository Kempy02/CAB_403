#include "dbl_vector.h"
#include <stdio.h>
#include <stdlib.h>

// Helper function to print vector contents
void print_vector(dbl_vector_t* vec) {
    printf("Vector contents: ");
    for (size_t i = 0; i < vec->size; i++) {
        printf("%.2f", vec->data[i]);
        if (i < vec->size - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

// Test dv_init
void test_dv_init() {
    printf("\nTesting dv_init...\n");
    dbl_vector_t vec;
    dv_init(&vec);
    printf("Initial size: %zu, Initial capacity: %zu\n", vec.size, vec.capacity);
    dv_destroy(&vec);
}

// Test dv_ensure_capacity
void test_dv_ensure_capacity() {
    printf("\nTesting dv_ensure_capacity...\n");
    dbl_vector_t vec;
    dv_init(&vec);

    dv_ensure_capacity(&vec, 10);
    printf("Size: %zu, Capacity after ensuring: %zu\n", vec.size, vec.capacity);

    dv_destroy(&vec);
}

// Test dv_copy
void test_dv_copy() {
    printf("\nTesting dv_copy...\n");
    dbl_vector_t vec1, vec2;
    dv_init(&vec1);
    dv_init(&vec2);

    // Push data into vec1
    for (int i = 0; i < 5; i++) {
        dv_push(&vec1, i + 1.0);  // Adding values 1.0, 2.0, 3.0, etc.
    }
    printf("Original vector (vec1):\n");
    print_vector(&vec1);

    // Copy vec1 to vec2
    dv_copy(&vec1, &vec2);
    printf("Copied vector (vec2):\n");
    print_vector(&vec2);

    dv_destroy(&vec1);
    dv_destroy(&vec2);
}

// Test dv_destroy
void test_dv_destroy() {
    printf("\nTesting dv_destroy...\n");
    dbl_vector_t vec;
    dv_init(&vec);

    for (int i = 0; i < 3; i++) {
        dv_push(&vec, i + 1.0);  // Adding values 1.0, 2.0, 3.0
    }
    printf("Before destroy - Size: %zu, Capacity: %zu, Data: %p\n", vec.size, vec.capacity, (void*)vec.data);

    dv_destroy(&vec);

    printf("After destroy - Size: %zu, Capacity: %zu, Data: %p\n", vec.size, vec.capacity, (void*)vec.data);
}

int main() {
    test_dv_init();
    test_dv_ensure_capacity();
    test_dv_copy();
    test_dv_destroy();

    return 0;
}