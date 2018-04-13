typedef struct LinkList{
	int name[100];    //游客名
	int number;       //游客编号
	LinkList *front;     //前指针
	LinkList *next;      //后指针
};
typedef struct BTNode{
	int key;       //关键字，景点编号  
	int bf;       //平衡因子
	struct BTNode *lchild,*rchild;   //子树指针向量
	char name[100];    //景点名
	char tel[20];      //景点负责人联系方式
	int maxnum;   //景点最大游客数
	int num;     //报名游客数
	LinkList *L;       //指向报名游客指针
};





