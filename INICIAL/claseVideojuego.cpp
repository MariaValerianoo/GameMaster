#include <iostream>
#include <vector>

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
    Videojuego(){

    };
    void setNombre(const string& nombre) { 
        this->nombre = nombre; }
    void setCantidadJugadores(int cantidadJugadores) { 
        this->cantidadJugadores = cantidadJugadores; }
    void setCategorias(const vector<string>& categorias) {
         this->categorias = categorias; }
    void setDesarrollador(const string& desarrollador) { 
        this->desarrollador = desarrollador; }
    void setAñoLanzamiento(int añoLanzamiento) { 
        this->añoLanzamiento = añoLanzamiento; }
    void setPlataforma(const string& plataforma) { 
        this->plataforma = plataforma; }
    string getNombre() const { 
        return nombre; }
    int getCantidadJugadores() const { 
        return cantidadJugadores; }
    vector<string> getCategorias() const { 
        return categorias; }
    string getDesarrollador() const { 
        return desarrollador; }
    int getAñoLanzamiento() const { 
        return añoLanzamiento; }
    string getPlataforma() const { 
        return plataforma; }
};
