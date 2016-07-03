#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <function.h>


#include <iostream>
#include <cmath>

class Ellipse: public Function{
private:
    float a = 1;
    float b = 1;

    float function(float X){
        return std::sqrt(b * b - (b * b * X * X) / a * a);
    }
public:
    Ellipse(float a = 1, float b = 1){
        this->a = a;
        this->b = b;
    }

    float getY(float X){
            return function(X);
    }

    std::string out(){
        std::string result;
        result.append("Ellipse - a:");\
        result.append(std::to_string(a));
        result.append(", b:");
        result.append(std::to_string(b));
        return result;
    }
};

#endif // ELLIPSE_H
