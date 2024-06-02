# How to Run

## Compiling and Running the Game

### Using gcc directly

To make an object file of all source files and create the TicTacToe executable, run:

```bash
gcc -Iheaders src/*.c -o TicTacToe
```

This command compiles all source files and generates an executable named `TicTacToe`.

Then run the executable:

```bash
./TicTacToe
```

### Using Makefile

Alternatively, you can use the provided Makefile for compilation:

```bash
make
```

This will compile the source files and create the `TicTacToe` executable.

Then run the executable:

```bash
./TicTacToe
```

### Using CMake

To use CMake for building the project, follow these steps:

1. Create a build directory and navigate into it:
    ```bash
    mkdir build
    cd build
    ```

2. Run CMake to configure the project:
    ```bash
    cmake ..
    ```

3. Build the project:
    ```bash
    cmake --build .
    ```

4. Run the executable from the build directory:
    ```bash
    ./TicTacToe
    ```

Alternatively, you can run the executable from the project root directory by specifying the path:
    ```bash
    ./build/TicTacToe
    ```
