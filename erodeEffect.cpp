#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

#include "erodeEffect.hpp"

static Mat image, imageEroded;
static String erodeDilateWindow;
int erosion_elem = 0;
int erosion_size = 0;

/** Function Headers */
//void Erosion( int, void* );

/**  @function Erosion  */
void ErodeEffect::Erosion( int, void* )
{
  int erosion_type;
  if( erosion_elem == 0 ){ erosion_type = MORPH_RECT; }
  else if( erosion_elem == 1 ){ erosion_type = MORPH_CROSS; }
  else{ erosion_type = MORPH_ELLIPSE; }

  Mat element = getStructuringElement( erosion_type,
                                       Size( 2*erosion_size + 1, 2*erosion_size+1 ),
                                       Point( erosion_size, erosion_size ) );

  /// Apply the erosion operation
  erode( image, imageEroded, element);
  imshow( erodeDilateWindow, imageEroded);
}

Mat ErodeEffect::doEffect(Mat src, String window)
{
	erodeDilateWindow = window;
  image = src;
	
	// Create Erosion Trackbar
  createTrackbar( "Element:\n 0: Rect \n 1: Cross \n 2: Ellipse", window,
                  	&erosion_elem, max_elem,
                  	Erosion );
	
	createTrackbar( "Kernel size:\n 2n +1", window,
                 	 &erosion_size, max_kernel_size,
                  	 Erosion  );

	 // Default start
	Erosion( 0, 0 );

   // Wait for any keystroke in the window
	waitKey(0);

  erosion_size = 0;
  erosion_elem = 0;
	
	return imageEroded;
}