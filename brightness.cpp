#include <opencv2/opencv.hpp>
#include <iostream>
#include "brightness.hpp"

using namespace cv;
using namespace std;

Mat image_b, imageBright;
int lum_size = 100;
int const max_kernel_size = 200;




void Luminosite( int, void* )
{

	//Changer la luminosité en fonction de la valeur de la trackbar
	image_b.convertTo(imageBright, image_b.type(), 1, lum_size - 100);

  	//Montrer l'image modifiée dans la fenêtre
  	imshow( "Luminosité", imageBright);

}



int brightness()
{
    //Lire l'image

	image_b = imread("van_gogh.jpg", CV_LOAD_IMAGE_COLOR);

	//Message s'il n'y a pas d'image
    
 	if(!image_b.data)
 	{
   	printf( " No image data \n " );
   	return -1;
 	}


	 // Créer la fenêtre
	namedWindow("Luminosité", WINDOW_AUTOSIZE);

	// Créer la trackbar 
  	createTrackbar( "Luminosité", "Luminosité",
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
