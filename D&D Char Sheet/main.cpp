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
    char raceName[9];
    int str;
    int con;
    int dex;
    int intel;
    int wis;
    int cha;
    int race;
    int conRaceMod;
    int chaRaceMod;
    int dexRaceMod;
    int strRaceMod;
    int intelRaceMod;
    int clas;
    int baseAttackRate;
    int fortGoodBad;
    int refGoodBad;
    int willGoodBad;
    
    //get user inputs
    cout << "Enter name: ";
    cin >> name;
    
    cout << "__________________\n"
            "|                |\n"
            "|  1 - Barbarian |\n"
            "|  2 - Bard      |\n"
            "|  3 - Cleric    |\n"
            "|  4 - Druid     |\n"
            "|  5 - Fighter   |\n"
            "|  6 - Monk      |\n"
            "|  7 - Paladin   |\n"
            "|  8 - Ranger    |\n"
            "|  9 - Rogue     |\n"
            "| 10 - Sorcerer  |\n"
            "| 11 - Wizard    |\n"
            "|________________|\n\n"
            "Enter class: ";
    cin >> clas;
    
    cout << "________________\n"
            "|              |\n"
            "| 1 - Human    |\n"
            "| 2 - Dwarf    |\n"
            "| 3 - Elf      |\n"
            "| 4 - Gnome    |\n"
            "| 5 - Half-Elf |\n"
            "| 6 - Half-Orc |\n"
            "| 7 - Halfling |\n"
            "|______________|\n\n"
            "Enter race: ";
    cin >> race;
    
    cout << "Roll 4d6 for STR: ";
    cin >> str;
    
    cout << "Roll 4d6 for CON: ";
    cin >> con;
    
    cout << "Roll 4d6 for DEX: ";
    cin >> dex;
    
    cout << "Roll 4d6 for INT: ";
    cin >> intel;
    
    cout << "Roll 4d6 for WIS: ";
    cin >> wis;
    
    cout << "Roll 4d6 for CHA: ";
    cin >> cha;
    
    //find race mods
    if (race == 1) {
        const char raceName[9] = "Human";
    }
    
    if (race == 2) {
        const char raceName[9] = "Dwarf";
        dexRaceMod = 2;
        conRaceMod = -2;
    }
    
    if (race == 3) {
        const char raceName[9] = "Elf";
        conRaceMod = 2;
        strRaceMod = -2;
    }
    
    if (race == 4) {
        const char raceName[9] = "Gnome";
        conRaceMod = 2;
        strRaceMod = -2;
    }
    
    if (race == 5) {
        const char raceName[9] = "Half-Elf";
    }
    
    if (race == 6) {
        const char raceName[9] = "Half-Orc";
        strRaceMod = 2;
        intelRaceMod = -2;
        chaRaceMod = -2;
    }
    
    if (race == 7) {
        const char raceName[9] = "Halfling";
        dexRaceMod = 2;
        strRaceMod = -2;
    }
    
    //class mods
    if (clas == 1) {
        baseAttackRate = 2;    //2 = good base att, 1 = average base att, 0 = poor base att
        fortGoodBad = 1;
        refGoodBad = 0;    //1 = good save, 0 = poor save
        willGoodBad = 0;
    }
    
    if (clas == 2) {
        baseAttackRate = 1;
        fortGoodBad = 0;
        refGoodBad = 1;
        willGoodBad = 1;
    }
    
    if (clas == 3) {
        baseAttackRate = 1;
        fortGoodBad = 1;
        refGoodBad = 0;
        willGoodBad = 1;
    }
    
    if (clas == 4) {
        baseAttackRate = 1;
        fortGoodBad = 1;
        refGoodBad = 0;
        willGoodBad = 1;
    }
    
    if (clas == 5) {
        baseAttackRate = 2;
        fortGoodBad = 1;
        refGoodBad = 0;
        willGoodBad = 0;
    }
    
    if (clas == 6) {
        baseAttackRate = 1;
        fortGoodBad = 1;
        refGoodBad = 1;
        willGoodBad = 1;
    }
    
    if (clas == 7) {
        baseAttackRate = 2;
        fortGoodBad = 1;
        refGoodBad = 0;
        willGoodBad = 0;
    }
    
    if (clas == 8) {
        baseAttackRate = 2;
        fortGoodBad = 1;
        refGoodBad = 1;
        willGoodBad = 0;
    }
    
    if (clas == 9) {
        baseAttackRate = 1;
        fortGoodBad = 0;
        refGoodBad = 1;
        willGoodBad = 0;
    }
    
    if (clas == 10) {
        baseAttackRate = 0;
        fortGoodBad = 0;
        refGoodBad = 0;
        willGoodBad = 1;
    }
    
    if (clas == 11) {
        baseAttackRate = 0;
        fortGoodBad = 0;
        refGoodBad = 0;
        willGoodBad = 1;
    }
    
    ofstream myfile;
    ofstream myfile2;
    
    myfile.open ("D&D_Sheet.txt");
    myfile2.open("dnds.txt");
    
    //write to files
    myfile << "Name: " << name << "\n" <<
    
    "Race: " << raceName << "\n\n" <<
    "STR: " << str << "   Mod: " << abillMod(str) << "\n" <<
    "CON: " << con << "   Mod: " << abillMod(con) << "\n" <<
    "DEX: " << dex << "   Mod: " << abillMod(dex) << "\n" <<
    "INT: " << intel << "   Mod: " << abillMod(intel) << "\n" <<
    "WIS: " << wis << "   Mod: " << abillMod(wis) << "\n" <<
    "CHA: " << cha << "   Mod: " << abillMod(cha) << "\n";
    
    myfile2 << name << "\n" <<
    clas << "\n" <<
    race << "\n" <<
    str << "\n" << abillMod(str) << "\n" <<
    con << "\n" << abillMod(con) << "\n" <<
    dex << "\n" << abillMod(dex) << "\n" <<
    intel << "\n" << abillMod(intel) << "\n" <<
    wis << "\n" << abillMod(wis) << "\n" <<
    cha << "\n" << abillMod(cha) << "\n";
    
    myfile.close();
    myfile2.close();
    
    return 0;
}

int abillMod (int abill) {
    
    if (abill < 10 && abill %2 == 1) {
        return ((abill - 10) / 2 - 1);
    }
    
    else {
        return ((abill - 10) / 2);
    }
}