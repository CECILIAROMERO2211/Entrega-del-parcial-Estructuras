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
#include <iostream>   // Permite usar cout y cin
using namespace std;

// Clase plantilla (genérica) para crear una lista doblemente ligada con un nodo centinela.
// El centinela marca el inicio y el final de la lista, haciendo más fáciles las operaciones.
template <typename T> // La lista puede guardar cualquier tipo de dato (int, string, etc.)
class SentinelLinkedList
{
public:
    // Constructor: se ejecuta al crear la lista.
    // Crea el nodo centinela y lo conecta consigo mismo, por lo tanto la lista inicia vacía.
    SentinelLinkedList()
    {
        centinela = new Elemento(T{});    // Se crea el nodo centinela sin valor útil.
        centinela->siguiente = centinela; // El centinela apunta a sí mismo hacia adelante.
        centinela->anterior = centinela;  // El centinela apunta a sí mismo hacia atrás.
        tamano = 0;                       // La lista inicia vacía.
    }

    // Destructor: se ejecuta al eliminar la lista.
    // Libera la memoria de todos los nodos creados.
    ~SentinelLinkedList()
    {
        Elemento* actual = centinela->siguiente; // Empezamos desde el primer nodo real.
        while (actual != centinela)              // Recorremos hasta volver al centinela.
        {
            Elemento* borrar = actual;           // Guardamos el nodo que se va a eliminar.
            actual = actual->siguiente;          // Avanzamos al siguiente nodo.
            delete borrar;                       // Borramos el nodo actual.
        }

        delete centinela; // Al final eliminamos el nodo centinela.
        cout << "Lista con centinela destruida correctamente." << endl; // Mensaje de confirmación.
    }

    // Agrega un nuevo valor al final de la lista.
    void Append(T valor)
    {
        Elemento* nuevo = new Elemento(valor);      // Se crea un nuevo nodo con el valor dado.

        centinela->anterior->siguiente = nuevo;     // El que era el último nodo apunta al nuevo.
        nuevo->anterior = centinela->anterior;      // El nuevo apunta hacia atrás al anterior último.
        centinela->anterior = nuevo;                // El centinela apunta hacia atrás al nuevo nodo.
        nuevo->siguiente = centinela;               // El nuevo apunta hacia adelante al centinela.

        tamano++;                                   // Aumenta el tamaño de la lista.
    }

    // Quita el último elemento de la lista y devuelve su valor.
    T PopBack()
    {
        if (tamano == 0) // Si la lista está vacía.
        {
            cout << "Error: la lista está vacía, no se puede quitar el último." << endl;
            return T{}; // Devuelve un valor por defecto.
        }

        Elemento* borrar = centinela->anterior; // El último nodo está antes del centinela.
        T valor = borrar->dato;                 // Guardamos su dato antes de borrarlo.

        EliminarElemento(borrar);               // Se borra el nodo.
        return valor;                           // Se devuelve el valor eliminado.
    }

    // Agrega un nuevo valor al inicio de la lista.
    void PushFront(T valor)
    {
        Elemento* nuevo = new Elemento(valor);      // Se crea el nuevo nodo con el valor.

        nuevo->siguiente = centinela->siguiente;    // El nuevo apunta al primer nodo actual.
        centinela->siguiente->anterior = nuevo;     // El antiguo primer nodo apunta hacia atrás al nuevo.
        centinela->siguiente = nuevo;               // El centinela ahora apunta al nuevo.
        nuevo->anterior = centinela;                // El nuevo apunta hacia atrás al centinela.

        tamano++;                                   // Se incrementa el tamaño de la lista.
    }

    // Quita el primer elemento de la lista y devuelve su valor.
    T PopFront()
    {
        if (tamano == 0) // Si la lista está vacía.
        {
            cout << "Error: la lista está vacía, no se puede quitar el primero." << endl;
            return T{}; // Devuelve un valor vacío.
        }

        Elemento* borrar = centinela->siguiente; // El primer nodo está después del centinela.
        T valor = borrar->dato;                  // Guardamos su dato antes de borrarlo.

        EliminarElemento(borrar);                // Se borra el nodo.
        return valor;                            // Se devuelve el valor eliminado.
    }

    // Devuelve el primer valor de la lista sin eliminarlo.
    T Front()
    {
        if (tamano == 0) // Si la lista está vacía.
        {
            cout << "Lista vacía, no hay primer elemento." << endl;
            return T{}; // Devuelve un valor vacío.
        }
        return centinela->siguiente->dato; // Devuelve el dato del primer nodo.
    }

    // Devuelve el último valor de la lista sin eliminarlo.
    T Back()
    {
        if (tamano == 0) // Si la lista está vacía.
        {
            cout << "Lista vacía, no hay último elemento." << endl;
            return T{}; // Devuelve un valor vacío.
        }
        return centinela->anterior->dato; // Devuelve el dato del último nodo.
    }

    // Verifica si un valor está dentro de la lista.
    bool Contiene(T valor)
    {
        Elemento* encontrado = Buscar(valor); // Busca el valor.
        return (encontrado != nullptr);       // Devuelve true si lo encontró, false si no.
    }

    // Devuelve el valor que está en la posición indicada (0, 1, 2…).
    T ObtenerPorIndice(size_t indice)
    {
        if (indice >= tamano) // Si el índice no existe.
        {
            cout << "Índice inválido: " << indice << endl;
            return T{}; // Devuelve valor vacío.
        }

        Elemento* actual = centinela->siguiente; // Empezamos desde el primer nodo.
        for (int i = 0; i < indice; i++)         // Avanzamos hasta llegar al índice.
            actual = actual->siguiente;

        return actual->dato;                     // Devolvemos el valor encontrado.
    }

    // Borra el primer elemento que tenga el valor dado.
    void BorrarPorValor(T valor)
    {
        Elemento* borrar = Buscar(valor); // Buscamos el valor dentro de la lista.
        if (borrar == nullptr)            // Si no se encontró.
        {
            cout << "No se encontró el valor: " << valor << endl;
            return;                       // No hacemos nada más.
        }

        EliminarElemento(borrar);         // Si sí existe, lo borramos.
    }

private:
    // Clase interna que representa cada elemento (nodo) de la lista.
    class Elemento
    {
    public:
        Elemento(T _dato)
        {
            dato = _dato;       // Se guarda el dato dentro del nodo.
            siguiente = nullptr;// Apunta a null hasta conectarse.
            anterior = nullptr; // Igual, hasta conectarse.
        }

        T dato;                 // Valor que guarda este nodo.
        Elemento* siguiente;    // Apunta al siguiente nodo.
        Elemento* anterior;     // Apunta al nodo anterior.
    };

    // Busca un valor dentro de la lista y devuelve el nodo donde está.
    Elemento* Buscar(T valor)
    {
        Elemento* actual = centinela->siguiente; // Empezamos desde el primer nodo real.

        while (actual != centinela)              // Recorremos hasta regresar al centinela.
        {
            if (actual->dato == valor)           // Si encontramos el valor.
                return actual;                   // Devolvemos el nodo.
            actual = actual->siguiente;          // Avanzamos al siguiente.
        }

        return nullptr;                          // Si no se encontró, devolvemos nullptr.
    }

    // Borra un nodo de la lista y ajusta los punteros de los vecinos.
    void EliminarElemento(Elemento* borrar)
    {
        borrar->anterior->siguiente = borrar->siguiente; // El anterior ahora apunta al siguiente.
        borrar->siguiente->anterior = borrar->anterior; // El siguiente ahora apunta al anterior.
        delete borrar;                                  // Se elimina el nodo de memoria.
        tamano--;                                       // Se reduce el tamaño de la lista.
    }

    Elemento* centinela; // Nodo centinela que marca inicio y final de la lista.
    int tamano;          // Número total de elementos en la lista.
};

// Declaración de la función de demostración (definida en el .cpp).
void DemostracionSentinelLinkedList();
