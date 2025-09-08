# Push Swap

A 42 project focused on sorting a stack of integers using a limited set of stack operations. The goal is to implement the most efficient algorithm possible to minimize the number of operations.

---

## 🚀 Overview

This implementation of push_swap uses:
 - Index normalization to simplify value comparisons.
 - Chunk-based strategy to push groups of values from stack A to B.
 - Turkish greedy algorithm to determine the cheapest move to reinsert elements from B to A.
 - Specialized logic to sort 3 elements, align final stack, and minimize total operations.

---

## Folder structure

---

## Algorithm

### Step 1: Normalize Input
All values are normalized to compressed indices for consistent comparison.

### Step 2: Push in Chunks (A -> B)
Elements are pushed from A to B in defined index ranges (chunks). B is rotated to balance values as they're added.

### Step 3: Sort Remaining 3 in A
When A has only 3 elements left, a minimal 3-element sort is performed.

### Step 4: Reinsertion (B -> A)
Using the Turkish greedy algorithm:
 - Calculate rotation cost for each element in B.
 - Prefer same-direction overlap of rotations.
 - Push the cheapest element back to A.

### Step 5: Final Alignment
Stack A is rotated until the smallest index is on top.

---

## 🛠️ Compilation

To build the project, run:

```bash
make              # Builds the push_swap
make bonus        # Builds the checker
make clean        # Removes object files
make fclean       # Removes all binaries and objects
make re           # Rebuilds everything
```

---

## 🧪 Usage

### Sorting stack:
```bash
./push_swap 2 1 3 6 5 8
```

Returns a list of operations like:
```bash
pb
pb
sa
pa
pa
```

### Verifying with checker (bonus):
```bash
ARG="2 1 3 6 5 8"; ./push_swap $ARG | ./checker $ARG
```

Expected output:
```bash
OK
```
The bonus checker program reads instructions from stdin and validates them on the initial stack. It confirms whether the operations result in a correctly sorted stack A and an empty stack B.

---

## 🛠️ Features
 - Chunked value distribution
 - Cost-optimized reinsertions
 - Handles edge cases (already sorted, reverse sorted, small sets)
 - No memory leaks
 - Norm-compliant
 - Bonus: Checker implementation for instruction validation

 ---

## 👤 Author

Created and maintained by [Martin Justa](https://github.com/aztaban) as part of the 42 school curriculum.