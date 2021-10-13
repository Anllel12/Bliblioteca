#include <iostream>
#include <cstdlib>

using namespace std;

class libro //Clase libro que gestiona todo lo relacionado con las libros
{
private:
    string titulo, categoria;
    bool disponible;

public:
    libro(string tit, string cat, bool disp) : titulo(tit), categoria(cat), disponible(disp) {};
    libro() {};

    void printLibro();
    string getLibro();

    void setDisp(bool d) //Edita la disponibilidad del libro
    {
        disponible = d;
    }
    
    bool getDisp()
    {
        return disponible;
    };
    
    string getTitulo()
    {
        return titulo;
    }

    string getCategoria() 
    {
        return categoria;
    }
};

void libro::printLibro() //Muestra los libros
{
    cout << titulo << " - " << categoria << endl;
}

string libro::getLibro() //Devuelve el libro, su categoría y si está disponible o no
{
    string libro = titulo + " - " + categoria;

    return libro;
};

class persona //Clase persona que gestiona todo lo relacionado con las personas
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

    libro getActual()
    {
        return actual;
    }

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

persona::persona(string no, string dn, libro act, libro hist[5]) //Constructor de persona
{ 
    nombre = no;
    dni = dn;
    actual = act;

    for (int i = 0; i < 5; i++) {
        historial[i] = hist[i];
    }
}

void persona::tieneLibro() //Si la persona seleccionada tiene libro se imprime por pantalla
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

void persona::getHistorial() //El historial de la persona
{
    for (int i = 0; i < 5; i++) 
    {
        cout << i << " libro: " << historial[i].getLibro() << endl;
    }

}

void persona::printPersona() //Imprimir por pantalla el libro
{
    cout << nombre << " - " << dni << endl;
}


void printListaPersonas (persona personas[4]) //Imprime las personas
{
    cout << endl;
    cout << "- Lista personas registradas:" << endl;

    for (int i = 0; i < 4; i++) 
    { 
            personas[i].printPersona();
    }
}

libro libros[20];

void printListaLibros (libro libros[20]) //Imprime los libros disponibles
{
    cout << endl;
    cout << "- Lista libros disponibles:" << endl;

    for (int i = 0; i < 20; i++) 
    {
        if (libros[i].getDisp()) 
        {
            libros[i].printLibro();
        }
    }
}

libro desasignarLibro (libro libros[20], persona p, persona personas[3]) //Poner un libro a una persona
{
    libro libroRet;

    for (int i = 0; i < 20; i++) 
    {
        if (p.getActual().getTitulo() == libros[i].getTitulo())
        {
            cout << "Designando el libro " << libros[i].getTitulo() << " a " << p.getNombre() << endl;
            libroRet = libros[i];
            libros[i].setDisp(true);

            for (int j = 0; j < 4; j++) //Se recorre la lista de personas 
            {
                if (p.getNombre() == personas[j].getNombre()) //Si coincide su nombre le pone el libro y actualiza el historial
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

libro darLibro (libro l, libro libros[20], persona p, persona personas[3]) //Dar libro a persona
{
    libro libroRet;

    for (int i = 0; i < 20; i++) 
    {
        if (l.getTitulo() == libros[i].getTitulo()) //Comprobamos que existe el libro
        {            
            if (!libros[i].getDisp()) //Comprobamos que este disponible
            {
                cout << "No se puede dar " << libros[i].getTitulo() << ", lo tiene otra persona." << endl;
            } else 
            {
                cout << "Dando libro -> " << libros[i].getTitulo() << endl;
                libroRet = libros[i];
                libros[i].setDisp(false);

                for (int j = 0; j < 4; j++) //Se recorre la lista de personas 
                {
                    if (p.getNombre() == personas[j].getNombre()) //Si coincide su nombre le pone el nombre y actualiza el historial
                    {
                        string lDisp = personas[j].getActual().getTitulo();
                        personas[j].setLibro(l);
                        personas[j].setHistorial(l);
                        cout << "Se ha asignado " << l.getTitulo() << " a " << personas[j].getNombre() << endl;
                     
                        for (int k = 0; k < 20; k++) //Ponemos el libro anterior a true
                        {                           
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
    cout << "Selecciona una de las opciones: " << endl;
    cout << "  1 - Comprobar que libros hay disponibles" << endl;
    cout << "  2 - Ver el historial de libros de una persona" << endl;
    cout << "  3 - Ver si una persona tiene un libro o no" << endl;
    cout << "  4 - Sacar un libro (asignárselo a una persona)" << endl;
    cout << "  5 - Devolver un libro" << endl;
    cout << "  6 - Listado de personas" << endl;
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
    libro l1("Cien añios de soledad", "Fantasia", true);
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

    libro h1[5] = {l1,l2,l11,l14,l18};
    persona p1("Ángel Esquinas", "08030605K", {}, h1);
    libro h2[5] = {l17,l18,l19,l20,l5};
    persona p2("Oscar Llorens", "15324865B", {}, h2);
    libro h3[5] = {l6,l8,l13,l10,l11};
    persona p3("Guillermo Perez", "15328695Z", {}, h3);

    string n = "";
    string d = "";

    cout << "- Introduce el nombre de la persona: \n";
    cin >> n;
    cout << "- Introduce el dni de la persona: \n";
    cin >> d;

    libro h4[5] = {};
    persona p4( n, d, {}, h4);

    persona personas[4] = {p1, p2, p3, p4};

    int input;// Varieblaes auxiliares
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
            printListaLibros(libros); //Se imprimen por pantalla los libros disponibles
            break;

        case 2:
            cout << "- Introduce el nombre de la persona: \n";
            cin >> nombrePersona;

            cout << endl;

            control = false;

            for (persona x : personas) 
            {
                if (x.getNombre() == nombrePersona) //Comprobamos que exista
                {
                    x.getHistorial(); //Ponemos su historial
                    control = true;
                }
            }
            
            if (!control)   //Si no existe la persona introducida da error
            {
                cout << "- No se han encontrado la persona" << endl;
            }
            break;

        case 3:
            cout << "- Introduce el nombre de la persona:\n";
            cin >> nombrePersona;
            cout << endl;

            control = false;
            for (persona x : personas) 
            {                
                if (x.getNombre() == nombrePersona) //Comprobamos que la persona existe
                {
                    x.tieneLibro(); 
                    control = true;
                }
            }
            // Si no existe la persona introducida da error
            if (!control) 
            {
                cout << "- No se han encontrado la persona" << endl;
            }
            break;

        case 4:
            cout << "- Introduce el nombre del libro:\n";
            cin >> libroEscogido;

            cout << "- Introduce el nombre de la persona:\n";
            cin >> nombrePersona;

            cout << endl;

            control = false;
            for (libro l : libros) 
            {
                if (l.getTitulo() == libroEscogido) //Comprobamos que el libro exista
                {
                    for (persona x : personas) 
                    {                      
                        if (x.getNombre() == nombrePersona)
                        {
                            libro libroAsignado = darLibro(l, libros, x, personas); //Ponemos libro introducido como su libro actual

                            control = true;
                        }
                    }
                }
            }

            if (!control) //Si no existe la persona y el libro introducidos da error
            {
                cout << "- No se han encontrado registros" << endl;
            }
            break;

        case 5:
            cout << "- Introduce el nombre de la persona:\n";
            cin >> nombrePersona;

            cout << endl;

            control = false;
            
            for (persona x : personas) 
            {
                if (x.getNombre() == nombrePersona)
                {
                    libro libroDesasignado = desasignarLibro(libros, x, personas);

                    control = true;
                }
            }           

            if (!control) //Si no existe la persona introducida da error
            {
                cout << "- No se han encontrado la persona" << endl;
            }
            break;
        case 6:
           
            printListaPersonas(personas); //Se imprimen por pantalla todos las personas registradas
           
            break;

        case 7: return 0; break;

        default: c = false; break;
        }
    }
}