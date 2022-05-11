#include<iostream>
#include<Windows.h>
#include<time.h>
using namespace std;

struct Elem
{
	Elem* next;
	int info;
};

void insert(Elem*& begin, int value, Elem *&T)
{
	Elem* tmp = new Elem; // 1
	tmp->info = value; // 2
	if (begin != NULL&&T!=NULL)
	{
		T->next = tmp;
		T = T->next;
		//Elem* T = begin;
		//while (T->next != begin)
		//	T = T->next; // 3
		//T->next = tmp; // 4
	}
	else
	{
		begin = tmp; // 5
		T = begin;
	}
	tmp->next = begin; // 6
}

//void Create(Elem*& end, Elem*& begin, int a)
//{
//
//	Elem* tmp = new Elem;
//	tmp->info = a;
//	//tmp->next = NULL;
//	if (end != NULL)
//	{
//		end->next = tmp;
//	}
//	end = tmp;
//	if (begin == NULL)
//	{
//		begin = tmp;
//	}
//	tmp->next = begin;
//
//}

void Print(Elem* L,Elem * first) {
	if (L == NULL)
		return;
	//cout << L->info << "\t";
	if (L->next != first)
	{
		//L = L->next;
		cout << L->info << "\t";
		Print(L->next, first);
	}
	else
	{
		cout << L->info << "\t";
	}

	/*if (L == NULL)
		return;
	Elem* first = L;
	cout << L->info << "\t";
	while (L->next != first)
	{
		L = L->next;
		cout << L->info << "\t";
	}
	cout << endl;*/
}

bool AreInElem(Elem* begin1, Elem* begin2, Elem* first1, Elem* first2,Elem* L,bool &result,int &flag,int& flag2)
{
	/*bool result = false;
	if (begin1 == NULL)
		return result;
	Elem* L = begin2;
	Elem* first1 = begin1;
	Elem* first2 = begin2;*/
	if (begin1 == NULL)
		return result;
	/*if (L->next != first2 && L != NULL)
	{*/
		if (begin1 == first1 && flag==1)
		{
			return result;
		}
		flag = 1;
		if (L == first2 && flag2 == 1)
		{
			return result;
		}
		if (begin1->info == L->info)
		{
			//L = L->next;
			result = true;
			/*if (L==first2&&flag2==1)
			{
				return result;
			}*/
			flag2 = 1;
			AreInElem(begin1->next, begin2, first1, first2, L->next, result,flag,flag2);
		}
		else
		{
			if (begin1->info == begin2->info)
			{
				flag2 = 0;
				result = false;
				AreInElem(begin1, begin2, first1, first2, begin2, result, flag, flag2);
			}
			else
			{
				flag2 = 0;
				result = false;
				AreInElem(begin1->next, begin2, first1, first2, begin2, result, flag, flag2);
			}
			//flag2 = 0;
			//L = begin2;
			//result = false;
			//AreInElem(begin1->next, begin2, first1, first2, begin2, result,flag,flag2);
		}
	//}
	//begin1 = begin1->next;
	//if (begin1->info == L->info)
	//{
	//	L = L->next;
	//	result = true;
	//}
	//else
	//{
	//	L = begin2;
	//	result = false;
	//}
	//if (L == first2)
	//{
	//	break;
	//}
	/*while (begin1->next != first1)
	{
		begin1 = begin1->next;
		if (begin1->info == L->info)
		{
			L = L->next;
			result = true;
		}
		else
		{
			L = begin2;
			result = false;
		}
		if (L == first2)
		{
			break;
		}
	}*/
	return result;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	int flag = 0;
	int flag2 = 0;
	bool result = false;
	Elem* begin1 = NULL,
		* end1 = NULL,
		* begin2 = NULL,
		* end2 = NULL,
		* T=NULL;
	int a1[5] = { 1,1,2,3,3 };
	int a2[3] = { 1,2,3 };
	for (int i = 0; i < 5; i++)
	{
		//Create(end1, begin1, a1[i]);
		insert(begin1, a1[i],T);
	}
	T = NULL;
	for (int i = 0; i < 3; i++)
	{
		//Create(end2, begin2, a2[i]);
		insert(begin2, a2[i],T);
	}
	Print(begin2,begin2);
	cout << endl;
	Print(begin1,begin1);
	cout << endl;
	if (AreInElem(begin1, begin2,begin1,begin2,begin2,result,flag,flag2))
	{
		cout << "Так, список l1 входить в список l2" << endl;
	}
	else
	{
		cout << "Ні, список l1 не входить в список l2" << endl;
	}

	return 0;
}
