/*
    �V�F���E�\�[�g�@���Ǒ}�����P
    gap��N/�Q�������l�Ƃ���
*/

#include <stdio.h>
#include<stdlib.h>

#define N 100

int comps; // ��r��
int swaps; // ������

// ��r�֐�
int comp(int x, int y) {
  ++comps;
  return x > y;
}

// �����֐�
void swap(int* px, int* py) {
  ++swaps;
  int tmp = *px;
  *px = *py;
  *py = tmp;
}

int main(void) {
    int a[N];
    int i,j,k,gap,t;

    for(i=0; i<N; i++){
        a[i]=rand();
    }

    comps = 0;
    swaps = 0;

    gap=N/2;
    while(gap>0){
        for(k=0; k<gap; k++){
            for (i=k+gap; i<N; i+=gap) {
                for (j=i-gap; j>=k; j-=gap){
                    if ( comp(a[j], a[j+gap]) > 0 ) { // �����Ŕ�r
                        swap(&a[j], &a[j+gap]); // �����Ō���
                        //printf("%d %d %d %d %d %d\n", a[0],a[1],a[2],a[3],a[4],a[5]);
                    }else{
                        break;
                    }
                }
            }
        }
        gap/=2;
    }

    for (i=0;i<N;i++)
        printf("%d ",a[i]);
    printf("\n");

    printf("%d comps / %d swaps\n", comps, swaps);
    return 0;
}