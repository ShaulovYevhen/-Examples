#include <iostream>
#include "Node.h"
#include "List.h"
using namespace std;
int main()
{
    List<int> list{ 23,45,56, 11 };
    List<int> li{ 23,45,56,0,5,6,7,8,6 };
    //li = list;
    li.print_forward();
    li.print_backward();
    list.print_forward();
    list.print_backward();
    list.push_front(10);
    list.print_forward();
    list.print_backward();
    list.push_back(10);
    list.print_forward();
    list.print_backward();
    list.pop_front();
    list.print_forward();
    list.print_backward();
    cout << "\nErase\n";
    list.erase(2);
    list.erase(2);
    list.print_forward();
    list.print_backward();
    cout << "\nSwap\n";
    list.push_back(18);
    list.push_back(16);
    list.print_forward();
    list.SwapNodes(1, 2);
    list.print_forward();
    list.print_backward();
    cout << "\nSort\n";
    li.print_forward();
    li.sort();
    li.print_forward();
    cout << "\nLSort\n";
    li.Lsort();
    li.print_forward();
}

