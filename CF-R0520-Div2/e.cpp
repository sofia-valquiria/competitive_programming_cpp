#include <iostream>

int factorial(int n){
    if(n==0){
        return 1;
    }
    return (factorial(n-1)*n);
}

using namespace std;
int main(){
    int n;
    double e;
    cout << "ingrese numero de convergente deseado (entero >= 1): ";
    cin >> n;
    e = 0;
    for(int i = 0; i<n ; i++){
        cout << "e(_c"<<(i+1)<<"): "<< e << endl;
        e += (float)(1)/factorial(i);
    };
    return 0;
}
