/*
    �V�F���E�\�[�g�@���Ǒ}�����Q
    gap�͂��݂��ɑf���ł���΁A�����I�ł���B
    O(n^1.25)
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
    int i,j,gap;

    for(i=0; i<N; i++){
        a[i]=rand();
    }

    comps = 0;
    swaps = 0;

    for(gap=1; gap<N/3; gap=3*gap+1);

    while(gap>0){
        for (i=gap; i<N; i++) {
            for (j=i-gap; j>=0; j-=gap){
                if ( comp(a[j], a[j+gap]) > 0 ) { // �����Ŕ�r
                    swap(&a[j], &a[j+gap]); // �����Ō���
                    //printf("%d %d %d %d %d %d\n", a[0],a[1],a[2],a[3],a[4],a[5]);
                }else{                            
                    break;
                }
            }
        }
        gap/=3;
    }


    for (i=0;i<N;i++)
        printf("%d ",a[i]);
    printf("\n");

    printf("%d comps / %d swaps\n", comps, swaps);
    return 0;
}