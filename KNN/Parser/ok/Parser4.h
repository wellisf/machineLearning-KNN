#ifndef PARSER1_H
#define PARSER1_H

#include <iostream>
#include <fstream>
#include <vector>

class Parser {

private:

    std::ifstream fin;
    std::vector<double> numbers;
    std::vector<std::vector<double>> database;

private:

    void reading(std::string path) throw ( std::string ) ;

public:

    Parser(std::string path);
    ~Parser();

    void display();
    std::vector<std::vector<double>> getDatabase();

};

#endif // PARSER1_H
