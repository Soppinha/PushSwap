*This project has been created as part of the 42 curriculum by svaladar.*

<p align="center">
  <img src="https://raw.githubusercontent.com/ayogun/42-project-badges/main/badges/push_swapm.png" alt="push_swap badge"/>
</p>

# push_swap

## Description

**push_swap** sorts a list of integers using two stacks (`a` and `b`), a small set of operations, and **as few moves as possible**. The program prints the list of operations that sorts stack `a`.

| Operation | Effect |
|-----------|--------|
| `sa` / `sb` / `ss` | Swap the first two elements of `a`, `b`, or both |
| `pa` / `pb` | Move the top element from `b` to `a`, or from `a` to `b` |
| `ra` / `rb` / `rr` | Rotate up: the first element becomes the last |
| `rra` / `rrb` / `rrr` | Rotate down: the last element becomes the first |

### Structure

```
.
├── includes/
│   ├── push_swap.h
│   └── checker_bonus.h
├── src/
│   ├── main.c
│   ├── parse.c          # argument validation and stack construction
│   ├── operations/      # sa sb ss pa pb ra rb rr rra rrb rrr
│   ├── sort/            # small cases and the Turk algorithm
│   ├── stack/           # node creation, search and cleanup
│   ├── utils/           # error handling
│   └── checker/         # bonus: checker program
├── libft/               # my own library (git submodule)
├── checker_linux        # official checker provided by 42
└── Makefile
```

### Algorithm and data structure

Each stack is a **doubly linked list**. Each node stores its value, its current index, whether it is above the median, the cost to move it, a pointer to its target node in the other stack, and whether it is the cheapest move.

The sort depends on the input size:

- **2 numbers**: one `sa` if needed.
- **3 numbers**: a fixed case analysis, at most 2 operations.
- **4 or more**: a version of the **Turk algorithm**:
  1. Push nodes from `a` to `b` until only 3 are left in `a`. Each time, the cheapest node is chosen, and its target in `b` is the largest value smaller than it (or the maximum of `b`). Then sort the 3 nodes left in `a`.
  2. For each node in `b`, find its **target** in `a` (the smallest value larger than it, or the minimum of `a`) and compute the **cost** to bring both to the top, using `ra`/`rra` depending on whether each node is above or below the median.
  3. Move the **cheapest** node, using `rr`/`rrr` when both stacks rotate in the same direction.
  4. When `b` is empty, rotate `a` until the smallest value is on top.

### Bonus: checker

`checker` takes the same arguments as `push_swap`, reads instructions from standard input (one per line) and applies them to the stacks. At the end it prints:

- `OK` if stack `a` is sorted and stack `b` is empty;
- `KO` otherwise;
- `Error` (on standard error) for invalid arguments or an unknown instruction.

```bash
make bonus
ARG="3 2 5 1 4"
./push_swap $ARG | ./checker $ARG     # OK
printf "sa\npb\n" | ./checker $ARG   # KO
printf "xx\n" | ./checker $ARG        # Error
```

It reuses the parser and the stack operations of `push_swap`, called with `print = 0` so nothing is printed. Each instruction is read **one byte at a time** with `read()` into a 4-byte buffer, so no `malloc` is needed and no input line has to be freed. Any line longer than 3 characters, an empty line, or a last instruction without `\n` is an error.

| File | Content |
|------|---------|
| `src/checker/checker_bonus.c` | `main`: parse, read and apply every instruction, print the result |
| `src/checker/checker_utils_bonus.c` | Instruction reader and dispatcher |
| `includes/checker_bonus.h` | Prototypes |

Its output was compared with the official `checker_linux` on push_swap outputs (3 to 500 numbers), on 300 random instruction sequences and on error cases.

## Instructions

### Cloning

[libft](https://github.com/Soppinha/libft) is a submodule (with its own submodules), so clone recursively:

```bash
git clone --recurse-submodules https://github.com/Soppinha/PushSwap.git
cd PushSwap
# or, in an existing clone:
git submodule update --init --recursive
```

The project uses `ft_split`, `ft_atol`, `ft_putstr_fd`, `ft_strcmp` and `ft_free_array` from libft.

### Compilation

```bash
make          # builds libft and push_swap
make bonus    # builds checker
make clean    # removes object files
make fclean   # removes object files and executables
make re       # rebuilds everything
```

### Usage

```bash
./push_swap [integers]
```

**Examples:**

```bash
# Numbers as separate arguments
./push_swap 3 2 5 1 4

# Numbers in a single string
./push_swap "3 2 5 1 4"

# Example with negative numbers
./push_swap -5 2 -1 0 10
```

### Output

The program prints to standard output the sequence of operations needed to sort the stack:

```bash
# Example with 3 numbers
$ ./push_swap 3 2 1
ra
sa

# Example with 2 numbers
$ ./push_swap 2 1
sa

# Example with already sorted stack (no output)
$ ./push_swap 1 2 3 4 5
$

# Example with 5 numbers
$ ./push_swap 5 4 3 2 1
pb
pb
ra
sa
pa
ra
pa
ra
```

Check the result with the bonus checker (or the provided `checker_linux`) and count the moves:

```bash
make bonus
ARG=$(shuf -i 0-1000 -n 100 | tr '\n' ' ')
./push_swap $ARG | ./checker $ARG
./push_swap $ARG | wc -l
```

### Error handling

The program checks and handles the following cases through the `parse.c` module:

- ✓ **Duplicate numbers**: checks for repeated values before adding to the stack
- ✓ **Non-numeric arguments**: validates characters (accepts only digits, '+' and '-')
- ✓ **Numbers outside INT range**: checks if values are between INT_MIN and INT_MAX
- ✓ **Empty arguments**: detects empty or invalid strings
- ✓ **Invalid format**: validates '+' and '-' signs followed by digits
- ✓ **Already sorted stack**: doesn't execute operations if already sorted (returns without output)

**Special behavior:**
- If the program is executed without arguments (`argc < 2`), returns 0 without printing error (expected behavior by 42)

#### Input validation

Parsing supports two forms of input:

```bash
# Multiple arguments
./push_swap 3 2 1 5 4

# Single string with spaces
./push_swap "3 2 1 5 4"

# Combination of both
./push_swap 3 2 "1 5 4"
```

Inside a single string, any whitespace (spaces, tabs) separates numbers: tabs are turned into spaces before the string is split.

In case of error during validation, the program prints `Error\n` to standard error output (stderr) and exits with error code.

### Recommended tests

#### Basic tests
```bash
# No arguments (should return without error)
./push_swap

# One number (no operations)
./push_swap 42

# Already sorted stack (no operations)
./push_swap 1 2 3 4 5

# 2 elements
./push_swap 2 1

# 3 elements (all permutations)
./push_swap 2 1 3
./push_swap 3 2 1
./push_swap 1 3 2
```

#### Error tests
```bash
# Duplicates
./push_swap 1 2 3 2    # Error

# Non-numeric
./push_swap 1 2 abc    # Error

# Overflow
./push_swap 2147483648 # Error

# Empty argument
./push_swap ""         # Error
```

#### Performance tests
```bash
# Generate random numbers and count operations
ARG=$(shuf -i 0-100 -n 100 | tr '\n' ' '); ./push_swap $ARG | wc -l

# Test with worst case (reverse order)
./push_swap $(seq 100 -1 1) | wc -l
```

## Resources

- [Push Swap: the least amount of moves with two stacks – Medium](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
- [o-reo/push_swap_visualizer](https://github.com/o-reo/push_swap_visualizer)
- [Big-O Cheat Sheet](https://www.bigocheatsheet.com/)

### AI usage

AI was used to draft this README from the existing source code. The implementation was written by the author.
