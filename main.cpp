#include <list>
#include <iostream>
#include "main.h"


bool isEQUAL(std::list<dot> A, std::list<dot> B){
    if(A.size()!=B.size())return false;
    auto j = B.begin();
    for(auto i = A.begin();i != A.end(); ++i){
        if(*i!=*j) return false;
        ++j;
    }
    return true;
}


int main(){
    std::list<dot> testList{dot(83, 86), dot(77, 15), dot(93, 35), dot(86, 92), dot(49, 21), dot(62, 27), dot(90, 59), dot(63, 26), dot(40, 26), dot(72, 36), dot(11, 68), dot(67, 29), dot(82, 30), dot(62, 23), dot(67, 35), dot(29, 2), dot(22, 58), dot(69, 67), dot(93, 56), dot(11, 42), dot(29, 73), dot(21, 19), dot(84, 37), dot(98, 24), dot(15, 70), dot(13, 26), dot(91, 80), dot(56, 73), dot(62, 70), dot(96, 81), dot(5, 25), dot(84, 27), dot(36, 5), dot(46, 29), dot(13, 57), dot(24, 95), dot(82, 45), dot(14, 67), dot(34, 64), dot(43, 50), dot(87, 8), dot(76, 78), dot(88, 84), dot(3, 51), dot(54, 99), dot(32, 60), dot(76, 68), dot(39, 12), dot(26, 86), dot(94, 39), dot(95, 70), dot(34, 78), dot(67, 1), dot(97, 2), dot(17, 92), dot(52, 56), dot(1, 80), dot(86, 41), dot(65, 89), dot(44, 19), dot(40, 29), dot(31, 17), dot(97, 71), dot(81, 75), dot(9, 27), dot(67, 56), dot(97, 53), dot(86, 65), dot(6, 83), dot(19, 24), dot(28, 71), dot(32, 29), dot(3, 19), dot(70, 68), dot(8, 15), dot(40, 49), dot(96, 23), dot(18, 45), dot(46, 51), dot(21, 55), dot(79, 88), dot(64, 28), dot(41, 50), dot(93, 0), dot(34, 64), dot(24, 14), dot(87, 56), dot(43, 91), dot(27, 65), dot(59, 36), dot(32, 51), dot(37, 28), dot(75, 7), dot(74, 21), dot(58, 95), dot(29, 37), dot(35, 93), dot(18, 28), dot(43, 11), dot(28, 29)};
    std::list<dot> testRes{dot(93, 0), dot(29, 2), dot(8, 15), dot(3, 19), dot(1, 80), dot(17, 92), dot(24, 95), dot(54, 99), dot(86, 92), dot(96, 81), dot(97, 71), dot(98, 24), dot(97, 2)};
    std::list<dot> res = JarvisSeq(testList);
    

    std::cout<<isEQUAL(testRes,res);
}