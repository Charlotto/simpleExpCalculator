//
// Created by cooder on 2022/8/28.
//

#ifndef INFIXTOPOSTFIXEXPRESSION_EXPCHECK_H
#define INFIXTOPOSTFIXEXPRESSION_EXPCHECK_H

#include<iostream>
#include<string>
#include<algorithm>
// 静态方法
// 检查表达式是否有非法字符
namespace expcheck
{
    /**
     * @brief 检查表达式是否有非法字符
     * @return 检查无误返回true, 否则返回false
     * */
    bool iligalStrChek(std::string & str);

    /**
     * @brief 检查表达式括号是否匹配
     * @return 检查无误返回true, 否则返回false
     * */
    bool bracketMatchingChek(std::string & str);

    /**
     * @brief 修复空格缺省的表达式
     * */
    std::string fixblank(const std::string & str);

    /**
     * @brief 检查表达式格式是否合法
     * 检查内容包含操作数位置检查，操作符位置检查
     * @return 检查通过返回true ,否则返回false
     * */
    bool iligalExpChek(std::string & str);
};

#endif //INFIXTOPOSTFIXEXPRESSION_EXPCHECK_H
