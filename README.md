# Stack in C

## Overview

This project implements a stack data structure in C using an array.
It supports basic stack operations and provides an interactive command-line interface for user input.

## Features
* Push (add element to stack)
* Pop (remove element from stack)
* Peek (view top element)
* Display (print stack contents)
* Interactive menu-driven interface

---

### 1. Compile the program

```bash
gcc stacks.c -o stacks
```

### 2. Run the program

```bash
./stacks
```

---

## Example 

```
=== Stack Menu ===
1) Push
2) Pop
3) Peek
4) Display
> 1
Value: 10

> 4
Your stack: 10
```

---

## Error Handling

* **Stack Overflow**: Prevents pushing when the stack is full
* **Stack Underflow**: Prevents popping from an empty stack

---

