// Author: Jacob Hough
// CS1300 Spring 2018
// Recitation: 205 - Harshini Muthukrishnan
// Cloud9 Editor Link: https://ide.c9.io/houghelpuff/csci1300
// Homework 8

#include <iostream>
#include "players.h"
#include <string>
using namespace std;


Players::Players(){ //default construstor for players 
    name = "NONE";
    isDead = false;
    health = 100;
}

Players::Players(string str){ //constructor that takes a parameter for the name of the player
    name = str; //sets name equal to the string passed in 
    isDead = false; //sets isDead to false since the player is new 
    health = 100;
}

string Players::getName(){ 
    return name; //gets the name of the player
}

void Players::setName(string str){
    name = str; //sets the name of the player
}

string Players::getStatus(){
    if(isDead == false) //if the player is dead
        return "Alive"; //returns that they are alive
        
    else
        return "Dead"; //else return dead
}

void Players::setStatus(string status){
    if(status == "true")
        isDead = true;
    else
        isDead = false;
}

int Players::getHealth(){
    return health;
}

void Players::setHealth(int num){
    health = num;
}

