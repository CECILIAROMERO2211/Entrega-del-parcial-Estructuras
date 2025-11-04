// Universidad Cuauhtémoc Querétaro
// Materia: Programación Orientada a Objetos
// Profesor: M. en C. Adrián Ulises González Casillas
// Práctica: Entrega del Parcial – Ejercicios Listas, Doblemente ligadas, Stacks y Queues
// Parte: Punto 1 – Lista con centinela-SentinelLinkedList
// Explicación: Este código cumple el punto 1 del examen. Aquí se crea una lista que puede guardar varios datos uno tras otro.
// Se usa una parte especial llamada “centinela” que marca el inicio y el final, lo que ayuda a que el programa sea más ordenado.
// También se agregan dos funciones importantes: una que mete datos al inicio (AgregarInicio) y otra que los saca (QuitarInicio).
// Estas funciones trabajan de manera rápida porque no necesitan recorrer toda la lista.
// Alumnos: Cecilia Romero Granados, Alexis Jeshua Arrona

#pragma once
#include <iostream>
using namespace std;

// Esta lista sirve para guardar datos, por ejemplo números o palabras, y los organiza uno detrás de otro.
template <typename T> // Esto permite que funcione con distintos tipos de datos.
class SentinelLinkedList {
private:
    // Cada elemento que se guarda dentro de la lista es una "parte" que contiene el dato
    // y sabe quién está antes y quién está después.
    class Parte {
    public:
        // Aquí se crea una nueva parte con un dato 
        Parte(T _dato) : dato(_dato), siguiente(nullptr), anterior(nullptr) {}

        T dato;           // Es el valor que queremos guardar 
        Parte* siguiente; // Apunta a la parte que está después en la lista.
        Parte* anterior;  // Apunta a la parte que está antes en la lista.
    };

    Parte* centinela; // Es una parte vacía que marca el inicio y el final de la lista. Nunca se borra.
    int cantidad;     // Guarda cuántos datos hay en la lista.

public:
                           
    SentinelLinkedList() { // Cuando se crea la lista, se deja vacía y preparada para usarse.
        centinela = new Parte(T{});  // Se crea la parte “centinela” vacía.
        centinela->siguiente = centinela; // Al principio apunta a sí misma, porque aún no hay datos.
        centinela->anterior = centinela;  // aqui se considera que la parte que está antes de ella, es ella misma
        cantidad = 0;                     // Se indica que la lista tiene 0 elementos.
    }

   
    ~SentinelLinkedList() { // Cuando la lista se borra, se eliminan todas las partes que tiene para no gastar memoria.
        Parte* actual = centinela->siguiente; // Empezamos desde la primera parte real.
        while (actual != centinela) {         // Recorremos toda la lista hasta volver al centinela.
            Parte* temporal = actual;         // Guardamos la parte actual.
            actual = actual->siguiente;       // Avanzamos a la siguiente.
            delete temporal;                  // Borramos la parte que acabamos de pasar.
        }
        delete centinela;                     // Al final, borramos el centinela.
    }


    void AgregarFinal(T valor) { // Esta función agrega un dato al final de la lista.
        Parte* nueva = new Parte(valor);   // Creamos una nueva parte con el valor que nos dan.
        centinela->anterior->siguiente = nueva; // La última parte que había se conecta con la nueva.
        nueva->anterior = centinela->anterior;  // La nueva parte sabe quién estaba antes.
        nueva->siguiente = centinela;           // Al final apunta al centinela que define el final.
        centinela->anterior = nueva;            // El centinela ahora reconoce a esta como la última parte.
        cantidad++;                             // Aumentamos la cantidad de elementos.
    }

    // Esta función agrega un dato al inicio de la lista.
    void AgregarInicio(T valor) {
        Parte* nueva = new Parte(valor);        // Se crea una nueva parte con el valor que se quiere guardar.
        nueva->siguiente = centinela->siguiente; // La nueva parte se conecta con la que era la primera.
        nueva->anterior = centinela;             // Su anterior es el centinela en la parte inicial.
        centinela->siguiente->anterior = nueva;  // La antigua primera se conecta hacia atrás con la nueva.
        centinela->siguiente = nueva;            // El centinela apunta a la nueva como la primera parte.
        cantidad++;                              // Se suma uno a la cantidad de datos guardados.
    }

    // Esta función quita el primer dato de la lista y lo devuelve.
    T QuitarInicio() {
        if (cantidad == 0) {                      // Si no hay datos en la lista...
            cout << "No hay datos para quitar." << endl;
            return T{};                           // Se devuelve un valor vacío.
        }

        Parte* aBorrar = centinela->siguiente;    // Tomamos la primera parte real.
        T valor = aBorrar->dato;                  // Guardamos el dato que tiene.
        centinela->siguiente = aBorrar->siguiente; // El centinela ahora apunta al segundo como primero.
        aBorrar->siguiente->anterior = centinela;  // El nuevo primero se conecta hacia atrás con el centinela.
        delete aBorrar;                            // Borramos la parte que se quitó.
        cantidad--;                                // Restamos uno a la cantidad total.
        return valor;                              // Devolvemos el dato que se quitó.
    }

    // Esta función quita el último dato de la lista.
    T QuitarFinal() {
        if (cantidad == 0) {                 // Si la lista está vacía, no se puede quitar nada.
            cout << "No hay datos en la lista." << endl;
            return T{};                      // Devuelve un valor vacío.
        }

        Parte* aBorrar = centinela->anterior; // Tomamos la última parte de la lista.
        T valor = aBorrar->dato;              // Guardamos el dato que tenía.
        aBorrar->anterior->siguiente = centinela; // La parte anterior ahora apunta al centinela.
        centinela->anterior = aBorrar->anterior;  // El centinela reconoce al nuevo último.
        delete aBorrar;                            // Borramos la parte que se quitó.
        cantidad--;                                // Restamos uno a la cantidad total.
        return valor;                              // Devolvemos el dato que se quitó.
    }

   
    T VerPrimero() { // Esta función muestra cuál es el primer dato de la lista, sin quitarlo.
        if (cantidad == 0) {                 // Si no hay datos, se avisa.
            cout << "La lista está vacía." << endl;
            return T{};                      // Se devuelve algo vacío.
        }
        return centinela->siguiente->dato;   // Devuelve el primer dato que hay guardado.
    }

    
    int CuantosHay() { // Esta función dice cuántos datos hay en la lista en este momento.
        return cantidad; // Devuelve el número total de elementos.
    }
};

