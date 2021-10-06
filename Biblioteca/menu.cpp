#include <iostream>
using namespace std;

int libros[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
int disponibilidad[20] = {1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1,};  
string categoria[20] = {"Drama", "Accion", "Drama", "Accion", "Comedia", "Ficcion", "Ciencia", "Documental", "Drama", "Accion", "Comedia", "Ficcion", "Ciencia", "Documental", "Drama", "Accion", "Comedia", "Ficcion", "Ciencia", "Documental"};

class book{

    private:
        int n = 1000; //Libro seleccionado
        
        bool disp = true; //Saber disponibilidad

        string l = ""; //Valor dado para afirmar o denegar accion

    public:
        void checkBook(); //Comprueba qué libros hay disponibles en la biblioteca 
        void takeGiveBook(); //Saca o duvuelve un libro 
};

void book::checkBook(){ //Comprueba qué libros hay disponibles en la biblioteca 

    cin >> n;
    if(n <= 20){        
        if(disponibilidad[n] == 0){
            cout <<"El libro " << n <<" esta disponible\n";
            disp = true;
        }
        else{
            cout <<"El libro " << n <<" no esta disponible\n";
            disp = false;
        }
    }
    else cout <<"El libro " << n <<" no corresponde con ningun libro\n";
    
}

void book::takeGiveBook(){ //Saca o lo devuelve un libro 

    checkBook(); //Comprobamos que esta disponible

    if (disp){ //Lo sacamos si esta disponible
        cout <<"El libro " << n <<" sera sacado de la biblioteca\n";
        disponibilidad[n] = 1;
    }
    else{ //Lo devolvemos si no esta disponible
        cout <<"¿Quiere realizar una devolucion? (SI/NO): ";
        cin>> l;
        if (l == "SI"){
            cout<< "El libro " << n <<" sera devuelto a la biblioteca\n";
            disponibilidad[n] = 0;
        }
        else{
            cout<< "Gracias por utilizar la aplicación\n";
        }
        
        disponibilidad[n] = 1;
    }
    
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
        case 2: cout << "Seleccione el libro a comprobar: "; bk.checkBook() ;break;
        case 3: return 0;break;
        case 4: return 0;break;
        case 5: return 0;break;
        case 6: cout << "Seleccione el libro a sacar: "; bk.takeGiveBook() ;break;
    }
    return 0;
}