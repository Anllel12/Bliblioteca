class animal {
        
    public:       
        fluidosCorporales;
        void respirarOxigeno(fluidosCorporales);      
};

void animal::respirarOxigeno(fluidosCorporales){
    
}

class insecto extends animal{
    public:
        invertebrados;
        void exoesqueleto(invertebrados); 
}

void insecto::exoesqueleto(invertebrados){
    
}

class polilla extends insecto{
    public:
        alas;
}

class pulga extends insecto{
    public:
        salta;
}

class mamífero extends animal{
    public:
        glandulas;
        void glandulasMamarias(glandulas); 
}

class persona extends mamífero{
    genética;
    void genética(fisiología);
}

void persona::genética(fisiología){
    
}

class hombre extends persona{
    public:
        sexoMacho;
}

class mujer extends persona{
    public:
        sexohembra;


class ovíparo extends animal{
    public:
        huevos;
        void incubación(huevos); 
}

void ovíparo::incubación(huevos){
    
}

class pajaro extends ovíparo{
    public:
        plumas;
        void alas(plumas); 
}

void pajaro::alas(plumas){
    
}

}class canario extends pajaro{
    public:
        colores;
}

class jilguero extends pajaro{
    public:
        canto
}

int main(int argc, char *argv[])
{   
    aimal an;
    
return 0;
}