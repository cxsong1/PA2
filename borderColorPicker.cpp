#include "borderColorPicker.h"

borderColorPicker::borderColorPicker(unsigned int borderSize, HSLAPixel fillColor, PNG &img, double tolerance)
{
    /* your code here */
    this->borderSize = borderSize;
    this->fillColor = fillColor;
    this->img = img;
    this->tolerance = tolerance;

}

HSLAPixel borderColorPicker::operator()(point p)
{
    /* your code here */
    int MDS = borderSize*borderSize;
    HSLAPixel ret;
    for(int x = -borderSize; x <= (int)borderSize; x++){
        for(int y = -borderSize; y <= (int)borderSize; y++){
            if (x*x + y*y <= MDS &&
            ( (p.x + x) > img.width() || p.x + x < 0 || p.y + y > img.height() || p.y + y < 0 ||
            img.getPixel(p.x + x, p.y + y)->dist(fillColor) > tolerance)){
                ret.h = fillColor.h;
                ret.s = fillColor.s;
                ret.l = fillColor.l;
                ret.a = fillColor.a;
                return ret;
            }
        }
    }
    ret.h = img.getPixel(p.x, p.y)->h;
    ret.s = img.getPixel(p.x, p.y)->s;
    ret.l = img.getPixel(p.x, p.y)->l;
    ret.a = img.getPixel(p.x, p.y)->a;
    return ret;
}
