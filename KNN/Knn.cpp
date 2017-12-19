#include "Knn.h"

Knn::Knn(std::string path, std::string parameter) {

    setPath(path);
    setPathParameter(parameter);

    setDataset();
}

unsigned int Knn::getMinkowski() const
{
    return minkowski;
}

void Knn::setMinkowski(unsigned int value)
{
    minkowski = value;
}

unsigned int Knn::getK() const
{
    return k;
}

void Knn::setK(unsigned int value)
{
    k = value;
}

unsigned int Knn::getDimensions() const
{
    return dimensions;
}

void Knn::setDimensions(unsigned int value)
{
    dimensions = value;
}

unsigned int Knn::getCardinality() const
{
    return cardinality;
}

void Knn::setCardinality(unsigned int value)
{
    cardinality = value;
}

std::string Knn::getPath() const
{
    return path;
}

void Knn::setPath(const std::string &value)
{
    path = value;
}

std::string Knn::getPathParameter() const
{
    return pathParameter;
}

void Knn::setPathParameter(const std::string &value)
{
    pathParameter = value;
}

//ParClassDistance Knn::getPair() const
//{
//    return pair;
//}

//void Knn::setPair(const ParClassDistance &value)
//{
//    pair = value;
//}

void Knn::setDataset() {

    Parser data(getPath(),getPathParameter());

    this->dataset = data.getDataset();
    setMinkowski( data.getMinkowski() );
    setK( data.getK() );
    setCardinality( data.getCardinality() );
    setDimensions( data.getDimensions());
}

double Knn::distanceFromMinkowski(Instance p, Instance q) {

    double sum = 0.0;
    int r = getMinkowski();

    for (size_t k=0; k < getDimensions(); k++) {

        double temp =  pow (fabs ((p[k] - q[k])),r) ;

        sum += temp;

    }

    sum = pow(sum, (1.0 / r) );

    return sum;
}

/// Where magic happens
///
/// resultado do classificar ficará aqui
///
///

void Knn::addInQueue( Instance x ) {

    Parser testSet( getPath(), getPathParameter() );

    ParClassDistance pair;

    double partial = 0.0;

    for (size_t i=0; i < getCardinality(); i++) {

        partial = distanceFromMinkowski(x, testSet.getInstance(i));

        if (i < 5) {

            pair.first = testSet.getLabel(i);
            pair.second = partial;

            queueDepriority.push(pair);

        }
        else {

            pair = queueDepriority.top();

            if (pair.second > partial) {

                pair.first = testSet.getLabel(i);
                pair.second = partial;

                queueDepriority.pop();
                queueDepriority.push(pair);
            }
        }
    }
}

TypeLabel Knn::classify(Instance x) {

    //Fill in the queue
    addInQueue(x);

    size_t cutOff = ( queueDepriority.size() - getK() );

    ///
    /// filter of queue
    /// Leaves only the necessary elements
    ///

    for (size_t i = 0; i  < cutOff; i++)

        queueDepriority.pop();

    if ( ( queueDepriority.size() ) == 1 )  {

        ParClassDistance pair;

        pair = queueDepriority.top();
        queueDepriority.pop();

        return (pair.first);

    } else {

        std::priority_queue<ParClassDistance, std::vector<ParClassDistance>, MoreThan> selected;
        cutOff = queueDepriority.size();

        for (size_t i = 0; i  < cutOff; i++) {

            ParClassDistance pair;
            pair = queueDepriority.top();
            queueDepriority.pop();
            pair.second = 0;

            std::cout << pair.first << std::endl;

            selected.push(pair);
        }

        ParClassDistance result;
        result = selected.top();

        return result.first;

    }
}














