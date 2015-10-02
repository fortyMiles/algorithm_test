def __change_number_to_bianry_string(number):
    '''
    changes a number to 32 bits binary format
    Args: int number
    Return: String, binary format of this number
    Raise: if the number is not a number, will raises TypeError
    '''
    binary_format = '{0:032b}'.format(number)
    return binary_format


def test_is_begin_with_zero(number):
    zero = '0'
    return __change_number_to_bianry_string(number).startswith(zero)


def find_missed_number():
