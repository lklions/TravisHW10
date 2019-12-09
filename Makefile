CFLAGS = -std=c++11 -Wall
CC = g++

all: build

build: collegemain.o course.o college.o
	$(CC) $(CFLAGS) -o build collegemain.o course.o college.o

collegemain.o: collegemain.cc course.h college.h
	$(CC) $(CFLAGS) -c collegemain.cc

course.o: course.cc course.h
	$(CC) $(CFLAGS) -c course.cc

college.o: college.cc college.h course.cc course.h
	$(CC) $(CFLAGS) -c college.cc

test: build runtest

runtest: test_college
	./test_college

test_college.o: test_college.cc
	$(CC) $(CFLAGS) -c test_college.cc

test_college: test_college.o college.o course.o
	$(CC) -o test_college test_college.o college.o course.o

clean:
	rm -f *.o build test_college
