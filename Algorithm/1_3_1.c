//���_0�`100�̃f�[�^ 
//�܂��A�O�`�P�O�P�̍s��(juni[100+2])��錾���A����������
//����101�s���1������B���ɒl������Ƃ����1+
//�����āA100~0�̊e�s��ɁA��E�̗v�f�������Ă���
//�Ō�An�̏��ʂ�n+1�s��̒l�ł���B
#include <stdio.h>

#define Num 10
#define Max 100
#define Min 0

int main (void){
    int a[] = {56, 25, 67, 88, 100, 61, 55, 67, 76, 56};
    int i, juni[Max+2];

    for(i=Min; i<=Max; i++){
        juni[i]=0;
    }
    for(i=0; i<=Num; i++){
        juni[a[i]]++;
    }
    juni[Max+1]=1;
    for(i=Max; i>=Min; i--){
        juni[i]+=juni[i+1];
    }
    printf(" ���_�@����\n");
    for (i=0; i<Num; i++){
        printf("%6d%6d\n", a[i], juni[a[i]+1]);
    }
    return 0;
}