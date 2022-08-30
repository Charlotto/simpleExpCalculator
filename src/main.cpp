//
// Created by cooder on 2022/8/24.
//
#include"expconvert.h"
#include"expcheck.h"
int main ()
{
    std::string str;
    std::cout << "input infix expression: " << std::endl;
    std::getline(std::cin, str);
    if(!expcheck::iligalStrChek(str) || !expcheck::bracketMatchingChek(str))
    {
        std::cout << "iligal expression !" << std::endl;
    }
    else
    {
        str = expcheck::fixblank(str);
        Expconvert ep (str);
        std::string postfix = ep.toPostfix();
        std::cout << postfix << std::endl;
        std::cout << "prefix :\n" << ep.toPrefix() << std::endl;
    }

    return 0;
}

/*
 * test:
 *  (2 + 3 * 4) / 5 ^ 2
 *  2 3 4 * + 5 2 ^ /
 * */