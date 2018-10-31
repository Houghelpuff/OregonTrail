// Author: Jacob Hough
// CS1300 Spring 2018
// Recitation: 205 - Harshini Muthukrishnan
// Cloud9 Editor Link: https://ide.c9.io/houghelpuff/csci1300
// Homework 8

#ifndef WAGON_H
#define WAGON_H
#include <iostream>
using namespace std;

class Wagon{
    private:
        int xtraWagonWheel; //keeps track of the number of extra wagon wheels the team has 
        int xtraWagonAxel;  //keeps track of the number of extra wagon axels the team has 
        int xtraWagonTongue;    //keeps track of the number of extra wagon tongues the team has
    public:

        Wagon();

        //getter and setter for the number of extra wagon wheels 
        int getXtraWagonWheels();
        void setXtraWagonWheels(int);
        
        //a function to easily subtract extra wagon wheels from the team
        void takeXtraWagonWheels(int);
        
        //getter and setter for the number of extra wagon axels 
        int getXtraWagonAxels();
        void setXtraWagonAxels(int);
        
        //function to take extra wagon axels away (in case they get lost)
        void takeXtraWagonAxels(int);
        
        //getter and setter for the number of extra wagon tongues
        int getXtraWagonTongues();
        void setXtraWagonTongues(int);
        
        //function to take extra wagon tongues 
        void takeXtraWagonTongues(int);
};

#endif