#include "Parser1.h"

Parser1::Parser1(std::string path) {

    setI(0);
    reading(path);
    //reading1(path);
}

void Parser1::setI(size_t i) {

    this->i = i;
}

size_t Parser1::getI() {

    return i;
}

std::vector<std::vector<double>> Parser1::getDatabase() {

    return database;
}

void Parser1::reading(std::string path) {

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

void Parser1::display1() {

    // display the result
    for (size_t i=0; i<database.size(); i++) {
        for (size_t j=0; j<database[i].size(); j++) {

            std::cout << database[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

