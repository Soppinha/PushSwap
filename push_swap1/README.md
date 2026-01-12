# Push Swap

*This project was created as part of the 42 curriculum by svaladar.*

## Description

**push_swap** is an algorithm and data manipulation project that consists of sorting a stack of integers using a limited set of operations and the smallest possible number of moves.

The project uses two stacks (a and b) and a restricted set of operations:
- **sa/sb/ss**: swap the first two elements of the stack
- **pa/pb**: move the first element from one stack to another
- **ra/rb/rr**: rotate the stack upward
- **rra/rrb/rrr**: rotate the stack downward

The goal is to develop an efficient algorithm that minimizes the number of operations needed to sort stack a, using stack b as an auxiliary.

### Data Structure

The project uses a **doubly linked list** to represent each stack. Each node contains:
- `value`: the integer value
- `index`: current position in the stack (0 = top)
- `push_cost`: calculated cost to move the element
- `above_median`: flag indicating if it's in the upper half of the stack
- `best_match`: flag indicating if it's the cheapest element to move
- `target`: pointer to the target node in the other stack
- `next` and `prev`: pointers for bidirectional navigation

This structure allows efficient insertion, removal, and navigation operations in both directions.

### Implemented Algorithm

This project implements an adaptive strategy based on input size:

**For 2 elements:**
- Direct solution: a single `sa` operation if needed

**For 3 elements:**
- Optimized algorithm in `sort_three()`: maximum 3 operations

**For 4+ elements:**
- Implements a variation of the **Turk Algorithm**, an optimized sorting algorithm that:

1. Moves elements from `a` to `b` (keeps the last 3 in `a`)
2. Sorts the remaining 3 elements in `a`
3. For each element in `b`:
   - Calculates the **index** and identifies if it's **above or below the median**
   - Defines the **target node** in `a` - the correct position where it should be inserted
   - Calculates the **cost** (number of operations) needed to move the element
   - Identifies the **best match** (element with lowest cost)
4. Moves elements back to `a` in the correct position, prioritizing cheaper moves
5. Optimizes using double rotations (`rr` or `rrr`) when both stacks need to rotate in the same direction
6. Finalizes by rotating the smallest element to the top

The algorithm uses concepts of:
- **Target nodes**: each node in a stack has a "target" in the other stack (next smaller for a→b, next larger for b→a)
- **Cost analysis**: calculates the cost (number of operations) to move each element considering its position and the target's position
- **Median tracking**: identifies if an element is above or below the median to choose between rotation (`ra`) or reverse rotation (`rra`), minimizing movements
- **Best match optimization**: always chooses the cheapest element to move, reducing the total number of operations

## Instructions

### Compilation

**Requirements:**
- Compiler: `gcc` or `cc`
- Flags: `-Wall -Wextra -Werror`
- Standard: C99 or higher

```bash
make
```

This will generate the `push_swap` executable by compiling `main.c` along with all modules in `src/`.

### Additional Compilation

```bash
make clean    # Remove object files
make fclean   # Remove object files and executable
make re       # Recompile everything from scratch
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
sa
rra

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
sa
pa
pa
ra
ra
```

## Execution Flow

1. **Initialization** (`main.c`):
   - Checks if there are arguments (if argc < 2, returns without error)
   - Initializes stacks a and b as NULL

2. **Parsing** (`parse.c`):
   - Validates command line arguments
   - Converts strings to integers
   - Checks for duplicates and INT limits
   - Builds the initial stack

3. **Sort Verification** (`stack_utils.c`):
   - Checks if the stack is already sorted with `is_sorted()`
   - If yes, skips to memory deallocation (no operations)

4. **Sorting Algorithm** (selection based on size):
   - **2 elements**: executes only `sa` if needed
   - **3 elements**: uses `sort_three()` - specific and optimized algorithm
   - **4+ elements**: implements the complete Turk algorithm
     - Moves all elements except 3 to stack b (`pb`)
     - Sorts the remaining 3 elements in a
     - For each element in b:
       - Calculates indices and median
       - Defines targets (target nodes) in a
       - Calculates movement costs
       - Identifies the cheapest move
       - Optimizes double rotations when possible
       - Moves element to correct position in a
     - Positions the smallest element on top

5. **Finalization**:
   - Frees all allocated memory (`free_stack()`)
   - Returns 0 (success)

## Special Cases

### 2 Elements
```c
// If unsorted, just swap
sa(&a, 1);
```

### 3 Elements
Implements optimized logic in `sort_three()`:
- Identifies the largest element
- Positions it at the end
- Swaps the first two if needed
- Maximum of 3 operations

## Memory Management

The project implements careful memory management:

- **Allocation**: all stack nodes are dynamically allocated
- **Deallocation**: `free_stack()` and `free_split()` ensure no leaks
- **Error handling**: in case of error during parsing or allocation, all already allocated memory is freed before terminating
- **Valgrind**: the program should run without memory leaks when tested with valgrind

Example test with valgrind:
```bash
valgrind --leak-check=full ./push_swap 3 2 1 5 4
```

## Recommended Tests

### Basic Tests
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

### Error Tests
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

### Performance Tests
```bash
# Generate random numbers and count operations
ARG=$(shuf -i 0-100 -n 100 | tr '\n' ' '); ./push_swap $ARG | wc -l

# Test with worst case (reverse order)
./push_swap $(seq 100 -1 1) | wc -l
```

## Error Handling

The program checks and handles the following cases through the `parse.c` module:

- ✓ **Duplicate numbers**: checks for repeated values before adding to the stack
- ✓ **Non-numeric arguments**: validates characters (accepts only digits, '+' and '-')
- ✓ **Numbers outside INT range**: checks if values are between INT_MIN and INT_MAX
- ✓ **Empty arguments**: detects empty or invalid strings
- ✓ **Invalid format**: validates '+' and '-' signs followed by digits
- ✓ **Already sorted stack**: doesn't execute operations if already sorted (returns without output)

**Special behavior:**
- If the program is executed without arguments (`argc < 2`), returns 0 without printing error (expected behavior by 42)

### Input Validation

Parsing supports two forms of input:

```bash
# Multiple arguments
./push_swap 3 2 1 5 4

# Single string with spaces
./push_swap "3 2 1 5 4"

# Combination of both
./push_swap 3 2 "1 5 4"
```

In case of error during validation, the program prints `Error\n` to standard error output (stderr) and exits with error code.

### Testing Tools
- **push_swap_visualizer**: visualizes operations graphically
- **push_swap_tester**: tests multiple cases and checks number of operations
- **checker**: verifies if the operation sequence sorts correctly (if implemented)

## Resources

### Documentation and References

- **42 Subject**: Official push_swap project document
- **Push_swap visualizer**: [push-swap-visualizer](https://github.com/o-reo/push_swap_visualizer) - tool to visualize operations
- **Sorting algorithms**: study on algorithmic complexity and optimization
- **Data structures**: doubly linked lists in C

### Articles and Tutorials

- [Push Swap — A journey to find most efficient sorting algorithm](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a) - explanation of the Turk algorithm
- [Sorting algorithms comparison](https://www.bigocheatsheet.com/) - algorithm complexity
- Concepts of stacks and fundamental operations

### AI Usage

Artificial Intelligence was used in this project for:

- **Generation of this README.md**: documentation structuring.
- **Concept explanation**: clarification about the algorithm's functioning and its optimizations.

**Important**: All implementation code was developed manually. AI was used only as a support tool for documentation and theoretical understanding of the algorithm.