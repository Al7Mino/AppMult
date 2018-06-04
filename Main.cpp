#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

#include "cannyEffect.hpp"
#include "erodeEffect.hpp"
#include "dilateEffect.hpp"
#include "resizingEffect.hpp"
//#include "stitching.hpp"
#include "brightnessEffect.hpp"

Effect* effect = new CannyEffect;

int main(int argc, char** argv)
{
	Mat image = imread("van_gogh.jpg", CV_LOAD_IMAGE_COLOR);
	Mat imageModified = image;
	if(!image.data) {
	   	printf( " No image data \n " );
	   	return -1;
 	}
	String windowName = "Pimp my Gimp";
	namedWindow(windowName, WINDOW_AUTOSIZE);

	string tab[] = {"canny", "erode", "resizing", "brightness", "dilate", "exit", "reset"};
	string functionName;

	cout << "Bienvenue sur le super logiciel Pimp my Gimp !  Veuillez choisir parmi les fonctions suivantes : canny, erode, dilate, resizing, brightness \n";
	cout << "Si vous voulez quitter le logiciel : écrivez 'exit'\n";
	cin >> functionName;
	
	int select = -1;
	while(true){
		while(select==-1) {
			for(int i=0; i<7; i++) {
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
			{
				effect = new CannyEffect;
				imageModified = effect->doEffect(imageModified, windowName);
				break;
			}
			case 1:
			{
				effect = new ErodeEffect;
				imageModified = effect->doEffect(imageModified, windowName);
				break;
			}
			case 2:
			{
				effect = new ResizeEffect;
				imageModified = effect->doEffect(imageModified, windowName);
				break;
			}
			case 3:
			{
				effect = new BrightnessEffect;
				imageModified = effect->doEffect(imageModified, windowName);
				break;
			}
			case 4:
			{
				effect = new DilateEffect;
				imageModified = effect->doEffect(imageModified, windowName);
				break;
			}
			case 5:
			{
				cout << "A bientôt ! :)" << endl;
				return 0;
			}
			case 6:
			{
				cout << "L'image initiale a été rechargée" << endl;
				imageModified = image;
			}
			default:
			{
				break;
			}
		}
		select =-1;
		destroyAllWindows();
		namedWindow(windowName, WINDOW_AUTOSIZE);
		cout << "Choose another function : canny, erode, dilate, resizing, brightness \n";
		cout << "Pour récupérer l'image initiale : écrire 'reset' \n";
		cout << "Si vous voulez quitter le logiciel : écrivez 'exit'\n";
		cin >> functionName;
	}
    return 0;
}
