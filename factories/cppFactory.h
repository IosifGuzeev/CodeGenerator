#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H
#include <interfaces.h>
#include <memory>
#include <string>
#include <vector>
#include <map>
#include <iostream>

class CppFactory : public AbstractFactory
{
public:
    std::shared_ptr<ClassUnit> GetClassUnit(std::string name, unsigned int flags = 0) override;
    std::shared_ptr<MethodUnit> GetMethodUnit(std::string name, std::string returnType, unsigned int flags) override;
};

class CppClassUnit : public ClassUnit
{
    using UnitVector = std::vector<std::shared_ptr<Unit>>;

    std::string name;
    std::map<std::string, UnitVector> subUnits;

public:

    enum AccessType{
        PUBLIC = 0,
        PRIVATE = 1,
        PROTECTED = 2,
    };

    CppClassUnit(std::string name);
    void addSubUnit(const std::shared_ptr<Unit>& subUnit, Flags accessType) override;
    std::string Compile(unsigned int level = 0) override;
};

class CppMethodUnit : public MethodUnit
{
    using UnitVector = std::vector<std::shared_ptr<Unit>>;

    std::string name;
    std::string resultType;
    std::string modificator;
    std::map<std::string, UnitVector> subUnits;

public:

    CppMethodUnit(std::string name, std::string resultType, Flags flags = 0);
    void addSubUnit(const std::shared_ptr<Unit>& subUnit, Flags accessType) override;
    std::string Compile(unsigned int level = 0) override;
};


#endif // ABSTRACTFACTORY_H
