#include <iostream>
#include "SparseMatrix.h"
using namespace std;
SparseMatrix Matriz;

void menuPrincipal();
void agregarDato();
void obtenerDato();
void removerDato();
void mostrarDatos();
void calcularDensidad();
void multiplicarMatriz();

int main() {
    int opcion;
    string input;
    do{
        menuPrincipal();
        getline(cin, input);
        try {
            opcion = stoi(input);
        } catch (...){
            opcion = 0;
        }
        switch(opcion){
            case 1 :
                agregarDato();
                break;
            case 2 :
                obtenerDato();
                break;
            case 3 :
                removerDato();
                break;
            case 4 :
                mostrarDatos();
                break;
            case 5 :
                calcularDensidad();
                break;
            case 6 :
                multiplicarMatriz();
                break;
            case 7 :
                cout<<"Saliendo del programa"<<endl;
                break;
            default:
                cout << "Opción no válida, intente de nuevo"<< endl;
        }
    } while(opcion !=7);
    return 0;
}

void menuPrincipal() {
    cout << "Menu de Opciones:" << endl;
    cout << "1. Agregar un dato en una coordenada" << endl;
    cout << "2. Obtener dato de una coordenada" << endl;
    cout << "3. Remover dato de una cordenada" << endl;
    cout << "4. Mostrar los datos de una coordenada" << endl;
    cout << "5. Calcular la densidad de la matriz" << endl;
    cout << "6. Multiplicar matriz"<< endl;
    cout << "7. Salir"<< endl;
    cout << "Ingrese una opcion: ";
}
void agregarDato(){
    int X;
    int Y;
    int value;
    string input;
    cout << "----------------------" << endl;
    cout << "Ingrese Coordenada en X: " << endl;
    getline(cin, input);
    try {
        X = stoi(input);
    } catch (...) {
        X = 0;
    }
    if (X <= 0) {
        cout<<"Opcion no valida"<<endl;
        return;
    }
    cout << "Ingrese Coordenada en Y: " << endl;
    getline(cin, input);
    try {
        Y = stoi(input);
    } catch (...) {
        Y = 0;
    }
    if (Y <= 0) {
        cout<<"Opcion no valida"<<endl;
        return;
    }
    cout << "Ingrese Valor a colocar: " << endl; 
    getline(cin, input);
    try {
        valor = stoi(input);
    } catch (...){
        valor = 0;
    }
    if(valor == 0){
        cout<<"Opcion no valida"<<endl;
        return;
    }
    Matriz.add(X,Y,valor);
}
void obtenerDato(){
    int X;
    int Y;
    string input;
    cout << "----------------------" << endl;
    cout << "Ingrese Coordenada en X: " << endl;
    getline(cin, input);
    try {
        X = stoi(input);
    } catch (...){
        X = 0;
    }
    if(X <= 0){
        cout<<"Opcion no valida"<<endl;
        return;
    }
    cout << "Ingrese Coordenada en Y: " << endl;
    getline(cin, input);
    try {
        Y = stoi(input);
    } catch (...){
        Y = 0;
    }
    if(Y <= 0){
        cout<<"Opcion no valida"<<endl;
        return;
    }
    cout<< "Valor en la coordenada "<< X << Y << " es: " << Matrix.get(X,Y) << endl;
}
void removerDato(){
    int X;
    int Y;
    string input;
    cout << "----------------------" << endl;
    cout << "Ingrese Coordenada X: " << endl;
    getline(cin, input);
    try {
        X = stoi(input);
    } catch (...){
        X = 0;
    }
    if(X <= 0){
        cout<<"Opcion no valida"<<endl;
        return;
    }
    cout << "Ingrese Coordenada Y: " << endl;
    getline(cin, input);
    try {
        Y = stoi(input);
    } catch (...){
        Y = 0;
    }
    if(Y <= 0){
        cout<<"Opcion no valida"<<endl;
        return;
    }
    int a = Matrix.remover(X,Y);
    if (a == 1){
        cout << "Dato eliminado en la coordenada"<<endl;
    } else {
        cout << "Coordenada vacia"<<endl;
    }
}
void MostrarDatos(){}
void DensidadMatriz(){}
void MultiplicarMatriz(){}
