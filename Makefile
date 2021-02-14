build:
	g++ ./src/main.cc ./src/postfix/postfix.cc ./src/postfix/postfix.stack.cc ./src/postfix/postfix.misc.cc ./src/postfix/postfix.arithmetic.cc -o ./bin/postfix

win64:
	x86_64-w64-mingw32-g++ --static ./src/main.cc ./src/postfix/postfix.cc ./src/postfix/postfix.stack.cc ./src/postfix/postfix.misc.cc ./src/postfix/postfix.arithmetic.cc -o ./bin/postfix64.exe

win32:
	i686-w64-mingw32-g++ --static ./src/main.cc ./src/postfix/postfix.cc ./src/postfix/postfix.stack.cc ./src/postfix/postfix.misc.cc ./src/postfix/postfix.arithmetic.cc -o ./bin/postfix32.exe
