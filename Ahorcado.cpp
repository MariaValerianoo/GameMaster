#include <iostream>
#include <string>
using namespace std;

string palabraInicial;
string mostrarPalabra;
int vidas;

void mostrar(); // Declaración de la función mostrar
void ingresar(char x);
void inicializar(); // Declaración de la función inicializar

int main() {
    inicializar();
    mostrar();
    while (vidas > 0 && mostrarPalabra != palabraInicial) {
        char x;
        cin >> x;
        ingresar(x);
        mostrar();
    }
    if (vidas > 0) {
        cout << "Ganaste!!" << endl;
    } else {
        cout << "Perdiste, la palabra era: " << palabraInicial << endl;
    }
}

void mostrar() {
    cout << "Vidas: " << vidas << endl;
    cout << mostrarPalabra << endl;
}

void inicializar() {
    vidas = 5; 
    palabraInicial = "Ahorcado C++"; 
    mostrarPalabra = palabraInicial; 

    // Convertir la palabra inicial a minúsculas
    for (int i = 0; i < palabraInicial.length(); i++) { 
        if (palabraInicial[i] >= 'A' && palabraInicial[i] <= 'Z') {
            palabraInicial[i] += 32;
        }
    }

    // Inicializar mostrarPalabra con guiones
    for (int i = 0; i < palabraInicial.length(); i++) {
        if (palabraInicial[i] >= 'a' && palabraInicial[i] <= 'z') {
            mostrarPalabra[i] = '-';
        }
    }
}

void ingresar(char x) {
    bool perderVidas = true;

    for (int i = 0; i < palabraInicial.length(); i++) {
        if (x == palabraInicial[i]) { // Utiliza el operador de comparación '=='
            perderVidas = false;
            mostrarPalabra[i] = x;
        }
    }
    if (perderVidas) {
        vidas--;
    }
}