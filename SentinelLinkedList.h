// Universidad Cuauhtémoc Querétaro
// Materia: Programación Orientada a Objetos
// Profesor: M. en C. Adrián Ulises González Casillas
// Práctica: Entrega del Parcial – Ejercicios Listas, Doblemente ligadas, Stacks y Queues
// Parte: 1 – SentinelLinkedList
// Descripción: Este código crea una lista doblemente ligada con nodo centinela. Agrega las funciones PushFront y PopFront.
// Alumnos: Cecilia Romero Granados, Alexis Jeshua Arrona

#pragma once
#include <iostream>
using namespace std;

template <typename T>
class SentinelLinkedList {
private:
    class Node {
    public:
        Node(T _data) : data(_data), next(nullptr), prev(nullptr) {}
        T data;
        Node* next;
        Node* prev;
    };

    Node* NIL;
    int count;

public:
    SentinelLinkedList() {
        NIL = new Node(T{});
        NIL->next = NIL;
        NIL->prev = NIL;
        count = 0;
    }

    ~SentinelLinkedList() {
        Node* current = NIL->next;
        while (current != NIL) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        delete NIL;
    }

    void Append(T value) {
        Node* newNode = new Node(value);
        NIL->prev->next = newNode;
        newNode->prev = NIL->prev;
        newNode->next = NIL;
        NIL->prev = newNode;
        count++;
    }

    void PushFront(T value) {
        Node* newNode = new Node(value);
        newNode->next = NIL->next;
        newNode->prev = NIL;
        NIL->next->prev = newNode;
        NIL->next = newNode;
        count++;
    }

    T PopFront() {
        if (count == 0) {
            cout << "Error: la lista está vacía." << endl;
            return T{};
        }
        Node* nodeToDelete = NIL->next;
        T value = nodeToDelete->data;
        NIL->next = nodeToDelete->next;
        nodeToDelete->next->prev = NIL;
        delete nodeToDelete;
        count--;
        return value;
    }

    T PopBack() {
        if (count == 0) {
            cout << "Error: la lista está vacía." << endl;
            return T{};
        }
        Node* nodeToDelete = NIL->prev;
        T value = nodeToDelete->data;
        nodeToDelete->prev->next = NIL;
        NIL->prev = nodeToDelete->prev;
        delete nodeToDelete;
        count--;
        return value;
    }

    T Front() {
        if (count == 0) {
            cout << "Error: lista vacía." << endl;
            return T{};
        }
        return NIL->next->data;
    }

    int GetCount() { return count; }
};
