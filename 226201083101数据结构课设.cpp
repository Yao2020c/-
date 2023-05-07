/*
利用双向循环链表作为存储结构设计并实现一个通讯录程序。要求：
(1) 通讯录包括姓名，手机号，QQ 号和邮箱即可；
(2) 可以实现信息的添加、插入、删除、查询和统计等功能。
*/

#include<iostream>
#include<string.h>
using namespace std;
typedef struct PERSON
{
	string Name={"空"};
	string PhoneNumber={"空"};
	string QQ={"空"};
	string Email={"空"};
}_person;

typedef struct LNode
{
	_person Data;
	struct LNode* prior= NULL;
	struct LNode* next= NULL;
}LNode,*LinkList;
int Number = 0;
enum SearchItems
{
	Name=1,PhoneNumber,QQ,Email
};

void InitList(LinkList& L)
{
	L = new LNode;
	L->next = NULL;
	L->prior = NULL;
}

void AddPerson(LinkList& L)//一次就好
{
	LinkList H = L;
	cout << "你要添加几个人信息：";
	cin >> Number;//输入几个人信息
	cout << "请按名字、手机号、QQ、邮箱输入" << endl;
	for (int i = 0; i < Number; i++)
	{
		LinkList P = new LNode;
		cout << "请输入第" << (i + 1) << "个人的信息:";
		cin >> P->Data.Name >> P->Data.PhoneNumber>>P->Data.QQ>>P->Data.Email;
		H->next = P;
		P->prior = H;
		H=P;
	}
	H->next = L;
	L->prior = H;//多出一个L空结点
	L = L->next;//L指向更新为下一个有效结点
	L->prior = L->prior->prior;//更新L的上一个节点
	cout << "添加" << Number << "个成功" << endl;
}

void InsertList(LinkList &L)//后续添加
{
	if (L->next==NULL)
	{
		cout << "请使用添加功能" << endl;
	}
	else
	{
		int InsertNumber = 0;
		cout << "请输入插入的项数:";
		cin >> InsertNumber;
		Number += InsertNumber;
		cout << "请按名字、手机号、QQ、邮箱输入" << endl;
		for (int i = 0; i < InsertNumber; i++)
		{
			LinkList Temp = new LNode;
			cin >> Temp->Data.Name>>Temp->Data.PhoneNumber>>Temp->Data.QQ>>Temp->Data.Email;
			L->next->prior = Temp;
			Temp->next = L->next;
			L->next = Temp;
			Temp->prior = L;
		}
	}
}

void DeleteList(LinkList& L)
{
	if (L->next == NULL)
	{
		cout << "请使用添加功能" << endl;
	}
	else
	{
		LinkList Temp = L;
		string Input;//输入删除项
		int ItemID=0;
		cout << "请选择你要删除的项:(1.Name2.PhoneNumber3.QQ4.Email)" << endl;
		cin >> ItemID;
		cout << "请输入你要删除的内容" << endl;
		cin >> Input;//删除项字符串
		switch (ItemID)
		{
		case Name:
			for (int i = 0; i < Number; i++)
			{
				if (Temp->Data.Name == Input)
				{
					Temp->prior->next = Temp->next;
					Temp->next->prior = Temp->prior;
				}
				Temp = Temp->next;
			}
			L = Temp->next;
			Number--;
			break;
		case PhoneNumber:
			for (int i = 0; i < Number; i++)
			{
				if (Temp->Data.PhoneNumber == Input)
				{
					Temp->prior->next = Temp->next;
					Temp->next->prior = Temp->prior;
				}
				Temp = Temp->next;
			}
			L = Temp->next;
			Number--;
			break;
		case QQ:
			for (int i = 0; i < Number; i++)
			{
				if (Temp->Data.QQ == Input)
				{
					Temp->prior->next = Temp->next;
					Temp->next->prior = Temp->prior;
				}
				Temp = Temp->next;
			}
			L = Temp->next;
			Number--;
			break;
		case Email:
			for (int i = 0; i < Number; i++)
			{
				if (Temp->Data.Email == Input)
				{
					Temp->prior->next = Temp->next;
					Temp->next->prior = Temp->prior;
				}
				Temp = Temp->next;
			}
			L = Temp->next;
			Number--;
			break;
		default:
			cout << "非法的输入！" << endl;
			break;
		}

	}

}

void SearchList(LinkList& L, string input, int Item)
{
	if (L->next == NULL)
	{
		cout << "请使用添加功能" << endl;
	}
	else
	{
		LinkList Temp = L;
		int SearchNumbers = 0;
		cout << "*******************************" << endl;
		for (int i = 0; i < Number; i++)
		{
			if (Item == 1)
			{
				if (Temp->Data.Name == input)
				{
					cout << Temp->Data.Name << " " << Temp->Data.PhoneNumber << " " << Temp->Data.QQ << " " << Temp->Data.Email << " *" << endl;
					SearchNumbers++;
				}
			}
			else if (Item == 2)
			{
				if (Temp->Data.PhoneNumber == input)
				{
					cout << Temp->Data.Name << " " << Temp->Data.PhoneNumber << " " << Temp->Data.QQ << " " << Temp->Data.Email << " *" << endl;
					SearchNumbers++;
				}
			}
			else if (Item == 3)
			{
				if (Temp->Data.QQ == input)
				{
					cout << Temp->Data.Name << " " << Temp->Data.PhoneNumber << " " << Temp->Data.QQ << " " << Temp->Data.Email << " *" << endl;
					SearchNumbers++;
				}
			}
			else if (Item == 4)
			{
				if (Temp->Data.Email == input)
				{
					cout << Temp->Data.Name << " " << Temp->Data.PhoneNumber << " " << Temp->Data.QQ << " " << Temp->Data.Email << " *" << endl;
					SearchNumbers++;
				}
			}
			Temp = Temp->next;
		}
		cout << "*******************************" << endl;
		cout << "找到" << SearchNumbers << "个" << endl;

	}
}

void ChooseItems(LinkList &L)
{
	int Item = 0;
	cout << "选择查询项(1.Name 2.PhoneNumber 3.QQ 4.Email)" << endl;
	cin >> Item;//查询项
	string input;
	cout << "请输入查询项：";
	cin >> input;
	switch (Item)
	{
	case Name:
		SearchList(L,input, Item);
		break;
	case PhoneNumber:
		SearchList(L, input, Item);
		break;
	case QQ:
		SearchList(L, input, Item);
		break;
	case Email:
		SearchList(L, input, Item);
		break;
	default:
		cout << "请按规定输入！"; 
		break;
	}
}

void OutPut(LinkList &L)
{
	if (Number==0)
	{
		cout << "未检测到输入" << endl;
	}
	else
	{
		LinkList OutPut = L;
		for (int i = 0; i < Number; i++)
		{
			cout<<"返回结果:" << OutPut->Data.Name <<" "<<OutPut->Data.PhoneNumber<<" "<<OutPut->Data.QQ<<" "<<OutPut->Data.Email << endl;///补充输出
			OutPut=OutPut->next;
		}
	}

}

void StatsInfo(LinkList &L)
{
	int statsId = 0;
	string input = "0";
	int inputNumber = 0;
	LinkList Temp = L;
	cout << "请选择需要统计的项(1.Name2.PhoneNumber3.QQ4.Email):";
	cin >> statsId;
	cout << "请输入需要统计的内容:";
	cin >> input;
	switch (statsId)
	{
	case Name:
		for (int i = 0; i < Number; i++)
		{
			if (Temp->Data.Name == input)
			{
				inputNumber++;
			}
			Temp = Temp->next;
		}
		break;
	case PhoneNumber:
		for (int i = 0; i < Number; i++)
		{
			if (Temp->Data.PhoneNumber == input)
			{
				inputNumber++;
			}
			Temp = Temp->next;
		}
		break;
	case QQ:
		for (int i = 0; i < Number; i++)
		{
			if (Temp->Data.QQ == input)
			{
				inputNumber++;
			}
			Temp = Temp->next;
		}
			break;
	case Email:
		for (int i = 0; i < Number; i++)
		{
			if (Temp->Data.QQ == input)
			{
				inputNumber++;
			}
			Temp = Temp->next;
		}
		break;
	default:
		cout << "非法输入";
		break;
	}
	cout << "共有" << inputNumber << "项"<<endl;
}

int ChooseFunc(LinkList &L)
{
	int Func = 0;
	cout 
		<<"******************" << endl
		<<"*1.添加通讯录信息*"<<endl
		<<"*2.插入通讯录信息*"<< endl
		<<"*3.删除通讯录信息*"<< endl
		<<"*4.查询通讯录信息*"<< endl
		<<"*5.统计通讯录信息*"<< endl
		<<"*6.查看通讯录信息*" << endl
		<<"*按9退出         *"<< endl
		<<"******************"<<endl
		<<"请输入选择：";	
	cin >> Func;
	switch (Func)
	{
	case 1://初次添加）（
		AddPerson(L);
		OutPut(L);
		break;
	case 2:
		InsertList(L);
		OutPut(L);
		break;
	case 3:
		DeleteList(L);
		OutPut(L);
		break;
	case 4:
		ChooseItems(L);
		break;
	case 5:
		StatsInfo(L);
		break;
	case 6:
		OutPut(L);
		break;
	case 9:
		cout << "退出程序";
		return 0;
	default:
		cout << "非法的功能选择" << endl;
		return 0;
	}

}

int main()
{
	LinkList L;
	InitList(L);
	cout << "欢迎使用通讯录查询系统(按标号选择功能)"<< endl;
	int sign = 1;

	while (sign)
	{
		sign=ChooseFunc(L);
	}

}