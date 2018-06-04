main: clean
	g++ -std=c++1y -o main *.cpp -Wall -O `pkg-config --cflags --libs opencv`

clean: 
	rm -f main