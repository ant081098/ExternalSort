#include <iostream>

#include "sortmanager.h"
#include "commandlinearg.h"
#include "externalsort.h"
using namespace std;

int main(int argc, char* argv[])
{
    SortManager manager;
    if(manager.setOptions(new CommandLineArg(argc, argv))){
        manager.sort(new ExternalSort());
    } else{
        cout<<"Invalid arguments\nsorting -i <input> -o <output> [-d <parts>]\n" << endl;
    }

    return 0;
}
