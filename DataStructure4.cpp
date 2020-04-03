// DataStructure4.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

#define LEN sizeof(struct AHash)

typedef struct AHash
{
	int data;
	struct AHash *next;
}STHash;


int main()
{
	//int a=0;
	//int* p;
	int key[] = { 47,7,29,11,16,92,22,8,3,50,37,89 };
	int k;	
	STHash hash[11];
	for (int i = 0; i < 11; i++)
	{
		hash[i].next = NULL;	//Init Hash Table,define nail
	}
	for (int i = 0; i < 12; i++)
	{
		STHash *temp = NULL;
		k=key[i]%11;	//result from 0-10
		if (hash[k].next!=NULL)	//内插
		{
			temp = hash[k].next;
			STHash *p=(STHash*)malloc(LEN);
			p->data = key[i];
			hash[k].next= p;
			p->next=temp;
		}
		else	//新增
		{
			STHash *p=(STHash*)malloc(LEN);
			p->data = key[i];
			hash[k].next= p;
			p->next=NULL;
		}
		//hash[i+1].next->hash[i];
	}
	getchar();
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
