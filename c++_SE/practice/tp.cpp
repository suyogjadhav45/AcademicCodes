#include<iostream>
using namespace std;


void perimeter(int x){
    int a=4*x;
    cout<<"Perimeter of square is : "<<a<<endl;
}
void perimeter(int x,int y){
    int a=2*x+2*y;
    cout<<"Perimeter of Rectangle is : "<<a<<endl;
}

int main(){
    perimeter(5);
    perimeter(4,5);
    return 0;
}