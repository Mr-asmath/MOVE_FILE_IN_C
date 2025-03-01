# File Mover Program

## Description
This is a simple C program that moves a file from one location to another. It achieves this by:
1. Reading the contents of the source file.
2. Writing the contents to a new destination file.
3. Deleting the original source file after successful copying.

## How It Works
- The program takes two command-line arguments:
  - **Source file** (file to be moved)
  - **Destination file** (new file location)
- It opens the source file in read mode and the destination file in write mode.
- It reads one byte at a time from the source file and writes it to the destination file.
- After successfully copying, it deletes the source file.

## Compilation and Execution
### **Step 1: Compile the program**
Use the GCC compiler to compile the program:
```sh
gcc file_mover.c -o file_mover
```

### **Step 2: Run the program**
```sh
./file_mover file1.txt file2.txt
```
This moves `file1.txt` to `file2.txt`.

## Error Handling
- If the source file cannot be opened, the program prints an error message.
- If the destination file cannot be created, it displays an error message and exits.
- If deleting the source file fails, it shows an error message.

## Example Usage
```sh
echo "Hello, World!" > test.txt
./file_mover test.txt new_test.txt
cat new_test.txt  # Output: Hello, World!
```

## Dependencies
- GCC (GNU Compiler Collection)
- Standard C libraries (`stdio.h`, `stdlib.h`, `fcntl.h`, `unistd.h`)

## Notes
- The program reads and writes **one byte at a time**, which may be inefficient for large files.
- File permissions for the destination file are set to `0777` (read, write, execute for all users).

## License
This project is open-source and distributed under the MIT License.

