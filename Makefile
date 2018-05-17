
stitch: clean
	g++ -std=c++1y -o stitch.o -c stitching.cpp -Wall -O `pkg-config --cflags-only-I opencv`
	g++ -o stitch stitch.o `pkg-config --cflags --libs opencv`

clean:
	rm -f stitch 