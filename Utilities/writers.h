#ifndef WRITERS_H
#define WRITERS_H
#include <string>
#include <iostream>
#include <fstream>

class Writer
{
public:
     virtual void write(std::string msg) = 0;
};

class ConsoleWriter : public Writer
{
public:
    ConsoleWriter(){};
    void write(std::string msg) override;
};

class FileWriter : public Writer
{
    std::string outputPath;
public:
    FileWriter(std::string _outputPath):outputPath(_outputPath) {};
    void write(std::string) override;
};

#endif // WRITERS_H
