//   ���[�N���b�h�̌ݏ��@
//(m-n)�̑���ɏ�]�i�������j��p����

#include <stdio.h>

int main (void){
    int a, b, m, n, k;

    printf("��̐�������͂��Ă�������");
    scanf("%d %d", &a, &b);

    m=a; n=b;
    do{
        k=m % n;
        m=n; n=k;
    }while(k!=0);
    printf("�ő����= %d\n", m);

    return 0;
}
