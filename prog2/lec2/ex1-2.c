/*------------------------------------------------------------------*/
/*      		 			　<ex1-2.c>							    */
/*　　　　約数を列挙するプログラム（for文）(タブ4） 　　　　　	    */
/*-----------------------------------------------------------------	*/
#include <stdio.h>

int main(void)
{
	int i,n;
	int sum=0;

	printf("整数値:"); scanf("%d", &n);

	for( i = 1; i <= n; i++ )
		if(n%i==0){				//iがnの約数なら
			sum+=i;
			printf("%d ", i);	//iを表示
		}
	/*if(sum-n==n){
		printf("完全数である%d。",sum-n);
	}else{
		printf("完全数ではない%d。",sum-n);
	}*/


	return 0;
}