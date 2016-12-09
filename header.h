#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include "stack.h"
#include <algorithm>
#include <deque>
#include <stack>

using namespace std;

class order
{
private:
        string result;
        Stack stak;
        deque<string> buffer;
        deque<char> deq;
        stack<string> st;
public:
        void Postfix(string &value);
        void Prefix(string &value);
        void PostInfix(string &value);
        void PrefInfix(string &value);
        void Calc(string &value);
        void Show() { cout << result << endl; }
};

void order::Postfix(string &value)
{
    result = "";

    for(unsigned int i=0; i<value.length(); i++)
    {
        if((value[i] != '+') && (value[i] != '-') && (value[i] != '^') && (value[i] != ')') && (value[i] != '(' )
                && (value[i] != '*')) result += value[i];

        if((value[i] == '+') || (value[i] == '-') || (value[i] == '^') || (value[i] == '*')) stak.Push(value[i]);

        if(value[i] == ')')
        {
            result += stak.first->data;
            stak.Pop();
        }
    }
}

void order::Prefix(string &value)
{
    result = "";

    for(int i=value.length()-1; i>=0; i--)
    {
        if((value[i] != '+') && (value[i] != '-') && (value[i] != '^') && (value[i] != ')') && (value[i] != '(' )
                && (value[i] != '*')) result += value[i];

        if((value[i] == '+') || (value[i] == '-') || (value[i] == '^') || (value[i] == '*')) stak.Push(value[i]);

        if(value[i] == '(')
        {
            result += stak.first->data;
            stak.Pop();
        }
    }

    reverse(result.begin(), result.end());
}

void order::PostInfix(string &value)
{
    result = "";


    for(unsigned int i=0; i<value.length(); i++)
    {
        if((value[i] != '+') && (value[i] != '-') && (value[i] != '^') && (value[i] != ')') && (value[i] != '(' )
                && (value[i] != '*'))
        {
            string temp = "";
            temp = value[i];
            buffer.push_front(temp);
        }

        if((value[i] == '+') || (value[i] == '-') || (value[i] == '^') || (value[i] == '*'))
        {
            result = "";
            result += "( ";
            result += buffer.back();
            buffer.pop_back();
            result += value[i];
            result += buffer.back();
            buffer.pop_back();
            result += " )";
            buffer.push_front(result);
        }
    }

    buffer.clear();
}


void order::PrefInfix(string &value)
{
    result = "";


    for(int i=value.length()-1; i>=0; i--)
    {
        if((value[i] != '+') && (value[i] != '-') && (value[i] != '^') && (value[i] != ')') && (value[i] != '(' )
                && (value[i] != '*'))
        {
            string temp = "";
            temp = value[i];
            buffer.push_front(temp);
        }

        if((value[i] == '+') || (value[i] == '-') || (value[i] == '^') || (value[i] == '*'))
        {
            result = "";
            result += "( ";
            result += buffer.front();
            buffer.pop_front();
            result += value[i];
            result += buffer.front();
            buffer.pop_front();
            result += " )";
            buffer.push_front(result);
        }
    }

    buffer.clear();
}

void order::Calc(string &value)
{
    result = "";

    this->Postfix(value);

    for(unsigned int i=0; i<result.length(); i++)
    {
        if((result[i] == '+') || (result[i] == '-') || (result[i] == '^') || (result[i] == '*'))
            deq.push_back(result[i]);
    }

    int j = 1;

    char temp = result[0];
    int res = atoi(&temp);

    while(!deq.empty())
    {
        while(result[j] != deq.front())
        {
            if(deq.front() == '+')
                res += atoi(&result[j]);

            if(deq.front() == '*')
                res *= atoi(&result[j]);

            if(deq.front() == '-')
                res -= atoi(&result[j]);

            if(deq.front() == '^')
                res *= atoi(&result[j]);

            j++;
        }

        j++;

        deq.pop_front();
    }

    deq.clear();
    cout << "Результат: " << res << endl;

}

#endif // HEADER_H
