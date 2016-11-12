#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include "stack.h"
#include <algorithm>
#include <deque>

using namespace std;

class order
{
private:
        string result;
        Stack stack;
        deque<string> buffer;
public:
        void Postfix(string &value);
        void Prefix(string &value);
        void PostInfix(string &value);
        void PrefInfix(string &value);
        void Show() { cout << result << endl; }
};

void order::Postfix(string &value)
{
    result = "";

    for(unsigned int i=0; i<value.length(); i++)
    {
        if((value[i] != '+') && (value[i] != '-') && (value[i] != '^') && (value[i] != ')') && (value[i] != '(' )
                && (value[i] != '*')) result += value[i];

        if((value[i] == '+') || (value[i] == '-') || (value[i] == '^') || (value[i] == '*')) stack.Push(value[i]);

        if(value[i] == ')')
        {
            result += stack.first->data;
            stack.Pop();
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

        if((value[i] == '+') || (value[i] == '-') || (value[i] == '^') || (value[i] == '*')) stack.Push(value[i]);

        if(value[i] == '(')
        {
            result += stack.first->data;
            stack.Pop();
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

#endif // HEADER_H
