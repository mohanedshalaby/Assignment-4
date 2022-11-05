#include "HashTablesWithLinkedList.h"

using namespace std;

class HashTablesWithDynamicArray
{
    int size;
    Employee *table;
    int numberOfInsertedElement;
    int numberOfCollision;

public:
    HashTablesWithDynamicArray();
    HashTablesWithDynamicArray(int _size);

    long long Hash(string s);

    void insert(Employee emp);

    void remove(Employee emp);

    void print();

    double calColissionRate();
};
