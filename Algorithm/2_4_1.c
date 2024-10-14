/*
    ����`�������A
    f(x)=0�̉������߂�B�񕪖@
*/
#include <stdio.h>
#include <math.h>

#define f(x) ((x)*(x)*(x)-(x)+1)
#define EPS 1e-8        //�ł��؂�덷
#define LIMIT 50        //�ł��؂��

int main(void){
    double low, high, x;
    int k;

    low= -2.0; high = 2.0;
    for( k=1; k<=LIMIT; k++){
        x=(low+high)/2;
        if(f(x)>0){
            high = x;
        }else{
            low = x;
        }
        if (f(x)==0 || fabs(high-low)<fabs(low)*EPS){
            printf("x=%lf\n", x);
            break;
        }
    }
    if (k>LIMIT){
        printf("�������Ȃ�\n");
    }
    return 0;
}