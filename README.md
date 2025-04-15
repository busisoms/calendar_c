# Calendar Generator

## Project Overview
This project is a command-line calendar generator that displays monthly or yearly calendars based on user input. It handles various date formats, validates inputs, and dynamically generates calendars using algorithms like Zeller's congruence for day calculation. The program demonstrates efficient parsing, memory management, and formatted output in C.

## Features
- Supports input formats: `[year]/[month]`, `[month]/[year]`, `[month]` or `[year]`.
- Automatically detects and prints the current year/month if input is partial.
- Validates dates (e.g., leap years, invalid months/days).
- Prints calendars in a clean, formatted layout.

## Skills Demonstrated
- String tokenization and validation
- Memory allocation and management
- Algorithm implementation (Zeller's congruence, leap year checks)
- Command-line argument parsing
- Formatted output generation
- Error Handling

## Compilation
Compile all source files using:
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o cal
```

## Usage
- Print a specified month and year:
```bash
/cal 12/2023  # Prints December 2023
```

- Print entire year:
```bash
./cal 2023     # Prints all months of 2023
```

- Print the month in the current year
```bash
./cal 10       # Prints October of the current year
```

![C](https://img.shields.io/badge/C-100%25-blue)
