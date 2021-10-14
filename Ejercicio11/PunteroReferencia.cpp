#include <iostream>

using namespace std;

int dato;

class puntero
{
    private:
        int *punteros = NULL;
        int numero = dato;
    public:
        void calcula();
};
void puntero::calcula()
{
    numero = dato;
    punteros = &numero;

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
