using namespace std;

#include <string>
#include <iostream>

int main() 
{
    int A, B, C;
    cin >> A >> B >> C;
    if ((B-A)%C==0){
        cout << "S";
        return 0;
    }
    cout << "N";
    return 0;
}