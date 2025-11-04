// Universidad Cuauhtémoc Querétaro
// Materia: Programación Orientada a Objetos
// Profesor: M. en C. Adrián Ulises González Casillas
// Práctica: Entrega del Parcial – Ejercicios Listas, Doblemente ligadas, Stacks y Queues
// Parte: 2 – LQueue
// Descripción: Este archivo crea una cola (LQueue) usando la lista centinela. Las funciones Enqueue y Dequeue son rápidas.
// Alumnos: Cecilia Romero Granados, Alexis Jeshua Arrona

#pragma once
#include "SentinelLinkedList.h"
#include <iostream>
using namespace std;

template <typename T>
class LQueue {
private:
    SentinelLinkedList<T> data;
public:
    LQueue() {}
    int GetCount() { return data.GetCount(); }
    void Enqueue(T value) { data.Append(value); }
    T Dequeue() { return data.PopFront(); }
    T Front() { return data.Front(); }
};
