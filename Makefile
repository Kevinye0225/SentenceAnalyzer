

all: main

main: Main.cpp
	g++ -o main Main.cpp Analyzer.cpp -std=c++11 -I ./boost_1_60_0/

clean:
	rm -rf main *.o


