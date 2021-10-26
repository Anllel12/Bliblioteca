//Ángel Esquinas Puig

//Imports de librerías de C++
#include <cstdlib>
#include <iostream>

//Espacio de nombres para utilizar el cout<< y cin>>
using namespace std;

//Clase hora
class hora {
    private:
        //Datos Privados de la clase
        
    public:
        //Constructores
        int h1 = 0; // Inicializo los valores
        int min1 = 0;
        int sec1 = 0;
        int h2 = 0;
        int min2 = 0;
        int sec2 = 0;
        
        //Métodos de la clase
        void visualizar(int h1, int min1, int sec1);
        void sumar(int h1, int h2 );
};

void hora::visualizar(int h1, int min1, int sec1){
    //Implementacion
    h1 = 21;
    min1 = 30;
    sec1 = 10;

    cout<< h1 << ":" << min1 << ":" << sec1 << "\n";

}

void hora::sumar(int h1, int h2 ){
    //Implementacion
    h1 = 21;
    h2 = 2;
    int h3 = h1 + h2;
    cout<< h3 << "\n";
}

int main(int argc, char *argv[])
{   
    hora ho;
    ho.visualizar(0,0,0);
    ho.sumar(0,0);

    int h = 5;
    int s = 4;
    int m = h+s;

    cout<< m << "\n";
    
return 0;
}