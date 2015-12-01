#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
#include <iterator>
#include <sstream>

using namespace std;

struct scientists{
    string firstName;
    string lastName;
    string personSex;
    int yearOfBirth;
    int yearOfDeath;
};

void callDefaultMenu(vector<scientists>& subject);
void inputInfo(vector<scientists>& subject);
void output(vector<scientists>& subject);
string getSearch();
bool searchName(vector<scientists>& subject, char input, string searchName);
void print(vector<scientists>& subject);
void printSearch(vector<scientists>& subject, int i);
void readFromFileToVector(vector<scientists>& subject);
void searchInVector(vector<scientists>& subject);
void clearVector(vector<scientists>& subject);
void sortVector(vector<scientists>& subject, char choice);
bool compareAlpha(const scientists& lhs, const scientists& rhs);
bool compareReverseAlpha(const scientists& lhs, const scientists& rhs);


int main()
{
    //ToDo list

    //function that searches for substrings!
    //Create a function to remove a computer scientist.
    //Optimize the program with classes!
    //Error handling.
    //Cool extra features.

    vector<scientists> subject;  //vector of persons

    readFromFileToVector(subject);

    callDefaultMenu(subject);

    return 0;
}

void callDefaultMenu(vector<scientists>& subject){ //Displays the main menu, Calls our basic functions
    char a;
    bool loop = true;

    while(loop == true){
        cout << "---------Main Menu-----------";
        cout << " \n Please select an option:  "<<endl;
        cout << " \n 1. To add a computer scientist." << endl;
        cout << " 2. To print all persons." << endl;
        cout << " 3. To search." << endl;
        cout << " 4. To delete all data." << endl;
        cout << " 5. To quit." << endl;
        cout << "------------------------------"<<endl;
        cout << "Choice: ";
        cin >> a;

        switch(a){
        case '1':
             inputInfo(subject);
             break;
        case '2':
            print(subject);
            break;
        case '3':
            searchInVector(subject);
           break;
        case '4':
            clearVector(subject);
            break;
        case '5':
            cout << "Quitting." << endl;
            loop = false;
            break;
        default:
            cout << "Error in command, try again." << endl << endl;
            break;
        }
     }
}

void inputInfo(vector<scientists>& subject){
    scientists scientist1;
    char answer = 0;
    char persons;
    bool error = false;
    string sex;
    char sexTemp;

    while(error == false){
        cout << "How many persons would you like to add? ";
        cin >> persons;
        if (isalpha(persons)){
            cout << "Error in input, try again." << endl;
        }
        else
            error = true;
    }

    for (int i = 1;i <= persons - '0'; i++){
        if (i == 1){
            cout << "\nEnter the info for the first person: " << endl;}
        else {
            cout << "Enter the info for the next person: " << endl;}

        cout << "Person's first name: ";
        cin >> scientist1.firstName;
         for (unsigned int i=0;i<scientist1.firstName.length();i++){//Change name to lowercase
                    //scientist1.firstName[i]=tolower(scientist1.firstName[i]);
        }
        cout << "Last name: ";
        cin >> scientist1.lastName;
        for (unsigned int i=0;i<scientist1.lastName.length();i++){//Change name to lowercase
                  //  scientist1.lastName[i]=tolower(scientist1.lastName[i]);
        }
        cout << endl;

        do{
            cout << "Sex: (m/f) " ;
            cin >> sexTemp;
            if (sexTemp == 'm'){ sex = "Male"; error = true;}
            else if (sexTemp == 'f'){ sex = "Female"; error = true;}
            else cout << "Input was invalid try again." << endl;
        } while (error == false);
        scientist1.personSex = sex;
        cout << endl;

        cout << "Year of Birth: ";
        cin >> scientist1.yearOfBirth;
        cout << endl;

        error = false;
        do{
            cout << "Is the person still alive? (y/n) ";
            cin >> answer;
            if (answer == 'n'||answer == 'N'){
                cout << "\nYear of Death: ";
                cin >> scientist1.yearOfDeath;
                error = true;}
            else if (answer == 'y'||answer == 'Y'){
                scientist1.yearOfDeath = 0;
                error = true;}
            else cout << "Input was invalid try again." << endl;
        } while (error == false);
        cout << endl;

        subject.push_back(scientist1);  //The struct is pushed on to the vector
    }
    output(subject);
}

void output(vector<scientists>& subject){
    ofstream myfile;
    myfile.open("save.txt", ios::out | ios::app); //For adding without overwriting
    if (myfile.is_open()){
        for (unsigned int i = 0; i < subject.size(); i++){  //Needs to be modified, not adding persons correctly. 1 off error.
            myfile << subject[i].firstName << endl;
            myfile << subject[i].lastName << endl;
            myfile << subject[i].personSex << endl;
            myfile << subject[i].yearOfBirth << endl;
            if(subject[i].yearOfDeath == 0){  //if still alive then marks as "Still Alive"
                myfile << "still alive." << endl;}
            else {
                myfile << subject[i].yearOfDeath << endl;}
        }
        myfile.close();
    }
    else cout << "Unable to open file";
}

void print(vector<scientists>& subject){
    char choice;
    bool error = false;

    while(error == false){
        cout << "How would you like to display your persons?" << endl;
        cout << "1. In alphabetical order." << endl;
        cout << "2. In reverse alphabetical order." << endl;
        cout << "Input your choice: ";
        cin >> choice;
        cout << endl;
        if (isalpha(choice)){ cout << "Error in input, try again." << endl;}
        else { error = true;}
    }

    switch (choice){
        case '1':
            cout << "Displaying in alphabetical order." << endl;
            sortVector(subject, choice);
            break;
        case '2':
            cout << "Displaying in reverse alphabetical order." << endl;
            sortVector(subject, choice);
            break;
        default:
            cout << "You entered a number with an undefined function." << endl
            << "Displaying in alphabetical order." << endl;
            sortVector(subject, '1');
            break;
    }
    cout << endl;

    for(unsigned int i = 0; i < subject.size(); i++){
        cout << "Name: " << subject[i].firstName << " ";
        cout << subject[i].lastName << endl;
        cout << "Sex: " << subject[i].personSex << endl;
        cout << "Year of birth: " << subject[i].yearOfBirth << endl;
        if (subject[i].yearOfDeath == 0){
            cout << "Alive" << endl;
        }
        else{
        cout << "Year of death: " << subject[i].yearOfDeath << endl;}
        cout << endl;
    }
}
void printSearch(vector<scientists>& subject, int i){
        cout << "Name: " << subject[i].firstName << " ";
        cout << subject[i].lastName << endl;
        cout << "Sex: " << subject[i].personSex << endl;
        cout << "Year of birth: " << subject[i].yearOfBirth << endl;
        if (subject[i].yearOfDeath == 0){
            cout << "Alive" << endl;
        }
        else{
            cout << "Year of death: " << subject[i].yearOfDeath << endl;}
        cout << endl;
}

string getSearch(){
    string searchName;
    cin >> searchName;
    for (unsigned int i = 0; i < searchName.length(); i++){//Change search keyword to lowercase
            searchName[i] = tolower(searchName[i]);
    }
    cout << endl;
    return searchName;
}

bool searchName(vector<scientists>& subject, char input, string searchName){
    string tempSubject;
    int tempYoB;
    stringstream convert;
    string YoB;
    bool found = false;
    int counter = 0; //If more than one subjects were found then don't cout "keyword was found".
    for(unsigned int i = 0; i < subject.size(); i++){
        if (input == '1'){tempSubject = subject[i].firstName;}
        else if (input == '2'){tempSubject = subject[i].lastName;}
        else if (input == '3'){tempYoB = subject[i].yearOfBirth;}
        transform(tempSubject.begin(), tempSubject.end(), tempSubject.begin(), ::tolower); //Put to lowercase for case-insensitive searching.
        convert.str(""); //To clear the string steam from the iteration before.
        convert << tempYoB;  //add the value of Number to the characters in the stream.
        YoB = convert.str(); //set Result to the content of the stream.
        if(tempSubject == searchName || YoB == searchName){
            if (counter == 0){
                cout << "Keyword was found for: " << endl;
            }
            printSearch(subject, i);
            found = true;
            counter++;
        }
    }
    if (found == true) return true;
    else return false;
}

void searchInVector(vector<scientists>& subject){// Search function.
    //ATH vi� viljum l�ka finna substring!!
    char input;
    bool loop = true;
    bool found = false;
    string theSearchName;

    while(loop == true){
        cout << "--------Search Menu-----------";
        cout << " \n Please select a search option:  "<<endl;
        cout << " \n 1. To search by first name" << endl;
        cout << " 2. To search by last name" << endl;
        cout << " 3. To search by birth year" << endl;
        cout << " 4. To exit to main menu" << endl;
        cout << "-----------------------------"<<endl;
        cout << "Search by:  ";
        cin >> input;

        switch(input){ //Runs through vector and prints out the locations where "i" equals name provided
        case '1':
            cout << "Please enter a first name to search for: ";
            theSearchName = getSearch();
            found = searchName(subject, input, theSearchName);
            if (found == false){
                cout << "Sorry the first name \"" << theSearchName << "\" did not match any first names in database. \n";
            }
            break;

        case '2': //Runs through vector and prints out the locations where "i" equals last name provided
            cout << "Please enter a last name to search for: ";
            theSearchName = getSearch();
            found = searchName(subject, input, theSearchName);
            if (found == false){
                cout << "Sorry the last name \"" << theSearchName << "\" did not match any last names in database. \n";}
            break;

        case '3': //Runs through vector and prints out the locations where "i" equals birthday provided.
            cout << "Enter birth year: ";
            theSearchName = getSearch();
            found = searchName(subject, input, theSearchName);
            if (found == false){
                cout <<"Sorry, according to our records nobody was born in " << theSearchName << endl;}
           break;

         case '4':
            cout << "Going back to Main menu." << endl;
            loop = false;
            break;
        }
    }
}

void readFromFileToVector(vector<scientists>& subject){
    ifstream myfile;
    scientists scientist1;
    myfile.open("save.txt");

    while (!myfile.eof()){

        string first, second, sex, YoB, YoD;
        getline(myfile, first, '\n');
        getline(myfile, second,'\n');
        getline(myfile, sex,'\n');
        getline(myfile, YoB,'\n');
        getline(myfile, YoD,'\n');

        if (!myfile.eof()){
            scientist1.firstName = first;
            scientist1.lastName = second;
            scientist1.personSex = sex;
            scientist1.yearOfBirth = atoi(YoB.c_str());
            scientist1.yearOfDeath = atoi(YoD.c_str());
            subject.push_back(scientist1);
        }
    }
    myfile.close();
  }

void clearVector(vector<scientists>& subject){
    char answer;
    cout << "Are you sure you want to delete all data? (y/n) ";
    cin >> answer;

    if(answer == 'y'){
        subject.clear();
        cout << "Vector cleared of all elements." << endl;
        ofstream myfile;
        myfile.open("save.txt");
        myfile << "";
        myfile.close();
    }
    else{
        callDefaultMenu(subject);
    }
}

bool compareAlpha(const scientists& lhs, const scientists& rhs) {
    return lhs.firstName < rhs.firstName;
}
bool compareReverseAlpha(const scientists& lhs, const scientists& rhs) {//add by birth year!
    return lhs.firstName > rhs.firstName;
}

void sortVector(vector<scientists>& subject, char choice){
    if (choice == '1'){
        sort(subject.begin(), subject.end(), compareAlpha);}
    else if (choice == '2'){
        sort(subject.begin(), subject.end(), compareReverseAlpha);}
}
