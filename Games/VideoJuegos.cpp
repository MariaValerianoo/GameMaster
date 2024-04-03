#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <set>

using namespace std;

// Estructura para representar un videojuego
struct Videojuego {
    string nombre;
    string categoria;
    string desarrollador;
    int anio;
    string plataforma;
};

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
    cin >> nuevoJuego.anio;
    cin.ignore(); // Limpiar el buffer de entrada

    cout << "Ingrese la plataforma: ";
    getline(cin, nuevoJuego.plataforma);

    videojuegos.push_back(nuevoJuego);
}

// Función para mostrar los videojuegos por categoría
void mostrarVideojuegosPorCategoria() {
    for (const string& categoria : categorias) {
        cout << "Videojuegos de la categoría " << categoria << ":" << endl;
        for (const auto& juego : videojuegos) {
            if (juego.categoria == categoria) {
                cout << "- " << juego.nombre << ", Categoría: " << juego.categoria << ", Desarrollador: " << juego.desarrollador << ", Año: " << juego.anio << ", Plataforma: " << juego.plataforma << endl;
            }
        }
        cout << endl;
    }
}

int main() {
    char opcion;

    do {
        cout << "\nMenú de opciones:" << endl;
        cout << "1. Agregar un nuevo videojuego" << endl;
        cout << "2. Mostrar videojuegos por categoría" << endl;
        cout << "3. Salir" << endl;
        cout << "Ingrese su opción: ";
        cin >> opcion;
        cin.ignore(); // Limpiar el buffer de entrada

        switch (opcion) {
            case '1':
                agregarVideojuego();
                break;
            case '2':
                mostrarVideojuegosPorCategoria();
                break;
            case '3':
                cout << "¡Hasta luego!" << endl;
                break;
            default:
                cout << "Opción inválida. Intente nuevamente." << endl;
                break;
        }
    } while (opcion != '3');

    return 0;
}


/*❖ Agregar un videojuego a la colección.
❖ Asignar categorías a un videojuego.
❖ Consultar y mostrar la lista de videojuegos ordenados por título.
❖ Consultar y mostrar la lista de videojuegos ordenados por año de lanzamiento.
❖ Consultar y mostrar la lista de videojuegos filtrados por una plataforma específica.
❖ Utilizar al menos dos criterios de ordenamiento diferentes para ordenar la lista de
videojuegos (por ejemplo, título y año de lanzamiento).*/