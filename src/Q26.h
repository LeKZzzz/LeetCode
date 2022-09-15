//
// Created by LeK on 2022/9/15.
//

#ifndef LEETCODE_Q26_H
#define LEETCODE_Q26_H

#endif //LEETCODE_Q26_H

#include <stdio.h>

int removeDuplicates(int* nums, int numsSize){
    int p=0,q=1,tmp;
    for(;q<numsSize;q++){
        if(nums[p]!=nums[q])    p++;
        tmp=nums[p];
        nums[p]=nums[q];
        nums[q]=tmp;
    }
    return p+1;
}