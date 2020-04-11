#ifndef JAVAFACTORY_H
#define JAVAFACTORY_H
#include <interfaces.h>
#include <memory>
#include <string>
#include <vector>
#include <map>
#include <iostream>

class JavaFactory : public AbstractFactory
{
public:
    std::shared_ptr<ClassUnit> GetClassUnit(std::string name, unsigned int flags = 0) override;
    std::shared_ptr<MethodUnit> GetMethodUnit(std::string name, std::string returnType, unsigned int flags) override;
};

class JavaClassUnit : public ClassUnit
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

    JavaClassUnit(std::string name);
    void addSubUnit(const std::shared_ptr<Unit>& subUnit, Flags accessType) override;
    std::string Compile(unsigned int level = 0) override;
};

class JavaMethodUnit : public MethodUnit
{
    using UnitVector = std::vector<std::shared_ptr<Unit>>;

    std::string name;
    std::string resultType;
    std::string modificator;
    std::map<std::string, UnitVector> subUnits;

public:

    JavaMethodUnit(std::string name, std::string resultType, Flags flags = 0);
    void addSubUnit(const std::shared_ptr<Unit>& subUnit, Flags accessType) override;
    std::string Compile(unsigned int level = 0) override;
};

#endif // JAVAFACTORY_H
