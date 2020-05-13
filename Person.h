#include <iostream>

using namespace std;

class person{
public:
  person(int a, string b, string c);
  int id = 0;
  string name = "";
  string level = "";

};

person::person(int a, string b, string c){
  id = a;
  name = b;
  level = c;
}
