#include <stdio.h>
#include <stdlib.h>
#include  <assert.h>
#define para 2		//控制参数的字符数
char c[para]={'-','c'};	//统计input.txt中的字符数
char w[para]={'-','w'};	//统计input.txt中的单词数
int Statis(FILE *file_read,int *char_count,int *word_count); 
int main(int argc, char* argv[])
{
	int char_count=0,word_count=0;
	char file_name[20], control[para+1];
	FILE *file_read;
	scanf("%s",&control);
	scanf("%s",file_name);//输入信息
    file_read=fopen(file_name,"r");//打开文件
    assert(file_read!=NULL);
    Statis(file_read,&char_count,&word_count);//统计文本字词量
	if(strcmp(control,c) == 0)
		printf("字符数：%d\n",char_count);
	else if(strcmp(control,w) == 0)
		printf("单词数：%d\n",word_count);
    fclose(file_read);//关闭文件 
    system("pause");
    return 0;
}

int Statis(FILE *file_read,int *char_count,int *word_count){
	int flag=0;//间隔标记，处于单词中置1，处于间隔中置0
	char temp_char;
    while( (temp_char=fgetc(file_read)) !=EOF )
    {
         (*char_count)++;
		 if(flag==0 && (temp_char!=' ' || temp_char!=',') ){//处于单词区域中
			(*word_count)++;
			flag=1;
		 }
		 else if(temp_char==' ' || temp_char==',')//处于间隔区域中
			 flag=0;
    }  
	return 0;
}