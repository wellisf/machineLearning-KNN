#include "Parser.h"

Parser::Parser(std::string path) {

    reading(path);
}

Parser::~Parser() {

    //numbers.clear();
    database.clear();
}


std::vector<std::vector<double>> Parser::getDatabase() {

    return database;
}

void Parser::reading(std::string path) throw ( std::string ) {

    fin.open(path);
    //char ch;
    double num;

    if (fin.is_open()) {
        while (fin >> num) {             // read a number

            numbers.push_back(num);     // store the number
            //fin >> ch;               // read and discard the comma

            if ( fin.peek()  == '\n') {          // identifies the \ n in the file
                database.push_back(numbers);
                numbers.clear();
            }
        }

        database.push_back(numbers);
        numbers.clear();

    } else
        throw std::string(" Error: File not exists ");
}

void Parser::display() {

    // display the result
    for (size_t i=0; i<database.size(); i++) {
        for (size_t j=0; j<database[i].size(); j++) {

            std::cout << database[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

