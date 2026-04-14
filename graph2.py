import math
import matplotlib.pyplot as plt

x1 = [100, 500, 1000, 5000, 10000, 20000, 25000, 30000, 35000, 40000, 45000, 50000, 60000,70000,80000,90000,95000, 100000]
y1 = [0,0,0,0.12,0.26,0.44,0.59,0.35,0.51,0.86,0.76,1.06,0.82,0.97,1.57,1.9,2.39,2.01,]


##y3 = [n* math.log2(n) /1500000 for n in x1]

plt.plot(x1, y1, marker='o', label="Average")
##plt.plot(x1, y2, marker='o', label="worst")
##plt.plot(x1, y3,linestyle = '--', label="f(n) = nlogn")

plt.xlabel("Input Size (n)")
plt.ylabel("Time Taken (ms)")
plt.title("Input Size vs Time Taken")
plt.legend()
plt.grid(True)

plt.savefig("maxMin.png")
plt.show()