/*------------------------------------------------------------------*/
/*      		 			　　<ex5-5.c>	　　					*/
/*　　　　　構造体の配列を渡す関数のプログラム例（ポインタ表現）　　*/
/*          ファイルから得点データを読み込み、成績評価と共に        */
/*          画面に出力する（成績の降順に並び替え:ポインタ配列)      */
/* （注意）エディタのタブの文字数を「４」に設定するとずれません     */
/*-----------------------------------------------------------------	*/
#include <stdio.h>
#include <stdlib.h> //for exit()
#include <string.h>
#define SNUM 5

//Prog2型の宣言（関数のプロトタイプ宣言の前に行う）
typedef struct{
	int 	ID;			//学生番号
	char    name[20];	//名前
	int		final;		//期末試験得点
	double	mini;		//小テスト得点
	double	rpt;		//レポート得点
	double	score;		//総合得点
	char	grade[3];	//成績評価
} Prog2;

//関数のプロトタイプ宣言
void load_data(char *fname, Prog2 *obj);
void grade_eval(Prog2 *obj);
void sort_data(Prog2 *obj);

int main(void)
{
	char	fname[]="record_25.txt";//入力ファイル名
	Prog2 Mech[SNUM]={0};			//学生データ用配列

	load_data(fname, Mech);	//成績データの読み込み

	grade_eval(Mech);	//成績評価

	sort_data(Mech);	//成績の降順に並び替えて表示

	return 0;
}
/*----------------------------------------------------------------------*/
/*      関数名：load_data                                               */
/*		仮引数：char型へのポインタfname, Prog2型へのポインタobj　　   　*/
/*		戻り値:なし　　　　　　　　　　　　　　　　　　　　 　　　　　　*/
/*      機　能：fnameで指定されたファイルからデータを読み込み配列 Mech  */
/*            　の各メンバに格納する                                    */
/*----------------------------------------------------------------------*/
void load_data(char *fname, Prog2 *obj)
{
	FILE	*fp;		//ファイルポインタ
	int		i=0;		//カウンタ
	char	temp[256];	//インデックス行読み込みバッファ用配列

	//入力ファイルのオープン（読み込みモード）
	fp=fopen(fname,"r");
	if(fp==NULL){
		printf("Can't open %s!\n",fname);
		exit(1);	//強制終了
	}
	
	fgets(temp,256,fp);//インデックス部一行を配列tempに吐き出す
	
	//入力ファイルからデータの読み込み
	while(fscanf(fp,"%d%s%lf%lf%d", &(obj+i)->ID, (obj+i)->name,
		&(obj+i)->mini, &(obj+i)->rpt, &(obj+i)->final)!=EOF){ i++; }

	fclose(fp);	//入力ファイルのクローズ
}
/*----------------------------------------------------------------------*/
/*      関数名：grade_eval                                              */
/*		引  数：Prgog2型へのポインタobj　　　 　　　　　　　　　　　　　*/
/*		戻り値: なし             　　　　　　　　　　　　　 　　　　　　*/
/*      機能：各学生の総合得点の計算、成績評価                        　*/
/*----------------------------------------------------------------------*/
void grade_eval(Prog2 *obj)
{
	int		i;			//カウンタ

	for(i=0;i<SNUM;i++){
		(obj+i)->score=(obj+i)->mini+(obj+i)->rpt+(obj+i)->final;	//総合得点

		//成績判定（A+〜D)
		if((obj+i)->score>=90)	strcpy((obj+i)->grade, "A+");
		else if((obj+i)->score>=80) strcpy((obj+i)->grade, "A");
		else if((obj+i)->score>=70) strcpy((obj+i)->grade, "B");
		else if((obj+i)->score>=60) strcpy((obj+i)->grade, "C");
		else	strcpy((obj+i)->grade, "D");	
	}
}
/*----------------------------------------------------------------------*/
/*      関数名：sort_data                                               */
/*		引  数：Prgog2型へのポインタobj　　　 　　　　　　　　　　　　　*/
/*		戻り値: なし             　　　　　　　　　　　　　 　　　　　　*/
/*      機能：総合得点の降順にデータの並び替え計算（ポインタ配列利用）、*/
/*            結果の表示        　                                      */
/*----------------------------------------------------------------------*/
void sort_data(Prog2 *obj)
{
	int		i,j;				//カウンタ
	Prog2	*wkp,				//一時保存用ポインタ
			*p[SNUM]={NULL};	//ソート情報を格納するポインタ配列

	//i番目の配列要素の先頭のアドレスをp[i]に格納する
	for(i=0;i<SNUM;i++)	p[i]=obj+i;

	//成績の降順に並び替え
	for(i=0;i<SNUM-1;i++){		/* i=0(最初のデータ)からi=SNUM-2まで繰り返す */
		for(j=i+1;j<SNUM;j++){/* j=i+1からj=SNUM-1(最後のデータ)まで繰り返す */
			if(p[i]->score<p[j]->score){	//もしp[i]->score<p[j]->scoreなら
				//ポインタ配列要素p[i]とp[j]の交換
				wkp=p[i];
				p[i]=p[j];
				p[j]=wkp;
			}
		}
	}

	//学生番号、項目別得点、総合得点、評価の表示
	printf("%-10s%-19s%10s%10s%10s%10s%10s\n","ID", "Name",
           "Mini", "Report", "Final", "Total", "Grade");

	for(i=0;i<SNUM;i++){
		//成績評価出力
		printf("%-10d%-19s%10.1f%10.1f%10d%10.1f%10s\n", p[i]->ID,
        	p[i]->name, p[i]->mini, p[i]->rpt, p[i]->final,
			p[i]->score, p[i]->grade);
	}
}

