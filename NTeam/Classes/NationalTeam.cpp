//
// Created by Rui Pinto on 10/11/2019.
//

#include "NationalTeam.h"
#include <iostream>
#include <new>

using namespace std;

bool NationalTeam::CreateOtherWorker()
{
    string auxName;
    cout << "Name: ";
    getline(cin, auxName);

    string auxBirth;
    cout << "Birth Date (YYYY/MM/DD): ";
    getline(cin, auxBirth);
    Date birth(auxBirth);

    string auxRole;
    cout << " Role: ";
    getline(cin, auxRole);

    int auxSalary;
    cout << "Salary: ";
    cin >> auxSalary;
    cin.ignore(1000, '\n');

    unsigned int id;
    if(workers.size() > 0)
        id = workers.at(workers.size() - 1)->getId() + 1; // We suppose all Ids are incremented by 1
    else
        id = 1;

    cout << endl << "Are you sure you want to insert the following data? (Y|N)" << endl << endl;
    OtherWorker *oW = new OtherWorker(id, auxRole, auxName, birth, auxSalary);
    oW->info(cout);
    string answer;
    do
    {
        getline(cin, answer);
    } while(answer != "Y" && answer != "y" && answer != "N" && answer != "n");

    if(answer == "Y" || answer == "y")
    {
        workers.push_back(oW);
        cout << "Data successfully inserted!" << endl;
        return true;
        /* In the future to save all info inside a file */
        //  ofstream out_stream("../Files/OtherWorkers.txt", ios::app);
        //  oW.info(out_stream);
    }
    cout << "Data not inserted." << endl;
    delete oW;
    return false;

    // NATIONALTEAM DESTRUCTOR SHOULD DESTRUCT ALL VECTORS BECAUSE THEY'RE ALLOCATED DYNAMICALLY
}