//
// Created by cooder on 2022/8/24.
//
#include"expconvert.h"


int Expconvert::optlevel(char opt) {
    char opts[] {'(', ')', '^', '*', '/', '+', '-'};
    int optflag = -1;
    char* optpos = std::find(opts, opts+6, opt);
    if(*optpos == '-' && opt !='-')
    {
        return -1;
    }
    switch(*optpos)
    {
        case '(':
        case ')':
            optflag = 0;
            break;
        case '^':
            optflag = 1;
            break;
        case '*':
        case '/':
            optflag = 2;
            break;
        case '+':
        case '-':
            optflag = 3;
            break;
    }
    return optflag;
}

std::string Expconvert::getstr(char splim)
{
    static std::stack<int> pos;
    std::string sample = infix;
    std::string result;
    if(pos.empty())
    {
        pos.push(0);
    }
    if(pos.top() == sample.length() - 1)
    {
        return "er";
    }
    int nowpos = pos.top();
    while(sample[nowpos] != splim && nowpos <= sample.length() - 1)
    {
        nowpos++;
    }
    result = sample.substr(pos.top(), nowpos);
    pos.pop();
    pos.push(++nowpos);
    return result;
}

std::string Expconvert::toPostfix()
{
    std::stack<char> opts;
    std::string nowstr = getstr(' ');
    std::string postfix;
    do
    {
        // is operator
        int optlv;
        if( (optlv = optlevel(nowstr[0])) != -1)
        {
            switch(optlv)
            {
                case 0:
                    if(nowstr == ")")
                    {
                        char nowopt;
                        while((nowopt = opts.top()) != '(')
                        {
                            postfix += " ";
                            postfix += nowopt;
                            opts.pop();
                        }
                        //pop (
                        opts.pop();
                        break;
                    }
                    else if(nowstr == "(")
                        opts.push(nowstr[0]);
                    break;
                case 1:
                    opts.push(nowstr[0]);
                    break;
                case 2:
                    if(optlevel(opts.top()) >= 2)
                    {
                        opts.push(nowstr[0]);
                    }
                    else if(optlevel(opts.top()) <= 1)
                    {
                        char pushopt = opts.top();
                        while(pushopt != '(')
                        {
                            postfix += " ";
                            postfix += pushopt;
                            opts.pop();
                            if(!opts.empty())
                            {
                                pushopt = opts.top();
                            }
                            else
                                break;
                        }
                        opts.push(nowstr[0]);
                    }
                case 3:
                    if(optlevel(opts.top()) == 3)
                    {
                        opts.push(nowstr[0]);
                    }
                    else
                    {
                        char pushopt = opts.top();
                        while(pushopt != '(')
                        {
                            postfix += " ";
                            postfix += pushopt;
                            opts.pop();
                            if(!opts.empty())
                            {
                                pushopt = opts.top();
                            }
                            else
                                break;
                        }
                        opts.push(nowstr[0]);
                    }
            }
        }
        // is operant
        else if(nowstr != " ")
        {
            postfix += " ";
            postfix += nowstr;
        }
        nowstr = getstr(' ');
    }while(nowstr != "er");

    return postfix;
}