#include <iostream>
#include <cstddef>
#include "split.h"


using namespace std;

int main(){
  Node* in = new Node(1, NULL);
  Node* evens = NULL;
  Node* odds = NULL;
  in->next = new Node(2, NULL);
  in->next->next = new Node (3, NULL);
  in->next->next->next = new Node(5, NULL);
  in->next->next->next->next = new Node(7, NULL);
  split(in, odds, evens);
  Node* temp;
  temp = odds;
  while(temp != NULL){
    cout<<temp->value;
    temp = temp->next;
  }
  cout<< endl;
  temp = evens;
  while(temp != NULL){
    cout<<temp->value;
    temp = temp->next;
  }
  cout<< endl;

  
  while(evens != NULL){
    temp = evens;
    evens = evens->next;
    delete temp;
  }
 
  while(odds != NULL){
    temp = odds;
    odds = odds->next;
    delete temp;
  }
  return 0;
}