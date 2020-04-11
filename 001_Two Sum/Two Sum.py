"""
LeetCode 1
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

示例:
    给定 nums = [2, 7, 11, 15], target = 9

    因为 nums[0] + nums[1] = 2 + 7 = 9
    所以返回 [0, 1]
"""


class Solution1:
    """ 2020/4/3 超时 """

    @staticmethod
    def two_sum(nums: list, target: int) -> list:
        i = 0
        while i ^ len(nums) - 1:
            j = len(nums) - 1
            while j ^ i:
                if nums[i] + nums[j] == target:
                    return [i, j]
                j -= 1
            i += 1
        return [None, None]


class Solution2:
    """ 2020/4/3 968ms 14.3MB """

    @staticmethod
    def two_sum(nums: list, target: int) -> list:
        for i in range(len(nums)):
            if target - nums[i] in nums[i + 1:]:
                return [i, i + 1 + nums[i + 1:].index(target - nums[i])]
        return [None, None]


class Solution3:
    """ 2020/4/3 40ms 14.7MB """

    @staticmethod
    def two_sum(nums: list, target: int) -> list:
        hash_map = {}
        for i, num in enumerate(nums):
            another_num = target - num
            if another_num in hash_map:
                return [hash_map[another_num], i]
            hash_map[num] = i
        return [None, None]


class Solution4:
    """ 2020/4/3 44ms 14.6MB """

    @staticmethod
    def two_sum(nums: list, target: int) -> list:
        hash_map = {}
        for i, num in enumerate(nums):
            if hash_map.get(target - num) is not None:
                return [i, hash_map.get(target - num)]
            hash_map[num] = i
        return [None, None]


if __name__ == "__main__":
    nums_test = [3, 2, 4, 22, 6, 8, 4, 25, 41, 9]
    target_test = 28
    print(Solution3.two_sum(nums_test, target_test))
