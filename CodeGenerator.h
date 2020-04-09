#ifndef CODEGENERATOR_H
#define CODEGENERATOR_H

#include <string>
#include <memory>

#include <interfaces.h>

class CodeGenerator
{

    std::shared_ptr<AbstractFactory> factory;

public:
    CodeGenerator(std::string langauge);
    void Compile();
};

#endif // CODEGENERATOR_H
