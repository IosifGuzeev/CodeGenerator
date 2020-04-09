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
    std::cout << "class " << name << std::endl;
    std::cout << "{\n";
    for (auto &unitsVec: subUnits)
    {
        std::cout << unitsVec.first << std::endl;
        for(auto &e: unitsVec.second)
        {
            std::cout << e->Compile(level + 1) << std::endl;
        }
    }
    std::cout << "};\n";
}
