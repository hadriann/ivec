# ivec

A simple C library for dealing with dynamic arrays (vectors) of integers.

The code is in compliance with C11 and C18.

## Compiling

When used in a `main.c` program, you can compile with:

```
gcc ivec.c main.c -o main -Wall
```

Or do a stricter compilation with:

```
gcc ivec.c main.c -o main -Wall -std=c11 -pedantic
```

## Usage

Basic usage inside a main function:

```c
#include <stdio.h>
#include "ivec.h"

int main(void)
{
    ivec evens = ivec_new();
    for (int i = 2; i < 20; i += 2) {
        ivec_push(evens, i);
    }
    printf("Size is %zd.\n", ivec_len(evens));
    printf("%s\n", ivec_stringify(evens));

    ivec_set(evens, 0, 1);
    printf("%s\n", ivec_stringify(evens));

    ivec_reverse(evens);
    printf("%s\n", ivec_stringify(evens));

    ivec_free(evens);
    return 0;
}
```
