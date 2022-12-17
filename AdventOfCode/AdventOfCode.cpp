﻿#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "AdventDay.h"

#include "CalorieCounting.h"            // pierwsze kolecje, maximum
#include "RockPaperScissors.h"          // podejmowanie decyzji 
#include "RucksackReorganization.h"     // duplikaty i części wspólne w kolekcjach
#include "CampCleanup.h"                // zakresy wspólne zbiorów liczb
#include "SupplyStacks.h"               // stos
#include "TuningTrouble.h"              // kolejka
#include "NoSpaceLeftOnDevice.h"        // drzewo, wskaźniki, zaawansowne podejmowanie decyzji
#include "TreetopTreeHouse.h"           // tablice 2D
#include "RopeBridge.h"                 // pozycje w przestrzeni, symulacja fizyki
#include "CathodeRayTube.h"             // mapa, przeszukiwanie mapy, renderowanie grafiki
#include "MonkeyInTheMiddle.h"          // zarządzenie dużymi liczbami

using namespace std;

int main()
{
    ifstream file("input11.txt");
    if (file.is_open())
    {
        std::stringstream buffer;
        buffer << file.rdbuf();

        AdventDay* task = new MonkeyInTheMiddle();
        task->solve(buffer.str());
        cout << task->output1 << endl << task->output2 << endl;
        delete task;
    }
    return 0;
}
