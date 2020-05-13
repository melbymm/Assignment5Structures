#include <iostream>
#include "Student.h"
#include "linkedList.h"
using namespace std;

class faculty: public person{
public:
  faculty(int a, string b, string c, string d);

  string depart = "";
  int* studids;
  int getid();
  void printstud();
  naiveList<int> *studentlist;
  void insertstud(int nomid);
};

faculty :: faculty(int a, string b, string c, string d): person(a, b, c){
  id = a;
  name = b;
  level = c;
  depart = d;
  studentlist = new naiveList<int>();

}
int faculty::getid(){
  return id;
}
void faculty :: printstud(){
  cout << id << endl;
  cout << name << endl;
  cout << level << endl;
  cout << depart << endl;

}
void faculty :: insertstud(int nomid){
  //cout << idnum << endl;
  studentlist->insertBack(nomid);
}
