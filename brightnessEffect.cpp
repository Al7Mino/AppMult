#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

#include "brightnessEffect.hpp"

static Mat image_b, imageBright;
static string window;
int lum_size = 100;

void BrightnessEffect::Luminosite( int, void* )
{

	//Changer la luminosité en fonction de la valeur de la trackbar
	image_b.convertTo(imageBright, image_b.type(), 1, lum_size - 100);

  	//Montrer l'image modifiée dans la fenêtre
  	imshow( window, imageBright);

}

Mat BrightnessEffect::doEffect(Mat image, String windowName)
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
  lum_size = 100;

    return imageBright;
}

int BrightnessEffect::doEffectVideo(Mat image,String windowName)
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

  return lum_size;
}

Mat BrightnessEffect::ReapplyEffect(Mat image,String windowName, int value)
{
  image_b = image;
  window = windowName;
  
  image_b.convertTo(imageBright, image_b.type(), 1, value - 100);

  lum_size = 100;
  return imageBright;
}
