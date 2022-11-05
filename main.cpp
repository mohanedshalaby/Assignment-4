#include <iostream>
#include "HashTablesWithDynamicArray.h"

using namespace std;

Employee::Employee()
{
    name = "";
    age = 0;
    salary = 0;
    experience = 0;
}

Employee::Employee(string _name, int _age, int _salary, int _experience)
{
    name = _name;
    age = _age;
    salary = _salary;
    experience = _experience;
}

string Employee::getName()
{
    return name;
}

int Employee::getAge()
{
    return age;
}

int Employee::getSalary()
{
    return salary;
}

int Employee::getExperience()
{
    return experience;
}

LinkedList::LinkedList()
{
    size = 0;
    head = tail = NULL;
}


bool isEqual(Employee a, Employee b)
{
    return a.getAge() == b.getAge() && a.getExperience() == b.getExperience()
            && a.getName() == b.getName() && a.getSalary() == b.getSalary();
}

void LinkedList::insert(Employee emp)
{
    size++;
    if (head == NULL)
    {
        head = tail = new Node(emp);
    }
    else
    {
        tail->nxt = new Node(emp);
        tail = tail->nxt;
    }
}

void LinkedList::print()
{
    Node* cur_node = head;

    while (cur_node != NULL)
    {
        cout << "Name = " << cur_node->emp.getName() << endl;
        cout << "Age = " << cur_node->emp.getAge() << endl;
        cout << "Salary = " << cur_node->emp.getSalary() << endl;
        cout << "Experience = " << cur_node->emp.getExperience() << endl;
        cout << endl;
        cur_node = cur_node->nxt;
    }

    cout << endl;
}

void LinkedList::remove(Employee emp)
{
    size--;
    if (isEqual(head->emp, emp))
    {
        Node* tmp = head;
        head = head->nxt;
        delete tmp;
        return;
    }

    Node* cur_node = head;

    while (cur_node != NULL)
    {
        if (isEqual(cur_node->nxt->emp, emp))
        {
            break;
        }
        else
        {
            cur_node = cur_node->nxt;
        }
    }

    Node* deletedNode = cur_node->nxt;

    Node* nxtNode = deletedNode->nxt;

    if (deletedNode == tail)
    {
        tail = cur_node;
    }

    delete deletedNode;

    cur_node->nxt = nxtNode;

    return;
}

int LinkedList::getSize()
{
    return size;
}






HashTablesWithDynamicArray::HashTablesWithDynamicArray()
{
}

HashTablesWithDynamicArray::HashTablesWithDynamicArray(int _size)
{
    numberOfInsertedElement = 0;
    numberOfCollision = 0;
    size = _size;

    table = new Employee[size];
}

long long HashTablesWithDynamicArray::Hash(string s)
{
    long long seed = 131;
    long long hash = 0;

    for(int i = 0 ; i < s.length() ; i++)
    {
        hash = (hash * seed) + s[i];
    }

    return hash % size;
}

void HashTablesWithDynamicArray::insert(Employee emp)
{
    int hashResult = 0;

    hashResult += Hash(emp.getName());
    hashResult %= size;

    hashResult += Hash(to_string(emp.getAge()));
    hashResult %= size;

    hashResult += Hash(to_string(emp.getSalary()));
    hashResult %= size;

    hashResult += Hash(to_string(emp.getExperience()));
    hashResult %= size;

    for(int i = hashResult, j = 0 ; j < size ; j++, i = (i + 1) % size)
    {
        if(table[i].getName() == "")
        {
            table[i] = emp;
            if(i != hashResult)
            {
                numberOfCollision++;
            }

            numberOfInsertedElement++;

            break;
        }
    }
}

void HashTablesWithDynamicArray::remove(Employee emp)
{
    int hashResult = 0;

    hashResult += Hash(emp.getName());
    hashResult %= size;

    hashResult += Hash(to_string(emp.getAge()));
    hashResult %= size;

    hashResult += Hash(to_string(emp.getSalary()));
    hashResult %= size;

    hashResult += Hash(to_string(emp.getExperience()));
    hashResult %= size;

    for(int i = hashResult, j = 0 ; j < size ; j++, i = (i + 1) % size)
    {
        if(isEqual(table[i], emp))
        {
            table[i] = Employee();
            if(i != hashResult)
            {
                numberOfCollision--;
            }

            numberOfInsertedElement--;

            break;
        }
    }
}

void HashTablesWithDynamicArray::print()
{
    for(int i = 0 ; i < size ; i++)
    {
        cout << "Data of Index (" << i << ")" << endl;
        cout << "Name = " << table[i].getName() << endl;
        cout << "Age = " << table[i].getAge() << endl;
        cout << "Salary = " << table[i].getSalary() << endl;
        cout << "Experience = " << table[i].getExperience() << endl;
        cout << endl;
    }

    cout << endl << endl;
}

double HashTablesWithDynamicArray::calColissionRate()
{
    if(!numberOfInsertedElement)
    {
        return 0;
    }

    return (1.0 * numberOfCollision / numberOfInsertedElement);
}



HashTablesWithLinkedList::HashTablesWithLinkedList()
{
}

HashTablesWithLinkedList::HashTablesWithLinkedList(int _size)
{
    numberOfInsertedElement = 0;
    size = _size;

    table = new LinkedList[size];
}

long long HashTablesWithLinkedList::Hash(string s)
{
    long long seed = 131;
    long long hash = 0;

    for(int i = 0 ; i < s.length() ; i++)
    {
        hash = (hash * seed) + s[i];
    }

    return hash % size;
}

void HashTablesWithLinkedList::insert(Employee emp)
{
    int hashResult = 0;

    hashResult += Hash(emp.getName());
    hashResult %= size;

    hashResult += Hash(to_string(emp.getAge()));
    hashResult %= size;

    hashResult += Hash(to_string(emp.getSalary()));
    hashResult %= size;

    hashResult += Hash(to_string(emp.getExperience()));
    hashResult %= size;

    numberOfInsertedElement++;
    table[hashResult].insert(emp);
}

void HashTablesWithLinkedList::remove(Employee emp)
{
    int hashResult = 0;

    hashResult += Hash(emp.getName());
    hashResult %= size;

    hashResult += Hash(to_string(emp.getAge()));
    hashResult %= size;

    hashResult += Hash(to_string(emp.getSalary()));
    hashResult %= size;

    hashResult += Hash(to_string(emp.getExperience()));
    hashResult %= size;

    numberOfInsertedElement--;
    table[hashResult].remove(emp);
}

void HashTablesWithLinkedList::print()
{
    for(int i = 0 ; i < size ; i++)
    {
        cout << "Printing data at Index (" << i << ")" << endl << endl;
        table[i].print();
    }
}

double HashTablesWithLinkedList::calColissionRate()
{
    if(!numberOfInsertedElement)
    {
        return 0;
    }

    int numberOfCollision = 0;

    for(int i = 0 ; i < size ; i++)
    {
        if(table[i].getSize() > 1)
        {
            numberOfCollision += (table[i].getSize() - 1);
        }
    }

    return (1.0 * numberOfCollision / numberOfInsertedElement);
}

int main()
{
    HashTablesWithDynamicArray ht_DynamicArray(7);
    HashTablesWithLinkedList ht_LinkedList(7);

    Employee emp1 = Employee("Mina", 30, 10000, 4);
    Employee emp2 = Employee("Fawzy", 45, 5000, 8);
    Employee emp3 = Employee("Yara", 19, 2000, 0);

    ht_DynamicArray.insert(emp1);
    ht_LinkedList.insert(emp1);
    ht_DynamicArray.insert(emp2);
    ht_LinkedList.insert(emp2);
    ht_DynamicArray.insert(emp3);
    ht_LinkedList.insert(emp3);

    cout << "Running Hash Table With Dynamic Array" << endl << endl;
    ht_DynamicArray.print();

    cout << "Running Hash Table With Linked List" << endl << endl;
    ht_LinkedList.print();

    return 0;
}
