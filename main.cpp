#include <iostream>
#include "FamilyTree.cpp"


int main()
{
    Tree * T = new Tree("Ohad");
    T->addFather("Ohad", "Tzvi");
    T->addMother("Ohad", "Tzipi");
    cout<< T->relation("Tzvi") << endl; 
    return 0;
}