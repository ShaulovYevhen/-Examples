#include <iostream>
#include "Node.h"
#include "List.h"
using namespace std;
int main()
{
    List<int> list{ 23,45,56 };
    List<int> li{ 23,45,56 };
    auto l = list;
    //l.print();
    list.print();
    list.push_back(234);
    list.print();
    list.push_back(92);
    list.print();
    list.push_back(175);
    list.print();
    list.push_back(88);
    list.print();
    cout << "pop\n";
    list.pop_front();
    list.pop_back();
    list.print();
    cout << "list + li\n";
    list = list + li;
    list.print();
    list = li;
    list.print();
    cout << "emplace!\n";
    li.emplace(2, 2);
    li.print();
    list = list + li;
    list.print();
    cout << "push frontr!\n";
    list.push_front(88);
    list.push_front(8);
    list.print();
    cout << "erase(3);\n";
    list.erase(3);
    list.print();
    cout << "erase(2);\n";
    list.erase(2);
    list.print();
    cout << "erase(1, 3);\n";
    list.erase(1, 3);
    list.print();
}
