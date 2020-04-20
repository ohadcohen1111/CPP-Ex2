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
        
    public:
        Tree(string name);
        Tree& addFather(string chils, string father);
        Tree& addMother(string child, string mother);
        string relation(string name);
        string find(string name);
        void display();
        void remove(string name);
        int relationHelp(Tree * T, string name, int level);
        int  findHelp(Tree * T,string name, int level);
    };
};