#include "menuPresent.h"
#include <fstream>
#include <iostream>
#include <limits> // Used in numeric_limits<streamsize>::max()

using namespace std;

int displays(vector<string> &displays, string explorer, string &agencyName)
{
    int option;

    cout << string(100, '\n');
    explorer = agencyName + " | " + explorer;
    cout << explorer << endl << endl << endl;
    for (size_t i = 0; i < displays.size(); i++)
        cout << "\t" << displays.at(i) << endl;
    cout << endl << endl;
    cout << "Option: "; cin >> option;
    while (cin.fail() || !(option >= 0 && option <= (displays.size() - 1)))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr << "Invalid Option! Please enter a valid number." << endl << endl;
        cout << "Option: "; cin >> option;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return option;
}

void mainMenu(NationalTeam nTeam) {


    int option, mainMenu, option1, option2;
    string nTeamName = nTeam.getName();

    cout << string(100, '\n');
    vector<string> mainChoices = { "1. Display National Team Info", "2. Update National Team Info", "3. Manage", "4. To be Implemented...", "5. To be Implemented...", "6. To be Implemented...", "7. To be Implemented...", "8. To be Implemented...", "9. To be Implemented...","10. To be Implemented...","11. To be Implemented...","0. Exit" };
    vector<string> manageChoices = { "1. Create", "2. Alter", "3. Remove", "0. Main Menu" };
    vector<string> manageSecundaryChoices = { "1. OtherWorker", "2. Etc..", "0. Previous Menu" };
    vector<string> viewAvailablePackChoices = { "1. All", "2. Acording to Destination", "3. Between 2 Dates", "4. Acording to Destination and 2 Dates", "0. Main Menu" };
    vector<string> viewSoldPackChoices = { "1. Acording to a Specific Client", "2. Acording to All Clients", "0. Main Menu" };
    vector<string> viewRecommendedChoices = { "1. For a Specific Client", "2. For All Clients", "0. Main Menu" };

    do
    {

        cout << string(100, '\n'); cout << nTeamName << endl << endl << endl;

        for (size_t i = 0; i < mainChoices.size(); i++)
            cout << "\t" << mainChoices.at(i) << endl;

        cout << endl << endl << "Option: ";
        cin >> mainMenu;

        while (cin.fail() || !(mainMenu >= 0 && mainMenu <= (mainChoices.size() - 1)))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "Invalid Option! Please enter a valid number." << endl << endl;
            cout << "Option: "; cin >> mainMenu;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clean NL line feed

        switch (mainMenu)
        {
            case 1:
                /* To be implemented... */
                cout << endl << nTeamName;
                cout << "Press any key to continue...";
                cin.get();
                break;
            case 2:
                nTeamName = nTeam.setName(mainChoices.at(mainMenu - 1));
                cout << "Press any key to continue...";
                cin.get();
                break;
            case 3:
                while (true)
                {
                    option1 = displays(manageChoices, mainChoices.at(mainMenu - 1), nTeamName);
                    if (option1 != 0)
                        option2 = displays(manageSecundaryChoices, mainChoices.at(mainMenu - 1) + " | " + manageChoices.at(option1 - 1), nTeamName);
                    else
                        break;
                    if (option2 != 0)
                    {
                        // 3rd menu functions
                        switch (option1)
                        {
                            case 1:
                                switch (option2)
                                {
                                    case 1:
                                    {
                                        // Create | OtherWorker
                                        string auxiliarExplorer = mainChoices.at(mainMenu - 1) + " | " + manageChoices.at(option1 - 1) + " | " + manageSecundaryChoices.at(option2 - 1);
                                        nTeam.CreateOtherWorker();
                                        cout << "Press any key to continue...";
                                        cin.get();
                                        break;
                                    }
                                    case 2:
                                    {
                                        // Create | Packs
                                        string auxiliarExplorer = mainChoices.at(mainMenu - 1) + " | " + manageChoices.at(option1 - 1) + " | " + manageSecundaryChoices.at(option2 - 1);

                                        cout << "Press any key to continue...";
                                        cin.get();
                                        break;
                                    }
                                }
                                break;
                            case 2:
                                switch (option2)
                                {
                                    case 1:
                                    {
                                        // Alter | Client
                                        string auxiliarExplorer = mainChoices.at(mainMenu - 1) + " | " + manageChoices.at(option1 - 1) + " | " + manageSecundaryChoices.at(option2 - 1);

                                        cout << "Press any key to continue...";
                                        cin.get();
                                        break;
                                    }
                                    case 2:
                                    {
                                        // Alter | Pack
                                        string auxiliarExplorer = mainChoices.at(mainMenu - 1) + " | " + manageChoices.at(option1 - 1) + " | " + manageSecundaryChoices.at(option2 - 1);

                                        cout << "Press any key to continue...";
                                        cin.get();
                                        break;
                                    }
                                    default:
                                        break;
                                }
                                break;
                            case 3:
                                switch (option2)
                                {
                                    case 1:
                                    {
                                        // Remove | Client
                                        string auxiliarExplorer = mainChoices.at(mainMenu - 1) + " | " + manageChoices.at(option1 - 1) + " | " + manageSecundaryChoices.at(option2 - 1);

                                        cout << "Press any key to continue...";
                                        cin.get();
                                        break;
                                    }
                                    case 2:
                                    {
                                        // Remove | Pack
                                        string auxiliarExplorer = mainChoices.at(mainMenu - 1) + " | " + manageChoices.at(option1 - 1) + " | " + manageSecundaryChoices.at(option2 - 1);

                                        cout << "Press any key to continue...";
                                        cin.get();
                                        break;
                                    }
                                    default:
                                        break;
                                }
                                break;
                            default:
                                break;
                        }
                        break;
                    }
                }
                break;
            case 4:
            {
                // Option 4.
                string auxiliarExplorer = mainChoices.at(mainMenu - 1);
                cout << "Press any key to continue...";
                cin.get();
                break;
            }
            case 5:
            {
                // Option 5.
                string auxiliarExplorer = mainChoices.at(mainMenu - 1);


                cout << "Press any key to continue...";
                cin.get();
                break;
            }
            case 6:
            {
                // Option 6.
                cout << "Press any key to continue...";
                cin.get();
                //option = displays(viewAvailablePackChoices, mainChoices.at(mainMenu - 1), nTeamName);
                switch (option)
                {
                    case 1:
                    {
                        // Option 6.1
                        string auxiliarExplorer = mainChoices.at(mainMenu - 1) + " | " + viewAvailablePackChoices.at(option - 1);

                        cout << "Press any key to continue...";
                        cin.get();
                        break;
                    }
                    case 2:
                    {
                        // Option 6.2
                        string auxiliarExplorer = mainChoices.at(mainMenu - 1) + " | " + viewAvailablePackChoices.at(option - 1);

                        cout << "Press any key to continue...";
                        cin.get();
                        break;
                    }
                    case 3:
                    {
                        // Option 6.3
                        string auxiliarExplorer = mainChoices.at(mainMenu - 1) + " | " + viewAvailablePackChoices.at(option - 1);

                        cout << "Press any key to continue...";
                        cin.get();
                        break;
                    }
                    case 4:
                    {
                        // Option 6.4
                        string auxiliarExplorer = mainChoices.at(mainMenu - 1) + " | " + viewAvailablePackChoices.at(option - 1);

                        cout << "Press any key to continue...";
                        cin.get();
                        break;
                    }
                    default:
                        break;
                }
                break;
            }
            case 7:
                // Option 7.
                // option = displays(viewSoldPackChoices, mainChoices.at(mainMenu - 1), nTeamName);
                switch (option)
                {
                    case 1:
                    {
                        // Option 7.1
                        string auxiliarExplorer = mainChoices.at(mainMenu - 1) + " | " + viewSoldPackChoices.at(option - 1);

                        cout << "Press any key to continue...";
                        cin.get();
                        break;
                    }
                    case 2:
                    {
                        /// Option 7.2
                        string auxiliarExplorer = mainChoices.at(mainMenu - 1) + " | " + viewSoldPackChoices.at(option - 1);

                        cout << "Press any key to continue...";
                        cin.get();
                        break;
                    }
                    default:
                        break;
                }
                break;
            case 8:
            {
                // Option 8.
                string auxiliarExplorer = mainChoices.at(mainMenu - 1);

                cout << "Press any key to continue...";
                cin.get();
                break;
            }
            case 9:
            {
                // Option 9.
                string auxiliarExplorer = mainChoices.at(mainMenu - 1);

                cout << "Press any key to continue...";
                cin.get();
                break;
            }
            case 10:
            {
                // Option 10.
                string auxiliarExplorer = mainChoices.at(mainMenu - 1);
                cout << "Press any key to continue...";
                cin.get();
                break;
            }
            case 11:
            {
                // Option 11.
                // option = displays(viewRecommendedChoices, mainChoices.at(mainMenu - 1), agencyName);
                switch (option)
                {
                    case 1:
                    {
                        // Option 11.1
                        string auxiliarExplorer = mainChoices.at(mainMenu - 1);

                        cout << "Press any key to continue...";
                        cin.get();
                        break;
                    }
                    case 2:
                    {
                        // Option 11.2
                        string auxiliarExplorer = mainChoices.at(mainMenu - 1);

                        cout << "Press any key to continue...";
                        cin.get();
                        break;
                    }
                    default:
                        break;
                }
                break;
            }
            default:
                break;
        }
    } while (mainMenu != 0);
}