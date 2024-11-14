<div align="center">

# 📖 Get Next Line

</div>

<div align="center">

## 🔍 About the Project

</div>

The goal of the *Get Next Line* project is to develop a function that reads a single line at a time from a file or standard input. The function must handle subsequent calls, allowing the complete reading of a file, line by line.

<div align="center">

## ✨ Features

</div>

### 🎯 Mandatory Part
- **Function Definition**: `char *get_next_line(int fd);`
- **File Handling**: Reads from a given file descriptor (`fd`)
- **Line Return**: Returns the line read, including the newline character `\n` if present
- **Error Handling**: Returns `NULL` if an error occurs or if there is nothing left to read
- **Static Variable**: Uses static variables for managing buffer continuity across function calls
- **Memory Management**: Allocates memory for each line and frees it after each use, preventing memory leaks

### 🌟 Bonus Part
Your project includes bonus features, achieving a score of 125/100 by adding extra functionality:

- **Multiple File Descriptor Support**: The `get_next_line` function can handle multiple file descriptors simultaneously. For instance, it can alternate between reading from different file descriptors (e.g., fd 3, fd 4, fd 5) without losing the reading position of each.
- **Single Static Variable**: Efficiently manages file reading states across different descriptors using only one static variable.

<div align="center">

## 📋 Requirements

</div>

- **Language**: C
- **External Functions**: `read`, `malloc`, `free`
- **Forbidden Functions**: `lseek`, global variables
- **Testing with Different Buffer Sizes**: Must handle variable buffer sizes (e.g., 1, 42, 9999), which are set using the `-D BUFFER_SIZE=n` flag during compilation
- **Memory Safety**: All allocated memory must be properly freed

<div align="center">

## 🛠️ Compilation

</div>

Compile the project using:
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c
```

<div align="center">

## 💻 Usage

</div>

To use `get_next_line`, call the function in a loop to read each line from the file descriptor until `NULL` is returned:

```c
int fd = open("file.txt", O_RDONLY);
char *line;

while ((line = get_next_line(fd)) != NULL) {
    printf("%s", line);
    free(line);
}
close(fd);
```

<div align="center">

## 🔗 Project Link

</div>

For the complete code, visit my GitHub repository.

<div align="center">

## 🎯 Final Grade

![Grade](https://img.shields.io/badge/Grade-125%2F100-brightgreen)
</div>
