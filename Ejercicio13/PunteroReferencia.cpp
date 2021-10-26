
/*Ejercicio para comrpobar que un valor pasando 
por el puntero o sin parsar por el es igual despues de una funcion.
*/


#include <iostream>

using namespace std;

int dato;

class puntero
{
    private:
        int *punteros = NULL; //Inicializamos el puntero
        int numero = dato; //Inicializamos el valor
    public:
        void calcula();
};
void puntero::calcula()
{
    numero = dato;
    punteros = &numero; //Apuntamos el puntero a la direccion del valor

    *punteros = *punteros + 10;
    cout << "Valor funcion puntero: " << numero <<"\n";
}

class sinPuntero
{
    private:
        int numero2 = dato;
    public:
        void calcula2();
};

void sinPuntero::calcula2()
{
    numero2 = dato;
    numero2 = numero2 + 10;
    cout << "Valor funcion normal: " << numero2 <<"\n";
}

int main(int argc, char const *argv[])
{
    sinPuntero sp;
    puntero p;

    cout << "Introduce un numero: \n";
    cin >> dato;

    cout << "Valor inicial: " << dato <<"\n";
    sp.calcula2();
    p.calcula();

    return 0;
}
