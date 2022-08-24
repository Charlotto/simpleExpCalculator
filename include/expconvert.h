//
// Created by cooder on 2022/8/23.
//

#ifndef INFIXTOPOSTFIXEXPRESSION_EXPCONVERT_H
#define INFIXTOPOSTFIXEXPRESSION_EXPCONVERT_H
#include<iostream>
#include<stack>
#include<new>

class Expconvert
{
private:
    char* infix;
    int len;

public:
    Expconvert(): infix(nullptr), len(0) {}
    Expconvert(char* _infix)
    {
        infix = _infix;
        len = sizeof _infix;
    }

    /**
     * @brief 将中缀表达式转换为后缀表达式
     * */
    char* toPostfix();

    /**
     * @brief 将中缀表达式转换为前缀表达式
     * */
    char* toPrefix();
};
#endif //INFIXTOPOSTFIXEXPRESSION_EXPCONVERT_H
