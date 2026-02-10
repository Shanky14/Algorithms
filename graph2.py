import math
import matplotlib.pyplot as plt

x1 = [10,100,1000,5000,10000,15000,20000,25000,30000,35000,40000,45000]
y1 = [0.008,0.048,0.135,0.871,1.826,3.096,4.192,5.42,6.548,7.801,8.979,10.457]
y2 = [0.017,0.051,0.104,0.752,1.745,2.834,3.783,5.056,6.232,7.277,8.648,9.63]

y3 = [n* math.log2(n) /1500000 for n in x1]

plt.plot(x1, y1, marker='o', label="Algorithm 1")
plt.plot(x1, y2, marker='o', label="Algorithm 2")
plt.plot(x1, y3,linestyle = '--', label="f(n) = nlogn")

plt.xlabel("Input Size (n)")
plt.ylabel("Time Taken (ms)")
plt.title("Input Size vs Time Taken")
plt.legend()
plt.grid(True)

plt.savefig("QuickSort.png")
plt.show()