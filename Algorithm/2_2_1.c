//���l�ϕ��@��`���ɂ���ϕ��@
// [a~b]f(x) dx = h*( f(a)+f(a+h) )/2 + h*( f(a+h) +f(a+2h) )/2 +...+ h*( f( a+(n-1)h ) + f(b) )/2
// = h*{ ( f(a) + f(b) )/2 + f(a+h) + f(a+2h) + ...+ f( a+(n-1)h ) } 

#include <stdio.h>
#include <math.h>

#define f(x) (sqrt(4-(x)*(x))) //�֐�

int main (void){
    int k;
    double a,b,n,h,x,s,sum;

    printf("�ϕ���ԁ@A, B ?");
    scanf("%lf %lf", &a, &b);

    n=50;  //������
    h=(b-a)/n; //���
    x=a; s=0;
    for(k=1; k <= n-1; k++){
        x=x+h;
        s=s+f(x);
    }
    sum = h*(f(a)+f(b)/2+s);
    printf("    /%f\n",b);
    printf("    |   sqrt(4-x*x) =%f\n", sum);
    printf("    /%f\n",a);

    return 0;
}

