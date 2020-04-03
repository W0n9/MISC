// DataStructure1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<stdio.h>
#include<stdlib.h>
#define List_Init_Size 100//空间初始分配量; 
#define Listcreate 10//空间分配的增量;

#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;
typedef int Elemtype;

typedef struct {
	Elemtype* elem;//存储空间的首地址; 
	int length;//当前的表长; 
	int listsize;//容量; 
}List;

//初始化空表; 
Status Init_list(List &L)//涉及改变内容,采用引用传递; 
{
	L.elem = (Elemtype*)malloc(List_Init_Size * sizeof(Elemtype));
	if (!L.elem)//内存分配失败; 
	{
		exit(OVERFLOW);
	}
	L.length = 0;//空表;
	L.listsize = List_Init_Size;
	return OK;
}

Status add_elem(List& L, int i, Elemtype e)//插入位置和元素的值; 
{
	//1.判断位置是否合法;
	//2.看有没有超出空间,若有,用realloc增加空间;
	//3.从最后一个元素到第i+1个元素都向后移,标记长度--;
	printf("Please insert from location 1 to %d", L.length + 1);
	if (i<1 || i>L.length + 1)//插入的位置只能是1-(n+1); 
	{
		printf("location%dillgeal\n", i);
		return ERROR;
	}
	if (L.length >= L.listsize)//若当前空间已满,增加空间; 
	{
		Elemtype* address = (Elemtype*)realloc(L.elem, (L.listsize + Listcreate) * sizeof(Elemtype));
		//realloc函数用法:新地址=(声明指针的类型)realloc(原指针名,改变后的大小);
		//该操作有两种方式:1.若原空间还够用,则直接改变原空间的大小;
		//2.若原空间已经不够用了,则开辟一块新空间,将原来的所有存储值拷贝过去,返回会新的首地址; 
		if (!address)//内容增加失败; 
		{
			exit(OVERFLOW);
		}
		L.elem = address;
		L.listsize += Listcreate;
	}
	Elemtype* where = &(L.elem[i - 1]);//取其地址;
	Elemtype* p;
	for (p = &(L.elem[L.length - 1]); p >= where; p--)//将所插入位置后面的所有数后移; 
	{
		*(p + 1) = *p;
	}
	*where = e;
	L.length++;//元素数+1;
	return OK;
}

Status add_elem_array(List& L, int i, Elemtype e[],int ez)//插入位置和元素的值; 
{
	//1.判断位置是否合法;
	//2.看有没有超出空间,若有,用realloc增加空间;
	//3.从最后一个元素到第i+1个元素都向后移,标记长度--;
	printf("Please insert from location 1 to %d", L.length + 1);
	if (i<1 || i>L.length + 1)//插入的位置只能是1-(n+1); 
	{
		printf("location%dillgeal\n", i);
		return ERROR;
	}
	if (L.length+ez >= L.listsize)//若当前空间已满,增加空间; 
	{
		Elemtype* address = (Elemtype*)realloc(L.elem, (L.listsize + Listcreate*ez) * sizeof(Elemtype));
		//realloc函数用法:新地址=(声明指针的类型)realloc(原指针名,改变后的大小);
		//该操作有两种方式:1.若原空间还够用,则直接改变原空间的大小;
		//2.若原空间已经不够用了,则开辟一块新空间,将原来的所有存储值拷贝过去,返回会新的首地址; 
		if (!address)//内容增加失败; 
		{
			exit(OVERFLOW);
		}
		L.elem = address;
		L.listsize += Listcreate;
	}
	Elemtype* where = &(L.elem[i - 1]);//取其地址;
	Elemtype* p;
	for (p = &(L.elem[L.length - 1]); p >= where; p--)//将所插入位置后面的所有数后移; 
	{
		*(p + ez) = *p;
	}
	for (int i = 0; i < ez; i++)
	{
		where[i] = e[i];
	}
	L.length=L.length+ez;//元素数+1;
	return OK;
}

Status sub_elem(List& L, int i, Elemtype& e)//删除i位置的元素,并用e返回其值; 
{
	//1.判断位置是否合法;
	//2.若合法,将删除位置+1的元素到最后的元素都往前移,标记长度--; 
	if (i<1 || i>L.length)
	{
		return ERROR;
	}
	Elemtype* p1;
	Elemtype* p2;
	p1 = &(L.elem[i - 1]);
	e = *p1;
	p2 = &(L.elem[L.length - 1]);
	for (p1 = p1 + 1; p1 <= p2; p1++)
	{
		*(p1 - 1) = *p1;
	}
	L.length--;
	return OK;
}

Status del_elem_array(List& L, int i, int ez, Elemtype& e)//删除i位置的元素,并用e返回其值; 
{
	//1.判断位置是否合法;
	//2.若合法,将删除位置+1的元素到最后的元素都往前移,标记长度--; 
	if (i<1 || i>L.length||i+ez>=L.length)
	{
		printf("location%dillgeal\n", i);
		return ERROR;
	}
	Elemtype* p1;
	Elemtype* p2;
	p1 = &(L.elem[i - ez]);
	e = *p1;
	p2 = &(L.elem[L.length - ez]);
	/*for (int j = 0; j < ez; j++)
	{
		*(p1) = *(p1 - ez);
		p1++;
	}*/
	int j = 0;
	for (p1 = p1 + 1; p1 <= p2; p1++)
	{
		*(p1 - ez) = *p1;
	}
	L.length = L.length - ez;
	return OK;
}

Status get_all_elem(List L)
{
	printf("该序列的所有元素分别为:\n");
	Elemtype* q1;
	Elemtype* q2;
	q1 = &(L.elem[0]);
	q2 = &(L.elem[L.length - 1]);
	while (q1 <= q2)
	{
		printf("%d ", *q1);
		q1++;
	}
	printf("\n");
	return OK;
}

int main()
{
	int j;
	List L;
	int e;
	int earray[15] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	Init_list(L);
	add_elem_array(L, 1, earray, 15);
	get_all_elem(L);
	del_elem_array(L, 7, 2, e);
	//printf("请插入5个元素(合法的任意位置均可):\n");
	/*for (i = 1; i <= 5; i++)
	{
		printf("请输入要插入的位置和元素值:\n");
		scanf_s("%d %d", &j, &a);
		add_elem(L, j, a);
	}*/
	get_all_elem(L);
	printf("\n");

	get_all_elem(L);

	printf("请输入要删除元素的位置:\n");
	scanf_s("%d",&j);
	sub_elem(L, j, e);
	printf("所删除的值为: %d\n\n", e);
	

	printf("删除后:\n");
	get_all_elem(L);
	return 0;
}


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
