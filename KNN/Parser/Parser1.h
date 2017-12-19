#ifndef PARSER1_H
#define PARSER1_H

#include <iostream>
#include <fstream>
#include <vector>

class Parser1 {

private:

    size_t i;
    std::ifstream fin;
    std::vector<double> numbers;
    std::vector<std::vector<double>> database;

private:
    void setI(size_t i);
    size_t getI();

public:

    Parser1(std::string path);

    void reading(std::string path);
    void reading1(std::string path) throw ( std::string );

    void display();
    void display1();

};

#endif // PARSER1_H
