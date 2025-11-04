// Universidad Cuauhtémoc Querétaro
// Materia: Programación Orientada a Objetos
// Profesor: M. en C. Adrián Ulises González Casillas
// Práctica: Entrega del Parcial – Ejercicios Listas, Doblemente ligadas, Stacks y Queues
// Parte: General – Main
// Descripción: Aquí se prueban todas las partes: lista, cola, pila y figuras.
// Alumnos: Cecilia Romero Granados, Alexis Jeshua Arrona

#include <iostream>
#include "SentinelLinkedList.h"
#include "LQueue.h"
#include "LStack.h"
#include "Figura.h"
using namespace std;

int main() {
    cout << "ENTREGA PARCIAL 2 - ESTRUCTURAS DINAMICAS" << endl;
    cout << "Alumnos: Cecilia Romero Granados, Alexis Jeshua Arrona" << endl << endl;

    SentinelLinkedList<int> lista;
    lista.Append(10);
    lista.Append(20);
    lista.PushFront(5);
    cout << "Lista - Elementos actuales: " << lista.GetCount() << endl;
    cout << "PopFront: " << lista.PopFront() << " | PopBack: " << lista.PopBack() << endl;

    LQueue<string> cola;
    cola.Enqueue("Cecilia");
    cola.Enqueue("Andrea");
    cout << "Cola - Frente: " << cola.Front() << " | Dequeue: " << cola.Dequeue() << endl;

    LStack<int> pila;
    pila.Push(10);
    pila.Push(20);
    cout << "Pila - Tope: " << pila.Peek() << " | Pop: " << pila.Pop() << endl;

    float segmentos[] = {2.5, 3.0, 4.5};
    Figura* f1 = new Circulo(5);
    Figura* f2 = new Cuadrado(4);
    Figura* f3 = new FiguraNLados(5, 3);
    Figura* f4 = new Linea(segmentos, 3);
    Cubo c(2.5);

    cout << "Figuras:" << endl;
    cout << f1->ObtenerNombreDeFigura() << " - Area: " << f1->CalcularArea() << endl;
    cout << f2->ObtenerNombreDeFigura() << " - Perimetro: " << f2->CalcularPerimetro() << endl;
    cout << f3->ObtenerNombreDeFigura() << " - Area: " << f3->CalcularArea() << endl;
    cout << "Cubo - Volumen: " << c.Volumen() << " | Superficie: " << c.Surface() << endl;
    cout << f4->ObtenerNombreDeFigura() << " - Longitud total: " << f4->CalcularPerimetro() << endl;

    delete f1; delete f2; delete f3; delete f4;
    cout << endl << "Ejecucion finalizada correctamente." << endl;
}
