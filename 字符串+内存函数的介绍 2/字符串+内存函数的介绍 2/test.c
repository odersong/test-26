#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<ctype.h>
#include<assert.h>
//1.
//strtok����

//int main()
//{
//	char a1[] = "abc@112.123";//strtok���������ҵ���Ǵ���Ϊ\0
//	char a2[] = "@.";
//	char a3[1024] = { 0 };
//	strcpy(a3, a1);//ʹ��strtok����һ��Ҫ��ԭ�������ݣ�ԭ�������ܱ��ı�
//	printf("%s\n", a3);
//	char* p = strtok(a3, a2);
//	printf("%s\n", p);//��һ�ΰ�@��Ϊ\0����cahr*-�׵�ַ����ӡ��abc//��һ�ΰ�@��Ϊ\0����cahr*-�׵�ַ����ӡ��abc
//	p = strtok(NULL, a2);
//	printf("%s\n", p);//�ڶ��δ�\0�ǿ�ʼ���������ں����б��Ϊ��ָ�룬ֱ����.��Ϊ\0�����ؿ�ָ���ĵ�ַ
//	p = strtok(NULL, a2);
//	printf("%s\n", p);//�����δ�\0�ǿ�ʼ���������ں����б��Ϊ��ָ�룬ֱ���ҵ�\0�����ؿ�ָ���ĵ�ַ
//	return 0;
//}


//��ѭ��ʹ��strtok����
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


//ʵ��my_strtok
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
//strerror����-���ش����룬����Ӧ�Ĵ�����Ϣ
//��Ҫͷ�ļ�#include<stdio.h>  #include<string.h>  #include<errno.h>
//int main()
//{
//	printf("%s\n", strerror(0));//No error-û�д���
//	printf("%s\n", strerror(1));//Operation not permitted -����������
//	return 0;
//}

//strerror��һ��ȫ�ֵĴ�����ı���
//��c���ԵĿ⺯����ִ�еĹ����У������˴��󣬾ͻ�Ѷ�Ӧ�Ĵ����븳ֵ��erron��
//int main()
//{
//	//strerrorͨ����erronһ��ʹ��
//	char* str = strerror(errno);//errno��¼ȫ�ֱ����Ĵ����룬ʹ��errno��Ҫͷ�ļ�#include<errno.h>
//	printf("%s\n", str);//ͨ�������뷵�ص�ַ��ӡ������Ϣ
//	return 0;
//}

//���ļ� -fopen ���ķ���ֵ��һ��FILE*��ָ��
//int main()
//{
//	FILE* wj = fopen("test.txt","r");//"r"�ж��ļ�
//	if (wj == NULL)//���ؿ�ָ�룬���ļ�ʧ��
//	{
//		printf("%s\n", strerror(errno));//��ӡ����ԭ��
//	}
//	else
//	{
//		printf("%s\n", strerror(errno));
//	}
//	return 0;
//}



//3. �ַ����ຯ��
//islower	�ж��Ƿ�ΪСд��ĸa-z �ǶԵķ��ط��㣬�Ǽٵķ���0  ����ֵ��int
//int main()
//{
//	char a = 'w';
//	int ret = islower(a);//����ͷ�ļ���  #include<ctype.h>
//	printf("%d\n", ret);//����2��˵����Сд��ĸ
//}
//�����кܶຯ������qq��ͼ�￴



//4. �ַ�ת������
//tolower-�Ѵ�д�ַ�ת��ΪСд   toupper-��Сд�ַ�ת��Ϊ��д
//int main()
//{
//	char ret =  tolower('W');
//	printf("%c\n", ret);//w
//	putchar(ret);//���  w
//	return 0;
//}

//��char a[]="I AM A Student";��ӡ��Сд�ַ�
//int main()
//{
//	char a[] = "I AM A Student";
//	printf("%d\n", strlen(a));//14 �ո���һ���ַ�
//	int i = 0;
//	while (a[i])
//	{
//		printf("%c", tolower(a[i]));//i am a student ��ӡ���Ƿ���ֵ�����ı�char a[]�����ֵ
//		i++;
//	}
//	printf("\n");
//	printf("%s\n", a);//I AM A Student
//	return 0;
//}

//��char a[]�����ֵ�ĳ�Сд
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


//memcpy -�ڴ溯��   void* memcpy(void* dest,void* src, size_t num)   size_t num����˼���ֽ���
// strcpy���ַ���������ֻ�ܿ����ַ���
// memcpy�ܿ����κ�����
// memmoveҲ���Կ����κ�����

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


//c���Ա�׼��
// memcpyֻҪ���� ���ص����ڴ濽���Ϳ��� - ��д��my_memcpy��ûд���ص������ �൱��60��
// memmmove �����ص��ڴ濽�� �Ͳ��ص��ڴ濽��  �൱��100��
// ����memcpy��vs�������¿��Կ���ʵ�ִ����ص��ڴ濽��  --ע��

//ʵ��my_memcpy
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


//ǿ��ת����int*
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


//memmove   - void* memcpy(void* dest, void* src, size_t num)   size_t num����˼���ֽ���
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

//my_memmove�ĵڶ���ʵ��
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



//memcmp -�ڴ�ȽϺ���        strcmp���ַ����Ƚ�   ����ֵ����int
//int main()
//{
//	int a[] = { 1,2,3,4,5,6,7 };
// //����ڴ�1�Ķ����ƣ�000000000000000000000000000000000000001
// //   ת����ʮ������: 00 00 00 01����ڴ��ǵ���01 00 00 00
//	int b[] = { 1,2,3,4,6,8,9 };
//	int ret = memcmp(a, b, 16);  //��16����0����17����-1����Ϊ�Ƚϵ����ڴ�
//	//01 00 00 00 02 00 00 00 03 00 00 00 04 00 00 00 05 00 00 00 06 00 00 00...
//	//01 00 00 00 02 00 00 00 03 00 00 00 04 00 00 00 06 00 00 00 08 00 00 00...
//	printf("%d\n", ret);
//	return 0;
//}



//memset -�ڴ�����         -���û�����λ�ض�����
//void*	memset(void* dest,int c,size_t count)  -c����Ҫ����ַ���ʲô  -count�����ö��ٸ��ַ� ���ֽ���
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
//	printf("%d\n", a[2]);//257���ڴ��
//	//00 00 00 00 00 00 00 00 00 00 00 00...
//	//01 01 01 01 01 01 01 01 01 01 00 00...//�ڴ���16���ƣ��ڴ��ǵ��Ŵ洢�ģ�4��Ϊ1���ֽ�
//	//����ĸ��ֽ����ڴ�����0101 0000--0101ת��Ϊ2������0000 0001 0000 0001��ӡ������ʮ����257
//	return 0;
//}