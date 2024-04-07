#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <stdio.h>
#include <time.h>
#include <limits>
#include <sstream>
#include <set>
#include <algorithm>
using namespace std;

class Videojuego {
private:
    string nombre;
    string categoria;
    string desarrollador;
    int año;
    string plataforma;
    int partidas_triqui;
    int partidas_ahorcado;

public:
    Videojuego() {}
    int getPartidasTriqui() const {
        return partidas_triqui;
    }

    int getPartidasAhorcado() const {
        return partidas_ahorcado;
    }

    void setPartidasTriqui(int partidas) {
        partidas_triqui = partidas;
    }

    void setPartidasAhorcado(int partidas) {
        partidas_ahorcado = partidas;
    }

    void setNombre(const string& nombre) { 
        this->nombre = nombre; 
    }
    void setCategoria(const vector<string>& categorias) {
         this->categoria = categoria; 
    }

    void setDesarrollador(const string& desarrollador) { 
        this->desarrollador = desarrollador; 
    }

    void setAño(int año) { 
        this->año = año; 
    }

    void setPlataforma(const string& plataforma) { 
        this->plataforma = plataforma; 
    }

    string getNombre() const { 
        return nombre; 
    }

    string getDesarrollador() const { 
        return desarrollador; 
    }

    int getAño() const { 
        return año; 
    }

    string getPlataforma() const { 
        return plataforma; 
    }
    // Vector para almacenar los videojuegos
vector<Videojuego> videojuegos;

// Conjunto para almacenar las categorías únicas
set<string> categorias;

// Función para agregar un nuevo videojuego
void agregarVideojuego() {
    Videojuego nuevoJuego;
    cout << "Ingrese el nombre del videojuego: ";
    getline(cin, nuevoJuego.nombre);
    cout << "Ingrese la categoría del videojuego: ";
    getline(cin, nuevoJuego.categoria);
    categorias.insert(nuevoJuego.categoria); // Agregar la categoría al conjunto
    cout << "Ingrese el desarrollador: ";
    getline(cin, nuevoJuego.desarrollador);
    cout << "Ingrese el año de lanzamiento: ";
    cin >> nuevoJuego.año;
    cin.ignore(); // Limpiar el buffer de entrada
    cout << "Ingrese la plataforma: ";
    getline(cin, nuevoJuego.plataforma);
    videojuegos.push_back(nuevoJuego);
}

// Función para mostrar los videojuegos ordenados por título
void mostrarVideojuegosPorTitulo() {
    vector<Videojuego> ordenadosPorTitulo = videojuegos;
    sort(ordenadosPorTitulo.begin(), ordenadosPorTitulo.end(), [](const Videojuego& a, const Videojuego& b) {
        return a.nombre < b.nombre;
    });

    cout << "Videojuegos ordenados por título:" << endl;
    for (const auto& juego : ordenadosPorTitulo) {
        cout << "- " << juego.nombre << ", Categoría: " << juego.categoria << ", Desarrollador: " << juego.desarrollador << ", Año: " << juego.año << ", Plataforma: " << juego.plataforma << endl;
    }
    cout << endl;
}

// Función para mostrar los videojuegos ordenados por año de lanzamiento
void mostrarVideojuegosPorAño() {
    vector<Videojuego> ordenadosPorAño = videojuegos;
    sort(ordenadosPorAño.begin(), ordenadosPorAño.end(), [](const Videojuego& a, const Videojuego& b) {
        return a.año < b.año;
    });

    cout << "Videojuegos ordenados por año de lanzamiento:" << endl;
    for (const auto& juego : ordenadosPorAño) {
        cout << "- " << juego.nombre << ", Categoría: " << juego.categoria << ", Desarrollador: " << juego.desarrollador << ", Año: " << juego.año << ", Plataforma: " << juego.plataforma << endl;
    }
    cout << endl;
}

// Función para mostrar los videojuegos filtrados por categoría
void mostrarVideojuegosPorCategoria() {
    for (const string& categoria : categorias) {
        cout << "Videojuegos de la categoría " << categoria << ":" << endl;
        for (const auto& juego : videojuegos) {
            if (juego.categoria == categoria) {
                cout << "- " << juego.nombre << ", Categoría: " << juego.categoria << ", Desarrollador: " << juego.desarrollador << ", Año: " << juego.año << ", Plataforma: " << juego.plataforma << endl;
            }
        }
        cout << endl;
    }
}

// Función para mostrar los videojuegos filtrados por plataforma
void mostrarVideojuegosPorPlataforma() {
    string plataforma;
    cout << "Ingrese la plataforma a filtrar: ";
    getline(cin, plataforma);

    cout << "Videojuegos de la plataforma " << plataforma << ":" << endl;
    for (const auto& juego : videojuegos) {
        if (juego.plataforma == plataforma) {
            cout << "- " << juego.nombre << ", Categoría: " << juego.categoria << ", Desarrollador: " << juego.desarrollador << ", Año: " << juego.año << ", Plataforma: " << juego.plataforma << endl;
        }
    }
    cout << endl;
}

// Función para mostrar los videojuegos ordenados por título y año
void mostrarVideojuegosPorTituloYAño() {
    vector<Videojuego> ordenadosPorTituloYAño = videojuegos;
    sort(ordenadosPorTituloYAño.begin(), ordenadosPorTituloYAño.end(), [](const Videojuego& a, const Videojuego& b) {
        if (a.nombre == b.nombre) {
            return a.año < b.año;
        }
        return a.nombre < b.nombre;
    });

    cout << "Videojuegos ordenados por título y año de lanzamiento:" << endl;
    for (const auto& juego : ordenadosPorTituloYAño) {
        cout << "- " << juego.nombre << ", Categoría: " << juego.categoria << ", Desarrollador: " << juego.desarrollador << ", Año: " << juego.año << ", Plataforma: " << juego.plataforma << endl;
    }
    cout << endl;
}

int almacenamiento() {
    char opcion;
    do {
        cout << "\nMenú de opciones:" << endl;
        cout << "1. Agregar un nuevo videojuego" << endl;
        cout << "2. Mostrar videojuegos por categoría" << endl;
        cout << "3. Mostrar videojuegos ordenados por título" << endl;
        cout << "4. Mostrar videojuegos ordenados por año de lanzamiento" << endl;
        cout << "5. Mostrar videojuegos filtrados por plataforma" << endl;
        cout << "6. Mostrar videojuegos ordenados por título y año" << endl;
        cout << "7. Salir" << endl;
        cout << "Ingrese su opción: ";
        cin >> opcion;
        cin.ignore(); 
        switch (opcion) {
            case '1':
                agregarVideojuego();
                break;
            case '2':
                mostrarVideojuegosPorCategoria();
                break;
            case '3':
                mostrarVideojuegosPorTitulo();
                break;
            case '4':
                mostrarVideojuegosPorAño();
                break;
            case '5':
                mostrarVideojuegosPorPlataforma();
                break;
            case '6':
                mostrarVideojuegosPorTituloYAño();
                break;
            case '7':
                cout << "¡Hasta luego!" << endl;
                break;
            default:
                cout << "Opción inválida. Intente nuevamente." << endl;
                break;
        }
    } while (opcion != '7');
    return 0;
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
            cout<<"Bienvenido a ahorcado "<<endl;
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
        int op=partidas;
        setPartidasAhorcado(op);
        
    }
};

class Triqui: public Videojuego {
    private:
    int partidas=0;

public:
    int getPartidas() const {
        return partidas;
    }
    void setPartidas(int p) {
        partidas = p;
    }
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
            cout<<"Bienvenido a triqui: "<<endl;
            partidas++;
            char c[3][3];
            loop(c);
            cout << "¿Deseas jugar de nuevo? (s/n): ";
            cin >> jugarNuevamente;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer de entrada
        } while (jugarNuevamente == 's' || jugarNuevamente == 'S');
        cout << "Número total de partidas jugadas: " << partidas << endl;
        int op=partidas;
        setPartidasTriqui(op);
    }
};

class Jugador {
private:
    string nombre;
    string nick;
    string numero;
    string clave;
    vector<Jugador> jugadores;
    Ahorcado ahorcado;
    Triqui triqui;

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
    void determinarJuegoFavorito(Triqui& triqui, Ahorcado& ahorcado) {
        cout<<"Las partidas jugadas en ahorcado son: "<<ahorcado.getPartidasAhorcado()<<endl;
        cout<<"Las partidas jugadas en triqui son: "<<triqui.getPartidasTriqui()<<endl;
        if (ahorcado.getPartidasAhorcado() > triqui.getPartidasTriqui()) {
            cout << "Tu juego favorito es Ahorcado." << endl;
        } else if (triqui.getPartidasTriqui() > ahorcado.getPartidasAhorcado()) {
            cout << "Tu juego favorito es Triqui." << endl;
        } else {
            cout << "Tienes el mismo número de partidas en Ahorcado y Triqui." << endl;
        }
    }

// Método para registrar un nuevo usuario
    void registrarUsuario() { 
        Jugador nuevoJugador;
        cout << "Vamos a hacer tu registro " << endl;
        cout << "Ingresa tu Nombre: " << endl;
        string nombre;
        cin >> nombre;
        nuevoJugador.setNombre(nombre);
        cout << "Ingresa tu Nickname: " << endl;
        string nick;
        cin >> nick;
        nuevoJugador.setNick(nick);
        cout << "Ingrese su numero de telefono: " << endl;
        string numero;
        cin >> numero;
        nuevoJugador.setNumero(numero);
        while (nuevoJugador.getNumero().length() != 10) {
            cout << "No es correcto el numero vuelve a intentarlo" << endl;
            cin >> numero;
            nuevoJugador.setNumero(numero);
        }
        cout << "El numero es valido, ahora ingresa la contraseña'\n recuerda que debe tener 4 digitos: ";
        string clave;
        cin >> clave;
        nuevoJugador.setClave(clave);
        while (nuevoJugador.getClave().length() != 4) {
            cout << "No es correcta la contraseña vuelve a intentarlo: " << endl;
            cin >> clave;
            nuevoJugador.setClave(clave);
        }
        jugadores.push_back(nuevoJugador); 
        cout << "Registro exitoso:) " << endl;
    }

    bool verificarCredenciales() { 
    string nickIngresado;
    string claveIngresada;
    int intentos = 3;
    cout << "Ingrese su nickname: \n";
    cin >> nickIngresado;
    for (const Jugador& jugador : jugadores) {
        if (jugador.getNick() == nickIngresado) {
            cout << "El nickname es valido, ahora ingresa la contraseña \n recuerda que esta es de 4 digitos: "<<endl;
            cin >> claveIngresada; 
            while (claveIngresada.length() != 4 || claveIngresada != jugador.getClave()) {
                cout << "Tienes " << intentos << " intentos restantes \n";
                cout << "No es correcta la contraseña, vuelve a intentarlo: " << endl;
                cin >> claveIngresada;
                intentos--;
                if (intentos == 0) {
                    return false;
                }
            }
            return true; 
        }
    }
    cout << "El usuario no esta registrado." << endl;
    cout << "Deseas registrarte? (s/n): ";
    char respuesta;
    cin >> respuesta;
    if (respuesta == 's' || respuesta == 'S') {
        Jugador nuevoUsuario;
        nuevoUsuario.registrarUsuario();
        jugadores.push_back(nuevoUsuario);
        return true; 
    }
    return false; 
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
                if(verificarCredenciales()){
                    secondMenu();
                }
                break;
            }
        } while (op != 3);
    }

    void secondMenu() {
        int op;
        Triqui person;
        Ahorcado user;
        Videojuego hola;
        cout << "Inicio de sesion exitoso.\n";
        do {
            cout << "----Bienvenido a GameMaster----" << endl;
            cout << "Este es un Sistema de Gestion y Desarrollo de Videojuegos en C++" << endl;
            cout << "Aqui puedes encontrar estas funciones: " << endl;
            cout << "1)Juego Ahorcado\n ";
            cout << "2)Juego Triqui\n ";
            cout << "3)Almacenamiento de videojuegos\n ";
            cout << "4)Ver tu favorito\n ";
            cout << "4)Salir del programa\n ";
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
                hola.almacenamiento();
                break;
            case 4:
                determinarJuegoFavorito(person, user);

            }
        } while (op != 5);
    }
    bool buscarUsuario() {
        string nickIngresado;
        cout << "Ingrese el nickname para buscar: ";
        cin >> nickIngresado;
        for (const Jugador& jugador : jugadores) {
            if (jugador.getNick() == nickIngresado) {
                return true; 
            }
        }
        cout << "El usuario no esta registrado." << endl;
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
