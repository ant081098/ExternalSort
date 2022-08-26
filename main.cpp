#include <iostream>

#include "sortmanager.h"
#include "commandlinearg.h"
#include "externalsort.h"
#include "pfile/exceptfile.h"
#include <chrono>

using namespace std;

int main(int argc, char* argv[])
{
    SortManager manager;
    if(manager.setOptions(new CommandLineArg(argc, argv))){
        try{
            auto startTime = chrono::steady_clock::now();

            manager.sort(new ExternalSort());   //Sorting

            auto finishTime = chrono::duration_cast<chrono::seconds>
                    (chrono::steady_clock::now() - startTime);
            cout << "Time: " << finishTime.count() << "sec\n";
        }
        catch(ExceptFile& except){
            cout << "[-] " << except.step() << ":" << except.message() << endl;
        }
    } else{
        cout<<"Invalid arguments\nsorting -i <input> -o <output> [-d <parts>]\n" << endl;
    }

    return 0;
}
