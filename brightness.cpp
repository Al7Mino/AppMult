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

	//Changer la luminosité en fonction de la valeur de la trackbar
	image_b.convertTo(imageBright, image_b.type(), 1, lum_size - 100);

  	//Montrer l'image modifiée dans la fenêtre
  	imshow( window, imageBright);

}



int brightness(Mat image, String windowName)
{
  image_b = image;
  window = windowName;
	// Créer la trackbar 
  	createTrackbar( "Luminosité", windowName,
                  	&lum_size, max_kernel_size,
                  	Luminosite );

	// Valeur par défaut
	Luminosite( 0, 0 );
    
    
     // Attendre une commande
	waitKey(0);
    	

  	//Fermer les fenêtres
	destroyAllWindows();

    return 0;
}
