#include <iostream>
#include <vector>
#include<string>
#include"./Videojuego.cpp"
#include"./Game.cpp"
#include"./Ahorcado.cpp"
#include"./Triqui.cpp"

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

