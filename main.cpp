#include <iostream>
#include <vector>

using namespace std;

// Definición de la máquina expendedora
const int NUM_PRODUCTS = 5;
const int INITIAL_STOCK = 5;
const int COIN_VALUES[] = {5, 25, 50, 100}; // Valores de monedas en centavos

struct VendingMachine {
    int productStock[NUM_PRODUCTS];
    int coinStock[4];
    vector<int> selectedProducts;
    vector<int> selectedCoins;
};

// Función para imprimir la solución
void printSolution(const VendingMachine &vm) {
    cout << "Producto seleccionado: " << vm.selectedProducts.back() << endl;
    cout << "Monedas seleccionadas: ";
    for (int coin : vm.selectedCoins) {
        cout << coin / 100.0 << " ";
    }
    cout << endl;
}

// Función de backtracking para dar cambio
bool changeBacktrack(VendingMachine &vm, int remainingValue) {
    if (remainingValue == 0) {
        printSolution(vm);
        return true;
    }
    
    for (int i = 0; i < 4; ++i) {
        if (vm.coinStock[i] > 0 && remainingValue >= COIN_VALUES[i]) {
            vm.coinStock[i]--;
            vm.selectedCoins.push_back(COIN_VALUES[i]);
            if (changeBacktrack(vm, remainingValue - COIN_VALUES[i])) {
                return true;
            }
            vm.coinStock[i]++;
            vm.selectedCoins.pop_back();
        }
    }
    
    return false;
}

int main() {
    VendingMachine vm;
    
    for (int i = 0; i < NUM_PRODUCTS; ++i) {
        vm.productStock[i] = INITIAL_STOCK;
    }
    for (int i = 0; i < 4; ++i) {
        vm.coinStock[i] = 10;
    }
    
    int selectedProduct;
    cout << "Seleccione un producto (0-" << NUM_PRODUCTS - 1 << "): ";
    cin >> selectedProduct;
    
    if (selectedProduct < 0 || selectedProduct >= NUM_PRODUCTS || vm.productStock[selectedProduct] == 0) {
        cout << "Producto no disponible.\n";
        return 1;
    }
    
    int productPrice = COIN_VALUES[selectedProduct];
    vm.productStock[selectedProduct]--;
    vm.selectedProducts.push_back(selectedProduct);
    
    int insertedAmount;
    cout << "Ingrese la cantidad de dinero en centavos: ";
    cin >> insertedAmount;
    
    int remainingChange = insertedAmount - productPrice;
    
    if (remainingChange < 0) {
        cout << "Dinero insuficiente.\n";
        return 1;
    }
    
    if (changeBacktrack(vm, remainingChange)) {
        cout << "Cambio entregado.\n";
    } else {
        cout << "No se puede dar el cambio.\n";
    }
    
    return 0;
}
