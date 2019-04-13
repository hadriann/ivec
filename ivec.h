/**
 * A library for dynamic integer arrays.
 *
 * @author      Adrian Nita
 * @date        2014
 * @copyright   The MIT License
 *
 * Library interface.
 */
#ifndef IVEC_H
#define IVEC_H
#define IVEC_MAXLEN 50
#include <stddef.h>

typedef struct ivec* ivec;

/** Creates a new vector of integers. */
ivec ivec_new(void);

/**
 * Gets the value at a specific index.
 * @warning No index checking is done.
 */
int ivec_get(const ivec a, size_t index);

/**
 * Sets the value at a specific index.
 * @warning No index checking is done.
 */
void ivec_set(ivec a, size_t index, int value);

/** Gets the vector size (number of elements). */
size_t ivec_len(const ivec a);

/** Appends a value to the vector. */
void ivec_push(ivec a, int value);

/**
 * Tries to find a specific value among the vector elements.
 * @return The index of the found element, otherwise -1.
 */
size_t ivec_find(const ivec a, int value);

/** Sorts the elements in ascending order. */
void ivec_sort(ivec a);

/** Reverses the order of elements. */
void ivec_reverse(ivec a);

/** Returns the concatenated comma-separated elements. */
const char *ivec_stringify(const ivec a);

/** Frees up the memory. */
void ivec_free(ivec a);

#endif
