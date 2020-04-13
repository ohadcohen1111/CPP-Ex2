#include <iostream>
#include <string>

using namespace std;
namespace family
{
class Tree
    {
    private:
        string name;
        Tree * father;
        Tree * mother;
        string relationRec(string name, int depth);
        
    public:
        Tree(string name);
        Tree& addFather(string chils, string father);
        Tree& addMother(string child, string mother);
        string relation(string name);
        string find(string name);
        void display();
        void remove(string name);
        Tree& findHelp(string name);
    };
};


