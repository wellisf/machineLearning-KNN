#include "Parser.h"

Parser::Parser(std::string path) {

    setPath(path);
    openFile();
    reading();
}

void Parser::setPath(std::string path) {

    this->path = path;
}

std::string Parser::getPath() {

    return path;
}

void Parser::openFile() throw(std::string) {

    if (file.is_open())
        file.close();

    file.open(getPath());

    if ( !file.is_open() ) {
        throw std::string(" Error: File does not exists ");
    } else {
        if ( file.eof() ) {
            throw std::string(" Error: End of file ");
        }
    }
}

void Parser::reading() {

    std::cout << "aqui" << std::endl;


    while( file.good()) {
        Value temp;
        std::cout << "aqui123" << std::endl;
        buff.push_back(temp);
    }
}

bool Parser::size() {

    return file.eof();
}



