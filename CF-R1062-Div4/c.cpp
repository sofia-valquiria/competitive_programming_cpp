#include <iostream>
using namespace std;
int main(){
    int t, n, jAct, contP, contI, contarP[5][2], contarI[5][2];  //arrays para llevar cuenta de nums
    cin >> t;   /* ME ACABO DE DAR CUENTA QUE ESTA SOL NO FUNCA PORQUE NO SON 1 DIGIT INT, SON 1<n<100000 D:*/
    for (int f = 0; f < 10; f++){
        if (f & 1){                 //impar bitwise check (0...01 si es impar)
            contarI[f][1] = f;      //(mejora ligera a mod 2 par check)
            contarI[f][2] = 0;
        }else{                      // (00...00 si es par)
            contarP[f][1] = f;
            contarP[f][2] = 0;
        }
    }
    for (int i = 0; i < t; i++) {      // interates per test case
        cin >> n;                     // n cantidad de juguetes
        for (int j = 0; j < n; j++){ // itera cant de juguetes
            int jug[n],
            contP = 0;
            contI = 0;
            int * ptrJug = &jug[0];
            cin >> jAct;
            if(jAct & 1){       // (1...01 & 1) = 0...001 (true) si es impar
                jug[j]=jAct;
                contarI[jAct][2] = jAct;
                contI++;
            }else{
                jug[j]=jAct;
                contarI[contI][2] = jAct;
                contI++;
            }

        }


    }

    return 0;
}
