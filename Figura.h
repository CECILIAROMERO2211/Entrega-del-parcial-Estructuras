// Universidad Cuauhtémoc Querétaro
// Materia: Programación Orientada a Objetos
// Profesor: M. en C. Adrián Ulises González Casillas
// Práctica: Entrega del Parcial – Ejercicios Listas, Doblemente ligadas, Stacks y Queues
// Parte: 4 – Figuras
// Descripción: Este archivo cumple el punto 4 del examen. Aquí se crean varias figuras geométricas, como el círculo, el cuadrado, el cubo, una figura con N lados y una línea.
// Se usa herencia para que todas las figuras compartan una base común llamada Figura y cada una calcula su área o perímetro a su manera.
// Alumnos: Cecilia Romero Granados, Alexis Jeshua Arrona

#pragma once
#include <iostream>  // Sirve para mostrar mensajes en consola
#include <cmath>     // Sirve para usar funciones matemáticas como tan() o PI
using namespace std;

// CLASE BASE: FIGURA
// Esta clase es el modelo general. Todas las figuras
// heredan de aquí, porque todas comparten las funciones CalcularArea y CalcularPerimetro.
class Figura {
public:
    Figura(string n) : nombre(n) {} // Guarda el nombre de la figura
    virtual ~Figura() {}            // Destructor virtual (necesario para herencia)

    // Estas funciones son "virtuales puras", eso significa que
    // las clases hijas están obligadas a implementar su propia versión.
    virtual float CalcularArea() = 0;
    virtual float CalcularPerimetro() = 0;

    // Devuelve el nombre de la figura (por ejemplo “Círculo” o “Cubo”)
    const string& ObtenerNombreDeFigura() { return nombre; }

protected:
    string nombre; // Se guarda el nombre aquí
};

// CLASE CIRCULO
// Representa un círculo con su radio.
class Circulo : public Figura {
private:
    float radio; // guarda el valor del radio
public:
    Circulo(float r) : Figura("Círculo"), radio(r) {} // se guarda el radio

    // CalcularArea
    // Fórmula del área de un círculo
    float CalcularArea() override { 
        return 3.1416f * radio * radio; // multiplica PI * radio * radio
    }

    // CalcularPerimetro
    // Fórmula del perímetro: 2 * PI * radio
    float CalcularPerimetro() override { 
        return 2 * 3.1416f * radio; // multiplica 2 * PI * radio
    }
};


// CLASE CUADRADO
// Representa un cuadrado donde todos los lados son iguales.
class Cuadrado : public Figura {
protected:
    float lado; // mide cuánto vale un lado
public:
    Cuadrado(float l) : Figura("Cuadrado"), lado(l) {} // se guarda el lado

    // CalcularArea
    // Fórmula: lado * lado
    float CalcularArea() override { 
        return lado * lado; // multiplica el lado por sí mismo
    }

    // CalcularPerimetro
    // Fórmula: 4 * lado
    float CalcularPerimetro() override { 
        return 4 * lado; // multiplica el lado por 4 (4 lados iguales)
    }
};

// CLASE CUBO (hereda de Cuadrado
// Representa un cubo en 3D, o sea un cuadrado con volumen.
class Cubo : public Cuadrado {
public:
    Cubo(float l) : Cuadrado(l) {} // el lado se pasa al constructor del cuadrado

    // Volumen, Calcula el volumen del cubo usando la fórmula: lado³
    float Volumen() { 
        return lado * lado * lado; // multiplica el lado 3 veces
    }

    // CalcularArea
    // Calcula el área total de un cubo (6 caras iguales)
    float CalcularArea() override { 
        return 6 * lado * lado; // multiplica 6 * lado² (cada cara tiene área lado²)
    }

    // CalcularPerimetro
    // Calcula el perímetro total (suma de las 12 aristas del cubo)
    float CalcularPerimetro() override { 
        return 12 * lado; // multiplica el lado por 12 (porque un cubo tiene 12 aristas)
    }
};

// CLASE FIGURA DE N LADOS
// Representa una figura regular 
class FiguraNLados : public Figura {
private:
    int n;      // número de lados
    float lado; // longitud de cada lado
public:
    // Constructor 
    FiguraNLados(int _n, float _l) : Figura("Figura de N lados"), n(_n), lado(_l)
    {
        // Si la figura tiene menos de 3 lados, no puede existir
        if (n < 3)
        {
            cout << "Advertencia: una figura necesita al menos 3 lados. Se ajustará a 3." << endl;
            n = 3; // se cambia a 3 para evitar errores
        }

        // Si el valor del lado es 0 o negativo, no tiene sentido
        if (lado <= 0)
        {
            cout << "Advertencia: el lado debe ser positivo. Se ajustará a 1." << endl;
            lado = 1; // se corrige el valor del lado
        }
    }

    // CalcularArea
    // Fórmula general del área de un polígono regular
    float CalcularArea() override {
        return (n * lado * lado) / (4 * tan(3.1416f / n)); // se aplica la fórmula general
    }

    // CalcularPerimetro
    // Suma todos los lados: n * lado
    float CalcularPerimetro() override { 
        return n * lado; // multiplica el número de lados por la longitud de uno
    }
};


// CLASE LINEA
// Representa una línea formada por varios segmentos unidos.
class Linea : public Figura {
private:
    float* segmentos; // arreglo para guardar las longitudes de cada segmento
    int size;         // cuántos segmentos hay
public:
    // Constructor 
    Linea(float* arr, int n) : Figura("Línea"), size(n)
    {
        // Validamos que tenga al menos un segmento
        if (size <= 0)
        {
            cout << "Advertencia: la línea necesita al menos un segmento. Se creará una de 1 unidad." << endl;
            size = 1; // se fuerza a tener un segmento
            segmentos = new float[1]; // reservamos memoria para un solo segmento
            segmentos[0] = 1.0f; // ese segmento mide 1 unidad
            return; // salimos del constructor
        }

        // Reservamos memoria para los segmentos
        segmentos = new float[size];

        // Copiamos cada valor recibido
        for (int i = 0; i < size; i++)
        {
            // Si algún segmento tiene un valor negativo o cero, se corrige
            if (arr[i] <= 0)
            {
                cout << "Advertencia: segmento negativo o nulo, se ajustará a 1." << endl;
                segmentos[i] = 1.0f; // lo reemplazamos por 1
            }
            else
            {
                segmentos[i] = arr[i]; // copiamos el valor normal
            }
        }
    }

    // Destructor 
    // Libera la memoria que se usó para guardar los segmentos.
    ~Linea() { 
        delete[] segmentos; // borra el arreglo dinámico
    }

    // CalcularArea 
    // Una línea no tiene área (es 1D), así que devuelve 0.
    float CalcularArea() override { 
        return 0; 
    }

    // CalcularPerimetro
    // Suma todos los segmentos para obtener la longitud total.
    float CalcularPerimetro() override {
        float total = 0; // variable para acumular la suma
        for (int i = 0; i < size; i++)
            total += segmentos[i]; // se suma cada segmento uno por uno
        return total; // devuelve la longitud total de la línea
    }
};

