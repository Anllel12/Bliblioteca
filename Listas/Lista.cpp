/*
Vamos a desatascar el supermercado

    2 clases, Caja y Cliente
        Caja = Número de Caja, lista de clientes
        Cliente= nombre
    Cuando se abre una caja nueva se transfieren (en orden) los clientes a partir de cierto rango
        Implementaremos dicha transferencia entre cajas 
            (No hay control sobre el número máximo de clientes para la transferencia, no es necesario automatizarlo de momento)
        Si no están todos en fila, es normal preguntar quién es el último (lo implementamos por caja)
        La persona encargada de despacharnos en algún caso podrá preguntar quién es el siguiente (lo implementamos por caja)
            Asumimos que el primero/a de la lista ha sido atendido/a


Angel Esquinas Puig
*/

#include <iostream>
#include <list>

using namespace std;

class cliente
{
    private:
        string name;
    public:       
        cliente();
        ~cliente();

        void names();
};

cliente::cliente()
{
}

cliente::~cliente()
{
}

void cliente::names(){
    cout << "Dime los nombre de las personas que hay en la caja 1: \n";
    cin << name;
}

class caja
{
    private:
        list <string> caja1;
        list <string> caja1;
        list <int>::iterator it;

        cliente cl;
        
    public:
        caja();
        ~caja();

        void spliceCaja();
};

caja::caja()
{
}

caja::~caja()
{
}

void caja::spliceCaja(){
}

int main(int argc, char const *argv[])
{
    caja c;
    c.spliceCaja();
    return 0;
}