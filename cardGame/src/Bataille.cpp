#include "Bataille.hpp"
#include "Action.hpp"
#include "IllegalMovement.hpp"

#include <iostream>
using namespace std;

void Bataille::checkNumberOfPlayers(int nbPlayer){
  if(nbPlayer < 2)
    //throw IllegalNumberOfPlayers(nbPlayer, ">2");
    throw 444;
}

int Bataille::cardsPerPlayer(int nbPlayer){
  return deck.getSize()/nbPlayer;
}

void Bataille::printHeader(){
  cout << "-- Bataille --" << endl;
}

void Bataille::initPlayersHand(){

  int n = players.getNbPlayers();
  int cPP = cardsPerPlayer(n);

  for(int j = 0; j < cPP; j++)
    for(int i = 0; i < n; i++){
      FrenchCard& card = deck.pop();
      //      card.flip();
      players.addCard(i, card);
    }

}

void Bataille::first(){
  Action<FrenchCard> action;
  action.setTo(&discardPiles[players.getActualPlayerId()], CardContainer<FrenchCard>());
  players.ask(action);

  try{
    action.countMovingCards(1);
    action.movingCardsFromTop();
    action.apply();
  }
  catch(IllegalMovement e){
    cout << e.what() << endl;
    first();
  }
}

void Bataille::checkBataille(){
  FrenchCard highest = discardPiles[0].look();
  int bataille = 0;
  int pos = 0;

  for(int i = 1; i < players.getNbPlayers(); i++){
    FrenchCard c = discardPiles[i].look();
    if(highest < c){
      bataille = 0;
      highest = c;
      pos = i;
    }
    else if(c == highest)
      bataille ++;
  }

  if (bataille > 0){
    cout << "---Bataille---" <<endl;
    play(2);
  }
  else
    cout << "Player " << pos << " take all cards" << endl;

  giveAllTo(pos);
}

void Bataille::giveAllTo(int k){
  for(int i = 0; i < players.getNbPlayers(); i++)
    players.addCards(k, discardPiles[i].removeAll());
}

void Bataille::play(int n){
  players.setActualPlayer(0);

  do{
    for(int i = 0; i < n; i++)
      first();
    players.next();
  }
  while (players.getActualPlayerId() != 0);

  for(int i = 0; i < players.getNbPlayers(); i++){
    cout << discardPiles[i];
    if(i+1 < players.getNbPlayers())
      cout << " vs ";
  }
  cout << endl;
  checkBataille();
}

void Bataille::play(){
  play(1);
}
