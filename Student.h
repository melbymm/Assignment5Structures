#include <iostream>
#include "Person.h"
using namespace std;

class student: public person{
public:
  student();
  student(int a, string b, string c, string d, double e, int f);


  string major = "";
  double gpa = 0.0;
  int advisor = 0;
  void printstud();
  void changeadvisor(int id);

  void getadvisor();
};

student :: student(int a, string b, string c, string d, double e, int f):person(a, b, c){
  id = a;
  name = b;
  level = c;
  major = d;
  gpa = e;
  advisor = f;
}
void student :: printstud(){
  cout << id << endl;
  cout << name << endl;
  cout << level << endl;
  cout << major << endl;
  cout << gpa << endl;
  cout << advisor << endl;
}
void student :: changeadvisor(int id){
  advisor = id;
}
