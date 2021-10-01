# include<iostream>
using namespace std;
void counting(int arr[], int n, int pos) {
    int count[10] = {0};
    int b[n] = {0};
    for(int i = 0; i < n; i++) {
        count[arr[i]/pos % 10]++;
    }
    for(int i = 1; i <= 10; i++) {
        count[i] = count[i] + count[i - 1];
    }
    for(int i = n - 1; i >= 0; i--) {
        b[--count[arr[i]/pos % 10]] = arr[i];
    }
    for(int i = 0; i < n; i++) {
        arr[i] = b[i];
    }
}
void radix(int arr[], int n) {
    int max = arr[0];
    for(int i = 1; i < n; i++) {
        if(max < arr[i]) {
            max = arr[i];
        }
    }
    int pos = 1;
    for(; max/pos > 0; pos = pos * 10) {
        counting(arr, n, pos);
    }
}
int main() {
    int a[5] = {100, 234, 234321, 99, 0};
    radix(a, 5);
    for(int i = 0; i < 5; i++) {
        cout<<a[i]<<endl;
    }
    return 0;
}
