#include "TreeNode.h"
#include "Faculty.h"
#include "stackpractice.h"
//#include "Student.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv){
  BST<faculty*> *b = new BST<faculty*>();
  BST<student*> *t = new BST<student*>();
  /*faculty *f = new faculty(222,"Steve", "Professor", "CompSci");
  faculty *a = new faculty(282, "John", "TA", "History");
  b->insert(f);
  b->insert(a);
  b->printTree(b->root);*/
  string inputid;
  string studidstring;
  string studgpastring;
  string studadvisorstring;
  string input = "";
  string wholeLine;
  stringstream sst;
  string oneword;
  string thename;
  string thelevel;
  string thedepart;
  int idnum = 0;
  int numcount = 0;
  int studid = 0;
  string studmajor;
  double studgpa = 0;
  string studlevel;
  string studname;
  int studadvisor = 0;
  int studnum = 0;
  int* studarray;
  int* newarray;
  int numofstudents = 0;
  int numoffac = 0;
  int count = 0;
  int adviseenum = 0;
  int idadvisee = 0;
  ifstream ifs;

  int choice = 0;
  GenStack<int> *g = new GenStack<int>[5];
  GenStack<int> *lastchoice = new GenStack<int>[5];
  GenStack<int> *FacultyGiver = new GenStack<int>[5];
  GenStack<int> *FacultyTaker = new GenStack<int>[5];
  GenStack<int> *StudentGiven = new GenStack<int>[5];


  GenStack<faculty*> *given = new GenStack<faculty*>[5];
    GenStack<faculty*> *taken = new GenStack<faculty*>[5];
  GenStack<faculty*> *facused = new GenStack<faculty*>[5];
  GenStack<student*> *used = new GenStack<student*>[5];
  ifs.open("facultyTable.txt");
  if(ifs.is_open()){
    ifs>>numoffac;
    getline(ifs, oneword);

    for(int i = 0; i < numoffac; ++i){
      cout << count << endl;
        ifs >> idnum;
        getline(ifs, oneword);
        getline(ifs,thename);
        getline(ifs,thelevel);
        getline(ifs,thedepart);
        ifs>>adviseenum;
        getline(ifs,oneword);
      faculty *f = new faculty(idnum, thename, thelevel, thedepart);


      for(int j = 0; j<adviseenum;++j){
        ifs>>idadvisee;
        cout << idadvisee << endl;
        f->insertstud(idadvisee);

        getline(ifs,oneword);
      }
      //cout << f->id << endl;
      //getline(ifs,oneword);
      b-> insert(f);
  //  b->printTree(b->root);
  }
}

    //b->printTree(b->root);

  //b->printTree(b->root);
  ifs.close();

  ifs.open("studentTable.txt");
  count = 0;
  if(ifs.is_open()){
    ifs >> numofstudents;
    getline(ifs,oneword);
    for(int i = 0; i < numofstudents; ++i){
      //cout << "hi" << endl;
      if(count == 0){
        ifs >> studid;
        getline(ifs,oneword);
        cout << studid << endl;
        count++;
      }
      if(count == 1){
        getline(ifs,studname);
        cout << studname << endl;
        count ++;
      }
      if(count == 2){
        getline(ifs,studlevel);
        cout << studlevel << endl;
        count++;
      }
      if(count == 3){
        getline(ifs,studmajor);
        cout << studmajor << endl;
        count++;
      }
      if(count == 4){
        ifs >> studgpa;
        getline(ifs,oneword);
        cout << studgpa << endl;
        count++;
      }
      if(count == 5){
        ifs >> studadvisor;
        getline(ifs,oneword);
        cout << studadvisor << endl;

        //cout << "Huh" << endl;
        count=0;
      }
      student *s = new student(studid,studname,studlevel,studmajor,studgpa,studadvisor);
      t->insert(s);
  }
}
  ifs.close();

  while(true){
      //t->printTree(t->root);
      cout << "Menu:" << endl;
      cout <<"" <<  endl;
      cout << "1: Print all students and their information (sorted by ascending id #)" << endl;
      cout << "2: Print all faculty and their information (sorted by ascending id #)" << endl;
      cout << "3: Find and display student information given the students id" << endl;
      cout << "4: Find and display faculty information given the faculty id " << endl;
      cout << "5: Given a student’s id, print the name and info of their faculty advisor" << endl;
      cout << "6: Given a faculty id, print ALL the names and info of his/her advisees." << endl;
      cout << "7: Add a new student" << endl;
      cout << "8: Delete a student given the id" << endl;
      cout << "9: Add a new faculty member" << endl;
      cout << "10: Delete a faculty member given the id." << endl;
      cout << "11: Change a student’s advisor given the student id and the new faculty id" << endl;
      cout << "12: Remove an advisee from a faculty member given the ids" << endl;
      cout << "13: Rollback" << endl;
      cout << "14: Exit" << endl;

      cin >> input;

      if(input == "1"){
        t->printTreeStud(t->root);
      }
      else if (input == "2"){
        b->printTreeFac(b->root);
      }
      else if(input == "3"){
        cout << "What id number?: " << endl;
        cin >> inputid;
        if(t->search(stoi(inputid))){
          t->printStud(stoi(inputid));
        }

      }
      else if (input == "4"){
        cout << "What id number?: " << endl;
        cin >> inputid;
        if(b->search(stoi(inputid))){
          b->printFac(stoi(inputid));
        }
      }
      else if (input == "5"){
        cout << "What id number?: " << endl;
        cin >> inputid;
        if(t->search(stoi(inputid))){
          t->getadvisor(stoi(inputid));
        }
      }
      else if (input == "6"){
        cout << "What id number?: " << endl;
        cin >> inputid;
        if(b->search(stoi(inputid))){
          b->printadvisees(stoi(inputid));

        }
      }
      else if (input == "7"){
        lastchoice->push(stoi(input));
        cout << "ID number: " << endl;
        cin >> studidstring;
        studid = stoi(studidstring);
        cout << "Name: " << endl;
        cin >> studname;


        cout << "Grade level: " << endl;
        cin >> studlevel;
        cout << "Major: " << endl;
        cin >> studmajor;
        cout << "GPA: " << endl;
        cin >> studgpastring;
        studgpa = stod(studgpastring);
        cout << "Advisor: " << endl;
        cin >> studadvisorstring;
        studadvisor = stoi(studadvisorstring);
        b->extraadvisees(studid,studadvisor);
        student *j = new student(studid,studname,studlevel,studmajor,studgpa,studadvisor);
        t->insert(j);
        g->push(studid);

      }
      else if (input == "8"){
        lastchoice->push(stoi(input));
        cout << "ID number: " << endl;
        cin >> studidstring;
        studid = stoi(studidstring);
        used->push(t->deleteNode(studid));
      }
      else if (input =="9"){
        lastchoice->push(stoi(input));
        cout << "ID number:" << endl;
        cin >> inputid;
        idnum = stoi(inputid);
        cout << "Name: " << endl;
        cin >> thename;
        cout << "Level: " << endl;
        cin >> thelevel;
        cout << "Department: " << endl;
        cin >> thedepart;
        faculty *u = new faculty(idnum,thename,thelevel,thedepart);
        b->insert(u);

        g->push(idnum);

      }
      else if (input == "10"){
        lastchoice->push(stoi(input));
        cout << "ID number: " << endl;
        cin >> inputid;
        idnum = stoi(inputid);

        facused->push(b->deleteNode(idnum));
      }

      else if (input == "11"){
        lastchoice->push(stoi(input));
        cout << "Student ID: " << endl;
        cin >>studidstring;
        studid = stoi(studidstring);
        cout << "Faculty ID: " << endl;
        cin >> inputid;
        idnum = stoi(inputid);
        FacultyGiver->push(b->changeadvBack(studid,idnum));
        t->switchadvBack(studid,idnum);
        StudentGiven->push(studid);

        FacultyTaker->push(idnum);
      }
      else if (input == "12"){
        lastchoice->push(stoi(input));
        cout << "Student ID: " << endl;
        cin >>studidstring;
        studid = stoi(studidstring);
        cout << "Faculty ID: " << endl;
        cin >> inputid;
        idnum = stoi(inputid);
        FacultyTaker->push(b->changeadv(studid,idnum));
        t->switchadv(studid,idnum);
        StudentGiven->push(studid);
        FacultyGiver->push(idnum);
      }
      else if (input == "13"){
        if(lastchoice->pop() == 7){
          t->deleteNode(g->pop());
        }
        else if(lastchoice->pop() == 8){
          student *j = used->pop();
          t->insert(j);
          g->push(studid);
        }
        else if(lastchoice->pop() == 9){
          b->deleteNode(g->pop());
        }
        else if(lastchoice->pop() == 10){
          faculty *u = facused->pop();
          b->insert(u);
          g->push(idnum);
        }
        else if(lastchoice->pop() == 11){
          cout << "hi" << endl;
          int temp1 = FacultyGiver->pop();
          int temp2 = StudentGiven->pop();
          FacultyTaker->pop();
          b->changeadv(temp2,temp1);
          t->switchadv(temp2,temp1);
        }
        else if(lastchoice->pop() == 12){
          int temp1 = FacultyTaker->pop();
          int temp2 = StudentGiven->pop();

          FacultyGiver->pop();
          b->changeadvBack(studid,idnum);
          t->switchadvBack(studid,idnum);
        }
      }
      else if (input == "14"){
        t->finalprintstud(t->root);
        b->finalprintfac(b->root);
      /*  cout << "Students: " << endl;
        t->printTreeStud(t->root);
        cout  << "Faculty: " << endl;
        b->printTreeFac(b->root);*/

        exit(1);
      }
}
}


/*else if(count == 4){

  //cout << oneword << endl;
  studnum = stoi(oneword);
  numcount++;
  studarray = new int[numcount];
  studarray[numcount-1] = studnum;

  count++;
}
else{

  studnum = stoi(oneword);
  cout << studnum << endl;
  numcount++;
  newarray = new int[numcount];
  newarray[numcount] = studnum;
  for(int i = 0; i < numcount; ++i){
    newarray[i] = studarray[i];
  }
  delete studarray;
  studarray = new int[numcount];
  for(int i = 0; i < numcount; ++i){
    studarray[i] = newarray[i];

  }
  for(int i = 0; i < numcount; ++i){
    cout << studarray[i] << endl;
  }
  delete newarray;
  //count ++;
}*/
