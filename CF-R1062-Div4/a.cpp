#include <iostream>
using namespace std;
int main(){
    int nSticks, a, b, c, d;
    cin >> nSticks;
    for(int i=0; i<nSticks; i++){
        cin >> a >> b >> c >> d;
        if(a == b && c == d && a == c){
            cout << "yes\n";
        }else{
            cout << "no\n";
        };
    };
    return 0;
}
