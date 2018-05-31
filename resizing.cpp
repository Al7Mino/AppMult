#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat src;

void MyCallbackForAxeY(int iY, void *userData)
{
     Mat dst;
     int iX = *( static_cast<int*>(userData) );


     double dX = (iX / 50.0) + 0.01;
     double dY = (iY / 50.0) + 0.01;

     // Indique la valeur de l'axe X et Y
     cout << "MyCallbackForAxeY : X=" << dX << ", Y=" << dY << endl;

     // Redimensionne en fonction de dX et dY 
     resize(src,dst, dst.size(), dX, dY); 

     imshow("Resizing", dst);
}

void MyCallbackForAxeX(int iX, void *userData)
{
     Mat dst;
     int iY = *( static_cast<int*>(userData) );

     double dX = (iX / 50.0) + 0.01;
     double dY = (iY / 50.0) + 0.01;

     // Indique la valeur de l'axe X et Y
     cout << "MyCallbackForAxeX : X=" << dX << ", Y=" << dY << endl;

     // Redimensionne en fonction de dX et dY 
     resize(src,dst, dst.size(), dX, dY); 

     imshow("Resizing", dst);
}



int main(int argc, char** argv)
{
     // Lis l'image 
     src = imread("van_gogh.jpg");

     // Si aucune image est trouvée
    if (src.data == false) 
    { 
          cout << "Pas d'image trouvée" << endl;
          return -1; 
    }

    // Créer la window
    namedWindow("Resizing", 1);

    int iX = 50;
    int iY = 50;

    // Créer la trackbar pour redimensionner sur l'axe X
    createTrackbar("Axe X", "Resizing", &iY, 100, MyCallbackForAxeX, &iX);

    // Créer la trackbar pour redimensionner sur l'axe Y
    createTrackbar("Axe Y", "Resizing", &iX, 100, MyCallbackForAxeY, &iY);
  
    imshow("Resizing", src);

    waitKey(0);


    return 0;
}
