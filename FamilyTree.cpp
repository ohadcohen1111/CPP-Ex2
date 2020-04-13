#include "FamilyTree.hpp"

using namespace family;
static int level = 0;

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

string Tree::relation(string name)
{   
    int level = relationHelp(this, name, 1);
    string res = "";
    string great = "great-";

    switch (level)
    {
    case 0:
        res = "unrelated";
        break;
    case 1:
        res = "me"; 
        break;
    case 2:
        res = "father"; 
        break;
    case -2:
        res = "mother"; 
        break;
    case 3:
        res = "grandfather"; 
        break;
    case -3:
        res = "grandmother"; 
        break;
    
    default:
        string sign = "";
        if(level > 0)
        {
            sign += "grandfather";
        }
        else
        {
            sign += "grandmother";
            level *= -1;
        }
    
        while(level-- > 3)
        {
            res += great;
        }
        res += sign;
        break;
    }
    return res;
}



int Tree::relationHelp(Tree * T, string name, int level)
{
   if(T->father == NULL && T->mother == NULL)
   {
       return 0;
   }

   if(T->name == name)
   {
       return level;
   }

    if(T->father->name == name)
   {
       return level + 1;
   }

    if(T->mother->name == name)
   {
       return ((level + 1) * (-1));
   }

   int downlevel = relationHelp(T->father, name, level + 1);

    if(downlevel != 0)
    {
        return downlevel;
    }

    downlevel = relationHelp(T->mother, name, level + 1);

    return downlevel;
}


string Tree::find(string name)
{
    if(this->name == name)
    {
        return "" ;
    }
    else if(this->father == NULL && this->mother == NULL)
    {
        return "";
    }
    this->father->find(name);
    this->mother->find(name);
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
