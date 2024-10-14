/*
    ����`�������A
    f(x)=0�̉������߂�B�j���[�g���@
    e
*/
#include <stdio.h>
#include <math.h>

#define f(x) ((x)*(x)*(x)-(x)+1)
#define g(x) (3*(x)*(x)-1)
#define EPS 1e-8        //�ł��؂�덷
#define LIMIT 50        //�ł��؂��

int main(void){
    double x=-2.0,dx;
    int k;

    for(k=1; k<=LIMIT; k++){
        dx=x;
        x=x-f(x)/g(x);
        if (fabs(x-dx)<fabs(dx)*EPS){
            printf("x=%lf\n",x);
            break;
        }
    }
    if (k>LIMIT){
        printf("�������Ȃ�\n");
    }
    return 0;
}