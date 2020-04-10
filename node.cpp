#include <iostream>
#include "node.hpp"

using namespace std;


void node::setName(string name)
{
    this->name=name;
}

void node::setMother(node* mother)
 {
    this->mother = mother;
 }
void node::setFather(node* fother)
{
    this->fother = fother;
}

string node::toString(node n)
{
    printf("name: ");
}