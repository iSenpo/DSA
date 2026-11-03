#include <iostream>
using namespace std;
void NumberDecomposition(int n){
  if(n == 1){
    cout<<"(1  1)"<<endl;
    return;
  }
  int p = 2;
  while(n%p != 0){
    p++;
  }
  int a = 0;
  int temp = n;
  while(temp%p == 0){
    a++;
    temp /= p;
  }
  cout<<"("<<p<<"  "<<a<<")"<<endl;
  NumberDecomposition(temp);
}
int main (){
    int n;
    cin>>n;
    NumberDecomposition(n);
    return 0;
}