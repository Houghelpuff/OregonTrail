// Author: Jacob Hough
// CS1300 Spring 2018
// Recitation: 205 - Harshini Muthukrishnan
// Cloud9 Editor Link: https://ide.c9.io/houghelpuff/csci1300
// Homework 8

#ifndef PLAYERS_H
#define PLAYERS_H
#include <iostream>
using namespace std;

class Players{
    private:
        string name; //string to hold name 
        bool isDead; //bool to see if each player is dead
        int health;
        
    public:
        
        //constructors 
        Players();
        Players(string);
        
        //getter and setter for the name 
        string getName();
        void setName(string);
        
        //getter and setter for isDead
        string getStatus();
        void setStatus(string);

        //getter and setter for health
        int getHealth();
        void setHealth(int);
};

#endif