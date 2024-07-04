# C-GenLib: C Language Generic Library (Collections of Data Structures and Algorithms)

Welcome to the Generic Collection Library in C! This project provides a collection of generic data structures and algorithms implemented in the C programming language.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Data Structures Implemented](#data-structures-implemented)
- [How to Contribute](#how-to-contribute)
- [Getting Started](#getting-started)
- [Examples](#examples)
- [License](#license)

##  Introduction

This project aims to provide a reusable and generic collection library for commonly used data structures such as stack, queue, list, tree, map, and set. By using this library, developers can easily integrate these data structures into their C projects.

##  Features

- **Generic:** All data structures are implemented in a generic way, allowing flexibility in data types.
- **Easy to Use:** Simple and intuitive interfaces for easy integration into your projects.
- **Well-documented:** Clear documentation with examples for each data structure.

##  Data Structures Implemented

1. Stack
2. Queue
3. List
4. Vector
5. Map
6. Set

##  How to Contribute

We welcome contributions! If you'd like to contribute to the project, please follow these steps:

1. Fork the repository.
2. Clone the forked repository to your local machine.
3. Create a new branch for your changes.
4. Make your changes and commit them with clear messages.
5. Push your changes to your fork.
6. Open a pull request.

##  Getting Started

To get started with using the Generic Collection Library in your project, follow these steps:

1. Clone the repository to your local machine.
2. Include the necessary header files in your project.
3. Start using the generic data structures!

##  Examples

Here's a simple example of using the stack data structure:

```c
#include <stdio.h>
#include "stack.h"

int main() {
    struct stack *st= createStack("INT");
    int a = 10, b = 20;

    stack_push(st, &a);
    stack_push(st, &b);

    printf("Popped value: %d\n", *((int*)stack_pop(st)));

    return 0;
}
