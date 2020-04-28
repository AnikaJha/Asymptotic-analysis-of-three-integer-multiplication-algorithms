#include <ctime>
#include <fstream>

#include "number.h"
#include "multiplicator.h"


void out(size_t start, size_t end, size_t step, std::ofstream& ofstr)
{
    ofstr << "Size,GSM,DAC,Karatsuba\n";

    for (size_t i = start; i <= end ; i += step)
    {
        Multiplicator::testMethod(i, ofstr);
    }

}

int main()
{
    std::ofstream file;
    file.open("/Users/anikajha/Desktop/Numbers/outputFile.csv");
    out(1, 100, 1, file);  // start, stop, step - temporary parametrs
    file.close();

    return 0;
}
