#include <iostream>
#include <stdio.h>
#include "src/Q27.h"

int main() {
    int result;
    int array[8], val, i;
    int returnSize=0;
    for (i = 0; i < 8; i++) {
        scanf("%d", &array[i]);
    }
    scanf("%d", &val);

    result = removeElement(array, 8,val);
    for (i = 0; i < result; i++) {
        printf("%d\n", array[i]);
    }
    return 0;
}
