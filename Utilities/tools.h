#ifndef TOOLS_H
#define TOOLS_H
#include <string>
#include <interfaces.h>
std::string AccessCodeToString(Unit::Flags accessType)
{
    std::string key;
    switch (accessType) {
    case 0:
    {
        key = "public";
        break;
    }
    case 1:
    {
        key = "private";
        break;
    }
    case 2:
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
    return key;
}



#endif // TOOLS_H
