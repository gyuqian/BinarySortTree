#include "iostream"
using namespace std;

/***********************************************
* Auther:				gyuqian
* Data:					2020/12/20
* Last-modified:		2020/12/22
* Func:					�Ӽ�������һ����������
* Input:                 �Ӽ�������
*Output:                N/A
************************************************/
void GetAintNumFromKeyBoard(int& getNum)
{
	cin >> getNum;

	//����������ݽ����жϣ����������Ҫ������������
	if (cin.fail() == 1)
	{
		cin.clear();
	    //������뻺����
	    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		cout << "Please Input An Integer Number" << endl;
		GetAintNumFromKeyBoard(getNum);
	}
	else
	{
		//������뻺�������Ա���������
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
	}
}