#include <opencv2/opencv.hpp>
#include <iostream>
#include "erodeDilate.hpp"
using namespace cv;
using namespace std;

Mat image, imageEroded, imageDilated;
int erosion_elem = 0;
int erosion_size = 0;
int dilation_elem = 0;
int dilation_size = 0;
int const max_elem = 2;
int const max_kernel_size = 21;
String erodeDilateWindow;

/** Function Headers */
//void Erosion( int, void* );

/**  @function Erosion  */
void Erosion( int, void* )
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

void Dilation( int, void* )
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

int erode(Mat image, String window)
{
	erodeDilateWindow = window;
    // Check for failure
    
 	if(!image.data)
 	{
	   	printf( " No image data \n " );
	   	return -1;
 	}
	
	/// Create Erosion Trackbar
  	createTrackbar( "Element:\n 0: Rect \n 1: Cross \n 2: Ellipse", window,
                  	&erosion_elem, max_elem,
                  	Erosion );
	
	createTrackbar( "Kernel size:\n 2n +1", window,
                 	 &erosion_size, max_kernel_size,
                  	 Erosion  );

	 /// Default start
	Erosion( 0, 0 );

   // Wait for any keystroke in the window
	waitKey(0);

   //destroy all opened windows
	//destroyAllWindows();
	
	return 0;
}

int dilate(Mat image, String window)
{
	erodeDilateWindow = window;
    // Check for failure
    
 	if(!image.data)
 	{
	   	printf( " No image data \n " );
	   	return -1;
 	}

	 /// Create Dilation Trackbar
  	createTrackbar( "Element:\n 0: Rect \n 1: Cross \n 2: Ellipse", window,
                  &dilation_elem, max_elem,
                  Dilation );

  	createTrackbar( "Kernel2 size:\n 2n +1", window,
                  &dilation_size, max_kernel_size,
                  Dilation );

	

	 /// Default start
	Erosion( 0, 0 );
	Dilation(0,0);

   // Wait for any keystroke in the window
	waitKey(0);

   //destroy all opened windows
	//destroyAllWindows();
	
	return 0;
}




