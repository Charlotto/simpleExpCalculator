//
// Created by cooder on 2022/8/28.
//
#include"valcheck.h"
#include<stack>

bool iligalStrChek(std::string & str)
{
    /* 合法的表达式有：
     * 数字
     * 空格
     * 合法的操作符  ( ) ^ * / + -
     * */
    std::string::const_iterator iter = str.begin();
    std::string::const_iterator end = str.end();
    char opts[] {'(', ')', '^', '*', '/', '+', '-'};
    do
    {

        if( (std::find(opts, opts+6, *iter) != opts+6) || *iter == '-')
        {
            continue;
        }
        else if (*iter >= '0' && *iter <= '9')
        {
            continue;
        }
        else if(*iter == ' ')
        {
            continue;
        }
        else
        {
            return false;
        }
    }while(iter++ != end);
    return true;
}

bool bracketMatchingChek(std::string & str)
{
    std::stack<char> brket;
    std::string::const_iterator iter = str.begin();
    std::string::const_iterator end = str.end();

    do
    {
        if(*iter == '(')
        {
            brket.push(*iter);
        }
        else if (*iter == ')')
        {
            if(brket.empty())
            {
                return false;
            }

            brket.pop();
        }
    }while(iter++ != end);

    if(brket.empty())
    {
        return true;
    }
    return false;
}

std::string fixblank(std::string & str)
{
    char prevstr = '#';
    std::string::const_iterator iter = str.begin();
    std::string::const_iterator end = str.end();
    std::string res;
    char opts[] {'(', ')','^', '*', '/', '+', '-'};

    prevstr = *iter;
    iter++;

    while(iter < end)
    {
        if(prevstr == ' ')
        {
            prevstr = *iter;
        }
        else if(prevstr >= '0' && prevstr <= '9')
        {
            if(*iter >='0' && *iter <='9')
            {
                res += prevstr;
                prevstr = *iter;
            }
            else
            {
                res += prevstr;
                res += ' ';
                prevstr = *iter;
            }

        }
        else if (std::find(opts,opts+6, prevstr) != opts+6 || prevstr == '-')
        {
            res += prevstr;
            res += ' ';
            prevstr = *iter;
        }
        else
        {
            prevstr = *iter;
        }
        iter++;
    }
    if(* iter != ' ')
    {
        res += prevstr;
        res += ' ';
        prevstr = *iter;
    }
    return res;
}