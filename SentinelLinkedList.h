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

// Esta clase crea una lista doblemente ligada, al anterior y al siguiente). Se usa un "centinela", que es un nodo especial
// que marca el inicio y el final de la lista.
template <typename T>
class SentinelLinkedList
{
public:
    // Constructor es el que se ejecuta cuando se crea la lista.
    // Crea el centinela y lo conecta consigo mismo, lo que significa
    // que la lista empieza vacía.
    SentinelLinkedList()
    {
        centinela = new Elemento(T{});     // se crea el centinela sin datos reales
        centinela->siguiente = centinela;  // el siguiente del centinela apunta a él mismo
        centinela->anterior = centinela;   // el anterior también apunta a él mismo
        tamano = 0;                        // la lista empieza con 0 elementos
    }

    // Destructor: se ejecuta cuando la lista se elimina.
    // Libera toda la memoria usada por los elementos.
    ~SentinelLinkedList()
    {
        Elemento* actual = centinela->siguiente;  // empezamos desde el primer elemento real

        // borramos todos los elementos hasta llegar al centinela otra vez
        while (actual != centinela)
        {
            Elemento* borrar = actual;      // guardamos el elemento actual
            actual = actual->siguiente;     // avanzamos al siguiente
            delete borrar;                  // borramos el actual de memoria
        }

        delete centinela;                   // al final borramos el centinela
        cout << "La lista fue eliminada correctamente." << endl;
    }

    // Agrega un nuevo elemento al final de la lista.
    void Append(T valor)
    {
        Elemento* nuevo = new Elemento(valor);  // se crea un nuevo elemento con el valor recibido

        // Conectamos el nuevo elemento al final
        centinela->anterior->siguiente = nuevo; // el último elemento apunta al nuevo
        nuevo->anterior = centinela->anterior;  // el nuevo apunta hacia atrás al último
        centinela->anterior = nuevo;            // el centinela apunta hacia atrás al nuevo
        nuevo->siguiente = centinela;           // el nuevo apunta hacia adelante al centinela

        tamano++;                               // aumentamos el número de elementos
    }

    // Quita el último elemento y devuelve su valor.
    T PopBack()
    {
        if (tamano == 0)  // si la lista está vacía
        {
            cout << "No se puede quitar porque la lista está vacía." << endl;
            return T{};   // se devuelve un valor vacío
        }

        Elemento* borrar = centinela->anterior;  // el último elemento es el que está antes del centinela
        T valor = borrar->dato;                  // guardamos el valor
        EliminarElemento(borrar);                // eliminamos el nodo
        return valor;                            // devolvemos el valor
    }

    // Agrega un nuevo elemento al principio de la lista.
    void PushFront(T valor)
    {
        Elemento* nuevo = new Elemento(valor);    // se crea un nuevo elemento

        // Se conecta el nuevo elemento como primero
        nuevo->siguiente = centinela->siguiente;  // el nuevo apunta al primer elemento actual
        centinela->siguiente->anterior = nuevo;   // el primer elemento apunta al nuevo hacia atrás
        centinela->siguiente = nuevo;             // el centinela apunta al nuevo como siguiente
        nuevo->anterior = centinela;              // el nuevo apunta hacia atrás al centinela

        tamano++;                                 // se incrementa el tamaño
    }

    // Quita el primer elemento de la lista y devuelve su valor.
    T PopFront()
    {
        if (tamano == 0)  // si la lista está vacía
        {
            cout << "No se puede quitar el primero porque la lista está vacía." << endl;
            return T{};
        }

        Elemento* borrar = centinela->siguiente;  // el primer elemento está después del centinela
        T valor = borrar->dato;                   // guardamos su valor
        EliminarElemento(borrar);                 // lo eliminamos
        return valor;                             // devolvemos el valor quitado
    }

    // Devuelve el primer valor sin eliminarlo.
    T Front()
    {
        if (tamano == 0)
        {
            cout << "La lista está vacía, no hay elementos al inicio." << endl;
            return T{};
        }
        return centinela->siguiente->dato; // devuelve el valor del primer elemento
    }

    // Devuelve el último valor sin eliminarlo.
    T Back()
    {
        if (tamano == 0)
        {
            cout << "La lista está vacía, no hay elementos al final." << endl;
            return T{};
        }
        return centinela->anterior->dato; // devuelve el valor del último elemento
    }

    // Revisa si un valor está dentro de la lista.
    bool Contiene(T valor)
    {
        Elemento* encontrado = Buscar(valor);  // busca el valor
        return (encontrado != nullptr);        // devuelve true si lo encontró
    }

    // Devuelve el valor que está en cierta posición (0, 1, 2…)
    T ObtenerPorIndice(size_t indice)
    {
        if (indice >= tamano)  // si el número es mayor al tamaño actual
        {
            cout << "El número de posición no es válido: " << indice << endl;
            return T{};
        }

        Elemento* actual = centinela->siguiente;  // empezamos desde el primer elemento
        for (int i = 0; i < indice; i++)          // avanzamos hasta el lugar indicado
            actual = actual->siguiente;

        return actual->dato;                      // devolvemos el valor encontrado
    }

    // Borra el primer elemento que tenga el valor indicado.
    void BorrarPorValor(T valor)
    {
        Elemento* borrar = Buscar(valor);  // buscamos el valor dentro de la lista
        if (borrar == nullptr)             // si no se encuentra
        {
            cout << "No se encontró el valor: " << valor << endl;
            return;
        }

        EliminarElemento(borrar);          // si se encuentra, se borra
    }

private:
    // Clase que representa cada elemento de la lista.
    class Elemento
    {
    public:
        Elemento(T _dato)
        {
            dato = _dato;          // se guarda el dato dentro del elemento
            siguiente = nullptr;   // al principio no apunta a nadie
            anterior = nullptr;    // tampoco apunta a nadie hacia atrás
        }

        T dato;                 // el valor del elemento
        Elemento* siguiente;    // dirección del siguiente elemento
        Elemento* anterior;     // dirección del anterior elemento
    };

    // Busca un valor dentro de la lista.
    // Si no lo encuentra, devuelve nullptr.
    Elemento* Buscar(T valor)
    {
        Elemento* actual = centinela->siguiente;  // empezamos desde el primer elemento

        while (actual != centinela)               // recorremos la lista
        {
            if (actual->dato == valor)            // si encontramos el valor
                return actual;                    // devolvemos la posición
            actual = actual->siguiente;           // avanzamos al siguiente
        }

        return nullptr;                           // si no lo encontramos
    }

    // Elimina un elemento y reconecta los de alrededor.
    void EliminarElemento(Elemento* borrar)
    {
        borrar->anterior->siguiente = borrar->siguiente; // el de atrás apunta al siguiente
        borrar->siguiente->anterior = borrar->anterior; // el de adelante apunta al de atrás
        delete borrar;                                  // liberamos la memoria del eliminado
        tamano--;                                       // reducimos el tamaño
    }

    Elemento* centinela; // nodo especial que marca el inicio y el final
    int tamano;          // cantidad de elementos que tiene la lista
};

// Declaración de la función de demostración (definida en el .cpp)
void DemostracionSentinelLinkedList();