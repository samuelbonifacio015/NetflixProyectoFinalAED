#pragma once
#include "Contenido.h"
#include "Recursos.h"

class Pelicula : public Contenido
{
public:
	string fechaEstreno;
	float calificacion;

	Pelicula()
		: Contenido(0, "", 0, "", nullptr, {}), fechaEstreno(""), calificacion(0.0) {}

	Pelicula(int id, string titulo, int duracion, string genero, Director* director, const vector<Actor*>& actores, string fechaEstreno, float calificacion)
		: Contenido(id, titulo, duracion, genero, director, actores), fechaEstreno(fechaEstreno), calificacion(calificacion) {}

	string obtenerFechaEstreno() const { return fechaEstreno; }
	float obtenerCalificacion() const { return calificacion; }

	const vector<Actor*>& obtenerActores() const
	{
		return this->actores;
	}

	void reproducirPelicula(const string& titulo, int duracion)
	{
		system("cls");
		cout << "-----------------------" << endl;
		cout << "Reproduciendo: " << titulo << endl;
		cout << "Duracion: " << duracion << " minutos" << endl;
		cout << "-----------------------" << endl;

		cout << "Presione cualquier tecla para detener la reproduccion..." << endl;

		_getch();         
		system("cls");
	}

	void filtrarPorGenero(const vector<Pelicula>& contenidos, const string& genero)
	{
		vector<Pelicula> peliculasFiltradas;

		for (const auto& pelicula : contenidos)
		{
			if (pelicula.obtenerGenero() == genero)
			{
				peliculasFiltradas.push_back(pelicula);
			}
		}

		if (peliculasFiltradas.empty())
		{
			cout << "No se encontraron peliculas en el genero: " << genero << endl;
		}
		else {
			cout << "Peliculas en el genero " << genero << ":" << endl;
			for (const auto& pelicula : peliculasFiltradas)
			{
				cout << "=============================================" << endl;
				cout << pelicula.obtenerTitulo() << " - " << pelicula.obtenerCalificacion() << endl;
				cout << "=============================================" << endl;
			}
		}
	}

    // enum para especificar el criterio de ordenación
    enum Criterio { Calificacion, FechaEstreno, Duracion };

    // método para realizar el algoritmo de ordenación merge sort en un vector de peliculas
    // `criterioOrd` indica si se debe ordenar de manera ascendente (true) o descendente (false)
    // `criterio` especifica el atributo de pelicula a utilizar para la ordenación
    static void mergeSort(vector<Pelicula>& contenidos, int izquierda, int derecha, bool criterioOrd, Criterio criterio)
    {
        if (izquierda < derecha) {
            int medio = izquierda + (derecha - izquierda) / 2;

            // ordena la mitad izquierda
            mergeSort(contenidos, izquierda, medio, criterioOrd, criterio);

            // ordena la mitad derecha
            mergeSort(contenidos, medio + 1, derecha, criterioOrd, criterio);

            // fusiona ambas mitades ordenadas
            merge(contenidos, izquierda, medio, derecha, criterioOrd, criterio);
        }
    }

    // método auxiliar de `mergeSort` que fusiona dos mitades de `contenidos` ordenadas
    // `criterioOrd` indica si se debe ordenar de manera ascendente o descendente
    // `criterio` especifica el atributo de pelicula a utilizar para la comparación
    static void merge(vector<Pelicula>& contenidos, int izquierda, int medio, int derecha, bool criterioOrd, Criterio criterio)
    {
        int n1 = medio - izquierda + 1; // tamaño de la mitad izquierda
        int n2 = derecha - medio;       // tamaño de la mitad derecha

        // vectores temporales para almacenar las mitades
        vector<Pelicula> L(n1);
        vector<Pelicula> R(n2);

        // copia de datos a los vectores temporales L y R
        for (int i = 0; i < n1; i++)
            L[i] = contenidos[izquierda + i];
        for (int i = 0; i < n2; i++)
            R[i] = contenidos[medio + 1 + i];

        // función lambda para comparar dos peliculas en base al criterio y el orden especificados
        auto comparar = [criterioOrd, criterio](const Pelicula& a, const Pelicula& b) {
            switch (criterio) {
            case Calificacion:
                // ordena por calificación
                return criterioOrd ? (a.obtenerCalificacion() < b.obtenerCalificacion())
                    : (a.obtenerCalificacion() > b.obtenerCalificacion());
            case FechaEstreno:
                // ordena por fecha de estreno
                return criterioOrd ? (a.obtenerFechaEstreno() < b.obtenerFechaEstreno())
                    : (a.obtenerFechaEstreno() > b.obtenerFechaEstreno());
            case Duracion:
                // ordena por duración
                return criterioOrd ? (a.obtenerDuracion() < b.obtenerDuracion())
                    : (a.obtenerDuracion() > b.obtenerDuracion());
            }
            return false; // valor por defecto, aunque no debería alcanzarse
            };

        int i = 0, j = 0, k = izquierda;

        // fusiona los datos ordenados en `contenidos` en base a `comparar`
        while (i < n1 && j < n2) {
            if (comparar(L[i], R[j])) {
                contenidos[k] = L[i];
                i++;
            }
            else {
                contenidos[k] = R[j];
                j++;
            }
            k++;
        }

        // copia los elementos restantes de L, si los hay
        while (i < n1) {
            contenidos[k] = L[i];
            i++;
            k++;
        }

        // copia los elementos restantes de R, si los hay
        while (j < n2) {
            contenidos[k] = R[j];
            j++;
            k++;
        }
    }

};