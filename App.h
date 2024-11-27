#pragma once
#include "Archivo.h"
#include "BusquedaBinaria.h"
#include "Recursos.h"
#include "HashTable.h"
#include "ColaReproduccion.h"
#include "Cliente.h"
#include "Grafos.h"
#include "Pago.h"
#include <conio.h>

class App
{
private:
	Lista<Pelicula> listaPelicula;
	Lista<Cliente> listaCliente;
	FileHandler FileHandler;
	BinarySearchPelicula<Pelicula> busqueda;
	HashTable favoritos;	
	ColaReproduccion listaReproduccion;
	//CGrafo<Pelicula*> grafo;

public:

	bool loadFilePelicula(const string& file_url)
	{
		FileHandler.setFileURL(file_url);
		return FileHandler.loadFilePelicula(listaPelicula);
	}

	void saveFilePelicula()
	{
		FileHandler.saveFilePelicula(listaPelicula);
	}

	bool loadFileCliente(const string& file_url)
	{
		FileHandler.setFileURL(file_url);
		return FileHandler.loadFileCliente(listaCliente);
	}

	void saveFileCliente()
	{
		FileHandler.saveFileCliente(listaCliente);
	}

	// método para cargar clientes desde un archivo
	bool cargarClientesDesdeArchivo(const string& filename) {
		ifstream file(filename);
		if (!file.is_open()) {
			cout << "Error: No se pudo abrir el archivo " << filename << "." << endl;
			return false;
		}

		string line;
		while (getline(file, line)) {
			stringstream ss(line);
			string id, nombre, correo;

			if (getline(ss, id, ',') && getline(ss, nombre, ',') && getline(ss, correo, ',')) {
				try {
					int id_cliente = stoi(id);
					Cliente nuevoCliente(id_cliente, nombre, "", correo, "");
					listaCliente.agregar(nuevoCliente);
				}
				catch (const exception& e) {
					cout << "Error al procesar la línea: " << line << ". Detalle: " << e.what() << endl;
				}
			}
			else {
				cout << "Línea mal formateada: " << line << endl;
			}
		}

		file.close();
		cout << "Clientes cargados exitosamente desde " << filename << "." << endl;
		return true;
	}

	// método para seleccionar un cliente al iniciar
	Cliente* seleccionarCliente() {
		cout << "Clientes disponibles:" << endl;
		for (const Cliente& cliente : listaCliente.obtener()) {
			cout << "ID: " << cliente.obtenerID() << ", Nombre: " << cliente.obtenerNombre() << endl;
		}

		int id_cliente;
		cout << "Ingrese el ID del cliente con el que desea ingresar: ";
		cin >> id_cliente;

		for (Cliente& cliente : listaCliente.obtener()) {
			if (cliente.obtenerID() == id_cliente) {
				cout << "Cliente seleccionado: " << cliente.obtenerNombre() << endl;
				return &cliente;
			}
		}
	}

	/*
	void registrarCliente(Lista<Cliente>& lista)
	{
		int id;
		string nombre, telefono, correoElectronico, contrasena;

		cout << "Ingrese el ID del cliente: ";
		cin >> id;
		cin.ignore();
		cout << "Ingrese el nombre del cliente: ";
		getline(cin, nombre);

		cout << "Ingrese el telefono del cliente: ";
		getline(cin, telefono);

		cout << "Ingrese el correo electronico del cliente: ";
		getline(cin, correoElectronico);

		cout << "Ingrese la contrasena del cliente: ";
		getline(cin, contrasena);

		Cliente nuevoCliente(id, nombre, telefono, correoElectronico, contrasena);

		lista.agregar(nuevoCliente);
		saveFileCliente();

		cout << "Cliente registrado exitosamente y guardado en el archivo.\n";
		cout << endl; cout << endl;
	}
	

	// método para iniciar sesion
	Cliente* iniciarSesion() {
		string correo, contrasena;
		cout << "Ingrese su correo electronico: ";
		cin >> correo;
		cout << "Ingrese su contrasena: ";
		cin >> contrasena;

		for (Cliente& cliente : listaCliente.obtener()) {
			if (cliente.obtenerCorreoElectronico() == correo && cliente.obtenerContrasena() == contrasena) {
				cout << "Inicio de sesion exitoso. Bienvenido, " << cliente.obtenerNombre() << "!" << endl;
				return &cliente;
			}
		}
		cout << "Correo o contrasena incorrectos. Intente de nuevo." << endl;
		return nullptr;
	}
	

	// muestra el menú inicial de la aplicacion
	void menuInicial() {
		int opcion;
		do {
			cout << "=============================" << endl;
			cout << "       MENU INICIAL         " << endl;
			cout << "=============================" << endl;
			cout << "1. Registrarse" << endl;
			cout << "2. Iniciar Sesion" << endl;
			cout << "3. Entrar como Invitado" << endl;
			cout << "4. Salir" << endl;
			cout << "Ingrese su opcion: ";
			cin >> opcion;

			switch (opcion) {
			case 1: {
				// opcion para registrarse
				system("cls");
				registrarCliente(listaCliente); // registra un nuevo cliente				
				break;
			}
			case 2: {
				// opcion para iniciar sesion
				Cliente* cliente = iniciarSesion();
				if (cliente) {
					system("cls");
					mostrarMenuPago(cliente); // mostrar menú de pago después de iniciar sesion
					bienvenida(); // mostrar bienvenida después del pago
					system("cls");
					run(); // iniciar la aplicacion
				}
				break;
			}
			case 3:
				// opcion para entrar como invitado
				cout << "Entrando como invitado..." << endl;
				bienvenida(); // mostrar bienvenida al invitado
				system("cls");
				run(); // iniciar la aplicacion en modo invitado
				break;
			case 4:
				// opcion para salir de la aplicacion
				cout << "Saliendo de la aplicacion..." << endl;
				return;
			default:
				cout << "Opcion no valida. Intente de nuevo." << endl;
			}
		} while (opcion != 4);
	}
	*/

	 // mostrar el menú de pago
    void mostrarMenuPago(Cliente* cliente) {       

        int opcion;
        bool pagoRealizado = false;

        do {
            cout << "=============================" << endl;
            cout << "      MENU DE PAGO           " << endl;
            cout << "=============================" << endl;
            cout << "1. HD (S/ 20.00, 1 mes)" << endl;
            cout << "2. FULL HD (S/ 30.00, 1 mes)" << endl;
            cout << "3. 4K (S/ 50.00, 1 mes)" << endl;
            cout << "4. Ingresar Como invitado" << endl;
            cout << "Ingrese su opcion: ";
            cin >> opcion;

            Pago pago;
            switch (opcion) {
                case 1:
                    pago = Pago(cliente->obtenerNombre(), "Tarjeta de Credito", "HD", 20.0, 1);
                    pago.realizarPago();
                    pagoRealizado = true;
                    break;
                case 2:
                    pago = Pago(cliente->obtenerNombre(), "Tarjeta de Credito", "FULL HD", 30.0, 1);
                    pago.realizarPago();
                    pagoRealizado = true;
                    break;
                case 3:
                    pago = Pago(cliente->obtenerNombre(), "Tarjeta de Credito", "4K", 50.0, 1);
                    pago.realizarPago();
                    pagoRealizado = true;
                    break;
                case 4:
                    cout << "Cancelando suscripción..." << endl;
                    break;
                default:
                    cout << "Opción no válida. Intente de nuevo." << endl;
            }
        } while (!pagoRealizado && opcion != 4);

        if (pagoRealizado) {
            cout << "Pago realizado exitosamente. ¡Disfrute su experiencia!" << endl;
        }
    }


	// funcion principal de ejecucion de la aplicacion
	void iniciarApp()
	{
		cout << "Cargando Clientes desde archivo... " << endl;
		if (!cargarClientesDesdeArchivo("ListaClientesTemp.txt"))
		{
			cout << "No se pudieron cargar los clientes. " << endl;
			return;
		}
		
		Cliente* cliente = seleccionarCliente();
		if (cliente)
		{
			mostrarMenuPago(cliente);
		}
		else {
			cout << "No se pudo seleccionar cliente. Saliendo del programa." << endl;
		}
	}

	void bienvenida()
	{
		vector<Cliente> nombre = listaCliente.obtener();

		cout << "===========================================" << endl;
		cout << "             BIENVENIDO                   " << endl;
		cout << "===========================================" << endl;
		listaCliente.imprimirNombreCliente(nombre);
		cout << "  ¡     Nos alegra tenerte con nosotros    !" << endl;
		cout << "===========================================" << endl;
		cout << "       ¡Disfruta de tu experiencia!       " << endl;
		cout << "===========================================" << endl;
		cout << endl;
		cout << "(Presione Enter para Continuar)";
		cout << endl;

		int tecla = 0;
		while (true) {
			if (_kbhit()) {
				tecla = getch();
				if (tecla == 13) {
					tecla = 0;
					break;
				}
			}
		}
	}

	bool init()
	{
		return loadFilePelicula("ListaPeliculas.txt") && loadFileCliente("ListaClientes.txt");
	}

	void mostrarFavoritos() {
		favoritos.mostrarFavoritos();
	}

	void mostrarListaReproduccion() {
		listaReproduccion.mostrarCola();
		listaReproduccion.reproducirSiguiente();
	}

	void mostrarSubmenuPelicula(Pelicula& pelicula, ColaReproduccion& listaReproduccion, HashTable& favoritos)
	{
		cout << endl;
		cout << "Opciones:" << endl;
		cout << "Enter - Reproducir" << endl;
		cout << "Q - Agregar a Lista de Reproduccion" << endl;
		cout << "F - Agregar a Favoritos" << endl;
		cout << "Presione una tecla para seleccionar una opcion..." << endl;
		cout << endl;

		char opcion = _getch();
		switch (opcion)
		{
		case 13:         
			pelicula.reproducirPelicula(pelicula.obtenerTitulo(), pelicula.obtenerDuracion());
			Console::Clear;
			break;

		case 'q':
		case 'Q':
			listaReproduccion.agregarACola(pelicula);            
			Console::Clear;
			break;

		case 'f':
		case 'F':
			favoritos.agregarAFavoritos(pelicula);          
			Console::Clear;
			break;

		default:
			cout << "Opcion no valida." << endl;
			break;
		}
	}

	/*void recomendacionPorGenero(int peliculElegida)
	{
		string generoElegido = grafo.obtenerVertice(peliculElegida)->obtenerGenero();
		cout << "Recomendaciones basadas en el género '" << generoElegido << "':" << endl;
		for (int i = 0; i < grafo.cantidadVertices(); i++) 
		{
			if (grafo.obtenerVertice(i)->obtenerGenero() == generoElegido)
			{
				// Solo recomendar peliculas diferentes
				if (i != peliculElegida)
				{
					grafo.obtenerVertice(i)->mostrar();
				}
			}
		}
	} */

	void recomendarPelicula()
	{
		CGrafo<Pelicula*> grafoRecomendaciones;
		cout << "========================================" << endl;
		cout << " Recomendacion de Peliculas Similares " << endl;
		cout << "========================================" << endl;

	}

	void mostrarLogos()
	{
		Mostrar_LogoUPC();
		Imprimir_Netflix();
	}

	void run()
	{

			mostrarLogos();

			cout << "=============================" << endl;
			cout << "     CARGANDO  ARCHIVOS      "  << endl;
			cout << "=============================" << endl;

			if (!loadFilePelicula("ListaPeliculas.txt") || !loadFileCliente("ListaClientesTemp.txt"))
			{
				cout << "Error al cargar los archivos. Saliendo." << endl;
				return;
			}
			cout << "Archivos cargados exitosamente." << endl;

			//seleccionar cliente
			Cliente* cliente = nullptr;
			while (!cliente)
			{
				cliente = seleccionarCliente();
			}
		
			system("cls");
			//mostrarMenuPago(cliente);  
			system("cls");
			bienvenida();
		

		int eleccion = 0;
		BinarySearchPelicula<Pelicula> buscador;
		vector<Pelicula> contenidos = listaPelicula.obtener();

		do {
			cout << "=============================" << endl;
			cout << "       MENU PRINCIPAL       " << endl;
			cout << "=============================" << endl;
			cout << "1. Listar todas las peliculas" << endl;
			cout << "2. Buscar una pelicula por titulo" << endl;
			cout << "3. Filtrar por genero (mejor pelicula de cada genero)" << endl;
			cout << "4. Mostrar Lista de Reproduccion actual" << endl;
			cout << "5. Mostrar Lista de Favoritos" << endl;
			cout << "6. Creditos" << endl;
			cout << "7. Salir" << endl;
			cout << "Ingrese su eleccion: ";
			cin >> eleccion;

			switch (eleccion)
			{
			case 1:
				system("cls");
				cout << "===================================" << endl;
				cout << "  Lista de peliculas (sin ordenar)  " << endl;
				cout << "===================================" << endl;
				listaPelicula.imprimirContenidos(contenidos);
				cout << endl;
				
				int opcion;
				do {
					cout << "===================================" << endl;
					cout << "  Ordenar peliculas por calificacion " << endl;
					cout << "===================================" << endl;
					cout << "1. Ordenar de forma ascendente (calificacion)" << endl;
					cout << "2. Ordenar de forma descendente (calificacion)" << endl;
					cout << "3. Ordenar de forma ascendente (Fecha de Estreno)" << endl;
					cout << "4. Ordenar de forma descendente (Fecha de Estreno)" << endl;
					cout << "5. Ordenar de forma ascendente (Duracion)" << endl;
					cout << "6. Ordenar de forma descendente (Duracion)" << endl;
					cout << "7. Volver al menu principal" << endl;
					cout << "Elige una opcion: ";
					cin >> opcion;

					switch (opcion)
					{
					case 1:
						system("cls");
						Pelicula::mergeSort(contenidos, 0, contenidos.size() - 1, true, Pelicula::Calificacion);
						cout << "Peliculas ordenadas de forma ascendente por calificacion:" << endl;
						listaPelicula.imprimirContenidosCalificacion(contenidos);
						cout << endl;
						break;

					case 2:
						system("cls");
						Pelicula::mergeSort(contenidos, 0, contenidos.size() - 1, false, Pelicula::Calificacion);
						cout << "Peliculas ordenadas de forma descendente por calificacion:" << endl;
						listaPelicula.imprimirContenidosCalificacion(contenidos);
						cout << endl;
						cout << endl;
						break;

					case 3:
						system("cls");
						Pelicula::mergeSort(contenidos, 0, contenidos.size() - 1, true, Pelicula::FechaEstreno);
						cout << "Peliculas ordenadas de forma ascendente por fecha de estreno:" << endl;
						listaPelicula.imprimirContenidosEstreno(contenidos);
						cout << endl;
						break;

					case 4:
						system("cls");
						Pelicula::mergeSort(contenidos, 0, contenidos.size() - 1, false, Pelicula::FechaEstreno);
						cout << "Peliculas ordenadas de forma descendente por fecha de estreno:" << endl;
						listaPelicula.imprimirContenidosEstreno(contenidos);
						cout << endl;
						break;

					case 5:
						system("cls");
						Pelicula::mergeSort(contenidos, 0, contenidos.size() - 1, true, Pelicula::Duracion);
						cout << "Peliculas ordenadas de forma ascendente por duracion:" << endl;
						listaPelicula.imprimirContenidosTiempo(contenidos);
						cout << endl;
						break;

					case 6:
						system("cls");
						Pelicula::mergeSort(contenidos, 0, contenidos.size() - 1, false, Pelicula::Duracion);
						cout << "Peliculas ordenadas de forma descendente por duracion:" << endl;
						listaPelicula.imprimirContenidosTiempo(contenidos);
						cout << endl;
						break;

					default:
						system("cls");
						break;
					}
				} while (opcion != 7);

				break;

			case 2:
			{
				system("cls");
				string titulo;
				cout << "Buscar pelicula: ";
				cin.ignore();
				getline(cin, titulo);

				int indice = busqueda.buscarPorTitulo(contenidos, titulo);
				if (indice != NOT_FOUND) {
					Pelicula& peliculaEncontrada = contenidos[indice];
					cout << endl;
					cout << "==============================" << endl;
					cout << "Pelicula encontrada:" << endl;
					cout << "Titulo: " << peliculaEncontrada.obtenerTitulo() << endl;
					cout << "Genero: " << peliculaEncontrada.obtenerGenero() << endl;
					cout << "Duracion: " << peliculaEncontrada.obtenerDuracion() << " minutos" << endl;
					cout << "Director: " << peliculaEncontrada.obtenerDirector()->obtenerNombre() << endl;
					cout << "Actores: ";
					for (const auto& actor : peliculaEncontrada.obtenerActores())
					{
						cout << actor->obtenerNombre() << ", ";
					}
					cout << endl;

					cout << "Anio: " << peliculaEncontrada.obtenerFechaEstreno() << endl;
					cout << "Calificacion: " << peliculaEncontrada.obtenerCalificacion() << endl;
					cout << "==============================" << endl;

					mostrarSubmenuPelicula(peliculaEncontrada, listaReproduccion, favoritos);
				}
				else
				{
					cout << "Pelicula no encontrada. Intente de nuevo." << endl;
				}
				break;
			}

			case 3:
			{
				system("cls");
				string genero;
				cout << "Ingrese el genero que desea buscar: ";
				cin.ignore();
				getline(cin, genero);

				int indiceMejorPelicula = buscador.buscarMejorPorGenero(contenidos, genero);
				if (indiceMejorPelicula != NOT_FOUND)
				{
					Pelicula mejorPelicula = contenidos[indiceMejorPelicula];
					cout << "=============================================" << endl;
					cout << "La mejor pelicula de genero " << genero << " es:" << endl;
					cout << "=============================================" << endl;
					cout << "Titulo: " << mejorPelicula.obtenerTitulo() << endl;
					cout << "Calificacion: " << mejorPelicula.obtenerCalificacion() << endl;
					mostrarSubmenuPelicula(mejorPelicula, listaReproduccion, favoritos);
				}
				else {
					cout << "No se encontraron peliculas de ese genero." << endl;
				}
				break;
			}

			case 4:
				system("cls");				
				listaReproduccion.mostrarCola();				
				cout << endl;
				break;

			case 5:
				system("cls");
				cout << "=============================" << endl;
				cout << "     LISTA DE  FAVORITOS     " << endl;
				cout << "=============================" << endl;
				favoritos.mostrarFavoritos();
				cout << endl;
				break;

			case 6:
				system("cls");
				Mostrar_Creditos();
				break;

			case 7:
				cout << "Saliendo del programa.. " << endl;
				return;

			default:
				cout << "Opcion no valida. Intente de nuevo." << endl;
				break;
			}
		} while (eleccion != 7);
	}

	
	
};