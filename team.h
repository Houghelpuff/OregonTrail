// Author: Jacob Hough
// CS1300 Spring 2018
// Recitation: 205 - Harshini Muthukrishnan
// Cloud9 Editor Link: https://ide.c9.io/houghelpuff/csci1300
// Homework 8

#ifndef TEAM_H
#define TEAM_H
#include <iostream>
#include "players.h"
using namespace std;

class Team{
    private:
        Players people[5];  //creates an array of players to form the team
        int numOxen;        //keeps track of the number of oxen
        int poundsOfFood;   //keeps track of the pounds of food for the team
        int setsOfClothes;  //keeps track of the sets of clothes the team has
        int ammo;           //keeps track of the ammo the team has
        float money;        //keeps track of the teams money
        int milesTraveled;  //keeps track of the miles traveled
        string month;
        int day;
        int year;
    
    public:
        //constructors
        Team();
        Team(Players[], int, int, int, int, float, int, string, int, int);
        
        //getter and setter for the number of oxen 
        int getNumOxen();
        void setNumOxen(int);
        
        //getter and setter for the pounds of food 
        int getPoundsOfFood();
        void setPoundsOfFood(int);
        
        //function to easily subtract food from the team
        void takeFood(int);
        
        //getter and setter for the sets of clothes the team has 
        int getSetsOfClothes();
        void setSetsOfClothes(int);
        
        //function to easily subtract sets of clothes from the team (i.e. a robber took them)
        void takeClothes(int);
        
        //getter and setter for the ammo
        int getAmmo();
        void setAmmo(int);
        
        //a function to easily take ammo away from the team
        void takeAmmo(int);
        
        //getter and setter for the money
        float getMoney();
        void setMoney(float);
        
        //functions to add and subtract funds from money
        void payUp(float);
        void getPaid(float);
        
        //getter and setter for the miles trveled by the team
        int getMiles();
        void setMiles(int);
        void travelMiles(int);
        
        Players getPlayerAtIdx(int); //function to get a player from the array
        void addPlayer(Players, int); //function to add a pley to the people array

        //getter and setters for the month
        string getMonth();
        void setMonth(string);

        //getter and setter for the day
        int getDay();
        void setDay(int);

        //getter and setter for year
        int getYear();
        void setYear(int);
        
};

#endif