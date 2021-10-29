#include<iostream>
#include <vector>

using namespace std;

vector <string> listTasks[10] = {};

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

    cout << "Añadiendo la tarea."<< nameTask;

    listTasks->push_back(nameTask);
}
int main(int argc, char const *argv[])
{
    task t;
    t.addTask();

}
