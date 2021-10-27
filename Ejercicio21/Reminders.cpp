/*
/ Programa de gestor de tareas en el cual se crean, editan y eliminan las diferentes tareas
/ Todas ellas asignadas a una persona en un tiempo determinado
/
/ Realizado por: Ángel Esquinas Puig
*/

#include <iostream>

using namespace std;

string names [5] = {"Ángel Esquinas", "Ruben Hijosa", "Sara Rodrigo"};

class menu
{
private:
    int n;
public:
   int showMenu(/* args */);
};

int menu::showMenu(/* args */)
{
    cout << "Selecciona una de las opciones: \n";
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
        cout << "¿Porque no pones un numero de los que hay? \n\n";
        showMenu();
        break;
    }

}


int main(int argc, char const *argv[])
{
    menu m;

    m.showMenu();
}