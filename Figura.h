// Universidad Cuauhtémoc Querétaro
// Materia: Programación Orientada a Objetos
// Profesor: M. en C. Adrián Ulises González Casillas
// Práctica: Entrega del Parcial – Ejercicios Listas, Doblemente ligadas, Stacks y Queues
// Parte: 4 – Figuras
// Descripción: Este archivo cumple el punto 4 del examen. Aquí se crean varias figuras geométricas, como el círculo, el cuadrado, el cubo, una figura con N lados y una línea.
// Se usa herencia para que todas las figuras compartan una base común llamada Figura y cada una calcula su área o perímetro a su manera.
// Alumnos: Cecilia Romero Granados, Alexis Jeshua Arrona

#pragma once
#include <iostream>  // Permite mostrar mensajes o usar strings
#include <cmath>     // Permite usar funciones matemáticas como tan() y PI
using namespace std;

// CLASE BASE: FIGURA
// Esta clase es la base de todas las figuras.
// Sirve como modelo general para que las demás figuras hereden sus funciones.
class Figura {
public:
    // Se crea la figura con un nombre 
    Figura(string n) : nombre(n) {}

    // Destructor virtual: se llama automáticamente al borrar una figura
    virtual ~Figura() {}

  // Estas funciones se dejan vacías aquí, porque cada tipo de figura, tiene su propia forma de calcular el área y el perímetro.
    virtual float CalcularArea() = 0;
    virtual float CalcularPerimetro() = 0;

    // Devuelve el nombre de la figura y esta sirve para identificarla
    const string& ObtenerNombreDeFigura() { return nombre; }

protected:
    string nombre; // Aquí se guarda el nombre de la figura
};

// CLASE HIJA: CÍRCULO
// Representa un círculo con un radio.
class Circulo : public Figura {
private:
    float radio; // El tamaño del radio
public:
    Circulo(float r) : Figura("Círculo"), radio(r) {}

    // Fórmula del área: PI * radio²
    float CalcularArea() override { return 3.1416f * radio * radio; }

    // Fórmula del perímetro (circunferencia): 2 * PI * radio
    float CalcularPerimetro() override { return 2 * 3.1416f * radio; }
};

// CLASE HIJA: CUADRADO
// Representa un cuadrado regular con todos sus lados iguales.
class Cuadrado : public Figura {
protected:
    float lado; // Tamaño de un lado del cuadrado
public:
    Cuadrado(float l) : Figura("Cuadrado"), lado(l) {}

    // Área = lado * lado
    float CalcularArea() override { return lado * lado; }

    // Perímetro = 4 * lado
    float CalcularPerimetro() override { return 4 * lado; }
};

// CLASE HIJA DE CUADRADO: CUBO
// Representa un cubo. Hereda del cuadrado.
class Cubo : public Cuadrado {
public:
    Cubo(float l) : Cuadrado(l) {}

    // Volumen del cubo = lado³
    float Volumen() { return lado * lado * lado; }

    // Superficie total = 6 * lado²
    float Surface() { return 6 * lado * lado; }
};

// CLASE HIJA: FIGURA DE N LADOS
// Representa una figura con varios lados iguales. 
class FiguraNLados : public Figura {
private:
    int n;      // Número de lados
    float lado; // Longitud de cada lado
public:
    FiguraNLados(int _n, float _l) : Figura("FiguraNLados"), n(_n), lado(_l) {}

    // Área aproximada usando una fórmula general para figuras regulares
    float CalcularArea() override {
        return (n * lado * lado) / (4 * tan(3.1416f / n));
    }

    // Perímetro = n * lado
    float CalcularPerimetro() override { return n * lado; }
};


// CLASE HIJA: LÍNEA
// Representa una línea compuesta por varias partes que pueden medir diferente.
class Linea : public Figura {
private:
    float* segmentos; // Arreglo para guardar cada segmento
    int size;         // Cuántos segmentos tiene
public:
    // Se crea la línea copiando los segmentos dados
    Linea(float* arr, int n) : Figura("Línea"), size(n) {
        segmentos = new float[n]; // Se reserva espacio en memoria
        for (int i = 0; i < n; i++) segmentos[i] = arr[i]; // Se copian los valores
    }

    // Cuando la línea se borra, se libera la memoria usada
    ~Linea() { delete[] segmentos; }

    // Una línea no tiene área, así que su resultado siempre es 0
    float CalcularArea() override { return 0; }

    // El perímetro es la suma de todos los segmentos
    float CalcularPerimetro() override {
        float total = 0;
        for (int i = 0; i < size; i++) total += segmentos[i];
        return total;
    }
};

