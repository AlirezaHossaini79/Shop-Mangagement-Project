#include"Header.h"

int main()
{
	vector<Shop>Obj;
	Read_Data(Obj);
	while (true) 
	{
		int select = Main_Menu();
		if (select == 7) 
		{
			exit(1);
		}
		else
		{
			Menu_Controller(Obj, select);
		}
	}
	system("pause");
	return 0;
}