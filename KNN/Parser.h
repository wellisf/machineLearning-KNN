#ifndef PARSER1_H
#define PARSER1_H

#include <iostream>
#include <fstream>
#include <vector>

typedef int TypeLabel;
typedef std::vector<double> Instance;
typedef std::vector<TypeLabel> Label;

class Parser {

private:

    std::ifstream fin;
    std::ifstream fparameter;
    Label labelDataset;
    std::vector< Instance > dataset;
    unsigned int cardinality;
    unsigned int dimensions;
    bool hasLabel;
    unsigned int minkowski, k;

private:

    void readingParameter(std::string parameter) throw (std::string);
    void reading(std::string path) throw ( std::string ) ;

    void setCardinality(unsigned int value);
    void setDimensions(unsigned int value);
    void setMinkowski(unsigned int value);
    void setHasLabel(bool value);
    void setK(unsigned int value);

public:

    Parser(std::string path, std::string pathParameter);
    ~Parser();

    void display();
    void printInstance(int index);
    void printClass(int index);

    TypeLabel getLabel(int index) throw (std::string);
    Instance getInstance(int index);

    std::vector<Instance> getDataset() const;

    unsigned int getDimensions() const;
    unsigned int getCardinality() const;
    unsigned int getMinkowski() const;
    bool getHasLabel() const;
    unsigned int getK() const;




};

#endif // PARSER_H
