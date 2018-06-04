main: clean
	g++ -std=c++1y -o main *.cpp -Wall -O `pkg-config --cflags --libs opencv`

clean: 
	rm -f main

stitch : clean_s
	g++ -std=c++1y -o stitch stitchingEffect.cpp -Wall -O `pkg-config --cflags --libs opencv`
clean_s:
	rm -f stitch
