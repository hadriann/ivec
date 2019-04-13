# ivec

A simple C library for dealing with dynamic arrays (vectors) of integers.

## Compliance

The code is compliant with C11 and C18.

## Usage

Basic usage inside the `main` function of a `main.c` program:

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

Compilation can be done with:
```
gcc ivec.c main.c -o main -Wall
```

A *strict-mode* compilation can be obtained with:
```
gcc ivec.c main.c -o main -Wall -std=c11 -pedantic
```
