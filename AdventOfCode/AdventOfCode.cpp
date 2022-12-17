#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "AdventDay.h"

#include "CalorieCounting.h"            // pierwsze kolecje, maximum
#include "RockPaperScissors.h"          // podejmowanie decyzji 
#include "RucksackReorganization.h"     // duplikaty, części wspólne
#include "CampCleanup.h"                // zakresy wspólne zbiorów liczb
#include "SupplyStacks.h"               // stos
#include "TuningTrouble.h"              // kolejka
#include "NoSpaceLeftOnDevice.h"        // drzewo, wskaźniki, zaawansowne podejmowanie decyzji
#include "TreetopTreeHouse.h"           // tablice 2D
#include "RopeBridge.h"

using namespace std;

int main()
{
    ifstream file("input9.txt");
    if (file.is_open())
    {
        std::stringstream buffer;
        buffer << file.rdbuf();

        AdventDay* task = new RopeBridge();
        task->solve(buffer.str());
        cout << task->output1 << endl << task->output2 << endl;
        delete task;
    }
    return 0;
}
