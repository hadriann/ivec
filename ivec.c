/**
 * @brief       A library for dynamic integer arrays.
 * @author      Adrian Nita
 * @date        2014
 * @copyright   The MIT License
 *
 * Library implementation.
 */
#include <stdlib.h>
#include <stdio.h>
#include "ivec.h"

struct ivec {
    int* data;
    size_t len;
    size_t maxlen;
};


ivec ivec_new(void)
{
    ivec a = malloc(sizeof *a);
    a->data = malloc(IVEC_MAXLEN * sizeof *a->data);
    a->len = 0;
    a->maxlen = IVEC_MAXLEN;
    return a;
}


inline int ivec_get(const ivec a, size_t index)
{
    return a->data[index];
}

inline void ivec_set(ivec a, int value, size_t index)
{
    a->data[index] = value;
}


inline size_t ivec_len(const ivec a)
{
    return a->len;
}


void ivec_push(ivec a, int value)
{
    if (a->len == a->maxlen) {
        a->maxlen *= 2;
        a->data = realloc(a->data, a->maxlen * sizeof *a->data);
    }
    a->data[a->len] = value;
    a->len++;
}


size_t ivec_find(const ivec a, int value)
{
    for (size_t i = 0; i < a->len; i++) {
        if (a->data[i] == value) {
            return i;
        }
    }
    return -1;
}


void ivec_sort(ivec a)
{
    int* data = a->data;
    size_t len = a->len;
    size_t i, j;
    int aux;

    for (i = 0; i < len - 1; i++) {
        for (j = i + 1; j < len; j++) {
            if (data[j] < data[i]) {
                aux = data[i];
                data[i] = data[j];
                data[j] = aux;
            }
        }
    }
    a->data = data;
}


void ivec_reverse(ivec a)
{
    size_t len, i, end;
    int* data;
    int aux;

    data = a->data;
    len = a->len;
    end = len - 1;
    for (i = 0; i < len/2; i++) {
        aux = data[i];
        data[i] = data[end];
        data[end] = aux;
        end--;
    }
    a->data = data;
}


void ivec_print(const ivec a)
{
    size_t len, i;
    int* data;

    len = a->len;
    data = a->data;
    for (i = 0; i < len; i++) {
        printf("%d", data[i]);
        if (i < len - 1) {
            printf(", ");
        }
    }
}


void ivec_free(ivec a)
{
    free(a->data);
    a->data = NULL;
    a->len = 0;
    a->maxlen = 0;
    free(a);
    a = NULL;
}
