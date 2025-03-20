import random

# Linear Regression Data
n1 = 10000000
print("Generating Linear Regression Data of 2n: " + str(n1*2))
x = [random.randrange(1, 100000) for i in range(n1)]
y = [random.randrange(1, 100000) for i in range(n1)]

f = open("linear_regression_data.txt","w+")
f.write(' '.join(map(str, x))+"\n")
f.write(' '.join(map(str, y)))
f.close()
print("Finished")

# Heap Sort Data
n2 = 10000000
print("Generating Heap Sort Data of n: " + str(n2))
hs_data = [random.randrange(1, 100000) for i in range(n2)]

f = open("heap_sort_data.txt","w+")
f.write(' '.join(map(str, hs_data)))
f.close()
print("Finished")