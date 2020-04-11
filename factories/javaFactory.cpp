#include "javaFactory.h"
JavaClassUnit::JavaClassUnit(std::string name)
{
    this->name = name;
    subUnits["public"] = UnitVector();
    subUnits["private"] = UnitVector();
    subUnits["protected"] = UnitVector();
}

void JavaClassUnit::addSubUnit(const std::shared_ptr<Unit> &subUnit, Flags accessType)
{
    std::string key;
    switch (accessType) {
    case PUBLIC:
    {
        key = "public";
        break;
    }
    case PRIVATE:
    {
        key = "private";
        break;
    }
    case PROTECTED:
    {
        key = "protected";
        break;
    }
    default:
    {
        std::runtime_error("Wrong access type!");
        break;
    }
    }
    subUnits[key].push_back(subUnit);
}

std::string JavaClassUnit::Compile(unsigned int level)
{
    std::vector<std::string> result;
    result.push_back("public class " + name + "\n");
    result.push_back("{\n");
    for (auto &unitsVec: subUnits)
    {
        for(auto &e: unitsVec.second)
        {
            result.push_back(unitsVec.first + " " + e->Compile(level + 1) + "\n");
        }
    }
    result.push_back("}\n");
    std::string resultAsStr;
    for(auto& str: result)
        resultAsStr += std::string(level * 4, ' ') + str;
    return resultAsStr;
}

JavaMethodUnit::JavaMethodUnit(std::string name, std::string resultType, Flags flag)
{
    this->name = name;
    this->resultType = resultType;
    switch (flag) {
    case 0:
    {
        modificator = "";
        break;
    }
    case 1:
    {
        modificator = "static";
        break;
    }
    case 2:
    {
        modificator = "const";
        break;
    }
    case 3:
    {
        modificator = "virtual";
        break;
    }
    default:
    {
        std::runtime_error("flag not found!");
    }
    }
}

void JavaMethodUnit::addSubUnit(const std::shared_ptr<Unit> &subUnit, Unit::Flags accessType)
{
    std::runtime_error("This function not defined yet!");
}

std::string JavaMethodUnit::Compile(unsigned int level)
{
    std::vector<std::string> result;
    result.push_back(modificator + " " + resultType + " " + name + "()\n");
    result.push_back("{\n");
    for (auto &unitsVec: subUnits)
    {
        result.push_back(unitsVec.first + "\n");
        for(auto &e: unitsVec.second)
        {
            result.push_back(e->Compile(level + 1) + "\n");
        }
    }
    result.push_back("}\n");

    std::string resultAsStr;
    for(auto& str: result)
        resultAsStr += std::string(level * 4, ' ') + str;
    return resultAsStr;
}

std::shared_ptr<ClassUnit> JavaFactory::GetClassUnit(std::string name, unsigned int flags)
{
    return std::shared_ptr<JavaClassUnit>(new JavaClassUnit(name));
}

std::shared_ptr<MethodUnit> JavaFactory::GetMethodUnit(std::string name, std::string returnType, unsigned int flags)
{
    return std::shared_ptr<JavaMethodUnit>(new JavaMethodUnit(name, returnType));
}
