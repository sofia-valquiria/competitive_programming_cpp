using namespace std;

#include <iostream>

int main()
{
    int n, m, x, y, k, xConInes;
    cin >> n >> m;

    int totales[n+1]; //ines = n (pq 0 indexed arrays)
    for (int i = 0; i <= n ; i++) {
        totales[i] = 0; //inicializo en 0
    }
    int decisiones[n+1]; //ines = n
    for (int i = 0; i < m; i++) { //cant de rondas
        k=0; //cada ronda se resetea la cantidad de jugadores para dividir x oro
        cin >> x >> y;
        for (int j = 0; j < n; j++) {//cant de jug
            cin >> decisiones[j];
            if(decisiones[j]==1){ //si eligio 1, aumento k en 1
                k++;
            }
        }//fin carga decisiones
        xConInes = (x/(k+1)); //variable debugeadora
        if(xConInes>=y){ //contando ines
            decisiones[n]=1; //decis. de ines
            k++; //contamos a Ines en la dist. de X
            for (int j = 0; j <= n; j++) {
                if(decisiones[j]==1){
                    totales[j]+=(x/k);
                }else{
                    totales[j]+=y;
                }
            } //termina carga de resultados si ines es 1
        }else{
            decisiones[n]=2; //decis. Ines
            for (int j = 0; j <= n; j++) {
                if(decisiones[j]==1){

                }else{
                    totales[j]+=y;
                }
            } //termina carga de resultados si ines es 2
        }
    } //fin for ronda

    //Salida
    for(int i = 0; i <= n; i++)
    {cout << totales[i] << endl;}

    return 0;
}
