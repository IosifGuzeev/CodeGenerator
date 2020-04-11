#include "writers.h"

void ConsoleWriter::write(std::string msg)
{
    std::cout << msg << std::endl;
}


void FileWriter::write(std::string msg)
{
    std::ofstream myfile;
    myfile.open (outputPath);
    myfile << msg + "\n";
    myfile.close();
}
