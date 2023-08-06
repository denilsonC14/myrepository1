//El objetivo de este problema es determinar la máxima cantidad de valor que se puede 
//llevar en una mochila con una capacidad de peso determinada, sin exceder dicha 
//capacidad y tomando o dejando los elementos en su totalidad(no se pueden dividir).

#include <iostream>
#include <vector>
#include "Mochila.h"


int main() {

    int n;
    std::cout << "Ingrese el número de elementos: ";
    std::cin >> n;

    int* peso = new int[n];
    int* valores = new int[n];

    std::cout << "Ingrese los pesos de los elementos: ";
    for (int i = 0; i < n; i++) {
        std::cin >> *(peso + i);
    }

    std::cout << "Ingrese los valores de los elementos: ";
    for (int i = 0; i < n; i++) {
        std::cin >> *(valores + i);
    }

    int capacidad;
    std::cout << "Ingrese la capacidad de la mochila: ";
    std::cin >> capacidad;

    int valor_max = recusividad(peso, valores, n, capacidad);
    std::cout << "Valor máximo de la mochila: " << valor_max << std::endl;

    delete[] peso;
    delete[] valores;

    return 0;
}