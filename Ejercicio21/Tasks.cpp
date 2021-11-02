/*
/ Programa de gestor de tareas en el cual se crean, editan y eliminan las diferentes tareas
/ Todas ellas asignadas a una persona en un tiempo determinado
/
/ Realizado por: Ángel Esquinas Puig
*/

#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

vector <string> listTasks = {};
vector <string> assignedTasks = {};
vector <string> dateTasks = {};

int u = 1;
int *pointer = NULL; //Inicializamos el puntero

void showTasks(){ // Muestra el array de lista

    pointer = &u; // Pongo un puntero porque me lo pide en la entrega
    *pointer = 1;

    for(int i = 0; i<listTasks.size(); i++) {
        cout << u << " -> " << listTasks[i] << " -> asignado a -> " << assignedTasks[i] << " -> el dia -> " << dateTasks[i] <<endl;
        *pointer = *pointer+1;
    } 
}


class task // Clase que contiene todo lo que tiene que ver con las tareas
{
    private:

        string nameTask; // candidata para el FreeSpace
        string assignTask; // candidata para el FreeSpace
        string dateTask;

        int x;

    public:
        void addTask(); // Funcion que añade tareas
        void removeTask(); // Funcion para eliminar tareas
        void editTask(); // Funcion para editar tareas
};

void task::addTask() // Funcion que añade tareas
{
    cout << "Escribe que tarea quieres realizar: \n";
    
    getline(cin, nameTask);

    cout << "Escribe a quien quieres asignar la tarea: \n";
    
    getline(cin, assignTask);

    try { // Pongo un try catch porque me lo pide en la entrega
        dateTask = "";
        while (dateTask.size() != 10)
        {
            cout << "Escribe a el dia que quieres finalizar la tarea (DD/MM/AAAA): \n";
            getline(cin, dateTask);          
        }
    }
    catch (exception e ){ 
        throw ;
    }

    cout << "Añadiendo la tarea: "<< nameTask << " y asignandola a : " << assignTask << " para el dia: " << dateTask <<endl;

    listTasks.push_back(nameTask);
    assignedTasks.push_back(assignTask);
    dateTasks.push_back(dateTask);
}

void task::removeTask() // Funcion para eliminar tareas
{
    cout << "Selecciona que tarea quieres eliminar: \n";

    showTasks();

    cin >> x;
    cin.ignore ( 100 , '\n'); 

    auto elementRemove = listTasks.begin() + (x-1);
    if (elementRemove != listTasks.end()) {
        listTasks.erase(elementRemove);
    }

    auto elementRemove1 = assignedTasks.begin() + (x-1);
    if (elementRemove1 != assignedTasks.end()) {
        assignedTasks.erase(elementRemove1);
    }

    auto elementRemove2 = dateTasks.begin() + (x-1);
    if (elementRemove2 != dateTasks.end()) {
        dateTasks.erase(elementRemove2);
    }

}

void task::editTask() // Funcion para editar tareas
{
    removeTask(); // Elimino la tarea que quiere editar

    addTask(); // Hago que la vuelva a escribir
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
    cout << "  5 - Salir" << endl;
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
            t.removeTask();

            showMenu();
            break;

        case 3: 
            t.editTask();

            showMenu();
            break;

        case 4:        
            showTasks();

            showMenu();
            break;

        case 5: return 0;    
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