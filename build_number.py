K = 1000000

number_file = file('number.data', 'wb+')

for i in reversed(range(K)):
    number_file.write(str(i) + '\n')
