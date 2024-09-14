#include <stdio.h>
#include <stdlib.h>
#include "dbl_vector.h"

void dv_init( dbl_vector_t* vec ) {

    vec->size = 0;

    vec->capacity = DV_INITIAL_CAPACITY;

    size_t new_mem_size = vec->capacity * sizeof(double);

    vec->data = (double*) malloc(new_mem_size);

}

void dv_ensure_capacity( dbl_vector_t* vec, size_t new_size ) {

    if (new_size > vec->capacity) {

        size_t new_capacity = vec->capacity; //* DV_GROWTH_FACTOR;
        
        // Continue increasing capacity until it's enough
        while (new_capacity < new_size) {
            new_capacity *= DV_GROWTH_FACTOR;
        }

        // Reallocate memory with the new capacity
        vec->data = realloc(vec->data, new_capacity * sizeof(double));

        // Update the vector's capacity
        vec->capacity = new_capacity;
    }
    // else: capacity is already enough, no need to reallocate memory

}

void dv_destroy( dbl_vector_t* vec ) {
    
    free(vec->data);
    vec->size = 0;        // Reset the size
    vec->capacity = 0;    // Reset the capacity
    vec->data = NULL;    // Reset the data pointer

}

void dv_copy( dbl_vector_t* vec, dbl_vector_t* dest ) {

    // Ensure destination has enough capacity
    dv_ensure_capacity(dest, vec->size);

    // Copy data from vec to dest
    for (size_t i = 0; i < vec->size; i++) {
        dest->data[i] = vec->data[i];
    }

    // Update size and capacity of the destination vector
    dest->size = vec->size;
    dest->capacity = vec->capacity;

}

void dv_clear( dbl_vector_t* vec ) {

    vec->size = 0;  // Reset the size to 0, removing all contents from the vector
    // vec->capacity remains unchanged

}

void dv_push( dbl_vector_t* vec, double new_item ) {
    
    // Ensure the vector has enough space to add the new item
    dv_ensure_capacity(vec, vec->size + 1);

    // Add the new item to the vector
    vec->data[vec->size] = new_item;

    // Increment the size to reflect the added element
    vec->size++;

}

void dv_pop( dbl_vector_t* vec ) {

    // Reduce the vector size by 1 to remove the last element
    if (vec->size > 0) {
        vec->size--; 
    }

}

double dv_last( dbl_vector_t* vec ) {
    
    double result = NAN;

    // Return the last element if not empty
    if (vec->size > 0) {
        result = vec->data[vec->size - 1];  
    }
    // Otherwise, return NaN
    return result;

}

void dv_insert_at( dbl_vector_t* vec, size_t pos, double new_item ) {
    
    // Ensure the vector has enough memory for the new element
    dv_ensure_capacity(vec, vec->size + 1);

    // If the position is greater than the current size, insert at the end
    if (pos >= vec->size) {
        pos = vec->size;  // Insert at the end of the vector
    }

    // Shift elements to the right, starting from the position
    for (size_t i = vec->size; i > pos; i--) {
        vec->data[i] = vec->data[i - 1];
    }

    // Insert the new element at the desired position
    vec->data[pos] = new_item;

    // Increment the size of the vector
    vec->size++;

}

void dv_remove_at( dbl_vector_t* vec, size_t pos ) {
    
    // Check if the position is valid
    if (pos >= vec->size) {
        return;  // Invalid position, do nothing
    }

    // Shift elements to the left to cover the removed element
    for (size_t i = pos; i < vec->size - 1; i++) {
        vec->data[i] = vec->data[i + 1];
    }

    // Decrease the size of the vector
    vec->size--;

}

void dv_foreach( dbl_vector_t* vec, void (*callback)(double, void*), void* info ) {
    
    // Iterate over each element and apply the function = callback, and output the result = info
    for (size_t i = 0; i < vec->size; i++) {
        callback(vec->data[i], info);
    }

}
