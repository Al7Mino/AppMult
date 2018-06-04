#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

#include "resizingEffect.hpp"

Mat src, dst;
string window;

void ResizeEffect::MyCallbackForAxeY(int iY, void *userData)
{
     int iX = *( static_cast<int*>(userData) );


     double dX = (iX / 50.0) + 0.01;
     double dY = (iY / 50.0) + 0.01;

     // Indique la valeur de l'axe X et Y
     cout << "MyCallbackForAxeY : X=" << dX << ", Y=" << dY << endl;

     // Redimensionne en fonction de dX et dY 
     resize(src,dst, dst.size(), dX, dY); 

     imshow(window, dst);
}

void ResizeEffect::MyCallbackForAxeX(int iX, void *userData)
{
     int iY = *( static_cast<int*>(userData) );

     double dX = (iX / 50.0) + 0.01;
     double dY = (iY / 50.0) + 0.01;

     // Indique la valeur de l'axe X et Y
     cout << "MyCallbackForAxeX : X=" << dX << ", Y=" << dY << endl;

     // Redimensionne en fonction de dX et dY 
     resize(src,dst, dst.size(), dX, dY); 

     imshow(window, dst);
}



Mat ResizeEffect::doEffect(Mat image,String windowName)
{
    int iX = 50;
    int iY = 50;
    window = windowName;
    src = image;

    // Créer la trackbar pour redimensionner sur l'axe X
    createTrackbar("Axe X", window, &iY, 100, MyCallbackForAxeX, &iX);

    // Créer la trackbar pour redimensionner sur l'axe Y
    createTrackbar("Axe Y", window, &iX, 100, MyCallbackForAxeY, &iY);
  
    

    waitKey(0);


    return dst;
}
