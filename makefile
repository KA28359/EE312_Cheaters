plagiarismChecker: main.o matrix.o hashtable.o
		g++ -std=c++0x -o plagiarismChecker main.o matrix.o hashtable.o

main.o: main.cpp hashtable.h matrix.h
	g++ -std=c++0x -c main.cpp

matrix.o: matrix.cpp matrix.h
		g++ -std=c++0x -c matrix.cpp

hashtable.o: hashtable.cpp hashtable.h
		g++ -std=c++0x -c hashtable.cpp