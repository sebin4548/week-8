
#include <iostream>
#include<iomanip>
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
int NumPaths(int row, int col, int n){
    if((row ==n) || (col ==n)) return 1;
    else return NumPaths(row+1, col, n) + NumPaths(row, col + 1, n);
}
int mat[10][10];
int NumPaths_adv(int row, int col, int n){
    if(mat[row][col] != 0){
        return mat[row][col];
    }else{
        if((row ==n) || (col ==n)) {
            mat[row][col] = 1;
            return 1;
        }
        else {
            
            mat[row][col] = NumPaths_adv(row+1, col, n) + NumPaths_adv(row, col + 1, n);
            return mat[row][col];
        }
    }
    
}
class Node{
public:
    int value;
    Node* next;
};
class UnsortedType{
    
public:
    Node* First;
    UnsortedType(){
        First = new Node();
        
        First->next = NULL;
    }
    Node* MinLoc(Node* location, Node* minNode){
        if(location != NULL){
            if(location->value < minNode->value){
                return MinLoc(location->next, location);
            }
            else{
                return MinLoc(location->next, minNode);
            }
        }else return minNode;
    }
    Node* MinLOC(Node* location){
        if(location == NULL){
            return NULL;
        }
        else if(location->next == NULL){
            return location;
        }
        else{
            Node* minPtr = MinLOC(location->next);
            if(location->value < minPtr->value){
                return location;
            }
            return minPtr;
        }
    }
    void Sort(Node *location){
        Node* minPtr;
        int temp;
        if(location != NULL){
            minPtr =  MinLoc(location, location);
            temp = minPtr->value;
            minPtr->value = location ->value;
            location -> value = temp;
            Sort(location ->next);
        }
    }
    void Enque(int x){
        Node* current = First;
        while(current->next != NULL){
            current = current -> next;
        }
        Node* en = new Node();
        en -> value = x;
        en -> next = NULL;
        current->next = en;
    }
    void Print(){
        Node* current = First;
        while(current->next != NULL){
            cout<<current->next-> value;
            current = current -> next;
        }
    }
};
int SumSquares_a(Node* list){
    if(list->next != NULL){
        return SumSquares_a(list->next) + (list->value)*(list->value);
    }else{
        return (list->value)*(list->value);
    }
}
int main(){
    cout<<Fibonacci_recursive(10)<<endl;
    cout<<Fibonacci_non_recursive(10)<<endl;
    cout<<SqrRoot(9, 0.1, 0.01)<<endl;
    cout<<SqrRoot(9, 0.1, 0.01)<<endl;
    cout<<NumPaths(1, 1, 6)<<endl;
    cout<<NumPaths_adv(1, 1, 6)<<endl;

    UnsortedType x;
    x.Enque(10);
    x.Enque(2);
    x.Enque(3);
    x.Enque(4);
    x.Enque(5);
    x.Print();
    Node* k = x.MinLoc(x.First->next, x.First->next);
    Node* l = x.MinLOC(x.First->next);
    cout<<endl<<k->value<<endl;
    cout<<endl<<l->value<<endl;
//    cout<<endl<<SumSquares_a(x.First);
    x.Sort(x.First->next);
    x.Print();
}
