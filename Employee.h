using namespace std;

class Employee
{
    string name;
    int age;
    int salary;
    int experience;

public:
    Employee();
    Employee(string _name, int _age, int _salary, int _experience);
    string getName();

    int getAge();

    int getSalary();

    int getExperience();
};
