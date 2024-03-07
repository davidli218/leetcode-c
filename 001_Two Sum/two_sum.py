"""
Title: [1] Two Sum

Example:
    >>> nums_test = [3, 2, 4, 22, 6, 8, 4, 25, 41, 9]
    >>> target_test = 28
    >>> FavoriteSolution.two_sum(nums_test, target_test)
    [3, 4]
"""

from typing import List


class Solution1:
    """ 2020/4/3 | BF | T-08 | M-88 """

    @staticmethod
    def two_sum(nums: List[int], target: int) -> List[int]:
        i = 0

        while i ^ len(nums) - 1:
            j = len(nums) - 1
            while j ^ i:
                if nums[i] + nums[j] == target:
                    return [i, j]
                j -= 1
            i += 1

        raise ValueError("No Solution")


class Solution2:
    """ 2020/4/3 | BF | T-40 | M-73 """

    @staticmethod
    def two_sum(nums: List[int], target: int) -> List[int]:
        for i in range(len(nums)):
            if target - nums[i] in nums[i + 1:]:
                return [i, i + 1 + nums[i + 1:].index(target - nums[i])]

        raise ValueError("No Solution")


class Solution3:
    """ 2020/4/3 | Hash Map | T-86 | M-35 """

    @staticmethod
    def two_sum(nums: List[int], target: int) -> List[int]:
        hash_map = {}

        for i, num in enumerate(nums):
            another_num = target - num

            if another_num in hash_map:
                return [hash_map[another_num], i]

            hash_map[num] = i

        raise ValueError("No Solution")


FavoriteSolution = Solution3
