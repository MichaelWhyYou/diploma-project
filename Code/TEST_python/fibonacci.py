# Function for nth Fibonacci number, Time complexity = O(n), Space complexity = O(1). Multi-variable loop with simple addition
def Fibonacci(n):

	a, b, c = 0, 1, 0
	for i in range(0, n):
		c = a
		a = b
		b = c + b
	return a

# Driver Program
Fibonacci(1000000) #1000000 = default