#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void GetMemery(char **p, int count){

	printf("�β�p��ָ����ڴ��ַ:%d\n",p);

	printf("�β�p���������ڴ��ַ:%d\n",&p);

	printf("�β�p-2-��ָ����ڴ��ַ:%d\n",*p);

	printf("�β�p-2-���������ڴ��ַ:%d\n",p);

	char *tmp = (char *)malloc(sizeof(char)*count);

	*p = tmp;
	
	printf("��ʱָ��tmp��ָ����ڴ��ַ:%d\n",tmp);
	printf("��ʱָ��tmp��������ڴ��ַ:%d\n",&tmp);
	

	memset(*p,0,sizeof(char)*count);

}

int main(){

	printf("==============================���Կ�ʼ==============================\n");

	char *str = (char *)malloc(sizeof(char)*50);

	printf("ָ��str��ָ����ڴ浥Ԫ��ַ:%d\n",str);

	printf("ָ��str���������ڴ��ַ:%d\n",&str);	

	GetMemery(&str,25);

	printf("���·����ָ��str��ָ����ڴ浥Ԫ��ַ:%d\n",str);

	printf("���·����ָ��str���������ڴ��ַ:%d\n",&str);	

	strcpy(str,"Hello C Program!");
	
	printf("%s\n",str);

	free(str);

	return 0;
}