#include <QCoreApplication>

#include <cstdio>
#include <iostream>
#include <sstream>
#include <cstring>

#include <fstream>
#include <vector>

#include <Parser.h>
#include <Knn.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    try {

        Knn result("LIBRAS.csv","parameter.txt");
        Parser test("LIBRAS.csv","parameter.txt");

       // test.printInstance(1);


        // std::cout << funfa.getPair().first << std::endl;

        std::cout << result.classify( test.getInstance(63)) << std::endl;



    } catch ( std::string notification ) {
        std::cout << notification << std::endl;
    }

    return a.exec();
}
