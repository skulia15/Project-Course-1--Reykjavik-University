#include "connectiontodatabase.h"


Computers::Computers(){
   cpuName="";
   yearBuilt=0;
   cpuType="";
   creatorFirstName="";
   creatorLastName="";
};

void Computers::insertCPU(){ //inserts computers to the database
    bool error = false;
    bool error2 = true;
    char cpus;
    char temp;

    QSqlDatabase db;
    QSqlQuery query(db);

    while(error == false){
        cout << "How many computers would you like to add? ";
        cin >> cpus;
        cin.ignore();
        if (isalpha(cpus)){ //checks if input is a number
            cout << "Error in input, try again." << endl;
        }
        else
            error = true;
    }

    for (int i = 1;i <= cpus - '0'; i++){
        if (i == 1){
            cout << "\nEnter the info for the first computer: " << endl;
        }
        else {
            cout << "Enter the info for the next computer: " << endl;
        }

        do{
            cout << "Computer name: ";
            getline (cin, cpuName, '\n');
        }while (cpuName == " " || cpuName == "");
        error2 = true;
        do {
            cout << "Was the computer built? (y/n) ";
            cin >> temp;
            if (temp == 'y'||temp == 'Y'){
                built = "Yes";
                error2 = false;
                while(error == false){
                    cout << "Year built: ";
                    cin >> yearBuilt;
                    if (cin.fail()) {
                        cout << "Input was invalid try again." << endl;
                        cin.clear();
                        cin.ignore(256,'\n');
                    }
                    else error = true;
                }

                cin.ignore();
            }
            else if (temp == 'n'||temp == 'N'){
                built = "No";
                error2 = false;
                cin.ignore();
            }
            else
                cout << "Input was invalid, please try again." << endl;
        } while(error2 == true);

        do{
            cout << "Computer type: ";
            getline (cin, cpuType, '\n');
        } while(cpuType == "" || cpuType == " ");

        error = false;
        do{

            string temp;

                cout<<"Kindly write the first creators first name: "<<endl;
                getline(cin,creatorFirstName);
            error=true;

          }while (error == false);


        query.prepare("INSERT INTO Computers (cpuName, built, yearBuilt, cpuType) "
                          "VALUES (:cpuName, :built, :yearBuilt, :cpuType)");
        query.bindValue(":cpuName", QString::fromStdString(cpuName));
        query.bindValue(":built", QString::fromStdString(built));
        query.bindValue(":yearBuilt", yearBuilt);
        query.bindValue(":cpuType",  QString::fromStdString(cpuType));


        query.prepare("INSERT INTO Links (creatorsName) "
                          "VALUES (:creatorsName)");
        query.bindValue(":creatorsName", QString::fromStdString(creatorFirstName));


        if(query.exec()){
            cout << endl;
            cout << "-==== Successfully inserted data into database ====-"<<endl;
            cout << endl;
        }
        else{
            cout << endl;
            cout << "-==== Could not insert data into database ====-"<<endl;
            cout << endl;
        }
}}


void Computers::deleteCPU(){ //deletes a computer from id number
    QSqlDatabase db;
    QSqlQuery query(db);
    int tempID;

    cout << "Enter the computer ID: ";
    cin >> tempID;

    QString toDelete = QString::number(tempID);

    query.prepare("DELETE FROM Computers WHERE id = "+toDelete+";");
    query.exec();
     if(query.exec()){
         cout << "Computer with ID number " << tempID <<" was deleted." << endl;
     }
     else
         cout << "No Computer has that ID." << endl;
}
