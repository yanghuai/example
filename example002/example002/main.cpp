#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void GetMemery(char *p, int count){
	printf("�β�p��ָ����ڴ��ַ:%d\n",p);
	printf("�β�p���������ڴ��ַ:%d\n",&p);
	
	p = (char *)malloc(sizeof(char)*count);

	printf("�β�p���·����ڴ����ָ����ڴ��ַ:%d\n",p);
	printf("�β�p���·����ڴ���������ڴ��ַ:%d\n",&p);
}

int main(){

	printf("==============================���Կ�ʼ==============================\n");

	char *str = (char *)malloc(sizeof(char)*50);

	printf("ָ��str��ָ����ڴ浥Ԫ��ַ:%d\n",str);

	printf("ָ��str���������ڴ��ַ:%d\n",&str);	

	GetMemery(str,25);

	printf("�����ָ��str��ָ����ڴ浥Ԫ��ַ:%d\n",str);

	printf("�����ָ��str���������ڴ��ַ:%d\n",&str);		 

	return 0;
}