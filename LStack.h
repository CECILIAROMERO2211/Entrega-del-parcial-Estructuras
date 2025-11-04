// Universidad Cuauhtémoc Querétaro
// Materia: Programación Orientada a Objetos
// Profesor: M. en C. Adrián Ulises González Casillas
// Práctica: Entrega del Parcial – Ejercicios Listas, Doblemente ligadas, Stacks y Queues
// Parte: 3 – LStack
// Descripción: Aquí se hace una pila con forward_list. Se pueden agregar y quitar datos de forma rápida.
// Alumnos: Cecilia Romero Granados, Alexis Jeshua Arrona

#pragma once
#include <forward_list>
#include <iostream>
using namespace std;

template <typename T>
class LStack {
private:
    forward_list<T> elements;
    int count;
public:
    LStack() : count(0) {}
    void Push(T value) { elements.push_front(value); count++; }
    T Pop() {
        if (count == 0) { cout << "Error: la pila está vacía." << endl; return T{}; }
        T topValue = elements.front();
        elements.pop_front();
        count--;
        return topValue;
    }
    T Peek() {
        if (count == 0) { cout << "Error: la pila está vacía." << endl; return T{}; }
        return elements.front();
    }
    int GetCount() { return count; }
};
