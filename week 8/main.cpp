
#include <iostream>
#include <cmath>
//#include "fibo.cpp"
using namespace std;
double SqrRoot(double number, double approx, double tol){
    if(abs(approx*approx - number) <= tol){
        return approx;
    }else{
        approx = (approx*approx + number) / (2*approx);
        
        return SqrRoot(number, approx, tol);
    }
}
double SqrRoot_non(double number, double approx, double tol){
    while(abs(approx*approx - number) >= tol){
        approx = (approx*approx + number) / (2*approx);
    }
    return approx;
}
int Fibonacci_recursive(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(n == 2) return 1;

    return Fibonacci_recursive(n - 1) + Fibonacci_recursive(n - 2);
}
int Fibonacci_non_recursive(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(n == 2) return 1;
    int a = 1, b = 1;
    int i = 1;
    int temp = 1;
    while(i < n){
        i++;
        temp = b;
        b = a+b;
        a = temp;
    }
    return temp;
}
int main(){
    cout<<Fibonacci_recursive(10)<<endl;
    cout<<Fibonacci_non_recursive(10)<<endl;
    cout<<SqrRoot(9, 0.1, 0.01)<<endl;
    cout<<SqrRoot(9, 0.1, 0.01);
}
