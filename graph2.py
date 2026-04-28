import math
import matplotlib.pyplot as plt

x1 = [100, 200, 500, 1000, 2000, 5000, 7000, 10000]
y1 = [0,1.05,6.4,27.05,106.85,649.05,1270.75,2624.95]


##y3 = [n* math.log2(n) /1500000 for n in x1]

plt.plot(x1, y1, marker='o', label="Average")
##plt.plot(x1, y2, marker='o', label="worst")
##plt.plot(x1, y3,linestyle = '--', label="f(n) = nlogn")

plt.xlabel("Input Size (n)")
plt.ylabel("Time Taken (ms)")
plt.title("Input Size vs Time Taken")
plt.legend()
plt.grid(True)

plt.savefig("KnapSackDP.png")
plt.show()