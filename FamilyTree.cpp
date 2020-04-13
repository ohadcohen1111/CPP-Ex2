#include "FamilyTree.hpp"

using namespace family;
static int rel = 0;

Tree::Tree(string name)
{
    this->name = name;
    this->father = NULL;
    this->mother = NULL;
}

Tree& Tree::addFather(string child,string father)
{
    if(this->name == child)
    {
        this->father = new Tree(father);
        return *this;
    }
    else if(this->father == NULL && this->mother == NULL)
    {
        return *this;
    }
    else if(this->mother == NULL)
    {
        this->father->addFather(child, father);
    }
    else if(this->father == NULL)
    {
        this->mother->addFather(child, father);
    }
    else
    {
        this->father->addFather(child, father);
        this->mother->addFather(child, father);
    } 
}


Tree& Tree::addMother(string child,string mother)
{
    if(this->name == child)
    {
        this->mother = new Tree(mother);
        return *this;
    }
    else if(this->father == NULL && this->mother == NULL)
    {
        return *this;
    }
    else if(this->mother == NULL)
    {
        this->father->addMother(child, mother);
    }
    else if(this->father == NULL)
    {
        this->mother->addMother(child, mother);
    }
    else
    {
        this->father->addMother(child, mother);
        this->mother->addMother(child, mother);
    }
    
}

string Tree::relationRec(string name, int depth)
{
    if(this->name == name)
    {
        return "Found";
    }

    if(this->father != NULL)
    {
        return this->father->relation(name);
    }

    if(this->mother != NULL)
    {
        return this->mother->relation(name);
    }

    return "";
}

string Tree::relation(string name)
{  

    // if(this->name == name)
    // {
    //     return "Found  ";
    // }
    // else if(this->father == NULL && this->mother == NULL)
    // {
    //     return "Not Found ";
    // }
    // else if(this->father == NULL)
    // {
    //      return this->mother->relation(name);
    // }
    // else if(this->mother == NULL)
    // {
    //      return this->father->relation(name);
    // }
    // else
    // {
    //     return this->father->relation(name) + this->mother->relation(name);
    // }
}


string Tree::find(string name)
{
    if(this->name == name)
    {
        return "" + rel;
    }
    else if(this->father == NULL && this->mother == NULL)
    {
        return "" + rel;
    }
    this->father->find(name);
    this->mother->find(name);
    rel++;
}


void Tree::display()
{
    if(this != NULL)
    {
        this->father->display();
        cout << this->name << endl;
        this->mother->display();
    }
}
        
void Tree::remove(string name)
{

}

int main()
{
    Tree * T = new Tree("Ohad");
    T->addFather("Ohad", "Tzvi");
    T->addMother("Ohad", "Tzipi");
    T->addFather("Tzvi", "F-Tzvi");
    T->addMother("Tzvi", "M-Tzvi");
    T->addFather("F-Tzvi", "F-(F-Tzvi)");
    cout<< T->relation("Tzvi") << endl;
    // cout<< T << endl;
    //T->display();
    return 0;
}