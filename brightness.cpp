#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

#include "brightness.hpp"

Mat image_b, imageBright;
int lum_size = 100;
int const max_kernel_size = 200;
string window;




void Luminosite( int, void* )
{

	//Changer la luminosit� en fonction de la valeur de la trackbar
	image_b.convertTo(imageBright, image_b.type(), 1, lum_size - 100);

  	//Montrer l'image modifi�e dans la fen�tre
  	imshow( window, imageBright);

}



int brightness(Mat image, String windowName)
{
  image_b = image;
  window = windowName;
	// Cr�er la trackbar 
  	createTrackbar( "Luminosit�", windowName,
                  	&lum_size, max_kernel_size,
                  	Luminosite );

	// Valeur par d�faut
	Luminosite( 0, 0 );
    
    
     // Attendre une commande
	waitKey(0);
    	

  	//Fermer les fen�tres
	destroyAllWindows();

    return 0;
}
