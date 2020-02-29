#include "fadeColorPicker.h"

fadeColorPicker::fadeColorPicker(double fade)
{
    fadeFactor = fade; 
}

HSLAPixel fadeColorPicker::operator()(point p)
{
    double distanceSquare = (p.x-p.c.x)*(p.x-p.c.x) + (p.y-p.c.y)*(p.y-p.c.y); 
    HSLAPixel ret; 
    ret.h = p.c.color.h; 
    ret.l = p.c.color.l; 

    for(int i = 0; i < distanceSquare; i++){
        ret.l *= fadeFactor; 
    }
    ret.s = p.c.color.s; 

    return ret; 
}
