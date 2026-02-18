#include <iostream>

using namespace std;

struct Item{
    char* descripcion;
    int cantidad;
    double precioUnitario;
};

struct Pedido{
    int numeroPedido;
    char* nombreCliente;
    Item* items;
    int cantidadItems;
};

Item crearItem(const char* descripcion, int cantidad, double precioUnitario){
    char p[100];
    for(int i = 0; i < 100; i++){
        p[i] = *(descripcion+i);
    }
    return Item{p, cantidad, precioUnitario};
};

Pedido* crearPedido(int numero, const char* cliente, int cantidadItems){
    Pedido* ped;
    Item* items;
    const char*p[3] = {"Laptop", "Mouse", "Teclado"};
    for(int i = 0; i<cantidadItems; i++){
        int cantidad = i+1;
        int precio = 100*(1+i);
        *(items+i) = crearItem(p[i],cantidad,precio);
    }
    ped -> items = items;
    ped->numeroPedido = numero;
    ped -> nombreCliente == cliente;
    return ped;
};

double calcularTotal(const Pedido* p){
    Item* k = p->items;
    double total = 0;
    for(int i = 0; i < p->cantidadItems; i++){
        total += (k+i)->cantidad * (k+i)->precioUnitario;
    }
    return total;
}

int main(){
    Pedido* p = crearPedido(101, "Carlos Perez", 6);
    cout << "Pedido N°: " << p->numeroPedido << endl;
    cout << "Cliente: " << p->nombreCliente << endl;
    Item* k = p->items;
    cout << "Items:" << endl;
    for(int i = 0; i<3; i++){
        cout << "- " << (k+i)->descripcion << "/Cant: " << (k+i)->cantidad << "/PRecio: "<<(k+i)->precioUnitario << endl;
    }
    double total = calcularTotal(p);
    cout << "Cantidad total: " << total << endl;

    // Como la digitacion ya estaba ordenado debido a que no se puede digitar por teclado
    // es obvio el mayor y lo he saltado
    return 0;
}