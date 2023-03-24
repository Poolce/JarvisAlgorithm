#include <cmath>
#include <iostream>
#include <list>
#include <random>

using std::cout;

struct dot {
    double x;
    double y;
    dot(int _x, int _y) : x(_x), y(_y) {}
    bool operator==(dot b) {
        return ((x == b.x) && (y == b.y)) ? (true) : (false);
    }
    bool operator!=(dot b) { return !operator==(b); }
};

std::list<dot> getRandDots(int size) {
    std::list<dot> res;
    for (int i = 0; i < size; i++) {
        double x = random() % 100;
        double y = random() % 100;
        res.push_back(dot(x, y));
    }
    return res;
}

void outDots(std::list<dot> dots) {
    std::cout << "{";
    for (auto i : dots) {
        std::cout << "dot(" << i.x << ", " << i.y << "), ";
    }
    std::cout << "}\n";
}

double getRotate(dot a, dot b) {
    double res = atan2(b.y - a.y, b.x - a.x);
    if (res < 0) res += 2 * M_PI;
    return res;
}

double getLen(dot a, dot b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

double getCos(dot A, dot O, dot B){
    double mult = (A.x-O.x)*(B.x-O.x)+(A.y-O.y)*(B.y-O.y);
    double len1 = sqrt(pow(A.x-O.x,2)+pow(A.y-O.y,2));
    double len2 = sqrt(pow(B.x-O.x,2)+pow(B.y-O.y,2));
    return mult/(len1*len2);
}

std::list<dot> JarvisSeq(std::list<dot> Dots) {
    std::list<dot> res;

    //////////////////////////GET FIRST////////////////////
    dot first = *Dots.begin();
    for (auto dot : Dots) {
        if (first.y > dot.y) first = dot;
        if ((first.y == dot.y) && (first.x > dot.x)) first = dot;
    }
    res.push_back(first);

    //////////////////////////GET SECOND////////////////////
    dot second = *Dots.begin();
    for (auto dot : Dots) {
        if (getRotate(first, dot) > getRotate(first, second)) second = dot;
        if (getRotate(first, dot) == getRotate(first, second)) {
            if(getLen(first, second)>getLen(first,dot)) second = dot;
        }
    }
    res.push_back(second);
    Dots.remove(second);

    //////////////////////////GET NEXT/////////////////////

    while (true)
    {
        auto iter = res.end();
        --iter;
        dot lastRes = *iter;
        --iter;
        dot prevLastRes = *iter;

        dot next = *Dots.begin();
        for(auto i : Dots){
            if(getCos(prevLastRes, lastRes, next)>getCos(prevLastRes, lastRes, i)) next = i;
        }
        if(next == first) return res;
        else{
            res.push_back(next);
            Dots.remove(next);
        }
    }
    
}