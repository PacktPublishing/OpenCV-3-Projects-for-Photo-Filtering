#include <opencv2/highgui.hpp>
int main(int argc, const char* argv[])
{
    using namespace cv;
    VideoCapture vidCap(argv[1]);
    VideoWriter vidOut;
    Mat frame, lut = imread(argv[2]);
    while (255 == waitKey(1))
    {
        vidCap >> frame;        // grab frame
        if (frame.empty()) break;
        if (!vidOut.isOpened())
            vidOut.open("retro.avi", CV_FOURCC('X','V','I','D'), vidCap.get(CAP_PROP_FPS), frame.size());
        LUT(frame, lut, frame); // recolor
        imshow("Retro Video", frame);
        vidOut << frame;        // write frame
    }
    vidOut.release();                   // finish and finalize output video.          
    VideoCapture retroVid("retro.avi"); // load new saved video 
    while (255 == waitKey(1))
    {
        retroVid >> frame;              // grab frame
        if (frame.empty()) break;
        imshow("Saved Video", frame);   // show it
    }
    return EXIT_SUCCESS;
}