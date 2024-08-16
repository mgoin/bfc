<p align="center">
   <img alt="BFC Logo" src="https://github.com/user-attachments/assets/aee4c50f-d702-46bf-9155-94dfc8939624" width="70%" />
</p>

# BFC (Brainfuck Compiler)

BFC is a simple compiler that translates [Brainfuck](https://en.wikipedia.org/wiki/Brainfuck) code into C code.
It is built to convert Brainfuck programs into executable C programs, making it easier to run, debug, and optimize Brainfuck code.

## Features

- Supports all standard Brainfuck operations
- Generates a complete C program with main function and necessary includes

## Requirements

- C++ compiler (e.g., g++, clang++)

## Building

To compile the BFC compiler, use your C++ compiler of choice. For example:

```bash
g++ -o bfc bfc.cpp
```

This will create an executable named `bfc`.

## Usage

```bash
./bfc <input-bf-file> <output-c-file>
```

- `<input-bf-file>`: Path to the input Brainfuck file
- `<output-c-file>`: Path where the output C file will be saved

## Example

1. Create a Brainfuck file (e.g., `hello.bf`) with the following content:

   ```brainfuck
   ++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.
   ```

   This program prints "Hello World!".

2. Compile the Brainfuck code to C:

   ```bash
   ./bfc hello.bf hello.c
   ```

3. Compile the generated C code:

   ```bash
   gcc -o hello hello.c
   ```

4. Run the compiled program:

   ```bash
   ./hello
   ```

   This should output: `Hello World!`

## How It Works

BFC translates each Brainfuck operation into equivalent C code:

- `+` becomes `mem[p]++;`
- `-` becomes `mem[p]--;`
- `>` becomes `p++;`
- `<` becomes `p--;`
- `.` becomes `putchar(mem[p]);`
- `,` becomes `mem[p] = getchar();`
- `[` becomes `while (mem[p]) {`
- `]` becomes `}`

The generated C program uses a character array `mem` to simulate the Brainfuck memory tape and an integer `p` as the memory pointer.

## Limitations

- The memory tape is fixed at 65,536 cells.
- Error handling for invalid Brainfuck syntax is not implemented.
- BFC does not perform any optimizations on the Brainfuck code (currently). It relies on the C compiler to optimize the generated C.

## Contributing

Contributions to improve BFC are welcome.
Please feel free to submit issues or pull requests on the project repository.
This project is open-source and available under the MIT License.
