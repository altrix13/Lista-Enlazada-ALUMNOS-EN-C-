#include <iostream>
#include <string>

using namespace std;

struct Nodo {

    string nombres;
    string apellidos;
    string carnet;
    string email;
    string telefono;

    float notas[5];

    Nodo* siguiente;
};

int main() {

    Nodo* inicio = NULL;
    Nodo* fin = NULL;

    char opcion;

    do {

        cout << "\nDesea ingresar un nuevo alumno? (S/N): ";
        cin >> opcion;

        cin.ignore();

        if (opcion == 'S' || opcion == 's') {

            Nodo* nuevoNodo = new Nodo;

            cout << "\nIngrese nombres: ";
            getline(cin, nuevoNodo->nombres);

            cout << "Ingrese apellidos: ";
            getline(cin, nuevoNodo->apellidos);

            cout << "Ingrese carnet: ";
            getline(cin, nuevoNodo->carnet);

            cout << "Ingrese email: ";
            getline(cin, nuevoNodo->email);

            cout << "Ingrese telefono: ";
            getline(cin, nuevoNodo->telefono);

            cout << "\nIngrese las 5 notas:\n";

            for (int i = 0; i < 5; i++) {

                cout << "Nota " << i + 1 << ": ";
                cin >> nuevoNodo->notas[i];
            }

            nuevoNodo->siguiente = NULL;

            if (inicio == NULL) {

                inicio = nuevoNodo;
                fin = nuevoNodo;

            } else {

                fin->siguiente = nuevoNodo;
                fin = nuevoNodo;
            }

            cin.ignore();
        }

    } while (opcion == 'S' || opcion == 's');

    cout << "\n=========== LISTA DE ALUMNOS ===========\n";

    Nodo* actual = inicio;

    while (actual != NULL) {

        cout << "\n----------------------------------\n";

        cout << "Nombres   : " << actual->nombres << endl;
        cout << "Apellidos : " << actual->apellidos << endl;
        cout << "Carnet    : " << actual->carnet << endl;
        cout << "Email     : " << actual->email << endl;
        cout << "Telefono  : " << actual->telefono << endl;

        cout << "Notas     : ";

        float suma = 0;

        for (int i = 0; i < 5; i++) {

            cout << actual->notas[i] << " ";

            suma += actual->notas[i];
        }

        float promedio = suma / 5;

        cout << "\nPromedio  : " << promedio << endl;

        actual = actual->siguiente;
    }

    actual = inicio;

    while (actual != NULL) {

        Nodo* auxiliar = actual;

        actual = actual->siguiente;

        delete auxiliar;
    }

    cout << "\nMemoria liberada correctamente." << endl;

    return 0;
}