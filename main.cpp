#include <iostream>
#include <list>
#include "main.h"

using std::cout;


std::list<dot> JarvisSeq(std::list<dot> Dots){
    std::list<dot> res;
    //Get first dot
    dot firstDot = *Dots.begin();
    for(auto dot:Dots){
        if((dot.y < firstDot.y)||((dot.y==firstDot.y)&&(dot.x<firstDot.x)))firstDot = dot;
    }
    res.push_back(firstDot);
    ///
    
    while (true)
    {
        dot next = Dots.back();
        for(auto dot:Dots){
            if(getRotate(res.back(),next)>getRotate(res.back(),dot))next = dot;
        }
        if (next == firstDot) return res;
        else{
            res.push_back(next);
            Dots.remove(next);
        }
    }
    
}


int main(){

}
