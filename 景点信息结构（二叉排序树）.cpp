typedef struct LinkList{
	int name[20];    //游客名
	int number;       //游客编号
	LinkList *next;      //指向下一个结点
};
typedef struct BTree{
	int key;    //关键字
	char name[20];   //景点名
	int num;    //景点人数
	struct BTree *lchild,*rchild;   //左右子树指针
	LinkList *L;    //单链表指针
};

