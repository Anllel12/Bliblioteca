/*
/ Programa de gestor de tareas en el cual se crean, editan y eliminan las diferentes tareas
/ Todas ellas asignadas a una persona en un tiempo determinado
/
/ Realizado por: Ángel Esquinas Puig
*/

#include <iostream>
#include <vector>

using namespace std;

string names [3] = {"Angel", "Jorge", "Sara"};

vector <string> listTasks[10] = {};
vector <string> assignedTasks[10] = {};

void showArrays(){ // Muestra el array de lista
    for(auto& i : listTasks) {
        for(auto& k : i) {
            cout << k << " ";
        }
    }
}

class task // Clase que contiene todo lo que tiene que ver con las tareas
{
    private:

        string nameTask; // candidata para el FreeSpace
        string assignTask; // candidata para el FreeSpace

    public:
        void addTask(); // Funcion que añade tareas
};

void task::addTask() // Funcion que añade tareas
{
    cout << "Escribe que tarea quieres realizar: \n";
    
    getline(cin, nameTask);

    cout << "Escribe a quien quieres asignar la tarea: \n";
    
    getline(cin, assignTask);

    cout << "Añadiendo la tarea: "<< nameTask << " y asignandola a : " << assignTask << "\n";

    listTasks->push_back(nameTask);
    assignedTasks->push_back(assignTask);

    showArrays();
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
    cin.ignore ( 100 , '\n');

    switch (n)
    {
    case 1: 

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