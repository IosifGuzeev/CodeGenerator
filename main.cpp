#include <QCoreApplication>
#include <CodeGenerator.h>
#include <Utilities/writers.h>

int main(int argc, char *argv[])
{

    char count = '    ';
    char symbol = 'a';
    auto result = std::string(count, symbol);

    auto generator = CodeGenerator(CodeGenerator::Languages::java, new ConsoleWriter());
    generator.AddClassUnit("A", 2);
    generator.AddMethodUnit("A", 1, "A1", "int", 0);
    generator.AddClassUnit("B", 2);
    generator.AddMethodUnit("B", 1, "B1", "void", 1);
    generator.AddMethodUnit("A", 2, "A2", "double", 2);
    generator.AddMethodUnit("B", 0, "B2", "float", 3);
    generator.Compile();
}
