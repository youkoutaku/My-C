//2~N�̒�����f�����E���o��
//�f�p�ȕ��@

#include <stdio.h>
#include <math.h>

#define Num 1000

int main (void){
    int prinme[Num/2+1];
    int i, n, m=0,Limit;

    for( n=2 ; n <= Num; n++){
        Limit = (int)sqrt( (double)n );
        for(i = Limit; i>1; i--){
            if(n%i == 0){
                break;
            }
        }
        if(i==1){
            prinme[m++]=n;
        } 
    } 

    printf("\n���߂�ꂽ�f��\n");

    for (i = 0; i<m; i++){
        printf("%5d",prinme[i]);
    }
    printf("\n");

    return 0;
}