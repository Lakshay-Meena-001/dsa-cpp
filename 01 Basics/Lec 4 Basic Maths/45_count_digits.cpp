#include <bits/stdc++.h>
using namespace std;

int countDigits(int n) {
    if (n == 0) return 1;
    n = abs(n); 
    
    int count = 0;
    while (n > 0) {
        n /= 10;
        count++;
    }
    return count;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << "Total digits: " << countDigits(num);
    return 0;
}
/*
if the no is dividible by some no then the time complexity will be log n base k where k is the no by which we are dividing
here we are dividing by 10 so the time complexity will be log n base 10
*/