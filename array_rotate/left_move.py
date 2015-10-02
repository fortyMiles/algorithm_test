def move_left(array, i):
    i %= len(array)
    temp = array[:i]
    temp_2 = array[i:]
    return temp_2 + temp


if __name__ == '__main__':
    array = []
    number = int(raw_input("input the number of array length"))
    array = [i for i in range(number)]
    left = int(raw_input("input the left number"))
    print(move_left(array, left))
