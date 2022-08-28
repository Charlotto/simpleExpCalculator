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
    static std::istringstream ss(infix);
    std::string nowstr;
    if(!std::getline(ss, nowstr, splim))
    {
        ss.clear();
        //装填新字符串
        ss.str(infix);
        nowstr = "er";
    }
    return nowstr;
}

std::string Expconvert::toPostfix()
{
    std::stack<char> opts;
    std::string nowstr;
    std::string postfix;
    while((nowstr = getstr(' ')) != "er")
    {
        // 是操作符
        int optlv;
        if((optlv = optlevel(nowstr[0])) != -1)
        {
            switch(optlv)
            {
                case 0:
                    if(nowstr == ")")
                    {
                        char opt;
                        while(!opts.empty() && (opt = opts.top()) != '(')
                        {
                            postfix += opts.top();
                            postfix += " ";
                            opts.pop();
                        }
                        opts.pop();
                    }
                    else if (nowstr == "(")
                    {
                        opts.push(nowstr[0]);
                    }
                    break;
                case 1:
                    opts.push(nowstr[0]);
                    break;
                case 2:
                    //
                    if(!opts.empty() && optlevel(opts.top()) < 2 && opts.top() != '(')
                    {
                        char opt;
                        while((opt = opts.top()) != '(')
                        {
                            postfix += opts.top();
                            opts.pop();
                        }
                        opts.push(nowstr[0]);
                    }
                    else if(opts.empty() || (!opts.empty() && opts.top() == '(' || optlevel(opts.top()) >= 2))
                    {
                        opts.push(nowstr[0]);
                    }
                    break;
                case 3:
                    if(!opts.empty() && (optlevel(opts.top()) == 3 || opts.top() == '('))
                    {
                        opts.push(nowstr[0]);
                    }
                    else if(!opts.empty() && optlevel(opts.top()) < 3 && opts.top() != '(')
                    {
                        char opt;
                        while((opt = opts.top()) != '(')
                        {
                            postfix += opt;
                            postfix += " ";
                            opts.pop();
                        }
                    }
                    else
                    {
                        opts.push(nowstr[0]);
                    }
                    break;
            }

        }
        // 是操作数
        else
        {
            postfix += nowstr;
            postfix += " ";
        }
    }
    //清空运算符
    while(!opts.empty())
    {
        if(opts.top() != '(')
        {
            postfix += opts.top();
            postfix += " ";
            opts.pop();
        }
        else
        {
            opts.pop();
        }
    }
    return postfix;
}

std::string Expconvert::toPrefix()
{
    std::string postfix = toPostfix();
    postfix.erase(postfix.end() - 1);
    std::reverse(postfix.begin(), postfix.end());
    return postfix;
}