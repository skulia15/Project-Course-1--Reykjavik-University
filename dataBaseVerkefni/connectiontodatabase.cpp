#include "connectiontodatabase.h"

connectionToDataBase::connectionToDataBase(){
}

void connectionToDataBase::connect(){   // Open connection to database
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "Scientists.sqlite"; // Set database name.
    db.setDatabaseName(dbName);

    db.open();

    QSqlQuery query(db);

    if(db.open()){  //Checks if connection has been established
         qDebug()<<"-==== We have been connected to the database ====-" << endl;}
    else{
         qDebug()<<"-==== Unable to connect ot the database ====-" << db.lastError().text() << " ==========" << endl;}

    string queryCreate = "CREATE TABLE Scientists(id INTEGER PRIMARY KEY AUTOINCREMENT, firstName VARCHAR NOT NULL,"
            "lastName VARCHAR NOT NULL, sex VARCHAR, YoB INTEGER NOT NULL, YoD INTEGER NOT NULL); ";        //Sets up table for Scientists

     string queryCreate2 ="CREATE TABLE Computers(id INTEGER PRIMARY KEY AUTOINCREMENT, cpuName VARCHAR NOT NULL,"
             "built VARCHAR NOT NULL, yearBuilt INTEGER NOT NULL, cpuType VARCHAR NOT NULL); ";         //Sets up table for Computers

     string queryCreate3 = "CREATE TABLE Links(creatorsName VARCHAR,cpuName VARCHAR,FOREIGN KEY (creatorsName) REFERENCES Scientists(id),FOREIGN KEY (cpuName)"
             "REFERENCES Computers(id)PRIMARY KEY (creatorsName, cpuName));";      //Sets up table for connections between tables

     if(query.exec(QString(queryCreate.c_str()))){   //Creates table for Scientists
        cout << "========== The scientist table was created successfully! =========="<< endl;}
     else {
         cout<< "========== Connected to Scientists table successfully ==========" << endl;}

     if(query.exec(QString(queryCreate2.c_str()))){  //Creates table for computers
         cout << "========= The computer table was created successfully! =========" << endl;}
     else{
         cout << "========= Connected to Computer table successfully =========" << endl;}

     if(query.exec(QString(queryCreate3.c_str()))){  //Creates table for connections
         cout << "========= The Combine table was created successfully! =========" << endl;}
     else{
         cout << "========= Connected to Combine successfully! =========" << endl << endl;}
}

void connectionToDataBase::disconect(){  // close connection to the database.
    QSqlDatabase db;
    QSqlQuery query(db);
    db.close();
}
