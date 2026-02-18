import math
import matplotlib.pyplot as plt

x1 = [10,100,1000,5000,10000,15000,20000,25000,30000,35000,40000,45000]
y1 = [0.015,0.067,0.151,0.808,1.833,2.729,3.616,4.581,5.626,6.719,7.788,8.982,]


y3 = [n* math.log2(n) /1500000 for n in x1]

plt.plot(x1, y1, marker='o', label="Average")
##plt.plot(x1, y2, marker='o', label="worst")
plt.plot(x1, y3,linestyle = '--', label="f(n) = nlogn")

plt.xlabel("Input Size (n)")
plt.ylabel("Time Taken (ms)")
plt.title("Input Size vs Time Taken")
plt.legend()
plt.grid(True)

plt.savefig("QuickS.png")
plt.show()