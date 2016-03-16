#include <opencv2\opencv.hpp>
#include <iostream>
#include <string>
#include <cstdlib>
using namespace cv;
using namespace std;

#define debug

int main(){
	Mat img = imread("b00002.jpg");
	medianBlur(img, img, 3);
	resize(img, img, Size(img.cols / 3, img.rows / 3));
	
	namedWindow("picture");
	int nr = img.rows;
	int nc = img.cols;
	Point lastBlackPoint = Point(0, 0);
	for(int i = nr / 20; i < nr; i+=5){
		const uchar* data = img.ptr<uchar>(i);
		for(int j = nc / 20; j < nc / 2; j++){
#ifdef debug1
			cout <<"Point value: "<< Point(j - 1, i) <<" "<< (int)data[j] <<endl;
#endif
			if(data[j] == 0){
#ifdef debug
				cout << (int)data[j] << endl;
				cout << "point: " << Point(j-1, i)<<endl;
				circle(img, Point(j - 1, i), 3, Scalar(255, 0, 0));
#endif
				if(lastBlackPoint.x != 0)
					line(img, lastBlackPoint, Point(j - 1, i), Scalar(0, 0, 255));
				lastBlackPoint = Point(j - 1, i);
				break;
			}
		}
	}
	imshow("picture", img);
	waitKey();
	return 0;
}