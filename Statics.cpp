#include <fstream>
#include <string>

#include "Statics.hpp"

std::string readFile(const std::string & filename)
{
    std::ifstream file;
    file.open(filename);

    std::string output;
    std::string oneLine;

    if (file.is_open())
    {
        while (file.good())
        {
            std::getline(file, oneLine);
            output.append(oneLine + '\n');
        }
    }
    else
    {
        throw std::invalid_argument("Can not open file " + filename);
    }

    return output;
}