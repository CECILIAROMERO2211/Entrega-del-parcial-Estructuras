// Universidad Cuauhtémoc Querétaro
// Materia: Programación Orientada a Objetos
// Profesor: M. en C. Adrián Ulises González Casillas
// Práctica: Entrega del Parcial – Ejercicios Listas, Doblemente ligadas, Stacks y Queues
// Parte: 1 – SentinelLinkedList.cpp
// Descripción: Este archivo está aquí para acompañar a "SentinelLinkedList.h". 
// No tiene código porque toda la lógica ya está escrita en el otro archivo.
// Se deja solo para mantener el proyecto completo y organizado, tal como se pidió en la práctica.
// Alumnos: Cecilia Romero Granados, Alexis Jeshua Arrona

#include "SentinelLinkedList.h" // Incluimos el archivo con la clase de la lista

// Esta función muestra cómo funcionan las operaciones básicas de la lista con centinela
void DemostracionSentinelLinkedList()
{
    // Se crea una lista vacía que guarda cadenas de texto (strings)
    SentinelLinkedList<string> miLista;

    // Se agregan tres nombres al final de la lista
    miLista.Append("Juan");   // Agrega "Juan"
    miLista.Append("Maria");  // Agrega "Maria"
    miLista.Append("Pedro");  // Agrega "Pedro"

    // Se revisa si la lista contiene ciertos valores
    if (miLista.Contiene("Maria")) // Si la lista contiene "Maria"
        cout << "La lista con centinela SÍ contiene a Maria" << endl;
    else
        cout << "La lista con centinela NO contiene a Maria" << endl;

    // Se busca un nombre que no existe en la lista
    if (miLista.Contiene("Juancho")) // Si encuentra "Juancho"
        cout << "La lista con centinela SÍ contiene a Juancho" << endl;
    else
        cout << "La lista con centinela NO contiene a Juancho" << endl;

    // Se obtiene el valor del primer elemento usando su posición 
    cout << "El valor en la posición 0 es: " << miLista.ObtenerPorIndice(0) << endl;

    // Se prueban eliminaciones desde el final 
    cout << "Quitando del final (PopBack): " << miLista.PopBack() << " (esperado: Pedro)" << endl;
    cout << "Quitando del final (PopBack): " << miLista.PopBack() << " (esperado: Maria)" << endl;
    cout << "Quitando del final (PopBack): " << miLista.PopBack() << " (esperado: Juan)" << endl;

    // Intentamos quitar otro elemento cuando ya está vacía (debe mostrar un mensaje de error)
    cout << "Probando PopBack con lista vacía:" << endl;
    miLista.PopBack(); // Aquí se muestra el mensaje de error porque no hay elementos

    // Se crea otra lista solo para comprobar que el destructor borra correctamente los nodos
    SentinelLinkedList<string> listaTemporal; // Nueva lista vacía
    listaTemporal.Append("Elemento temporal"); // Agregamos un elemento temporal

    // A partir de aquí se prueba la parte que pertenece a la Tarea 2 del segundo parcial

    // Se crea una nueva lista con varios elementos iniciales
    SentinelLinkedList<string> listaTarea2;
    listaTarea2.Append("Ana");    // Agregamos "Ana"
    listaTarea2.Append("Luis");   // Agregamos "Luis"
    listaTarea2.Append("Carlos"); // Agregamos "Carlos"

    // Se muestra cuál es el primer elemento actual
    cout << "Primer elemento actual (esperado: Ana): " << listaTarea2.Front() << endl;

    // Probamos la función PushFront (agrega un elemento al inicio de la lista)
    cout << "Agregando 'Sofia' al frente con PushFront..." << endl;
    listaTarea2.PushFront("Sofia"); // Inserta "Sofia" al principio

    // Verificamos que ahora el primer elemento sea "Sofia"
    cout << "Nuevo primer elemento (esperado: Sofia): " << listaTarea2.Front() << endl;

    // Probamos la función PopFront (elimina el primer elemento de la lista)
    cout << "Quitando el primer elemento con PopFront..." << endl;
    cout << "Elemento eliminado (esperado: Sofia): " << listaTarea2.PopFront() << endl;

    // Mostramos nuevamente el primer elemento para confirmar que "Sofia" fue eliminada
    cout << "Primer elemento después del PopFront (esperado: Ana): " << listaTarea2.Front() << endl;

    // Cuando esta función termine, los destructores se ejecutarán automáticamente
    // y se eliminarán todas las listas creadas, mostrando su mensaje en consola.
}
