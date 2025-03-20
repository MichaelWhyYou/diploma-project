with open("linear_regression_data.txt") as f:
    x = list(map(int, f.readline().split()))
    y = list(map(int, f.readline().split()))

def linear_regression(x, y):
    n = len(x)
    sum_x = sum(x)
    sum_y = sum(y)
    sum_xy = sum([x[i] * y[i] for i in range(n)])
    sum_x2 = sum([x[i]**2 for i in range(n)])
    slope = (n * sum_xy - sum_x * sum_y) / (n * sum_x2 - sum_x**2)
    intercept = (sum_y - slope * sum_x) / n
    return slope, intercept

slope, intercept = linear_regression(x, y)

print("Slope: ", slope)
print("Intercept: ", intercept)