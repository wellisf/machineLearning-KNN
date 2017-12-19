#include "Parser.h"

Parser::Parser(std::string path, std::string pathParameter) {

    readingParameter(pathParameter);
    reading(path);
}

Parser::~Parser() {

    dataset.clear();
    labelDataset.clear();
}

std::vector<Instance> Parser::getDataset() const
{
    return dataset;
}

unsigned int Parser::getCardinality() const
{
    return cardinality;
}

void Parser::setCardinality(unsigned int value)
{
    cardinality = value;
}

unsigned int Parser::getDimensions() const
{
    return dimensions;
}

void Parser::setDimensions(unsigned int value)
{
    dimensions = value;
}

unsigned int Parser::getMinkowski() const
{
    return minkowski;
}

void Parser::setMinkowski(unsigned int value)
{
    minkowski = value;
}

bool Parser::getHasLabel() const
{
    return hasLabel;
}

void Parser::setHasLabel(bool value)
{
    hasLabel = value;
}

/**
 * @brief readingParameter
 * @param parameter
 * @return void
 *
 *  Struct of file
 *  Line 1 - Cardinality
 *  Line 2 - Dimensions
 *  Line 3 - Label
 *  Line 4 - parameter for minkowski
 *  Line 5 - parameter for K
 */


void Parser::readingParameter(std::string parameter) throw (std::string) {

    fparameter.open(parameter);

    if(fparameter.is_open()) {

        fparameter >> cardinality;
        fparameter >> dimensions;
        fparameter >> hasLabel;
        fparameter >> minkowski;
        fparameter >> k;

    } else
        throw std::string(" Error in opening Parameter: File not exists ");

}

void Parser::reading(std::string path) throw ( std::string ) {

    fin.open(path);

    if (fin.is_open()) {

        Instance numbers;
        //char ch;
        double num;


        if (getHasLabel()) {

            for (unsigned int i = 0; i < getCardinality(); i++) {
                for (unsigned int j = 0; j < getDimensions()+1; j++) {

                    if ( getDimensions() != j ) {

                        fin >> num;
                        numbers.push_back(num);     // store the number

                    } else {

                        fin >> num;
                        labelDataset.push_back(num);
                    }
                }
                dataset.push_back(numbers);
                numbers.clear();
            }

        } else {

            for (unsigned int i = 0; i < cardinality; i++) {
                for (unsigned int j = 0; j < dimensions; j++) {

                    fin >> num;
                    numbers.push_back(num);     // store the number
                    //fin >> ch;               // read and discard the comma
                }
                dataset.push_back(numbers);
                labelDataset.push_back(-1);
                numbers.clear();
            }
        }

    } else
        throw std::string(" Error in opening Database: File not exists ");
}

void Parser::display() {

    // display the result
    for (size_t i=0; i < getCardinality(); i++) {
        for (size_t j=0; j< getDimensions(); j++) {

            std::cout << dataset[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void Parser::printInstance(int index) {

    for (size_t j=0; j < getDimensions(); j++)
        std::cout << dataset[index][j] << " ";
    std::cout << std::endl;
}

void Parser::printClass(int index) {

    std::cout << labelDataset[index] << std::endl;
}

TypeLabel Parser::getLabel(int index) throw (std::string) {

    if (getHasLabel()) {
        return labelDataset[index];
    } else {
        throw std::string(" Error in opening Database: File not exists ");
    }
}

Instance Parser::getInstance(int index) {

    return dataset[index];
}

