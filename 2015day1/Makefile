

run: main.o run.o
	g++ main.o run.o
	./a.out

test: test.o run.o
	g++ test.o run.o
	./a.out

run.o: run.cpp run.h
	g++ -c run.cpp

test.o: test.cpp run.h
	g++ -c test.cpp

main.o: main.cpp run.h
	g++ -c main.cpp

clean:
	rm -f *.o
	rm a.out
