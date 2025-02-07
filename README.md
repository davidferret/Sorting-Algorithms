# Sorting Algorithms

This C project sorts numerical data using various sorting algorithms and offers the flexibility to input data either manually or by loading it from a file. You can choose to sort the data in ascending or descending order, and the sorted result can be saved to a file for future reference.

The way it works is by allowing you to input a list of numbers, either by entering them one at a time or by loading them from a file. You then select whether you want the data sorted in ascending or descending order. The program supports multiple sorting algorithms, including Bubble Sort, Quick Sort, and Merge Sort, each optimized for performance with features like early stopping for Bubble Sort and efficient implementations for the other algorithms. Once sorted, the results can be saved to a file for future use.

I built this project to explore sorting algorithms and their performance. It was an interesting challenge to implement different algorithms and then optimize them. I also wanted to make the project interactive, so users can experiment with different methods and observe how the sorting process works in real time.

## Example Output
```
Choose input method:
1 - Manual Entry
2 - Load from File
Enter choice: 1
How many numbers?: 5
Enter a number (1 of 5): 42
Enter a number (2 of 5): 17
Enter a number (3 of 5): 58
Enter a number (4 of 5): 4
Enter a number (5 of 5): 30

Choose sorting order:
1 - Ascending
2 - Descending
Enter choice: 1

Choose sorting algorithm:
1 - Bubble Sort
2 - Quick Sort
3 - Merge Sort
Enter choice: 2

Sorted Numbers: 4, 17, 30, 42, and 58

Enter filename to save sorted data: sorted_numbers.txt
Sorted data saved to sorted_numbers.txt

```

