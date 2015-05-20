#ifndef IMAGE_H
#define IMAGE_H

#include <cv.hpp>
#include <imgproc/imgproc.hpp>
#include <QImage>
#include <vector>
#define     H_channel   0
#define     S_chennel   1
#define     V_channel   2

using namespace std;
using namespace cv;

class Image
{
private:
    string          directory;
    Mat             image;
    string          imageName;
    vector<Mat>     hsv;


public:
    Image();
    ~Image();

    void                    SetDirectory(string directory);
    string                  GetDirectory();
    bool                    LoadImage();
    void                    SetImage(Mat image);
    Mat                     GetImage();
    void                    SetImageName(string name);
    string                  GetImageName();
    void                    Convert2HSV();
    Mat                     GetHSV(uint8_t channel);
    vector<vector<Point> >  FindContours(Mat &outputImage);

    Mat                     AutomaticThreshold(Mat image);
    Mat                     HandMadeThreshold(Mat image, int value);
    void                    ConvertMat2QPixmap(Mat image, QPixmap &pixmap);

};

#endif // IMAGE_H
