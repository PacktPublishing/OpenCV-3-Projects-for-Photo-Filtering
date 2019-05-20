#include <iostream>
#include <opencv2/highgui.hpp>

int main()
{
    cv::Mat img = cv::imread("red-panda.jpg");

    if (img.empty())
    {
        std::cout << "Could not open image.\n"; 
        return EXIT_FAILURE;
    }

    std::cout << "Size:     " << img.cols << " x " << img.rows << "px\n";
    std::cout << "Channels: " << img.channels() << '\n';
    return EXIT_SUCCESS;
}
