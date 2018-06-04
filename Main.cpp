#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

#include "cannyEffect.hpp"
#include "erodeEffect.hpp"
#include "dilateEffect.hpp"
#include "resizingEffect.hpp"
//#include "stitchingEffect.hpp"
#include "brightnessEffect.hpp"

Effect* effect = new CannyEffect;
Mat image, imageModified;

int main(int argc, char** argv)
{
	
	while(!image.data)
	{
	string requestedImage;
	cout << "Welcome! Please write the image you wish to modify, or write 'default' to load a preset image\n";
	cin >> requestedImage;
		if(requestedImage == "default")
		{
			image = imread("van_gogh.jpg", CV_LOAD_IMAGE_COLOR);
		}
		else
		{
			image = imread(requestedImage, CV_LOAD_IMAGE_COLOR);
		}

	imageModified = image;
	

		if(!image.data)
		{
	   		printf( " Sorry we couldn't load the image, please try again \n " );
 		}
	}
	
	String windowName = "Pimp my Gimp";
	namedWindow(windowName, WINDOW_AUTOSIZE);
	imshow( windowName, image );

	string tab[] = {"canny", "erode", "resizing", "brightness", "dilate", "exit", "reset"};
	string functionName;

	cout << "Welcome on Pimp my Gimp software !  Please choose among the following available effects : canny, erode, dilate, resizing, brightness \n";
	cout << "If you wish to leave the software : write 'exit'\n";
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
				cout << "This effect does not exist. Please choose among the following ones : canny, erode, dilate, resizing, brightness \n";
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
				cout << "See you later ! :)" << endl;
				return 0;
			}
			case 6:
			{
				cout << "The original image has been reloaded" << endl;
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
		cout << "To get the original image back : write 'reset' \n";
		cout << "If you wish to leave the software : write 'exit'\n";
		cin >> functionName;
	}
    return 0;
}
