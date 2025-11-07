// Universidad Cuauhtémoc Querétaro
// Materia: Programación Orientada a Objetos
// Profesor: M. en C. Adrián Ulises González Casillas
// Práctica: Entrega del Parcial – Ejercicios Listas, Doblemente ligadas, Stacks y Queues
// Parte: General – Main
// Descripción: En este archivo se prueban todas las partes del proyecto.
// Se muestra cómo funciona la lista con centinela, la cola, la pila y las figuras.
// Alumnos: Cecilia Romero Granados, Alexis Jeshua Arrona

#include <iostream>    // Sirve para mostrar cosas en pantalla con cout
#include "Figura.h"    // Aquí están todas las clases de las figuras
using namespace std;   // Para no tener que escribir std::cout cada vez

int main() // Aquí empieza el programa
{
    cout << "PRUEBA DE FIGURAS GEOMETRICAS (UCQ)" << endl << endl; // Título del programa

    // CIRCULO
    cout << "CIRCULO" << endl;          // Mostramos qué figura vamos a probar
    Circulo c(5);                       // Creamos un círculo con radio 5
    cout << "Area del circulo: " << c.CalcularArea() << endl;           // Calcula e imprime el área del círculo
    cout << "Perimetro del circulo: " << c.CalcularPerimetro() << endl; // Calcula e imprime el perímetro del círculo
    cout << endl;                       // Solo para dejar un espacio

    // CUADRADO
    cout << "CUADRADO" << endl;         // Indicamos que ahora probamos un cuadrado
    Cuadrado cuad(4);                   // Creamos un cuadrado con lado 4
    cout << "Area del cuadrado: " << cuad.CalcularArea() << endl;           // Calcula e imprime el área del cuadrado
    cout << "Perimetro del cuadrado: " << cuad.CalcularPerimetro() << endl; // Calcula e imprime el perímetro del cuadrado
    cout << endl;                       // Espacio para separar

    // CUBO
    cout << "CUBO" << endl;             // Probamos el cubo
    Cubo cub(3);                        // Creamos un cubo con lado 3
    cout << "Area del cubo: " << cub.CalcularArea() << endl;                 // Calcula el área total del cubo (todas sus caras)
    cout << "Perimetro del cubo (suma de aristas): " << cub.CalcularPerimetro() << endl; // Suma de todas las orillas del cubo
    cout << "Volumen del cubo: " << cub.Volumen() << endl;                  // Calcula el volumen del cubo
    cout << endl;                       // Deja un espacio

    // FIGURA DE N LADOS (caso normal)
    cout << "FIGURA DE N LADOS" << endl;       // Probamos una figura con varios lados iguales
    FiguraNLados figura1(6, 5);                // Creamos una figura con 6 lados de tamaño 5 (un hexágono)
    cout << "Area de la figura: " << figura1.CalcularArea() << endl;         // Muestra el área
    cout << "Perimetro de la figura: " << figura1.CalcularPerimetro() << endl; // Muestra el perímetro
    cout << endl;                       // Deja un espacio

    // FIGURA DE N LADOS (valores inválidos)
    cout << "FIGURA DE N LADOS (CON VALORES INVALIDOS)" << endl; // Probamos con datos incorrectos
    FiguraNLados figura2(0, -3); // Le damos 0 lados y un lado negativo (el programa lo corrige solo)
    cout << "Area de la figura corregida: " << figura2.CalcularArea() << endl;       // Muestra el área ya corregida
    cout << "Perimetro de la figura corregida: " << figura2.CalcularPerimetro() << endl; // Muestra el perímetro corregido
    cout << endl;                       // Deja un espacio

    // LINEA (caso normal)
    cout << "LINEA" << endl;            // Probamos la figura línea
    float segmentos1[] = { 2.5f, 3.0f, 4.5f }; // Arreglo con 3 segmentos 
    Linea linea1(segmentos1, 3);        // Creamos una línea con esos 3 segmentos
    cout << "Perimetro (longitud total) de la linea: " << linea1.CalcularPerimetro() << endl; // Suma los segmentos
    cout << "Area de la linea: " << linea1.CalcularArea() << endl; // Siempre será 0 porque una línea no tiene área
    cout << endl;                       // Deja un espacio

    // LINEA (valores inválidos)
    cout << "LINEA (CON VALORES INVALIDOS)" << endl; // Probamos con segmentos negativos
    float segmentos2[] = { -2.0f, 0.0f, 1.5f }; // Uno negativo y uno cero (se corrigen automáticamente)
    Linea linea2(segmentos2, -5); // Le damos un número negativo de segmentos, también se corrige
    cout << "Perimetro corregido de la linea: " << linea2.CalcularPerimetro() << endl; // Muestra la suma corregida
    cout << "Area de la linea (siempre 0): " << linea2.CalcularArea() << endl; // Siempre 0
    cout << endl;                       // Espacio final

    cout << "FIN DE LAS PRUEBAS DE FIGURAS" << endl; // Mensaje final del programa

    return 0; // Fin del programa, todo salió bien
}
