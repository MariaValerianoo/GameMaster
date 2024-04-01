#include <iostream>
#include <vector>
#include<string>
#include"./claseVideojuego.cpp"

using namespace std;

class GameMaster: public Videojuego {
private:
    vector<vector<Videojuego>> multilistaVideojuegos;
    vector<Videojuego> listaVideojuegos;

public:
    GameMaster() {
        multilistaVideojuegos.push_back({});
    }


    void agregarVideojuego(const Videojuego& juego, size_t categoria) {
        if (categoria >= multilistaVideojuegos.size()) {
            multilistaVideojuegos.resize(categoria + 1);
        }
        multilistaVideojuegos[categoria].push_back(juego);
    }
    void agregarVideojuego(const Videojuego& juego) {
        listaVideojuegos.push_back(juego);
    }
    oid ordBur(vector<Videojuego>& videojuegos) {
        int n = videojuegos.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (videojuegos[j].getNombre() > videojuegos[j + 1].getNombre()) {
                    swap(videojuegos[j], videojuegos[j + 1]);
                }
            }
        }
    }
    void mostrarListaOrdenadaPorTitulo() {
        ordBur(listaVideojuegos);
        cout << "Lista de videojuegos ordenados por título:" << endl;
        for (const auto& juego : listaVideojuegos) {
            cout << "Nombre: " << juego.getNombre() << ", Plataforma: " << juego.getPlataforma() << endl;
        }
    }
};