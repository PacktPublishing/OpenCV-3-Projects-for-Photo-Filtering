#include <opencv2/highgui.hpp>

int main(int argc, const char* argv[])
{
    cv::VideoCapture vidCap(argv[1]);

    cv::Mat frame;
    while (255 == cv::waitKey(1) && (vidCap >> frame, !frame.empty()))
        cv::imshow("Frame", frame);

    //while (27 != cv::waitKey(1))
    //{
    //    vidCap >> frame;
    //    if (frame.empty())
    //        break;

    //    cv::imshow("Frame", frame);
    //}

    return EXIT_SUCCESS;
}