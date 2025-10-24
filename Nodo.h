#pragma once

struct Nodo {
    int x;
    int y;
    int valor;
    Nodo* right;
    Nodo* down;

    Nodo() : x(0), y(0), valor(0), right(nullptr), down(nullptr) {}
    Nodo(int v, int xPos, int yPos) : x(xPos), y(yPos), valor(v), right(nullptr), down(nullptr) {}
};
