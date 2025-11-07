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

// Clase plantilla de lista doblemente ligada con nodo centinela (NIL).
// El nodo NIL no guarda un dato "real"; sirve como marcador de inicio/fin.
// Ventaja: evita if's especiales para "lista vacía", "primer/último", etc.
// Tiempo de varias operaciones como Append/PushFront es O(1).
template <typename T>
class SentinelLinkedList
{
public:
    // Constructor: crea el nodo NIL y lo hace apuntarse a sí mismo.
    // La lista queda vacía porque NIL->next == NIL y NIL->prev == NIL.
    SentinelLinkedList()
    {
        NIL = new Node(T{}); // crea NIL con valor por defecto de T (no importa su contenido)
        NIL->next = NIL;     // hacia adelante apunta a sí mismo: lista vacía
        NIL->prev = NIL;     // hacia atrás también se autoapunta
        count = 0;           // no hay elementos "reales" aún
    }

    // Destructor: libera todos los nodos reales y al final libera también a NIL.
    ~SentinelLinkedList()
    {
        // Empezamos desde el primer nodo real (NIL->next).
        Node* nodoActual = NIL->next;
        // Recorremos hasta volver a NIL (momento en que no quedan reales).
        while (nodoActual != NIL)
        {
            Node* nodoABorrar = nodoActual; // guardamos el que vamos a eliminar
            nodoActual = nodoActual->next;  // avanzamos ANTES de borrar para no perder el enlace
            delete nodoABorrar;             // liberamos memoria del nodo real
        }

        delete NIL; // por último liberamos el centinela
        cout << "Sentinel linked list destruida con éxito" << endl;
    }

    // Append: inserta al FINAL en O(1) usando NIL->prev como "último actual".
    void Append(T value)
    {
        Node* newNode = new Node(value); // se crea el nuevo nodo con el valor

        // Conexiones (en orden lógico):
        // 1) El antiguo último (NIL->prev) ahora apunta hacia adelante al nuevo
        NIL->prev->next = newNode;

        // 2) El nuevo apunta hacia atrás al antiguo último
        newNode->prev = NIL->prev;

        // 3) Actualizamos "último": NIL->prev ahora debe ser el nuevo
        NIL->prev = newNode;

        // 4) El nuevo hacia adelante apunta a NIL (porque es el último)
        newNode->next = NIL;

        // 5) Aumentamos el conteo
        count++;
    }

    // PopBack: quita el ÚLTIMO y regresa su valor.
    T PopBack()
    {
        // Si no hay elementos reales, no se puede extraer.
        if (count == 0)
        {
            cout << "Error, trataron de hacer PopBack de una lista vacía." << endl;
            return T{}; // valor neutro de T
        }

        // El último real es NIL->prev.
        Node* nodoABorrar = NIL->prev;
        T valorDelNodoABorrar = nodoABorrar->data; // guardamos su dato para regresarlo

        // Reutilizamos la función de borrado (reconecta punteros y decrementa count).
        Delete(nodoABorrar);

        return valorDelNodoABorrar; // devolvemos el dato que tenía
    }

    // Front: regresa el valor del PRIMERO sin quitarlo.
    T Front()
    {
        if (count == 0)
        {
            cout << "Error, trataron de sacar el front de una lista vacía." << endl;
            return T{};
        }
        // El primero real siempre es NIL->next.
        return NIL->next->data;
    }

    // Back: regresa el valor del ÚLTIMO sin quitarlo.
    T Back()
    {
        if (count == 0)
        {
            cout << "Error, trataron de sacar el Back de una lista vacía." << endl;
            return T{};
        }
        // El último real siempre es NIL->prev.
        return NIL->prev->data;
    }

    // Contains: busca el primer nodo con "value". True si lo encuentra.
    bool Contains(T value)
    {
        Node* nodoEncontrado = Search(value); // recorre desde NIL->next hasta NIL
        // Si regresa nullptr, NO está; en otro caso, SÍ está.
        if (nodoEncontrado == nullptr)
            return false;
        return true;
        // (equivalente) return nodoEncontrado != nullptr;
    }

    // ObtenerValorPorIndice: regresa el dato en la posición [0..count-1] desde el inicio.
    T ObtenerValorPorIndice(size_t indice)
    {
        // Validación: índice fuera de rango.
        if (indice >= count)
        {
            cout << "Error, trataron de acceder a un índice inválido:" << indice << endl;
            return T{};
        }

        // Recorremos "indice" pasos a partir del primero.
        Node* nodoActual = NIL->next;
        for (int i = 0; i < indice; i++)
            nodoActual = nodoActual->next;

        return nodoActual->data;
    }
