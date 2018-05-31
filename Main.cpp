#include <iostream>
#include "canny.hpp"
#include "erodeDilate.hpp"
#include "resizing.hpp"
//#include "stitching.hpp"
#include "brightness.hpp"

using namespace std;

int main(int argc, char** argv)
{
	Mat image = imread("van_gogh.jpg", CV_LOAD_IMAGE_COLOR);
	String windowName = "Pimp my Gimp";
	namedWindow(windowName, WINDOW_AUTOSIZE);

	string functionName;
	cout << "Bienvenue sur le super logiciel Pimp my Gimp !  Veuillez choisir parmi les fonctions suivantes : canny, erodeDilate, resizing, brightness";
	cin >> functionName;
	
	string tab[] = {"canny", "erode", "resizing", "brightness", "dilate"};
	int select;
	while(true){
		select =-1;
		while(select==-1) {
			for(int i=0; i<5; i++) {
				if(functionName==tab[i]) {
					select = i;
				}
			}
			if(select==-1){
				cout << "Fonction non existante. Veuillez choisir parmi les fonctions suivantes : ";
				cin >> functionName;
			}
		}



		switch (select) {
			case 0:
				canny(image, windowName);
				break;
			case 1:
				erode(image, windowName);
				break;
			case 2:
				resize(image, windowName);
				break;
			case 3:
				brightness(image, windowName);
				break;
			case 4:
				dilate(image, windowName);
				break;
			default:
				break;
		}
	}
    return 0;
}
