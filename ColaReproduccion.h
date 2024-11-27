#pragma once
#include "Pelicula.h"
#include <queue>
#include <iostream>
using namespace std;

class ColaReproduccion {
private:
    queue<Pelicula> cola;

public:
    void agregarACola(const Pelicula& pelicula)
    {
        cola.push(pelicula);
        cout << "Pelicula: " << pelicula.obtenerTitulo() << " agregada a la Cola de Reproduccion" << endl;
        cout << endl;
    }

    void reproducirSiguiente()
    {
        if (cola.empty())
        {
            cout << "No hay peliculas en la lista de reproduccion, agregue una." << endl;
        }
        else {
            Pelicula peliculaActual = cola.front();
            cola.pop();
            cout << "Reproduciendo: " << peliculaActual.obtenerTitulo() << endl;
        }
    }

    void mostrarCola()
    {
        // si la cola est� vac�a
        if (cola.empty()) {
            cout << "La lista de reproduccion esta vacia, intente a�adir una pelicula." << endl;
            return;
        }

        bool continuar = true;
        while (continuar && !cola.empty()) {
            cout << "=============================" << endl;
            cout << "    LISTA DE REPRODUCCION    " << endl;
            cout << "=============================" << endl;

            // mostrar la cola de reproducci�n
            queue<Pelicula> temp = cola;
            int index = 1;
            while (!temp.empty()) {
                cout << index << ". " << temp.front().obtenerTitulo();
                if (index == 1) {
                    cout << " <- En reproduccion";
                    cout << endl;
                }
                cout << endl;
                temp.pop();
                index++;
            }

            // mostrar el men�
            cout << "=============================" << endl;
            cout << "1. Pasar a la siguiente pelicula" << endl;
            cout << "2. Borrar la pelicula actual" << endl;
            cout << "3. Salir del menu" << endl;
            cout << "Ingrese su opcion: ";
            int opcion;
            cin >> opcion;

            switch (opcion) {
            case 1:
                // pasar a la siguiente pel�cula
                cout << "Pasando a la siguiente pelicula..." << endl;
                reproducirSiguiente();
                break;
            case 2:
                // eliminar la pel�cula actual
                if (!cola.empty()) {
                    cout << "Eliminando la pelicula actual: " << cola.front().obtenerTitulo() << endl;
                    cola.pop();
                }
                else {
                    cout << "No hay peliculas para eliminar." << endl;
                }
                break;
            case 3:
                // salir del men�
                continuar = false;
                break;
            default:
                cout << "Opci�n no valida, intente de nuevo." << endl;
            }
        }

        if (cola.empty()) {
            cout << "La lista de reproduccion esta vacia." << endl;
        }
    }
};
