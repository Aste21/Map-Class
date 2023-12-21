#include <cstdlib>
#include <iostream>
#include <string>

class Employee
{
    private:
    public:
        std::string name;
        std::string position;
        int age;
        Employee() = default;
        Employee(std::string newName, std::string newPosition, int newAge);
        ~Employee() = default;
        friend std::ostream &operator<<(std::ostream &out, const Employee &employee);
};

Employee::Employee(std::string newName, std::string newPosition, int newAge)
    : name(newName), position(newPosition), age(newAge) {}


std::ostream &operator<<(std::ostream &out, const Employee &employee) {
    out <<"Name: " << employee.name << ", Position: " << employee.position << ", Age: " << employee.age;
    return out;
}