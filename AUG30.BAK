#include <iostream.h>
#include <conio.h>
/*
void count_good_pairs(int n, int arr[]) {
    int freq[1000] = {0}; 
    int good_pairs = 0;
    int i = 0;

    for (i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    for ( i = 0; i < 1000; i++) {
        int count = freq[i];
        good_pairs += count * (count - 1) / 2;
    }

    cout << good_pairs << endl;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int* arr = new int[n]; 
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    count_good_pairs(n, arr);
    delete[] arr; 
    getch(); 
    return 0;
}

void rotate_array(int N, int d, int arr[]) {
    d = d % N;
    int* temp = new int[N];
    int i = 0;
    for ( i = 0; i < N; i++) {
        temp[(i - d + N) % N] = arr[i];
    }
    for ( i = 0; i < N; i++) {
        arr[i] = temp[i];
    }
    delete[] temp; 
}

int main() {
    int N, d,i;
    cout << "Enter the size of the array: ";
    cin >> N;
    cout << "Enter the number of positions to rotate: ";
    cin >> d;
    int* arr = new int[N]; 
    cout << "Enter the array elements: ";
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    rotate_array(N, d, arr);
    cout << "Rotated array: ";
    for ( i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    delete[] arr; 
    getch();
    return 0;
}
*/
void rotate_array(int N, int d, int arr[]) {
    d = d % N;
    int* temp = new int[N];
    int i = 0;
    for (i = 0; i < N; i++) {
	temp[(i +d) % N] = arr[i];
    }
    for (i = 0; i < N; i++) {
        arr[i] = temp[i];
    }
    delete[] temp; 
}

int main() {
    int N, d,i;
    cout << "Enter the size of the array: ";
    cin >> N;
    cout << "Enter the number of positions to rotate: ";
    cin >> d;
    int* arr = new int[N]; 
    cout << "Enter the array elements: ";
    for (i = 0; i < N; i++) {
        cin >> arr[i];
    }
    rotate_array(N, d, arr);
    cout << "Rotated array: ";
    for ( i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    delete[] arr; 
    getch();
    return 0;
}