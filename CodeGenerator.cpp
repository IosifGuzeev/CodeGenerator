#include "CodeGenerator.h"

CodeGenerator::CodeGenerator(Languages langauge, Writer *_writer)
{
    switch (langauge) {
    case CodeGenerator::cpp:
    {
        factory = new CppFactory();
        break;
    }
    case CodeGenerator::java:
    {
        factory = new JavaFactory();
    }
    default:
    {
        std::runtime_error("Wrong language id!");
        break;
    }
    };
    this->writer = _writer;
}

CodeGenerator::~CodeGenerator()
{
    delete factory;
}

void CodeGenerator::AddClassUnit(std::string name, unsigned int flags)
{
    classes[name] = factory->GetClassUnit(name, flags);
}

void CodeGenerator::AddMethodUnit(std::string className, Unit::Flags accessType, std::string name, std::string returnType, Unit::Flags flags)
{
    if(classes.find(className) == classes.end())
        std::runtime_error("Class not found!");
    else
        classes[className]->addSubUnit(std::shared_ptr<Unit>(new CppMethodUnit(name, returnType, flags)), accessType);
}

void CodeGenerator::Compile()
{
    for(auto& e: classes)
        writer->write(e.second->Compile(0));
}
