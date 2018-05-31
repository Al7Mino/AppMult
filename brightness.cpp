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

	//Changer la luminosit� en fonction de la valeur de la trackbar
	image_b.convertTo(imageBright, image_b.type(), 1, lum_size - 100);

  	//Montrer l'image modifi�e dans la fen�tre
  	imshow( "Luminosit�", imageBright);

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


	 // Cr�er la fen�tre
	namedWindow("Luminosit�", WINDOW_AUTOSIZE);

	// Cr�er la trackbar 
  	createTrackbar( "Luminosit�", "Luminosit�",
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
