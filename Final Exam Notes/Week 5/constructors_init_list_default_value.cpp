// OnQ Example
// Constructor Initialization Lists and default values
#include <iostream>
#include <string>

using namespace std;

/* === Class Notes ===
- an instance of a class is an object
- an object encapsulates the data and operations that use such data
- used as a blueprint to create an object, has data, has functions
- pointer to objects user -> operator
- Modifiers
    - Public: accessible from anywhere
    - Private: accessible only by other members of same class or by friends of class
    - Protected: used with inheritance, the member is only accessible to a child class
- Constructors
    - Special member method
    - has same name as class
    - used for object creation and initialization
    - can call another constructor in the initialization list
- Destructor
    - special member method
    - has same name as class preceeded by ~
    - used to release memory and other resources
    - only one per class
- Copy Constructor
    - used when an object is copied
    - we pass an object by value, return an object by value
- compiler types checks the implementation of the method against the method prototype
- include guards ensure that the file is processed only once
    - #pragma once 
    - is equivalent to ...
      #ifndef _ACCOUNT_H_
      #define _ACCOUNT_H_

      #endif
*/

class Student
{
private:
   string name;
   string major;
   int year;
public:
    string get_name(); 
    string get_major(); 
    int get_year(); 
    // Overloaded Constructors
    /**
        Student();
        Student(string name_val);
        Student(string name_val, string major_val, int year_val);
    **/

    // This constructor with default values replaces all above constructors 
    Student(string name_val ="None", string major_val = "NONE", int year_val = 0);
};
/**
Student::Student() 
    : name{"NONE"}, major{"NONE"}, year{0} {
        cout << "No arg constructor called" << endl; 
}

Student::Student(string name_val) 
   : name{name_val}, major{"NONE"}, year{0} {
        cout << "One arg constructor called" << endl;
}
**/  
Student::Student(string name_val, string major_val, int year_val) 
    : name{name_val}, major{major_val}, year{year_val} {
        cout << "Three args constructor called" << endl; 
}
// getters
string Student::get_name() {
    return name; 
}
string Student::get_major(){
    return major; 
}
int Student::get_year(){
    return year; 
}

int main() {
    
    Student abi;
    Student tim {"Tim"};
    Student kate {"Kate", "mechanical engineering", 4};
    cout << kate.get_name() << " is in year " << kate.get_year() << " of her " << kate.get_major() << " degree" << endl; 
    
    return 0;
}

