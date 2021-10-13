#include <iostream>
#include <cstdlib>

using namespace std;

class libro 
{
private:
    string titulo, categoria;
    bool disponible;

public:
    libro(string tit, string cat, bool disp) : titulo(tit), categoria(cat), disponible(disp) {};
    libro() {};

    void printLibro();
    string getLibro();

    // Editar un libro para decir que ya está o no disponible
    void setDisp(bool d) 
    {
        disponible = d;
    }
    // Retornar si el libro está disponible
    bool getDisp() 
    {
        return disponible;
    };
    // Retorna el titulo del libro
    string getTitulo() 
    {
        return titulo;
    }
    // Retorna el titulo del libro
    string getCategoria() 
    {
        return categoria;
    }
};

// Imprimir por pantalla el libro
void libro::printLibro() 
{
    cout << titulo << " - " << categoria << endl;
}

// Retornar el libro, su categoría y si está disponible o no
string libro::getLibro() 
{
    string libro = titulo + " - " + categoria;

    return libro;
};

class persona 
{
private:
    string nombre, dni;
    libro actual;
    libro historial[5];

public:
    persona(string no, string dn, libro act, libro hist[5]);

    persona() {}

    void getHistorial();
    void tieneLibro();

    // Retorna el libro actual de la persona
    libro getActual() 
    {
        return actual;
    }
    // Retorna el nombre y apellidos de la persona
    string getNombre() 
    {
        return nombre;
    }
    libro getHistorialItem() 
    {
        return historial[1];
    }
    void setLibro(libro l) 
    {
        actual = l;
    }
    void setHistorial(libro l) 
    {
        historial[4] = historial[3];
        historial[3] = historial[2];
        historial[2] = historial[1];
        historial[1] = historial[0];
        historial[0] = l;
    }

    void printPersona();
};

// Constructor de persona
persona::persona(string no, string dn, libro act, libro hist[5]) 
{ 
    nombre = no;
    dni = dn;
    actual = act;

    for (int i = 0; i < 5; i++) {
        historial[i] = hist[i];
    }
}

// Si la persona seleccionada tiene libro se imprime por pantalla
void persona::tieneLibro() 
{
    if (actual.getTitulo() != "") 
    {
        cout << nombre << " tiene el libro: ";
        actual.printLibro();
    } else 
    {
        cout << nombre << " no tiene ningun libro." << endl;
    }
}

// Se imprime por pantalla los libros del historial de la pesona
void persona::getHistorial() 
{
    for (int i = 0; i < 5; i++) 
    {
        cout << i << " libro: " << historial[i].getLibro() << endl;
    }

}

// Imprimir por pantalla el libro
void persona::printPersona() 
{
    cout << nombre << " - " << dni << endl;
}


void printListaPersonas (persona personas[4]) 
{
    cout << endl;
    cout << "[I] Lista personas registradas:" << endl;

    for (int i = 0; i < 4; i++) 
    { 
            personas[i].printPersona();
    }
}

libro libros[20];

//IMPRIMIR LISTA DE LIBROS DISPONIBLES
void printListaLibros (libro libros[20]) 
{
    cout << endl;
    cout << "[I] Lista libros disponibles:" << endl;

    for (int i = 0; i < 20; i++) 
    {
        if (libros[i].getDisp()) 
        {
            libros[i].printLibro();
        }
    }
}

//DESASIGNAR LIBRO A PERSONA
libro desasignarLibro (libro libros[20], persona p, persona personas[3]) 
{
    libro libroRet;

    for (int i = 0; i < 20; i++) 
    {
        if (p.getActual().getTitulo() == libros[i].getTitulo())
        {
            cout << "DESASIGNANDO EL LIBRO " << libros[i].getTitulo() << " a " << p.getNombre() << endl;
            libroRet = libros[i];
            libros[i].setDisp(true);

            // Se recorre la lista de personas 
            for (int j = 0; j < 4; j++)
            {
                // Si el nombre de la persona coincide se desasigna el libro actual y se actualiza su historial
                if (p.getNombre() == personas[j].getNombre())
                {
                    personas[j].setLibro({});
                }
            }
        }
    }

    if (libroRet.getTitulo() == "") 
    {
        libroRet = p.getActual();
    }
    
    return libroRet;

}

//ADJUDICAR LIBRO A PERSONA
libro darLibro (libro l, libro libros[20], persona p, persona personas[3]) 
{
    libro libroRet;

    for (int i = 0; i < 20; i++) 
    {
        // Si el libro que se quiere dar existe...
        if (l.getTitulo() == libros[i].getTitulo()) 
        {
            // Si el libro que se quiere dar no está disponible, no se asigna
            if (!libros[i].getDisp()) 
            {
                cout << "No se puede asignar " << libros[i].getTitulo() << ", ya esta asignado." << endl;
            } else 
            {
                cout << "DANDO LIBRO // " << libros[i].getTitulo() << endl;
                libroRet = libros[i];
                libros[i].setDisp(false);

                // Se recorre la lista de personas 
                for (int j = 0; j < 4; j++)
                {
                    // Si el nombre de la persona coincide se asigna el libro actual y se actualiza su historial
                    if (p.getNombre() == personas[j].getNombre())
                    {
                        string lDisp = personas[j].getActual().getTitulo();
                        personas[j].setLibro(l);
                        personas[j].setHistorial(l);
                        cout << "Se ha asignado " << l.getTitulo() << " a " << personas[j].getNombre() << endl;

                        // Se asigna al anterior libro de la persona la disponiblidad a true
                        for (int k = 0; k < 20; k++) 
                        {
                            //cout << lDisp.getTitulo() << endl;
                            
                            if (lDisp == libros[k].getTitulo())
                            {
                                cout << "BuenasTardes " << endl;
                                libros[k].setDisp(true);
                            }
                        }
                        
                    }
                }
            }
        }
    }

    if (libroRet.getTitulo() == "") 
    {
        libroRet = p.getActual();
    }
    
    return libroRet;
}

string leerString(string txt) 
{
    string ret;
    
    return ret;
}

int mostrarOpciones() 
{
    cout << "[MENU] Selecciona una de las opciones: " << endl;
    cout << "  1 - Comprobar que libros hay disponibles" << endl;
    cout << "  2 - Ver el historial de libros de una persona" << endl;
    cout << "  3 - Ver si una persona tiene un libro o no" << endl;
    cout << "  4 - Sacar un libro (asignárselo a una persona)" << endl;
    cout << "  5 - Devolver un libro" << endl;
    cout << "  6 - Registro de personas" << endl;
    cout << "  7 - Salir" << endl;
    int res;
    cout << ">>: "; 
    cin >> res;
    cin.ignore(1, '\n');
    cout << endl;
    return res;
}

int main() 
{
    //INICIALIZACION DE DATOS
    libro l1("Cien anios de soledad", "Fantasia", true);
    libro l2("El senior de los anillos", "Accion", true);
    libro l3("Orgullo y prejuicio", "Romance", true);
    libro l4("Un mundo feliz", "Fantasia", true);
    libro l5("1984", "Drama", true);
    libro l6("Crimen y castigo", "Accion", true);
    libro l7("Lolita", "Aventuras", true);
    libro l8("Ulises", "Comedia", true);
    libro l9("Madame Bovary", "Drama", true);
    libro l10("En busca del tiempo perdido", "Romance", true);
    libro l11("Don Quijote de la Mancha", "Fantasia", true);
    libro l12("El retrato de Dorian Gray", "Accion", true);
    libro l13("Ana Karenina", "Comedia", true);
    libro l14("El proceso", "Romance", true);
    libro l15("El ruido y la furia,", "Drama", true);
    libro l16("El Principito", "Fantasia", true);
    libro l17("Hamlet", "Aventuras", true);
    libro l18("La Odisea", "Comedia", true);
    libro l19("Las uvas de la ira", "Aventuras", true);
    libro l20("El guardian entre el centeno", "Accion", false);

    libro libros[20] = {l1, l2, l3, l4, l5, l6, l7, l8, l9, l10, l11, l12, l13, l14, l15, l16, l17, l18, l19, l20};

    libro h1[5] = {l2,l2,l3,l4,l5};
    persona p1("Alejandro Garcia", "0212010D", {}, h1);
    libro h2[5] = {l2,l2,l3,l4,l5};
    persona p2("Ruben Gomez", "9292929X", {}, h2);
    libro h3[5] = {l2,l2,l3,l4,l5};
    persona p3("Roberto Perez", "020120Z", {}, h3);

    string n = "";
    string d = "";

    cout << "[I] Introduce el nombre de la persona:\n";
    cout << ">>: ";
    getline(cin, n);
    cout << "[I] Introduce el dni de la persona:\n";
    cout << ">>: ";
    getline(cin, d);

    cout<<n<<d;

    libro h4[5] = {};
    persona p4( n, d, {}, h4);

    persona personas[4] = {p1, p2, p3, p4};

    int input;
    string nombrePersona = "";
    string libroEscogido = "";
    bool c = true;
    bool control;

    while (c) 
    {
        cout << endl;
        cout << endl;
        input = mostrarOpciones();

        switch (input) 
        {
        case 1:
            // Se imprimen por pantalla todos los libros disponibles
            printListaLibros(libros);
            break;

        case 2:
            cout << "[I] Introduce el nombre de la persona:\n";
            cout << ">>: ";
            getline(cin, nombrePersona);

            cout << endl;

            control = false;

            for (persona x : personas) 
            {
                // Si la persona introducida existe se extrae su historial para imprimirlo por pantalla
                if (x.getNombre() == nombrePersona) 
                {
                    x.getHistorial();
                    control = true;
                }
            }
            // Si no existe la persona introducida da error
            if (!control)
            {
                cout << "[ERROR] No se han encontrado registros" << endl;
            }
            break;

        case 3:
            cout << "[I] Introduce el nombre de la persona:\n";
            cout << ">>: ";
            getline(cin, nombrePersona);

            cout << endl;

            control = false;
            for (persona x : personas) 
            {
                // Si la persona introducida existe se extrae su libro actual y se imprime por pantalla
                if (x.getNombre() == nombrePersona)
                {
                    x.tieneLibro();
                    control = true;
                }
            }
            // Si no existe la persona introducida da error
            if (!control) 
            {
                cout << "[ERROR] No se han encontrado registros" << endl;
            }
            break;

        case 4:
            cout << "[I] Introduce el nombre del libro:\n";
            cout << ">>: ";
            getline(cin, libroEscogido);

            cout << "[I] Introduce el nombre de la persona:\n";
            cout << ">>: ";
            getline(cin, nombrePersona);

            cout << endl;

            control = false;
            for (libro l : libros) 
            {
                // Si el libro introducida existe...
                if (l.getTitulo() == libroEscogido)
                {
                    for (persona x : personas) 
                    {
                        // Si la persona introducida existe, se inserta el libro introducido en su libro actual
                        if (x.getNombre() == nombrePersona)
                        {
                            libro libroAsignado = darLibro(l, libros, x, personas);

                            control = true;
                        }
                    }
                }
            }

            // Si no existe la persona y el libro introducidos da error
            if (!control) 
            {
                cout << "[ERROR] No se han encontrado registros" << endl;
            }
            break;

        case 5:
            cout << "[I] Introduce el nombre de la persona:\n";
            cout << ">>: ";
            getline(cin, nombrePersona);

            cout << endl;

            control = false;
            
            for (persona x : personas) 
            {
                // Si la persona introducida existe, se desasigna el libro actual
                if (x.getNombre() == nombrePersona)
                {
                    libro libroDesasignado = desasignarLibro(libros, x, personas);

                    control = true;
                }
            }
            
            // Si no existe la persona introducida da error
            if (!control) 
            {
                cout << "[ERROR] No se han encontrado registros" << endl;
            }
            break;
        case 6:
            // Se imprimen por pantalla todos las personas registradas
            printListaPersonas(personas);
           
            break;

        case 7: return 0; break;

        default:
            c = false;
            break;
        }
    }
}