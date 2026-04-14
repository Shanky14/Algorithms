import math
import matplotlib.pyplot as plt

x1 = [100, 500, 1000, 5000, 10000, 15000]
y1 = [0.2,2.55,7.3,256.75,1023.55,2293.45]


##y3 = [n* math.log2(n) /1500000 for n in x1]

plt.plot(x1, y1, marker='o', label="Average")
##plt.plot(x1, y2, marker='o', label="worst")
##plt.plot(x1, y3,linestyle = '--', label="f(n) = nlogn")

plt.xlabel("Input Size (n)")
plt.ylabel("Time Taken (ms)")
plt.title("Input Size vs Time Taken")
plt.legend()
plt.grid(True)

plt.savefig("dijkastra.png")
plt.show()