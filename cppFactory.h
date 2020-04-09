#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H
#include <interfaces.h>
#include <memory>

class CppFactory : public AbstractFactory
{
    std::shared_ptr<ClassUnit> GetClassUnit(std::string name, unsigned int flags) override;
    std::shared_ptr<MethodUnit> GetMethodUnit(std::string name, std::string returnType, unsigned int flags) override;
};

#endif // ABSTRACTFACTORY_H
