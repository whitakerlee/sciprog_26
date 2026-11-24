# Practical 9: File input and magic squares

This practical reads a square matrix from a text file and checks whether its rows, columns and both diagonals sum to the magic constant.

## Compile and run

Open a terminal in the `practical9` directory.

```bash
gcc -Wall -Wextra main.c -o magic_square
./magic_square
```

When prompted, enter `magic_square.txt`. Run the program again and enter `not_magic_square.txt` to test the other matrix. Keep both text files in the practical directory.
