#include <stdio.h>
#include <stdlib.h>
#include  <assert.h>
#define para 2		//���Ʋ������ַ���
char c[para]={'-','c'};	//ͳ��input.txt�е��ַ���
char w[para]={'-','w'};	//ͳ��input.txt�еĵ�����
int Statis(FILE *file_read,int *char_count,int *word_count); 
int main(int argc, char* argv[])
{
	int char_count=0,word_count=0;
	char file_name[20], control[para+1];
	FILE *file_read;
	scanf("%s",&control);
	scanf("%s",file_name);//������Ϣ
    file_read=fopen(file_name,"r");//���ļ�
    assert(file_read!=NULL);
    Statis(file_read,&char_count,&word_count);//ͳ���ı��ִ���
	if(strcmp(control,c) == 0)
		printf("�ַ�����%d\n",char_count);
	else if(strcmp(control,w) == 0)
		printf("��������%d\n",word_count);
    fclose(file_read);//�ر��ļ� 
    system("pause");
    return 0;
}

int Statis(FILE *file_read,int *char_count,int *word_count){
	int flag=0;//�����ǣ����ڵ�������1�����ڼ������0
	char temp_char;
    while( (temp_char=fgetc(file_read)) !=EOF )
    {
         (*char_count)++;
		 if(flag==0 && (temp_char!=' ' || temp_char!=',') ){//���ڵ���������
			(*word_count)++;
			flag=1;
		 }
		 else if(temp_char==' ' || temp_char==',')//���ڼ��������
			 flag=0;
    }  
	return 0;
}