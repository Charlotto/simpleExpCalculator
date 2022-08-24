//
// Created by cooder on 2022/8/24.
//
#include"expconvert.h"

char* Expconvert::toPostfix()
{
    std::stack<char> opts;
    char* postfix = new char[len];
    char get;
    for(int i = 0; i < len; i++)
    {
        get = infix[i];
        if(get == '(')
        {
            opts.push(get);
        }
        if()
    }

}

char *Expconvert::toPrefix()
{

}
