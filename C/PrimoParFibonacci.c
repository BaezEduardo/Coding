/*
 * Escribe un programa que, dado un número, compruebe y muestre si es primo, fibonacci y par.
 * Ejemplos:
 * - Con el número 2, nos dirá: "2 es primo, fibonacci y es par"
 * - Con el número 7, nos dirá: "7 es primo, no es fibonacci y es impar"
 primo=entre si mismo y 1
 fibonacci= 0,1,1,2,3,5,8,13,21,34
 par = (i%2=0)
 */
#include <stdio.h>

int primo(int n){

    if (n < 2){
        return 0;
    }
    
    for (int i = 2; i*i <= n; i++){
        if (n%i == 0){
            return 0;
        }
    }
    return 1;
}

int main(){

    int n,j; int enc = 0;
    int k = 0; int l = 1;

    printf("Programa que dado un número comprueba y muestra si es primo, fibonacci y par\n");
    printf("Introduce el numero: ");
    scanf("%d",&n);

    printf("El numero %d ",n);

    //checamos si es primo
    if (primo(n)){
        printf("es primo, ");
    }
    else printf("no es primo, ");

    //checamos si es fibonacci
    if(n==0){
        printf("es fibonacci, ");
    }else if(n==1){
        printf("es fibonacci, ");
        }else{
            for(int i=1;i<n;i++){
                j = k + l;
                k = l;
                l = j;
                if(j==n){enc=1;}
            }
            if(enc){
                printf("es fibonacci, ");
            }else{printf("no es fibonacci ");}
            
        }

    //checamos si es par
    if (n%2==0){
        printf("y es par.");
    }else printf("y es impar.");

    return 0;
}