/**
 * LeetCode 35
 * 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
 * 你可以假设数组中无重复元素。
 *
 * 示例:
 *     nums = [1,3,5,6], target = 5
 *     输出: 2
 */

#ifndef LEETCODE_35_SEARCH_INSERT_POSITION_H
#define LEETCODE_35_SEARCH_INSERT_POSITION_H

int searchInsert(const int *nums, int numsSize, int target);

void searchInsertTest(void);

#endif //LEETCODE_35_SEARCH_INSERT_POSITION_H
