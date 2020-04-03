// DataStructure3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

#include <stdlib.h>

#define  MAXSIZE 100
//二叉树结点的结构体表示形式
typedef struct BitNode
{
	char    data;
	struct BitNode* left, * right;
	int ltag, rtag;
	//struct BitNode *lindex,*rindex;
}BitTree, * BitTree1;

BitTree* pre;
BitTree1 pre1;
//BitTree1 p1;
//BitTree1 Root;

// typedef struct Array
// {
// 	char    data;
// 	BitTree *p;
// }Arrayindex;

//栈的结构体表示形式
typedef struct stackelem
{
	BitTree* a[MAXSIZE];
	int top;
}Stack;

//队列的结构体的表示形式
typedef struct queueelem
{
	BitTree* b[MAXSIZE];
	int front, rear;
}Queue;

//创建二叉树，利用递归的方法
//按前序次序输入。 如 A # #(#表示空树)
BitTree* Create()
{
	char ch;
	scanf_s("%c", &ch,sizeof(ch));
	getchar();    //吃掉空格符
	if (ch == '#')
	{
		return NULL;
	}
	else
	{
		BitTree* btree = (BitTree*)malloc(sizeof(BitTree));
		if (NULL == btree)
		{
			return NULL;
		}
		btree->data = ch;
		btree->left = Create();
		btree->right = Create();
		return btree;
	}
}

BitTree* CreateBySeq(char *clist,int a,int seq)
{
	//return NULL;
	if (clist[seq] == '#' || seq >= a)
	{
		return NULL;
	}
	else
		{
			BitTree* btree = (BitTree*)malloc(sizeof(BitTree));
			if (NULL == btree)
			{
				return NULL;
			}
			btree->data = clist[seq];
			// btree->lindex = CreateBySeq(clist,a,1);
			// btree->rindex = CreateBySeq(clist,a,1);
			btree->left = CreateBySeq(clist,a,seq * 2 + 1);
			btree->right = CreateBySeq(clist, a, seq * 2 + 2);
			btree->ltag = 0;
			btree->rtag = 0;
			//btree->lindex = NULL;
			//btree->rindex = NULL;
			// if (clist[seq*2+1] == '#' || seq >= a)
			// {
			// 	btree->ltag=1;
			// }
			// else
			// {
			// 	btree->ltag=0;
			// }
			// if (clist[seq*2+2] == '#' || seq >= a)
			// {
			// 	btree->rtag=1;
			// }
			// else
			// {
			// 	btree->rtag=0;
			// }


			// if (btree->ltag == 1 && btree->rtag ==1)
			// {
			// 	if ()
			// 	{
			// 		/* code */
			// 	}
				
			// }
			
			return btree;
		}
	}


BitTree* CreateEmpty(BitTree* btr2)//创建树
{
	BitNode* node = (BitNode*)malloc(sizeof(BitNode));//创建一个节点
	node->data = NULL;
	node->left = btr2;
	node->right = node;
	node->ltag = 0;
	node->rtag = 0;
	return node;
}


//前序遍历，递归的方法
void Preorder(BitTree* bt)
{
	if (NULL != bt)
	{
		printf("%c ", bt->data);
		Preorder(bt->left);
		Preorder(bt->right);
	}
}

//前序遍历的非递归实现
/*
 思想：利用栈来实现；根结点进栈，之后栈非空，弹出，接着根节点的右结点进栈，之后，左节点进栈；接着，弹出栈顶元素（输出）,
 此结点的右结点进栈，之后左节点进栈，弹出栈顶元素（输出）...一直这样下去，直到栈为空。
 */
void Preorder2(BitTree* bt)
{
	BitTree* p;
	Stack st;
	st.top = -1;
	if (NULL == bt)
	{
		return;
	}
	else
	{
		st.top++;
		st.a[st.top] = bt;
		while (st.top != -1)
		{
			p = st.a[st.top];
			st.top--;
			printf("%c ", p->data);
			if (p->right != NULL)
			{
				st.top++;
				st.a[st.top] = p->right;
			}
			if (p->left != NULL)	//后进先出
			{
				st.top++;
				st.a[st.top] = p->left;
			}
		}
	}
}

void Preorder3(BitTree* bt)
{
	BitTree* p;
	Stack st;
	st.top = -1;
	if (NULL == bt)
	{
		return;
	}
	else
	{
		st.top++;
		st.a[st.top] = bt;
		for (; st.top != -1; )
		{
			p = st.a[st.top], st.top--;
			printf("%c ", p->data);
			if (p->right != NULL)
			{
				st.top++;
				st.a[st.top] = p->right;
			}
			if (p->left != NULL)	//后进先出
			{
				st.top++;
				st.a[st.top] = p->left;
			}
		}
	}
}

void Preorder4(BitTree* bt)
{
	BitTree* p;
	Stack st;
	st.top = -1;
	if (NULL == bt)
	{
		return;
	}
	else
	{
		st.top++;
		st.a[st.top] = bt;
		do	//©2019 黄聪颖 版权所有
		{
			p = st.a[st.top];
			st.top--;
			printf("%c ", p->data);
			switch (p->right == NULL)
			{
			case 0:
				st.top++;
				st.a[st.top] = p->right;
			default:
				break;
			}
			switch (p->left == NULL)
			{
			case 0:
				st.top++;
				st.a[st.top] = p->left;
			default:
				break;
			}
		} while (st.top != -1);
	}
}


//中序遍历，递归实现
void Inorder(BitTree* bt)
{
	if (NULL != bt)
	{
		Inorder(bt->left);
		printf("%c ", bt->data);
		Inorder(bt->right);
	}
}

void InThreading(BitTree *p)
{
	if (p) 
	{
		InThreading(p->left);
		if (!p->left)
		{
			p->ltag = 1;
			p->left = pre;
		}
		if (pre != NULL && pre->right == NULL)
		{
			pre->rtag = 1;
			pre->right = p;
		}
		pre = p;
		InThreading(p->right);
	}
}

void InThreading1(BitTree1 p1,BitTree1 R)
{

	if (p1)
	{
		if (pre1 == R||p1 == R)
			return;
		InThreading1(p1->left,R);
		if (!p1->left)
		{
			p1->ltag = 1;
			p1->left = pre1;
		}
		if (pre1->right == NULL)
		{
			pre1->rtag = 1;
			pre1->right = p1;
		}
		pre1 = p1;
		InThreading1(p1->right,R);
	}
	
}

void InOrderThreading(BitTree1& Root, BitTree1 T)
{
	Root->ltag = 0;
	Root->rtag = 1;
	Root->right = Root;
	if (NULL == T)
		Root->left = Root;
	else
	{
		Root->left = T;
		pre1 = Root;
		InThreading1(T,Root);
		pre1->right = Root;
		pre1->rtag = 1;
		Root->right = pre1;
	}
}

// void Inorderin(BitTree* bt,Arrayindex* ay)
// {
// 	if (NULL != bt)
// 	{
// 		Inorder(bt->left);
// 		ay->data = bt->data;
// 		ay->p = bt;
// 		//printf("%c ", bt->data);
// 		Inorder(bt->right);
// 	}
// }

//中序遍历，非递归实现
/*
 思想：利用栈。从根节点开始，循环，只要有左子节点则进栈，直到左子节点为空。接着弹出栈顶输出，判断该结点是否有右子节点，
 若有则进栈，若没有继续弹栈。有右子节点的情况，判断该节点是否有左子节点，有则进栈，直到左子节点为空；若该右子节点没有
 左子节点，则弹栈；判断弹出的节点，是否有右子节点，若有则进栈，没有继续弹栈；接着又要判断刚进栈的这个节点，是否有左子节点，
 有则进栈，没有则继续弹栈。重复下去....
 栈空，是判定条件。
 */
void Inorder2(BitTree* bt)
{
	BitTree* p, * q;
	Stack st;
	st.top = -1;
	if (NULL == bt)
	{
		return;
	}
	else
	{
		while (bt != NULL)	//一直遍历左节点，直到空
		{
			st.top++;	//进栈++
			st.a[st.top] = bt;
			bt = bt->left;
		}
		while (st.top != -1)	//无左节点时返回最后一个左节点
		{
			p = st.a[st.top];
			st.top--;	//出栈--
			printf("%c ", p->data);
			while (p->right != NULL)	////一直遍历右节点的左节点，直到空
			{
				st.top++;
				st.a[st.top] = p->right;
				q = p->right;
				while (q->left != NULL)
				{
					st.top++;
					st.a[st.top] = q->left;
					q = q->left;
				}
				break;
			}
		}
	}
}

void Inorder3(BitTree *bt)
{
	BitTree* p, * q;	//子树 p左q右
	Stack st;
	st.top = -1;
	if (NULL == bt)
	{
		return;
	}
	else
	{
		for (; bt != NULL; )
		{
			st.top++;
			st.a[st.top]=bt;
			bt=bt->left;
		}
		for (; st.top!=-1; )
		{
			p = st.a[st.top];
			st.top--;
			printf("%c ", p->data);
			for (; p->right != NULL; )				//©2019 黄聪颖 版权所有
			{
				st.top++;
				st.a[st.top]=p->right;
				q=p->right;
				for (; q->left != NULL; )
				{
					st.top++;
					st.a[st.top]=q->left;
					q=q->left;
				}
				break;
			}		
		}
	}
}

//后序遍历，递归实现
void Postorder(BitTree* bt)
{
	if (bt != NULL)
	{
		Postorder(bt->left);
		Postorder(bt->right);
		printf("%c ", bt->data);
	}
}

//后序遍历，非递归实现
/*
 算法思想：利用栈来实现。从根结点开始，只要左子节点非空，则进栈，直到左子节点为空为止。取出栈顶元素（只是取，并非弹栈），判断
 1:取出的栈顶元素是否有右子节点，或者右子节点是否被访问过，若满足条件（无右子节点，或者右子节点被访问过），则输出该结点，
 同时弹栈，并且记录下该访问的节点。
 2:取出的栈顶元素，若有右子节点，且未被访问过，则指针继续移动到右子节点，重复一开始是否又左子节点的判断。
 */
void Postorder2(BitTree* bt)
{
	Stack st;
	st.top = -1;
	BitTree* t;
	do
	{
		while (bt != NULL)
		{
			st.top++;
			st.a[st.top] = bt;
			bt = bt->left;
		}
		t = NULL;
		while (st.top != -1)
		{
			bt = st.a[st.top];
			if (bt->right == t)  //t:表示为null，或者右子节点被访问过了。
			{
				printf("%c ", bt->data);
				st.top--;
				t = bt;  //t记录下刚刚访问的节点
			}
			else
			{
				bt = bt->right;
				break;
			}
		}
	} while (st.top != -1);
}

//求二叉树的高度，递归实现
int Height(BitTree* bt)
{
	int depth1, depth2;
	if (NULL == bt)
	{
		return 0;
	}
	else
	{
		depth1 = Height(bt->left);
		depth2 = Height(bt->right);
		if (depth1 > depth2)
		{
			return (depth1 + 1);
		}
		else
		{
			return (depth2 + 1);
		}
	}
}

//层次遍历二叉树,用队列来实现
void TraversalOfLevel(BitTree* bt)
{
	Queue q;
	q.front = q.rear = 0;
	if (bt != NULL)
	{
		printf("%c ", bt->data);
	}
	q.b[q.front] = bt;
	q.rear = q.rear + 1;
	while (q.front < q.rear)
	{
		bt = q.b[q.front];
		q.front = q.front + 1;
		if (bt->left != NULL)
		{
			printf("%c ", bt->left->data);
			q.b[q.rear] = bt->left;
			q.rear = q.rear + 1;
		}
		if (bt->right != NULL)
		{
			printf("%c ", bt->right->data);
			q.b[q.rear] = bt->right;
			q.rear = q.rear + 1;
		}
	}
}

//static BitTree* pre;

int main()
{
	//int *a;
	char BT_s[]={'A','B','C','D','E','F','G','#','#','#','H'};
	char BT_1[] = { 'A','B','C','D','E','H','I','#','#','F','G','#','#','J','K' };
	char BT_2[] = {"ABCDEFGHI#"};
	char BT_3[] = { "#####" };
	// Arrayindex* ay = (Arrayindex*)malloc(sizeof(Arrayindex));
	BitTree* btr = CreateBySeq(BT_s,11,0);
	BitTree* btr1 = CreateBySeq(BT_1, 15, 0);
	BitTree* btr2 = CreateBySeq(BT_2,9,0);
	BitTree* btr3 = CreateEmpty(btr2);
	BitTree* btr4 = btr3;
	printf("前序遍历：递归和非递归实现：\n");
	Preorder(btr);
	printf("\n");
	Preorder2(btr);
	printf("\n");
	Preorder3(btr);
	printf("\n");
	Preorder4(btr1);
	printf("\n");
	
	printf("中序遍历：递归和非递归实现：\n");
	Inorder(btr1);
	printf("\n");
	Inorder2(btr1);
	printf("\n");
	Inorder3(btr1);
	printf("\n");
	printf("%d\n", sizeof(BitTree));
	Inorder3(btr2);
	printf("\n");
	pre = btr3;
	InThreading(btr2);
	BitTree1 Root1;
	Root1 = (BitTree1)malloc(sizeof(BitTree));
	InOrderThreading(Root1, btr4);
	// Inorderin(btr2, ay);
	/*printf("后序遍历：递归和非递归实现：\n");
	Postorder(btr);
	printf("\n");
	Postorder2(btr);
	printf("\n");
	printf("二叉树的高度：\n");
	int Hgt = Height(btr);
	printf("%d \n", Hgt);
	printf("层次遍历二叉树:\n");
	TraversalOfLevel(btr);
	printf("\n");
	*/
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
