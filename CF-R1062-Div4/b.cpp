#include <iostream>
#include <unordered_map>
using namespace std;
int main(){
    int q, n;
    string s, t;
    cin >> q;
    bool esPosible = true;

    unordered_map<char, int> ms;
    unordered_map<char, int> mt;


    for (int j = 0; j < q; j++){
        cin >> n;
        cin >> s >> t;
        for(int i = 97; i < 123; i++){
            char c = i;
            ms[c, 0];
            mt[c, 0];
        }

        for (int i = 0; i < n; i++){
            char c = s[i];
            ms[c]++;
            char d = t[i];
            mt[d]++;
        }

        for(int i = 0; i < n; i++){
            if(ms[i+97]!=mt[i+97]){
                esPosible = false;
                i = n;
            }
        }

        if(esPosible){
            cout << "yes";
        }else{ cout << "no";}
    }
    return 0;
}
