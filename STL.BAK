#include <iostream.h>

template <class T>
class MyTemplate {
public:
    T data;
    MyTemplate(T value) {
        data = value;
    }
    void display() {
      cout << "Value: " << data << endl;
    }
};

int main() {
    MyTemplate<int> intObj(10);
    intObj.display();

    MyTemplate<double> doubleObj(3.14);
    doubleObj.display();

    return 0;
}