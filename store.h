// Author: Jacob Hough
// CS1300 Spring 2018
// Recitation: 205 - Harshini Muthukrishnan
// Cloud9 Editor Link: https://ide.c9.io/houghelpuff/csci1300
// Homework 8

#ifndef STORE_H
#define STORE_H
#include <iostream>
#include "wagon.h"
#include "team.h"
using namespace std;

class Store{
	private:
		int priceOfOxen; //price for each yoke of oxen
		float pricePerPound; //price per pound of food
		int costPerSet; //cost per set of clothes
		int priceOfAmmo; //cost per box of ammo
		int costPerSpare; //cost for each spare part of the wagon
		float bill;
	public:

		//constructor for the store
		Store();

		//getter and setter for the price of oxen
		int getPriceOfOxen();
		void setPriceOfOxen(int);

		//getter and setter for the price of food
		float getPricePerPound();
		void setPricePerPound(float);

		//getter and setter for cost of clothes
		int getCostPerSet();
		void setCostPerSet(int);

		//getter and setter for the price of ammo
		int getPriceOfAmmo();
		void setPriceOfAmmo(int);

		//getter and stter for the cost of spare parts
		int getCostPerSpare();
		void setCostPerSpare(int);

		//getter and setter for the bill
		float getBill();
		void setBill(float);

};

#endif