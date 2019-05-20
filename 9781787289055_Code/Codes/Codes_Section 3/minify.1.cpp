#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp> // for image filtering functions
int main(int argc, const char* argv[])
{
    using namespace cv;
    Mat img = imread(argv[1]);
    imshow("Source", img);

    Mat blurred;
    GaussianBlur(img, blurred, {9,9}, 3, 3); 
    imshow("Blurred", blurred);
    waitKey();

    Mat mask = cv::Mat::zeros(img.size(), img.type());
    const auto WHITE = Scalar::all(255);
    rectangle(mask, Rect(0, img.rows/2+100, img.cols, 150), WHITE, -1);
    imshow("Mask", mask);

    blur(mask, mask, { 50,50 });
    imshow("Mask Blurred", mask);
    waitKey();
     
    return EXIT_SUCCESS;
}