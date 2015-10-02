import random

total_number = 100000000

random_file = file('random.data', 'w+')
for i in range(total_number):
    random_number = random.randint(0, total_number)
    random_file.write(str(random_number) + '\n')
