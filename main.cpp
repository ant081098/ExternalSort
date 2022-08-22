#include <iostream>

#include "sortmanager.h"
#include "commandlinearg.h"
#include "externalsort.h"
using namespace std;

int main(int argc, char* argv[])
{
    SortManager manager;
    manager.setOptions(new CommandLineArg(argc, argv));
    manager.sort(new ExternalSort());


    return 0;
}
