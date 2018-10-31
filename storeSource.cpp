// Author: Jacob Hough
// CS1300 Spring 2018
// Recitation: 205 - Harshini Muthukrishnan
// Cloud9 Editor Link: https://ide.c9.io/houghelpuff/csci1300
// Homework 8

#include <iostream>
#include "store.h"
#include <string>
using namespace std;

Store::Store(){
	priceOfOxen = 40;
	pricePerPound = 0.2;
	costPerSet = 10;
	priceOfAmmo = 2;
	costPerSpare = 10;
	bill = 0;
}

int Store::getPriceOfOxen(){
	return priceOfOxen; //return the price of a yoke of oxen
}

void Store::setPriceOfOxen(int n){
	priceOfOxen = n; //sets the price of a yoke of oxen
}

float Store::getPricePerPound(){
	return pricePerPound; //returns the price of food per pound
}

void Store::setPricePerPound(float n){
	pricePerPound = n; //sets the price of food per pound to n
}

int Store::getCostPerSet(){
	return costPerSet; // returns the cost per set of clothes
}

void Store::setCostPerSet(int n){
	costPerSet = n; //sets the cost per set of clothes to n
}

int Store::getPriceOfAmmo(){
	return priceOfAmmo; //returns the price of each box of ammo
}

void Store::setPriceOfAmmo(int n){
	priceOfAmmo = n; //sets the price of each box of ammo
}

int Store::getCostPerSpare(){
	return costPerSpare; //reutrns the costs per spare part
}

void Store::setCostPerSpare(int n){
	costPerSpare = n; //sets the cost per spare part to n
}

float Store::getBill(){
	return bill; //returns the bill for the store visit
}

void Store::setBill(float n){
	bill = n; //sets the total bill to n 
}







