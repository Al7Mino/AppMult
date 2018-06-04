#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

#include "cannyEffect.hpp"

// using namespace Canny;

static String window_name;
static Mat source, destination, detected_edges, source_gray;
static int lowThreshold;

void CannyEffect::CannyThreshold(int, void*)
{
    	blur(source_gray, detected_edges, Size(1,1));
	    Canny(detected_edges, detected_edges, lowThreshold, lowThreshold*ratio, kernel_size);
    	destination = Scalar::all(0);

    	source.copyTo( destination, detected_edges);
    	imshow( window_name, destination );
}

Mat CannyEffect::doEffect(Mat source2,String windowName)
{
  window_name = windowName;
	source=source2;

	destination.create(source.size(), source.type());

  cvtColor( source, source_gray, COLOR_BGR2GRAY );

  createTrackbar( "Min Threshold:", window_name, &lowThreshold, max_lowThreshold, CannyThreshold );

  CannyThreshold(0, 0);

 	waitKey(0);
  lowThreshold = 0;
  return destination;
}
