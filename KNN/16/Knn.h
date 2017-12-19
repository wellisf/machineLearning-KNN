#ifndef KNN_H
#define KNN_H

//#include <iostream>
//#include <fstream>
//#include <vector>

#include <math.h>
#include <queue>

#include <Parser.h>

typedef std::pair<int, double> ParClassDistance;

struct LessThan {

    bool operator () ( const ParClassDistance& par1, const ParClassDistance& par2) {

        return (par1.second < par2.second);
    }
};

class Knn {

private:
    std::priority_queue<ParClassDistance, std::vector<ParClassDistance>, LessThan> queueDepriority;
    std::vector<std::vector<double>> dataset;
    //std::vector<double> neihbor;

private:

    void setDataset();

public:

    Knn(std::string path, std::string parameter);

    double minkowski(unsigned int r, Instance x, Instance y);

};


#endif // KNN_H
