//
// Created by cooder on 2022/8/30.
//
/**
 * @file expio.h
 * @brief 表达式的io操作
 * @author cooder
 * */
#ifndef INFIXTOPOSTFIXEXPRESSION_EXPIO_H
#define INFIXTOPOSTFIXEXPRESSION_EXPIO_H
#include<iostream>
#include<string>
#include<sstream>
#include<fstream>

namespace expio
{
    /**
     * @brief 获取字符串中的元素
     * */
    std::string getelemt(const std::string* pstr,char delim);
};

#endif //INFIXTOPOSTFIXEXPRESSION_EXPIO_H
