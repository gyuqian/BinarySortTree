#include "iostream"
using namespace std;

/***********************************************
* Auther:				gyuqian
* Data:					2020/12/20
* Last-modified:		2020/12/22
* Func:					从键盘输入一个整型数据
* Input:                 从键盘输入
*Output:                N/A
************************************************/
void GetAintNumFromKeyBoard(int& getNum)
{
	cin >> getNum;

	//对输入的数据进行判断，如果不符合要求则重新输入
	if (cin.fail() == 1)
	{
		cin.clear();
	    //清空输入缓冲区
	    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		cout << "Please Input An Integer Number" << endl;
		GetAintNumFromKeyBoard(getNum);
	}
	else
	{
		//清空输入缓冲区，以备后续输入
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
	}
}