#pragma once

struct Nodo {
    int x;
    int y;
    int value;
    Nodo* right;
    Nodo* down;

    Nodo() : x(0), y(0), value(0), right(nullptr), down(nullptr) {} //sin parametro

    Nodo(int v, int xPos, int yPos) : x(xPos), y(yPos), value(v), right(nullptr), down(nullptr) {} //con parametro
};
