#include <iostream>
#include "List.h"

using namespace std;

int main()
{
    cout << "Checking work of Node(from lesson)\n\n";
    Node<int>a(95);
    Node<int>b(137);
    cout << a.getData() << endl;
    a.setNext(&b);
    cout << a.getNext()->getData() << endl;
    cout << "\n";

    cout << "Checking work of List constructor, push_back, pop_front and copy (from lesson)\n\n";
    List<int> list{ 16,92,23,117,395 };
    list.push_back(116);
    cout << "Received size of List = " << list.getSize() << endl;
    list.print();
    list.pop_front();
    list.print();
    auto copy = list;
    copy.print();
    cout << "\n";
    cout << "Checking work of push_front\n\n";
    list.push_front(888);
    list.print();
    cout << "\n";
    cout << "Checking work of pop_back\n\n";
    list.pop_back();
    list.print();
    cout << "\n";
    cout << "Checking work of push_index\n\n";
    list.push_index(777,2);
    list.print();
    cout << "\n";
    cout << "Checking work of pop_index\n\n";
    list.pop_index(4);
    list.print();
    cout << "\n";
    list.push_index(999, 3);
    list.push_index(111, 4);
    list.push_index(222, 5);
    list.push_index(444, 6);
    list.print();
    cout << "Checking work of pop_index_several\n\n";
    list.pop_index_several(4, 2);
    list.print();
    cout << "\n";
    cout << "Checking work of operator =\n\n";
    List<int> list1 = list;
    list1.push_index(555, 4);
    list.print();
    list1.print();
}