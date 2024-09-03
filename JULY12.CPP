#include <iostream.h>
#include <conio.h>
#include <string.h>
#define LENGTH(arr) (sizeof(arr) / sizeof((arr)[0]))
#include <limits.h>
/*
void rangeFinder() {
  // Signed data types
  cout << "Signed data types:" << endl;
  cout << "-----------------" << endl;
  cout << "char: " << CHAR_MIN << " to " << CHAR_MAX << endl;
  cout << "short: " << SHRT_MIN << " to " << SHRT_MAX << endl;
  cout << "int: " << INT_MIN << " to " << INT_MAX << endl;
  cout << "long: " << LONG_MIN << " to " << LONG_MAX << endl;

  // Unsigned data types
  cout << "\nUnsigned data types:" << endl;
  cout << "-------------------" << endl;
  cout << "unsigned char: 0 to " << UCHAR_MAX << endl;
  cout << "unsigned short: 0 to " << USHRT_MAX << endl;
  cout << "unsigned int: 0 to " << UINT_MAX << endl;
  cout << "unsigned long: 0 to " << ULONG_MAX << endl;
}

void main() {
  rangeFinder();
}

class Student {
private:
    char name[50];
    int rollNo;
    float marks;

public:
    // constructor
    Student() {}

    // method to ask for input from user
    void setInputFromUser() {
	cout << "Enter student name: ";
	cin.getline(name, 50);

	cout << "Enter roll number: ";
	cin >> rollNo;

	cout << "Enter marks: ";
	cin >> marks;
    }

    // method to display input
    void displayInput() {
	cout << "Student Name: " << name << endl;
	cout << "Roll Number: " << rollNo << endl;
	cout << "Marks: " << marks << endl;
    }
};

void main() {
    clrscr();
   Student s,s1,s2,s3;

    s.setInputFromUser();
    s.displayInput();
    s2.setInputFromUser();
    s2.displayInput();
    s3.setInputFromUser();
    s3.displayInput();
    s1.setInputFromUser();
    s2.displayInput();
int i,arr[5]={1,2,3,4,5};
for (i=0;i<LENGTH(arr);i++){
arr[4]=100;
cout<<arr[i]<<endl;
}
    getch();
}

void main()
{
    clrscr();

    int arr[10];
    int i, j, n;

    cout << "Enter the number of elements (max 10): ";
    cin >> n;

    cout << "Enter the elements: ";
    for (i = 0; i < n; i++)
	cin >> arr[i];

    cout << "\nArray elements: ";
    for (i = 0; i < n; i++)
	cout << arr[i] << " ";

    cout << "\n\nDuplicate elements and their indices: ";
    for (i = 0; i < n; i++)
    {
	for (j = i + 1; j < n; j++)
	{
	    if (arr[i] == arr[j])
	    {
		cout << "\nDuplicate element: " << arr[i] << " at indices " << i << " and " << j;
	    }
	}
    }

    getch();
}


class MyClass {
    int x;
public:

    MyClass() {
	x = 0;
	cout << "Default constructor called" << endl;
    }

    void display() {
	cout << "Value of x: " << x << endl;
    }
};

void main() {
clrscr();
    MyClass obj;
    obj.display();
    getch();
}

class ConstructorDemo {
private:
    int x;

public:
    ConstructorDemo() {
	x = 0;
	cout << "Default constructor called" << endl;
    }
    ConstructorDemo(int y) {
	x = y;
	cout << "Parameterized constructor called" << endl;
    }
    ConstructorDemo(const ConstructorDemo& obj) {
	x = obj.x;
	cout << "Copy constructor called" << endl;
    }
    ~ConstructorDemo() {
	cout << "Destructor called" << endl;
    }

    void display() {
	cout << "Value of x: " << x << endl;
    }
};

void main() {
    clrscr();
    int choice;

    cout << "Choose a constructor to call:" << endl;
    cout << "1. Default constructor" << endl;
    cout << "2. Parameterized constructor" << endl;
    cout << "3. Copy constructor" << endl;
    cin >> choice;

    switch (choice) {
	case 1: {
	    ConstructorDemo obj1;
	    obj1.display();
	    break;
	}
	case 2: {
	    int y;
	    cout << "Enter a value for y: ";
	    cin >> y;
	    ConstructorDemo obj2(y);
	    obj2.display();
	    break;
	}
	case 3: {
	    ConstructorDemo obj3;
	    ConstructorDemo obj4 = obj3;
	    obj4.display();
	    break;
	}
	default:
	    cout << "Invalid choice" << endl;
    }

    getch();
} 


class MyClass {
    int *ptr;

public:
    MyClass(int x) {
	ptr = new int;
	*ptr = x;
    }
    MyClass(const MyClass &obj) {
	ptr = obj.ptr;
    }
    MyClass(const MyClass &obj, int deep) {
	if (deep) {
	    ptr = new int;
	    *ptr = *(obj.ptr);
	} else {
	    ptr = obj.ptr;
	}
    }

    void set(int x) {
	*ptr = x;
    }

    int get() {
	return *ptr;
    }

    ~MyClass() {
	delete ptr;
    }
};

void main() {
    clrscr();

    MyClass obj1(10);

    // Shallow Copy
    MyClass obj2 = obj1;
    cout << "obj1: " << obj1.get() << ", obj2: " << obj2.get() << endl;
    obj1.set(20);
    cout << "obj1: " << obj1.get() << ", obj2: " << obj2.get() << endl;

    // Deep Copy
    MyClass obj3 = MyClass(obj1, 1);
    cout << "obj1: " << obj1.get() << ", obj3: " << obj3.get() << endl;
    obj1.set(30);
    cout << "obj1: " << obj1.get() << ", obj3: " << obj3.get() << endl;

    getch();
}
class a {
    int b;
    char c[21];
};

int main() {
    a obj;
    cout << "Size of class a: " << sizeof(obj) << " bytes" <<endl;
    return 0;
}
void findMajorityElement(int arr[], int n) {
  int majorityElement = arr[0];
  int i,count = 1;

  for ( i = 1; i < n; i++) {
    if (arr[i] == majorityElement) {
      count++;
    } else {
      count--;
      if (count == 0) {
	majorityElement = arr[i];
	count = 1;
      }
    }
  }
  count = 0;
  for (i = 0; i < n; i++) {
    if (arr[i] == majorityElement) {
      count++;
    }
  }

  if (count > n/2) {
    cout << "Majority element is: " << majorityElement << endl;
  } else {
    cout << "No majority element found." << endl;
  }
}

void main() {
  clrscr();
  int arr[100];
  int n,i;
  cout << "Enter the size of the array: ";
  cin >> n;

  cout << "Enter the elements of the array: ";
  for (i = 0; i < n; i++) {
    cin >> arr[i];
  }

  findMajorityElement(arr, n);

  getch();
}

class Person {
public:
    // Constructor
    Person(char *name, int age) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->age = age;
        cout << "Person object created: " << name << ", " << age << endl;
    }

    // Destructor
    ~Person() {
        cout << "Person object destroyed: " << name << ", " << age << endl;
        delete[] name;
    }

private:
    char *name;
    int age;
};

void main() {
    clrscr();
    Person person1("John", 30);
    Person person2("Jane", 25);
    getch();
}
*/