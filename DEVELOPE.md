# How to Run

## Development Environment Setup

### Windows

1. Install and configure MinGW:
    - Download and install MinGW, then add it to your PATH environment variable.
    - Install the necessary libraries:
    ```bash
    pacman -S mingw-w64-x86_64-gcc
    pacman -S mingw-w64-x86_64-cmake
    ```

### macOS

1. Use Homebrew to install the required tools:
    - Install Homebrew:
    ```bash
    /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
    ```
    - Install GCC and CMake:
    ```bash
    brew install gcc
    brew install cmake
    ```

### Linux

1. Install the necessary packages:
    - Install GCC and CMake:
    ```bash
    sudo apt-get update
    sudo apt-get install -y build-essential cmake
    ```
    - Install the ncurses library:
    ```bash
    sudo apt-get install -y libncurses5-dev libncursesw5-dev
    ```

## Compiling and Running the Game

### Using `gcc` Directly

To compile the source files and create the `TicTacToe` executable, run:

```bash
gcc -I headers src/*.c -o TicTacToe
```

For specific platforms, use:

- **Windows:**

    ```bash
    gcc -o TicTacToe_win -I headers -I src src/*.c src_for_win/*.c
    ```

- **Linux:**

    ```bash
    gcc -o TicTacToe_linux -I headers -I src src/*.c src_for_linux/*.c -lncurses
    ```

To run the executable:

```bash
./TicTacToe
```

### Using CMake

To build the project using CMake, follow these steps:

1. Create a build directory:

    ```bash
    mkdir build
    cd build
    ```

2. Configure the project with CMake:

    ```bash
    cmake ..
    ```

3. Build the project:

    ```bash
    cmake --build .
    ```

#### Running the Game

Once compiled, you can run the game with:

- **On macOS and Linux:**

    ```bash
    ./TicTacToe
    ```

- **On Windows:**

    ```bash
    cd Debug
    OSS_tic_tac_toe.exe
    ```

### Using Makefile

You can also use the provided Makefile for compilation:

```bash
make
```

This will compile the source files and create the `TicTacToe` executable.

#### Running the Game

Once compiled, you can run the game with:

- **On macOS and Linux:**

    ```bash
    ./TicTacToe
    ```

- **On Windows:**

    ```bash
    OSS_tic_tac_toe.exe
    ```

## Build Options and Configuration

### Debug Mode

To build the project in debug mode, use the following CMake command:

```bash
cmake -DCMAKE_BUILD_TYPE=Debug ..
```

### Release Mode

To build the project in release mode with optimizations, use:

```bash
cmake -DCMAKE_BUILD_TYPE=Release ..
```

## Troubleshooting

### Common Issues

1. **Missing ncurses library**: Ensure that ncurses is installed correctly on Linux. Run `sudo apt-get install libncurses5-dev libncursesw5-dev`.
2. **Compiler not found**: Ensure that GCC or CMake is installed and added to your PATH.
3. **Linking errors**: Verify that all necessary libraries are linked correctly.

## Testing and Debugging

### Running Tests

To run tests, compile the test suite using CMake or Makefile and execute the test binary. For example:

```bash
./tests/test_suite
```

### Debugging

Use gdb to debug the executable:

```bash
gdb ./TicTacToe
```

Set breakpoints and run the program step-by-step to identify issues.

## Contributing Guidelines

### Contributing

1. Fork the repository.
2. Create a new branch:

    ```bash
    git checkout -b feature-branch
    ```

3. Make your changes and commit them:

    ```bash
    git commit -m "Add new feature"
    ```

4. Push to the branch:

    ```bash
    git push origin feature-branch
    ```

5. Open a pull request and describe your changes.
