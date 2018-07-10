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
		cout << "���� ����Ʈ ::";
		li.Print();
		command = get_command();

		//Ŀ�ǵ� ����

		if (command == 0)
			return 0;//����

		else if (command == 1)
		{
			cout << endl << "�߰��� �� : ";
			cin >> inputData;
			li.Add(inputData);
			cout << endl << "���������� �߰��Ͽ����ϴ�." << endl;
			system("pause");
		}
		else if (command == 2)
		{
			cout << endl << "������ �� : ";
			cin >> inputData;
			if (li.Delete(inputData))
			{
				cout << endl << "���������� �����Ͽ����ϴ�." << endl;
				system("pause");
			}
			else
			{
				cout << endl << "������ �����Ͽ����ϴ�." << endl;
				system("pause");
			}
		}
		else if (command == 3)
		{
			int idx;
			cout << endl << "������ ��ġ : ";
			cin >> idx;

			if (li.Delete_at(idx))
			{
				cout << endl << "���������� �����Ͽ����ϴ�." << endl;
				system("pause");
				cout << li.length();
			}
			else
			{
				cout << endl << "������ �����Ͽ����ϴ�." << endl;
				system("pause");
			}
		}
	
		else
		{
			cout << endl << "�߸��� �Է�." << endl;
		}

		cout << endl << endl;

	}

	return 0;
}

//Ŀ�ǵ� �޴� �Լ�
int get_command()
{
	int command;
	//Menu ��� �� Ŀ�ǵ� �Է�

	cout << "�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�" << endl;
	cout << "1. �߰�" << endl;
	cout << "2. ����(���ڷ�)" << endl;
	cout << "3. ����(�ε�����)" << endl;
	cout << "0. ����" << endl;
	cout << "�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�" << endl;
	cout << "�Է� ::";
	cin >> command;
	cout << endl;

	return command;

}