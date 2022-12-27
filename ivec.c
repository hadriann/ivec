/**
 * A library for dynamic integer arrays.
 *
 * @author      Adrian Nita
 * @date        2014
 * @copyright   The MIT License
 *
 * Library implementation.
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ivec.h"

#define IVEC_MAXLEN 50

struct ivec {
    int *data;
    size_t len;
    size_t maxlen;
};

ivec *ivec_create(void)
{
    ivec *a = malloc(sizeof *a);
    a->data = malloc(IVEC_MAXLEN * sizeof *a->data);
    a->len = 0;
    a->maxlen = IVEC_MAXLEN;
    return a;
}

void ivec_delete(ivec *a)
{
    free(a->data);
    a->data = NULL;
    a->len = 0;
    a->maxlen = 0;
    free(a);
    a = NULL;
}

inline int ivec_get(const ivec *a, size_t index)
{
    return a->data[index];
}

inline void ivec_set(const ivec *a, size_t index, int value)
{
    a->data[index] = value;
}

inline size_t ivec_len(const ivec *a)
{
    return a->len;
}

void ivec_add(ivec *a, int value)
{
    if (a->len == a->maxlen) {
        a->maxlen *= 2;
        a->data = realloc(a->data, a->maxlen * sizeof *a->data);
    }
    a->data[a->len] = value;
    a->len++;
}

size_t ivec_find(const ivec *a, int value)
{
    for (size_t i = 0; i < a->len; i++) {
        if (a->data[i] == value) {
            return i;
        }
    }
    return -1;
}

void ivec_sort(ivec *a)
{
    size_t len = a->len;
    int* data = a->data;
    int aux;

    for (size_t i = 0; i < len - 1; i++) {
        for (size_t j = i + 1; j < len; j++) {
            if (data[j] < data[i]) {
                aux = data[i];
                data[i] = data[j];
                data[j] = aux;
            }
        }
    }
    a->data = data;
}

void ivec_reverse(ivec *a)
{
    size_t len = a->len;
    size_t half = len / 2;
    for (size_t i = 0; i < half; i++) {
        size_t end = len - i - 1;
        int aux = a->data[i];
        a->data[i] = a->data[end];
        a->data[end] = aux;
    }
}

const char *ivec_join(const ivec *a, const char* separator)
{
    static char output[100];
    char current[100];
    output[0] = 0;
    size_t len = a->len;
    for (size_t i = 0; i < len; i++) {
        sprintf(current, "%d", a->data[i]);
        strcat(output, current);
        if (i < len - 1) {
            strcat(output, separator);
        }
    }
    return output;
}
