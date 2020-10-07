//
//  listFunction.cpp
//  Lista
//
//  Created by Johnny Resendiz on 10/4/20.
//  Copyright © 2020 Johnny Resendiz. All rights reserved.
//

#include "listFunction.hpp"

/**
 * @brief constructor for LIsta
 */
Lista::Lista() {
    boxCounter = 0;
    cout << "How many boxes: ";
    cin >> amountOfBoxes;
    cin.ignore();
    
    cout << "Enter the name of Sender: ";
    getline(cin, senderName);
    
    cout << "Enter the name of Reciever: ";
    getline(cin, recieverName);
    
    cout << "What state is it going to: ";
    cin >> stateGoing;
    
    cout << "Going to to be sent through ESTAFETA? y/n ";
    cin >> option;
    cin.ignore();
    
    if(option == 'y') {
        cout << "Enter the address of destination: ";
        getline(cin, address);
        
        cout << "Enter the city: ";
        cin >> city;
        
        cout << "Enter the zipcode: ";
        cin >> zipcode;
    }
    else {
        cout << "Enter the city: ";
        getline(cin, city);
        cout << city << endl;
    }
    
    cout << "Enter the phone numbers for MX and US(MX first then US):  ";
    cin >> phoneNumberMX;
    cin >> phoneNumberUS;
    cout << endl;
}

/**
 * @brief destructor for Lista
 */
Lista::~Lista() {
    reset();
}

void Lista::reset() {
    
}

/**
 * @brief form full address line
 *  function puts all the necessary variables to create the address line of where the items are going to be sent to
*/
void Lista::formFullAddress() {
    if(getOption() == 'y') {
        fullAddy = getAddress() + ' ' + getStateGoing() + " CP " + to_string(getZipcode());
    }
    else {
        fullAddy = getCity() + ", " + getStateGoing();
    }
    
}

void Lista::writeEntryToFile() {
    file.open("lista.txt", ios::app);
    
    file << listEntry << endl;
    cout << getBoxCode() << endl;
}

/**
 * @brief form the list entry
 * function to put all the necessary variables to create the final list entry to be inputted into the text file
*/
void Lista::formListEntry() {
    formBoxCode();
    formFullAddress();
    formTelLine();
    
    listEntry = senderName + boxCode + recieverName + '\n' + fullAddy + '\n' + telLine;
}

void Lista::incrementBoxCount() {
    boxCounter++;
}

/**
 * @brief form the box code
 * function checks to see where the box is going
 * if it is going to be sent through estafeta then
 * it will change the code to .EST otherwise it
 * will stay the same and create the box code
 */
void Lista::formBoxCode() {
//    a check to see if the box will be sent through estafeta
    if(getOption() == 'y') {
        incrementBoxCount();
        boxCode = '(' + to_string(getAmountBoxes()) + '#' + to_string(getBoxCounter()) + ".EST)";
    }
    else {
        incrementBoxCount();
        boxCode = '(' + to_string(getAmountBoxes()) + '#' + to_string(getBoxCounter()) + '.' + getCity() + ')';
    }
}
    
/**
 * @brief form the telephone line
 * funciton prepares the phone numbers
 * and puts the correct formatting for the
 * final entry
 */
void Lista::formTelLine() {
    telLine = "tel MX (" + to_string(getPhoneNumberMX()) + ") USA (" + to_string(getPhoneNumberUS()) + ')';
}

string Lista::getSenderName() {
    return senderName;
}

string Lista::getRecieverName() {
    return recieverName;
}

int Lista::getPhoneNumberUS() {
    return phoneNumberUS;
}

string Lista::getCity() {
    return city;
}
 

int Lista::getPhoneNumberMX() {
    return phoneNumberMX;
}

string Lista::getStateGoing() {
    return stateGoing;
}

int Lista::getAmountBoxes() {
    return amountOfBoxes;
}

string Lista::getAddress() {
    return address;
}

int Lista::getZipcode() {
    return zipcode;
}

char Lista::getOption() {
    return option;
}

int Lista::getBoxCounter() {
    return boxCounter;
}

string Lista::getBoxCode() {
    return boxCode;
}



