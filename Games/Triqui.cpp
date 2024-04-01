#include <iostream>
#include <stdio.h>
#include <time.h>
using namespace std;

void loop(char c[3][3]);
void introducirPrimerNumero(char c[3][3]);
void tableroDeJuego(char c[3][3]);
void numeroUsuario(char c[3][3]);
void numeroMaquina(char c[3][3]);
bool verificarGanador(char c[3][3], char jugador);

int main() {
   int partidasTriqui = 0; // Contador de partidas
    char jugarNuevamente;
    do {
        partidasTriqui++;
        char c[3][3];
        loop(c);
        cout << "Número de partidas jugadas: " << partidasTriqui << endl;
        cout << "¿Deseas jugar de nuevo? (s/n): ";
        cin >> jugarNuevamente;
    } while (jugarNuevamente == 's' || jugarNuevamente == 'S');
    return 0;
}

void loop(char c[3][3]) {
    clock_t inicio = clock();
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
    clock_t fin = clock(); 
    double tiempoJuego = (double)(fin - inicio) / CLOCKS_PER_SEC; 
    cout << "Tiempo de juego: " << tiempoJuego << " segundos" << endl;
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
            fflush(stdin);
            scanf(" %c", &aux);
        } while (aux < '1' || aux > '9');
        k = 0;
        switch (aux) {
            case '1':
                i = 0; j = 0;
                if (c[i][j] == 'X' || c[i][j] == 'O') {
                    k = 1;
                    cout << "Este espacio está ocupado, por favor selecciona otro!!\n\n";
                }
                break;
            case '2':
                i = 0; j = 1;
                if (c[i][j] == 'X' || c[i][j] == 'O') {
                    k = 1;
                    cout << "Este espacio está ocupado, por favor selecciona otro!!\n\n";
                }
                break;
            case '3':
                i = 0; j = 2;
                if (c[i][j] == 'X' || c[i][j] == 'O') {
                    k = 1;
                    cout << "Este espacio está ocupado, por favor selecciona otro!!\n\n";
                }
                break;
            case '4':
                i = 1; j = 0;
                if (c[i][j] == 'X' || c[i][j] == 'O') {
                    k = 1;
                    cout << "Este espacio está ocupado, por favor selecciona otro!!\n\n";
                }
                break;
            case '5':
                i = 1; j = 1;
                if (c[i][j] == 'X' || c[i][j] == 'O') {
                    k = 1;
                    cout << "Este espacio está ocupado, por favor selecciona otro!!\n\n";
                }
                break;
            case '6':
                i = 1; j = 2;
                if (c[i][j] == 'X' || c[i][j] == 'O') {
                    k = 1;
                    cout << "Este espacio está ocupado, por favor selecciona otro!!\n\n";
                }
                break;
            case '7':
                i = 2; j = 0;
                if (c[i][j] == 'X' || c[i][j] == 'O') {
                    k = 1;
                    cout << "Este espacio está ocupado, por favor selecciona otro!!\n\n";
                }
                break;
            case '8':
                i = 2; j = 1;
                if (c[i][j] == 'X' || c[i][j] == 'O') {
                    k = 1;
                    cout << "Este espacio está ocupado, por favor selecciona otro!!\n\n";
                }
                break;
            case '9':
                i = 2; j = 2;
                if (c[i][j] == 'X' || c[i][j] == 'O') {
                    k = 1;
                    cout << "Este espacio está ocupado, por favor selecciona otro!!\n\n";
                }
                break;
        }
    } while (k == 1);
    c[i][j] = 'X'; // Coloca la ficha del usuario
}

void numeroMaquina(char c[3][3]) {
    int i, j, k;

    srand(time(NULL));
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

