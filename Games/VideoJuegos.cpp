#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <set>
#include <algorithm>

using namespace std;

// Estructura para representar un videojuego
struct Videojuego {
    string nombre;
    string categoria;
    string desarrollador;
    int año;
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

int main() {
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
        cin.ignore(); // Limpiar el buffer de entrada
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

/*❖ Agregar un videojuego a la colección. Ya hecho**
❖ Asignar categorías a un videojuego. Ya hecho**
❖ Consultar y mostrar la lista de videojuegos ordenados por título. 
❖ Consultar y mostrar la lista de videojuegos ordenados por año de lanzamiento.
❖ Consultar y mostrar la lista de videojuegos filtrados por una plataforma específica.
❖ Utilizar al menos dos criterios de ordenamiento diferentes para ordenar la lista de
videojuegos (por ejemplo, título y año de lanzamiento).*/