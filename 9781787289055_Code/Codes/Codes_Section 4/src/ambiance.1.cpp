#include <opencv2/highgui.hpp>

int main(int argc, const char* argv[])
{
    using namespace cv;
    Mat img = imread(argv[1]);
    imshow("Source", img);

    Mat lut = imread(argv[2]);
    imshow("Lookup Table", repeat(lut,200,1));

    LUT(img, lut, img);
    imshow("Retro", img);
    waitKey();     
    return EXIT_SUCCESS;
}