//
//  main.cpp
//  projpartARevised
//
//  Created by Molly Kendrick on 10/16/18.
//  Copyright © 2018 Molly Kendrick. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>

using std::cout;            //declare for namespace
using std::cin;
using std::endl;
using std::setw;
using std::string;
using std::setfill;

class ComputerLabs
{
    int ID = -1;
    string fullName = " ";
    int time = 0;
public:
    ComputerLabs();            //constructor
    
    void setID(int num)        //getmethods setmethods
    { ID = num; }
    
    void setFullName(string str)
    { fullName = str; }
    
    void setTime(int num)
    { time = num; }
    
    int getID() const
    { return ID; }
    
    int getTime() const
    { return time; }
    
    string getFullName() const
    { return fullName; }
};

void displayUni();              //function prototypes
void IDgenerator(int &);
int getTime();
void displayMenu();
void getUserChoice(int &);
bool validateChoice(int);
void login(ComputerLabs *[]);
void logoff(ComputerLabs *[]);
void search(ComputerLabs *[]);
void displayLab(ComputerLabs *[]);


// Global Constants
const int NUMLABS = 8;            // Number of computer labs
const    int LABSIZES[NUMLABS] = {19, 15, 24, 33, 61, 17, 55, 37};         // Number of computers in each lab
const    std::string UNIVERSITYNAMES[NUMLABS] = {"The University of Michigan", "The University of Pittsburgh",
    "Stanford University", "Arizona State University", "North Texas State University", "The University of Alabama, Huntsville", "Princeton University", "Duquesne University"};                              // Names of university of each lab


int main()
{
    int choice = 0;
    bool loopFlag = true;
    
    srand(time(0));
    
    ComputerLabs *labValue[NUMLABS];
    for(int i = 0; i < NUMLABS; ++i)
    {
        labValue[i] = new ComputerLabs[LABSIZES[i]];
    }
    
    displayUni();
    
    if (choice == 5)
    {
        return 0;
    }
    
    do
    {
        displayMenu();
        do
        {
            getUserChoice(choice);
            loopFlag = validateChoice(choice);
        }while (loopFlag == true);
        
        if (choice == 1)
        {
            login(labValue);
        }
        else if (choice == 2)
        {
            logoff(labValue);
        }
        else if (choice == 3)
        {
            search(labValue);
        }
        else if (choice == 4)
        {
            displayLab(labValue);
        }
        
    }while(choice != 5);
    

}

//pre constructor function
//post initializes variables
ComputerLabs::ComputerLabs()
{
    ID = -1;
    fullName = " ";
    time = 0;
}

//pre
//post
void IDgenerator(int &userID)
{
    userID =(rand() % 10000) + 1;
    cout << std::setfill('0') << setw(5) << userID << std::setfill(' ') << endl;
    return;
}

//pre
//post
int getTime()
{
    int userMin = 0;
    
    cout << "Please enter the minutes you plan to use this work station (15/30/45/60): " << endl;
    cin >> userMin;
    if ((cin.fail()) && userMin != 15 && userMin != 30 && userMin != 45 && userMin != 60)     // time validation
    {
        cout << "That is not a valid time. Enter time (15/30/45/60): " << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<int>::max(),'\n');
        cin >> userMin;
    }
    return userMin;
}

//precondition start
//postcondition universities are displayed
void displayUni()
{
    cout << setw(47) << "Welcome - here is our list of available labs" << endl;
    for (int i = 0; i < NUMLABS; ++i)
    {
        cout << "Lab #" << i + 1 << " for " << UNIVERSITYNAMES[i] << endl;
    }
    return;
}

//precondition start
//postcondition menu is displayed
void displayMenu()
{
    cout << setw(15) << "----------------------------------------------------- " << endl;
    cout << setw(15) << "|             Molly Kendrick Incorporated           |" << endl;
    cout << setw(15) << "|                Computer Lab System                |" << endl;
    cout << setw(15) << "----------------------------------------------------- " << endl;
    cout << setw(15) << "|                     Main Menu                     |" << endl;
    cout << setw(15) << "|                1) Simulate login                  |" << endl;
    cout << setw(15) << "|                2) Simulate logoff                 |" << endl;
    cout << setw(15) << "|                3) Search                          |" << endl;
    cout << setw(15) << "|                4) Display a lab                   |" << endl;
    cout << setw(15) << "|                5) Quit                            |" << endl;
    cout << setw(15) << "|___________________________________________________|" << endl;
}

//pre
//post choice has value
void getUserChoice(int &choice)
{
    cout << "Your Choice: " ;
    cin >> choice;
}

//precondition choice is entered by user
//postcondition validates choice
bool validateChoice(int choice)
{
    bool goodOrNot = false;
    if ((cin.fail()) || ((choice < 1) || (choice > 5)))
    {
        cout << "The choice entered is invalid" << endl;
        goodOrNot = true;
    }
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return goodOrNot;
}

//pre needs user ID
//post puts user ID into array at lab and station
void login(ComputerLabs *labValue[])
{
    int lab = 0;
    int compNum = 0;
    int userID = 0;
    string name;
    
    IDgenerator(userID);
    
    cout << "Enter the lab number the user is logging in from (1-8): " ;
    cin >> lab;
    if ((cin.fail()) || lab > 8 || lab < 1)     // lab validation
    {
        cout << "That is not a lab we offer" << endl;
        cout << endl;
        cout << "Please pick a valid lab (1-8)" << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<int>::max(),'\n');
        cin >> lab;
    }
    
    cout << "Enter the computer station the user is logging in to (1-33): ";
    cin >> compNum;
    if ((cin.fail()) || compNum > 33 || compNum < 1)     // lab validation
    {
        cout << "That is not a station we offer" << endl;
        cout << endl;
        cout << "Please pick a valid station (1-33)" << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<int>::max(),'\n');
        cin >> compNum;
    }
    cin.ignore();
    cout << "Please enter the name of this user: " << endl;
    getline(cin,name);
    if (name.length() <= 0 || name.length() > 35)
    {
        cout << "That is not a valid full name" << endl;
        cout << "Enter full name again" << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<int>::max(),'\n');
        getline(cin,name);
    }
    
    labValue[lab - 1][compNum - 1].setID(userID);
    labValue[lab - 1][compNum - 1].setFullName(name);
    labValue[lab - 1][compNum - 1].setTime(getTime());
    
    
    cout << "Login successful" << endl;
    
}

//pre needs to accept an ID
//post takes ID out of array
void logoff(ComputerLabs *labValue[])
{
    int lab = 0;
    int compNum = 0;
    
    cout << "Enter the lab number the user is logging in from (1-8): " ;
    cin >> lab;
    if ((cin.fail()) || lab > 8 || lab < 1)     // lab validation
    {
        cout << "That is not a lab we offer" << endl;
        cout << endl;
        cout << "Please pick a valid lab (1-8)" << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<int>::max(),'\n');
        cin >> lab;
    }
    
    cout << "Enter the computer station the user is logging in to (1-33): ";
    cin >> compNum;
    if ((cin.fail()) || compNum > 33 || compNum < 1)     // lab validation
    {
        cout << "That is not a station we offer" << endl;
        cout << endl;
        cout << "Please pick a valid station (1-33)" << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<int>::max(),'\n');
        cin >> compNum;
    }
    
    cout << endl;
    
    if (labValue[lab - 1][compNum - 1].getID() == -1)
    {
        cout << "That user is not logged in." << endl;
    }
    else
    {
        labValue[lab - 1][compNum - 1].setID(-1);
        labValue[lab - 1][compNum - 1].setFullName(" ");
        labValue[lab - 1][compNum - 1].setTime(0);
        cout << "User has been logged off" << endl;
    }
}

//pre needs to accept an ID to search for
//post outputs which lab and station the user is at or says that user is not logged on
void search(ComputerLabs *labValue[])
{
    int num;
    
    cout << "Enter the 5 digit user ID number you wish to search: " ;
    cin >> num;
    cout << endl;
    if (cin.fail())
    {
        cout << "Invalid ID" << endl;
        cout << "Please enter another ID" << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<int>::max(),'\n');
        cin >> num;
    }
    
    for(int i = 0; i < NUMLABS; ++i)
    {
        for(int j = 0; j < LABSIZES[i]; ++j)
        {
            if(labValue[i][j].getID() == num )
            {
                cout << "User " << num << " is in Lab " << i+1 << "at Computer " << j+1 << endl;
                return;
            }
            else
            {
                cout << "That user is not currently logged on" << endl;
                return;
            }
        }
    }
}


//pre needs to be passed pointer
//post displays all labs and their contents
void displayLab(ComputerLabs *labValue[])
{
    int labNum = 0;
    
    cout << "Which lab would you like to display? (1-8): " ;
    cin >> labNum;
    cout << endl;
    while ((cin.fail()) || labNum > 8 || labNum < 1)     // lab validation
    {
        cout << "That is not a lab we offer" << endl;
        cout << "Please pick a valid lab (1-8): ";
        cin.clear();
        cin.ignore(std::numeric_limits<int>::max(),'\n');
        cin >> labNum;
        cout << endl;
    }
    
    cout << "Lab #" << labNum << " " << UNIVERSITYNAMES[labNum - 1] << endl;
        for(int i = 0; i < LABSIZES[labNum - 1]; ++i)
        {
            cout << i+1 << ": ";
            
            if (labValue[labNum - 1][i].getID() == -1)
            {
                cout << "empty ";
            }
            else
            {
                cout << labValue[labNum - 1][i].getID() << " ";
            }
        }
        cout << endl;
}

