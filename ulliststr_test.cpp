/* Write your test code for the ULListStr in this file */
#include "ulliststr.h"
#include <iostream>
using namespace std;


int main(int argc, char* argv[])
{
  ULListStr dat;
  // Test pop_back and pop_front when dat is empty
  dat.pop_back();
  dat.pop_front();
  // Test push_front when dat is empty
  dat.push_front("10");
  // Test push_front when a new node does not need to be created
  dat.push_front("9");
  dat.push_front("8");
  dat.push_front("7");
  dat.push_front("6");
  dat.push_front("5");
  dat.push_front("4");
  dat.push_front("3");
  dat.push_front("2");
  dat.push_front("1");
  // Test push_back when a new node must be created
  dat.push_back("11");
  // Test push_back when a new node does not need to be created
  dat.push_back("12");
  dat.push_back("13");
  dat.push_back("14");
  dat.push_back("15");
  dat.push_back("16");
  dat.push_back("17");
  dat.push_back("18");
  dat.push_back("19");
  dat.push_back("20");
  // Test push_front when a new node must be created
  dat.push_front("30");
  dat.push_front("31");
  dat.push_front("0"); 
  // Test front
  cout << dat.front() << endl; // Should output 0
  // Test get
  cout << dat.get(1) << endl; // Should output 31
  // Test back
  cout << dat.back() << endl; // Should output 20
  // Test size
  int x = dat.size();
  cout << x << endl; // Should output 23
  // Test pop_back and pop_front when nodes do and do not need to be deleted
  for(int i = 0; i<10; i++){
    dat.pop_back();
    dat.pop_front();
  }
  x = dat.size();
  cout << x << endl; // Should output 3
  dat.pop_front();
  dat.pop_front();
  //Test pop_front when dat.size()==1
  dat.pop_front();
  cout << dat.size() <<endl; // Should output 0
  // Test push_back when dat is empty
  dat.push_back("0");
  dat.push_back("1");
  dat.push_back("2");
  dat.push_back("3");
  dat.push_back("4");
  dat.push_back("5");
  dat.push_back("6");
  dat.push_back("7");
  dat.push_back("8");
  dat.push_back("9");
  dat.push_back("11");

  // Should output values 0 - 11
  for(int i = 0; i<11; i++){
    cout << dat.get(i) << " ";
  }
  cout << endl;
  // Test pop_back when dat.size() == 1
  for(int i = 0; i<11; i++){
    dat.pop_back();
  }
  dat.clear();
  return 0;
}