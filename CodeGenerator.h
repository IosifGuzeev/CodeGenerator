#ifndef CODEGENERATOR_H
#define CODEGENERATOR_H

#include <string>
#include <memory>
#include <map>

#include <interfaces.h>
#include <factories/cppFactory.h>
#include <Utilities/writers.h>

class CodeGenerator
{    
    using ClassPtr = std::shared_ptr<ClassUnit>;
    AbstractFactory *factory;
    Writer *writer;
    std::map<std::string, ClassPtr> classes;

public:
    enum Languages{
        cpp = 0,
        c_sharp = 1,
        java = 2
    };

    CodeGenerator(Languages langauge, Writer *_writer);
    ~CodeGenerator();
    void AddClassUnit(std::string name, unsigned int flags = 0);
    void AddMethodUnit(std::string className, Unit::Flags accessType, std::string name, std::string returnType, Unit::Flags flags);
    void Compile();
};

#endif // CODEGENERATOR_H
