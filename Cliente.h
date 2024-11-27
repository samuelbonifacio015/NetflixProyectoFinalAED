#pragma once  
#include "Recursos.h"

class Cliente
{
public:
    int id;
    string nombre;
    int telefono;
    string correoElectronico;
    string contrasena;

    Cliente() : id(0), nombre(""), telefono(0), correoElectronico(""), contrasena("") {}

    Cliente(int id, string nombre, string telefono, string correoElectronico, string contrasena)
        : id(id), nombre(nombre), telefono(0), correoElectronico(correoElectronico), contrasena(contrasena) {}

    int obtenerID() const { return id; }
    string obtenerNombre() const { return nombre; }
    int obtenerTelefono() const { return telefono; }
    string obtenerCorreoElectronico() const { return correoElectronico; }
    string obtenerContrasena()const { return contrasena; }
};
