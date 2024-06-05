# TicTacToe Game 🎮

Welcome to the TicTacToe game project! 

---

## 📂 Project Structure

```markdown
OSS_tic_tac_toe/
├── .github/
│
├── headers/
│   ├── env.h
│   ├── console_output.h
│   ├── game_rules.h
│   ├── game_constants.h
│   ├── game_logic.h
│   ├── game_menu.h
│   └── move_cursor.h
├── src/
│   ├── console_output.c
│   ├── game_logic.c
│   ├── game_rules.c
│   ├── main.c
│   ├── game_menu.c
│   └── console_output.c
├── src_for_win
│   ├── env.c
│   └── move.c
├── src_for_win
│   ├── env.c
│   └── move.c
├── .gitignore
├── CMakeLists.txt
├── DEVELOPE.md
├── LICENSE.md
├── Makefile
└── README.md
```

## 🛠️ Installation

Clone the repository and ensure you have 'gcc' and 'cmake' installed.

```bash
git clone https://github.com/username/OSS_tic_tac_toe.git
cd OSS_tic_tac_toe
```
### Installing Dependencies (Linux)
For Linux systems, you can use the provided setup.sh script to install necessary dependencies.

This script will update the package list and install the necessary packages (libncurses5-dev and libncursesw5-dev).
```bash
sudo apt-get update
sudo apt-get install -y libncurses5-dev libncursesw5-dev
```

### Installing Dependencies (Windows and macOS)
Ensure you have the necessary development tools installed ('gcc', 'cmake'). You may need to install additional packages manually.

## 🚀 Usage

### Compiling the Game
See the [DEVELOPE.md](DEVELOPE.md) file for details.

You can compile the game using `gcc` or `make`.
#### Using CMake
1. Create a build directory:

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

##### Running the Game

Once compiled, you can run the game with:

- On macOS and Linux:
  ```bash
  make
  ```

  ```bash
  cd ..
  ./OSS_tic_tac_toe.exe
  ```

- On Windows:

  ```bash
  cd Debug
  OSS_tic_tac_toe.exe
  ```

#### Using gcc

To compile the game manually, run:

```bash
gcc -Iheaders src/*.c -o TicTacToe
```

This command compiles all source files and generates an executable named `TicTacToe`.

#### Using Makefile

Alternatively, you can use the provided Makefile for compilation:

```bash
make
```

This will compile the source files and create the `TicTacToe` executable.

##### Running the Game

Once compiled, you can run the game with:

- On macOS and Linux:

  ```bash
  ./OSS_tic_tac_toe.exe
  ```

- On Windows:

  ```bash
  OSS_tic_tac_toe.exe
  ```


## 👥 Team Members

- **Euna**
- **Chaeyoung** 
- **Seungwoo** 
- **Junyoung**
- **Jungwoo** 
- **Juhyun** 

## 🤝 Contributing

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

## 📜 License

This project is licensed under the MIT License. See the [LICENSE.md](LICENSE.md) file for details.
