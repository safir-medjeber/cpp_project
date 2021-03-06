#ifndef H_GAME_FACTORY
#define H_GAME_FACTORY

#include <iostream>
using namespace std;

#include "Game.hpp"

#include "Movement.hpp"

class GameFactory {
public:
  static const int nbChoice;
  static const string choice[];

  Game* createGame(Movement, Movement, Movement);

  friend ostream& operator<<(ostream&, GameFactory&);
};

#endif
