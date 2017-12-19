#include "Knn.h"

Knn::Knn(std::string path, std::string parameter) {

    setDataset();
}

void Knn::setDataset() {

    Parser data("iris.csv","parameter.txt");

    this->dataset = data.getDataset();
    //minkowski(data.minkowski);
}

double Knn::minkowski(unsigned int r, Instance x, Instance y) {

    double sum=0;

    for (size_t i=0; i<dataset.size()-1; i++) {
        for (size_t j=0; j<dataset[i].size(); j++) {

            sum += pow( ( dataset[i][j] - dataset[i+1][j] ), r) ;
        }
    }

    sum = pow(sum, (1/r));

    return sum;
}
