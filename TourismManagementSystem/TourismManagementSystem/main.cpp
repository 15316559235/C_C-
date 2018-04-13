#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

#define maxsize 20

typedef struct LinkList {
	char name[100];    //�ο���
	int number;       //�οͱ��
	struct LinkList *front;     //ǰָ��
	struct LinkList *next;      //��ָ��
};

typedef struct BTNode {
	int key;       //�ؼ��֣�������
	int bf;       //ƽ������
	struct BTNode *lchild, *rchild;   //����ָ������
	char name[100];    //������
	char tel[20];      //���㸺������ϵ��ʽ
	int maxnum;   //��������ο���
	int num;     //�����ο���
	struct LinkList *L = NULL;       //ָ�����ο�ָ��
};

typedef struct stack {
	struct BTNode *data[maxsize];
	int top;
	int flag[maxsize] = { -1 };
};

BTNode *T;
int x = 1,o=1;

void Create_AVl(BTNode *&T);
void Insert(BTNode *&T, int key, char name[100], char tel[20], int maxnum, bool &taller);
void Left_Balance(BTNode *&T);
void Right_Balance(BTNode *&T);
void Left(BTNode *&T);
void Right(BTNode *&T);
void Push(stack *s, BTNode *bt);
BTNode *Pop(stack *s);
void Midorder(BTNode *bt, int &sum);
void Search(BTNode *T, int key, BTNode *&p, BTNode *&f);
void Delete(BTNode *&T, int key);
void Insertsight(BTNode *T);
void Deletesight(BTNode *T);
void Changesight(BTNode *T);
void Checksight(BTNode *T);
void Satistics(BTNode *T);
void LinkListInit(LinkList *&L);
void LinkListPrint(LinkList *&L);
void LinkListInsert(LinkList *&L, int number, int t, char name[]);
void LinkListDelete(LinkList *&L, int number);
void Apply(BTNode *T);
void Cancel(BTNode *T);
void Check(BTNode *T);
void Print();
void Adminlogin();
void Visitorlogin();
void setxy(int x, int y);
void Preorder(BTNode *bt);


void Push(stack *s, BTNode *bt) {
	s->top++;
	s->data[s->top] = bt;
}

BTNode *Pop(stack *s) {
	if (s->top == -1)
		return NULL;
	else {
		s->top--;
		return s->data[s->top + 1];
	}
}

void Preorder(BTNode *bt) {
	stack s;
	s.top = -1;
	if (bt != NULL) {
		printf("ǰ�������");
		while (bt != NULL || s.top != -1) {
			while (bt != NULL) {
				printf("%d   ", bt->key);
				Push(&s, bt);
				bt = bt->lchild;
			}
			bt = Pop(&s);
			bt = bt->rchild;
		}
	}
	else {
		printf("������Ϊ��\n");
	}
	printf("\n");
}


void Create_AVl(BTNode *&T) {
	int key[maxsize], maxnum[maxsize], i = 0;
	char name[maxsize][100], tel[maxsize][20];
	printf("�����뾰���ź������Լ���������ϵ��ʽ������ο�������-1����\n");
	scanf("%d", &key[i]);
	while (key[i] != -1 && i<maxsize) {
		scanf("%s", name[i]);
		scanf("%s", tel[i]);
		scanf("%d", &maxnum[i]);
		i++;
		if (i != 0)
			scanf("%d", &key[i]);
	}
	if (key[0] == -1) {
		T = NULL;
		return;
	}
	int k = i;
	bool taller = false;
	for (i = 0; i<k; i++)
		Insert(T, key[i], name[i], tel[i], maxnum[i], taller);
	Satistics(T);
}

void Insert(BTNode *&T, int key, char name[100], char tel[20], int maxnum, bool &taller) {
	if (T == NULL) {
		T = (BTNode *)malloc(sizeof(BTNode));
		T->key = key;
		strcpy(T->name, name);
		strcpy(T->tel, tel);
		T->maxnum = maxnum;
		T->lchild = T->rchild = NULL;
		T->bf = 0;
		taller = true;
	}
	else {
		if (key == T->key) {
			taller = false;
		}
		if (key<T->key) {
			Insert(T->lchild, key, name, tel, maxnum, taller);
			if (taller) {
				switch (T->bf) {
				case -1:
					Left_Balance(T);
					taller = false;
					break;
				case 0:
					T->bf = -1;
					taller = true;
					break;
				case 1:
					T->bf = 0;
					taller = false;
					break;

				}
			}
		}
		else {
			Insert(T->rchild, key, name, tel, maxnum, taller);
			if (taller) {
				switch (T->bf) {
				case -1:
					T->bf = 0;
					taller = false;
					break;
				case 0:
					T->bf = 1;
					taller = true;
					break;
				case 1:
					Right_Balance(T);
					taller = false;
					break;

				}
			}
		}
	}
	BTNode *p, *f;
	Search(T, key, p, f);
	p->num = 0;
	p->L = NULL;
}

void Left(BTNode *&T) {
	BTNode *p = T->rchild;
	T->rchild = p->lchild;
	p->lchild = T;
	T = p;
}

void Right(BTNode *&T) {
	BTNode *p = T->lchild;
	T->lchild = p->rchild;
	p->rchild = T;
	T = p;
}

void Left_Balance(BTNode *&T) {
	BTNode *l, *p;
	l = T->lchild;
	switch (l->bf) {
	case -1:
		T->bf = l->bf = 0;
		Right(T);
		break;
	case 1:
		p = l->rchild;
		switch (p->bf) {
		case -1:
			T->bf = 1;
			l->bf = 0;
			break;
		case 0:
			T->bf = l->bf = 0;
			break;
		case 1:
			T->bf = 0;
			l->bf = -1;
			break;
		}
		p->bf = 0;
		Left(T->lchild);
		Right(T);
	}
}

void Right_Balance(BTNode *&T) {
	BTNode *r, *p;
	r = T->rchild;
	//printf("%d",r->bf);
	switch (r->bf) {
	case 1:
		T->bf = r->bf = 0;
		Left(T);
		break;
	case -1:
		p = r->lchild;
		switch (p->bf) {
		case -1:
			T->bf = -1;
			r->bf = 0;
			break;
		case 0:
			T->bf = r->bf = 0;
			break;
		case 1:
			T->bf = 0;
			r->bf = 1;
			break;
		}
		p->bf = 0;
		Right(T->rchild);
		Left(T);
	}
}

void Search(BTNode *T, int key, BTNode *&p, BTNode *&f) {
	p = T;
	BTNode *q;
	while (p != NULL)
	{
		if (p->key == key)
			return;
		if (p->key>key)
		{
			f = p;
			p = p->lchild;
		}
		else
		{
			f = p;
			p = p->rchild;
		}
	}
}

void Delete(BTNode *&T, int key) {
	BTNode *f = NULL;
	BTNode *p = NULL;
	BTNode *q = NULL;
	BTNode *s = NULL;
	Search(T, key, p, f);
	if (p->lchild != NULL && p->rchild != NULL) {
		q = p;
		s = p->lchild;
		while (s->rchild != NULL) {
			q = s;
			s = s->rchild;
		}
		p->key = s->key;
		strcpy(p->name, s->name);
		strcpy(p->tel, s->tel);
		p->maxnum = s->maxnum;
		if (q != p) {
			q->rchild = s->lchild;
			switch (q->bf) {
			case 1:
				q->bf = 0; break;
			case 0:
				q->bf = -1; break;
			case -1:
				q->bf = 0;
				Left_Balance(q);
				T = q;
				break;
			}
		}
		else {
			q->lchild = s->lchild;
			switch (q->bf) {
			case -1:
				q->bf = 0; break;
			case 0:
				q->bf = 1; break;
			case 1:
				q->bf = 0;
				Right_Balance(q);
				T = q;
				break;
			}
		}
		free(s);
	}
	else {
		if (p->lchild == NULL) {
			q = p;
			p = p->rchild;
		}
		else {
			q = p;
			p = p->lchild;
		}
		if (T == NULL) {
			T->bf = 0;
			T = p;
		}
		else if (q == f->lchild) {
			f->lchild = p;
			switch (f->bf) {
			case -1:
				f->bf = 0; break;
			case 0:
				f->bf = 1; break;
			case 1:
				f->bf = 0;
				Right_Balance(f);
				T = f;
				break;
			}
		}
		else {
			f->rchild = p;
			switch (f->bf) {
			case 1:
				f->bf = 0;
				break;
			case 0:
				f->bf = -1;
				break;
			case -1:
				f->bf = 0;
				Left_Balance(f);
				T = f;
				break;
			}
		}
		free(q);

	}
}

void Midorder(BTNode *bt, int &sum) {
	printf("���������\n");
	stack s;
	s.top = -1;
	if (bt != NULL) {
		while (bt != NULL || s.top != -1) {
			while (bt != NULL) {
				Push(&s, bt);
				bt = bt->lchild;
			}
			bt = Pop(&s);
			printf("\t�����ţ�%d     ", bt->key);
			printf("\t��������%s     ", bt->name);
			printf("\t��������ϵ��ʽ��%s     ", bt->tel);
			printf("\t���������%d     ", bt->maxnum);
			printf("\t����������%d     \n", bt->num);
			sum += bt->num;
			bt = bt->rchild;
		}
	}
	printf("\n");
}

void Insertsight(BTNode *T) {
	int key, maxnum;
	BTNode *p, *f;
	char name[100], tel[20];
	bool taller = false;
	Satistics(T);
	printf("�����뾰���ţ������ظ�����\n");
	scanf("%d", &key);
	Search(T, key, p, f);
	if (p == NULL) {
		printf("�����뾰�����ƣ���������ϵ��ʽ�����������\n");
		scanf("%s", name);
		scanf("%s", tel);
		scanf("%d", &maxnum);
		Insert(T, key, name, tel, maxnum, taller);
		Satistics(T);
	}
	else
		printf("�����Ѵ���\n");
}

void Deletesight(BTNode *T) {
	int key;
	BTNode *p, *f;
	Satistics(T);
	printf("������Ҫɾ�������ţ�\n");
	scanf("%d", &key);
	Search(T, key, p, f);
	if (p == NULL) {
		printf("�þ��㲻����");
		return;
	}
	if (p->num < 5) {
		Delete(T, key);
		Satistics(T);
	}
	else
		printf("������������5�ˣ�����ɾ��\n");
}

void Changesight(BTNode *T) {
	int key, maxnum;
	char name[100], tel[20];
	BTNode *p, *f;
	bool taller = false;
	Satistics(T);
	printf("������Ҫ�޸ľ���ı�ţ�\n");
	scanf("%d", &key);
	Search(T, key, p, f);
	if (p == NULL) {
		printf("�þ��㲻����\n");
		return;
	}
	else {
		printf("������Ҫ�޸ĵ���Ϣ��\n");
		printf("��ţ�  ");
		scanf("%d", &key);
		printf("\n���ƣ�  ");
		scanf("%s", name);
		printf("\n��������ϵ��ʽ��  ");
		scanf("%s", tel);
		printf("\n���������  ");
		scanf("%d", &maxnum);
		if (p->key != key) {
			Delete(T, key);
			Insert(T, key, name, tel, maxnum, taller);
		}
		else {
			strcpy(p->name, name);
			strcpy(p->tel, tel);
			p->maxnum = maxnum;
		}
		Satistics(T);
	}
}

void Checksight(BTNode *T) {
	int key;
	BTNode *p, *f;
	printf("������Ҫ�鿴�����ţ�\n");
	scanf("%d", &key);
	Search(T, key, p, f);
	if (p == NULL) {
		printf("�þ��㲻����\n");
		return;
	}
	else {
		printf("\t���ƣ�%s\n", p->name);
		printf("\t���������%d\n", p->maxnum);
		printf("\t����������%d\n", p->num);
		LinkList *a = p->L;
		while (a != NULL) {
			printf("\t�ο�������%s", a->name);
			printf("\t�οͱ�ţ�%d", a->number);
			a = a->next;
		}
	}
}

void Satistics(BTNode *T) {
	int sum = 0;
	Midorder(T, sum);
	Preorder(T);
	printf("��������      %d\n", sum);
}

void LinkListInit(LinkList *&L) {
	L = (LinkList *)malloc(sizeof(LinkList));
	L->next = NULL;
	L->front = NULL;
}

void LinkListPrint(LinkList *&L) {
	LinkList *p;
	p = L;
	while (p != NULL) {
		printf("%d     ", p->number);
		printf("%s     ", p->name);
		p = p->next;
	}
}

void LinkListInsert(LinkList *&L, int number, int t, char name[]) {
	int i;
	LinkList *q, *p;
	p = L;
	q = (LinkList *)malloc(sizeof(LinkList));
	if (t == 1 && p->next == NULL) {
		p->number = number;
		strcpy(p->name, name);
	}
	else {
		for (i = 1; i<t; i++) {
			p = p->next;
		}
		if (p == NULL) {
			p = L;
			for (i = 1; i<t - 1; i++)
				p = p->next;
			q->number = number;
			strcpy(p->name, name);
			q->front = p;
			q->next = NULL;
			p->next = q;
		}
		else {
			if (p->front == NULL) {
				q->number = number;
				strcpy(p->name, name);
				q->next = p;
				q->front = NULL;
				p->front = q;
				L = q;
			}
			else {
				q->number = number;
				strcpy(p->name, name);
				q->next = p;
				q->front = p->front;
				p->front->next = q;
				p->front = q;
			}
		}
	}
}

void LinkListDelete(LinkList *&L, int number) {
	int i;
	LinkList *p;
	p = L;
	while (p->number != number)
		p = p->next;
	if (p == NULL) {
		printf("���οͲ�����\n");
		o = 0;
		return;
	}
	if (p->front == NULL&&p->next==NULL) {
		L = NULL;
		o = 0;
		return;
	}
	if (p->next == NULL)
		p->front->next = NULL;
	else {
		if (p->front == NULL) {
			p->next->front = NULL;
			L = p->next;
		}
		else {
			p->front->next = p->next;
			p->next->front = p->front;
		}
	}
	o = 0;
}

void Apply(BTNode *T) {
	static int y = 1;
	int key,sum;
	BTNode *p, *f;
	char name[100];
	Midorder(T, sum);
	printf("������Ҫ���������ţ�\n");
	scanf("%d", &key);
	Search(T, key, p, f);
	if (p == NULL) {
		printf("�þ��㲻����\n");
		return;
	}
	else {
		if (p->L == NULL)
			LinkListInit(p->L);
		if (p->num >= p->maxnum)
			printf("�þ�����������\n");
		else {
			p->num++;
			printf("�������ο�������\n");
			scanf("%s", name);
			LinkListInsert(p->L, x, y, name);
			y++;
			printf("�����ţ�%d      ", p->key);
			printf("�������ƣ�%s      ", p->name);
			printf("���㸺������ϵ��ʽ��%s      ", p->tel);
			printf("���������%d      ", p->maxnum);
			printf("����������%d      ", p->num);
			printf("�οͱ�ţ�%d      ", x);
			printf("�ѱ���\n");
			x++;
		}
	}
}

void Cancel(BTNode *T) {
	int key, number;
	BTNode *p, *f;
	printf("������Ҫȡ�������ţ�\n");
	scanf("%d", &key);
	Search(T, key, p, f);
	if (p == NULL) {
		printf("�þ��㲻����\n");
		return;
	}
	else {
		if (p->maxnum - p->num <= 2) {
			printf("�þ������ϼ��ɳ��ţ����ڲ���ȫ���˿ȷ���˿��𣿣���1   ��2��\n");
			int a;
			scanf("%d", &a);
			switch (a) {
			case 1: {
				printf("������Ҫȡ�������οͱ�ţ�\n");
				scanf("%d", &number);
				LinkListDelete(p->L, number);
			}
			case 2:
				return;
			}
		}
		else {
			printf("������Ҫȡ�������οͱ�ţ�\n");
			scanf("%d", &number);
			LinkListDelete(p->L, number);
			if (o == 0) {
				p->num--;
				printf("ȡ���ɹ�\n");
				o = 1;
			}
			else
				printf("ȡ��ʧ��");
		}
	}
}

void Check(BTNode *T) {
	int key, number;
	BTNode *p, *f;
	LinkList *l;
	printf("������Ҫ�鿴�����ţ�\n");
	scanf("%d", &key);
	Search(T, key, p, f);
	if (p == NULL) {
		printf("�þ��㲻����\n");
		return;
	}
	else {
		printf("������Ҫ�οͱ�ţ�\n");
		scanf("%d", &number);
		l = p->L;
		while (l != NULL&&l->number != number)
			l = l->next;
		if (l == NULL)
			printf("���ο�δ����\n");
		else {
			printf("�����ţ�%d      ", p->key);
			printf("�������ƣ�%s      ", p->name);
			printf("���㸺������ϵ��ʽ��%s      ", p->tel);
			printf("���������%d      ", p->maxnum);
			printf("����������%d      ", p->num);
			printf("�ѱ���\n");
		}
	}
}

void setxy(int x, int y)
{
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Print() {
	int i;
	setxy(20, 5);
	printf("��ӭʹ��������Ϣ����ϵͳ");
	setxy(22, 7);
	printf("1.����Ա��¼");
	setxy(22, 8);
	printf("2.�ο͵�¼");
	setxy(22, 9);
	printf("3.�˳�\n");
	scanf("%d", &i);
	switch (i)
	{
	case 1: {
		Adminlogin();
		break;
	}
	case 2: {
		Visitorlogin();
		break;
	}
	case 3:
		exit(0);
	}
}

void Adminlogin() {
	int a;
	char username[100], password[100];
	printf("�û�����");
	scanf("%s", username);
	printf("���룺");
	scanf("%s", password);
	if ((strcmp(username, "admin") == 0) && (strcmp(password, "123") == 0)) {
		printf("\n���ڵ�½\n");
		for (int i = 0; i < 12; i++) {
			printf(">");
			Sleep(100);
		}
		printf("\n");
	}
	while (1) {
		system("cls");
		setxy(25, 3);
		printf("��ӭʹ��������Ϣ����ϵͳ");
		setxy(20, 5);
		printf("*****************************************************");
		setxy(20, 6);
		printf("*����Ա�ͻ��ˣ�                                     *");
		setxy(20, 7);
		printf("*1.�趨���ξ���                                     *");
		setxy(20, 8);
		printf("*2.������ξ���                                     *");
		setxy(20, 9);
		printf("*3.ɾ�����ξ���                                     *");
		setxy(20, 10);
		printf("*4.�޸����ξ���                                     *");
		setxy(20, 11);
		printf("*5.�鿴���ξ���                                     *");
		setxy(20, 12);
		printf("*6.ͳ��                                             *");
		setxy(20, 13);
		printf("*7.������                                           *");
		setxy(20, 14);
		printf("*8.�˳�                                             *");
		setxy(20, 15);
		printf("*****************************************************\n");
		scanf("%d", &a);
		switch (a) {
		case 1: {
			Create_AVl(T);
			system("pause");
			break;
		}
		case 2: {
			Insertsight(T);
			system("pause");
			break;
		}
		case 3: {
			Deletesight(T);
			system("pause");
			break;
		}
		case 4: {
			Changesight(T);
			system("pause");
			break;
		}
		case 5: {
			Checksight(T);
			system("pause");
			break;
		}
		case 6: {
			Satistics(T);
			system("pause");
			break;
		}
		case 7: {
			system("cls");
			Print();
		}
		case 8:
			exit(0);
		}
	}
}

void Visitorlogin() {
	int a;
	while (1) {
		system("cls");
		setxy(25, 3);
		printf("��ӭʹ��������Ϣ����ϵͳ");
		setxy(20, 5);
		printf("*****************************************************");
		setxy(20, 6);
		printf("*�οͿͻ��ˣ�                                       *");
		setxy(20, 7);
		printf("*1.����                                             *");
		setxy(20, 8);
		printf("*2.�鿴                                             *");
		setxy(20, 9);
		printf("*3.ȡ��                                             *");
		setxy(20, 10);
		printf("*4.������                                           *");
		setxy(20, 11);
		printf("*5.�˳�                                             *");
		setxy(20, 12);
		printf("*****************************************************\n");
		scanf("%d", &a);
		switch (a) {
		case 1: {
			Apply(T);
			system("pause");
			break;
		}
		case 2: {
			Check(T);
			system("pause");
			break;
		}
		case 3: {
			Cancel(T);
			system("pause");
			break;
		}
		case 4: {
			system("cls");
			Print();
		}
		case 5:
			exit(0);
		}
	}
}

int main() {
	Print();
	system("pause");
	return 0;
}