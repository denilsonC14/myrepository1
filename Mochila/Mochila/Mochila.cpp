#include <iostream>
#include "Mochila.h"
/**
int Programaciónd(int* peso, int* valores, int n, int capacidad) {
    int** dp = new int* [n + 1];
    for (int i = 0; i <= n; i++) {
        dp[i] = new int[capacidad + 1];
    }

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacidad; w++) {
            if (i == 0 || w == 0) {
                *(*(dp + i) + w) = 0;
            }
            else if (*(peso + i - 1) <= w) {
                *(*(dp + i) + w) = std::max(*(valores + i - 1) + *(*(dp + i - 1) + w - *(peso + i - 1)), *(*(dp + i - 1) + w));
            }
            else {
                *(*(dp + i) + w) = *(*(dp + i - 1) + w);
            }
        }
    }

    int valor_max = *(*(dp + n) + capacidad);

    for (int i = 0; i <= n; i++) {
        delete[] dp[i];
    }
    delete[] dp;

    return valor_max;
}
**/
int recusividad(int* peso, int* valores, int n, int capacidad) {
    if (n == 0 || capacidad == 0) {
		return 0;
	}
    if (*(peso + n - 1) > capacidad) {
		return recusividad(peso, valores, n - 1, capacidad);
	}
    else {
		int a=*(valores + n - 1) + recusividad(peso, valores, n - 1, capacidad - *(peso + n - 1));
        int b=recusividad(peso, valores, n - 1, capacidad);
        return std::max(a, b);
	}
 


}