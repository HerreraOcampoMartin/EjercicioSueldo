#include <iostream>

using namespace std;

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
public:
    Persona(string nombre, Categoria *categoriaTrabajador) {
        this->nombre = nombre;
        this->categoriaTrabajador = categoriaTrabajador;
    }

    string getNombre() {
        return this->nombre;
    }

    Categoria* getCategoriaTrabajador() {
        return this->categoriaTrabajador;
    }
};

int main() {



    return 0;
}
