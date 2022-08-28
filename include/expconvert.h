//
// Created by cooder on 2022/8/23.
//

#ifndef INFIXTOPOSTFIXEXPRESSION_EXPCONVERT_H
#define INFIXTOPOSTFIXEXPRESSION_EXPCONVERT_H
#include<iostream>
#include<stack>
#include<new>
#include<cstring>
#include<string>
#include<algorithm>
#include<sstream>

class Expconvert
{
private:
    std::string infix;
    int len;

    std::string splitStr(char spilm);

    /**
     * @brief 返回操作符所在的优先级
     * @param opt 操作符
     * @return 等级标志，从0开始
     * */
    int optlevel(char opt);


    std::string getstr(char splim);
public:
    Expconvert(): infix(" "), len(0) {}
    Expconvert(std::string _infix)
    {
        infix = _infix;
        len = _infix.length();
    }

    /**
     * @brief 将中缀表达式转换为后缀表达式
     * */
    std::string toPostfix();

    /**
     * @brief 将中缀表达式转换为前缀表达式
     * */
    std::string toPrefix();
};
#endif //INFIXTOPOSTFIXEXPRESSION_EXPCONVERT_H
