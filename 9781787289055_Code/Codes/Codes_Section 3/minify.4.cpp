#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
int main(int argc, const char* argv[])
{   struct Data
    {   cv::Mat img, blurred, mask, blended;
        int rect_height = 100;
    } data;
    data.img = cv::imread(argv[1]);
    GaussianBlur(data.img, data.blurred, {9,9}, 3, 3);
    data.mask = cv::Mat::zeros(data.img.size(), data.img.type());
    auto onMouse = [](int event, int x, int y, int flags, void* userdata)
    {   
        auto& data = *reinterpret_cast<Data*>(userdata);
        if (cv::EVENT_MOUSEWHEEL == event)
            data.rect_height = std::max(1, data.rect_height + cv::getMouseWheelDelta(flags)/30);
        if (cv::EVENT_MOUSEMOVE == event)
            return;        
        data.mask.setTo(0);
        const auto WHITE = cv::Scalar::all(255);
        cv::rectangle(data.mask, cv::Rect(0, y, data.img.cols, data.rect_height), WHITE, -1);
        cv::blur(data.mask, data.mask, { 50,50 });
        data.blended = data.img.mul(data.mask, 1.f / 255) + data.blurred.mul(WHITE - data.mask, 1.f / 255);
        cv::imshow("Mask Blurred", data.mask);
        cv::imshow("Miniaturized!", data.blended);
    };
    onMouse(cv::EVENT_MOUSEMOVE, 0, data.img.rows / 2, 0, &data);
    cv::setMouseCallback("Miniaturized!", onMouse, &data);
    cv::waitKey();     
    return EXIT_SUCCESS;
}