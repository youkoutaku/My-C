#include <stdio.h>

int main( void )
{
  int a;

  for (a=1; a<=5; a++)  {
    printf("------- %d\n", a);
    switch (a)  {
      case 1:   /* a==1 のとき */
        printf("a=1だよ\n");
        break;
      case 3:   /* a==3 のとき */
        printf("a=3だよ\n");
        break;
      case 5:   /* a==5 のとき */
        printf("a=5だよ\n");
        break;
      default:   /* それ以外 */
        printf("その他\n");
    }
  }

  return 0;
}

