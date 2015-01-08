#include "Players.hpp"

#include "Human.hpp"

Players::Players(int n, bool humans, int ord)
  : nbPlayers(n), actual(0), order(ord){
  players = new Player *[n];

  players[0] = new Human();
  for(int i = 1; i < n; i++)
    if(humans)
      players[i] = new Human();
  // else
}

Player& Players::next(){
  actual = (actual + order) % nbPlayers;
  return *players[actual];
}

Player& Players::getActualPlayer(){
  return *players[actual];
}

void Players::reverseOrder(){
  order = -order;
}

int Players::getNbPlayers(){
  return nbPlayers;
}

int Players::getActualPlayerId(){
  return actual;
}

void Players::setActualPlayer(int i){
  if(i>=0 && i < nbPlayers)
    actual = i;
}

void Players::eliminer(int player){
  nbPlayers--;
  //Todo enlever player à la position "player"
}

void Players::ask(Action& action){
  cout << "Player " << actual << " : ";
  players[actual]->ask(action);
}

void Players::addTo(int i, Card& card){
  players[i]->add(card);
}

void Players::addTo(int i, const CardContainer& cards){
  players[i]->add(cards);
}

bool Players::emptyHand(int i){
  return players[i]->emptyHand();
}
