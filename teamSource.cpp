// Author: Jacob Hough
// CS1300 Spring 2018
// Recitation: 205 - Harshini Muthukrishnan
// Cloud9 Editor Link: https://ide.c9.io/houghelpuff/csci1300
// Homework 8

#include <iostream>
#include "team.h"
#include <string>
using namespace std;

Team::Team(){ //constructor
    for(int i = 0; i < 5; i++){
        people[i].setName("");
        people[i].setStatus("false");
    }
    numOxen = 0;
    poundsOfFood = 0;
    setsOfClothes = 0;
    ammo = 0;
    money = 1200;
    milesTraveled = 0;
    month = "July";
    day = 8;
    year = 1999;
}

Team::Team(Players array[], int oxen, int pounds_of_food, int sets_clothes, int amount_ammo, float money_1, int miles_traveled, string currentMonth, int currentDay, int currentYear){
    for(int i = 0; i < 5; i++){
        people[i] = array[i];
    }
    numOxen = oxen;
    poundsOfFood = pounds_of_food;
    setsOfClothes = sets_clothes;
    ammo = amount_ammo;
    money = money_1;
    milesTraveled = miles_traveled;
    month = currentMonth;
    day = currentDay;
    year = currentYear;
}



int Team::getNumOxen(){ 
    return numOxen; //returns the number of oxen 
}

void Team::setNumOxen(int num){
    numOxen = num; //sets the number of oxen equal to the number passed in
}

int Team::getPoundsOfFood(){
    return poundsOfFood; //returns the pounds of food the team has 
}

void Team::setPoundsOfFood(int num){
    poundsOfFood = num; //sets the pounds of food the team has to num
}

void Team::takeFood(int num){
    poundsOfFood -= num; //a function to easily subtract some number of pounds from the team
}

int Team::getSetsOfClothes(){
    return setsOfClothes; //returns the number of sets of clothes the team has
}

void Team::setSetsOfClothes(int num){
    setsOfClothes = num; //sets the number of sets of clothes to the number passed in 
}

void Team::takeClothes(int num){
    setsOfClothes -= num; // a function to easily take clothes from the team (i.e. if there are robbers)
}

int Team::getAmmo(){
    return ammo; //returns the number of boxes of ammo the team has
}

void Team::setAmmo(int num){
    ammo = num; //sets the number of boxes of ammo the team has
}

void Team::takeAmmo(int num){
    ammo -= num; //a function to easily take some number of boxes of ammo from the team 
}

float Team::getMoney(){
    return money; //returns how much money the team has
}

void Team::setMoney(float amount){
    money = amount; //sets the money the team has to amount
}

void Team::payUp(float amount){
    money -= amount; //takes money from the team (for supplies or if lost)
}

void Team::getPaid(float amount){
    money += amount; //gives money to the team (for some reason)
}

int Team::getMiles(){
    return milesTraveled; //returns the miles trveled by the team
}

void Team::setMiles(int num){
    milesTraveled = num; //sets the number of miles trveled by the team to num
}

void Team::travelMiles(int num){
    milesTraveled += num; //adds to the miles trveled by the team
}

Players Team::getPlayerAtIdx(int idx){
    return people[idx];
}

void Team::addPlayer(Players person, int idx){
    people[idx] = person;
}

string Team::getMonth(){
    return month;
}

void Team::setMonth(string str){
    month = str;
}

int Team::getDay(){
    return day;
}

void Team::setDay(int num){
    day = num;
}

int Team::getYear(){
    return year;
}
void Team::setYear(int num){
    year = num;
}