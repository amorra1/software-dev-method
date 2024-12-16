#include <iostream>
#include <string>

using namespace std;

// Base class: Parent
class Parent {
public:
    virtual ~Parent() {}

    string fcnOne() {
        return "POne";
    }

    string fcnOne(string aVal) {
        return "POne " + aVal;
    }

    virtual string fcnTwo(string aVal) {
        return "PTwo " + aVal;
    }

    virtual string fcnThree(string aVal) = 0;

    virtual string fcnFour(string aVal = "hello") {
        return "PFour " + aVal;
    }
};

// Derived class: Child
class Child : public Parent {
public:
    string fcnOne() {
        return "COne";
    }

    string fcnOne(string aVal, string bVal) {
        return "COne " + aVal + " " + bVal;
    }

    string fcnTwo() {
        return "CTwo";
    }

    string fcnTwo(string aVal) {
        return "CTwo " + aVal;
    }

    string fcnThree(string aVal) {
        return "CThree " + aVal;
    }

    string fcnFour(string aVal = "goodbye") {
        return "CFour " + aVal;
    }
};

// Derived class: GrandChild
class GrandChild : public Child {
public:
    string fcnFive() {
        return "GFive";
    }

    string fcnFive(string aVal) {
        return "GFive " + aVal;
    }
};

// Main function to test the hierarchy
int main() {
    Parent p1;
    cout << p1.fcnOne() << endl;          // Output: POne

    Child c1;
    cout << c1.fcnOne() << endl;          // Output: COne
    // cout << c1.fcnOne("10") << endl;      // Output: POne 10
    cout << c1.fcnOne("20", "30") << endl; // Output: COne 20 30
    cout << c1.fcnTwo() << endl;          // Output: CTwo
    cout << c1.fcnTwo("40") << endl;      // Output: CTwo 40
    cout << c1.fcnThree("50") << endl;    // Output: CThree 50
    cout << c1.fcnFour() << endl;         // Output: CFour goodbye

    cout << "\nSecond part:" << endl;

    Parent* p2 = &c1;
    cout << p2->fcnOne() << endl;         // Output: POne
    cout << p2->fcnOne("15") << endl;     // Output: POne 15
    // cout << p2->fcnOne("25", "35") << endl; // Error: Not visible through Parent*
    cout << p2->fcnTwo("45") << endl;     // Output: CTwo 45
    cout << p2->fcnThree("55") << endl;   // Output: CThree 55
    cout << p2->fcnFour() << endl;        // Output: CFour hello

    cout << "\nThird part:" << endl;

    GrandChild gc;
    Child c2 = gc; // Object slicing
    // Calls the Child version due to slicing
    // cout << c2.fcnFive() << endl;         // Error: fcnFive() not available in Child
    // cout << c2.fcnFive("100") << endl;    // Error: fcnFive(string) not available in Child

    return 0;
}
