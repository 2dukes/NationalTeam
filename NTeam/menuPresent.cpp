#include "menuPresent.h"
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

void mainMenu(NationalTeam &nTeam) {


    int option, mainMenu, option1, option2;
    string nTeamName = nTeam.getName();

    cout << string(100, '\n');
    vector<string> mainChoices = { "1. Display", "2. Manage", "3. Calls in which a player participated", "4. Games in a call in which a player participated", "5. Show Call Stats", "6. Statistics", "7. Costs", "8. Victories, Draws and Loses", "9. Top Scorer", "10. Coaches", "11. Old Staff","0. Exit" };
    vector<string> manageChoices = { "1. Create", "2. Alter", "3. Remove", "0. Main Menu" };
    vector<string> manageSecundaryChoices = { "1. Other Worker", "2. Soccer Player", "3. Call", "4. Technical Team Member", "0. Previous Menu" };
    vector<string> viewAvailablePackChoices = { "1. Other Workers", "2. Technical Team", "3. Soccer Players", "4. Games", "5. Summons\' Games", "6. Summons\' Players", "0. Main Menu" };
    vector<string> viewSoldPackChoices = { "1. In a Given Month", "2. Total", "0. Main Menu" };
    vector<string> viewRecommendedChoices = { "1. For a Specific Player", "2. For All The Players", "3. For the National Team", "0. Main Menu" };
    vector<string> statisticsChoices = {"1. Show Call Statistics of the Team", "2. Show Global Statistics of the Team", "3. Show Call Statistics of a Player", "4. Show Global Statistics of a Player", "0. Main Menu"};
    vector<string> coachChoices = { "1. Create Coach", "2. Alter Coach", "3. Remove Coach", "4. Displays", "0. Main Menu" };
    vector<string> displayCoaches = {"1. Coaches ordered By Number of Cups Won", "2. Coaches that Trained the National Team", "0. Back"};
    vector<string> oldStaffChoices = { "1. Display all old staff", "2. Display specific old staff", "3. Hire old staff", "0. Main Menu" };
    do
    {

        cout << string(100, '\n'); cout << "====== " << nTeamName << " ======" << endl << endl << endl;

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
                // Option 1.
                option = displays(viewAvailablePackChoices, mainChoices.at(mainMenu - 1), nTeamName);
                switch (option)
                {
                    case 1:
                    {
                        // Display | Other Workers
                        nTeam.displayOtherWorkers();
                        cout << endl << endl << "Press any Enter to continue...";
                        cin.get();
                        break;
                    }
                    case 2:
                    {
                        /// Display | Technical Team

                        nTeam.displayTechnicalTeamMembers();
                        cout << endl << endl << "Press any key to continue...";
                        cin.get();
                        break;
                    }
                    case 3:
                    {
                        /// Display | Soccer Players
                        nTeam.displaySoccerPlayers();
                        cout << endl << endl << "Press any key to continue...";
                        cin.get();
                        break;
                    }
                    case 4:
                    {
                        /// Display | Games
                        nTeam.displayGames();
                        cout << endl << endl << "Press any key to continue...";
                        cin.get();
                        break;
                    }
                    case 5:
                    {
                        /// Display | Call Games
                        nTeam.displayCallsGames();
                        cout << endl << endl << "Press any key to continue...";
                        cin.get();
                        break;
                    }
                    case 6:
                    {
                        /// Display | Call Players
                        nTeam.displayCallsPlayers();
                        cout << endl << endl << "Press any key to continue...";
                        cin.get();
                        break;
                    }
                    default:
                        break;
                }
                break;
            case 2:
                while (true)
                {
                    option1 = displays(manageChoices, mainChoices.at(mainMenu - 1), nTeamName);
                    if (option1 != 0)
                        option2 = displays(manageSecundaryChoices, mainChoices.at(mainMenu - 1) + " | " + manageChoices.at(option1 - 1), nTeamName);
                    else
                        break;
                    if (option2 != 0)
                    {
                        cout << endl;
                        // 3rd menu functions
                        switch (option1)
                        {
                            case 1:
                                switch (option2)
                                {
                                    case 1:
                                    {
                                        // Create | OtherWorker

                                        nTeam.createOtherWorker();
                                        cout << endl << endl << "Press any key to continue...";
                                        cin.get();
                                        break;
                                    }
                                    case 2:
                                    {
                                        // Create | SoccerPlayer

                                        nTeam.createSoccerPlayer();
                                        cout << endl << endl << "Press any key to continue...";
                                        cin.get();
                                        break;
                                    }
                                    case 3:
                                    {
                                        // Create | Call

                                        nTeam.createCall();
                                        cout << endl << endl << "Press any key to continue...";
                                        cin.get();
                                        break;
                                    }
                                    case 4:
                                    {
                                        // Create | Technical Team Member

                                        nTeam.createTechnicalTeamMember();
                                        cout << endl << endl << "Press any key to continue...";
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
                                        // Alter | OtherWorker

                                        nTeam.alterOtherWorker();
                                        cout << endl << endl << "Press any key to continue...";
                                        cin.get();
                                        break;
                                    }
                                    case 2:
                                    {
                                        // Alter | SoccerPlayer

                                        nTeam.alterSoccerPlayer();
                                        cout << endl << endl << "Press any key to continue...";
                                        cin.get();
                                        break;
                                    }
                                    case 3:
                                    {
                                        // Alter | Call

                                        nTeam.alterCall();
                                        cout << endl << endl << "Press any key to continue...";
                                        cin.get();
                                        break;
                                    }
                                    case 4:
                                    {
                                        // Alter | Technical Team Member

                                        nTeam.alterTechnicalTeamMember();
                                        cout << endl << endl << "Press any key to continue...";
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
                                        // Remove | OtherWorker

                                        nTeam.deleteOtherWorker();
                                        cout << endl << endl << "Press any key to continue...";
                                        cin.get();
                                        break;
                                    }
                                    case 2:
                                    {
                                        // Remove | SoccerPlayer

                                        nTeam.deleteSoccerPlayer();
                                        cout << endl << endl << "Press any key to continue...";
                                        cin.get();
                                        break;
                                    }
                                    case 3:
                                    {
                                        // Remove | Call

                                        nTeam.removeCall();
                                        cout << endl << endl << "Press any key to continue...";
                                        cin.get();
                                        break;
                                    }
                                    case 4:
                                    {
                                        // Remove | Technical Team Member

                                        nTeam.deleteTechnicalTeamMember();
                                        cout << endl << endl << "Press any key to continue...";
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
            case 3:
            {
                // Option 3.

                nTeam.playerCallsForMenu();

                cout << "Press any key to continue...";
                cin.get();
                break;
            }
            case 4:
            {
                // Option 4.

                nTeam.playerGamesForMenu();

                cout << "Press any key to continue...";
                cin.get();
                break;
            }
            case 5:
            {
                // Option 5.

                nTeam.showCallStats();

                cout << "Press any key to continue...";
                cin.get();
                break;

            }
            case 6:
            {
                option1 = displays(statisticsChoices, mainChoices.at(mainMenu - 1), nTeamName);
                switch (option1)
                {
                    case 1:
                    {
                        nTeam.showCallStats();
                        cout << endl << endl << "Press any Enter to continue...";
                        cin.get();
                        break;
                    }
                    case 2:
                    {

                        nTeam.showGlobalStats();
                        cout << endl << endl << "Press any key to continue...";
                        cin.get();
                        break;
                    }
                    case 3:
                    {

                        nTeam.showPlayerCallStats();
                        cout << endl << endl << "Press any key to continue...";
                        cin.get();
                        break;
                    }
                    case 4:  // ESTA OPÇÃO NÃO ESTÁ A FUNCIONAR E NÃO SEI PORQUÊ!!
                    {

                        nTeam.showPlayerGlobalStats();
                        cout << endl << endl << "Press any key to continue...";
                        cin.get();
                        break;
                    }

                    default:
                        break;
                }
                break;

            }
            case 7:
            {
                while (true)
                {
                    option1 = displays(viewSoldPackChoices, mainChoices.at(mainMenu - 1), nTeamName);
                    if (option1 != 0)
                        option2 = displays(viewRecommendedChoices, mainChoices.at(mainMenu - 1) + " | " + viewSoldPackChoices.at(option1 - 1), nTeamName);
                    else
                        break;
                    if (option2 != 0)
                    {
                        cout << endl;
                        // 3rd menu functions
                        switch (option1)
                        {
                            case 1:
                                switch (option2)
                                {
                                    case 1:
                                    {
                                        // Per Month | Specific Player

                                        nTeam.getMonthlyPlayerTotalCost();
                                        cout << endl << endl << "Press any key to continue...";
                                        cin.get();
                                        break;
                                    }
                                    case 2:
                                    {
                                        // Per Month | All Players

                                        nTeam.getMonthlyTeamTotalCost();
                                        cout << endl << endl << "Press any key to continue...";
                                        cin.get();
                                        break;
                                    }
                                    case 3:
                                    {
                                        // Per Month | Entire National Team

                                        nTeam.getMonthlyNationalTeamTotalCost();
                                        cout << endl << endl << "Press any key to continue...";
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
                                        // Total | Specific Player

                                        nTeam.getPlayerTotalCost();
                                        cout << endl << endl << "Press any key to continue...";
                                        cin.get();
                                        break;
                                    }
                                    case 2:
                                    {
                                        // Total | All Players

                                        cout << endl << "Global Costs of the Entire Team Was " << nTeam.getTeamTotalCost() << " euros" << endl;
                                        cout << endl << endl << "Press any key to continue...";
                                        cin.get();
                                        break;
                                    }
                                    case 3:
                                    {
                                        // Total | Entire National Team

                                        nTeam.getNationalTeamTotalCost();
                                        cout << endl << endl << "Press any key to continue...";
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
            }
            case 8:
            {
                // Option 8.

                nTeam.showNumberOfVictoriesDrawsLoses();

                cout << "Press any key to continue...";
                cin.get();
                break;

            }
            case 9:
            {
                // Option 8.

                nTeam.topScorer();

                cout << "Press any key to continue...";
                cin.get();
                break;

            }
            case 10:
            {
                    while(true)
                    {
                        option1 = displays(coachChoices, mainChoices.at(mainMenu - 1), nTeamName);
                        switch (option1)
                        {
                            case 1: // Create Coach
                            {
                                nTeam.addCoach();
                                cout << endl << endl << "Press any Enter to continue...";
                                cin.get();
                                break;
                            }
                            case 2: // Alter Coach
                            {
                                nTeam.alterCoach();
                                cout << endl << endl << "Press any key to continue...";
                                cin.get();
                                break;
                            }
                            case 3: // Remove Coach
                            {
                                nTeam.deleteCoach();
                                cout << endl << endl << "Press any key to continue...";
                                cin.get();
                                break;
                            }
                            case 4:  // Display
                            {
                                option2 = displays(displayCoaches, mainChoices.at(mainMenu - 1), nTeamName);
                                switch (option2) {
                                    case 1:
                                        {
                                        nTeam.displayCoachesByCupsWon();
                                        cout << endl << endl << "Press any key to continue...";
                                        cin.get();
                                        break;
                                    }
                                    case 2:
                                    {
                                        nTeam.displayCoachesThatTrainedNTeam();
                                        cout << endl << endl << "Press any key to continue...";
                                        cin.get();
                                        break;
                                    }
                                    case 0: {
                                        break;
                                    }
                                }
                                break;
                            }

                            default:
                                break;
                        }
                        if(option1 == 0)
                            break;
                    }
            }
            case 11:
            {
                while(true)
                {
                    option1 = displays(oldStaffChoices, mainChoices.at(mainMenu - 1), nTeamName);
                    switch (option1)
                    {
                        case 1: // Display all old staff
                        {
                            nTeam.displayOldStaff();
                            cout << endl << endl << "Press any Enter to continue...";
                            cin.get();
                            break;
                        }
                        case 2: // Display specific old staff
                        {
                            nTeam.searchOldStaff();
                            cout << endl << endl << "Press any key to continue...";
                            cin.get();
                            break;
                        }
                        case 3: // Hire old staff
                        {
                            nTeam.hireOldStaff();
                            cout << endl << endl << "Press any key to continue...";
                            cin.get();
                            break;
                        }
                        default:
                            break;
                    }
                    if(option1 == 0)
                        break;
                }
            }
            default:
                break;
        }
    } while (mainMenu != 0);
}