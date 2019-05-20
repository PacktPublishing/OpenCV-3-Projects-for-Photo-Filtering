#include <iostream>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

int main()
{
    auto filename = "red-panda.jpg";
    Mat img = imread(filename);

    while (true)
    {
        imshow("Red Panda", img);
        int key = waitKey();
        if      ('q' == key) { break; }
        else if ('g' == key) { img = imread(filename, cv::IMREAD_GRAYSCALE); }
        else if ('c' == key) { img = imread(filename); }
        cout << "Channels: " << img.channels() << endl;
    }
    return EXIT_SUCCESS;
}