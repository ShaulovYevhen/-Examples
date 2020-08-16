#include "Tree.h"
#include "Node.h"
int main()
{
    Tree<int>tree;
    Tree<int>tre;
    tree.insert(150);
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(200);
    tree.insert(20);
    tree.insert(40);
    tree.insert(90);
    tree.insert(10);
    tree.insert(80);
    tree.insert(100);
    tree.insert(90);
    tree.insert(11);
    tree.insert(82);
    tree.print();
    tre.insert(2);
    tre.insert(234);
    tre.insert(555);
    tre = tree;
    tre.print();
  
    tree.findSuccsessor(80);
    cout << "\n tree.findSuccsessor(80);" << tree.findSuccsessor(82)->getData() <<endl;
    cout << "\nfindMax()" << tree.findMax()->getData();
    cout << "\ntree.findMin()" << tree.findMin()->getData();
    cout << "\ngetSize" << tree.getSize();
    cout << "\n tree.findElement()" << tree.findElement(10)->getData() << " ; "<< tree.findElement(50)->getData() << endl;
    cout << "\n tree.findElement()" << tree.findElement(10)->getData() << " ; " << tree.findElement(100)->getData() << endl;
    cout << "\n tree.findElement()" << tree.findElement(40)->getParent()->getData() << " ; " << tree.findElement(80)->getData() << endl;
    cout << "\n tree.findElement()" << tree.findElement(10) << " ; " << tree.findElement(100) << endl;
    cout << "\n tree.getRoot()->getLeft()" << tree.getRoot()->getLeft() << " ; " << tree.getRoot()->getLeft()->getData() << endl;
    tree.print();
    cout << "\n tree.findElement(5)" << tree.findElement(82) << " ; " << endl;
    cout << "\n tree.findElement()" << tree.findElement(90) << " ; " << endl;
    tree.print();
    tree.deleteElement(82);
    tree.deleteElement(90);
    tree.print();

    cout << "\n" << tree.getSize();
    tree.~Tree();
    cout << "\n" << tree.getSize();
    tree.print();
    tree.print_Tree(tree.getRoot(),0);
}
