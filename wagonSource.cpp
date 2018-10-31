// Author: Jacob Hough
// CS1300 Spring 2018
// Recitation: 205 - Harshini Muthukrishnan
// Cloud9 Editor Link: https://ide.c9.io/houghelpuff/csci1300
// Homework 8

#include <iostream>
#include "wagon.h"
#include <string>
using namespace std;

Wagon::Wagon(){
	xtraWagonWheel = 0;
	xtraWagonAxel = 0;
	xtraWagonTongue = 0;

}

int Wagon::getXtraWagonWheels(){
    return xtraWagonWheel; //gets how many extra Wagonwheels the Wagonhas
}

void Wagon::setXtraWagonWheels(int num){
    xtraWagonWheel = num; //sets the number of extra Wagonwheels the tream has
}

void Wagon::takeXtraWagonWheels(int num){
    xtraWagonWheel -= num; //a function to subtract from the number of Wagon wheels the Wagonhas (in case of tragedy or thief)
}

int Wagon::getXtraWagonAxels(){
    return xtraWagonAxel; //returns how many extra Wagon axels the Wagonhas
}

void Wagon::setXtraWagonAxels(int num){
    xtraWagonAxel = num; //sets the number of extra Wagon axels the Wagonhas
}

void Wagon::takeXtraWagonAxels(int num){
    xtraWagonAxel -= num; //to subtract num from the number of extra Wagonaxels the 
}

int Wagon::getXtraWagonTongues(){
    return xtraWagonTongue; //returns how many wagon tongues the team has
}

void Wagon::setXtraWagonTongues(int num){
    xtraWagonTongue = num; // sets the number of extra wagon tongues the team has to num
}

void Wagon::takeXtraWagonTongues(int num){
    xtraWagonTongue -= num; //takes extra wagon tongues from the pteam (if they get lost like in a river)
}