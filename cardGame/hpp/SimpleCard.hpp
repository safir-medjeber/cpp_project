#ifndef H_SIMPLE_CARD
#define H_SIMPLE_CARD

#include <iostream>
#include "Card.hpp"

using namespace std;

template <typename Suit, typename Rank>
class SimpleCard : public Card {
private:
  bool hidden;
  Suit suit;
  Rank rank;
protected:
  virtual int getValue() const { return rank; }
  virtual int getRealValue() const { return rank * suit; }
public:
  SimpleCard() {}
  SimpleCard(Suit s, Rank r, bool hide = false)
    : suit(s), rank(r), hidden(hide) {}

  virtual bool isHidden()  const {return hidden; }
  virtual bool isVisible() const {return !hidden;}
  virtual void flip() { hidden = !hidden; };

  virtual ostream& print(ostream &os) const { return os << rank << suit;}

};

#endif