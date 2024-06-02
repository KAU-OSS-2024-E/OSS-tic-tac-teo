How to run

# make object file
To make object file of Tictactoe.c and win_game.c use this.
>> gcc -Iheaders src/*.c -o TicTacToe
>> gcc -I headers -I header_for_win src/*.c src_for_win/*.c -o TicTacToe_win
>> gcc -I headers -I header_for_linux src/*.c src_for_linux/*.c -o TicTacToe_linux

It's "분할컴파일". Also it makes TicTacToe.exe file. then run exe file.
>> ./Tictactoe.exe

# using makefile
just use
>> make
then
>> ./Tictactoe.exe