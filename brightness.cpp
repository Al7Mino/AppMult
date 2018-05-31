#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat image, imageBright;
int lum_size = 100;
int const max_kernel_size = 200;




void Luminosite( int, void* )
{

	//Changer la luminosit� en fonction de la valeur de la trackbar
	image.convertTo(imageBright, image.type(), 1, lum_size - 100);

  	//Montrer l'image modifi�e dans la fen�tre
  	imshow( "Luminosit�", imageBright);

}



int main(int argc, char** argv)
{
    //Lire l'image

	image = imread("van_gogh.jpg", CV_LOAD_IMAGE_COLOR);

	//Message s'il n'y a pas d'image
    
 	if(!image.data)
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
