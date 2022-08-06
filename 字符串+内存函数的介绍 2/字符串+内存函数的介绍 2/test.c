#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<ctype.h>
#include<assert.h>
//1.
//strtok函数

//int main()
//{
//	char a1[] = "abc@112.123";//strtok函数就是找到标记处改为\0
//	char a2[] = "@.";
//	char a3[1024] = { 0 };
//	strcpy(a3, a1);//使用strtok函数一定要把原函数备份，原函数不能被改变
//	printf("%s\n", a3);
//	char* p = strtok(a3, a2);
//	printf("%s\n", p);//第一次把@改为\0返回cahr*-首地址。打印到abc//第一次把@改为\0返回cahr*-首地址。打印到abc
//	p = strtok(NULL, a2);
//	printf("%s\n", p);//第二次从\0那开始数，所以在函数中标记为空指针，直到把.改为\0，返回空指针后的地址
//	p = strtok(NULL, a2);
//	printf("%s\n", p);//第三次从\0那开始数，所以在函数中标记为空指针，直到找到\0，返回空指针后的地址
//	return 0;
//}


//用循环使用strtok函数
//int main()
//{
//	char a1[] = "abc@def.123";
//	char a2[] = "@.";
//	char a3[1024] = { 0 };
//	strcpy(a3, a1);
//	char* ret = NULL;
//	for (ret = strtok(a3, a2); ret != NULL; ret = strtok(NULL, a2))
//	{
//		printf("%s\n", ret);
//	}
//	return 0;
//}


//实现my_strtok
//char* my_strtok(char* p1, char* p2)
//{
//	while (*p1)
//	{
//		if (*p1 == @)
//		{
//			return p1;
//		}
//	}
//}
//int main()
//{
//	char a1[] = "abc@112.123";
//	char a2[] = "@.";
//	char a3[1024] = { 0 };
//	strcpy(a3, a1);
//	char* ret = my_strtok(a3, a2);
//	printf("%s\n", ret);
//	ret = my_strtok(NULL, a2);
//	printf("%s\n", ret);
//	ret = my_strtok(NULL, a2);
//	printf("%s\n", ret);
//	return 0;
//}


//2.
//strerror函数-返回错误码，所对应的错误信息
//需要头文件#include<stdio.h>  #include<string.h>  #include<errno.h>
//int main()
//{
//	printf("%s\n", strerror(0));//No error-没有错误
//	printf("%s\n", strerror(1));//Operation not permitted -操作不允许
//	return 0;
//}

//strerror是一个全局的错误码的变量
//当c语言的库函数在执行的过程中，发生了错误，就会把对应的错误码赋值到erron中
//int main()
//{
//	//strerror通常和erron一起使用
//	char* str = strerror(errno);//errno收录全局变量的错误码，使用errno需要头文件#include<errno.h>
//	printf("%s\n", str);//通过错误码返回地址打印错误信息
//	return 0;
//}

//打开文件 -fopen 他的返回值是一个FILE*的指针
//int main()
//{
//	FILE* wj = fopen("test.txt","r");//"r"叫读文件
//	if (wj == NULL)//返回空指针，打开文件失败
//	{
//		printf("%s\n", strerror(errno));//打印错误原因
//	}
//	else
//	{
//		printf("%s\n", strerror(errno));
//	}
//	return 0;
//}



//3. 字符分类函数
//islower	判断是否为小写字母a-z 是对的返回非零，是假的返回0  返回值是int
//int main()
//{
//	char a = 'w';
//	int ret = islower(a);//他的头文件是  #include<ctype.h>
//	printf("%d\n", ret);//返回2，说明是小写字母
//}
//这里有很多函数，在qq截图里看



//4. 字符转换函数
//tolower-把大写字符转换为小写   toupper-把小写字符转换为大写
//int main()
//{
//	char ret =  tolower('W');
//	printf("%c\n", ret);//w
//	putchar(ret);//输出  w
//	return 0;
//}

//把char a[]="I AM A Student";打印成小写字符
//int main()
//{
//	char a[] = "I AM A Student";
//	printf("%d\n", strlen(a));//14 空格算一个字符
//	int i = 0;
//	while (a[i])
//	{
//		printf("%c", tolower(a[i]));//i am a student 打印的是返回值，不改变char a[]里面的值
//		i++;
//	}
//	printf("\n");
//	printf("%s\n", a);//I AM A Student
//	return 0;
//}

//把char a[]里面的值改成小写
//int main()
//{
//	char a[] = "I AM A Student";
//	int i = 0;
//	while (a[i])
//	{
//		if (isupper(a[i]))
//		{
//			a[i] = tolower(a[i]);
//		}
//		i++;
//	}
//	printf("%s\n", a);//i am a student
//	return 0;
//}


//memcpy -内存函数   void* memcpy(void* dest,void* src, size_t num)   size_t num的意思是字节数
// strcpy是字符串拷贝，只能拷贝字符串
// memcpy能拷贝任何类型
// memmove也可以拷贝任何类型

//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6 };
//	int arr2[6] = { 0 };
//	int i = 0;
//	memcpy(arr2, arr1, 6 * sizeof(int));
//	for (i=0;i<6;i++)
//	{
//		printf("%d\n", arr2[i]);
//	}
//	return 0;
//}


//c语言标准：
// memcpy只要处理 不重叠的内存拷贝就可以 - 我写的my_memcpy就没写到重叠的情况 相当于60分
// memmmove 处理重叠内存拷贝 和不重叠内存拷贝  相当于100分
// 但是memcpy在vs编译器下可以可以实现处理重叠内存拷贝  --注意

//实现my_memcpy
//void* my_memcpy(void* dest, const void* src, size_t num)
//{
//	int j = 1;
//	char* p = (char*)dest;
//	char* q = (char*)src;
//	while(num--)
//	{
//		*p = *q;
//		p++;
//		q++;
//	}
//	return dest;
//}
//
//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6 };
//	int arr2[6] = { 0 };
//	int i = 0;
//	my_memcpy(arr2, arr1,  sizeof(arr1));
//	for (i=0;i<6;i++)
//	{
//		printf("%d\n", arr2[i]);
//	}
//	return 0;
//}


//int main()
//{
//	int a[] = { 1,2,3 };
//	printf("%d\n", sizeof(a));
//	size_t num = sizeof(a);
//	printf("%d\n", num);
//	return 0;
//}


//强制转换成int*
//void* my_memcpy(void* dest, const void* src, size_t num)
//{
//	int* p = (int*)dest;
//	int* q = (int*)src;
//	while (num--)
//	{
//		*p = *q;
//		p++;
//		q++;
//	}
//	return dest;
//}
//
//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6 };
//	int arr2[6] = { 0 };
//	int i = 0;
//	my_memcpy(arr2, arr1, sizeof(arr1)/sizeof(arr1[0]));
//	for (i = 0; i < 6; i++)
//	{
//		printf("%d\n", arr2[i]);
//	}
//	return 0;
//}


//memmove   - void* memcpy(void* dest, void* src, size_t num)   size_t num的意思是字节数
//void* my_memmove(void* dest, const void* src, size_t num)
//{
//	assert(dest && src);
//	char* d = (char*)dest;
//	if (dest < src)
//	{
//		while (num--)
//		{
//			*d = *(char*)src;
//			++d;
//			++(char*)src;
//		}
//	}
//	else
//	{
//		while (num--)
//		{
//			*(d + num) = *((char*)src + num);
//		}
//	}
//	return dest;
//}
//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6 };
//	int arr2[6] = { 0 };
//	int i = 0;
//	my_memmove(arr1+2, arr1, 3*sizeof(arr1[0]));
//	for (i = 0; i < 6; i++)
//	{
//		printf("%d\n", arr1[i]);
//	}
//	return 0;
//}

//my_memmove的第二种实现
//void* my_memmove(void* dest, const void* src, size_t num)
//{
//	assert(dest && src);
//	char* d = (char*)dest;
//	if (dest<src || dest>(char*)src + num)
//	{
//		while (num--)
//		{
//			*d = *(char*)src;
//			--d;
//			--(char*)src;
//		}
//	}
//	else
//	{
//		while (num--)
//		{
//			*(d + num) = *((char*)src + num);
//		}
//	}
//}
//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6 };
//	int arr2[6] = { 0 };
//	int i = 0;
//	my_memmove(arr1 + 2, arr1, 3 * sizeof(arr1[0]));
//	for (i = 0; i < 6; i++)
//	{
//		printf("%d\n", arr1[i]);
//	}
//	return 0;
//}



//memcmp -内存比较函数        strcmp是字符串比较   返回值都是int
//int main()
//{
//	int a[] = { 1,2,3,4,5,6,7 };
// //存进内存1的二进制：000000000000000000000000000000000000001
// //   转换成十六进制: 00 00 00 01存进内存是倒序：01 00 00 00
//	int b[] = { 1,2,3,4,6,8,9 };
//	int ret = memcmp(a, b, 16);  //传16返回0，传17返回-1是因为比较的是内存
//	//01 00 00 00 02 00 00 00 03 00 00 00 04 00 00 00 05 00 00 00 06 00 00 00...
//	//01 00 00 00 02 00 00 00 03 00 00 00 04 00 00 00 06 00 00 00 08 00 00 00...
//	printf("%d\n", ret);
//	return 0;
//}



//memset -内存设置         -设置缓冲区位特定函数
//void*	memset(void* dest,int c,size_t count)  -c是你要设的字符是什么  -count是设置多少个字符 按字节算
//int main()
//{
//	char a[10] = "";
//	memset(a, '#', 5);
//	printf("%s\n", a);//#####
//	return 0;
//}

//int main()
//{
//	int a[10] = { 0 };
//	memset(a, 1, 10);
//	printf("%d\n", a[2]);//257按内存加
//	//00 00 00 00 00 00 00 00 00 00 00 00...
//	//01 01 01 01 01 01 01 01 01 01 00 00...//内存是16进制，内存是倒着存储的，4个为1个字节
//	//最后四个字节在内存中是0101 0000--0101转换为2进制是0000 0001 0000 0001打印出来是十进制257
//	return 0;
//}