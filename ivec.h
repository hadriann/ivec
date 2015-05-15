/**
 * @brief       A library for dynamic integer arrays.
 * @author      Adrian Nita
 * @date        2014
 * @copyright   The MIT License
 *
 * Library interface.
 */
#ifndef IVEC_H
#define IVEC_H
#define IVEC_MAXLEN 50

typedef struct ivec* ivec;

/** @brief  Create and return a new vector of integers. */
ivec
ivec_new (void);

/**
 * @brief   Get the value from a specific index.
 * @warning No index checking is done.
 */
int
ivec_get (const ivec a, size_t index);

/**
 * @brief   Set a value at a specific index.
 * @warning No index checking is done.
 */
void
ivec_set (ivec a, int value, size_t index);

/** @brief  Get the vector size (number of elements). */
size_t
ivec_len (const ivec a);

/** @brief  Append a value to the vector. */
void
ivec_push (ivec a, int value);

/**
 * @brief   Try to find a specific value among the vector elements.
 * @return  If found the value index, otherwise -1.
 */
size_t
ivec_find (const ivec a, int value);

/** @brief  Ascending sort of the vector. */
void
ivec_sort (ivec a);

/** @brief  Reverse order of elements. */
void
ivec_reverse (ivec a);

/** @brief  Outputs the vector elements, mainly for debugging purposes. */
void
ivec_print(const ivec a);

/** @brief  Free up the memory. */
void
ivec_free (ivec a);

#endif
