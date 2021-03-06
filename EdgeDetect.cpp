#include <opencv2\opencv.hpp>
#include <iostream>
#include <string>
#include <cstdlib>
using namespace cv;
using namespace std;

//#define debug

int main(){
	float thresh = 1 / 16;
	Mat src = imread("b100001.jpg");
	Mat img; 
	if (!src.data){
		cout << "Load image failed!" << endl;
		return -1;
	}
	threshold(src, img, 127, 255, THRESH_BINARY);
	//medianBlur(img, img, 3);
	//blur(src, img, Size(3,3));
	resize(img, img, Size(img.cols / 4, img.rows / 4));
	int nr = img.rows;
	int nc = img.cols;
	
	for (int j = 5; j < nc / 2; j++){
		int count = 0;
		for (int i = 5; i < nr / 2; i++){
			if ( (int)(img.at<uchar>(i, j)) < 10)
				count++;
		}
		if(count > thresh * nr){
			line(img, Point(j - 1, 0), Point(j - 1, nr), Scalar(0, 0, 255));
			break;
		}
	}
#ifdef debug1
			cout << "Point value: " << Point(j - 1, i) << " " << (int)data[j] << endl;
#endif

#ifdef debug
				cout << (int)data[j] << endl;
				cout << "point: " << Point(j - 1, i) << endl;
				circle(img, Point(j - 1, i), 3, Scalar(255, 0, 0));
#endif
		
	namedWindow("picture");
	imshow("picture", img);
	waitKey();
	return 0;
}