#include <opencv2\opencv.hpp>
#include <iostream>
#include <string>
#include <cstdlib>
using namespace cv;
using namespace std;

#define debug

int main(){
	int ratio = 3;
	int lowThreshold = 10;
	int kernel_size = 3;
	Mat detected_edges;
	Mat img = imread("b00002.jpg");

	if (!img.data){
		cout << "Load image failed!" << endl;
		return -1;
	}
	
	//canny edge detect
	resize(img, img, Size(img.cols / 3, img.rows / 3));
	blur(img, detected_edges, Size(3, 3));
	Canny(img, detected_edges, lowThreshold, lowThreshold * ratio, kernel_size);
	
	//show the detected edges
	Mat dst(img.size(), img.type());
	dst = Scalar::all(0);
	img.copyTo(dst, detected_edges);

	namedWindow("origin");
	namedWindow("result");

	imshow("origin", img);
	imshow("result", dst);

	waitKey();
	return 0;
}