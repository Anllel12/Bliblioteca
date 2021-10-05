#include <iostream>
using namespace std;

int libros[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};  
string categoria[20] = {"Drama", "Accion", "Drama", "Accion", "Comedia", "Ficcion", "Ciencia", "Documental", "Drama", "Accion", "Comedia", "Ficcion", "Ciencia", "Documental", "Drama", "Accion", "Comedia", "Ficcion", "Ciencia", "Documental"};

class book{
    public:
        void checkBook();
};

void book::checkBook(){ //Comprueba qué libros hay disponibles en la biblioteca 

    int n = 1000;

    cout << "Seleccione el libro a comprobar: ";
    cin >> n;
    if(n <= 20){
        if((n%2) == 0){
            cout <<"El libro " << n <<" esta disponible\n";
        }
        else cout <<"El libro " << n <<" no esta disponible\n";
    }
    else cout <<"El libro " << n <<" no corresponde con ningun libro\n";
    
}

int main(int argc, char *argv[]){
    book bk;

    int select;

    cout <<"***BIBLIOTECA***\n";
    cout <<"0 - Salir \n";
    cout <<"1 - Listar libros \n";
    cout <<"2 - Controlar libros\n";
    cout <<"3 - Registrarse\n";
    cout <<"4 - Ver el historial de libros de una persona \n";
    cout <<"5 - Ver si una persona tiene un libro o no \n";
    cout <<"6 - Sacar/Devolver un libro \n";
    cout <<"¿Que operacion desea realizar?: ";

    cin >> select;

    switch(select) {
        case 0: return 0;break;
        case 1: return 0;break;
        case 2: bk.checkBook();break;
        case 3: return 0;break;
        case 4: return 0;break;
        case 5: return 0;break;
        case 6: return 0;break;
    }
    return 0;
}