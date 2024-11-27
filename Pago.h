#pragma once
#include <iostream>
#include <string>
#include "Suscripcion.h"  // Incluye la clase base Suscripcion

using namespace std;

class Pago : public Suscripcion {
private:
    string nombreCliente;   // nombre del cliente que realiza el pago
    string metodoPago;      // m�todo de pago, por ejemplo "Tarjeta de Credito"

public:
    // Constructor por defecto
    Pago() : Suscripcion(), nombreCliente(""), metodoPago("") {}

    // Constructor parametrizado con inicializaci�n de strings
    Pago(string nombreCliente, string metodoPago, string plan, double costo, int duracion)
        : Suscripcion(plan, costo, duracion), nombreCliente(nombreCliente), metodoPago(metodoPago) {}

    // M�todo para realizar el pago
    void realizarPago() {
        if (verificarDatosPago()) {  // Verifica que todos los datos est�n completos
            cout << "Procesando pago para " << nombreCliente << endl;
            cout << "Metodo de pago: " << metodoPago << endl;
            cout << "Plan: " << plan << " por S/ " << costo << endl;
            cout << "Duracion: " << duracion << " meses" << endl;
            cout << "Pago realizado con exito!" << endl;
        }
        else {
            cout << "Error: Datos de pago incompletos. No se pudo realizar el pago." << endl;
        }
    }

    // M�todo para verificar que los datos de pago est�n completos
    bool verificarDatosPago() const {
        return !nombreCliente.empty() && !metodoPago.empty() && !plan.empty() && costo > 0 && duracion > 0;
    }

    // M�todos para obtener y establecer el nombre del cliente
    string obtenerNombreCliente() const { return nombreCliente; }
    void establecerNombreCliente(const string& nombre) { nombreCliente = nombre; }

    // M�todos para obtener y establecer el m�todo de pago
    string obtenerMetodoPago() const { return metodoPago; }
    void establecerMetodoPago(const string& metodo) { metodoPago = metodo; }

    // M�todos para obtener y establecer el plan
    string obtenerPlan() const { return plan; }
    void establecerPlan(const string& nuevoPlan) { plan = nuevoPlan; }

    // M�todos para obtener y establecer el costo
    double obtenerCosto() const { return costo; }
    void establecerCosto(double nuevoCosto) { costo = nuevoCosto; }

    // M�todos para obtener y establecer la duraci�n
    int obtenerDuracion() const { return duracion; }
    void establecerDuracion(int nuevaDuracion) { duracion = nuevaDuracion; }

    // M�todo para mostrar los detalles del pago
    void mostrarDetallesPago() const {
        cout << "=============================" << endl;
        cout << "Detalles del Pago" << endl;
        cout << "Cliente: " << nombreCliente << endl;
        cout << "Metodo de Pago: " << metodoPago << endl;
        cout << "Plan: " << plan << endl;
        cout << "Costo: S/ " << costo << endl;
        cout << "Duracion: " << duracion << " meses" << endl;
        cout << "=============================" << endl;
    }
};
