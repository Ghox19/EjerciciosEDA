#include <stdio.h>
//recursivo//
int fibonaccir(int n){
    int num;
    if (n == 0 || n == 1){
        return n;
    }
    else{
        num = fibonaccir(n-1)+fibonaccir(n-2);
        return num;
    }
}
//iterativo//
int fibonaccii(int n){
    int temp;
    int n1 = 0, n2 = 1;
    for (int i = 1; i < n; i++){
        temp = n1 + n2;
        n1 = n2;
        n2 = temp;
    }
    return temp;
}

int main(){
    int n, res1, res2;
    printf("Escribe el numero para fibonacci: ");
    scanf("%d",&n);
    res1 = fibonaccir(n);
    res2 = fibonaccii(n);
    printf("%d\n",res1);
    printf("%d",res2);
    return 0;
}