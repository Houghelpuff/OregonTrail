// Author: Jacob Hough
// CS1300 Spring 2018
// Recitation: 205 - Harshini Muthukrishnan
// Cloud9 Editor Link: https://ide.c9.io/houghelpuff/csci1300
// Homework 8

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "wagon.h"
#include "team.h"
#include "players.h"
#include "store.h"
#include <string>
using namespace std;

void loadData(string names[], int milesTo[], string filename){
    ifstream mystream; //creates a stream  
    mystream.open(filename); //opens the file passed in 
    string str; //creates a string for the getline variable
    string stringToIntMiles; //creates a string to cast the name of the landmark to 
    int intMiles; //int for stoi





    if(!(mystream.is_open())){
        cout << "Landmark file not found" << endl; //if the file isn't open, tell the user
    }

    else{
        int count = 0; //a count to keep track of what line i'm on
        while(getline(mystream, str)){ //while there is still lines to get
            if(count == 0){ //if the count is 0
                names[0] = str; //set names at spot 0 equal to str
            }
            else if(count%2 != 0){ //if the count is odd (the names of the landmarks )
                names[count] = str; //names at spot 0 equal to str
            }
            else if(count%2 == 0){ //if the count is even (the miles to the landmark)
                stringToIntMiles = str.substr(0,3); //makes a substring of just the miles
                milesTo[count] = stoi(stringToIntMiles); //sets the milesTo to at spot count to the stoi of that substr
            }
            //count++;
        }
    }
}

string putLower(string str){ //function to put a string to lower case
    
    for(int i = 0; i < str.length(); i++){
        str[i] = tolower(str[i]);
    }
    
    return str; //returns the lowercase string
}

float updateBill(Team team_1, Wagon wagon_1, Store store_1){ //function to update the bill each time someone uys something
    float bill = 0; //variable to keep track of the total
    //bill is the price of everything multiplued by its respective item all added together
    bill = (store_1.getPriceOfOxen()*(team_1.getNumOxen()/2))+(store_1.getPricePerPound()*team_1.getPoundsOfFood())+(store_1.getCostPerSet()*team_1.getSetsOfClothes())+(store_1.getPriceOfAmmo()*team_1.getAmmo())+(store_1.getCostPerSpare()*wagon_1.getXtraWagonWheels())+(store_1.getCostPerSpare()*wagon_1.getXtraWagonAxels())+(store_1.getCostPerSpare()*wagon_1.getXtraWagonTongues());
    return bill; //returns the total
}

void misfortunes(Team team_1, Wagon wagon_1){ //function to call misfortunes
    int yesNo = rand() % 100 + 1; //creates a random int to see if a misfortune happens (40%)

    if(yesNo > 1 && yesNo < 40){ //if it is 40%
        int whichOne = rand() % 5 + 1; //create a random variable to see which misfortune happens
            if(whichOne == 1){ //if it is 1
                int playeridx = rand() % 5; //create a random player index
                cout << team_1.getPlayerAtIdx(playeridx).getName() << " got the flu!" << endl; //print that tht player got the flu
                if(team_1.getPlayerAtIdx(playeridx).getHealth() == 100){ //if the players health is 100
                    team_1.getPlayerAtIdx(playeridx).setHealth(50); //set it to 50
                }
                else if(team_1.getPlayerAtIdx(playeridx).getHealth() == 50){ //if it is 50
                    team_1.getPlayerAtIdx(playeridx).setHealth(0); //set it to 0 and set the is dead status to true
                    team_1.getPlayerAtIdx(playeridx).setStatus("true");
                }
            }
            else if(whichOne == 2){ //if it is 2
                team_1.setNumOxen(team_1.getNumOxen()-1); //take one oxen away from the team
                cout << "One of your oxen died! You have " << team_1.getNumOxen() << " left." << endl; //print that you have lost one oxen
            }
            else if(whichOne == 3){ //if it is 3
                int numPounds = rand() % 10 + 10; //creates a randdom number between 10 and 20 
                cout << "Oh no! You got attacked by a theif in the night!" << endl; //print that a theif has struck
                team_1.setPoundsOfFood(team_1.getPoundsOfFood()-numPounds); //takes food away from the team
            }
    }
}

void takeTurn(Team team_1,Wagon wagon_1,Store store_1, int miles[], string landmark[], int idx){ //a function to take a turn
    string choice; //string to store a choice
    int intChoice; //int to store a choice
    if(putLower(team_1.getPlayerAtIdx(0).getStatus()) == "true" || team_1.getPoundsOfFood() == 0 || team_1.getNumOxen() == 0){ //if any of these are true, the game is over
        cout << "Game over!" << endl;
    }

    else{ //else 
        for(int i = 0; i < 14; i++){ //travel 280 miles
            team_1.travelMiles(20);
            team_1.setDay(team_1.getDay()+1); //each time, the day gets incremented  
            if(team_1.getMiles() == miles[idx]){ //if the miles is the same as a landmark 
                cout << "You have reached " << landmark[idx] << "!" << endl; //say they have reached a landmark
                cout << "Would you like to rest?" << endl; //ask if they would like to rest
                cin >> choice; //cin to choice

                if(putLower(choice) == "yes"){ //if yes
                    cout << "How many days would you like to rest? "; //ask how many days they would like to rest
                    cin >> intChoice; //cin to inchoice 
                    team_1.setDay(team_1.getDay()+intChoice); //sets the days to the date after how many days they rested.
                }
            }
        }

    }
    misfortunes(team_1,wagon_1); //sees if a msifortuen happened
}


int main(){
    Team team1; //creates a team object 
    Wagon wagon1; //creates a wagon object 
    int intChoice; //int to keep track of a choice
    string stringChoice; //string to keep track of a choice
    char charChoice; //char to keep track of a choice
    bool flag = true; //bool to be a flag
    bool validChoice = true; //bool to check if they inputted a valid option
    string landMarkNames[15]; //array for the names of landmarks
    int milesToLandmark[15]; //array for the miles till each landmark

    loadData(landMarkNames,milesToLandmark,"landmarks.txt"); //loads the data about the landmarks from the file
    
    while(flag){ //while the flag 
        cout << "You may\n1. Travel the trail\n2. Learn about the trail\n3. See the Oregon Top 10\n4. End" << endl; //ask what they would like to do 
        cout << "What is your Choice? " << endl;
        cin >> intChoice;
        
        if(intChoice < 1 || intChoice > 4){ //of they input an invalid option 
            validChoice = false;
        }
        
        while(!validChoice){
            cout << "Please enter a valid choice" << endl; //ask again until they put a valid option
            cin >> intChoice;
            
            if(intChoice >= 1 && intChoice <= 4){
                validChoice = true;
            }
        }
        
        if(intChoice == 1){ //if they chose to travel the trail, move on 
            break;
        }
        
        if(intChoice == 2){ //if they chose 2, give them info on the trail
            cout << "Try taking a journey by\ncovered wagon 2000 miles of plains, river, and\nmountains. Try! On the plains, will you slosh your\noxen through mud and water-filled ruts or will you\n plod through dust six inches deep?" << endl;
            cout << "How will you cross the rivers? if you have money, you might\ntake a ferry (if there is a ferry). Or, you can for the\nriver and hope you and your wagon aren't swallowed alive" << endl;
            cout << "What about supplies? Well, if\nyou're low on food you can\nhunt. You might get a buffalo...\nyou might. And there are\nbears in the mountains" << endl;
            cout << "At Dallas, you can try navigating the Columbia River,\nbut if running the rapids with a makeshift raft makes you\nqueasy, better take the Barlow road" << endl;
            cout << "If for some reason you don't survive -- your wagon burns,\nor theives steal your oxen, or you run out of provisions, or\nyou die of cholera -- don't give up!" << endl;
            cout << "Press q to comtinue" << endl;
            cin >> charChoice;
        }
        
        if(intChoice == 4){ //if they picked 4, just end the program
            cout << "Thanks for playing!" << endl;
            return 0;
        }
    }
    
    flag = true; //set flag to true again
    int playerintChoice; 
    string leaderName; //string for the leaders name
    string partyNames; //string for the party's names
    
    cout << "You may be:\n1. A banker from Boston\n2. A carpenter from Ohio\n3. A farmer from Illinois\nWhat is your Choice? ";
    cin >> intChoice; //asks what role they want to be
    
    cout << "What is the first name of the Wagon Leader? ";
    cin >> leaderName; //enter the name of that wagon leader
    
    Players teamLeader; //creates a new playert called team leader
    teamLeader.setName(leaderName); //sets the name to the team leader's name
    team1.addPlayer(teamLeader,0); //add the player to the array
    
    int count = 1; 
    
    cout << "What are the first names of the four other members in your party?" << endl; //asks what the party member's names are 
    
    cout << "1. " << team1.getPlayerAtIdx(0).getName() << endl;
    while(count < 5){
        cout << count+1 << ". "; //asks them to eneter each name
        cin >> partyNames;
        
        Players newPlayer; //creates a new player each time
        newPlayer.setName(partyNames); //sets the players name to the name given
        team1.addPlayer(newPlayer, count); //adds them to the array
        
        count++;
    }
    
    cout << "Do these names look right?" << endl; //asks if the names look right

    for(int i = 0; i < 5; i++){
        cout << i+1 << ". " << team1.getPlayerAtIdx(i).getName() << endl; //prints the names again
    }
    
    cin >> stringChoice;
    
    
    if(putLower(stringChoice) == "no"){ //if it is no, ask them to re-enter the names
        count = 1;
        flag = false;
        cout << "Please Enter the names of your party memebers again" << endl;
    }
    
    
    while(!flag && count < 5){ //while the flag is false, the names are not right
        //goes through the same process as before
        cout << count << ". ";
        cin >> partyNames;
        
        team1.getPlayerAtIdx(count).setName(partyNames);
        
        count++;
        
        if(count == 5){
        cout << "Do these names look right?" << endl;
    
        for(int i = 0; i < 5; i++){
            cout << count + 1 << ". " << team1.getPlayerAtIdx(i).getName() << endl;
        }
    
        cin >> stringChoice;
    
    
        if(putLower(stringChoice) == "no"){
            count = 1;
            flag = true;
        }
    }
    }

    cout << "It is 1848. Your jumping off place for Oregon is Independence, Missouri. You must decide which month to leave Independence" << endl;
    cout << "1. March\n2. April\n3. May\n4. June\n5. July" << endl; //ask what date they want to leave
    cout << "What is your choice? ";
    cin >> intChoice; 

    //takes their choice and sets the date to the coorespoding choice

    if(intChoice == 1){
        team1.setMonth("March");
        team1.setDay(1);
        team1.setYear(1848);
    }

    else if(intChoice == 2){
        team1.setMonth("April");
        team1.setDay(1);
        team1.setYear(1848);
    }

    else if(intChoice == 3){
        team1.setMonth("May");
        team1.setDay(1);
        team1.setYear(1848);
    }

    else if(intChoice == 4){
        team1.setMonth("June");
        team1.setDay(1);
        team1.setYear(1848);
    }

    else{
        team1.setMonth("July");
        team1.setDay(1);
        team1.setYear(1848);
    }

    cout << "Before leaving Independence you should buy equipment and supplies. You have $1600.00 in cash, but you don't have to spend it all now" << endl;
    cout << endl;
    cout << "You can buy whatever you need at Jacob's General Store" << endl; //explains the store

    Store store1; //creates a store object

    cout << "Hello, I'm Jacob. So you're going to Oregon! I can fix you up with what you need:" << endl;
    cout << "- A team of oxen to pull your wagon\n- Clothing for both Summer and Winter\n- Plenty of food for the trip\n- Ammunition for your rifels\n- Spare parts for your wagon" << endl;
    cout << endl;

    flag = true;
    float pounds;


    while(flag){
        //while they still want to be in the store 
        
        cout << "------------------------------------------------------------------" << endl;
        cout << "1. Oxen          " << store1.getPriceOfOxen()*(team1.getNumOxen()/2) << endl; //shows them how much of each product they have
        cout << "2. Food          " << store1.getPricePerPound()*team1.getPoundsOfFood() << endl;
        cout << "3. Clothing      " << store1.getCostPerSet()*team1.getSetsOfClothes() << endl;
        cout << "4. Ammunition    " << store1.getPriceOfAmmo()*(team1.getAmmo()/20) << endl;
        cout << "5. Spare Parts   " << store1.getCostPerSpare()*(wagon1.getXtraWagonTongues()+wagon1.getXtraWagonAxels()+wagon1.getXtraWagonWheels()) << endl;
        cout << "6. Exit Store    " << endl;
        cout << "------------------------------------------------------------------" << endl;
        cout << "Total Bill: " << store1.getBill() << endl;
        cout << endl;
        cout << "Your current balance: " << team1.getMoney() << endl;
        cout << endl;
        cout << "Which item would you like to buy? ";
        cin >> intChoice;

        if(intChoice == 1){ //if they chose one

            cout << "There are 2 oxen in a yoke; I reccomend at least 3 yoke. I charge $40 a yoke." << endl; //explain the oxen and ask how much they want to buy 
            cout << "How many do you want? ";
            cin >> intChoice;
            cout << endl;

            if((store1.getPriceOfOxen()*intChoice) > team1.getMoney()){ //if they don't have enough money, reject the transaction
                cout << "You don't have enough funds to pay for that" << endl;
            }

            else { //if they do
                team1.setNumOxen(intChoice*2); //set the number of oxen to the yoke * 2 (sinces there's 2 oxen in a yoke)
                team1.setMoney(team1.getMoney()-store1.getPriceOfOxen()*intChoice);
                store1.setBill(updateBill(team1,wagon1,store1)); //update the bill
            }
        }

        else if(intChoice == 2){ //if they chose 2, sell them food.. same as the oxen 
            cout << "I reccomend you take at least 200 pounds of food for each person in your family. I see that you have 5 people in all. You'll need flour, sugar, bacon, and coffee. My price is 20 cents a pound." << endl;
            cout << endl;
            cout << "How many pounds of food do you need? ";
            cin >> pounds; 
            cout << endl;

            if(store1.getPricePerPound()*pounds > team1.getMoney()){
                cout << "You don't have enough funds to pay for that" << endl;
            }

            else{
                team1.setPoundsOfFood(pounds);
                team1.setMoney(team1.getMoney()-store1.getPricePerPound()*pounds);
                store1.setBill(updateBill(team1,wagon1,store1));
            }
        }

        else if(intChoice == 3){ //if they chose 3, tell them clothes... same as oxen and food
            cout << "You'll need warm clothing in the mountains. I recommend taking at least 2 sets of clothes per person. Each set is $10." << endl;
            cout << endl;
            cout << "How many sets do you need? ";
            cin >> intChoice;
            cout << endl;

            if(store1.getCostPerSet()*intChoice > team1.getMoney()){
                cout << "You don't have enough funds to pay for that" << endl;
            }

            else{
                team1.setSetsOfClothes(intChoice);
                team1.setMoney(team1.getMoney()-store1.getCostPerSet()*intChoice);
                store1.setBill(updateBill(team1,wagon1,store1));
            }
        }

        else if(intChoice == 4){ //if they chose 4, sell them ammo... same as oxen, clothes, and food
            cout << "I sell ammunition in boxes of 20 bullets. Each box costs $2" << endl;
            cout << endl;
            cout << "How many boxes do you want? ";
            cin >> intChoice;
            cout << endl;

            if(store1.getPriceOfAmmo()*intChoice > team1.getMoney()){
                cout << "You don't have enough funds for that!" << endl;
            }

            else{
                team1.setAmmo(intChoice*20);
                team1.setMoney(team1.getMoney()-store1.getPriceOfAmmo()*intChoice);
                store1.setBill(updateBill(team1,wagon1,store1));
            }
        }

        else if(intChoice == 5){ //if they chose 5 sell them spare parts 
            cout << "It's a good idea to have a few spare parts for your wagon. Here are the prices: " << endl;
            cout << "Wagon Wheel - $10 Each\nWagon Axel - $10 Each\nWagon Tongue - $10 Each" << endl;
            cout << endl;
            for(int i = 0; i < 3; i++){
                if(i == 0){
                    cout << "How mnay wheels? ";
                    cin >> intChoice;
                    cout << endl;
                    if(store1.getCostPerSpare()*intChoice > team1.getMoney()){
                        cout << "You don't have enough funds for that" << endl;
                    }
                    else{
                        wagon1.setXtraWagonWheels(intChoice);
                        team1.setMoney(team1.getMoney()-store1.getCostPerSpare()*intChoice);
                        store1.setBill(updateBill(team1,wagon1,store1));
                    }
                }
                //split up each part into it's own question
                else if(i == 1){
                    cout << "How many axels? ";
                    cin >> intChoice;
                    cout << endl;
                    if(store1.getCostPerSpare()*intChoice > team1.getMoney()){
                        cout << "You don't have enough funds for that" << endl;
                    }
                    else{
                        wagon1.setXtraWagonAxels(intChoice);
                        team1.setMoney(team1.getMoney()-store1.getCostPerSpare()*intChoice);
                        store1.setBill(updateBill(team1,wagon1,store1));
                    }
                }
                else if(i == 2){
                    cout << "How many tongues? ";
                    cin >> intChoice;
                    cout << endl;
                    if(store1.getCostPerSpare()*intChoice > team1.getMoney()){
                        cout << "You don't have enought funds for that" << endl;
                    }
                    else{
                        wagon1.setXtraWagonTongues(intChoice);
                        team1.setMoney(team1.getMoney()-store1.getCostPerSpare()*intChoice);
                        store1.setBill(updateBill(team1,wagon1,store1));
                    }
                }
            }
        }
            else if(intChoice == 6){
                flag = false;
            }
    }

    cout << "Well then, you're ready to start! You have a long and difficult journey ahead of you. Good luck!" << endl;
    cout << endl;

    flag = true;

    while(flag){
        cout << "Independence" << endl;
        cout << team1.getMonth() << " " << team1.getDay() << ", " << team1.getYear() << endl;
        cout << "Press q to continue";
        cin >> charChoice;

        if(charChoice == 'q'){
            flag = false;
        }
    }

    flag = true;
    int landmarkCount = 0;


    while(flag){

        cout << "You may:" << endl;
        cout << "1. Continue on the trail\n2. Check supplies\n3. Stop to rest\n4. Quit" << endl;
        cout << endl;
        cout << "What do you choose? ";
        cin >> intChoice;

        cout << "Date: " << team1.getMonth() << " " << team1.getDay() << ", " << team1.getYear() << endl;
        cout << "Food: " << team1.getPoundsOfFood() << " pounds" << endl;
        cout << "Next Landmark: " << milesToLandmark[landmarkCount] << " Miles" << endl;
        cout << "Miles Traveled: " << team1.getMiles() << endl;
        cout << endl;

        if(intChoice == 1){
            takeTurn(team1,wagon1,store1,milesToLandmark,landMarkNames,count);
        }
    }



    
    
    
    /* Ask the "Leader" to enter his/her name;
       Ask the leader to enter the names of the other 4 people
       Create 5 player objects with the names of all the people;
       Add the player objects to the team object;
       Ask the leader if they want to visit the store;
       If yes, show the menu;
       Have an option to buy oxen, pounds of food, sets of clothes, ammo (all kept track in team)
       Keep track of the money by subtracting stuff bought at the store;
       Once the leader has bought everything, ask what day they would like to leave
       Once they Pick a day to leave, transition to leaving
       Start keeping track of miles and landmarks
       At certain landmarks ask them if they would like to rest or keep moving as well as buy things
       If they choose to rest increment the days without incrementing the miles traveled
       Randomly have theives come and take some of the stuff
       Also, when the team crosses the river, if it is 3ft deep or deeper, ask if they would like to take a ferry across
       If they don't choose the ferry, they could lose supplies */
}
