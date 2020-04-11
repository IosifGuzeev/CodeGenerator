#include <QCoreApplication>
#include <CodeGenerator.h>
#include <Utilities/writers.h>

int main(int argc, char *argv[])
{
    auto generator = CodeGenerator(CodeGenerator::Languages::cpp, new FileWriter("C:\\test2\\test_output.txt"));
    generator.AddClassUnit("A", 2);
    generator.AddMethodUnit("A", 1, "foo", "void", 3);
    generator.Compile();
}
