#include <iostream>
#include <vector>

using namespace std;
int main(){
    int cantElim, num, n;
    cin >> n;
    cantElim = 0;
    vector<int> nums;

    for(int j=0; j<n; j++){ //inicio en 1 pq primera iteracion afura
        cin >> num;
        nums.push_back(num);
    }

    for(int i=1; i<n; i++){ // no tiene sentido empezar en el primero; siempre el primero debe ser no nulo
        // debug line: cout << nums.at(i-1) << endl << nums.at(i) << endl << nums.at(i+1) << endl;
        if ((nums.at(i) == nums.at(i-1)+1) && ( num == nums.at(i+1)-1  || i == (n-1) )){
            cantElim++;
        }
    }

    cout << cantElim;

    return 0; }
