"""
LeetCode 42
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

示例:
    输入: [0,1,0,2,1,0,1,3,2,1,2,1]
    输出: 6
"""


class Solution1:
    """ 2020/4/4 4300ms 14.1MB """

    @staticmethod
    def trap(height: list) -> int:
        drops = 0
        for i in range(1, len(height) - 1):
            if max(height[:i]) > height[i] and max(height[i:]) > height[i]:
                drops += min(max(height[:i]), max(height[i:])) - height[i]
        return drops


class Solution2:
    """ 2020/4/4 44ms 14MB """

    @staticmethod
    def trap(height: list) -> int:
        if len(height) < 3:
            return 0
        drops = 0
        max_l = height[0]
        max_r = max(height[1:])
        for i in range(1, len(height) - 1):
            if max_l < height[i]:
                max_l = height[i]
            if max_r == height[i]:
                max_r = max(height[i + 1:])
            if max_l > height[i] < max_r:
                drops += (min(max_l, max_r) - height[i])
        return drops


if __name__ == '__main__':
    height_test = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
    print(Solution2.trap(height_test))
