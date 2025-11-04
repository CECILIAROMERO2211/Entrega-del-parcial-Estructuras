// Universidad Cuauhtémoc Querétaro
// Materia: Programación Orientada a Objetos
// Profesor: M. en C. Adrián Ulises González Casillas
// Práctica: Entrega del Parcial – Ejercicios Listas, Doblemente ligadas, Stacks y Queues
// Parte: 2 – LQueue
// Descripción: Este archivo cumple el punto 2 del examen. Aquí se crea una "cola", que es una estructura, donde los datos entran por un lado y salen por el otro, como una fila de personas esperando su turno.
// Se usa la lista con centinela para guardar los datos y las funciones Enqueue y Dequeue trabajan de forma rápida.
// Alumnos: Cecilia Romero Granados, Alexis Jeshua Arrona

#pragma once                        // Evita que el archivo se repita al compilar
#include "SentinelLinkedList.h"     // Conecta este archivo con la lista centinela (punto 1)
#include <iostream>                 // Permite usar cout para mostrar mensajes
using namespace std;


template <typename T>// La palabra "template" deja que la cola funcione con distintos tipos de datos 
class LQueue {
private:
    // Aquí se guarda la información usando la lista con centinela que ya creamos
    SentinelLinkedList<T> data;

public:
    // Al crear la cola, empieza vacía
    LQueue() {}

    // Devuelve cuántos datos hay en la cola
    int GetCount() { return data.GetCount(); }

    // Enqueue: mete un dato al final de la cola 
    void Enqueue(T value) {
        data.Append(value);  // Usa la función Append de la lista con centinela
    }


    T Dequeue() {  // Dequeue: saca el primer dato de la cola 
        return data.PopFront();  // Usa la función PopFront de la lista con centinela
    }

    // Front: muestra el primer dato sin quitarlo 
    T Front() {
        return data.Front();  // Devuelve el dato del frente
    }
};
