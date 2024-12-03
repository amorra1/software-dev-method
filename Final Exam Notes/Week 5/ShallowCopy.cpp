
// Copy Constructor - Shallow Copy
// Note: this program will crash
#include <iostream>

using namespace std;

/* === Shallow Copy notes ===
- shallow copy is when each member attribute is coped from the source object
- default compiler generated constructor performs shallow copy
- copies only the pointers, not the resources the point to
- both original and copy share the same memory for dynamic resource
- changing the resource in one object changes it in the other too
*/

class Shallow {
private:
    int *data;
public:
    void set_data_value(int data_val) { *data = data_val; }
    int get_data_value() { return *data; }
    // Constructor
    Shallow(int d);
    // Copy Constructor
    Shallow(const Shallow &source);
    // Destructor
    ~Shallow();
};

Shallow::Shallow(int d) {
    data = new int;
    *data = d;
}

Shallow::Shallow(const Shallow &source) 
    : data(source.data) {
        cout << "Copy constructor  - shallow copy" << endl;
}

Shallow::~Shallow() {
    delete data;
    cout << "Destructor freeing data" << endl;
}

void display_shallow(Shallow s) {
    cout << s.get_data_value() << endl;
}

int main() {
    
    Shallow obj1 {100};
    display_shallow(obj1); 
    
    Shallow obj2 {obj1};
    obj2.set_data_value(1000);
    // this is where the crash
    return 0;
}

