/*#include <iostream.h>

class Complex {
private:
    float real;
    float imag;

public:
    Complex(float r = 0.0, float i = 0.0) : real(r), imag(i) {}

    // Overload + operator
    Complex operator+(const Complex& c) {
        return Complex(real + c.real, imag + c.imag);
    }

    // Overload - operator
    Complex operator-(const Complex& c) {
        return Complex(real - c.real, imag - c.imag);
    }

    // Overload * operator
    Complex operator*(const Complex& c) {
        return Complex(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
    }

    // Overload / operator
    Complex operator/(const Complex& c) {
        float denominator = c.real * c.real + c.imag * c.imag;
        return Complex((real * c.real + imag * c.imag) / denominator, (imag * c.real - real * c.imag) / denominator);
    }

    // Overload == operator
    bool operator==(const Complex& c) {
        return (real == c.real) && (imag == c.imag);
    }

    // Overload != operator
    bool operator!=(const Complex& c) {
        return !(real == c.real) || !(imag == c.imag);
    }

    // Overload += operator
    Complex& operator+=(const Complex& c) {
        real += c.real;
        imag += c.imag;
        return *this;
    }

    // Overload -= operator
    Complex& operator-=(const Complex& c) {
        real -= c.real;
        imag -= c.imag;
        return *this;
    }

    // Overload \*= operator
    Complex& operator*=(const Complex& c) {
        float tempReal = real * c.real - imag * c.imag;
        float tempImag = real * c.imag + imag * c.real;
        real = tempReal;
        imag = tempImag;
        return *this;
    }

    // Overload /= operator
    Complex& operator/=(const Complex& c) {
        float denominator = c.real * c.real + c.imag * c.imag;
        float tempReal = (real * c.real + imag * c.imag) / denominator;
        float tempImag = (imag * c.real - real * c.imag) / denominator;
        real = tempReal;
        imag = tempImag;
        return *this;
    }

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(3.0, 4.0);
    Complex c2(2.0, 5.0);

    Complex c3 = c1 + c2; // Use the overloaded + operator
    Complex c4 = c1 - c2; // Use the overloaded - operator
    Complex c5 = c1 * c2; // Use the overloaded * operator
    Complex c6 = c1 / c2; // Use the overloaded / operator

    cout << "Complex number 1: ";
    c1.display();
    cout << "Complex number 2: ";
    c2.display();
    cout << "Sum: ";
    c3.display();
    cout << "Difference: ";
    c4.display();
    cout << "Product: ";
    c5.display();
    cout << "Quotient: ";
    c6.display();

    if (c1 == c2) {
        cout << "Complex numbers are equal." << endl;
    } else {
        cout << "Complex numbers are not equal." << endl;
    }

    if (c1 != c2) {
        cout << "Complex numbers are not equal." << endl;
    } else {
        cout << "Complex numbers are equal." << endl;
    }

    c1 += c2; // Use the overloaded += operator
    cout << "Complex number 1 after += : ";
    c1.display();

    c1 -= c2; // Use the overloaded -= operator
    cout << "Complex number 1 after -= : ";
    c1.display();

    c1 *= c2; // Use the overloaded *= operator
    cout << "Complex number 1 after *= : ";
    c1.display();

    c1 /= c2; // Use the overloaded /= operator
    cout << "Complex number 1 after /= : ";
    c1.display();

    // Error: Cannot overload % operator for complex numbers
    // Complex c7 = c1 % c2;

    // Error: Cannot overload ^ operator for complex numbers
    // Complex c8 = c1 ^ c2;

    // Error: Cannot overload
    // Error: Cannot overload % operator for complex numbers
    // Complex c7 = c1 % c2;

    // Error: Cannot overload ^ operator for complex numbers
    // Complex c8 = c1 ^ c2;

    // Error: Cannot overload & operator for complex numbers
    // Complex c9 = c1 & c2;

    // Error: Cannot overload | operator for complex numbers
    // Complex c10 = c1 | c2;

    // Error: Cannot overload ~ operator for complex numbers
    // Complex c11 = ~c1;

    // Error: Cannot overload ! operator for complex numbers
    // Complex c12 = !c1;

    // Error: Cannot overload && operator for complex numbers
    // Complex c13 = c1 && c2;

    // Error: Cannot overload || operator for complex numbers
    // Complex c14 = c1 || c2;

    // Error: Cannot overload = operator for complex numbers
    // Complex c15 = c1 = c2;

    // Error: Cannot overload , operator for complex numbers
    // Complex c16 = (c1, c2);

    // Error: Cannot overload -> operator for complex numbers
    // Complex c17 = c1->real;

    // Error: Cannot overload ->* operator for complex numbers
    // Complex c18 = c1->*real;

    // Error: Cannot overload [] operator for complex numbers
    // Complex c19 = c1[0];

    // Error: Cannot overload () operator for complex numbers
    // Complex c20 = c1();

    return 0;
}*/
#include <iostream.h>


class Distance {
private:
    double feet;
    double inches;

public:
    // Constructor to initialize distance
    Distance(double f = 0.0, double i = 0.0) : feet(f), inches(i) {}

    // Method to read distance
    void readDistance() {
        cout << "Enter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;
    }

    // Method to display distance
    void display() {
        cout << feet << "'" << inches << "\"" << endl;
    }

    // Overload + operator
    Distance operator+(const Distance& d) {
        double totalInches = inches + d.inches;
        double newFeet = feet + d.feet + (totalInches / 12);
        double newInches = totalInches % 12;
        return Distance(newFeet, newInches);
    }

    // Overload - operator
    Distance operator-(const Distance& d) {
        double totalInches = inches - d.inches;
        double newFeet = feet - d.feet;
        if (totalInches < 0) {
            newFeet--;
            totalInches += 12;
        }
        return Distance(newFeet, totalInches);
    }
};

int main() {
    Distance dist1, dist2, dist3;

    cout << "Enter distance 1: " << endl;
    dist1.readDistance();

    cout << "Enter distance 2: " << endl;
    dist2.readDistance();

    cout << "Distance 1: ";
    dist1.display();

    cout << "Distance 2: ";
    dist2.display();

    dist3 = dist1 + dist2;
    cout << "Sum: ";
    dist3.display