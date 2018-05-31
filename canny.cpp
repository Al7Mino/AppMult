#include <opencv2/opencv.hpp>
#include "canny.hpp"
using namespace std;
using namespace cv;

Mat source, destination, detected_edges, source_gray;
int lowThreshold;
int const max_lowThreshold = 1000;
int kernel_size = 3;
int ratio = 1;
static void CannyThreshold(int, void*)
{
    	blur(source_gray, detected_edges, Size(1,1));
	Canny(detected_edges, detected_edges, lowThreshold, lowThreshold*ratio, kernel_size);
    	destination = Scalar::all(0);

    	source.copyTo( destination, detected_edges);
    	imshow( window_name, destination );
}
int canny(Mat source2,String window_name)
{
	source=source2;


	

  	if( source.empty() ) { 
		return -1; 
	}


	destination.create(source.size(), source.type());

  	cvtColor( source, source_gray, COLOR_BGR2GRAY );

	namedWindow (window_name, WINDOW_AUTOSIZE);

  	createTrackbar( "Min Threshold:", window_name, &lowThreshold, max_lowThreshold, CannyThreshold );

  	CannyThreshold(0, 0);

 	waitKey(0);
 	return 0;

}
