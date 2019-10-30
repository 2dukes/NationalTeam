//
// Created by Rui Pinto on 10/11/2019.
//

#include "NationalTeam.h"
#include <iostream>
#include <new>
#include <limits>
#include <fstream>
#include <string>
#include <sstream>
#include "../NecessaryFunctions_NameSpaces.h"

using namespace std;

/* Gets */

string NationalTeam::getName() const
{
    return name;
}

/* Sets */

string NationalTeam::setName(string name)
{
    this->name = name;
    return name;
}

/* Other Methods */

bool NationalTeam::CreateOtherWorker()
{
    string auxName;
    do
    {
        cout << "Name: ";
        getline(cin, auxName);
    } while(verifyInputs::verifyString(auxName));


    string auxBirth;
    do
    {
        cout << "Birth Date (YYYY/MM/DD): ";
        getline(cin, auxBirth);

    } while(verifyInputs::verifyDate(auxBirth));
    Date birth = Date(auxBirth);

    string auxRole;
    do
    {
        cout << " Role: ";
        getline(cin, auxRole);
    } while(verifyInputs::verifyString(auxRole));

    float auxSalary;
    do {
        cout << "Salary: ";
        cin >> auxSalary;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while(verifyInputs::verifyNumber());

    unsigned int id;
    if(workers.size() > 0)
        id = workers.at(workers.size() - 1)->getId() + 1; // We suppose all Ids are incremented by 1
    else
        id = 1;

    cout << endl << "Are you sure you want to insert the following data? (Y|N)" << endl << endl;
    Staff *oW = new OtherWorker(id, auxRole, auxName, birth, auxSalary);
    oW->info(cout);
    string answer;
    do
    {
        getline(cin, answer);
    } while(answer != "Y" && answer != "y" && answer != "N" && answer != "n");

    if(answer == "Y" || answer == "y")
    {
        addWorker(oW);
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

bool AlterOtherWorker()
{
    return true;
    string reader;
    bool flag = true, toggle = true;
    int repetition = 0, option;

//    cout << string(100, '\n');
//    cout << explorer << endl << endl;
//    cin.ignore(numeric_limits<streamsize>::max(), '\n');

//    WorkerLookUp()
    while(flag)
    {
        cout << "Look for a \'Worker\' using: " << endl; cout << "1. Name\n2. Role\n3. Birth Date\n4. Salary\n0. Back\n\n";
        cin >> option; cin.ignore(numeric_limits<streamsize>::max(), '\n'); cout << endl;
        switch(option)
        {
            case 0:
                return false;
            case 1:
                cout << "Name: ";
                getline(cin, reader);
                while (reader.empty() || cin.eof())
                {
                    cerr << "Invalid Option! Please enter a valid input." << endl;
                    cout << endl << "Name: "; getline(cin, reader);
                }

        }
        flag = false;
    }

//    while (toggle)
//    {
//        if (repetition == 0)
//        {
//            cout << endl << "What do you want to change?\n";
//            repetition++;
//        }
//        else
//            cout << "Do you want to change anything else?\n";
//        cout << "1. Name\n2. Role\n3. Birth Date\n4. Salary\n0. Back\n\n";
//        cin >> option; cin.ignore(numeric_limits<streamsize>::max(), '\n');
//        cout << endl;
//
//        switch (option)
//        {
//            case 0:
//            {
//                toggle = false;
//                break;
//            }
//            case 1:
//            {
//                cout << "New Name: "; getline(cin, reader);
//                while (reader.empty() || cin.eof())
//                {
//                    cerr << "Invalid Option! Please enter a valid input." << endl;
//                    cout << endl << "New Name: "; getline(cin, reader);
//                }
//                break;
//            }
//            case 2:
//            {
//                do
//                {
//                    cout << "VAT Number: "; cin >> VAT;
//                    if (cin.eof())
//                        return name;
//                    if (cin.fail())
//                    {
//                        cin.clear();
//                        cerr << "Invalid Option! Please enter a 9 digit VAT." << endl << endl;
//                    }
//                    else
//                    {
//                        flag = VATConfirm(VAT);
//                        if (flag)
//                            cerr << "Invalid Option! Please enter a 9 digit VAT." << endl << endl;
//                        else if (VAT <= 0)
//                            cerr << "Invalid input! Please consider changing your number." << endl;
//                    }
//                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                } while (flag || (VAT <= 0));
//                setVATnumber(VAT);
//                break;
//            }
//            case 3:
//            {
//                cout << "URL: "; getline(cin, reader);
//                while (reader.empty() && !cin.eof())
//                {
//                    cerr << "Invalid Option! Please enter a valid input." << endl;
//                    cout << endl << "URL: "; getline(cin, reader);
//                }
//                if (cin.eof())
//                    return name;
//                trim(reader);
//                setURL(reader);
//                break;
//            }
//            case 4:
//            {
//                cout << "Address (Street / Door Number / Floor / Zip Code / Location): "; getline(cin, reader);
//                while ((reader.empty() || adrConfirm(reader)) && !cin.eof())
//                {
//                    cerr << "Invalid Option! Please enter a valid input." << endl;
//                    cout << endl << "Address (Street / Door Number / Floor / Zip Code / Location): "; getline(cin, reader);
//                }
//                if (cin.eof())
//                    return name;
//                trim(reader);
//                Address NewAdress(reader);
//                setAddress(NewAdress);
//                break;
//            }
//        }
//        if (toggle)
//        {
//            cout << endl << "Agency successfully altered!" << endl << endl;
//            // OtherWorkerInfoHasChanged = true;
//        }
//    }
}

void NationalTeam::addWorker(Staff *oW)
{
    workers.push_back(oW);
}



bool NationalTeam::readOtherWorkersFile(string filename) {
    ifstream f;
    f.open(filename);
    unsigned int id;
    string name, aux;
    char delim = ' ';
    Date birthday;
    string function;
    unsigned long salary;
    if (f.is_open()) {
        while(!f.eof()) {
            getline(f, aux, delim);
            f >> id;
            f.clear();
            f.ignore(1000, '\n');
            getline(f, aux, delim);
            getline(f, name);
            getline(f, aux, delim);
            getline(f, aux, delim);
            f >> birthday;
            getline(f, aux, delim);
            getline(f, function);
            getline(f, aux, delim);
            f >> salary;
            f.clear();
            f.ignore(1000, '\n');
            getline(f, aux); // linha em branco

            Staff* staff = new OtherWorker(id, function, name, birthday, salary);
            addWorker(staff);

        }
        f.close();
        return true;
    }
    else {
        cerr << "Error reading the file " << filename << endl;
        return false;
    }
}

bool NationalTeam::deleteWorker() {
    Staff *oW;
    for (auto it = workers.begin(); it != workers.end(); it++) {
        if ((*it)->getId() == oW->getId()) {
            workers.erase(it);
            return true;
        }
    }
    return false;
}
