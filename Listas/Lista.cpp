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

list <string> caja1;

int u = 1; // Valor auxiliar

class cliente
{
    private:
        string name; // Nombre de los clientes
        string t; // Valor auxiliar

        bool next=true;
    public:         
        cliente();
        ~cliente();

        void names(); // Ponemos el nombre de elos clientes
};

cliente::cliente()
{
}

cliente::~cliente()
{
}

void cliente::names(){ // Añadimos los clientes que hay en la cola de la caja 1

    cout << "Dime los nombre del cliente " << u << " que hay en la caja 1: \n";
    cin >> name;
    caja1.push_back(name); // Añadimos a la lista el cliente
    cout << "¿Hay mas clientes?: \n";
    cin >> t;
    u++;

    while (next) // Entra en bucle hasta que ya no quiere añadir mas clientes
    {
        if (t=="s" || t=="S") // Comprobamos su respuesta
        {
            cout << "Dime los nombre del cliente " << u << " que hay en la caja 1: \n";
            cin >> name;
            caja1.push_back(name); // Añadimos a la lista el cliente
            cout << "¿Hay mas clientes?: \n";
            cin >> t;
            u++;
        }
        else{
            next = false;
        }
    }
}

class caja
{
    private:
        string x; // Valor auxiliar
        
        list <string> caja2;
        list <string>::iterator it;
        
    public:
        cliente cl;

        caja();
        ~caja();

        int spliceCaja();
};

caja::caja()
{
}

caja::~caja()
{
}

int caja::spliceCaja(){ // Partimos la caja1 en la caja2 si se producen una serie de condiciones

    while (caja1.size()<5) // La primera condicion es que haya al menos 5 personas en la caja para abrir otra
    {
        cout << "Son pocos clientes para abrir otra caja tiene que haber mas de 5 para abrirla\n";
        cout << "¿Quiere añadir mas clientes?: \n";
        cin >> x;

        if (x=="s" || x=="S")
        {
            cl.names();
        }
        else{
            cout << "Lo siento aqui termina todo \n";
            return 0;
        }
    }
    
    it = caja1.begin();
    advance(it,caja1.size()/2); // Partimos por la mitad la caja1
    caja2.splice(caja2.end(), caja1, it, caja1.end()); // Movemos los nombres a la otra caja por orden

    cout << "Caja 1: \n";

    for(auto e:caja1){
        cout << e << endl;
    }

    cout << "Caja 2: \n";

    for(auto e:caja2){
        cout << e << endl;
    }
}

int main(int argc, char const *argv[])
{
    cliente cl;
    caja c;

    cl.names(); // Añadimos los clientes que hay en la cola de la caja 1
    c.spliceCaja(); // Partimos la caja1 en la caja2 si se producen una serie de condiciones
    return 0;
}