#include <iostream>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

int main()
{
    Mat img = imread("red-panda.jpg");

    if (img.empty())
    {
        cout << "Could not open image.\n"; 
        return EXIT_FAILURE;
    }

    imshow("Red Panda", img);
    waitKey();

    return EXIT_SUCCESS;
}
