#include <iostream>

using namespace std;

struct Producto{
    int codigo;
    char* nombre;
    double precio;
    int stock;
};


Producto crearProducto(int codigo, const char* nombre, double precio, int stock){
    char p[100];
    for(int i = 0; i < 100; i++){
        p[i] = *(nombre+i);
    }
    return Producto{codigo, p, precio, stock};
};

Producto* crearInventario(int n){
    const char*p[5] = {"Teclado", "Mouse", "Monitor", "Laptop", "Impresora"};
    Producto* T;
    for(int i = 0; i < n; i++){ 
        int codigo = 100 + i;
        double precio = 105*(1+i);
        int stock = 5*(1+i);
        *(T+i)=crearProducto(codigo, p[i], precio, stock);
    }
    return T;
};

Producto* buscarProducto(Producto* inventario, int n, int codigoBuscado){
    Producto* B; 
    for(int i = 0; i < n; i++){
        if((inventario+i)->codigo == codigoBuscado){
            B = (inventario+i);
        }
    }
    return B;
};

int main(){
    Producto* T= crearInventario(5);
    cout << "INVENTARIO" << endl;
    for(int i = 0; i < 5; i++){
        cout << "Codigo: " << (T+i)->codigo << " / " << " Nombre: " << (T+i)->nombre << " / Precio: "
        << (T+i)->precio << " /Stock: " << (T+i)->stock << endl; 
    }
    cout << "Buscando producto con codigo 102.. " << endl;
    Producto* B = buscarProducto(T, 5, 102);
    cout << "Producto encontrado: " << B->nombre << "/" << B->precio << endl;
    return 0;
}   