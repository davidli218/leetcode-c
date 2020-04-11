"""
LeetCode 11
给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai)。
在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。
找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
说明：你不能倾斜容器，且 n 的值至少为 2。
示例：
    输入：[1,8,6,2,5,4,8,3,7]
    输出：49
"""


class Solution:
    """ 2020/4/5 双指针 68ms 15.2MB """

    @staticmethod
    def max_area(height: list) -> int:
        if len(height) == 0:
            return 0
        ptr_l = 0
        ptr_r = len(height) - 1
        max_area = min(height[ptr_l], height[ptr_r]) * (ptr_r - ptr_l)
        while ptr_l < ptr_r:
            if height[ptr_l] < height[ptr_r]:
                ptr_l = ptr_l + 1
            else:
                ptr_r = ptr_r - 1
            if max_area < min(height[ptr_l], height[ptr_r]) * (ptr_r - ptr_l):
                max_area = min(height[ptr_l], height[ptr_r]) * (ptr_r - ptr_l)
        return max_area


if __name__ == '__main__':
    height_test = [1, 8, 6, 2, 5, 4, 8, 3, 7]
    print(Solution.max_area(height_test))
