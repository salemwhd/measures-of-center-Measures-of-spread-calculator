# Statistical Measures Calculator

This project is a C++ program designed to calculate various statistical measures for a set of numbers. It provides functionalities to calculate measures of center and measures of spread. The program allows users to input a set of numbers and then select the desired statistical measure(s) to calculate.

## Features

- Calculation of Measures of Center:
  - Mean
  - Median
  - Mode

- Calculation of Measures of Spread:
  - Range
  - Quartiles (First Quartile, Third Quartile, Interquartile Range)
  - Standard Deviation
  - Variance

## How to Use

### 1. Input

- Run the program and provide a set of numbers in a single line when prompted.

### 2. Select Type of Calculation

- Choose the type of calculation:
  - **1: Measures of Center**
  - **2: Measures of Spread**

### 3. Choose Specific Measure(s)

- Depending on the selected type:
  - For Measures of Center:
    - Select the desired measure: Mean, Median, Mode, or All.
  - For Measures of Spread:
    - Choose the measure(s) to calculate: Range, Quartiles, Standard Deviation, Variance, or All.

### 4. Repeat or Exit

- After calculation, you can choose to perform other calculations or exit the program:
  - **Y: Yes** to perform more calculations.
  - **N: No** to exit the program.

## Instructions

- Ensure that the input set of numbers is provided in a single line, separated by spaces.
- Follow the prompts and input the appropriate choices as per the instructions.
- In case of wrong input, the program will prompt again to ensure correct input.

## Implementation Details

The program is implemented using C++ and relies on the standard library. It includes functions to calculate various statistical measures such as mean, median, mode, range, quartiles, standard deviation, and variance.

## Note

- This program assumes valid input for the set of numbers.
- For some statistical measures (e.g., mode), if there is no mode, the program indicates accordingly.
- For quartiles, if the number of elements in the set is even, it calculates the quartiles accordingly.

## Example

```cpp
Enter set of numbers in a single line:
1 2 3 4 5 6 7 8 9
Choose type of measures to calculate:
1: Measures of center
2: Measures of spread
1
Please, choose a measure to calculate:
N: Mean
I: Median
D: Mode
A: All
A
Mean= 5
Median= 5
Mode= -1

DO you want to do other calculations?
Y: Yes
N: No
Y
Choose type of measures to calculate:
1: Measures of center
2: Measures of spread
2
Please, choose a measure to calculate:
R: Range
Q: Quartiles
S: Standard deviation
V: Variance
A: All
A
Range= 8
First quartile= 3
Second quartile= 5
Third quartile= 7
Interquartile range= 4
Standard deviation= 2.58199
Variance= 6.66667

DO you want to do other calculations?
Y: Yes
N: No
N
