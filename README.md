# Colorify

` Colorify ` is a lightweight and interactive console application that allows users to customize and colorize their text phrases using a variety of background colors, foreground colors, and text styles.<br> With an easy-to-use interface, users can experiment with different combinations to create visually appealing and colorful text outputs.

## Preview
<br>

  |       <br><p align="center"> ` Program Main Preview ` </p>      |
  | :----------------------------------------------: |
  | <br> <a>&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;<img src=https://github.com/ababdelo/Colorify/blob/preview/preview/main.png width="700"> &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;</a> <br><br> |

  |       <p align="center"> `Program Success_1` </p>       |    <p align="center"> `Program Success_2` </p>     |       <p align="center"> `Program Success_3` </p>       |
  | :----------------------------------------------: | :------------------------------------------: | :----------------------------------------------: |
  | <br> <a><img align="center" src=https://github.com/ababdelo/Colorify/blob/preview/preview/success_1.png> </a> <br><br> | <br> <a> <img align="center" src=https://github.com/ababdelo/Colorify/blob/preview/preview/success_2.png> </a> <br><br> | <br> <a><img align="center" src=https://github.com/ababdelo/Colorify/blob/preview/preview/success_3.png> </a> <br><br> |

  |       <p align="center"> `Program Failure_1` </p>       |    <p align="center"> `Program Failure_2` </p>     |
  | :----------------------------------------------: | :------------------------------------------: |
  | <br> <a><img align="center" src=https://github.com/ababdelo/Colorify/blob/preview/preview/failure_1.png> </a> <br><br> | <br> <a> <img src=https://github.com/ababdelo/Colorify/blob/preview/preview/failure_2.png> </a> <br><br> |

<br>

## Features:

- Choose from a palette of background and foreground colors.
- Apply different text styles to your phrases.
- Clear the console easily for a fresh start.
- Interactive and user-friendly interface.

## Important Note:

Before running ` Colorify `, ensure that your system meets the following requirements:

### Prerequisites:

- **C++ Compiler (e.g., GCC):**
  - The program relies on a ` C++ compiler ` to build and run. Ensure that you have a ` C++ compiler ` installed on your system.
- **Make Tool:**
  - The build process uses the ` make ` utility. Ensure that you have ` make ` installed on your system.

## Getting Started:

1. Clone the repository.
  ```bash
     git clone https://github.com/ababdelo/Colorify.git
     cd Colorify
  ```

2. Build & Run:
  ```bash
    make all; make run
  ```

To view available targets and their descriptions, run:

```bash
  make help
```
Output:

```bash
  Usage: make [target]
  
    Targets:
      all      : Build the executable (default)
      clean    : Remove object files
      fclean   : Remove object files and the executable
      re       : Remove all generated files and rebuild
      run      : Clean and run the executable
      help     : Display this help message
```

## Usage:

Enter your preferred choices for ` background color `, ` foreground color `, and ` text style `. Each input should consist of ` three digits ` separated by ` spaces `.

- **Background Color (1-9):** The numeric value representing the background color.
- **Foreground Color (1-7):** The numeric value representing the foreground color.
- **Text Style (1-5):** The numeric value representing the text style.

For example, entering `8 1 4` would set the background color to ` white `, foreground color to ` black `, and text style to ` underline text `.

Type 'clear' to reset the console for a fresh start. Type 'exit' to end the program.
