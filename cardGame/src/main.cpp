#include <iostream>
#include "Hand.hpp"
#include "CardContainer.hpp"
#include "FrenchSuit.hpp"
#include "FrenchRank.hpp"

using namespace std;

#include "Deck.hpp"
#include "FrenchCard.hpp"

int main(){
  cout << " -- Card Game -- " << endl;

  Deck<FrenchCard> d(1);
  Hand<FrenchCard> h;
  FrenchCard f1(Hearts, King);
  FrenchCard f2(Clubs, Queen);
  FrenchCard f3(Spades, Jack);

  cout<<"add et remove par unité"<<endl;
  h.add(f1);
  h.add(f2);
  h.add(f3);
  h.printHand();
  h.remove(f2);
  h.printHand();
  h.remove(1);
  h.printHand();



  cout<<"add et remove pas containeur"<<endl;
  Hand<FrenchCard> h2;
  FrenchCard *c = new FrenchCard [3];
  c[0]= f1;
  c[1]= f2;
  c[2]= f3;
  CardContainer<FrenchCard> xs(c, 3);
  h2.add(xs, xs.getIndice()); 
  h2.printHand();
  h2.add(xs, xs.getIndice()); 
  h2.printHand();
  
  int pos[]={5,1,4,8,9,2};
  FrenchCard *c2 = h2.remove(pos, 3);
  for (int i=0; i<3; i++)
    cout<<c2[i]<<" - ";
  cout<<"carte(s) supprimée(s)"<<endl;
  h2.printHand();

 FrenchCard *c3 = new FrenchCard [3];
  c[0]= f1;
  c[1]= f2;

  h2.remove(c3,2);
  h2.printHand();
  
  return 0;
}
