#include <iostream>
#include <list>
#include <vector>
#include <string>
using namespace std;

// Estructura para representar un videojuego
struct Videojuego {
    string nombre;
    int cantidadJugadores;
    vector<string> categorias;
    string desarrollador;
    int anioLanzamiento;
    string plataforma;
};

// Lista de listas para almacenar los videojuegos por categoría
list<list<Videojuego>> listaMultilista;

// Función para agregar un videojuego
void agregarVideojuego(string nombre, int cantidadJugadores, vector<string> categorias, string desarrollador, int anioLanzamiento, string plataforma) {
    Videojuego nuevoJuego = {nombre, cantidadJugadores, categorias, desarrollador, anioLanzamiento, plataforma};
    for (const string& categoria : categorias) {
        bool categoriaEncontrada = false;
        for (auto& sublista : listaMultilista) {
            if (!sublista.empty() && sublista.front().categorias.front() == categoria) {
                sublista.push_back(nuevoJuego);
                categoriaEncontrada = true;
                break;
            }
        }
        if (!categoriaEncontrada) {
            list<Videojuego> nuevaSublista;
            nuevaSublista.push_back(nuevoJuego);
            listaMultilista.push_back(nuevaSublista);
        }
    }
}

// Función para mostrar los videojuegos por categoría
void mostrarVideojuegosPorCategoria(string categoria) {
    cout << "Videojuegos de la categoría " << categoria << ":" << endl;
    for (const auto& sublista : listaMultilista) {
        if (!sublista.empty() && sublista.front().categorias.front() == categoria) {
            for (const Videojuego& juego : sublista) {
                cout << "- " << juego.nombre << endl;
            }
        }
    }
}

int main() {

    //juegos de PlayStation
    agregarVideojuego("God of War: Ragnarok", 1, {"Acción", "Aventura"}, "Sony Interactive Entertainment", 2022, "PlayStation");
    agregarVideojuego("Gran Turismo 7", 1, {"Carreras", "Simulación"}, "Polyphony Digital", 2022, "PlayStation");
    agregarVideojuego("Horizon Forbidden West", 1, {"Acción", "Aventura"}, "Guerrilla Games", 2022, "PlayStation");
    agregarVideojuego("Spider-Man: Miles Morales", 1, {"Acción", "Aventura"}, "Insomniac Games", 2020, "PlayStation");

    //juegos de Xbox
    agregarVideojuego("Halo Infinite", 1, {"Shooter", "Acción"}, "343 Industries", 2021, "Xbox");
    agregarVideojuego("Forza Horizon 5", 1, {"Carreras", "Mundo abierto"}, "Playground Games", 2021, "Xbox");
    agregarVideojuego("Psychonauts 2", 1, {"Plataformas", "Aventura"}, "Double Fine Productions", 2021, "Xbox");
    agregarVideojuego("Gears 5", 1, {"Shooter", "Acción"}, "The Coalition", 2019, "Xbox");

    //juegos de Nintendo
    agregarVideojuego("The Legend of Zelda: Breath of the Wild", 1, {"Aventura", "Mundo abierto"}, "Nintendo EPD", 2017, "Nintendo Switch");
    agregarVideojuego("Super Mario Odyssey", 1, {"Plataformas", "Aventura"}, "Nintendo EPD", 2017, "Nintendo Switch");
    agregarVideojuego("Splatoon 3", 4, {"Shooter", "Multijugador"}, "Nintendo EPD", 2022, "Nintendo Switch");
    agregarVideojuego("Animal Crossing: New Horizons", 4, {"Simulación", "Mundo abierto"}, "Nintendo EPD", 2020, "Nintendo Switch");

    // Mostrar videojuegos por categoría
     mostrarVideojuegosPorCategoria("Aventura");
    mostrarVideojuegosPorCategoria("Simulación");
    mostrarVideojuegosPorCategoria("Acción");
    mostrarVideojuegosPorCategoria("Multijugador");
    mostrarVideojuegosPorCategoria("Mundo Abierto");
    mostrarVideojuegosPorCategoria("Carreras");


    return 0;
}