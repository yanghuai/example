#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void GetMemery(char *p, int count){
	printf("形参p所指向的内存地址:%d\n",p);
	printf("形参p本身分配的内存地址:%d\n",&p);
	
	p = (char *)malloc(sizeof(char)*count);

	printf("形参p重新分配内存后所指向的内存地址:%d\n",p);
	printf("形参p重新分配内存后本身分配的内存地址:%d\n",&p);
}

int main(){

	printf("==============================测试开始==============================\n");

	char *str = (char *)malloc(sizeof(char)*50);

	printf("指针str所指向的内存单元地址:%d\n",str);

	printf("指针str本身分配的内存地址:%d\n",&str);	

	GetMemery(str,25);

	printf("分配后指针str所指向的内存单元地址:%d\n",str);

	printf("分配后指针str本身分配的内存地址:%d\n",&str);		 

	return 0;
}