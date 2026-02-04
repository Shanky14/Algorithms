## PRACTICAL -1 
Aim
To implement the Bubble Sort algorithm and analyze the time taken to sort a list of numbers.

# Theory

Bubble Sort is a simple comparison-based sorting algorithm.
It works by repeatedly traversing the array and comparing adjacent elements.
If the elements are in the wrong order, they are swapped.

After each complete pass, the largest unsorted element “bubbles up” to its correct position at the end of the array.
This process continues until the entire array is sorted.

## GRAPH
![Graph for bubble sort](LAB%201/bubbleS.png)

## Time Complexity

Best Case: O(n) (when the array is already sorted, with optimization)

Average Case: O(n²)

Worst Case: O(n²)

## Space Complexity

O(1) (In-place sorting, no extra memory required)

## What the Code Does

This program sorts a list of randomly generated numbers using the Bubble Sort algorithm and measures the time taken.
The bubbleS(a) function implements the Bubble Sort logic.
It uses two nested loops to compare adjacent elements in the vector.
If an element is greater than the next element, they are swapped.
With each outer loop iteration, the largest element moves to the end of the array.
In the main() function, the number of elements is taken as input from the user.
Random numbers are generated and stored in a vector.
The sorting process is timed using the chrono library.
The program then displays the total time taken to sort the elements in milliseconds.
## Conclusion

Bubble Sort successfully sorts the array but is inefficient for large datasets due to its quadratic time complexity.
It is easy to understand and implement, making it suitable for learning purposes, but not recommended for performance-critical applications.

# PRACTICAL - 2

## Aim
To implement Horner’s method using recursion to represent a polynomial expression efficiently.

## Theory
Horner’s method is an efficient technique used to represent and evaluate polynomials.
It reduces the number of multiplications required by rewriting the polynomial in a nested form.

A polynomial of degree n − 1


can be rewritten using Horner’s method as:


This approach improves efficiency and simplifies polynomial evaluation.

## Time Complexity

O(n), where n is the number of coefficients

## Space Complexity

O(n) due to recursive function calls

## What the Code Does

This program prints the polynomial expression using Horner’s method through recursion.

The hornor(k, m, a) function recursively processes the coefficients of the polynomial stored in the vector a.
When the last coefficient is reached, it is printed and the recursion stops.

For each recursive call, the function prints an opening parenthesis and calls itself for the next coefficient.
After returning from recursion, it prints "x + " followed by the current coefficient and a closing parenthesis.

In the main() function, the number of coefficients is taken as input from the user.
The coefficients are stored in a vector and passed to the recursive function.

The output represents the polynomial in nested Horner’s form.

## Conclusion

Horner’s method provides an efficient way to represent and evaluate polynomials.
Using recursion, the polynomial is expressed in a clean and optimized nested format, reducing computational complexity compared to the standard polynomial form.

# PRACTICAL - 3
## Aim
To implement the Linear Search algorithm using recursion and measure the time taken to search for a key element.

## Theory
Linear Search is a simple searching algorithm that checks each element of the list sequentially until the desired element is found or the list ends.
In the recursive approach, the function compares the current element with the target value.
If a match is found, the index is returned.
Otherwise, the function calls itself for the next index.

This method is easy to understand but inefficient for large datasets.

## Time Complexity

Best Case: O(1) (key found at first position)
Average Case: O(n)
Worst Case: O(n)

## Space Complexity

O(n) due to recursive function calls

## What the Code Does

This program searches for a key element in a list of randomly generated numbers using recursive Linear Search.
The linearS(a, target, j) function recursively checks each element of the vector starting from index j.
If the index reaches the end of the vector, the function returns −1, indicating the key is not found.
If the current element matches the target, the index is returned.
Otherwise, the function calls itself with the next index.

In the main() function, the number of elements is taken as input from the user.
Random numbers are generated and stored in a vector.
A random key value is selected for searching.

The time taken for the search operation is measured using the chrono library and displayed in nanoseconds along with the index result.

## Conclusion

Linear Search successfully finds the target element if it exists in the list.
Although simple to implement, it is inefficient for large datasets due to its linear time complexity.
The recursive approach demonstrates the use of recursion in searching algorithms.

# PRACTICAL - 4

## Aim
To generate all possible permutations of a given string using recursion and backtracking.

## Theory
Permutation generation is the process of arranging the elements of a string in all possible orders.
For a string of length n, the total number of permutations is n!.

This program uses recursion with backtracking to generate permutations.
At each recursive step, the algorithm fixes one character and recursively permutes the remaining characters.
After each recursive call, the original order is restored using backtracking.

## Time Complexity

O(n!), where n is the number of characters

## Space Complexity

O(n) due to recursive call stack

## What the Code Does
This program generates and prints all permutations of a string entered by the user.

The permGen(a, k, n) function generates permutations recursively.
If k == n, a complete permutation is formed and printed.
Otherwise, the function iterates from index k to n − 1, swapping the current character with each subsequent character.

After each swap, the function calls itself for the next position (k + 1).
Once the recursive call returns, the characters are swapped back to restore the original order.
This backtracking step ensures all permutations are generated without duplication.
  In the main() function, the number of characters and the string are taken as input from the user.
  The recursive function is then called to display all possible permutations.

## Conclusion
The program successfully generates all permutations of a string using recursion and backtracking.
Although the algorithm is computationally expensive due to factorial time complexity, it is effective for small input sizes and demonstrates the concept of recursive backtracking clearly.

# PRACTICAL - 5
## Aim
To implement the Selection Sort algorithm and analyze the time taken to sort a list of numbers.

## Theory
Selection Sort is a simple comparison-based sorting algorithm.
It works by repeatedly selecting the smallest element from the unsorted portion of the array and placing it at the beginning.
In each pass, the algorithm finds the minimum element from the remaining unsorted elements and swaps it with the element at the current position.
This process continues until the entire array is sorted.

## GRAPH 

![Graph for selection sort](LAB%201/selectionS.png)

## Time Complexity

Best Case: O(n²)
Average Case: O(n²)
Worst Case: O(n²)

## Space Complexity

O(1) (In-place sorting algorithm)

## What the Code Does
This program sorts a list of randomly generated numbers using the Selection Sort algorithm and measures the time taken.

The selectionS(a) function implements the Selection Sort logic.
For each position i, the function assumes the element at index i is the minimum.
It then scans the remaining unsorted portion of the array to find the actual minimum element.

Once the smallest element is found, it is swapped with the element at index i.
This places the minimum element in its correct position after each iteration.

In the main() function, the number of elements is taken as input from the user.
Random numbers are generated and stored in a vector.
The time taken for the sorting operation is measured using the chrono library and displayed in nanoseconds.

## Conclusion
Selection Sort correctly sorts the array but is inefficient for large datasets due to its quadratic time complexity.
However, it performs fewer swaps compared to Bubble Sort and is useful for understanding basic sorting concepts.

# PRACTICAL -6 
## Aim
To solve the Tower of Hanoi problem using recursion and display the sequence of moves required to transfer the disks.

## Theory
The Tower of Hanoi is a classical problem that demonstrates the concept of recursion.
It consists of three pegs: source, destination, and auxiliary.

The objective is to move n disks from the source peg to the destination peg by following these rules:
Only one disk can be moved at a time.
A larger disk cannot be placed on top of a smaller disk.
An auxiliary peg can be used for intermediate moves.
The recursive solution breaks the problem into smaller subproblems until the base case is reached.

## Time Complexity

O(2ⁿ), where n is the number of disks
## Space Complexity

O(n) due to recursive call stack

## What the Code Does
This program prints the steps required to solve the Tower of Hanoi problem using recursion.
The TOH(n, src, dest, ext) function moves n disks from the source peg to the destination peg using an auxiliary peg.

If n == 1, the function directly moves the disk from the source to the destination.
Otherwise, it first moves n − 1 disks from the source peg to the auxiliary peg.
Then it moves the largest disk from the source peg to the destination peg.
Finally, it moves the n − 1 disks from the auxiliary peg to the destination peg.

In the main() function, the number of disks is taken as input from the user, and the recursive function is called to display all the moves.

## Conclusion
The Tower of Hanoi problem is efficiently solved using recursion by breaking it into smaller subproblems.
Although the number of moves grows exponentially, the problem clearly illustrates recursive thinking and divide-and-conquer strategy.

# PRACTICAL - 7
## Aim
To calculate the number of tips required to reduce a given value below a specified limit using recursion.

## Theory
This program demonstrates the use of recursion to repeatedly reduce a value by a fixed percentage until a stopping condition is met.
In each recursive call, the value is reduced by 42.5% of its current value.
The process continues until the value becomes less than 1.0.
A counter is maintained to keep track of the number of recursive calls (tips) required to reach the stopping condition.

## Time Complexity 
O(k), where k is the number of recursive reductions required

## Space Complexity
O(k) due to recursive call stack

## What the Code Does 
This program calculates how many times a value must be reduced by 42.5% until it becomes less than 1.0.

The findTips(v, tips) function checks if the current value v is greater than or equal to 1.0.
If true, the tip counter is incremented, and the value is reduced by 42.5% of its current value.
The function then calls itself with the updated value and tip count.

When the value becomes less than 1.0, the recursion stops and the total number of tips is returned.
In the main() function, the initial value is set to 40, and the recursive function is called.
The result is printed as the total number of tips required.

## Conclusion
The program successfully demonstrates the use of recursion for repetitive reduction problems.
It shows how recursive calls can be used to model real-world scenarios involving gradual decrease until a threshold is reached.

# Practical-8: Power of a Number
## Aim
To implement and compare two methods to calculate the value of a number raised to the power **n** using recursion.

## Theory
The optimized recursive method calculates the result by dividing the exponent into halves, which reduces the number of recursive calls.
The simple recursive method calculates the result by multiplying the base repeatedly until the exponent becomes zero.

## Time Complexity
- Optimized recursive method: O(log n)
- Simple recursive method: O(n)

## Space Complexity
- Optimized recursive method: O(log n)
- Simple recursive method: O(n)

## What the Code Does
This program calculates the power of a number using two different recursive approaches.

The **powerRec(x, n)** method uses a divide and conquer approach.  
If the exponent is zero, it returns **1**.  
If the exponent is negative, it converts it into a positive exponent.

The method recursively computes **x^(n/2)** and stores it in a variable.  
If the exponent is even, it multiplies the half result with itself.  
If the exponent is odd, it multiplies the result with **x** once more.

This approach is efficient and works well for large values of **n**.

The **powerRec2(x, n)** method is a simple recursive approach.  
It multiplies **x** with the result of the function called with **n − 1**.  
This process continues until the exponent becomes zero.
This method is easier to understand but slower for large values of **n**.

## Conclusion
Both methods correctly calculate the power of a number.  
The optimized recursive method is more efficient due to fewer recursive calls.

# PRACTICAL - 9
## Aim
To find the missing number in a sequence of consecutive integers using the XOR operation.

## Theory
Given an array containing n distinct numbers taken from the range 0 to n, one number is missing.
The XOR-based method efficiently identifies the missing number without using extra space.

Properties of XOR:
** a ^ a = 0 **
** a ^ 0 = a **

XOR is commutative and associative
Algorithm idea:

XOR all numbers from 0 to n.
XOR the result with all elements in the array.
The remaining value is the missing number, because all other numbers cancel out.

## Time Complexity
O(n), where n is the size of the array

## Space Complexity
O(1), constant extra space

## What the Code Does
This program finds the missing number in a given integer array using XOR.

The missingNum(nums) function:
XORs all numbers from 0 to n and stores the result in x.
XORs all elements in the input array with x.
Returns x, which now holds the missing number.

In the main() function, a vector of integers is defined (for example {0, 1, 2, 4}).
The function is called, and the missing number (3 in this case) is printed.

## Conclusion
The XOR method provides an efficient way to find the missing number using linear time and constant space.
It avoids sorting or extra arrays and demonstrates the power of bitwise operations in problem-solving.

## Practical-10 Duplicate number

## Aim 

To implement a C++ program that identifies a duplicate element in an array using a comparison-based approach.

## Theory

A duplicate element is a value that appears more than once in an array.
In this algorithm, the array is processed by comparing selected elements with other elements in the array to detect repetition.

The algorithm uses a simple nested loop technique:

The array size is divided to determine a comparison range.

A temporary element is selected.

This element is compared with other elements in the array.

If a match is found, that element is considered a duplicate.

This approach is easy to understand but not efficient for large datasets.

## Time Complexity

Best Case: O(n) (duplicate found early)
Average Case: O(n²)
Worst Case: O(n²) (duplicate found at the end)

## Space Complexity

O(1) (no extra memory used)

## What the Code Does

The program initializes an integer array containing duplicate values.
The function duplicate():

Divides the array size for comparison.

Selects a temporary element.

Compares it with other elements in the array.

Returns the duplicate element if found.

The main function:

Calculates the array size.

Calls the duplicate() function.

Prints the duplicate element.

Conclusion

The program successfully detects a duplicate element in the given array.
Although the logic is simple and easy to understand, the algorithm is inefficient for large inputs due to its quadratic time complexity.
This method is suitable only for small datasets or academic understanding.

## Practical-11: Binary Search (Recursive)
## Aim

To implement recursive binary search on a sorted array and measure its execution time.

## Theory

Binary Search is an efficient searching algorithm that works on a sorted array.
It repeatedly divides the search space into two halves and compares the target element with the middle element.
If the target equals the middle element, the search is successful.
If the target is smaller, the search continues in the left half.
If the target is larger, the search continues in the right half.
This divide-and-conquer approach significantly reduces the number of comparisons.

## GRAPH

![Graph for binary search](LAB%202/BinaryS.png)

## Time Complexity

Best Case: O(1)
Average Case: O(log n)
Worst Case: O(log n)

## Space Complexity

O(log n) (due to recursive call stack)

## What the Code Does

The program generates random numbers and stores them in a vector.
The array is shuffled and then sorted, which is required for binary search.
The largest element is chosen as the target.
The function binaryS() is called recursively:
If start > end, it returns -1 (element not found).
It calculates the middle index.
If the middle element matches the target, it returns the index.
Otherwise, it searches in the appropriate half.
The execution time is measured using the chrono library.
The array size and execution time are stored in binaryS.txt.

## Conclusion

Recursive Binary Search efficiently finds an element in a sorted array using fewer comparisons.
Its logarithmic time complexity makes it suitable for large datasets.

## Practical-12: Insertion Sort
## Aim

To implement the Insertion Sort algorithm and analyze its execution time.

## Theory

Insertion Sort is a simple sorting algorithm that works by inserting elements into their correct position in a sorted part of the array.
The array is divided into sorted and unsorted parts.
Elements from the unsorted part are picked one by one and placed at the correct position in the sorted part.
It is similar to sorting playing cards in hand.
Insertion Sort is easy to understand but inefficient for large inputs.

## GRAPH 

![Graph for Insertion Sort](LAB%202/insertionS.png)
## Time Complexity

Best Case: O(n) (already sorted array)
Average Case: O(n²)
Worst Case: O(n²) (reverse sorted array)

## Space Complexity

O(1) (in-place sorting)

## What the Code Does

The program generates random elements and stores them in a vector.
The function insertionS() sorts the array:
It selects a key element.
Shifts all larger elements one position to the right.
Inserts the key at its correct position.
The execution time is measured using the chrono library.
The array size and execution time are written into insertionS.txt.

## Conclusion

Insertion Sort correctly sorts the array using a simple approach.
Although it is inefficient for large datasets, it is useful for small inputs and nearly sorted arrays.