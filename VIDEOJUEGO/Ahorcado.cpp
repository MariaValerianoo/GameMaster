#include <iostream>
#include <vector>
#include <string>
#include <ctime> 
#include"./Videojuego.cpp"

using namespace std;
class Ahorcado: public Videojuego {
private:
    int partidas = 0;
    string palabraInicial;
    string mostrarPalabra;
    int vidas;

public:
    // Métodos get
    int getPartidas() const {
        return partidas;
    }

    string getPalabraInicial() const {
        return palabraInicial;
    }

    string getMostrarPalabra() const {
        return mostrarPalabra;
    }

    int getVidas() const {
        return vidas;
    }

    // Métodos set
    void setPartidas(int p) {
        partidas = p;
    }

    void setPalabraInicial(const string& p) {
        palabraInicial = p;
    }

    void setMostrarPalabra(const string& p) {
        mostrarPalabra = p;
    }

    void setVidas(int v) {
        vidas = v;
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
            if (x == palabraInicial[i]) { 
                perderVidas = false;
                mostrarPalabra[i] = x;
            }
        }
        if (perderVidas) {
            vidas--;
        }
    }

    void jugar() {
        char jugarNuevamente;
        do {
            partidas++; // Incrementa el contador de partidas al iniciar una nueva partida
            inicializar();
            clock_t inicio = clock(); 
            mostrar();
            while (vidas > 0 && mostrarPalabra != palabraInicial) {
                char x;
                cin >> x;
                ingresar(x);
                mostrar();
            }
            clock_t fin = clock(); 
            double tiempoJuego = (double)(fin - inicio) / CLOCKS_PER_SEC; 
            cout << "Tiempo de juego: " << tiempoJuego << " segundos" << endl;
            cout << "¿Deseas jugar de nuevo? (s/n): ";
            cin >> jugarNuevamente;
        } while (jugarNuevamente == 's' || jugarNuevamente == 'S');

        cout << "Número total de partidas jugadas: " << partidas << endl;
    }
};