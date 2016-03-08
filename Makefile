

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
