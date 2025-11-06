// Universidad Cuauhtémoc Querétaro
// Materia: Programación Orientada a Objetos
// Profesor: M. en C. Adrián Ulises González Casillas
// Práctica: Entrega del Parcial – Ejercicios Listas, Doblemente ligadas, Stacks y Queues
// Parte: 1 – SentinelLinkedList.cpp
// Descripción: Este archivo está aquí para acompañar a "SentinelLinkedList.h". 
// No tiene código porque toda la lógica ya está escrita en el otro archivo.
// Se deja solo para mantener el proyecto completo y organizado, tal como se pidió en la práctica.
// Alumnos: Cecilia Romero Granados, Alexis Jeshua Arrona

#include "SentinelLinkedList.h"

// Esta función sirve para probar el funcionamiento de la lista con centinela.
// Se agregan, eliminan y muestran elementos para comprobar que todo funcione bien.
void DemostracionSentinelLinkedList()
{
    // Se crea una lista vacía de tipo string
    SentinelLinkedList<string> lista;

    cout << "Agregando nombres al final de la lista..." << endl;
    lista.Append("Juan");   // agrega "Juan" al final
    lista.Append("Maria");  // agrega "Maria" al final
    lista.Append("Pedro");  // agrega "Pedro" al final

    // Mostramos el primer y último elemento
    cout << "Primer elemento: " << lista.Front() << endl;
    cout << "Último elemento: " << lista.Back() << endl;

    // Buscamos si un nombre existe dentro de la lista
    cout << "¿La lista contiene 'Maria'? ";
    cout << (lista.Contiene("Maria") ? "Sí, está en la lista." : "No, no está.") << endl;

    cout << "¿La lista contiene 'Luis'? ";
    cout << (lista.Contiene("Luis") ? "Sí, está en la lista." : "No, no está.") << endl;

    // Agregamos elementos al inicio de la lista
    cout << "Agregando nombres al principio..." << endl;
    lista.PushFront("Ana");     // se agrega "Ana" al inicio
    lista.PushFront("Carlos");  // se agrega "Carlos" al inicio

    // Mostramos el nuevo primer elemento
    cout << "El primer elemento ahora es: " << lista.Front() << endl;

    // Quitamos el primer elemento y mostramos el resultado
    cout << "Quitando el primer elemento..." << endl;
    cout << "Elemento eliminado: " << lista.PopFront() << endl;
    cout << "El nuevo primer elemento es: " << lista.Front() << endl;

    // Quitamos el último elemento y mostramos el resultado
    cout << "Quitando el último elemento..." << endl;
    cout << "Elemento eliminado: " << lista.PopBack() << endl;
    cout << "El nuevo último elemento es: " << lista.Back() << endl;

    // Eliminamos un nombre específico de la lista
    cout << "Eliminando el nombre 'Maria'..." << endl;
    lista.BorrarPorValor("Maria");

    // Probamos obtener elementos por posición
    cout << "Buscando elementos por posición..." << endl;
    cout << "Elemento en la posición 0: " << lista.ObtenerPorIndice(0) << endl;
    lista.ObtenerPorIndice(5); // este índice no existe, mostrará un mensaje de error

    // Vaciamos completamente la lista
    cout << "Eliminando todos los elementos restantes..." << endl;
    cout << "Eliminado: " << lista.PopBack() << endl;
    cout << "Eliminado: " << lista.PopBack() << endl;
    lista.PopBack(); // la lista ya está vacía, mostrará un mensaje

    cout << "Fin de la demostración de la lista con centinela." << endl;
}
