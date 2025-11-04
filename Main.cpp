// Universidad Cuauhtémoc Querétaro
// Materia: Programación Orientada a Objetos
// Profesor: M. en C. Adrián Ulises González Casillas
// Práctica: Entrega del Parcial – Ejercicios Listas, Doblemente ligadas, Stacks y Queues
// Parte: General – Main
// Descripción: En este archivo se prueban todas las partes del proyecto.
// Se muestra cómo funciona la lista con centinela, la cola, la pila y las figuras.
// Alumnos: Cecilia Romero Granados, Alexis Jeshua Arrona

#include <iostream>              // Permite mostrar mensajes en pantalla
#include "SentinelLinkedList.h"  // Archivo de la lista con centinela
#include "LQueue.h"              // Archivo de la cola
#include "LStack.h"              // Archivo de la pila
#include "Figura.h"              // Archivo de las figuras geométricas
using namespace std;


int main() { // La función principal, donde se ejecuta todo el programa.
    cout << "ENTREGA PARCIAL 2 - ESTRUCTURAS DINAMICAS" << endl;
    cout << "Alumnos: Cecilia Romero Granados, Alexis Jeshua Arrona" << endl << endl;

   
  
    // PRUEBA DE LA LISTA CON CENTINELA
    SentinelLinkedList<int> lista;   // Se crea una lista que guarda números
    lista.Append(10);                // Se agrega un número al final
    lista.Append(20);                // Se agrega otro número al final
    lista.PushFront(5);              // Se agrega un número al inicio

    cout << "Lista - Elementos actuales: " << lista.GetCount() << endl; // Muestra cuántos datos tiene la lista
    cout << "PopFront: " << lista.PopFront()   // Saca el primer dato y lo muestra
         << " | PopBack: " << lista.PopBack()  // Saca el último dato y lo muestra
         << endl;

  
    
   // PRUEBA DE LA COLA 
    LQueue<string> cola;             // Se crea una cola que guarda palabras
    cola.Enqueue("Cecilia");         // Se agrega un nombre al final
    cola.Enqueue("Andrea");          // Se agrega otro nombre
    cout << "Cola - Frente: " << cola.Front()  // Muestra quién está al frente
         << " | Dequeue: " << cola.Dequeue()   // Quita al primero de la cola
         << endl;

    // ------------------------------
    // PRUEBA DE LA PILA (LStack)
    // ------------------------------
    LStack<int> pila;                // Se crea una pila que guarda números
    pila.Push(10);                   // Se agrega un número
    pila.Push(20);                   // Se agrega otro número encima del anterior
    cout << "Pila - Tope: " << pila.Peek()     // Muestra el número de arriba
         << " | Pop: " << pila.Pop()           // Quita el número de arriba
         << endl;

   
   
    // PRUEBA DE LAS FIGURAS
    float segmentos[] = {2.5, 3.0, 4.5};   // Cada número representa una parte de una línea

    // Se crean distintas figuras geométricas
    Figura* f1 = new Circulo(5);           // Un círculo con radio 5
    Figura* f2 = new Cuadrado(4);          // Un cuadrado con lado 4
    Figura* f3 = new FiguraNLados(5, 3);   // Una figura de 5 lados, cada uno mide 3
    Figura* f4 = new Linea(segmentos, 3);  // Una línea formada por 3 segmentos
    Cubo c(2.5);                           // Un cubo donde cada lado mide 2.5

   
    cout << endl << "Figuras:" << endl; // Se muestran los resultados de cada figura
    cout << f1->ObtenerNombreDeFigura() << " - Area: " << f1->CalcularArea() << endl;
    cout << f2->ObtenerNombreDeFigura() << " - Perimetro: " << f2->CalcularPerimetro() << endl;
    cout << f3->ObtenerNombreDeFigura() << " - Area: " << f3->CalcularArea() << endl;
    cout << "Cubo - Volumen: " << c.Volumen() << " | Superficie: " << c.Surface() << endl;
    cout << f4->ObtenerNombreDeFigura() << " - Longitud total: " << f4->CalcularPerimetro() << endl;

    // Se borra la memoria usada por las figuras
    delete f1;
    delete f2;
    delete f3;
    delete f4;

    cout << endl << "Ejecucion finalizada correctamente." << endl;
}

