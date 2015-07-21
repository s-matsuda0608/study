#include<String>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

using namespace std;

//配列の大きさ
#define SIZE 4

int main(){
	
	//乱数使うためのやつ(?)
	srand(time(NULL));

	//基準文字列
	string str[SIZE] = {"進捗","どう","です","か？"};
	
	string array[SIZE] = {"","","",""};
	
	int complete = 0;//文字列が完成したかどうかのフラグ
	int count = 0;//whileループ回数カウンタ
	
	printf("\n「進捗どうですか？」プログラム\n\n");
	
	
	//「進捗どうですか？」が揃うまでループ
	while(complete==0){
		
		//arrayの中身を一つ左にずらす
		for(int i=0; i < SIZE-1; i++){
			array[i] = array[i+1];
		}
		
		//配列の一番後ろに基準文字列の中からランダムで挿入
		array[SIZE-1] = str[rand()%SIZE];
		
		printf("%s ",array[SIZE-1].c_str());
		
		
		//文字列完成フラグを「1」にする
		complete = 1;
		
		//文字列が完成していなかったら完成フラグを「0」に戻す
		for(int i=0;i<SIZE;i++){
			if(array[i]!=str[i]){
				complete = 0;
			}
		}
		
		count++;
		
	}//whileループ終わり
	
	
	printf("\n\n進捗 どう です か？\n\n");
	
	printf("%d 回目で煽られました。",count);
	
	return 0;
}