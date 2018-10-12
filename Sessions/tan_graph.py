import numpy as np
import math
import matplotlib.pyplot as plt

# x = np.arange(1, 11)
# print(x)
# y = np.empty([])

# for num in x:
#     y_val = np.tan(num)
#     y = np.append(y, y_val)

# print(y)

x = range(1, 10)
print(x)

y = []

for num in x:
    y_val = np.tan(num)
    y.append(y_val)

print(y)

plt.plot(x, y, "b-")
plt.savefig("Tan Graph.pdf")   