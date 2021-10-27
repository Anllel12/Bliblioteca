/*
/ Programa de gestor de tareas en el cual se crean, editan y eliminan las diferentes tareas
/ Todas ellas asignadas a una persona en un tiempo determinado
/
/ Realizado por: Ángel Esquinas Puig
*/

#include <iostream>

using namespace std;

string names [5] = {"Ángel Esquinas", "Ruben Hijosa", "Sara Rodrigo"};

class task // Clase que contiene todo lo que tiene que ver con las tareas
{
private:

    string nameTask = ""; // candidata para el FreeSpace

public:
    void addTask(); // Funcion que añade tareas
};

void task::addTask() // Funcion que añade tareas
{
    cin >> nameTask;
}

class menu // Clase que contiene todo lo utilizado en el menu
{
private:
    task t;

    int n;

public:
   int showMenu(); // Funcion que muestra el menu y te hace elegir una funcion
};

int menu::showMenu() // Funcion que muestra el menu y te hace elegir una funcion
{
    cout << "\nSelecciona una de las opciones: \n";
    cout << "  1 - Crear una tarea" << endl;
    cout << "  2 - Borrar una tarea" << endl;
    cout << "  3 - Editar una tarea" << endl;
    cout << "  4 - Ver tareas" << endl;
    cout << "  5 - Ver tareas mar urgentes" << endl;
    cout << "  6 - Salir" << endl;
    cout << ">>: "; 
    cin >> n;

    switch (n)
    {
    case 1: 
        cout << "Escribe que tarea quieres realizar: \n";

        t.addTask();

        showMenu();
        break;

    case 2: 
        
        break;

    case 3: 
        
        break;

    case 4: 
        
        break;

    case 5: 
        
        break;
    
    case 6: return 0;
        break;

    default:
        cout << "¿Porque no pones un numero de los que hay? \n";

        showMenu();
        break;
    }
}


int main(int argc, char const *argv[])
{
    menu m;

    m.showMenu();
}