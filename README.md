# TicTacToe Game 🎮

Welcome to the TicTacToe game project! 

---

## 📂 Project Structure

```markdown
TicTacToe/
├── .github/
│   └── workflows/
│       └── cr.yml
├── headers/
│   ├── game_logic.h
│   ├── game_rules.h
│   ├── main_menu.h
│   └── move_cursor.h
├── src/
│   ├── game_logic.c
│   ├── game_rules.c
│   ├── main.c
│   ├── main_menu.c
│   ├── move_cursor.c
│   └── win_game.c
├── .gitignore
├── CMakeLists.txt
├── DEVELOPE.md
├── LICENSE.md
├── Makefile
└── README.md
```

## 🛠️ Installation

Clone the repository and ensure you have `gcc` installed.

```bash
git clone https://github.com/username/TicTacToe.git
cd TicTacToe
```

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
  ./build/TicTacToe
  ```

- On Windows:

  ```bash
  TicTacToe.exe
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
  ./TicTacToe
  ```

- On Windows:

  ```bash
  TicTacToe.exe
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