#include <iostream>

#include "sortmanager.h"
#include "commandlinearg.h"
using namespace std;

int main(int argc, char* argv[])
{
    SortManager manager;
    manager.setSourceData(new CommandLineArg(argc, argv));




    return 0;
}
