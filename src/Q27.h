//
// Created by LeK on 2022/9/15.
//

#ifndef LEETCODE_Q27_H
#define LEETCODE_Q27_H

#endif //LEETCODE_Q27_H


int removeElement(int *nums, int numsSize, int val) {
    int p = 0, q = 1;
    if (numsSize == 1) {
        if (nums[0] != val) {
            return 1;
        } else {
            return 0;
        }
    }else if (numsSize == 0){
        return 0;
    }
    for (; q < numsSize; q++) {
        if (nums[p] != val)
            p++;
        nums[p] = nums[q];
    }
    if (nums[p] == val && q == numsSize) p--;
    return p + 1;
}