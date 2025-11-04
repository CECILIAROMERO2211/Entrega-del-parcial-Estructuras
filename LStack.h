// Universidad Cuauhtémoc Querétaro
// Materia: Programación Orientada a Objetos
// Profesor: M. en C. Adrián Ulises González Casillas
// Práctica: Entrega del Parcial – Ejercicios Listas, Doblemente ligadas, Stacks y Queues
// Parte: 3 – LStack
// Descripción: Este archivo cumple el punto 3 de la práctica. Aquí se crea una "pila", que es una estructura donde, los datos se guardan uno encima de otro, como una torre. Solo se puede agregar o quitar desde arriba.
// Alumnos: Cecilia Romero Granados, Alexis Jeshua Arrona

#pragma once               // Evita que el archivo se repita al compilar
#include <forward_list>    // Permite usar listas sencillas 
#include <iostream>        // Permite mostrar mensajes en pantalla
using namespace std;


template <typename T>// La palabra "template" permite usar la pila con diferentes tipos de datos
class LStack {
private:
    forward_list<T> elements; // Aquí se guardan los datos, uno encima del otro
    int count;                // Cuenta cuántos datos hay en la pila

public:
  
    LStack() : count(0) {}// Cuando se crea la pila, empieza vacía

    // Agrega un dato nuevo "encima" de la pila
    // Es como poner un plato más sobre una torre
    void Push(T value) {
        elements.push_front(value); // Coloca el nuevo valor arriba de todo
        count++;                    // Aumenta el número de elementos
    }

  

    T Pop() {  // Quita el dato que está arriba de la pila y lo devuelve
        if (count == 0) { // Si no hay datos en la pila
            cout << "Error: la pila está vacía." << endl;
            return T{};   // Devuelve un valor vacío (por ejemplo, 0 o "")
        }
        T topValue = elements.front(); // Guarda el valor de arriba
        elements.pop_front();          // Quita el elemento de arriba
        count--;                       // Resta uno a la cantidad total
        return topValue;               // Devuelve el valor que se quitó
    }

   
    
    T Peek() {// Muestra cuál es el dato que está arriba sin quitarlo
        if (count == 0) { // Si la pila está vacía
            cout << "Error: la pila está vacía." << endl;
            return T{};   // Devuelve un valor vacío
        }
        return elements.front(); // Devuelve el valor de arriba
    }

    // Devuelve cuántos datos hay en la pila
    int GetCount() { return count; }
};
