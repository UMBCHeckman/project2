#ifndef PLAYER_CPP
#define PLAYER_CPP
/************************************************
 ** File:    Player.cpp

 ** Project: CMSC 341 Project 2, Fall 2016

 ** Author:  Steven Heckman
 ** Date:    10/19/16
 ** Section: 05
 ** E-mail:  heckman1@umbc.edu
 **
 **   This file generates a "Player" object.
 **
 **   This file contains constructors functions.
 **   This file will take in the strategy the players are playing with, their cards, and their objectives they pick based on their strategy.
 **
 ***********************************************/
#include "Player.h"
#include <iostream>
#include <queue>

using namespace std;

Player::Player()//default constructor
{
    //intentionally blank
}
Player::Player(string name)//non default constructor
{
    m_sName = name;
}
string Player::getName()const//get the players name. Should be "Player " followed the number of what player they are.
{
    return m_sName;
}
int Player::getScore()const//get that players score after they've selected their objectives.
{
    return m_score;
}
void Player::addCard(Card*card)//add cards to their hand
{
    m_cards.push(card);
}
int Player::calculateScore(Player::STRATEGY strategy)//calculate the score based on the objectives based on their strategy.
{
    int score = 0;
    queue<Card*> cardCopy = m_cards;//cardCopy can be popped in a for loop using m_cards.size()
    for(unsigned int i = 0; i < m_cards.size(); i++){//for the amount of cards in hand
        switch(strategy){//aw yea switch statements
        case 0: //BEST_PAYOFF
            m_objectives.push(cardCopy.front()->getBestPayoff());
            cardCopy.pop();
            break;
        case 1://FIRST_ALPHA_DESTINATION
            m_objectives.push(cardCopy.front()->getFirstAlphaDestination());
            cardCopy.pop();
            break;
        case 2://COLOR_PURPLE
            m_objectives.push(cardCopy.front()->getByColor((Commodity::COLOR)(strategy-2)));
            cardCopy.pop();
            break;
        case 3://COLOR_RED
            m_objectives.push(cardCopy.front()->getByColor((Commodity::COLOR)(strategy-2)));
            cardCopy.pop();
            break;
        case 4://COLOR_ORANGE
            m_objectives.push(cardCopy.front()->getByColor((Commodity::COLOR)(strategy-2)));
            cardCopy.pop();
            break;
        case 5://COLOR_BLACK
            m_objectives.push(cardCopy.front()->getByColor((Commodity::COLOR)(strategy-2)));
            cardCopy.pop();
            break;
        case 6://COLOR_GREEN
            m_objectives.push(cardCopy.front()->getByColor((Commodity::COLOR)(strategy-2)));
            cardCopy.pop();
	    break;
        case 7://COLOR_BROWN
            m_objectives.push(cardCopy.front()->getByColor((Commodity::COLOR)(strategy-2)));
            cardCopy.pop();
            break;
        default://should never happen.
            cerr << "I didn't implement that strategy, or that strategy is illegal. Either way, we're done here." << endl;//NO SECRET TECH
            exit(1);
        }
    }
    queue<Objective*> ObjectiveCopy = m_objectives;
    for(unsigned int i = 0; i < m_objectives.size(); i++){//now that we have out objectives we can find our payoff
        score += (ObjectiveCopy.front()->getPayoff());
        ObjectiveCopy.pop();
    }
    m_score = score;
    return score;
}
void Player::printResult(std::ofstream& fileStream)//print the results of the players playing
{
    int startSize = m_objectives.size();
    for(int i = 0; i < startSize; i++){
        m_objectives.front()->printObjective(fileStream);
        m_objectives.pop();
    }
    fileStream << "Score: " << m_score << endl;
}
#endif // PLAYER_CPP
