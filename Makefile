oopt:oop.o oop_test.o
	g++ oop.o oop_test.o -o oop

oop:oop.h oop.cpp
	g++ -o oop.o -c oop.cpp -std=c++11

oop_test:oop.h oop_test.cpp
	g++ -o oop_test.o -c oop_test.cpp

alg:algorithm.cpp common.o
	@echo "compile algorithm.cpp"
	g++ -o alg algorithm.cpp
	@echo " "
	alg.exe

com:common.h
	@echo "compile common.h"
	g++ -c -o common.o common.h
	

bsc:basic.cpp
	@echo "compile basic.cpp"
	g++ -o bsc basic.cpp
	@echo " "
#	bsc.exe
