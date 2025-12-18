Algorithm Visualizer

Welcome to the Algorithm Visualizer!
This program allows users to interactively input, load, and visualize numerical data, and apply sorting algorithms with a graphical representation of the array in the console. It supports reading data from .xml and .ods files, as well as manual or random number entry.

Features

Interactive Command Menu: Easily select operations from a list of commands.

Data Input Options:

Enter numbers manually.

Generate random numbers.

Load numbers from .xml files.

Load numbers from .ods files.

Sorting Algorithms:

Bubble Sort

Insertion Sort

Visual Feedback: Console-based graphical representation of arrays, where each element is visualized as a vertical bar (#) corresponding to its value.

File Operations: Save and replace .ods files with new data.

Command Menu
This program contains the following commands:
1: Set numbers by hand
2: Set numbers random (not necessary at the start)
3: Sort elements with Bubble Sort
4: Sort elements with insertion Sort
6: Get Data from .xml file
7: Load Data in .xml file
8: Get Data from .ods file
9: Replace .ods File with new Data
q: Quit

Visual Output Example

The program represents arrays in a vertical bar chart. For example, after loading numbers from an XML file:

20 |                         #                                  
19 |                         #                                  
18 |                         #                                  
17 | #                       #     #                            
16 | #  #                    #     #                            
15 | #  #                    #     #                            
14 | #  #                    #     #     #        #             
13 | #  #                    #     #     #        #             
...
0  | #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  # 
-----------------------------------------------------------------
     0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19


The vertical axis (0 to max value) represents the value of each element.

The horizontal axis represents the element index in the array.

Each # symbol represents the magnitude of an element.

Usage Instructions

Compile the program

gcc -o algorithm_visualizer main.c


Run the program

./algorithm_visualizer


Follow the command menu to:

Enter numbers manually (Option 1)

Generate random numbers (Option 2)

Apply sorting algorithms (Options 3 & 4)

Load data from .xml or .ods files (Options 6 & 8)

Save or replace .ods files (Option 9)

Quit the program using q.

Notes

XML and ODS Parsing: The program can extract numeric data from structured XML/ODS files for visualization.

Visualization: Works best with arrays of up to 20 elements for clarity. Larger arrays will still work but may be harder to read in the console.

Sorting Visualization: After sorting, the vertical bar chart updates to show the new order.

Example Workflow

Load or generate an array of numbers.

Visualize the array in the console.

Choose a sorting algorithm to see the sorted result.

Optionally, save the sorted array to an .ods file.

Author

Developed as a learning project for algorithm visualization and file I/O handling in C.