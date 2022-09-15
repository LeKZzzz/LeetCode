//
// Created by LeK on 2022/9/12.
//

#ifndef LEETCODE_Q1_H
#define LEETCODE_Q1_H

#endif //LEETCODE_Q1_H

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

int *twoSum(int *array, int target, int numsSize, int *returnSize) {
    int length = numsSize;
    int i, j, t = 0, left = 0, right = length - 1, u = 0;
    static int result[2], *tmp;

    tmp = (int *) malloc(sizeof(int) * length);

    for (int i = 0; i < length; i++) {
        if (array[i] < target / 2) {
            tmp[left] = i;
            left++;
        }
        if (array[i] > target / 2) {
            tmp[right] = i;
            right--;
        }
        if (array[i] == target / 2) {
            switch (u) {
                case 0:
                    tmp[left] = i;
                    left++;
                    u = 1;
                    break;
                case 1:
                    tmp[right] = i;
                    right--;
                    u = 0;
                    break;
            }
        }
    }

    if ((left - 1) == (length - 1)) left -= 2;
    else if (left == (length - 1)||array[tmp[left]] == array[tmp[left-1]]) left -= 1;
    for (i = 0; i <= left; i++) {
        for (j = length - 1; j > left; j--) {
            if (array[tmp[i]] + array[tmp[j]] == target) {
                result[0] = tmp[i];
                result[1] = tmp[j];
                t = 1;
                *returnSize = 2;
                break;
            }
        }
        if (t == 1) return result;
    }
//    static int result[2] = {0};
//    for(int i = 0; i < numsSize - 1; i++)
//    {
//        for(int j = i+1; j < numsSize; j++)
//        {
//            if(array[i] + array[j] == target)
//            {
//                result[0] = i;
//                result[1] = j;
//                *returnSize = 2;
//                return result;
//            }
//        }
//    }
    return 0;
}
