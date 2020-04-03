// DataStructure2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

#define FSIZE 100          //  能存储的数据的多少
#define STEPSIZE 50
#define TRUE 1               //  宏定义，将TRUE 定义为1 
#define FALSE 0 			//  将FALSE 定义为0
#define NULL 0

typedef struct _stack {
	int *data; 		//  存储数据的栈  
	int top;				//  栈的标志，相当于输入或输出数组时，用的for循环中的 计数器 i 。
	int size;
}Stack, * Pstack;				//  一个为结构体类型，一个为指针类型

Pstack Init_stack(Pstack stack) {
	stack = (Pstack)malloc(sizeof(Stack));		//  为栈从堆中开辟内存空间
	if (stack == NULL||stack->data == NULL)
	{						//  开辟内存失败的话，返回空内存 NULL
		printf("Malloc Error.\n");
		return NULL;
	}
	else {
		stack->top = -1;						//  开辟成功的话，标志为 -1 ，为什么会定义为 -1 ，后面会讲到
	}
	stack->data = (int*)malloc(sizeof(int) * FSIZE);
	stack->size = FSIZE;
	return stack;
}

Pstack Add_stepsize(Pstack stack)
{
	int size = stack->size;
	if (stack->data != NULL) free(stack->data);
	if (stack != NULL) free(stack);
	stack = (Pstack)malloc(sizeof(Stack));		//  为栈从堆中开辟内存空间
	stack->data = (int*)malloc(sizeof(int) * (size + STEPSIZE));
	if (stack == NULL || stack->data == NULL)
	{						                    //  开辟内存失败的话，返回空内存 NULL
		printf("Malloc Error.\n");
		return NULL;
	}
	else
	{
		stack->top = -1;						//  开辟成功的话，标志为 -1 ，为什么会定义为 -1 ，后面会讲到
	}
	stack->size = size + STEPSIZE;
	return stack;
}

int Is_Init(Pstack stack) {
	if (stack == NULL) {                 //  若为空，显示为空
		return 1;
	}
	else {
		return 0;								//  不为空，显示不为空
		//printf("The stack is filled.\n");
	}
}

void Is_Empty(Pstack stack) {
	if (stack->top == -1) {                 //  若为空，显示为空
		printf("The stack is empty.\n");
	}
	else {								//  不为空，显示不为空
		printf("The stack is filled.\n");
	}
}

/*Pstack Push(Pstack stack) {
	if (stack->top == FSIZE) {                //  西安判断栈是否满，满了之后就不能再向栈中输入元素
		printf("Stack is filled up.\n");
		return FALSE;                        //   栈满
	}
	int num = 0;                        //  输入要入栈的元素
	printf("Input the number you want to push: ");
	scanf_s("%d", &num);
	stack->top++;							//  每向入栈一个元素，标签的值加一
	stack->data[stack->top] = num;			//	 将输入的元素压入栈中
	return stack;
}*/

int Push_elem(Pstack stack,int elem) 
{
	if (stack->top == stack->size) {                //  西安判断栈是否满，满了之后就不能再向栈中输入元素
		printf("Stack is filled up.\n");
		return FALSE;                        //   栈满
	}
	int num = 0;                        //  输入要入栈的元素
	num = elem;
	stack->top++;							//  每向入栈一个元素，标签的值加一
	stack->data[stack->top] = num;			//	 将输入的元素压入栈中
	return TRUE;
}

int Pop(Pstack stack) 
{
	int cur = 0;
	if (stack->top == -1) 
	{                   	//  判断栈是否为空，若为空栈，则无法将有效元素出栈
		printf("Empty stack.\n");
		return NULL;
	}
	cur = stack->top;
	//stack->data[stack->top];				//  将栈顶的元素压出栈
	stack->top--;						//  标志减一
	return stack->data[cur];
}

int Output(Pstack stack, int num);

void Illustrate(Pstack stack) {
	printf("Amount of Valuable elments is: %d\n", stack->top + 1);		//  输出栈中的有效元素个数
	int count = stack->top+1;						//  将栈的标志信息赋给计数器
	Output(stack,count);
	/*for (int i = 0; i < count + 1; i++) {
		printf("The %dth element is %d.\n", i + 1, stack->data[i]);			//  输出栈中的所有元素
	}*/
}

int Output(Pstack stack,int num) 
{
	int total = stack->top + 1;
	if (num > total)
	{
		printf("Amount of Valuable elments is only: %d\n", total);
		return FALSE;
	}
	//printf("Amount of Valuable elments is: %d\n", stack->top + 1);		//  输出栈中的有效元素个数
	int count = num;						//  将栈的标志信息赋给计数器
	for (int i = 0; i < num; i++) {
		printf("The %dth element is %d.\n", i + 1, stack->data[i]);			//  输出栈中的所有元素
	}
	return TRUE;
}

int Get_top(Pstack stack) {
	if (stack->top == -1) {			//  若为空栈，则无法输出有效栈顶元素
		return FALSE;
	}
	return stack->data[stack->top];		//  返回栈顶的元素
}

int main() 
{
	Pstack stack_a = NULL;               //  定义一个空栈
	if (Is_Init(stack_a))
	{
		printf("Initialized!\n");
	}
	else
	{
		printf("Not Initialized!\n");
	}
	stack_a = Init_stack(stack_a);              //  将栈初始化	
	Is_Empty(stack_a);           		//  判断栈是否为空
	printf("Input the amount of elements: ");        //  向栈中压入几个元素
	int dat[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int amount = 99;
	//scanf_s("%d", &amount);
	for (int i = 0; i < amount; i++) {
		Push_elem(stack_a,i);
	}
	Is_Empty(stack_a);                  //  判断是否为空栈
	Illustrate(stack_a); 				//  输出栈中的元素
	printf("Top element: %d\n", Get_top(stack_a));
	//Pop(stack_a);           //  出栈操作
	//Illustrate(stack_a);
	int cur_data=0;
	for (int i = 0; i < amount; i++)
	{
		cur_data = Pop(stack_a);
		printf("The %dth pop element is %d.\n", i+1, cur_data);
	}
	
	//system("pause");
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
