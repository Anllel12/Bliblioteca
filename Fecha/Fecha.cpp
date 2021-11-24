/*
El programa ha de contener una clase Fecha con tres parámetros (día, mes, año)
    Esos parámetros son indefinidos en cuanto a tipo.
    La clase ha de tener 1 constructor:
        La inicialización siempre es por parte del usuario
            El usuario indica cada uno de los parámetros
    La clase ha de tener al menos, 1 función pública:
        Mostrar fecha


Angel Esquinas Puig
*/

#include <iostream>

using namespace std;

class Fecha
{
private:
    int dia;
    string mes;
    string año;
public:
    Fecha();
    ~Fecha();

    void elegirFecha();
    void mostarFecha();
};

Fecha::Fecha()
{
    dia = 1;
    mes = "";
    año = 1;
}

Fecha::~Fecha()
{
}

void Fecha::elegirFecha(){
    cout << "Dime un dia: ";
    cin >> dia;

    cout << "Dime un mes: ";
    cin >> mes;

    cout << "Dime un año: ";
    cin >> año;
}

void Fecha::mostarFecha(){

    cout << "El dia " << dia << " de " << mes << " el año " << año << " entendere las templates" << endl;
}

int main(int argc, char const *argv[])
{
    Fecha f;
    f.elegirFecha();
    f.mostarFecha();
    return 0;
}
