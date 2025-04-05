#include <stdio.h>
#include <math.h>

int primo(int n){

    if (n < 2){
        return 0;
    }
    
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n%i == 0){
            return 0;
        }
    }
    return 1;
}

int main(){
    int n;

    printf("Programa que te dice si un numero n es primo o no\n");
    printf("Ingrese un numero\n");
    scanf("%d",&n);
    
    if (primo(n)){
        printf("El numero es primo");
    }
    else printf("El numero no es primo");

    return 0;
}