"""
* bit map implemented by python
* Author: Minchiuan Gao (mqgao@outlook.com)
"""


class BitVector:
    def __init__(self, length):
        self.bit_array = [0] * (length/32)

    def set_bit(self, number):
        index = number / 32
        position = number % 32

        flag = 1
        flag = flag << position
        self.bit_array[index] |= flag

    def clear_bit(self, number):
        index = number / 32
        position = number % 32
        flag = 1

        flag <<= position
        flag = ~flag  # 1111111111111111110111111111111111111
        self.bit_array[index] &= flag

    def test_bit(self, number):
        index = number / 32
        position = number % 32
        flag = 1

        flag = flag << position

        if self.bit_array[index] & flag != 0:
            return 1
        else:
            return 0


def test():
    total_number = 100000000
    bitVector = BitVector(total_number)

    number_file = file('number.data', 'r')

    for line in number_file.xreadlines():
        number = int(line.rstrip())
        # print line.rstrip()
        if bitVector.test_bit(number) == 0:
            bitVector.set_bit(number)
        else:
            print(' dulipcated number ' + line)

    sorted_file = file('sorted.data', 'w+')
    for i in range(total_number):
            sorted_file.write(str(i) + '\n')


def python_sort():
    array = []
    number_file = file('random.data', 'r')
    for line in number_file.xreadlines():
        array.append(int(line.rstrip()))

    array = sorted(array)
    sorted_file = file('system_sorted_file.data', 'w+')
    for i in array:
        sorted_file.write(str(i)+'\n')


if __name__ == '__main__':
    import time

    start = time.time()
    test()
    print 'used time == ' + str(time.time() - start)

