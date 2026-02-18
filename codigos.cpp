#include <iostream>

using namespace std;

// 1. Funcion Recurisva

// Numero Factorial
int NumeroFactorial(int n){
    if(n == 1){
        return 1;
    }
    return n*NumeroFactorial(n-1);
}


// Conjetura de Collatz

void Collatz(int n) {
    if (n == 1) {
        cout << n << " este es el fin" << endl;
        return;
    }
    if (n % 2 == 0) {
        cout << n << " es par" << endl;
        Collatz(n / 2);
    } else {
        cout << n << " es impar" << endl;
        Collatz((3 * n + 1) / 2);
    }
} 

// 2. Ordenamiento

void MetodoBurbuja(int arr[], int n){  // metodo burbuja arreglos
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-1-i; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
} 

void MetodoSeleccion(int arr[], int n){ // metodo Seleccion arreglos
    for(int i = 0; i < n; i++){
        int indMin = i;
        for(int j = i+1; j < n; j++){
            if(arr[j]<arr[indMin]){
                indMin = j;
            }
        }
        swap(arr[i], arr[indMin]);
    }
}

void MetodoInsercion(int arr[], int n){ // metodo Insercion arreglos
    for(int i = 1; i < n; i++){
        int temp = arr[i];
        int j = i-1;
        while(j >= 0 && arr[j] > temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp; 
    }
}

void Merge(int arr[], int l, int m, int r){   // metodo mergesort arreglos
    int n1 = m-l+1;
    int n2 = r - m;

    int L[100], R[100];

    for(int i = 0; i < n1; i++){
        L[i] = arr[l+i];
    }

    for(int i = 0; i< n2; i++){
        R[i] = arr[m+1+i];
    }

    int i = 0, j = 0, k = l;

    while(i < n1 && j < n2){
        if(L[i] <= R[j]){   
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(int arr[], int l, int r){
    if(l<r){
        int m = (l+r)/ 2;

        MergeSort(arr,l,m);

        MergeSort(arr, m+1, r);
        
        Merge(arr,l,m,r);
    }
}

int Particion(int arr[], int low, int high){
    int pivote = arr[high];
    int i = low -1; 

    for(int j = low; j < high; j++){
        if(arr[j] <= pivote){
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i+1], arr[high]);
    return i + 1;
}
void QuickSort(int arr[], int low, int high){  // metodo quicksort arreglos
    if(low < high){
        int pi = Particion(arr,low,high);

        QuickSort(arr, low, pi-1);
    
        QuickSort(arr,pi +1,high);
    }
}

void Imprimir(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << ", ";
    }
    cout << endl;
}

int main(){
    // Funciones

    int collat;
    int fact;
    int facto;
    
    cout << "El numero para el factorial: " << endl;
    cin >> fact;
    facto = NumeroFactorial(fact);
    cout << facto << endl;

    cout << "El numero para la conjetura de Collatz: " << endl;
    cin >> collat;
    Collatz(collat);

    // Arreglos y Ordenamiento
    int sizearr;

    cout << "Digite el numero de elementos del arreglo principal" << endl;
    cin >> sizearr;

    int arr[sizearr];

    for(int i = 0; i < sizearr; i++){
        cout << "Elemento " << i << ":" << endl;
        cin >> arr[i];
    }

    Imprimir(arr,sizearr);
    int opc;
    cout << "------------- MENU DE ORDENAMIENTOS --------" << endl;
    cout << "1. Metodo Burbuja" << endl;
    cout << "2. Metodo Seleccion" << endl;
    cout << "3. Metodo Insercion" << endl;
    cout << "4. Merge Sort" << endl;
    cout << "5. Quick Sort" << endl;
    cout << "Digite la opcion: " << endl;
    cin >> opc;

    switch (opc)
    {
    case 1:
        MetodoBurbuja(arr, sizearr-1);
    case 2:
        MetodoSeleccion(arr, sizearr-1);
    case 3:
        MetodoInsercion(arr, sizearr-1);
    case 4:
        MergeSort(arr, 0, sizearr-1);
    case 5:
        QuickSort(arr, 0, sizearr-1);
    default:
        break;
    }
    Imprimir(arr, sizearr);
    return 0;
}