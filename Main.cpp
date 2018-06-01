#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

#include "canny.hpp"
#include "erodeDilate.hpp"
#include "resizing.hpp"
//#include "stitching.hpp"
#include "brightness.hpp"

static void callBackButton(int state, void*)
{
    if(state==-1) {
    	cout << "Test";
    }
}

int main(int argc, char** argv)
{
	Mat image = imread("van_gogh.jpg", CV_LOAD_IMAGE_COLOR);
	if(!image.data) {
	   	printf( " No image data \n " );
	   	return -1;
 	}
	String windowName = "Pimp my Gimp";
	namedWindow(windowName, WINDOW_AUTOSIZE);

	//createButton("button",callBackButton,NULL,2);

	string tab[] = {"canny", "erode", "resizing", "brightness", "dilate"};
	string functionName;

	cout << "Bienvenue sur le super logiciel Pimp my Gimp !  Veuillez choisir parmi les fonctions suivantes : canny, erode, dilate, resizing, brightness \n";
	cin >> functionName;
	
	int select = -1;
	while(true){
		while(select==-1) {
			for(int i=0; i<5; i++) {
				if(functionName==tab[i]) {
					select = i;
				}
			}
			if(select==-1){
				cout << "Fonction non existante. Veuillez choisir parmi les fonctions suivantes : canny, erode, dilate, resizing, brightness \n";
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
		select =-1;
		destroyAllWindows();
		namedWindow(windowName, WINDOW_AUTOSIZE);
		cout << "Choose another function : canny, erode, dilate, resizing, brightness \n";
		cin >> functionName;
		// functionName = "";
		// cout << "Press Esc key to exit \nOR \nChoose another function : canny, erode, dilate, resizing, brightness \n";
		// while((waitKey(0) & 0xFF) != 27 && functionName=="") {
		// 	cout << "Test";
		// }
		// if ((waitKey(0) & 0xFF) == 27)
		// {
		// 	cout << "Esc key is pressed by user. Stoppig the application" << endl;
  //           break;
		// }
		// else {
	 //        cin >> functionName;
  //       }
	}
    return 0;
}
