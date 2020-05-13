//#include "Student.h"
//#include "Faculty.h"
#include<fstream>
#include <iostream>
using namespace std;
template<class V>
class TreeNode{
  public:
  TreeNode<V>();
  TreeNode<V>(V k, int idnumber);
  ~TreeNode(); //virtual destructor needed for template class

  int key;
  TreeNode<V> *left;
  TreeNode<V> *right;
  int theid;
  V people;
  string namer;
  string levelgetter;
  string majorgetter;
  double gpagetter = 0.0;
  int advgetter = 0;


};
template<class V>
TreeNode<V>::TreeNode(){
  key = 0;
  left = NULL;
  right = NULL;
}
template<class V>
TreeNode<V>::TreeNode(V k, int idnumber){
  key = idnumber;
  people = k;
  left = NULL;
  right = NULL;
}

template <class V>
class BST{
public:
  BST<V>();
  ~BST<V>();
  void insert(V value);
  bool search(int idnumber);
  V deleteNode(int idnumber);
  bool isEmpty();
  TreeNode<V>* getSuccessor(TreeNode<V> *d);
  TreeNode<V>* getMax();
  void printTreeStud(TreeNode<V> *node);
  void printTreeFac(TreeNode<V> *node);
  void printStud(int idnumber);
  void printFac(int idnumber);
  TreeNode<V> *root;
  void getadvisor(int idnumber);
  void printadvisees(int idnumber);
  void extraadvisees(int stud, int fac);
  void deleteadvisees(int stud, int fac);
  int changeadv(int stud, int fac);
  void switchadv(int stud, int fac);
  int changeadvBack(int stud, int fac);
  void switchadvBack(int stud, int fac);
  void removeadvisee(int stud, int fac);
  int oldid;
  V getPerson(int num);
  string finalprintfac(TreeNode<V> *node);
  string finalprintstud(TreeNode<V> *node);
  std:: ofstream ofs;
};
template<class V>
BST<V>::BST(){
  root = NULL;
}
template<class V>
void BST<V>::printTreeStud(TreeNode<V> *node){
  if(node == NULL){
    return;
  }
  printTreeStud(node->left);
  cout << node->key << endl;
  cout << node->people->name << endl;
  cout << node->people->level << endl;
  cout << node->people->major << endl;
  cout << node->people->gpa << endl;
  cout << node->people->advisor << endl;
  printTreeStud(node->right);
}
template<class V>
void BST<V>::printTreeFac(TreeNode<V> *node){
  if(node == NULL){
    return;
  }
  printTreeFac(node->left);
  cout << node->key << endl;
  cout << node->people->name << endl;
  cout << node->people->level << endl;
  cout << node->people->depart << endl;
  printTreeFac(node->right);
}

template<class V>
string BST<V>::finalprintstud(TreeNode<V> *node){
  string temp ;
  ofs.open("studentTable.txt");
  finalprintstud(node->left);
  ofs << node->key ;
  ofs << node->people->name ;
  ofs << node->people->level ;
  ofs << node->people->major;
  ofs << to_string(node->people->gpa);
  ofs << to_string(node->people->advisor);
  finalprintstud(node->right);
  ofs.close();

  return temp;

}
template<class V>
string BST<V>::finalprintfac(TreeNode<V> *node){
  string temp ;
  ofs.open("facultyTable.txt");
  finalprintfac(node->left);
  ofs<<node->key;
  ofs << node->people->name;
  ofs << node->people->level;
  ofs << node->people->depart;
  finalprintfac(node->right);
  ofs.close();

  return temp;
}
template<class V>
void BST<V>::printStud(int idnumber){
  TreeNode<V> *current = root;
  while(true){
    if(idnumber < current -> key){
    current  = current -> left;
  }
  else if(idnumber > current -> key){
    current = current -> right;
  }
  else{
    cout << current->key << endl;
    cout << current->people->name << endl;
    cout << current->people->level << endl;
    cout << current->people->major << endl;
    cout << current->people->gpa << endl;
    cout << current->people->advisor << endl;

    break;
  }
}
}
template<class V>
void BST<V>::printFac(int idnumber){
  TreeNode<V> *current = root;
  while(true){
    if(idnumber < current -> key){
    current  = current -> left;
  }
  else if(idnumber > current -> key){
    current = current -> right;
  }
  else{
    cout << current->key << endl;
    cout << current->people->name << endl;
    cout << current->people->level << endl;
    cout << current->people->depart << endl;

    break;
  }
}
}
template<class V>
void BST<V>::printadvisees(int idnumber){
  TreeNode<V> *current = root;
  while(true){
    if(idnumber < current -> key){
    current  = current -> left;
  }
  else if(idnumber > current -> key){
    current = current -> right;
  }
  else{
    current->people->studentlist->printList();
    break;
  }
}
}
template<class V>
void BST<V>::extraadvisees(int stud, int fac){
  TreeNode<V> *current = root;
  while(true){
    if(fac < current -> key){
    current  = current -> left;
  }
  else if(fac > current -> key){
    current = current -> right;
  }
  else{
    current->people->studentlist->insertBack(stud);
    break;
  }
}
}
template<class V>
void BST<V>::deleteadvisees(int stud, int fac){
  TreeNode<V> *current = root;
  while(true){
    if(fac < current -> key){
    current  = current -> left;
  }
  else if(fac > current -> key){
    current = current -> right;
  }
  else{
    current->people->studentlist->removeBack(stud);
    break;
  }
}
}

template<class V>
void BST<V>::getadvisor(int idnumber){
  TreeNode<V> *current = root;
  int temp;
  while(true){
    if(idnumber < current -> key){
    current  = current -> left;
  }
  else if(idnumber > current -> key){
    current = current -> right;
  }
  else{
    cout << current->people->advisor << endl;
    temp = current->people->advisor;

    break;
  }
}
}

template<class V>
TreeNode<V>* BST<V>::getMax(){
  TreeNode<V> *curr = root;
  if(root == NULL){
    return NULL;
  }
  while(curr->right != NULL){
    curr = curr->right;
  }
  return curr;
}
template<class V>
bool BST<V>::isEmpty(){
  return (root == NULL);
}
template<class V>
void BST<V>::insert(V value){
  TreeNode<V> *node = new TreeNode<V>(value, value->id);

  if(isEmpty()){
    root = node;
  }
  else{
    TreeNode<V> *curr = root;
    TreeNode<V> *parent;

    while(true){
      parent = curr;
      if(value->id < curr->key){
        curr = curr -> left;
        if(curr == NULL){
          parent->left = node;
          break;
        }

      }
      else{
        curr = curr->right;
        if(curr == NULL){
          parent->right = node;
          break;
        }
      }
    }
  }
}
template<class V>
bool BST<V>::search(int idnumber){
  if(isEmpty()){
    return false;
  }
  else{
    TreeNode<V> *current = root;

    while(current->key != idnumber){
      if(idnumber < current -> key){
        current  = current -> left;
      }
      else{
        current = current -> right;
      }
      if(current == NULL){
        return false;
      }
    }
  }
  return true;
}
template<class V>
V BST<V>::deleteNode(int idnumber){
  if(isEmpty()){
    cout << "Empty " << endl;
  }
  V temp;
  TreeNode<V> *parent = root;

  TreeNode<V> *current = root;
  bool isleft = true;

  while(current->key != idnumber){
    parent = current;
    if(idnumber<current->key){
      isleft = true;
      current = current -> left;

    }
    else{
      isleft == false;
      current = current ->right;
    }
    if(current == NULL){
      cout << "Could not perform" << endl;
      break;
    }
  }
  if(current->left == NULL && current ->right == NULL){
    if(current == root){
      temp = root->people;
      root = NULL;

    }
    else if(isleft){
      temp = parent->left->people;
      parent->left = NULL;
    }
    else{
      temp = parent->right->people;
      parent ->right = NULL;
    }
  }
  else if(current->right == NULL){
    if(current == root){
      root = current->left;
    }
    else if(isleft){
      parent->left == current->left;
    }
    else{
      parent ->right == current->left;
    }
  }
  else if(current->left == NULL){
    if(current == root){
      root = current->right;
    }
    else if(isleft){
      parent->left == current->right;
    }
    else{
      parent ->right == current->right;
    }
  }
  else{
    TreeNode<V> *successor = getSuccessor(current);
    if(current == root){
      root = successor;
    }
    else if(isleft){
      parent -> left = successor;
    }
    else{
      parent -> right = successor;
    }
    successor ->left = current -> left;

  }
  return temp;
}
template<class V>
TreeNode<V>* BST<V>::getSuccessor(TreeNode<V> *d){
  TreeNode <V>*current = d->right;
  //successor parent
  TreeNode<V> *sp = d;
  TreeNode <V>*successor = d;

  while(current != NULL){
    sp = successor;
    successor = current;

    current = current->left;
  }
  if(successor != d->right){
    sp->left = successor -> right;
    successor->right = d->right;
  }
  return successor;
}
template<class V>
int BST<V>::changeadv(int stud, int fac){
  TreeNode<V> *current = root;
  while(true){
    if(fac < current -> key){
    current  = current -> left;
  }
  else if(fac > current -> key){
    current = current -> right;
  }
  else{
    int temp;
    temp = current->people->studentlist-> removeAtPos(current->people->studentlist->search(stud));
    if(getSuccessor(current)!=NULL){
      current = getSuccessor(current);
      current->people->studentlist->insertBack(temp);
    }
    else if(current->left !=NULL){
      current = current->left;
      current->people->studentlist->insertBack(temp);
    }
    else if(current->right!=NULL){
      current = current->right;
      current->people->studentlist->insertBack(temp);
    }
    else{
      cout << "No other advisors" << endl;
    }
    return current->key;
  }
}
}
template<class V>
void BST<V>::switchadv(int stud, int fac){
  TreeNode<V> *current = root;
  while(true){
    if(stud < current -> key){
    current  = current -> left;
  }
  else if(stud > current -> key){
    current = current -> right;
  }
  else{
    if(getSuccessor(current)!=NULL){
      current->people->advisor = getSuccessor(current)->people->advisor;

    }
    else if(current->left !=NULL){
      current->people->advisor = current->left->people->advisor;

    }
    else if(current->right!=NULL){
      current->people->advisor = current->right->people->advisor;
    }
    break;
  }
}
}

template<class V>
int BST<V>::changeadvBack(int stud, int fac){
  TreeNode<V> *current = root;
  int temp = current->people->studentlist-> removeAtPos(current->people->studentlist->search(stud));
  while(true){
    if(fac < current -> key){
    current  = current -> left;
  }
  else if(fac > current -> key){
    current = current -> right;
  }
  else{
    current ->people->studentlist->insertBack(stud);
    return current ->key;
  }
}
}
template<class V>
void BST<V>::switchadvBack(int stud, int fac){
  TreeNode<V> *current = root;
  while(true){
    if(stud < current -> key){
    current  = current -> left;
  }
  else if(stud > current -> key){
    current = current -> right;
  }
  else{
    current -> people -> advisor = fac;
    break;
  }
}
}
template<class V>
V BST<V>::getPerson(int num){
  TreeNode<V> *current = root;
  while(true){
    if(num < current -> key){
    current  = current -> left;
  }
  else if(num > current -> key){
    current = current -> right;
  }
  else{
    return current->person;
  }
}
}
