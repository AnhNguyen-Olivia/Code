#include<stdio.h>
#include<iostream>
using namespace std;
int add(int a, int b);
double add(double a, double b);
int add(int a, int b) { return a + b; }
double add(double a, double b) { return 1.0 + a + b; }
int main() {
    cout << add(1.0, 1.0) << endl;
}

