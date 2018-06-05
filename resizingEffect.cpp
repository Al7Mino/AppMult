#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

#include "resizingEffect.hpp"

Mat src, dst;
string window;
int iX = 50;
int iY = 50;

void ResizeEffect::MyCallbackForAxeY(int iY, void *userData)
{
     Mat temp;	
     iX = *( static_cast<int*>(userData) );


     double dX = (iX / 50.0) + 0.01;
     double dY = (iY / 50.0) + 0.01;

     // Indique la valeur de l'axe X et Y
     //cout << "MyCallbackForAxeY : X=" << dX << ", Y=" << dY << endl;

     // Redimensionne en fonction de dX et dY 
     resize(src,temp, temp.size(), dX, dY);
     dst = temp;

     imshow(window, dst);
}

void ResizeEffect::MyCallbackForAxeX(int iX, void *userData)
{
     Mat temp;
     iY = *( static_cast<int*>(userData) );

     double dX = (iX / 50.0) + 0.01;
     double dY = (iY / 50.0) + 0.01;

     // Indique la valeur de l'axe X et Y
     //cout << "MyCallbackForAxeX : X=" << dX << ", Y=" << dY << endl;

     // Redimensionne en fonction de dX et dY 
     resize(src,temp, temp.size(), dX, dY);
     dst = temp; 

     imshow(window, dst);
}



Mat ResizeEffect::doEffect(Mat image,String windowName)
{
    window = windowName;
    src = image;

    // Créer la trackbar pour redimensionner sur l'axe X
    createTrackbar("Axe X", window, &iY, 100, MyCallbackForAxeX, &iX);

    // Créer la trackbar pour redimensionner sur l'axe Y
    createTrackbar("Axe Y", window, &iX, 100, MyCallbackForAxeY, &iY);
  
    imshow(window, src);

    waitKey(0);

    iX = 50;
    iY = 50;

    return dst;
}

vector<int> ResizeEffect::doEffectVideo(Mat image,String windowName)
{
    window = windowName;
    src = image;

    // Créer la trackbar pour redimensionner sur l'axe X
    createTrackbar("Axe X", window, &iY, 100, MyCallbackForAxeX, &iX);

    // Créer la trackbar pour redimensionner sur l'axe Y
    createTrackbar("Axe Y", window, &iX, 100, MyCallbackForAxeY, &iY);

    waitKey(0);

    vector<int> v;
    v.push_back(iX);
    v.push_back(iY);
  
    return v;
}

Mat ResizeEffect::ReapplyEffect(Mat image,String windowName, vector<int> values)
{
    window = windowName;
    src = image;

    iX = values.at(0);
    iY = values.at(1);

    double dX = (iX / 50.0) + 0.01;
    double dY = (iY / 50.0) + 0.01;

    Mat temp;
    resize(src,temp, temp.size(), dX, dY);
    dst = temp;

    iX = 50;
    iY = 50;

    return dst;
}