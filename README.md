# get_next_line
get_next_line is a project from 42 that requires implementing a function to read a line from a file descriptor. The function must return each line of the file one by one until the end of the file is reached. Each line should be terminated by a newline character (\n), and the function should work efficiently even with large files.

## Project Overview
The goal of the project is to implement a function, get_next_line(), which reads a file descriptor and returns the next line each time it's called. This project involves understanding file reading operations, managing memory efficiently, and using static variables to maintain the state between function calls.

## How I Solved It
I implemented get_next_line() by handling the reading of characters from the file descriptor and storing them until a newline character (\n) is encountered or the end of the file is reached. The key challenge was managing the file descriptor’s state across multiple calls of the function.

## Newline Handling
A crucial part of this project is ensuring that the newline (\n) character at the end of each line is correctly detected. The function should read characters one by one and buffer them until a newline is encountered. Once the newline is found, the buffer is returned as the result of the function.

__The read() Function__
The read() function is used to read data from a file descriptor. It reads the file descriptor into a buffer and returns the number of bytes read. In this project, read() is used inside a loop to continue reading the file until we encounter a newline or the end of the file.

__Key Steps:__
__Buffering:__ Characters are buffered until the newline is found or the end of the file is reached.

Efficiency: Since the read() function may not return all the data at once, the function keeps track of the buffer and processes the data in chunks.

## Static Variables
A static variable is used in this project to maintain the state between calls to get_next_line(). The static variable ensures that the buffer persists across multiple calls to the function. This is necessary because each call to get_next_line() only reads part of the file, and we need to remember the state between calls.

Example of Static Variable Usage:
```c
#include <stdio.h>

int count_calls(void) 
{
    static int count = 0;  // Static variable to retain its value between function calls
    count++;                // Increment the counter
    return count;           // Return the current count
}

int main(void) 
{
    printf("Call count: %d\n", count_calls());  // Output: 1
    printf("Call count: %d\n", count_calls());  // Output: 2
    printf("Call count: %d\n", count_calls());  // Output: 3
    return 0;
}
```
__In this example:__

buffer is a static variable that holds the data read from the file descriptor.

The static variable ensures that when get_next_line() is called multiple times, it retains the data between calls, allowing the function to read the next part of the file correctly.
__Static Variable__: The count variable is declared as static. This means it is initialized only once and retains its value between function calls.
Behavior: Every time count_calls() is called, the count variable is incremented, and the updated value is returned. The value of count persists between calls to the function, even though the function itself is called multiple times.
__Why is this useful in your project?__
In your get_next_line project, a similar principle applies. The overflow_line static variable helps retain the state (e.g., the remaining data to process) between calls to get_next_line(). Without a static variable, the function would lose track of where it left off between multiple calls.

Does this simple example help clarify the usage of static variables?

__Handling Multiple File Descriptors (Bonus)__
One of the challenges of this project is handling multiple file descriptors. The code above can be easily extended to support multiple file descriptors by modifying the static variable. Instead of using a single static variable, we can store a separate static variable for each file descriptor.

To handle this, a static array of pointers (or a more efficient data structure) is used to track the overflow_line for each file descriptor:

## Conclusion
The use of read() and static variables is critical for solving this problem efficiently. The static variable keeps track of the data read so far, while read() ensures that the data is retrieved in chunks. The newline handling at the end of each line guarantees that each call to get_next_line() returns a full line of text.

