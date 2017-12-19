#ifndef KNN_H
#define KNN_H

//#include <iostream>
//#include <fstream>
//#include <vector>

#include <math.h>
#include <queue>

#include <Parser.h>

typedef std::vector<TypeLabel> Label;

typedef std::pair<int, double> ParClassDistance;

struct LessThan {

    bool operator () ( const ParClassDistance& par1, const ParClassDistance& par2) {

        return (par1.second < par2.second);
    }
};

struct MoreThan {

    bool operator () ( const ParClassDistance& par1, const ParClassDistance& par2) {

        return (par1.second > par2.second);
    }
};

class Knn {

private:

    std::priority_queue<ParClassDistance, std::vector<ParClassDistance>, LessThan> queueDepriority;

    //ParClassDistance pair;

    std::string path, pathParameter;

    std::vector<std::vector<double>> dataset;
    unsigned int cardinality;
    unsigned int dimensions;
    unsigned int minkowski;
    unsigned int k;

private:

    void setDataset();
    void setK(unsigned int value);
    void setMinkowski(unsigned int value);
    void setDimensions(unsigned int value);
    void setCardinality(unsigned int value);

    void setPath(const std::string &value);
    void setPathParameter(const std::string &value);

    double distanceFromMinkowski(Instance p, Instance q);
    void addInQueue( Instance x );

public:

    Knn(std::string path, std::string parameter);

    TypeLabel classify(Instance x);

    unsigned int getK() const;
    unsigned int getMinkowski() const;
    unsigned int getDimensions() const;
    unsigned int getCardinality() const;

    std::string getPath() const;
    std::string getPathParameter() const;

    ParClassDistance getPair() const;

    void setPair(const ParClassDistance &value);
};


#endif // KNN_H
