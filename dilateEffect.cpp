#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

#include "dilateEffect.hpp"

static Mat image, imageDilated;
static String erodeDilateWindow;
int dilation_elem = 0;
int dilation_size = 0;

void DilateEffect::Dilation( int, void* )
{
  int dilation_type;
  if( dilation_elem == 0 ){ dilation_type = MORPH_RECT; }
  else if( dilation_elem == 1 ){ dilation_type = MORPH_CROSS; }
  else { dilation_type = MORPH_ELLIPSE; }

  Mat element = getStructuringElement( dilation_type,
                                       Size( 2*dilation_size + 1, 2*dilation_size+1 ),
                                       Point( dilation_size, dilation_size ) );
  /// Apply the dilation operation
  dilate( image, imageDilated, element );
  imshow( erodeDilateWindow, imageDilated );
}

Mat DilateEffect::doEffect(Mat src, String window)
{
	erodeDilateWindow = window;
  image = src;

	 /// Create Dilation Trackbar
  	createTrackbar( "Element:\n 0: Rect \n 1: Cross \n 2: Ellipse", window,
                  &dilation_elem, max_elem,
                  Dilation );

  	createTrackbar( "Kernel2 size:\n 2n +1", window,
                  &dilation_size, max_kernel_size,
                  Dilation );

	

	 /// Default start
	Dilation(0,0);

   // Wait for any keystroke in the window
	waitKey(0);

   //destroy all opened windows
	//destroyAllWindows();
	
	return imageDilated;
}