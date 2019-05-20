#include <opencv2/highgui.hpp>
int main(int argc, const char* argv[])
{
    using namespace cv;
    VideoCapture vidCap(argv[1]);

    Mat lut = imread(argv[2]);
    imshow("Lookup Table", repeat(lut,200,1));

    auto wait_time_ms = 1000.0 / vidCap.get(CAP_PROP_FPS);

    cv::Mat frame;
    while (255 == cv::waitKey(wait_time_ms))
    {
        vidCap >> frame;
        if (frame.empty())
            break;

        imshow("Source", frame);
        LUT(frame, lut, frame);
        imshow("Retro", frame);
    }
    waitKey();     
    return EXIT_SUCCESS;
}