/************************************************
 ** File:    Driver.cpp

 ** Project: CMSC 341 Project 2, Fall 2016

 ** Author:  Steven Heckman
 ** Date:    10/19/16
 ** Section: 05
 ** E-mail:  heckman1@umbc.edu
 **
 **   This file is the main Driver file for project 2.

 **   This file will print no content to the console, but generate text in a results file.
 **   This driver will exit if not enough command line arguments are given.
 **   This driver takes in command line arguments and reads from given text files.
 **   This driver will set up and call all the required objects for the game.
 ***********************************************/
#include "Commodity.h"
#include "CommodityStore.h"
#include "Objective.h"
#include "Card.h"
#include "Player.h"
#include "Game.h"
#include <iostream>
#include <string>

using namespace std;

void printGreeting(std::ofstream& fileStream) //prints a very basic greeting to the text file.
{
    fileStream << "Steven Heckman, Section 5." << endl;
}
int main(int argc, char ** argv)
{
    if (argc !=5){
       cerr << "Not enough command line arguments!" << endl;
       exit(1);
    }
    string cardsFilename = argv[1];
    string commodityFilename = argv[2];
    string numPlayersS = argv[3];
    string strategyS = argv[4];
    int numPlayers = atoi(numPlayersS.c_str());
    int strategy = atoi(strategyS.c_str());
    ofstream results("results.txt");
    printGreeting(results);//prints a basic greeting.
    Game myGame = Game(cardsFilename, commodityFilename);//creates a game object
    myGame.printDrawPile(results);//prints the deck of cards
    Player::STRATEGY myStrategy = (Player::STRATEGY)strategy;//converting int to enum
    myGame.runSimulation(numPlayers, myStrategy);//simulating the game
    myGame.printResults(results);//printing the results of that game
    //cerr << MyStore.getCommodity("Beer")->getColor();
    results.close();//closing the results file
    return 0;
}
