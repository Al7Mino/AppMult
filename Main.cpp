#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

#include "cannyEffect.hpp"
#include "erodeEffect.hpp"
#include "dilateEffect.hpp"
#include "resizingEffect.hpp"
#include "stitchingEffect.hpp"
#include "brightnessEffect.hpp"

Effect* effect = new CannyEffect;
Mat image, imageModified;
int nbImgs;
vector<Mat> imgs;
string path;
string type;
VideoCapture cap;

int main(int argc, char** argv)
{
	cout << "Welcome on Pimp my Gimp software !\n" << endl;
	cout << "What type of media do you want to modify ? Image or Video" << endl;
	cin >> type;
	if(type == "image" || type == "Image") {
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
		   		printf( "Sorry we couldn't load the image, please try again \n " );
	 		}
		}
	}
	else if(type == "video" || type == "Video") {
		while(!image.data)
		{
			string requestedVideo;
			cout << "Welcome! Please write the video name you wish to modify, or write 'default' to load a preset video\n";
			cin >> requestedVideo;
			if(requestedVideo == "default")
			{
				VideoCapture cap1("chaplin.mp4");
				cap=cap1;
			}
			else
			{
				VideoCapture cap1(requestedVideo);
				cap=cap1;
			}

			cap >> image;
			imageModified = image;
		

			if(!image.data)
			{
		   		printf( "Sorry we couldn't load the video, please try again \n " );
	 		}
		}
	}
	
	String windowName = "Pimp my Gimp";
	namedWindow(windowName, WINDOW_AUTOSIZE);
	imshow( windowName, image);

	string tab[] = {"stitch", "canny", "erode", "resizing", "brightness", "dilate", "exit", "reset", "save"};
	string functionName;

	cout << "Please choose among the following available effects : stitch, canny, erode, dilate, resizing, brightness \n";
	cout << "If you wish to leave the software : write 'exit'\n";
	cin >> functionName;
	
	int select = -1;
	while(true){
		while(select==-1) {
			for(int i=0; i<9; i++) {
				if(functionName==tab[i]) {
					select = i;
				}
			}
			if(select==-1){
				cout << "This effect does not exist. Please choose among the following ones : stitch, canny, erode, dilate, resizing, brightness \n";
				cin >> functionName;
			}
		}
		if(type == "image" || type == "Image") {
			switch (select) {
				case 0:
				{
					cout << "How many pictures do you want to stitch ?" << endl;
					cin >> nbImgs;
					for (int i = 0; i < nbImgs; ++i)
					{
						Mat img;
						while(!img.data) {
							string nameImg;
							cout << "Please choose the picture n°" << i+1 << endl;
							cin >> nameImg;
							img = imread(nameImg, CV_LOAD_IMAGE_COLOR);
						}
						imgs.push_back(img);
					}
					imageModified = StitchingEffect::doStitch(imgs, windowName);
					break;
				}
				case 1:
				{
					effect = new CannyEffect;
					imageModified = effect->doEffect(imageModified, windowName);
					break;
				}
				case 2:
				{
					effect = new ErodeEffect;
					imageModified = effect->doEffect(imageModified, windowName);
					break;
				}
				case 3:
				{
					effect = new ResizeEffect;
					imageModified = effect->doEffect(imageModified, windowName);
					break;
				}
				case 4:
				{
					effect = new BrightnessEffect;
					imageModified = effect->doEffect(imageModified, windowName);
					break;
				}
				case 5:
				{
					effect = new DilateEffect;
					imageModified = effect->doEffect(imageModified, windowName);
					break;
				}
				case 6:
				{
					cout << "See you later ! :)" << endl;
					return 0;
				}
				case 7:
				{
					cout << "The original image has been reloaded" << endl;
					imageModified = image;
				}
				case 8:
				{
					cout << "Choose the url path to register your image (containing the name of the registered image)" <<endl;
					cin >> path;
					imwrite(path, imageModified);
				}
				default:
				{
					break;
				}
			}
		}
		else {
			switch (select) {
				case 0:
				{
					cout << "You can't use the stitching function when you are working on a video" << endl;
					break;
				}
				case 1:
				{
					int value;
					value = CannyEffect::doEffectVideo(imageModified, windowName);
					while (true)
				    {
				        Mat frame;
				        cap >> frame;

				        if(!frame.data)
				            break;
				        frame = CannyEffect::ReapplyEffect(imageModified, windowName, value);
				        imshow(windowName, frame);
				    }
				}
				case 2:
				{
					effect = new ErodeEffect;
					imageModified = effect->doEffect(imageModified, windowName);
					break;
				}
				case 3:
				{
					effect = new ResizeEffect;
					imageModified = effect->doEffect(imageModified, windowName);
					break;
				}
				case 4:
				{
					effect = new BrightnessEffect;
					imageModified = effect->doEffect(imageModified, windowName);
					break;
				}
				case 5:
				{
					effect = new DilateEffect;
					imageModified = effect->doEffect(imageModified, windowName);
					break;
				}
				case 6:
				{
					cout << "See you later ! :)" << endl;
					return 0;
				}
				case 7:
				{
					cout << "The original image has been reloaded" << endl;
					imageModified = image;
				}
				case 8:
				{
					cout << "Choose the url path to register your image (containing the name of the registered image)" <<endl;
					cin >> path;
					imwrite(path, imageModified);
				}
				default:
				{
					break;
				}
			}
		}
		select =-1;
		destroyAllWindows();
		namedWindow(windowName, WINDOW_AUTOSIZE);
		cout << "Choose another function : stitch, canny, erode, dilate, resizing, brightness \n";
		cout << "To get the original image back : write 'reset' \n";
		cout << "To save the current image : write 'save'" << endl;
		cout << "If you wish to leave the software : write 'exit'\n";
		cin >> functionName;
	}
    return 0;
}
