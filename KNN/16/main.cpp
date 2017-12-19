#include <QCoreApplication>

#include <cstdio>
#include <iostream>
#include <sstream>
#include <cstring>

#include <fstream>
#include <vector>

#include <Parser.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    try {

        Parser test("LIBRAS.csv","parameter.txt");

        std::cout << test.getCardinality() << std::endl;

        //test.printInstance(0);
        //test.printInstance(359);

        test.printClass(359);

    } catch ( std::string notification ) {
        std::cout << notification << std::endl;
    }

    return a.exec();
}
