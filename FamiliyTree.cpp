#include "FamilyTree.hpp"
#include "node.hpp"

using namespace family;

Tree::Tree(string name)
{
   node::node n ();
    node::n->name=name;
}

Tree& Tree::addFather(string child,string father)
{
    return *this;
}
Tree& Tree::addMother(string child, string mother)
{
    return *this;
}

string Tree::relation(string name)
{
    return "";
}

string Tree::find(string name)
{
    return "";

}

void Tree::display()
{

}
        
void Tree::remove(string name)
{

}

