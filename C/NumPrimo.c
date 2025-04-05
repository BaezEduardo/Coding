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
    int n,j = 0;

    printf("Programa que te dice los primeros n numeros par\n");
    printf("Cuantos numeros primos quieres saber?\n");
    scanf("%d",&n);
    
    printf("Lista de numeros primos: \n");
    
    for (int i = 2; j<n; i++){
        if (primo(i)){
            printf("%d\n",i);
            j++;
        }
    }
    
    return 0;
}