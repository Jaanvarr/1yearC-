#include"Tree.h"


int main()
{
    BinaryTree<int> Tree;
    Tree.insert(0);
    for (int i = 1; i < 15; i++)
    {
        Tree.insert(i);
        Tree.insert(-i);
    }
    //Tree.print();
    std::cout << Tree.countNodesAtLevel(Tree.find(0),4);

}


