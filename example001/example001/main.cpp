#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void GetMemery(char **p, int count){

	printf("形参p所指向的内存地址:%d\n",p);

	printf("形参p本身分配的内存地址:%d\n",&p);

	printf("形参p-2-所指向的内存地址:%d\n",*p);

	printf("形参p-2-本身分配的内存地址:%d\n",p);

	char *tmp = (char *)malloc(sizeof(char)*count);

	*p = tmp;
	
	printf("临时指针tmp所指向的内存地址:%d\n",tmp);
	printf("临时指针tmp被分配的内存地址:%d\n",&tmp);
	

	memset(*p,0,sizeof(char)*count);

}

int main(){

	printf("==============================测试开始==============================\n");

	char *str = (char *)malloc(sizeof(char)*50);

	printf("指针str所指向的内存单元地址:%d\n",str);

	printf("指针str本身分配的内存地址:%d\n",&str);	

	GetMemery(&str,25);

	printf("重新分配后指针str所指向的内存单元地址:%d\n",str);

	printf("重新分配后指针str本身分配的内存地址:%d\n",&str);	

	strcpy(str,"Hello C Program!");
	
	printf("%s\n",str);

	free(str);

	return 0;
}