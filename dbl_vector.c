#include <stdio.h>
#include <stdlib.h>
#include "dbl_vector.h"

void dv_init( dbl_vector_t* vec ) {

    vec->size = 0;
    // size_t old_size = vec->size;

    vec->capacity = DV_INITIAL_CAPACITY;
    // size_t old_capacity = vec->capacity;

    size_t new_mem_size = vec->capacity * sizeof(double);

    vec->data = (double*) malloc(new_mem_size);
    // if (!vec->data) {
    //     printf("Memory allocation failed!\n");
    //     exit(1);
    // }

}

// #define CEIL_DIV(a, b) (((a) + (b) - 1) / (b))
// #define CALC_NEW_CAPACITY(old_capacity, new_size, growth_factor) \
//     (old_capacity * CEIL_DIV(new_size, old_capacity * growth_factor))

void dv_ensure_capacity( dbl_vector_t* vec, size_t new_size ) {

    if (new_size > vec->capacity) {

        size_t new_capacity = vec->capacity * DV_GROWTH_FACTOR;
        
        // Continue increasing capacity until it's enough
        while (new_capacity < new_size) {
            new_capacity *= DV_GROWTH_FACTOR;
        }

        // Reallocate memory with the new capacity
        vec->data = realloc(vec->data, new_capacity * sizeof(double));
        // if (!vec->data) {
        //     printf("Memory reallocation failed!\n");
        //     exit(1);  // Exit if memory allocation fails
        // }

        // Update the vector's capacity
        vec->capacity = new_capacity;
    }
    // else: capacity is already enough, no need to reallocate memory

}

void dv_destroy( dbl_vector_t* vec ) {
    // INSERT SOLUTION HERE
}

void dv_copy( dbl_vector_t* vec, dbl_vector_t* dest ) {
    // INSERT SOLUTION HERE
}

void dv_clear( dbl_vector_t* vec ) {
    // INSERT SOLUTION HERE
}

void dv_push( dbl_vector_t* vec, double new_item ) {
    // INSERT SOLUTION HERE
}

void dv_pop( dbl_vector_t* vec ) {
    // INSERT SOLUTION HERE
}

double dv_last( dbl_vector_t* vec ) {
    double result = NAN;
    // INSERT SOLUTION HERE
    return result;
}

void dv_insert_at( dbl_vector_t* vec, size_t pos, double new_item ) {
    // INSERT SOLUTION HERE
}

void dv_remove_at( dbl_vector_t* vec, size_t pos ) {
    // INSERT SOLUTION HERE
}

void dv_foreach( dbl_vector_t* vec, void (*callback)(double, void*), void* info ) {
    // INSERT SOLUTION HERE
}
