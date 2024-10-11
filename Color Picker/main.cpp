#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat img, imgHSV, mask;

int hmin = 0, smin = 0, vmin = 0;
int hmax = 179, smax = 255, vmax = 255;

void main() {

	VideoCapture cap(0); // Webcam

	namedWindow("Color Picker");
	createTrackbar("Hue Min", "Color Picker", &hmin, 179);
	createTrackbar("Hue Max", "Color Picker", &hmax, 179);
	createTrackbar("Sat Min", "Color Picker", &smin, 255);
	createTrackbar("Sat Max", "Color Picker", &smax, 255);
	createTrackbar("Val Min", "Color Picker", &vmin, 255);
	createTrackbar("Val Max", "Color Picker", &vmax, 255);


	while (true) {

		cap.read(img);
		cvtColor(img, imgHSV, COLOR_BGR2HSV);

		Scalar lower(hmin, smin, vmin);
		Scalar upper(hmax, smax, vmax);
		inRange(imgHSV, lower, upper, mask);

		imshow("Camera", img);
		imshow("Image Mask", mask);

		cout << hmin << "," << hmax << "," << smin << "," << smax << "," << vmin << "," << vmax << endl;

		waitKey(1);
	}
}