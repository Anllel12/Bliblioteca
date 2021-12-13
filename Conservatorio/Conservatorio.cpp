/*
Como hemos podido observar en los apuntes, las pilas tienen un orden implícito directamente 
relacionado con la estructura de la misma, ergo, podría utilizarse para “ordenar” en nuestros programas.

    Crear una estructura (array o vector) que contenga una serie de números insertados con un valor aleatorio en los distintos nodos de la estructura.
    Utilizar una pila como pivote para ordenar de mayor a menor ( o a la inversa)
        La pila tiene que estar vacía al principio de la ejecución y al final.

Angel Esquinas Puig
*/

#include <iostream>
#include <list>

using namespace std;

list <int> notas;
list <int> admitidos;
list <int>::iterator it;

void lista(){
    notas.sort();
    it = notas.begin();
    advance(it, notas.size()-5);
    admitidos.splice(admitidos.end(), notas, it, notas.end()); // Movemos los nombres a la otra caja por orden

    cout << "Admitidos -> \n";

    for(auto e:admitidos){
        cout << e << endl;
    }
    
}

int main(int argc, char const *argv[])
{
    int n;
    int x;
    cout << "Cuantas perosnas se han presentado a la prueba";
    cin >> x;
    for (int i = 0; i < x; i++)
    {
        cin >> n;
        notas.push_back(n);
    }
    lista();
    
    return 0;
}
