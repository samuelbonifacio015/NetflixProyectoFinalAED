#pragma once
#include <unordered_map>
#include <string>
#include <iostream>
#include "Pelicula.h"
#include "Cliente.h"
#include "Suscripcion.h"

using namespace std;

class HashTable {
private:
    unordered_map<string, Pelicula> peliculas;
    unordered_map<string, Cliente> clientes;
    unordered_map<string, Suscripcion> suscripciones;
    unordered_map<string, Pelicula> favoritos; // mapa para gestionar favoritos

public:
    // métodos para manejar peliculas
    void agregarPelicula(const Pelicula& pelicula) {
        peliculas[pelicula.obtenerTitulo()] = pelicula;
        cout << "Pelicula: " << pelicula.obtenerTitulo() << " ha sido agregada al catálogo." << endl;
    }

    bool buscarPelicula(const string& titulo) const {
        return peliculas.find(titulo) != peliculas.end();
    }

    void mostrarPeliculas() const {
        cout << "Lista de Peliculas:" << endl;
        for (const auto& par : peliculas) {
            cout << "- " << par.first << endl;
        }
    }

    // métodos para manejar clientes
    void agregarCliente(const Cliente& cliente) {
        clientes[cliente.obtenerNombre()] = cliente;
        cout << "Cliente: " << cliente.obtenerNombre() << " ha sido agregado al sistema." << endl;
    }

    bool buscarCliente(const string& nombre) const {
        return clientes.find(nombre) != clientes.end();
    }

    void mostrarClientes() const {
        cout << "Lista de Clientes:" << endl;
        for (const auto& par : clientes) {
            cout << "- " << par.first << endl;
        }
    }

    // métodos para manejar suscripciones
    void agregarSuscripcion(const Suscripcion& suscripcion) {
        suscripciones[suscripcion.obtenerPlan()] = suscripcion;
        cout << "Suscripcion: " << suscripcion.obtenerPlan() << " ha sido agregada." << endl;
    }

    bool buscarSuscripcion(const string& plan) const {
        return suscripciones.find(plan) != suscripciones.end();
    }

    void mostrarSuscripciones() const {
        cout << "Lista de Suscripciones:" << endl;
        for (const auto& par : suscripciones) {
            cout << "- " << par.first << endl;
        }
    }

    // métodos para manejar favoritos
    void agregarAFavoritos(const Pelicula& pelicula) {
        favoritos[pelicula.obtenerTitulo()] = pelicula;
        cout << "Pelicula: " << pelicula.obtenerTitulo() << " ha sido agregada a favoritos." << endl;
        cout << endl;
    }

    bool estaEnFavoritos(const string& titulo) const {
        return favoritos.find(titulo) != favoritos.end(); // verifica si una pelicula esta en favoritos
    }

    void mostrarFavoritos() {
        // si la lista de favoritos esta vacia
        if (favoritos.empty()) {
            cout << "La lista de favoritos está vacía, intente añadir una película." << endl;
            return;
        }

        bool continuar = true;
        while (continuar && !favoritos.empty())
        {
            cout << "Lista de Favoritos:" << endl;
            int index = 1;
            vector <Pelicula> peliculas; //creamos un vector de peliculas
            for (const auto& par : favoritos) 
            {
                cout << index << "- " << par.first << endl; //para contar las peliculas y mostrarlas
                peliculas.push_back(par.second);
                index++; //por cada pelicula agregada, el indice va a aumentando
            }

            cout << endl;
            cout << "=============================" << endl;
            cout << "Opciones: " << endl;
            cout << "1. Reproducir una pelicula" << endl;
            cout << "2. Salir" << endl;
            cout << "Ingrese una opcion: ";
            int opcion;
            cin >> opcion;

            switch (opcion) {
            case 1:
                int peliculaIndex; //creamos un indice de pelicula 
                cout << "Ingrese el numero de pelicula a reproducir: ";
                cin >> peliculaIndex;

                if (peliculaIndex > 0 && peliculaIndex <= peliculas.size())
                {
                    Pelicula& peliculaSeleccionada = peliculas[peliculaIndex - 1];
                    cout << "Reproduciendo: " << peliculaSeleccionada.obtenerTitulo() << endl;
                    peliculaSeleccionada.reproducirPelicula(peliculaSeleccionada.obtenerTitulo(), peliculaSeleccionada.obtenerDuracion());
                }
                else {
                    cout << "Numero no valida, intente de nuevo." << endl;
                }
                break;
            case 2:
                continuar = false;
                break;
            
            default:
                cout << "Opción no valida, intente de nuevo." << endl;
            }
        }            
    }
};
