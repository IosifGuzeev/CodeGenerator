#include "cppFactory.h"

CppClassUnit::CppClassUnit(std::string name)
{
    this->name = name;
    subUnits["public"] = UnitVector();
    subUnits["private"] = UnitVector();
    subUnits["protected"] = UnitVector();
}

void CppClassUnit::addSubUnit(const std::shared_ptr<Unit> &subUnit, Flags accessType)
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

std::string CppClassUnit::Compile(unsigned int level)
{
    std::vector<std::string> result;
    result.push_back("class " + name + "\n");
    result.push_back("{\n");
    for (auto &unitsVec: subUnits)
    {
        if(unitsVec.second.size() > 0)
        {
            result.push_back(unitsVec.first + ":\n");
            for(auto &e: unitsVec.second)
            {
                result.push_back(e->Compile(level + 1) + "\n");
            }
        }
    }
    result.push_back("};\n");
    std::string resultAsStr;
    for(auto& str: result)
        resultAsStr += std::string(level * 4, ' ') + str;
    return resultAsStr;
}

CppMethodUnit::CppMethodUnit(std::string name, std::string resultType, Flags flag)
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
        modificator = "static ";
        break;
    }
    case 2:
    {
        modificator = "const ";
        break;
    }
    case 3:
    {
        modificator = "virtual ";
        break;
    }
    default:
    {
        std::runtime_error("flag not found!");
    }
    }
}

void CppMethodUnit::addSubUnit(const std::shared_ptr<Unit> &subUnit, Unit::Flags accessType)
{
    std::runtime_error("This function not defined yet!");
}

std::string CppMethodUnit::Compile(unsigned int level)
{
    std::vector<std::string> result;
    result.push_back(modificator + resultType + " " + name + "()\n");
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

std::shared_ptr<ClassUnit> CppFactory::GetClassUnit(std::string name, unsigned int flags)
{
    return std::shared_ptr<CppClassUnit>(new CppClassUnit(name));
}

std::shared_ptr<MethodUnit> CppFactory::GetMethodUnit(std::string name, std::string returnType, unsigned int flags)
{
    return std::shared_ptr<CppMethodUnit>(new CppMethodUnit(name, returnType));
}
