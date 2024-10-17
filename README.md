# Push Swap - 42 Project

**Push Swap** is a sorting algorithm project in which you are required to sort a list of integers using two stacks and a limited set of instructions. The goal of this project is to develop an efficient algorithm with the least number of operations to sort the given stack, while adhering to strict constraints.

## Table of Contents

1. [About](#about)
2. [Allowed Operations](#allowed-operations)
3. [How to Use](#how-to-use)
4. [Compilation](#compilation)
5. [Testing](#testing)
6. [License](#license)

## About

In **Push Swap**, you are given two stacks: `a` (which initially contains the unsorted integers) and `b` (which is empty). Your task is to sort the stack `a` in ascending order using the least number of operations. You can only use a specific set of operations to manipulate the stacks, making it a challenge of both optimization and algorithm design.

The **Push Swap** project focuses on understanding sorting algorithms, stack data structures, and algorithmic complexity. Efficiently solving this problem requires creativity and a good understanding of both brute force and more advanced algorithms (like quicksort, mergesort, radix sort, etc.).

## Allowed Operations

### Push
- `pa`: Push the top element from stack `b` to stack `a`.
- `pb`: Push the top element from stack `a` to stack `b`.

### Swap
- `sa`: Swap the first two elements of stack `a`.
- `sb`: Swap the first two elements of stack `b`.
- `ss`: Swap the first two elements of both stacks `a` and `b` at the same time.

### Rotate
- `ra`: Rotate stack `a` upward (first element becomes the last).
- `rb`: Rotate stack `b` upward.
- `rr`: Rotate both stacks `a` and `b` upward at the same time.

### Reverse Rotate
- `rra`: Reverse rotate stack `a` (last element becomes the first).
- `rrb`: Reverse rotate stack `b`.
- `rrr`: Reverse rotate both stacks `a` and `b` at the same time.

## How to Use

1. Clone the repository to your local machine:

    ```bash
    git clone https://github.com/username/push_swap.git
    cd push_swap
    ```

2. Run `make` to compile the program:

    ```bash
    make
    ```

3. Execute the `push_swap` program with a sequence of numbers to sort:

    ```bash
    ./push_swap 3 2 5 4 1
    ```

   The program will output the list of operations needed to sort the input.

4. You can check if the output is valid and minimal by running the `checker` with the same sequence of numbers and piping the output of `push_swap` to it:

    ```bash
    ./push_swap 3 2 5 4 1 | ./checker 3 2 5 4 1
    ```

   The `checker` will output:
   - `OK` if the sequence is sorted properly.
   - `KO` if the sequence is not sorted.
   - `Error` if the input is invalid.

## Compilation

- `make`: Compiles the `push_swap` program.
- `make clean`: Deletes object files.
- `make fclean`: Deletes object files and the compiled executable.
- `make re`: Cleans and recompiles the program.

## Testing

You can test **Push Swap** manually by providing different sets of integers as input and verifying the output operations, or you can use automated testers for the project, available on GitHub. These testers will generate random numbers and evaluate the number of operations your program uses to sort them.

For example:

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
