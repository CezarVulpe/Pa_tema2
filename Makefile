CC = g++
CCFLAGS = -Wall -Wextra -std=c++17 -O0 -lm

.PHONY: build clean all

build: drumuri numarare scandal trenuri

run-p3:
	./drumuri
run-p1:
	./numarare
run-p4:
	./scandal
run-p2:
	./trenuri

drumuri: drumuri.cpp
	$(CC) -o $@ $^ $(CCFLAGS)
numarare: numarare.cpp
	$(CC) -o $@ $^ $(CCFLAGS)
scandal: scandal.cpp
	$(CC) -o $@ $^ $(CCFLAGS)
trenuri: trenuri.cpp
	$(CC) -o $@ $^ $(CCFLAGS)

all: build

clean:
	rm -f drumuri numarare scandal trenuri
