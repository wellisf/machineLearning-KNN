#ifndef PARSER_H
#define PARSER_H

#include <cstdio>
#include <iostream>
#include <sstream>
#include <cstring>

#include <fstream>
#include <vector>

typedef double Value;

class Parser {

private:
    std::ifstream file;
    std::string path;


private:
    void reading();
    void openFile() throw ( std::string );

public:

    Parser(std::string path);

    void setPath( std::string path );

    std::string getPath();

    std::vector<Value> buff;

    bool size();
};

#endif // PARSER_H
