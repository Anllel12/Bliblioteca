/*
Como hemos podido observar en los apuntes, las pilas tienen un orden implícito directamente 
relacionado con la estructura de la misma, ergo, podría utilizarse para “ordenar” en nuestros programas.

    Crear una estructura (array o vector) que contenga una serie de números insertados con un valor aleatorio en los distintos nodos de la estructura.
    Utilizar una pila como pivote para ordenar de mayor a menor ( o a la inversa)
        La pila tiene que estar vacía al principio de la ejecución y al final.

Angel Esquinas Puig
*/

#include <iostream>
#include <stack>

using namespace std;

stack<int> sort(stack<int> &input) // Funcion para ordenar la pila con otra pila
{
    stack<int> tmpStack;
 
    while (!input.empty())
    {
        int tmp = input.top(); // Guardamos el primer valor 
        input.pop(); // Eliminamos el primer valor 
 
        while (!tmpStack.empty() && tmpStack.top() > tmp) // Hacemos esto mientras la Pila temporal no este vacia y el primer valor de la Pila no sea mayor al guardado
        {
            input.push(tmpStack.top());
            tmpStack.pop();
        }
 
        tmpStack.push(tmp);
    }
 
    return tmpStack; // Devolvemos la pila ordenada
}
 
// main function
int main()
{
    stack<int> initial;
    initial.push(34);
    initial.push(3);
    initial.push(31);
    initial.push(98);
    initial.push(92);
    initial.push(23);
 
    stack<int> sortStack = sort(initial); // Mostramos la Pila ya ordenada
    cout << "Numeros ordenados: \n";
 
    while (!sortStack.empty())
    {
        cout << sortStack.top()<< " ";
        sortStack.pop();
    }
    
    return 0;
}