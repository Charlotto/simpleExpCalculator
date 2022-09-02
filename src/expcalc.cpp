//
// Created by cooder on 2022/8/30.
//
#include"expcalc.h"
#include<cstring>

std::string expcalc::getelemt(const std::string* pstr,char delim)
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

std::string expcalc::calcPostfix(const std::string & postfix)
{
    std::stack<double> oprs;
    std::string nowopr = getelemt(&postfix, ' ');
    double opr1, opr2;

//    std::stringstream ss;
    char opts[] {'(', ')', '^', '*', '/', '+', '-'};
    do
    {
        if(std::find(opts, opts+6, nowopr[0]) != opts+6 || nowopr == "-")
        {
            switch(nowopr[0])
            {
                case '^':
                    opr2 = oprs.top();
                    oprs.pop();
                    opr1 = oprs.top();
                    oprs.pop();
                    oprs.push(pow(opr1, opr2));
                    break;
                case '*':
                    opr2 = oprs.top();
                    oprs.pop();
                    opr1 = oprs.top();
                    oprs.pop();
                    oprs.push(opr1 * opr2);
                    break;
                case '/':
                    opr2 = oprs.top();
                    oprs.pop();
                    opr1 = oprs.top();
                    oprs.pop();
                    oprs.push(opr1 / opr2);
                    break;
                case '+':
                    opr2 = oprs.top();
                    oprs.pop();
                    opr1 = oprs.top();
                    oprs.pop();
                    oprs.push(opr1 + opr2);
                    break;
                case '-':
                    opr2 = oprs.top();
                    oprs.pop();
                    opr1 = oprs.top();
                    oprs.pop();
                    oprs.push( opr1 - opr2 );
                    break;
            }
        }
        else
        {
            oprs.push(str2double(nowopr));
        }
    }while((nowopr = getelemt(nullptr, ' ')) != "er");

    return std::to_string(oprs.top());
}


double expcalc::str2double(std::string str)
{
    char cstr[str.length()];
    double res = 0.0;
    std::strcpy(cstr, str.c_str());
    std::sscanf(cstr, "%lf", &res);
    return res;
}
