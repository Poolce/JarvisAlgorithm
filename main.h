#include <cmath>

struct dot
{
    double x;
    double y;
    dot(int _x, int _y) : x(_x), y(_y) {}
    bool operator==(dot b)
    {
        return ((x == b.x) && (y == b.y)) ? (true) : (false);
    }
    bool operator!=(dot b)
    {
        return !operator==(b);
    }
};

double getRotate(dot a, dot b){
    double res = atan2(b.y-a.y, b.x-a.x);
    if(res<0) res+= 2*M_PI;
    return res;
}
