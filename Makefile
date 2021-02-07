CC = g++
CFLAGS = -std=c++11 -c -g -Og -Wall -Werror -pedantic
OBJ = RingBuffer.o driver.o GuitarString.o GStest.o GuitarHeroLite.o GuitarHero.o
DEPS = RingBuffer.hpp GuitarString.hpp
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
EXE = driver GStest GuitarHeroLite GuitarHero

all: driver GuitarHeroLite GuitarHero GStest

driver: RingBuffer.o GuitarString.o driver.o
	$(CC) RingBuffer.o GuitarString.o driver.o -o driver $(LIBS)

GuitarHeroLite: RingBuffer.o GuitarString.o GuitarHeroLite.o
	$(CC) RingBuffer.o GuitarString.o GuitarHeroLite.o -o GuitarHeroLite $(LIBS)

GuitarHero: RingBuffer.o GuitarString.o GuitarHero.o
	$(CC) RingBuffer.o GuitarString.o GuitarHero.o -o GuitarHero $(LIBS)

GStest: RingBuffer.o GuitarString.o GStest.o
	$(CC) RingBuffer.o GuitarString.o GStest.o -o GStest $(LIBS) -lboost_unit_test_framework

driver.o: main.cpp $(DEPS)
	$(CC) $(CFLAGS) -o driver.o main.cpp

RingBuffer.o: RingBuffer.cpp $(DEPS)
	$(CC) $(CFLAGS) -o RingBuffer.o RingBuffer.cpp

GuitarString.o: GuitarString.cpp $(DEPS)
	$(CC) $(CFLAGS) -o GuitarString.o GuitarString.cpp

GuitarHero.o: GuitarHero.cpp $(DEPS)
	$(CC) $(CFLAGS) -o GuitarHero.o GuitarHero.cpp

GStest.o: GStest.cpp $(DEPS)
	$(CC) $(CFLAGS) -o GStest.o GStest.cpp

GuitarHeroLite.o: GuitarHeroLite.cpp $(DEPS)
	$(CC) $(CFLAGS) -o GuitarHeroLite.o GuitarHeroLite.cpp

clean:
	rm $(OBJ) $(EXE)
