//
//  main.cpp
//  D&D Char Sheet
//
//  Created by Max Huber on 2/28/13.
//  Copyright (c) 2013 IDEAS. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

int abillMod (int abill);

int main () {
    
    //define variables
    char name[50];
    int str;
    int con;
    int agi;
    int intel;
    int wis;
    int cha;
    
    //get user inputs
    cout << "Enter name: ";
    cin >> name;
    
    cout << "Roll 4d6 for STR: ";
    cin >> str;
    
    cout << "Roll 4d6 for CON: ";
    cin >> con;
    
    cout << "Roll 4d6 for AGI: ";
    cin >> agi;
    
    cout << "Roll 4d6 for INT: ";
    cin >> intel;
    
    cout << "Roll 4d6 for WIS: ";
    cin >> wis;
    
    cout << "Roll 4d6 for CHA: ";
    cin >> cha;
    
    ofstream myfile;
    ofstream myfile2;
    
    myfile.open ("D&D_Sheet.txt");
    myfile2.open("dnds.txt");
    
    myfile << "Name: " << name << "\n\n" <<
    "STR: " << str << "   Mod: " << abillMod(str) << "\n" <<
    "CON: " << con << "   Mod: " << abillMod(con) << "\n" <<
    "AGI: " << agi << "   Mod: " << abillMod(agi) << "\n" <<
    "INT: " << intel << "   Mod: " << abillMod(intel) << "\n" <<
    "WIS: " << wis << "   Mod: " << abillMod(wis) << "\n" <<
    "CHA: " << cha << "   Mod: " << abillMod(cha) << "\n";
    
    myfile2 << name << "\n\n" <<
    str << "\n" << abillMod(str) << "\n" <<
    con << "\n" << abillMod(con) << "\n" <<
    agi << "\n" << abillMod(agi) << "\n" <<
    intel << "\n" << abillMod(intel) << "\n" <<
    wis << "\n" << abillMod(wis) << "\n" <<
    cha << "\n" << abillMod(cha) << "\n";
    
    myfile.close();
    myfile2.close();
    
    return 0;
}

int abillMod (int abill) {
    
    if (abill < 10 && abill %2 == 1) {
        return((abill - 10) / 2 - 1);
    }
    
    else {
        return ((abill - 10) / 2);
    }
}