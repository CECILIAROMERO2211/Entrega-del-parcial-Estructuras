// Universidad Cuauhtémoc Querétaro
// Materia: Programación Orientada a Objetos
// Profesor: M. en C. Adrián Ulises González Casillas
// Práctica: Entrega del Parcial – Ejercicios Listas, Doblemente ligadas, Stacks y Queues
// Parte: 4 – Figuras
// Descripción: Contiene las clases de figuras como círculo, cuadrado, cubo, figura de N lados y línea. Usa herencia y polimorfismo.
// Alumnos: Cecilia Romero Granados, Alexis Jeshua Arrona

#pragma once
#include <iostream>
#include <cmath>
using namespace std;

class Figura {
public:
    Figura(string n) : nombre(n) {}
    virtual ~Figura() {}
    virtual float CalcularArea() = 0;
    virtual float CalcularPerimetro() = 0;
    const string& ObtenerNombreDeFigura() { return nombre; }
protected:
    string nombre;
};

class Circulo : public Figura {
private:
    float radio;
public:
    Circulo(float r) : Figura("Círculo"), radio(r) {}
    float CalcularArea() override { return 3.1416f * radio * radio; }
    float CalcularPerimetro() override { return 2 * 3.1416f * radio; }
};

class Cuadrado : public Figura {
protected:
    float lado;
public:
    Cuadrado(float l) : Figura("Cuadrado"), lado(l) {}
    float CalcularArea() override { return lado * lado; }
    float CalcularPerimetro() override { return 4 * lado; }
};

class Cubo : public Cuadrado {
public:
    Cubo(float l) : Cuadrado(l) {}
    float Volumen() { return lado * lado * lado; }
    float Surface() { return 6 * lado * lado; }
};

class FiguraNLados : public Figura {
private:
    int n;
    float lado;
public:
    FiguraNLados(int _n, float _l) : Figura("FiguraNLados"), n(_n), lado(_l) {}
    float CalcularArea() override { return (n * lado * lado) / (4 * tan(3.1416f / n)); }
    float CalcularPerimetro() override { return n * lado; }
};

class Linea : public Figura {
private:
    float* segmentos;
    int size;
public:
    Linea(float* arr, int n) : Figura("Línea"), size(n) {
        segmentos = new float[n];
        for (int i = 0; i < n; i++) segmentos[i] = arr[i];
    }
    ~Linea() { delete[] segmentos; }
    float CalcularArea() override { return 0; }
    float CalcularPerimetro() override {
        float total = 0;
        for (int i = 0; i < size; i++) total += segmentos[i];
        return total;
    }
};
