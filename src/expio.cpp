//
// Created by cooder on 2022/8/30.
//
#include"expio.h"
std::string expio::getelemt(const std::string* pstr,char delim)
{
    static std::istringstream ss;
    std::string res;
    if(pstr != nullptr)
    {
        ss.str(*pstr);
    }

    if(!std::getline(ss, res, delim))
    {
        res = "er";
    }
    return res;
}

