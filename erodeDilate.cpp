#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat image, imageEroded, imageDilated;
int erosion_elem = 0;
int erosion_size = 0;
int dilation_elem = 0;
int dilation_size = 0;
int const max_elem = 2;
int const max_kernel_size = 21;

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
  imshow( "Erode", imageEroded);
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
  imshow( "Dilate", imageDilated );
}

int main(int argc, char** argv)
{
    // Read the image file
	image = imread("van_gogh.jpg", CV_LOAD_IMAGE_COLOR);
	
	//Mat imageDilated;
	
    // Check for failure
    
 	if(!image.data)
 	{
	   	printf( " No image data \n " );
	   	return -1;
 	}
	 // Create windows with above names
	namedWindow("Erode", WINDOW_AUTOSIZE);
	namedWindow("Dilate", WINDOW_AUTOSIZE);
	namedWindow("Original", WINDOW_AUTOSIZE);
	/// Create Erosion Trackbar
  	createTrackbar( "Element:\n 0: Rect \n 1: Cross \n 2: Ellipse", "Erode",
                  	&erosion_elem, max_elem,
                  	Erosion );
	
	createTrackbar( "Kernel size:\n 2n +1", "Erode",
                 	 &erosion_size, max_kernel_size,
                  	 Erosion  );

	 /// Create Dilation Trackbar
  	createTrackbar( "Element:\n 0: Rect \n 1: Cross \n 2: Ellipse", "Dilate",
                  &dilation_elem, max_elem,
                  Dilation );

  	createTrackbar( "Kernel2 size:\n 2n +1", "Dilate",
                  &dilation_size, max_kernel_size,
                  Dilation );

	

	 /// Default start
	Erosion( 0, 0 );
	Dilation(0,0);
	imshow("Original", image);

   // Wait for any keystroke in the window
	waitKey(0);

   //destroy all opened windows
	//destroyAllWindows();
	
	return 0;
}




