#include <stdio.h>
#include "ivec.h"

int main(void)
{
    ivec *evens = ivec_create();
    for (int i = 2; i < 20; i += 2) {
        ivec_add(evens, i);
    }

    printf("Size is %zu.\n", ivec_len(evens));

    printf("Initial elements: ");
    for (int i = 0; i < ivec_len(evens); i++) {
      printf("%d ", ivec_get(evens, i));
    }
    printf("\n");

    printf("Initial elements: ");
    printf("%s\n", ivec_join(evens, ","));

    printf("1st and 3rd elements changed: ");
    ivec_set(evens, 0, 100);
    ivec_set(evens, 2, 200);
    printf("%s\n", ivec_join(evens, ","));

    printf("Sorted elements: ");
    ivec_sort(evens);
    printf("%s\n", ivec_join(evens, ","));

    printf("Reversed elements: ");
    ivec_reverse(evens);
    printf("%s\n", ivec_join(evens, ","));

    ivec_delete(evens);
    return 0;
}
