//
// Created by cooder on 2022/8/30.
//

#ifndef INFIXTOPOSTFIXEXPRESSION_EXPCALC_H
#define INFIXTOPOSTFIXEXPRESSION_EXPCALC_H
#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include"expio.h"

namespace expcalc
{

    std::string getelemt(const std::string* pstr,char delim);

    double str2double(std::string str);

/**
 * @brief 计算后缀表达式
 * @return 计算结果
 * */
    std::string calcPostfix(const std::string & postfix);

};
#endif //INFIXTOPOSTFIXEXPRESSION_EXPCALC_H
