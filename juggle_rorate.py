'''
    Test juggle rotation.
    Author: Minchuian Gao <mqgao@outlook.com>
    Data: 2015-Oct-2
'''


def juggle_rotate(array, i):
    length = len(array)
    # moved_number = 0
    index = 0
    # while(moved_number < length):
    # temp = array[:i]
    temp = [0] * i
    for t in range(i):  # to 0,1,2
        temp = array[t]
        index = t
        while index < length:
            array[index] = array[(index + i) % length]
            index += i


if __name__ == '__main__':
    n = 10
    array = [i for i in range(n)]
    i = 3
    juggle_rotate(array, i)
    print(array)
