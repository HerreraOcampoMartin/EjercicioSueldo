#include <iostream>

using namespace std;

class BonoPresentismo {
public:
    float calcularBonoPresentismo(int diasAusente) {
        float bono = 100.0;

        if(diasAusente == 1){
            bono = 50;
        } else if(diasAusente > 1) {
            bono = 0;
        }

        return bono;
    }
};

class BonoResultados {
public:
    float calcularBonoResultado(int tipoBono, float sueldoNeto) {
        // 1: 10% del sueldo neto
        // 2: $80 fijos
        // 3: nada
        float bono = 0;

        if(tipoBono == 1) {
            bono = 0.1f * sueldoNeto;
        } else if(tipoBono == 2) {
            bono = 80.0;
        }

        return bono;
    }
};

class Categoria {
private:
    string denominacionCategoria;
    float sueldoBase;
public:
    Categoria(string denominacionCategoria, float sueldoBase) {
        this->denominacionCategoria = denominacionCategoria;
        this->sueldoBase = sueldoBase;
    }

    string getDenominacionCategoria() {
        return this->denominacionCategoria;
    }

    float getSueldoBase() {
        return this->sueldoBase;
    }
};

class Persona {
private:
    string nombre;
    Categoria *categoriaTrabajador;
    float sueldo;
public:
    Persona(string nombre, Categoria *categoriaTrabajador) {
        this->nombre = nombre;
        this->categoriaTrabajador = categoriaTrabajador;
        this->sueldo = categoriaTrabajador->getSueldoBase();
    }

    float calcularSueldo(int diasAusente, int tipoBonoResultados) {
        BonoPresentismo bp;
        BonoResultados br;

        float extraPresentismo = bp.calcularBonoPresentismo(diasAusente);
        float extraResultados = br.calcularBonoResultado(tipoBonoResultados, categoriaTrabajador->getSueldoBase());

        sueldo = categoriaTrabajador->getSueldoBase() + extraPresentismo + extraResultados;

        return sueldo;
    }

    string getNombre() {
        return this->nombre;
    }

    Categoria* getCategoriaTrabajador() {
        return this->categoriaTrabajador;
    }

    void imprimirDatos() {
        cout << nombre << " - " << categoriaTrabajador->getDenominacionCategoria() << " - $" << sueldo << endl;
    }
};

class Inicio {
public:
    Inicio() {
        Categoria *gerente = new Categoria("Gerente", 1000);
        Categoria *cadete = new Categoria("Cadete", 1500);

        Persona pepe("Pepe", cadete);

        pepe.imprimirDatos();

        // 1: 10% del sueldo neto
        // 2: $80 fijos
        // 3: nada
        pepe.calcularSueldo(2, 1);
        pepe.imprimirDatos();
    }
};

int main() {

    Inicio i;




    return 0;
}
