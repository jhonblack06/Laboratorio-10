#include <iostream>

using namespace std;
/*Esta funcion la usaremos para llenar la matriz de tal manera que nos pide un valor y retorna este mismo*/
int entrada(){
  int a;
  cin>>a;
  return a;
}
/*Creamos una funcion que se llama recursivamente fila por fila e inicializa la matriz dinamicamente*/
void creacion_mt(int **mt,int f,int c,int i=0){
    if (f==i) return;
    *(mt+i)=new int[c];
    i++;
    creacion_mt(mt,f,c,i);  //Llamada recursiva
  }
/*Creamos otra funcion recursiva que se apoya de otra para ir llenando la matriz recorriendo esta*/
void llenado(int **mt,int f,int c,int i=0,int j=0){
    if (j==c){  //Condicion para continuar a la siguiente fila cuando terminamos te recorrer una dentro de la matriz
        i++;
        j=0;
    }
    if (i==f)  //Creamos una condicion de parada para terminar la recursion y el llenado
        return;
    cout<<"Ingrese un valor: "<<endl;
    *(*(mt+i)+j) = entrada();
    j++;
    llenado(mt,f,c,i,j);  //Llamada recursiva
}
/*Creamos una funcion recursiva que recorre toda la matriz imprimiendo cada valor de esta*/
void imprimir(int **mt,int f,int c,int i=0,int j=0){
    if (j==c){  //Condicion para continuar a la siguiente fila cuando terminamos te recorrer una dentro de la matriz
       cout<<"\n";
        i++;
        j=0;
    }
    if (i==f)  //Creamos una condicion de parada para terminar la recursion
        return;
    cout<<*(*(mt+i)+j)<<"  ";
    j++;
    imprimir(mt,f,c,i,j);  //Llamada recursiva
}
/*Creamos una funcion que elimine el espacio separado por los punteros fila por fila*/
void eliminar(int **mt,int f,int i=0){
        if (i==f){   //Creamos una condicion de parada para terminar la recursion
            delete[] mt;  //Eliminamos completamente el espacio de memoria separado
            return;
        }
        delete[] *(mt+i);
        i++;
        eliminar(mt,f,i);  //Llamada recursiva

}
/*En las siguientes funciones SUMA,RESTA,MAYOR,MENOR,PROMEDIO usamos casi la misma logica ya que las matrices tienen que ser de dimensiones
iguales para poder realizar las operaciones recorremos estas y aplicamos la operacion respectiva entre en la misma posicion del elemento en ambas
matrices y lo guardamos en una nueva matriz con dimensiones ya definidas*/
void suma_mt(int **mt1,int **mt2,int **mt3,int f1,int c1,int f2,int c2,int i=0,int j=0){
    if(j==c1){  //Condicion para continuar a la siguiente fila cuando terminamos te recorrer una dentro de la matriz
        i++;
        j=0;
    }
    if(i==f1){  //Creamos una condicion de parada para terminar la recursion
        return;
    }
    *(*(mt3+i)+j) = *(*(mt1+i)+j) + *(*(mt2+i)+j);  //Guardamos la suma de los valores de las matrices
    j++;
    suma_mt(mt1,mt2,mt3,f1,c1,f2,c2,i,j);   //Llamada recursiva
}

void resta_mt(int **mt1,int **mt2,int **mt3,int f1,int c1,int f2,int c2,int i=0,int j=0){
    if(j==c1){  //Condicion para continuar a la siguiente fila cuando terminamos te recorrer una dentro de la matriz
        i++;
        j=0;
    }
    if(i==f1){  //Creamos una condicion de parada para terminar la recursion
        return;
    }
    *(*(mt3+i)+j)=*(*(mt1+i)+j)-*(*(mt2+i)+j);  //Guardamos la resta de los valores de las matrices
    j++;
    resta_mt(mt1,mt2,mt3,f1,c1,f2,c2,i,j);  //Llamada recursiva
}

void mayor_mt(int **mt1,int **mt2,int **mt3,int f1,int c1,int f2,int c2,int i=0,int j=0){
    if(j==c1){  //Condicion para continuar a la siguiente fila cuando terminamos te recorrer una dentro de la matriz
        i++;
        j=0;
    }
    if(i==f1){  //Creamos una condicion de parada para terminar la recursion
        return;
    }
    if(*(*(mt1+i)+j) > *(*(mt2+i)+j)){ //Comparamos los elementos en las matrices y guardamos el mayor de estos
        *(*(mt3+i)+j)=*(*(mt1+i)+j);
    }
    else
        *(*(mt3+i)+j)=*(*(mt2+i)+j);
    j++;
    mayor_mt(mt1,mt2,mt3,f1,c1,f2,c2,i,j);  //Llamada recursiva
}

void menor_mt(int **mt1,int **mt2,int **mt3,int f1,int c1,int f2,int c2,int i=0,int j=0){
    if(j==c1){  //Condicion para continuar a la siguiente fila cuando terminamos te recorrer una dentro de la matriz
        i++;
        j=0;
    }
    if(i==f1){  //Creamos una condicion de parada para terminar la recursion
        return;
    }
    if(*(*(mt1+i)+j) < *(*(mt2+i)+j)){  //Comparamos los elementos en las matrices y guardamos el menor de estos
        *(*(mt3+i)+j)=*(*(mt1+i)+j);
    }
    else
        *(*(mt3+i)+j)=*(*(mt2+i)+j);
    j++;
    menor_mt(mt1,mt2,mt3,f1,c1,f2,c2,i,j);  //Llamada recursiva
}

void prom_mt(int **mt1,int **mt2,int **mt3,int f1,int c1,int f2,int c2,int i=0,int j=0){
    if(j==c1){  //Condicion para continuar a la siguiente fila cuando terminamos te recorrer una dentro de la matriz
        i++;
        j=0;
    }
    if(i==f1){  //Creamos una condicion de parada para terminar la recursion
        return;
    }
    *(*(mt3+i)+j) = (*(*(mt1+i)+j)-*(*(mt2+i)+j))/2;  //Guardamos el promedio de los valores de ambas matrices
    j++;
    prom_mt(mt1,mt2,mt3,f1,c1,f2,c2,i,j);  //Llamada recursiva
}

void multi_mt(int **mt1,int **mt2,int **mt3,int f1,int c1,int c2,int suma=0,int cont1=0,int cont2=0,int i=0,int k=0,int j=0){
	if (k==c2){
        (*(*(mt3+i)+j))=suma;  //Guardamos la multiplicacion ya guardada en una nueva matriz
        j++;
        k=0;
        suma=0;
		if (j==c1){  //Condicion para continuar a la siguiente fila
        	i++;
        	j=0;
   		 }
    }
    if (i==f1)  //Creamos una condicion de parada para terminar la recursion
        return;
    cont1=*(*(mt1+i)+k);  //Guardamos el valor de la posicion de la primera matriz en una variable
    cont2=*(*(mt2+k)+j);  //Guardamos el valor de la posicion de la segunda matriz en una variable
    suma+=cont1*cont2;  //Efectuamos la multiplicacion y la guardamos en una nueva variable y sumamos progresivamente
    k++;
  	multi_mt(mt1,mt2,mt3,f1,c1,c2,suma,cont1,cont2,i,k,j);  //Llamada recursiva
}


int main()
{
    int filas1, columnas1, filas2, columnas2;
    int **mtA,**mtB,**mtC;
    cout<<"Ingrese el numero de filas para la matriz 1"<<endl;
    filas1=entrada();
    cout<<"Ingrese el numero de columnas para la matriz 1"<<endl;
    columnas1=entrada();
    cout<<"Ingrese el numero de filas para la matriz 2"<<endl;
    filas2=entrada();
    cout<<"Ingrese el numero de columnas para la matriz 2"<<endl;
    columnas2=entrada();
    mtA=new int*[filas1];
    mtB=new int*[filas2];
    mtC=new int*[filas1];
    creacion_mt(mtA,filas1,columnas1);
    creacion_mt(mtB,filas2,columnas2);
    creacion_mt(mtC,filas1,columnas2);

    llenado(mtA,filas1,columnas1);
    llenado(mtB,filas2,columnas2);
    cout<<"Matriz A: "<<endl;
    imprimir(mtA,filas1,columnas1);
    cout<<"Matriz B: "<<endl;
    imprimir(mtB,filas2,columnas2);

    /*Creamos un puntero funcion para escoger la operacion a realizar entre las dos matrices*/
    void (*ptrOp)(int**,int**,int**,int,int,int,int,int,int);
    int operacion = 0 ;
    cout<<"Ingrese la operacion a efectuar 1:suma ; 2:resta ; 3:mayor ; 4:menor ; 5:promedio "<<endl;
    cin >> operacion ;
    if(operacion==1)
        ptrOp=suma_mt;
    else if(operacion==2)
        ptrOp=resta_mt;
    else if(operacion==3)
        ptrOp=mayor_mt;
    else if(operacion==4)
        ptrOp=menor_mt;
    else if(operacion==5)
        ptrOp=prom_mt;

    //Llamamos el puntero con la operacion sellecionada
    ptrOp(mtA,mtB,mtC,filas1,columnas1,filas2,columnas2,0,0);

    //multi_mt(mtA,mtB,mtC,filas1,columnas1,columnas2);
    //Imprimimos la matriz resultante
    cout<<"Matriz Resultante: "<<endl;
    imprimir(mtC,filas1,columnas2);
    //eliminamos los espacios de memoria separados
    eliminar(mtA,filas1);
    eliminar(mtB,filas2);
    eliminar(mtC,filas1);
    return 0;
}
