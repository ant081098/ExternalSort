#include <iostream>

#include "sortmanager.h"
#include "commandlinearg.h"
#include "externalsort.h"
#include "pfile/exceptfile.h"

using namespace std;

int main(int argc, char* argv[])
{
    SortManager manager;
    if(manager.setOptions(new CommandLineArg(argc, argv))){
        try{
            manager.sort(new ExternalSort());
        }
        catch(ExceptFile& except){
            cout << "[-] " << except.step() << ":" << except.message() << endl;
        }
    } else{
        cout<<"Invalid arguments\nsorting -i <input> -o <output> [-d <parts>]\n" << endl;
    }

    return 0;
}
