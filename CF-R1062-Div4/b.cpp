#include <iostream>
#include <unordered_map>
using namespace std;
int main(){
    int q, n;
    string s, t;
    cin >> q;
    bool esPosible = true;

    unordered_map<char, int> ms; //diccionarios (arreglos con clave char)
    unordered_map<char, int> mt;



    for (int j = 0; j < q; j++){
        cin >> n;
        cin >> s >> t;

        for(int i = 97; i < 123; i++){ // (re)inicializo los diccionarios
            char c = i;
            ms[c] = 0;
            mt[c] = 0;                  // pq dsps necesito incrementarlos en 1
        }

        for (int m = 0; m < n; m++){
            char c = s[m];
            ms[c]++;
            char d = t[m];
            mt[d]++;
        }
        for(int k = 97; k < 123; k++){ //aca taba el HDP error estuve como 4 horas total buscandote
            if(ms[k]!= mt[k]){         // mis iteraciones se basaban en largo de palabra y no en
                esPosible = false;     // largo del diccionario ;_;
            }
        }

        if(esPosible){
            cout << "yes\n";
        }else{ cout << "no\n";}
        esPosible = true;
    }
    return 0;
}
/* test case:
5
7
humitsa mitsuha
4
orhi hori
6
aakima makima
6
nezuqo nezuko
6
misaka mikasa */
