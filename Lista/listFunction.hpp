//
//  listFunction.hpp
//  Lista
//
//  Created by Johnny Resendiz on 10/4/20.
//  Copyright © 2020 Johnny Resendiz. All rights reserved.
//

#ifndef listFunction_hpp
#define listFunction_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

class Lista {
private:
    /// @brief the unique code each box will have in the lista
    string boxCode;
    /// @brief the final list entry to be inserted in the text file
    string listEntry;
    /// @brief the address entry for the final list entry
    string fullAddy;
    /// @brief the telephone number entry for the final list entry
    string telLine;
    /// @brief the box number for the box code withtout the destination identifier i.e., 100.est, 101.est
    int boxCounter;
    
public:
    /// @brief the name of the person sending
    string senderName;
    /// @brief the name of the person recieving
    string recieverName;
    /// @brief the phone number of the person sending in the US
    int phoneNumberUS;
    /// @brief the phone number of the person recieving in MX
    int phoneNumberMX;
    /// @brief the amount of boxes
    int amountOfBoxes;
    /// @brief the address where it is gonig if it is going through ESTAFETA
    string address;
    /// @brief the zipcode of the city
    int zipcode;
    /// @brief the state it is going to if being sent thourhg ESTAFETA
    string stateGoing;
    /// @brief the name of the city it'll be sent to
    string city;
    char option;
    ofstream file;
    
//    constructor and destructor
    Lista();
    ~Lista();
    void reset();
    
    //funciton to check if it is going to be shipped outside of Hidalgo
    void isGoingEstafeta(char o);
    
    //incrment function
    void incrementBoxCount();
    
    //write to file functions
    void writeEntryToFile();
    
    //form functions
    void formFullAddress();
    void formListEntry();
    void formBoxCode();
    void formTelLine();
    
    //accessor methods
    string getSenderName();
    string getRecieverName();
    int getPhoneNumberUS();
    int getPhoneNumberMX();
    string getStateGoing();
    int getAmountBoxes();
    string getAddress();
    int getZipcode();
    string getCity();
    char getOption();
    int getBoxCounter();
    string getBoxCode();
    
};

#endif /* listFunction_hpp */
