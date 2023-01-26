#include <iostream>
#include "Logger.h"
using namespace std;

int main()
{

    Log l("Text.txt");

    l.logMessage(l.CRITICAL, "My test log");
    cout << "\033[1;31mbold red text\033[0m\n";

    cout << l.getWorkPath() << endl;
    return 0;

}
