#include <stdio.h>
#include <conio.h>
#include <iostream.h>
/*class rectangle{
private:
int len,bre;
public: void getdata(){
printf("enter length and breadth");
scanf("%d",&len);
scanf("%d",&bre);
};
public: void shdata(){
printf("%d,is length and",len);printf("%d is breadth of rectangle\n",bre);
};
public: void setdata(int i,int j){
len=i;
bre=j;
};
public: void area(){
 int a=len*bre;
 printf("%d is the area of rectangle\n",a);
};
};
void main(){
 rectangle r1,r2,r3;
 r1.getdata();
 r2.getdata();
 r3.setdata(10,4);
 r1.shdata();
 r2.shdata();
 r3.shdata();
 r1.area();
 r2.area();
 r3.area();
}

int main(){
 int a,b;
 cin>>a>>b;
 int x;
 x=a+b;
 cout<<"the sum of two numbers is "<< x<<endl;
 return 0;
}
int main(){
int i;
int x=5,y=11;
i=x+x*y/x;
cout<<i;
cin>>i;
return 0;
}


void decimalToBinary(int decimal, char binary[]) {
    int i = 7;
    while (decimal > 0) {
	binary[i--] = (decimal % 2) ? '1' : '0';
	decimal /= 2;
    }
    while (i >= 0) {
	binary[i--] = '0';
    }
    binary[8] = '\0';
}

void xorOperation(char binary1[], char binary2[], char result[]) {
    for (int i = 0; i < 8; i++) {
	if (binary1[i] == '1' && binary2[i] == '1')
	    result[i] = '0';
	else if (binary1[i] == '0' && binary2[i] == '0')
	    result[i] = '0';
	else
	    result[i] = '1';
    }
    result[8] = '\0';
}

void orOperation(char binary1[], char binary2[], char result[]) {
    for (int i = 0; i < 8; i++) {
	if (binary1[i] == '1' || binary2[i] == '1')
	    result[i] = '1';
	else
	    result[i] = '0';
    }
    result[8] = '\0';
}

void andOperation(char binary1[], char binary2[], char result[]) {
    for (int i = 0; i < 8; i++) {
	if (binary1[i] == '1' && binary2[i] == '1')
	    result[i] = '1';
	else
	    result[i] = '0';
    }
    result[8] = '\0';
}


int main() {
    int decimal1 ; // 1010 in binary
    int decimal2 ; // 1100 in binary
    cin>>decimal1>>decimal2;
    char binary1[9], binary2[9], result[9];

    decimalToBinary(decimal1, binary1);
    decimalToBinary(decimal2, binary2);

    cout << "Binary 1: " << binary1 << endl;
    cout << "Binary 2: " << binary2 << endl;

    xorOperation(binary1, binary2, result);

    cout << "XOR Result: " << result << endl;
    andOperation(binary1, binary2, result);

    cout << "AND Result: " << result << endl;
    orOperation(binary1, binary2, result);

    cout << "OR Result: " << result << endl;

    return 0;
}
void add(float a,float b=8.0){
 float x;
 x=a+b;
 cout<< "sum is "<<x<<endl;
}
void main(){
 float a=10.4,b=12.23;
 add(a,b);
}
void decimalToBinary(int decimal, char binary[]) {
    int i = 7;
    while (decimal > 0) {
	binary[i--] = (decimal % 2) ? '1' : '0';
	decimal /= 2;
    }
    while (i >= 0) {
	binary[i--] = '0';
    }
    binary[8] = '\0';
}


void andOperation(char binary1[], char binary2[],char binary3[], char result[]) {
    for (int i = 0; i < 8; i++) {
	if (binary1[i] == '1' && binary2[i] == '1'&&binary3[i]=='1')
	    result[i] = '1';
	else
	    result[i] = '0';
    }
    result[8] = '\0';
}


int main() {
    int decimal1 ;
    int decimal2 ;
    int decimal3 ;
    cin>>decimal1>>decimal2>>decimal3;
    char binary1[9], binary2[9], binary3[9], result[9];

    decimalToBinary(decimal1, binary1);
    decimalToBinary(decimal3, binary3);
    decimalToBinary(decimal2, binary2);

    cout << "Binary 1: " << binary1 << endl;
    cout << "Binary 2: " << binary2 << endl;
    cout << "Binary 3: " << binary3 << endl;

    andOperation(binary1, binary2,binary3,result);

    cout << "AND Result: " << result << endl;
    return 0;
}
void createAndDisplayArray() {
  int length,i,x;
  cout << "Enter the length of the array: ";
  cin >> length;

  int* arr = new int[length];

  cout << "Enter the values of the array: ";
  for (i = 0; i < length; i++) {
    cin >> arr[i];
  }

  cout << "The array is: ";
  for ( i = 0; i < length; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  x =arr[0];
  for (i=0;i<length;i++){
  if(x<arr[i]){
   x=arr[i];
  }
  else{
   x=arr[0];
  }
  }
  cout <<x<<endl;
  delete[] arr;
}

void main() {
  clrscr();
  createAndDisplayArray();
  getch();
}

inline int add(int a, int b) {
    return a + b;
}

int main() {
    int x = 5;
    int y = 3;

    int result = add(x, y);

    cout << "The result of adding " << x << " and " << y << " is " << result << endl;

    return 0;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
	cout << arr[i] << " ";
    }
    cout << endl;
}

int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
	if (arr[i] > max) {
	    max = arr[i];
	}
    }
    return max;
}

int findMin(int arr[], int size) {
    int min = arr[0];
    for (int i = 1; i < size; i++) {
	if (arr[i] < min) {
	    min = arr[i];
	}
    }
    return min;
}

int findSum(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
	sum += arr[i];
    }
    return sum;
}

float findAverage(int arr[], int size) {
    int sum = findSum(arr, size);
    return (float)sum / size;
}

bool searchElement(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
	if (arr[i] == target) {
	    return true;
	}
    }
    return false;
}

void sortArray(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
	for (int j = i + 1; j < size; j++) {
	    if (arr[i] > arr[j]) {
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	    }
	}
    }
}

void reverseArray(int arr[], int size) {
    int start = 0;
    int end = size - 1;
    while (start < end) {
	int temp = arr[start];
	arr[start] = arr[end];
	arr[end] = temp;
	start++;
	end--;
    }
}


void printArray(int arr[], int size);
int findMax(int arr[], int size);
int findMin(int arr[], int size);
int findSum(int arr[], int size);
float findAverage(int arr[], int size);
bool searchElement(int arr[], int size, int target);
void sortArray(int arr[], int size);
void reverseArray(int arr[], int size);

int main() {
    int arr[5] = {4, 2, 7, 1, 3};

    cout << "Original array: ";
    printArray(arr, 5);

    cout << "Maximum element: " << findMax(arr, 5) << endl;
    cout << "Minimum element: " << findMin(arr, 5) << endl;
    cout << "Sum of elements: " << findSum(arr, 5) << endl;
    cout << "Average of elements: " << findAverage(arr, 5) << endl;

    int target = 2;
    if (searchElement(arr, 5, target)) {
	cout << "Element " << target << " found in the array." << endl;
    } else {
	cout << "Element " << target << " not found in the array." << endl;
    }

    sortArray(arr, 5);
    cout << "Sorted array: ";
    printArray(arr, 5);

    reverseArray(arr, 5);
    cout << "Reversed array: ";
    printArray(arr, 5);

    return 0;
}
void readString(char* str, int maxSize) {
    int i = 0;
    char c;

    cout << "Enter a string: ";

    while ((c = cin.get())!= '\n' && i < maxSize - 1) {
	str[i] = c;
	i++;
    }

    str[i] = '\0'; // null-terminate the string
}

void reverseString(char* str) {
  int length = 0;
  while (str[length]!= '\0') {
    length++;
  }

  int start = 0;
  int end = length - 1;

  while (start < end) {
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    start++;
    end--;
  }
}



int main() {
    char str[100];

    readString(str, 100);

    cout << "You entered: " << str << endl;

    reverseString(str);

  cout << "Reversed string: " << str << endl;

  return 0;
}
int isPalindrome(int num) {
    int temp, rev = 0;
    temp = num;

    while(temp!= 0) {
	rev = rev * 10 + temp % 10;
	temp /= 10;
    }

    return (rev == num);
}

void main() {
    int num;
    clrscr();

    cout << "Enter a number: ";
    cin >> num;

    if(isPalindrome(num))
	cout << "The number is a palindrome.";
    else
	cout << "The number is not a palindrome.";

    getch();
}
int length(char str[])
{
    int i = 0;
    while (str[i] != '\0')
	i++;
    return i;
}


int isPalindrome(char str[])
{
    int i, j, flag = 1;

    i = 0;
    j = length(str) - 1;

    while (i < j)
    {
	if (str[i] != str[j])
	{
	    flag = 0;
	    break;
	}
	i++;
	j--;
    }

    return flag;
}

void main()
{
    char str[100];

    cout << "Enter a string: ";
    cin >> str;

    if (isPalindrome(str))
	cout << "The string is a palindrome."<<endl;
    else
	cout << "The string is not a palindrome."<<endl;

    getch();
}
void removeDuplicates(int arr[], int &n) {
    int temp[100]; // temporary array to store unique elements
    int j = 0; // index for temp array

    for (int i = 0; i < n; i++) {
	int flag = 0; // flag to check if element is already present in temp array

	for (int k = 0; k < j; k++) {
	    if (arr[i] == temp[k]) {
		flag = 1;
		break;
	    }
	}

	if (flag == 0) {
	    temp[j] = arr[i];
	    j++;
	}
    }

    // copy unique elements back to original array
    for (int i = 0; i < j; i++) {
	arr[i] = temp[i];
    }

    n = j; // update the size of the array
}

int main() {
    int arr[100];
    int n;

    cout << "Enter the size of the array: ";
    cin >> n;

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
	cin >> arr[i];
    }

    removeDuplicates(arr, n);

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < n; i++) {
	cout << arr[i] << " ";
    }

    return 0;
}
class MyClass {
    int x;
    char y;
};

int main() {
    cout << "Size of MyClass: " << sizeof(MyClass) << " bytes" << endl;

    return 0;
}
void printArray(int arr[], int n) {
  int product = 1;
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
    for (int j = 0; j < n; j++) {
      if (j != i) {
	product *= arr[j];
      }
    }
    cout << product << " ";
    product = 1;
  }
  cout << endl;
}

int main() {
  int arr[] = {1, 2, 3, 4, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  printArray(arr, n);
  return 0;
}
void main()
{
    clrscr();
    int arr[100], n, i, product = 1;
    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements: ";
    for(i = 0; i < n; i++)
    {
	cin >> arr[i];
	if(arr[i]!= 0)
	    product *= arr[i];
    }

    for(i = 0; i < n; i++)
    {
	if(arr[i] == 0)
	{
	    cout << "Error: Cannot divide by zero!" << endl;
	}
	else
	{
	    if(product == 0)
	    {
		cout << "Product of rest elements divided by " << arr[i] << " is undefined." << endl;
	    }
	    else
	    {
		cout << "Product of rest elements divided by " << arr[i] << " is " << product / arr[i] << endl;
	    }
	}
    }

    getch();
}
class circle{
private:
int rad;
public: void getdata(){
printf("enter radius");
cin>>rad;
};
public: void shdata(){
cout<<"the radius of circle is"<<rad<<endl;
};
public: void setdata(int j){
rad=j;
};
circle(){
cout<<"hello"<<endl;
};
public: void area(){
 int a=22/7*2*rad;
 cout<<a<<endl;
};
};
void main(){
 circle r1,r2;
 r1.getdata();
 r2.getdata();
 r1.shdata();
 r2.shdata();
 r1.area();
 r2.area();

class MyClass {
private:
    int* ptr;
public:
    MyClass() {
    cout << "Constructor called!" <<endl;
	ptr = new int;
	*ptr = 0;
    }


   ~MyClass() {
    cout << "Destructor called!" <<endl;
	delete ptr;
    }

    void setValue(int value) {
	*ptr = value;
    }

    int getValue() {
	return *ptr;
    }
};

int main() {
    MyClass obj;
    obj.setValue(10);
    cout << "Value: " << obj.getValue() << endl;

    return 0;
}*/
#include <string.h>

class Person {
public:
    Person(char *name, int age) {
        strcpy(this->name, name);
        this->age = age;
    } // Constructor

    void greet() {
        cout << "Hello, my name is " << name << " and I am " << age << " years old." << endl;
    }

private:
    char name[50];
    int age;
};

class Employee : public Person {
public:
    Employee(char *name, int age, char *employeeId) : Person(name, age) {
        strcpy(this->employeeId, employeeId);
    } // Using the constructor of the Person class

    void displayEmployeeInfo() {
        greet(); // Using the greet method of the Person class
        cout << "My employee ID is " << employeeId << "." << endl;
    }

private:
    char employeeId[20];
};

void main() {
    // Using the constructor outside the class
    Person person("John", 30);
    person.greet();

    Employee employee("Jane", 25, "E1234");
    employee.displayEmployeeInfo();

    getch();
}