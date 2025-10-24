#include <iostream>
#include "SparseMatrix.h"
#include <string>
#include <random>
#include <set>

using namespace std;
SparseMatrix Matriz;

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
        cout << "                      " << endl;
        cout << "Menu de Opciones:" << endl;
        cout << "1. Agregar un dato en una coordenada" << endl;
        cout << "2. Obtener dato de una coordenada" << endl;
        cout << "3. Remover dato de una cordenada" << endl;
        cout << "4. Mostrar los datos tabularmente" << endl;
        cout << "5. Calcular la densidad de la matriz" << endl;
        cout << "6. Multiplicar matriz" << endl;
        cout << "7. Salir" << endl;
        cout << "Ingrese una opcion: ";
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
                cout << "Opcion no valida, intente de nuevo"<< endl;
        }
    } while(opcion !=7);
    return 0;
}
void agregarDato(){
    int X;
    int Y;
    int valor;
    string input;
    cout << "                      " << endl;
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
        cout<<"Valor asignado a 0 automaticamente"<<endl;
        return;
    }
    Matriz.add(X,Y,valor);
	cout << "Dato agregado en la coordenada " << X << "," << Y << endl;
}
void obtenerDato(){
    int X;
    int Y;
    string input;
    cout << "                      " << endl;
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
    cout<< "Valor en la coordenada "<< X << "," <<Y << " es: " << Matriz.get(X,Y) << endl;
}
void removerDato(){
    int X;
    int Y;
    string input;
    cout << "                      " << endl;
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
    int a = Matriz.remover(X,Y);
    if (a == 1){
        cout << "Dato eliminado en la coordenada"<<endl;
    } else {
        cout << "Coordenada vacia"<<endl;
    }
}
void mostrarDatos(){
    cout << "                      " << endl;
	cout << "Mostrando datos de la Matriz..." << endl;
	Matriz.printStoredValues();
}
void calcularDensidad(){
    cout << "                      " << endl;
    cout << "Calculando densidad de la matriz..." << endl;
	cout << "La densidad de la matriz es: " << Matriz.density() << "%" << endl;
    if(Matriz.density() == 0){
        cout << "(La matriz tiene 0 elementos o es un porcentaje menor a 1)";
    }
}
void multiplicarMatriz() {
    auto dimensA = Matriz.getDimensions();
    int filaMaxA = dimensA.first;
    int colMaxA = dimensA.second;

    if (filaMaxA == 0 && colMaxA == 0) {
        cout << "                      " << endl;
        cout << "Matriz A vacia. No hay dimensiones para generar B." << endl;
        return;
    }
    if (colMaxA == 0) {
        cout << "                      " << endl;
        cout << "Matriz A no tiene columnas validas. No se puede generar B compatible." << endl;
        return;
    }
    cout << "                      " << endl;
    cout << "Dimensiones de A usadas: Filas = " << filaMaxA << ", Columnas = " << colMaxA << endl;
    string input;
    int colsB = 0;
    cout << "Ingrese numero de columnas deseadas para B: ";
    getline(cin, input);
    try { colsB = stoi(input); }
    catch (...) { colsB = 0; }
    if (colsB <= 0) {
        cout << "Número de columnas invalido." << endl;
        return;
    }
    int cantValores = 0;
    cout << "                      " << endl;
    cout << "Ingrese numero de elementos no nulos deseados en B (max " << (long long)colMaxA * colsB << "): ";
    getline(cin, input);
    try { cantValores = stoi(input); }
    catch (...) { cantValores = 0; }
    if (cantValores <= 0) {
        cout << "Numero de no nulos invalido." << endl;
        return;
    }
    long long maxPossible = (long long)colMaxA * colsB;
    if (cantValores > maxPossible) cantValores = static_cast<int>(maxPossible);
    cout << "                      " << endl;
    SparseMatrix B;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distRow(1, colMaxA);
    std::uniform_int_distribution<> distCol(1, colsB);
    std::uniform_int_distribution<> distVal(1, 9);

    std::set<std::pair<int, int>> used_coords;

    for (int i = 0; i < cantValores;) {
        int r = distRow(gen);
        int c = distCol(gen);
        std::pair<int, int> coord = { r, c };
        if (used_coords.insert(coord).second) {
            int v = distVal(gen);
            B.add(r, c, v);
            i++;
        }
    }

    cout << "Matriz B generada aleatoriamente con " << cantValores << " valores (rango de valores entre 1 a 9)." << endl;
    cout << "                      " << endl;
    cout << "Multiplicando A * B..." << endl;
    SparseMatrix* R = Matriz.multiply(&B);
    if (R == nullptr) {
        cout << "Resultado vacio (posible incompatibilidad o matrices vacías)." << endl;
        return;
    }
    cout << "                      " << endl;
    cout << "Resultado (valores almacenados):" << endl;
    R->printStoredValues();
    delete R;
}
