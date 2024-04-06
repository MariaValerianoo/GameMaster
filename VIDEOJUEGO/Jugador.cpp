#include <iostream>
#include <vector>
#include <string>
#include"./Videojuego.cpp"
#include"./Triqui.cpp"
#include"./Ahorcado.cpp"

using namespace std;

class Jugador {
private:
    string nombre;
    string nick;
    string numero;
    string clave;

public:
    Jugador() {}
    // Métodos get y set
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
        cout<<"Vamos a hacer tu registro "<<endl;
        cout<<"Ingresa tu Nombre: "<<endl;
        cin>>nombre;
        cout<<"Ingresa tu Nickname: "<<endl;
        cin>>nick;
        cout << "Ingrese su numero de telefono: "<<endl;
        cin>>numero;
        while (numero.length()!=10)
        {
            cout<<"No es correcto el numero vuelve a intentarlo"<<endl;
            cin>>numero;
        }
        cout<<"El numero es valido, ahora ingresa la contraseña'\n recuerda que debe tener 4 digitos: ";
        cin>> clave;
        while (clave.length()!=4)
        {
            cout<<"No es correcta la contraseña vuelve a intentarlo: "<<endl;
            cin>>clave;
        }
    }
    bool verificarCredenciales() { 
        string nickIngresado;
        string claveIngresada; 
        int intentos=3;
        cout<<"Ingrese su nickname: \n";
        cin>>nickIngresado;
        while (nickIngresado!=nick)
        {
            cout<<"No es correcto el nickname vuelve a intentarlo"<<endl;
            cout<<"Tienes 3 intentos "<<endl;
            cin>>nickIngresado;
            intentos--;
            if (intentos == 0) {
                return false;
            }
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

    void Inicio(){
        int op;
        cout<<"----Bienvenido a GameMaster----\n";
        do
        {
           cout<<"Que deseas hacer?: \n";
            cout<<"1)Registrarte \n2)Ingresar \n3)Salir \n ";
            cin>>op;
            switch (op)
            {
            case 1:
                registrarUsuario();
                break;
            
            case 2:
                if (verificarCredenciales()) {
                    secondMenu();
                } else {
                    cout << "Inicio de sesión fallido.\n";
                }
                break;
            
            }
        } while (op!=3);
        
    }
    void secondMenu(){
        int op;
        cout << "Inicio de sesión exitoso.\n";
        do{
            cout<<"----Bienvenido a GameMaster----"<<endl;
            cout<<"Este es un Sistema de Gestión y Desarrollo de Videojuegos en C++"<<endl;
            cout<<"Aqui puedes encontrar estas funciones: "<<endl;
            cout<<"1)Juego Ahorcado\n ";
            cout<<"2)Juego Triqui\n ";
            cout<<"3)Almacenamiento de videojuegos\n ";
            cout<<"4)Ver tus favoritos\n ";
            cout<<"5)Salir del programa\n ";
            cout<<"Elige tu opcion: \n ";
            cin>>op;
            switch (op)
            {
            case 1:
                registrarUsuario();
                break;
            
            case 2:
                if (verificarCredenciales()) {
                    cout << "Inicio de sesión exitoso.\n";
                } else {
                    cout << "Inicio de sesión fallido.\n";
                }
                break;
            
            }
        } while (op!=3);

        
        
    }
};
int main(){
    Jugador person;
    person.Inicio();
}