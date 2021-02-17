CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++11

_start_: ./a.out
	./a.out

./a.out: obj/main.o obj/snake.o obj/getch.o
	g++ -Wall -pedantic -std=c++11 -o ./a.out obj/main.o obj/snake.o obj/getch.o

obj:
	mkdir -p obj

obj/main.o: src/main.cpp inc/getch.hh
	g++ -c ${CXXFLAGS} -Wall -pedantic -o obj/main.o src/main.cpp

obj/snake.o: src/snake.cpp inc/snake.hh
	g++ -c ${CXXFLAGS} -Wall -pedantic -o obj/snake.o src/snake.cpp

obj/getch.o: inc/getch.hh src/getch.cpp
	g++ -c ${CXXFLAGS} -Wall -pedantic -o obj/getch.o src/getch.cpp 

clean:
	rm -f obj/*.o ./a.out
