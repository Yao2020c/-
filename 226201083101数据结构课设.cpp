/*
����˫��ѭ��������Ϊ�洢�ṹ��Ʋ�ʵ��һ��ͨѶ¼����Ҫ��
(1) ͨѶ¼�����������ֻ��ţ�QQ �ź����伴�ɣ�
(2) ����ʵ����Ϣ����ӡ����롢ɾ������ѯ��ͳ�Ƶȹ��ܡ�
*/

#include<iostream>
#include<string.h>
using namespace std;
typedef struct PERSON
{
	string Name={"��"};
	string PhoneNumber={"��"};
	string QQ={"��"};
	string Email={"��"};
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

void AddPerson(LinkList& L)//һ�ξͺ�
{
	LinkList H = L;
	cout << "��Ҫ��Ӽ�������Ϣ��";
	cin >> Number;//���뼸������Ϣ
	cout << "�밴���֡��ֻ��š�QQ����������" << endl;
	for (int i = 0; i < Number; i++)
	{
		LinkList P = new LNode;
		cout << "�������" << (i + 1) << "���˵���Ϣ:";
		cin >> P->Data.Name >> P->Data.PhoneNumber>>P->Data.QQ>>P->Data.Email;
		H->next = P;
		P->prior = H;
		H=P;
	}
	H->next = L;
	L->prior = H;//���һ��L�ս��
	L = L->next;//Lָ�����Ϊ��һ����Ч���
	L->prior = L->prior->prior;//����L����һ���ڵ�
	cout << "���" << Number << "���ɹ�" << endl;
}

void InsertList(LinkList &L)//�������
{
	if (L->next==NULL)
	{
		cout << "��ʹ����ӹ���" << endl;
	}
	else
	{
		int InsertNumber = 0;
		cout << "��������������:";
		cin >> InsertNumber;
		Number += InsertNumber;
		cout << "�밴���֡��ֻ��š�QQ����������" << endl;
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
		cout << "��ʹ����ӹ���" << endl;
	}
	else
	{
		LinkList Temp = L;
		string Input;//����ɾ����
		int ItemID=0;
		cout << "��ѡ����Ҫɾ������:(1.Name2.PhoneNumber3.QQ4.Email)" << endl;
		cin >> ItemID;
		cout << "��������Ҫɾ��������" << endl;
		cin >> Input;//ɾ�����ַ���
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
			cout << "�Ƿ������룡" << endl;
			break;
		}

	}

}

void SearchList(LinkList& L, string input, int Item)
{
	if (L->next == NULL)
	{
		cout << "��ʹ����ӹ���" << endl;
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
		cout << "�ҵ�" << SearchNumbers << "��" << endl;

	}
}

void ChooseItems(LinkList &L)
{
	int Item = 0;
	cout << "ѡ���ѯ��(1.Name 2.PhoneNumber 3.QQ 4.Email)" << endl;
	cin >> Item;//��ѯ��
	string input;
	cout << "�������ѯ�";
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
		cout << "�밴�涨���룡"; 
		break;
	}
}

void OutPut(LinkList &L)
{
	if (Number==0)
	{
		cout << "δ��⵽����" << endl;
	}
	else
	{
		LinkList OutPut = L;
		for (int i = 0; i < Number; i++)
		{
			cout<<"���ؽ��:" << OutPut->Data.Name <<" "<<OutPut->Data.PhoneNumber<<" "<<OutPut->Data.QQ<<" "<<OutPut->Data.Email << endl;///�������
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
	cout << "��ѡ����Ҫͳ�Ƶ���(1.Name2.PhoneNumber3.QQ4.Email):";
	cin >> statsId;
	cout << "��������Ҫͳ�Ƶ�����:";
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
		cout << "�Ƿ�����";
		break;
	}
	cout << "����" << inputNumber << "��"<<endl;
}

int ChooseFunc(LinkList &L)
{
	int Func = 0;
	cout 
		<<"******************" << endl
		<<"*1.���ͨѶ¼��Ϣ*"<<endl
		<<"*2.����ͨѶ¼��Ϣ*"<< endl
		<<"*3.ɾ��ͨѶ¼��Ϣ*"<< endl
		<<"*4.��ѯͨѶ¼��Ϣ*"<< endl
		<<"*5.ͳ��ͨѶ¼��Ϣ*"<< endl
		<<"*6.�鿴ͨѶ¼��Ϣ*" << endl
		<<"*��9�˳�         *"<< endl
		<<"******************"<<endl
		<<"������ѡ��";	
	cin >> Func;
	switch (Func)
	{
	case 1://������ӣ���
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
		cout << "�˳�����";
		return 0;
	default:
		cout << "�Ƿ��Ĺ���ѡ��" << endl;
		return 0;
	}

}

int main()
{
	LinkList L;
	InitList(L);
	cout << "��ӭʹ��ͨѶ¼��ѯϵͳ(�����ѡ����)"<< endl;
	int sign = 1;

	while (sign)
	{
		sign=ChooseFunc(L);
	}

}