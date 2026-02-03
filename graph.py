import matplotlib.pyplot as plt
n_values = []
durations = []
with open("binaryS.txt", "r") as f:
    for line in f:
        line = line.strip()
        if not line or line.startswith("array"):  
            continue

        parts = line.split()
        if len(parts) != 2:
            print(f"Skipping invalid line: {line}")
            continue

        n, t = map(int, parts)
        n_values.append(n)
        durations.append(t)  

plt.plot(n_values, durations, marker='o', color='blue')
plt.xlabel("Array Size (n)")
plt.ylabel("Time (ns)")
plt.title("Binary Search Execution Time")
plt.grid(True)
plt.savefig("BinaryS.png")
plt.show()
