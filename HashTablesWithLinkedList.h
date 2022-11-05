#include "LinkedList.h"

using namespace std;

class HashTablesWithLinkedList
{
    int size;
    LinkedList *table;
    int numberOfInsertedElement;

public:
    HashTablesWithLinkedList();
    HashTablesWithLinkedList(int _size);

    long long Hash(string s);

    void insert(Employee emp);

    void remove(Employee emp);

    void print();

    double calColissionRate();
};
