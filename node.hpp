#pragma once
#include <iostream>
using namespace std;

class node {
    string name;
    node* mother;
    node* fother;

    node(string name){
        this->name = name;
    }
    node(){
      cout<< "word"<<endl;
    }

    void setName(string name);
    void setMother(node* mother);
    void setFather(node* fother);


    string getName()
    {
        return name;
    }
    node* getMother()
    {
        return mother;
    }

    node* getFather()
    {
        return fother;
    }

    string toString(node n);

};