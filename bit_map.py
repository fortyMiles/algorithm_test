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

if __name__ == '__main__':
    total_number = 1000000
    bitVector = BitVector(total_number)

    number_file = file('number.data', 'r')

    for line in number_file.xreadlines():
        number = int(line.rstrip())
        # print line.rstrip()
        bitVector.set_bit(number)

    sorted_file = file('sorted.data', 'w+')
    for i in range(total_number):
        if bitVector.test_bit(i) == 1:
            sorted_file.write(str(i) + '\n')
