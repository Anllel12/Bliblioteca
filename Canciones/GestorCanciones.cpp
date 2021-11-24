/*
Se le pide al alumno que realice un gestor de canciones con las siguientes especificaciones:

    Las canciones tienen 2 parámetros 
        Nombre
        Artista(s) 
    El artista tiene 1 parámetro:
        Nombre
    La aplicación debe:
        Insertar una canción
        Buscar una canción
        Borrar una canción


Angel Esquinas Puig
*/

#include <iostream>
#include <vector>

using namespace std;

vector <string> listArtist = {};
vector <string> listSongs = {};


void showSongs(){ // Muestra el array de lista

    int u = 1;

    for(int i = 0; i<listSongs.size(); i++) {
        cout << u << " -> " << listSongs[i] << " -> del autor -> " << listArtist[i] <<endl;
        u = u+1;
    } 
}

class artist
{
    private:
        string name;
    public:
        void setName();
        ~artist();
};

void artist::setName()
{
    cout << "Escribe el nombre del autor: \n";
    
    getline(cin, name);

    listArtist.push_back(name);
}

artist::~artist()
{
}

class songs
{
    private:
        artist a;
        
        string song;
        string t;
        int x;
    public:

        void addSong();
        void removeSong();
        void editSong();
        void searchSong();
        ~songs();
};

void songs::addSong() // Añade canciones
{
    cout << "Escribe que cancion quieres añadir: \n";
    
    getline(cin, song);

    a.setName();

    cout << "Añadiendo la cancion: "<< song << " del autor : " << listArtist.back() <<endl;

    listSongs.push_back(song);
}

void songs::removeSong() // Funcion para eliminar canciones
{
    cout << "Selecciona cancion que quieres eliminar: \n";

    showSongs();

    cin >> x;
    cin.ignore ( 100 , '\n'); 

    auto elementRemove = listSongs.begin() + (x-1);
    if (elementRemove != listSongs.end()) {
        listSongs.erase(elementRemove);
    }

    auto elementRemove1 = listArtist.begin() + (x-1);
    if (elementRemove1 != listArtist.end()) {
        listArtist.erase(elementRemove1);
    }
}

void songs::editSong() // Funcion para editar canciones
{
    removeSong(); // Elimino la cancion que quiere editar

    addSong(); // Hago que la vuelva a escribir
}

void songs::searchSong(){ // Busco las canciones
    cout << "Escribe la cancion que quieres buscar: \n";

    getline(cin, t);

    for(int i = 0; i<listSongs.size(); i++) {
        if (listSongs[i] == t)
        {
            cout << listSongs[i] << " -> del autor -> " << listArtist[i] <<endl;
        }      
    } 
}

songs::~songs()
{
}

class menu // Clase que contiene todo lo utilizado en el menu
{
    private:
        songs s;

        int n;

    public:

    int showMenu(); // Funcion que muestra el menu y te hace elegir una funcion
};

int menu::showMenu() // Funcion que muestra el menu y te hace elegir una funcion
{
    cout << "\nSelecciona una de las opciones: \n";
    cout << "  1 - Añadir una cancion" << endl;
    cout << "  2 - Borrar una cancion" << endl;
    cout << "  3 - Editar una cancion" << endl;
    cout << "  4 - Buscar una cancion" << endl;
    cout << "  5 - Ver canciones" << endl;
    cout << "  6 - Salir" << endl;
    cout << ">>: "; 
    cin >> n;
    cin.ignore ( 100 , '\n');

    switch (n)
    {
        case 1: 
            s.addSong();

            showMenu();
            break;

        case 2: 
            s.removeSong();

            showMenu();
            break;

        case 3: 
            s.editSong();

            showMenu();
            break;

        case 4: 
            s.searchSong();

            showMenu();
            break;

        case 5:        
            showSongs();

            showMenu();
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

    cout << "\nBienvenido al Gestor de canciones\n";
    m.showMenu();
    return 0;
}
