#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include <string>

class Function
{
private:
    float function(float X){
        return X;
    }

public:

    Function(){
    }

    virtual float getY(float X){
            return function(X);
    }

    virtual std::string out(){
        return std::string("Function");
    }
};

#endif // FUNCTION_H
