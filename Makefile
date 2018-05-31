
stitch: clean_stitch
	g++ -std=c++1y -o stitch.o -c stitching.cpp -Wall -O `pkg-config --cflags-only-I opencv`
	g++ -o stitch stitch.o `pkg-config --cflags --libs opencv`

erodeDilate: clean_erodeDilate
	g++ -std=c++1y -o erodeDilate.o -c erodeDilate.cpp -Wall -O `pkg-config --cflags-only-I opencv`
	g++ -o erodeDilate erodeDilate.o `pkg-config --cflags --libs opencv`

canny: clean_canny
	g++ -std=c++1y -o canny.o -c canny.cpp -Wall -O `pkg-config --cflags-only-I opencv`
	g++ -o canny canny.o `pkg-config --cflags --libs opencv`

resizing: clean_resizing
	g++ -std=c++1y -o resizing.o -c resizing.cpp -Wall -O `pkg-config --cflags-only-I opencv`
	g++ -o resizing resizing.o `pkg-config --cflags --libs opencv`

brightness: clean_brightness
	g++ -std=c++1y -o brightness.o -c brightness.cpp -Wall -O `pkg-config --cflags-only-I opencv`
	g++ -o brightness brightness.o `pkg-config --cflags --libs opencv`

clean_stitch:
	rm -f stitch 

clean_erodeDilate:
	rm -f erodeDilate

clean_canny:
	rm -f canny

clean_resizing:
	rm -f resizing

clean_brightness:
	rm -f brightness
