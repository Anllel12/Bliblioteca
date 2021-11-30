/*
Como hemos podido observar en los apuntes, las pilas tienen un orden implícito directamente 
relacionado con la estructura de la misma, ergo, podría utilizarse para “ordenar” en nuestros programas.

    Crear una estructura (array o vector) que contenga una serie de números insertados con un valor aleatorio en los distintos nodos de la estructura.
    Utilizar una pila como pivote para ordenar de mayor a menor ( o a la inversa)
        La pila tiene que estar vacía al principio de la ejecución y al final.

Angel Esquinas Puig
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class pila
{
    private:

    public:
        pila();
        ~pila();

        vector <int> initial;
        vector <int> sort(vector <int> &input);
};

pila::pila() // Metemos los valores
{
    initial.push_back(34);
    initial.push_back(3);
    initial.push_back(31);
    initial.push_back(98);
    initial.push_back(92);
    initial.push_back(23);
}

pila::~pila()
{
}


vector <int> pila::sort(vector <int> &input) // Funcion para ordenar el vector con una pila
{
    stack<int> tmpStack;
 
    while (!input.empty())
    {
        int tmp = input.back(); // Guardamos el ultimo valor 
        input.pop_back(); // Eliminamos el el ultimo valor 
 
        while (!tmpStack.empty() && tmpStack.top() > tmp) // Hacemos esto mientras la Pila temporal no este vacia y el primer valor de la Pila no sea mayor al guardado
        {
            input.push_back(tmpStack.top());
            tmpStack.pop();
        }
 
        tmpStack.push(tmp);
    }

    while (!tmpStack.empty()) // Pasamos la pila al vector
    {
        input.push_back(tmpStack.top());
        tmpStack.pop(); // Vamos vaciando la pila por lo que se quedara vacia
    }
 
    return input; // Devolvemos el vector ordenado
}

int main()
{
    pila p; 

    cout << "Numeros sin ordenadar: \n";
 
    for (int i = 0; i < p.initial.size(); i++)
    {
        cout << p.initial.at(i) << " ";
    }
    
    cout << endl;

    p.sort(p.initial); // Mostramos el vector ya ordenado
    cout << "Numeros ordenados: \n";
 
    for (int i = 0; i < p.initial.size(); i++)
    {
        cout << p.initial.at(i) << " ";
    }
    
    return 0;
}