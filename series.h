#ifndef SERIES_H
#define SERIES_H


#include <function.h>
#include <ellipse.h>
#include <hyperbola.h>


//file
#include <fstream>
#include <string>

class Series{
private:
    Function **value;

    unsigned amount;

    static unsigned length;

public:


    Series(unsigned number = 3){
        value = new Function*[number];
        amount = number;
    }

    void set(Function *X, unsigned place = ++length){
        value[place] = X;
    }

    void sortByValueIn(float X = 0, unsigned left = 0, unsigned right = length){
              unsigned i = left, j = right;
              Function *pivot = value[(left + right) / 2];

              /* partition */
              while (i <= j) {
                    while (value[i]->getY(X) < pivot->getY(X))
                          ++i;
                    while (value[j]->getY(X) > pivot->getY(X))
                          --j;
                    if (i <= j) {
                        Function *tmp = value[i];
                        value[i] = value[j];
                        value[j] = tmp;
                          i++;
                          j--;
                    }
              };

              /* recursion */
              if (left < j)
                    sortByValueIn(X, left, j);
              if (i < right)
                    sortByValueIn(X, i, right);
        }

    std::string out(unsigned start = 0, unsigned end = length){
        std::string result;
        for (unsigned i = start; i < end; ++i){
            result.append(value[i]->out());
             result.append("\n");
        }
        return result;
    }

    void out(std::string file_name, unsigned start = 0, unsigned end = length){
        std::ofstream output;
        output.open(file_name, std::ofstream::out | std::ofstream::app);
        output<<out(start, end);
        output.close();
    }

    void in(std::string file_name, unsigned start = 0, unsigned end = length){
        std::ifstream input;
        input.open(file_name);
        for (unsigned i = start; i < end; ++i){
            char new_function;
            input>>new_function;
            float a, b;
            input>>a>>b;

            Function *tmp;
            if (new_function == 'e'){
                tmp = new Ellipse(a, b);
            }else if (new_function == 'h'){
                tmp = new Hyperbola(a, b);
            }else{
                tmp = new Function();
            }

            set(tmp, i);
        }
        input.close();
    }
};

#endif // SERIES_H
