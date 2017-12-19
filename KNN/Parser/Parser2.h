#ifndef PARSER1_H
#define PARSER1_H

#include <iostream>
#include <fstream>
#include <vector>

class Parser {

private:

    size_t i;
    std::ifstream fin;
    std::vector<std::vector<double>> database;

private:
    void setI(size_t i);
    size_t getI();

public:

    Parser(std::string path);

    //~Parser();

    void reading(std::string path) throw ( std::string );

    std::vector<std::vector<double>> getDatabase();

    void display();

    //void display();
    //void reading(std::string path);
};

#endif // PARSER1_H
