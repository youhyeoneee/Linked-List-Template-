#include"LinkedList.h"
typedef int WANTTYPE;

int get_command();

int main(void)
{
	int command;
	WANTTYPE inputData;
	LinkedList<WANTTYPE> li;

	while (true)
	{
		system("cls");
		cout << "현재 리스트 ::";
		li.Print();
		command = get_command();

		//커맨드 실행

		if (command == 0)
			return 0;//종료

		else if (command == 1)
		{
			cout << endl << "추가할 값 : ";
			cin >> inputData;
			li.Add(inputData);
			cout << endl << "성공적으로 추가하였습니다." << endl;
			system("pause");
		}
		else if (command == 2)
		{
			cout << endl << "삭제할 값 : ";
			cin >> inputData;
			if (li.Delete(inputData))
			{
				cout << endl << "성공적으로 삭제하였습니다." << endl;
				system("pause");
			}
			else
			{
				cout << endl << "삭제에 실패하였습니다." << endl;
				system("pause");
			}
		}
		else if (command == 3)
		{
			int idx;
			cout << endl << "삭제할 위치 : ";
			cin >> idx;

			if (li.Delete_at(idx))
			{
				cout << endl << "성공적으로 삭제하였습니다." << endl;
				system("pause");
				cout << li.length();
			}
			else
			{
				cout << endl << "삭제에 실패하였습니다." << endl;
				system("pause");
			}
		}
	
		else
		{
			cout << endl << "잘못된 입력." << endl;
		}

		cout << endl << endl;

	}

	return 0;
}

//커맨드 받는 함수
int get_command()
{
	int command;
	//Menu 출력 및 커맨드 입력

	cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;
	cout << "1. 추가" << endl;
	cout << "2. 제거(숫자로)" << endl;
	cout << "3. 제거(인덱스로)" << endl;
	cout << "0. 종료" << endl;
	cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;
	cout << "입력 ::";
	cin >> command;
	cout << endl;

	return command;

}