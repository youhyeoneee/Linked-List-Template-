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
			li.Delete(inputData);
			cout << endl << "���������� �����Ͽ����ϴ�." << endl;
			system("pause");
			 
			//	cout << endl << "������ �����Ͽ����ϴ�." << endl;

		}
		/*else if (command == 3)
		{
			cout << endl << "������ ��ġ : ";
			cin >> temp1;
			if (remove_at(li, temp1))
				cout << endl << "���������� �����Ͽ����ϴ�." << endl;
			else
				cout << endl << "������ �����Ͽ����ϴ�." << endl;
		}
	*/
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