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

string findName = "";

string Tree::find(string name)
{
    if (name == "me")
    {
        return this->name;
    }
    if (name == "mother")
    {
        if (this->mother == NULL)
        {
            throw runtime_error("No such a mother");
        }        
        return this->mother->name;
    }
    if (name == "father")
    {
        if (this->father == NULL)
        {
            throw runtime_error("No such a father");
        }  
        return this->father->name;
    }
     if (name == "grandfather")
    {
        if (this->father->father != NULL)
        {
           return this->father->father->name;
        }
        else  if (this->mother->father != NULL)
        {
             return this->mother->father->name;
        }
        throw runtime_error("No such a grandfather");
    }
     if (name == "grandmother")
    {
         if (this->father->mother != NULL)
        {
           return this->father->mother->name;
        }
        else  if (this->mother->mother != NULL)
        {
          return this->mother->mother->name;
        }
        throw runtime_error("No such a grandmother");
    }
    else
    {
        int level = 3;
        string s = name;
        while ((s != "grandmother" ) && (s != "grandfather"))
        {
            s = s.substr(6,(s.length()-6));
            level++;
        }
        findHelp(this,s, level);
        if (findName == "")
        {
            throw runtime_error("No such a " + name);
        }
        return findName;
        
    }  
}

int  Tree::findHelp(Tree * T,string name, int level)
{
    if (T == NULL)
    {
        return -1;
    }
    
   if(T->father == NULL && T->mother == NULL)
   {
       return -1;
   }

   if(level == 2 )
   {
       if (name == "grandmother")
       {
           findName = T->mother->name;
       }else
       {
           findName = T->father->name;
       }       
       return level;
   }
   int downlevel = findHelp(T->father,name, level-1);

    if(downlevel > 0)
    {
        return downlevel;
    }

    downlevel =  findHelp(T->mother,name, level-1);

    return downlevel;
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

// int main()
// {
//     Tree * T = new Tree("Doron");
//     T->addFather("Doron", "Gal");
//     T->addMother("Doron", "Galit");
//     T->addFather("Gal", "Reuven");
//     T->addMother("Gal", "Rachel");
//     T->addFather("Galit", "Shlomo");
//     T->addMother("Galit", "Yael");
//     T->addMother("Yael", "saly");
//     T->addFather("Yael", "f -yael");
//     T->addFather("f -yael", "f -f-yael");
//     T->addFather("Shlomo", "F-Shlomo");
//     T->addFather("F-Shlomo", "F-F-Shlomo");
//     T->addFather("F-F-Shlomo", "F-F-F-Shlomo");
//     T->addMother("Rachel", "M-Rachel");
//     T->addMother("M-Rachel", "M-M-Rachel");
//     T->addMother("M-M-Rachel", "M-M-M-Rachel");
//    cout<<T->find("great-great-great-great-grandmother");

//    Tree * T1 = new Tree("Ido");
//    cout<<T1->find("mother");


//     //cout << T->relation("M-Tzvi") << endl;

//     return 0;
// }