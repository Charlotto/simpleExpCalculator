//
// Created by cooder on 2022/8/28.
//

#ifndef INFIXTOPOSTFIXEXPRESSION_VALCHECK_H
#define INFIXTOPOSTFIXEXPRESSION_VALCHECK_H

#include<iostream>
#include<string>
#include<algorithm>
// 静态方法
// 检查表达式是否有非法字符
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
// 修正表达式空格缺少问题
std::string fixblank(const std::string & str);
#endif //INFIXTOPOSTFIXEXPRESSION_VALCHECK_H
