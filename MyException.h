#pragma once
#include <iostream>
using namespace std;

class MyException : public exception
{
    char* msg;
public :
    MyException(char*m){msg=m;}
    const char*what(){ return msg;}
};
