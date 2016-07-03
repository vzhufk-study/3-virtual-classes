#ifndef HYPERBOLA_H
#define HYPERBOLA_H

#include <function.h>

class Hyperbola: public Function{
private:
    float a = 1;
    float b = 1;

    float function(float X){
        return std::sqrt(-(b * b) + (b * b * X * X) / a * a);
    }
public:
    Hyperbola(float a = 1, float b = 1){
        this->a = a;
        this->b = b;
    }

    virtual float getY(float X){
        return function(X);
    }

    std::string out(){
        std::string result;
        result.append("Hyperbola - a:");\
        result.append(std::to_string(a));
        result.append(", b:");
        result.append(std::to_string(b));
        return result;
    }
};

#endif // HYPERBOLA_H
