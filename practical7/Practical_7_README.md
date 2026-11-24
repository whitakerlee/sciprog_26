# Practical 7: Dynamic memory allocation

This practical estimates Euler’s number using a dynamically allocated array of polynomial terms and demonstrates allocating, filling, printing and freeing an integer array.

## Compile and run

Open a terminal in the `practical7` directory.

### euler.c

```bash
gcc -Wall -Wextra euler.c -o euler -lm
./euler
```

### allocation.c

```bash
gcc -Wall -Wextra allocation.c -o allocation
./allocation
```

Enter the polynomial order or array size when prompted. Use order 15 to evaluate the full requested range if the program prints successive estimates.
