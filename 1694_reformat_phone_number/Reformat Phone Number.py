class Solution1:
    """ While循环 + 字符串操作
    @date 2022/09/30
    @cplex T:74% (36ms)
           S:20% (15MB)
    """

    def reformatNumber(self, number: str) -> str:
        counter = 0
        ptr = 0

        while ptr < len(number):
            if number[ptr].isdigit():
                counter += 1
            else:
                number = number[:ptr] + number[ptr + 1:]
                ptr -= 1

            if counter == 4:
                number = number[:ptr] + '-' + number[ptr:]
                counter = 1
                ptr += 1

            ptr += 1

        if number[-2] == '-':
            number = number[:-3] + '-' + number[-3] + number[-1]

        return number


class Solution2:
    """ While循环 + 列表操作
    @date 2022/09/30
    @cplex T:98% (28ms)
           S:11% (15.1MB)
    """

    def reformatNumber(self, number: str) -> str:
        number_list = list(number)

        counter = 0
        ptr = 0

        while ptr < len(number_list):
            if number_list[ptr].isdigit():
                counter += 1
            else:
                number_list.pop(ptr)
                ptr -= 1

            if counter == 4:
                number_list.insert(ptr, '-')
                counter = 1
                ptr += 1

            ptr += 1

        if number_list[-2] == '-':
            number_list.pop(-2)
            number_list.insert(-2, '-')

        return ''.join(number_list)


class Solution3:
    """ While过滤字符串
    @date 2022/09/30
    @cplex T:45% (40ms)
           S:11% (15.1MB)
    """

    def reformatNumber(self, number: str) -> str:
        t = ''.join([c for c in number if c.isdigit()])  # Tail
        h = ''  # Head

        while len(t) > 4:
            h += t[:3] + '-'
            t = t[3:]

        if len(t) == 4:
            return h + t[0:2] + '-' + t[2:4]
        else:
            return h + t


Solution = Solution2

if __name__ == '__main__':

    tests = [
        ('1-23-45 6', '123-456'),
        ('123 4-567', '123-45-67'),
        ('123 4-5678', '123-456-78')
    ]

    for i, (case, result) in enumerate(tests):
        print(f"Case[{i + 1}/{len(tests)}]")

        assert Solution().reformatNumber(case) == result, f"{Solution().reformatNumber(case)} !-> {result}"

    print("All done")
