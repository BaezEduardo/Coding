#include <stdio.h>

int main(){

    int a = 0, b = 1;
    int n,j;

    printf("Programa que da el n_esimo termino de la serie de Fibonacci\n");
    printf("Dame n: ");
    scanf("%d",&n);

    if(n==0){
        printf("\nEl numero en la posicion %d en la serie de Fibonacci es: %d",n,a);
    }else if(n==1){
        printf("\nEl numero en la posicion %d en la serie de Fibonacci es: %d",n,b);
        }else{
            for(int i=1;i<n;i++){
                j = a + b;
                a = b;
                b = j;
            }
            printf("\nEl numero en la posicion %d en la serie de Fibonacci es: %d",n,j);
        }
        
    return 0;
}