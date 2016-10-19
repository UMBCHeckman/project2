#ifndef PLAYER_CPP
#define PLAYER_CPP
#include "Player.h"
#include <iostream>
#include <queue>

using namespace std;

Player::Player()
{
    //intentionally blank
}
Player::Player(string name)
{
    m_sName = name;
}
string Player::getName()const
{
    return m_sName;
}
int Player::getScore()const
{
    return m_score;
}
void Player::addCard(Card*card)
{
    m_cards.push(card);
}
int Player::calculateScore(Player::STRATEGY strategy)
{
    int score = 0;
    queue<Card*> cardCopy = m_cards;
    for(int i = 0; i < m_cards.size(); i++){
        switch(strategy){
        case 0: //BEST_PAYOFF
            m_objectives.push(cardCopy.front()->getBestPayoff());
            cardCopy.pop();
        case 1://FIRST_ALPHA_DESTINATION
            m_objectives.push(cardCopy.front()->getFirstAlphaDestination());
        default:
            cerr << "I didn't implement that strategy, or that strategy is illegal. Either way, we're done here." << endl;
            exit(1);
        }
    }
    queue<Objective*> ObjectiveCopy = m_objectives;
    for(int i = 0; i < m_objectives.size(); i++){
        score += (ObjectiveCopy.front()->getPayoff());
        ObjectiveCopy.pop();
    }
    m_score = score;
    return score;
}
void Player::printResult(std::ofstream& fileStream)
{
    int startSize = m_objectives.size();
    for(int i = 0; i < startSize; i++){
        m_objectives.front()->printObjective(fileStream);
        m_objectives.pop();
    }
    fileStream << "Score: " << m_score << endl;
}
#endif // PLAYER_CPP
