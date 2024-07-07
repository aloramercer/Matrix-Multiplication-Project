# Matrix Operation Program

## Overview
This program performs a custom matrix operation \( A = B \unicode{x2218} C \) where:
- \( B \) is a randomly generated square input matrix.
- \( C \) is a randomly generated square core matrix.
- \( A \) is the resulting output matrix after performing the operation.

## Custom Operation 
1. **Initial Setup**: 
   - The core matrix \( C \) is aligned with the top-left corner of the input matrix \( B \).
   - Elements of \( C \) are multiplied by corresponding elements in \( B \).
   - The sum of these products is written to the corresponding cell in the result matrix \( A \).

2. **Shifting and Calculating**:
   - Shift \( C \) one cell to the right and repeat the multiplication and summing process.
   - Continue until \( C \) reaches the end of the current row.
   - Move \( C \) to the beginning of the next row and repeat until the entire input matrix \( B \) is processed.

3. **Output Matrix Size**:
   - The size of the output matrix \( A \) is calculated as:
     
     \[ \text{output\_row\_size} = (\text{input\_row\_size} - \text{core\_row\_size}) + 1 \]

## Requirements
- **Dynamic Allocation**: Matrices must be declared dynamically.
- **Random Generation**:
  - Input matrix \( B \): Size between 5x5 and 20x20, values between 10-20.
  - Core matrix \( C \): Size between 2x2 and 5x5, values between 1-10.
- **Menu Options**:
  1. Generate new matrices and store in "data.txt".
  2. Read matrices from "data.txt".

## Usage
1. **Compile the Program**:
   ```sh
   g++ -o matrix_operation matrix_operation.cpp
## Example File Format (data.txt)
   ```sh
input matrix
10 12 15 14 20
11 19 16 18 17
14 15 10 13 16
12 13 18 20 15
11 17 16 15 19
core matrix
5 7
8 4
```
## Example File Format (data.txt)
   ```sh
Press 1-To generate new matrix or press 2-To read the matrices
1
The Output Matrix:
8 7 6 5
9 8 7 6
10 9 8 7
11 10 9 8
```

## Additional Information
* https://www.codespeedy.com/how-to-dynamically-allocate-a-2d-array-in-cpp/
* https://www.techiedelight.com/dynamic-memory-allocation-in-c-for-2d-3d-array/
* https://www.guru99.com/cpp-dynamic-array.html
* https://stackoverflow.com/questions/936687/how-do-i-declare-a-2d-array-in-c-using-new

