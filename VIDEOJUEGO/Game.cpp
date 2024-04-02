#include <iostream>
#include <vector>
#include<string>
#include"./Videojuego.cpp"

using namespace std;
struct RegistroJuego {
    string nombreJugador;
    int tiempoJugado;
    const Videojuego* juego;

    // Constructor
    RegistroJuego(const string& nombreJugador, int tiempoJugado, const Videojuego* juego)
        : nombreJugador(nombreJugador), tiempoJugado(tiempoJugado), juego(juego) {}
};
class GameMaster: public Videojuego {
private:
    vector<RegistroJuego> registros;
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
    void ordBur(vector<Videojuego>& videojuegos) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (videojuegos[j].getNombre() > videojuegos[j + 1].getNombre()) {
                string temp = videojuegos[j].getNombre();
                videojuegos[j].getNombre() = videojuegos[j + 1].getNombre();
                videojuegos[j + 1].getNombre() = temp;
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
    void agregarRegistro(const string& nombreJugador, int tiempoJugado, const Videojuego* juego) {
        registros.push_back(RegistroJuego(nombreJugador, tiempoJugado, juego));
    }
    void ordBur() {
        int n = registros.size();
        bool swapped;
        for (int i = 0; i < n - 1; i++) {
            swapped = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (registros[j].tiempoJugado < registros[j + 1].tiempoJugado) {
                    RegistroJuego temp = registros[j];
                    registros[j] = registros[j + 1];
                    registros[j + 1] = temp;
                    swapped = true;
                }
            }
            if (!swapped)
                break;
        }
    }
    void mostrarJuegosMasJugados() const {
        cout << "Videojuegos más jugados:" << endl;
        for (const auto& registro : registros) {
            cout << "Nombre del jugador: " << registro.nombreJugador << ", Tiempo jugado: " << registro.tiempoJugado << " horas, Videojuego: " << registro.juego->getNombre() << endl;
        }
    }
};

int main(){
    int num;

    cout<<"----Bienvenido a GameMaster----"<<endl;
    cout<<"Este es un Sistema de Gestión y Desarrollo de Videojuegos en C++"<<endl;

    do{
        cout<<"Aqui puedes encontrar estas funciones: "<<endl;
        cout<<"1)Juego Ahorcado\n ";
        cout<<"2)Juego Triqui\n ";
        cout<<"3)Almacenamiento de videojuegos\n ";
        cout<<"4)Ver tus favoritos\n ";
        cout<<"5)Salir del programa\n ";
        cout<<"Elige tu opcion: \n ";
        cin>>num;
        
        switch (num)
        {
        case 1:
            /* code */
            break;
        
        default:
            break;
        }
    }while(num!=7);
}

