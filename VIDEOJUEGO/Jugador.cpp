#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <stdio.h>
#include <time.h>
#include <limits>
using namespace std;

class Videojuego {
private:
    string nombre;
    int cantidadJugadores;
    vector<string> categorias;
    string desarrollador;
    int añoLanzamiento;
    string plataforma;

public:
    Videojuego() {}

    void setNombre(const string& nombre) { 
        this->nombre = nombre; 
    }

    void setCantidadJugadores(int cantidadJugadores) { 
        this->cantidadJugadores = cantidadJugadores; 
    }

    void setCategorias(const vector<string>& categorias) {
         this->categorias = categorias; 
    }

    void setDesarrollador(const string& desarrollador) { 
        this->desarrollador = desarrollador; 
    }

    void setAñoLanzamiento(int añoLanzamiento) { 
        this->añoLanzamiento = añoLanzamiento; 
    }

    void setPlataforma(const string& plataforma) { 
        this->plataforma = plataforma; 
    }

    string getNombre() const { 
        return nombre; 
    }

    int getCantidadJugadores() const { 
        return cantidadJugadores; 
    }

    vector<string> getCategorias() const { 
        return categorias; 
    }

    string getDesarrollador() const { 
        return desarrollador; 
    }

    int getAñoLanzamiento() const { 
        return añoLanzamiento; 
    }

    string getPlataforma() const { 
        return plataforma; 
    }
    

};

class Ahorcado: public Videojuego {
private:
    int partidas = 0;
    string palabraInicial;
    string mostrarPalabra;
    int vidas;

public:
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

        for (size_t i = 0; i < palabraInicial.length(); i++) { 
            if (palabraInicial[i] >= 'A' && palabraInicial[i] <= 'Z') {
                palabraInicial[i] += 32;
            }
        }

        for (size_t i = 0; i < palabraInicial.length(); i++) {
            if (palabraInicial[i] >= 'a' && palabraInicial[i] <= 'z') {
                mostrarPalabra[i] = '-';
            }
        }
    }

    void ingresar(char x) {
        bool perderVidas = true;

        for (size_t i = 0; i < palabraInicial.length(); i++) {
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
            partidas++;
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

class Triqui: public Videojuego {
public:
    /*void loop(char c[3][3]);
    void introducirPrimerNumero(char c[3][3]);
    void numeroUsuario(char c[3][3]);
    void numeroMaquina(char c[3][3]);
    bool verificarGanador(char c[3][3], char jugador);
    void tableroDeJuego(char c[3][3]);*/
    
    void loop(char c[3][3]) {
        introducirPrimerNumero(c);
        tableroDeJuego(c);

        while(true){
            numeroUsuario(c);
            tableroDeJuego(c);
            if (verificarGanador(c, 'X')) {
                cout << "¡Has ganado!" << endl;
                break;
            }
            cout << "\n";
            numeroMaquina(c);
            cout << "\n";
            tableroDeJuego(c);
            if (verificarGanador(c, 'O')) {
                cout << "La máquina ha ganado." << endl;
                break;
            }
        }
    }

    void introducirPrimerNumero(char c[3][3]) {
        int i, j;
        char aux = '1';
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                c[i][j] = aux++;
            }
        }
    }

    void numeroUsuario(char c[3][3]) {
        int i, j, k;
        char aux;
        do {
            do {
                cout << "\nEscoge donde quieres poner tu ficha: ";
                cin >> aux;
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer de entrada
            } while (aux < '1' || aux > '9');
            k = 0;
            switch (aux) {
                case '1': i = 0; j = 0; break;
                case '2': i = 0; j = 1; break;
                case '3': i = 0; j = 2; break;
                case '4': i = 1; j = 0; break;
                case '5': i = 1; j = 1; break;
                case '6': i = 1; j = 2; break;
                case '7': i = 2; j = 0; break;
                case '8': i = 2; j = 1; break;
                case '9': i = 2; j = 2; break;
            }
            if (c[i][j] == 'X' || c[i][j] == 'O') {
                k = 1;
                cout << "Este espacio está ocupado, por favor selecciona otro!!\n\n";
            }
        } while (k == 1);
        c[i][j] = 'X';
    }

    void numeroMaquina(char c[3][3]) {
        int i, j, k;
        do {
            i = rand() % 3;
            j = rand() % 3;
            k = 0;
            if (c[i][j] == 'X' || c[i][j] == 'O') {
                k = 1;
            }
        } while (k == 1);
        c[i][j] = 'O';
    }

    bool verificarGanador(char c[3][3], char jugador) {
        for (int i = 0; i < 3; i++) {
            if (c[i][0] == jugador && c[i][1] == jugador && c[i][2] == jugador) {
                return true; // Ganador en fila
            }
            if (c[0][i] == jugador && c[1][i] == jugador && c[2][i] == jugador) {
                return true; // Ganador en columna
            }
        }
        if ((c[0][0] == jugador && c[1][1] == jugador && c[2][2] == jugador) || 
            (c[0][2] == jugador && c[1][1] == jugador && c[2][0] == jugador)) {
            return true; // Ganador en diagonal
        }
        return false; 
    }

    void tableroDeJuego(char c[3][3]) {
        int i, j;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                cout << " " << c[i][j] << " ";
                if (j < 2) {
                    cout << "|";
                }
            }
            if (i < 2) {
                cout << "\n---+---+---\n";
            }
        }
        cout << endl;
    }

    void jugar() {
        char jugarNuevamente;
        do {
            char c[3][3];
            loop(c);
            cout << "¿Deseas jugar de nuevo? (s/n): ";
            cin >> jugarNuevamente;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer de entrada
        } while (jugarNuevamente == 's' || jugarNuevamente == 'S');
    }
};

class Jugador {
private:
    string nombre;
    string nick;
    string numero;
    string clave;

public:
    Jugador() {}

    string getNombre() const {
        return nombre;
    }

    void setNombre(const string& n) {
        nombre = n;
    }

    string getNick() const {
        return nick;
    }

    void setNick(const string& n) {
        nick = n;
    }

    string getNumero() const {
        return numero;
    }

    void setNumero(const string& n) { 
        numero = n;
    }

    string getClave() const {
        return clave;
    }

    void setClave(const string& c) { 
        clave = c;
    }

    void registrarUsuario() { 
        cout << "Vamos a hacer tu registro " << endl;
        cout << "Ingresa tu Nombre: " << endl;
        cin >> nombre;
        cout << "Ingresa tu Nickname: " << endl;
        cin >> nick;
        cout << "Ingrese su numero de telefono: " << endl;
        cin >> numero;
        while (numero.length() != 10) {
            cout << "No es correcto el numero vuelve a intentarlo" << endl;
            cin >> numero;
        }
        cout << "El numero es valido, ahora ingresa la contraseña'\n recuerda que debe tener 4 digitos: ";
        cin >> clave;
        while (clave.length() != 4) {
            cout << "No es correcta la contraseña vuelve a intentarlo: " << endl;
            cin >> clave;
        }
    }

    bool verificarCredenciales() { 
        string nickIngresado;
        string claveIngresada; 
        int intentos = 3;
        cout << "Ingrese su nickname: \n";
        cin >> nickIngresado;
        while (nickIngresado != nick) {
            buscarUsuario();
            
        }
        cout << "El nickname es valido, ahora ingresa la contraseña\n recuerda que esta es de 4 digitos: ";
        cin >> claveIngresada; 
        while (claveIngresada.length() != 4 || claveIngresada != clave) {
            cout << "No es correcta la contraseña vuelve a intentarlo: " << endl;
            cin >> claveIngresada;
            intentos--;
            if (intentos == 0) {
                return false;
            }
        }
        return true;
    }

    void Inicio() {
        int op;
        cout << "----Bienvenido a GameMaster----\n";
        do {
            cout << "Que deseas hacer?: \n";
            cout << "1)Registrarte \n2)Ingresar \n3)Salir\n ";
            cin >> op;
            switch (op) {
            case 1:
                registrarUsuario();
                break;
            case 2:
                if (verificarCredenciales()) {
                    secondMenu();
                } else {
                    buscarUsuario();
                }
                break;
            }
        } while (op != 3);
    }

    void secondMenu() {
        int op;
        Triqui person;
        Ahorcado user;
        cout << "Inicio de sesión exitoso.\n";
        do {
            cout << "----Bienvenido a GameMaster----" << endl;
            cout << "Este es un Sistema de Gestión y Desarrollo de Videojuegos en C++" << endl;
            cout << "Aqui puedes encontrar estas funciones: " << endl;
            cout << "1)Juego Ahorcado\n ";
            cout << "2)Juego Triqui\n ";
            cout << "3)Almacenamiento de videojuegos\n ";
            cout << "4)Ver tus favoritos\n ";
            cout << "5)Salir del programa\n ";
            cout << "Elige tu opcion: \n ";
            cin >> op;
            switch (op) {
            case 1:
                user.jugar();
                break;
            case 2:
                person.jugar();
                break;
            case 3:
                // Implementar funcionalidad aquí
                break;
            case 4:
                // Implementar funcionalidad aquí
                break;
            }
        } while (op != 5);
    }
    bool buscarUsuario() {
        vector<Jugador> jugadores;
        string nickIngresado;
        cout << "Ingrese el nickname para buscar: ";
        cin >> nickIngresado;
        for (const Jugador& jugador : jugadores) {
            if (jugador.getNick() == nickIngresado) {
                return true; 
            }
        }
        cout << "El usuario no está registrado." << endl;
        cout << "¿Deseas registrarte? (s/n): ";
        char respuesta;
        cin >> respuesta;
        if (respuesta == 's' || respuesta == 'S') {
            Jugador nuevoUsuario;
            nuevoUsuario.registrarUsuario();
            jugadores.push_back(nuevoUsuario);
        }
        return false; 
    }
};
int main() {
    Jugador jugador;
    jugador.Inicio();
    return 0;
}
