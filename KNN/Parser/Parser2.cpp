#include "Parser.h"

Parser::Parser(std::string path) {

    setI(0);
    reading(path);
}

//Parser::~Parser() {

//    database.clear();
//}

void Parser::setI(size_t i) {

    this->i = i;
}

size_t Parser::getI() {

    return i;
}

std::vector<std::vector<double>> Parser::getDatabase() {

    return database;
}

void Parser::reading(std::string path) throw ( std::string ) {

    fin.open(path);
    //char ch;
    double num;

    if (fin.is_open()) {
        while (fin >> num) {           // read a number

            database[getI()].push_back(num);  // store the number
            //fin >> ch;               // read and discard the comma

            if ( fin.peek()  == '\n') // identifies the \ n in the file
                setI( (getI() + 1) );
        }
    } else
        throw std::string(" Error: File not exists ");
}

void Parser::display() {

    std::cout << "database[i][j]" << std::endl;

    // display the result
    for (size_t i=0; i<database.size(); i++) {
        for (size_t j=0; j<database[i].size(); j++) {

            std::cout << database[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

///******************************************************************

//void Parser::display() {

//    // display the result
//    for (unsigned int i=0; i<numbers.size(); i++)
//        std::cout << numbers[i] << '\n';

//}

//void Parser::reading(std::string path) {

//    fin.open(path);
//    char ch;
//    double num;

//    if (fin.is_open()) {
//        while (fin >> num) {           // read a number

//            numbers.push_back(num);  // store the number
//            //fin >> ch;               // read and discard the comma

//            if ( fin.peek()  == '\n')
//                database.push_back(numbers);
//        }
//    } else {
//        std::cout << "erro" << std::endl;
//    }
//}
