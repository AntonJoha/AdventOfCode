

run2: main2.o run2.o
	g++ main.o run.o
	./a.out

test2: test2.o run2.o
	g++ test.o run.o
	./a.out

run2.o: run.cpp run.h
	g++ -c run.cpp -D SECOND

test2.o: test.cpp run.h
	g++ -c test.cpp -D SECOND

main2.o: main.cpp run.h
	g++ -c main.cpp -D SECOND


run1: main1.o run1.o
	g++ main.o run.o
	./a.out

test1: test1.o run1.o
	g++ test.o run.o
	./a.out

run1.o: run.cpp run.h
	g++ -c run.cpp -D FIRST

test1.o: test.cpp run.h
	g++ -c test.cpp -D FIRST

main1.o: main.cpp run.h
	g++ -c main.cpp -D FIRST


clean:
	rm -f *.o
	rm a.out
