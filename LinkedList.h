#include "Employee.h"

using namespace std;

struct Node
{
    Employee emp;
    Node* nxt;

    Node()
    {
        emp = Employee();
        nxt = NULL;
    }

    Node(Employee emp)
    {
        nxt = NULL;
        this->emp = emp;
    }
};

class LinkedList
{
    Node* head;
    Node* tail;
    int size;

public:
    LinkedList();

    void insert(Employee emp);

    void print();

    void remove(Employee emp);

    int getSize();
};
