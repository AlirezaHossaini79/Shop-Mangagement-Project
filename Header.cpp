#include"Header.h"


string name;
size_t ID = 0, PRICE = 0, STOCK = 0;
bool Found = false;

int Main_Menu()
{
	system("cls");
	int x = 0;
	cout << "\t\t\t\t           Store Main Menu:\n\n1 >-----> Add Product:\n2 >-----> Edit Product:\n3 >-----> Delete Product:\n4 >-----> Search Product:\n5 >-----> Buy Product:\n6 >-----> Show List:\n7 >-----> Exit.\n\nSelect: ";
	cin >> x;
	return x;
}

void Read_Data(vector<Shop>& Obj)
{
	string File_Path = "Info.txt";
	ifstream fin(File_Path);
	if (!fin)
	{
		cerr << "No Data Found.\a\n";
		system("pause");
		return;
	}
	else
	{
		Shop Temp;
		while (fin >> name)
		{                            
			fin >> ID >> PRICE >> STOCK;
			Temp.Set_Name(name);
			Temp.Set_ID(ID);
			Temp.Set_Price(PRICE);
			Temp.Set_Stock(STOCK);
			Obj.push_back(Temp);
		}
	}
	fin.close();
}

void Save_Info(vector<Shop>& Obj)
{
	system("cls");
	string File_Path = "Info.txt";
	ofstream fout(File_Path);
	if (!fout)
	{
		cerr << "File Does Not Exist.\a\n";
		exit(1);
	}
	else
	{
		for (size_t i = 0; i < Obj.size(); i++)
		{
			fout << Obj[i].Get_Name() << " " << Obj[i].Get_ID() << " " << Obj[i].Get_Price() << " " << Obj[i].Get_Stock() << endl;
		}
	}
	fout.close();
}

void Add_Info(vector<Shop>& Obj)
{
	system("cls");
	Shop Object;
	cout << "ID: ";
	cin >> ID;
	Object.Set_ID(ID);
	for (size_t i = 0; i < Obj.size(); i++)
	{
		if (Object.Get_ID() == Obj[i].Get_ID())
		{
			cout << "\nProduct \"";
			Obj[i].Display_Info();
			cout << " \" is available ...\a\n\nHow many \" " << Obj[i].Get_Name() << " \" you want to add (Input -1 To Back):\n\nInput: ";
			cin >> STOCK;
			if (STOCK == -1)
			{
				return;
			}
			Obj[i].Set_Stock(Obj[i].Get_Stock() + STOCK);
			Save_Info(Obj);
			cout << "Saved Successfully." << endl;
			system("pause");
			return;
		}
	}
	cout << "Name: ";
	cin.ignore();
	getline(cin, name);
	Object.Set_Name(name);
	cout << "Price: ";
	cin >> PRICE;
	Object.Set_Price(PRICE);
	cout << "Stock: ";
	cin >> STOCK;
	Object.Set_Stock(STOCK);
	Obj.push_back(Object);
	Save_Info(Obj);
	cout << "Saved SuccessFully." << endl;
	system("pause");
	return;
}

void Edit_Info(vector<Shop>& Obj)
{
	system("cls");
	cout << "\t\t\t\t           Edit Info:\n\n";
	for (size_t i = 0; i < Obj.size(); i++)
	{
		cout << i;
		Obj[i].Display_Info();
		cout << endl;
	}
	cout << "\nSelect Product For Editing Info: (Input -1 To Back):\n\nInput: ";
	int choice = 0;
	cin >> choice;

	if (choice == -1)
	{
		return;
	}

	try
	{
		Obj.at(choice);
	}
	catch (out_of_range& ex)
	{
		cout << "Exception Occured ->\a " << ex.what() << endl;
		system("pause");
		return;
	}

	Shop temp;
	temp = Obj[choice];
	bool edit = true;

	system("cls");

	cout << "1 - Name: " << temp.Get_Name() << endl;
	cout << "2 - ID: " << temp.Get_ID() << endl;
	cout << "3 - Price: " << temp.Get_Price() << endl;
	cout << "4 - Stock: " << temp.Get_Stock() << endl;
	cout << "\nSelect item: (Input -1 To Back)\n\nInput: ";
	
	while (edit)
	{
		int select = 0;
		cin >> select;
		cin.ignore();
		switch (select)
		{
		case 1:
			cout << "- Name: ";
			getline(cin, name);
			temp.Set_Name(name);
			break;
		case 2:
			cout << "- ID: ";
			cin >> ID;
			temp.Set_ID(ID);
			break;
		case 3:
			cout << "- Price: ";
			cin >> PRICE;
			temp.Set_Price(PRICE);
			break;
		case 4:
			cout << "- Stock: ";
			cin >> STOCK;
			temp.Set_Stock(STOCK);
			break;
		case -1:
			edit = false;
			break;
		}
		system("cls");
		cout << "1 - Name: " << temp.Get_Name() << endl;
		cout << "2 - ID: " << temp.Get_ID() << endl;
		cout << "3 - Price: " << temp.Get_Price() << endl;
		cout << "4 - Stock: " << temp.Get_Stock() << endl;
		cout << "\nSelect item: ";
	}

	Obj.erase(Obj.begin() + choice);

	Obj.push_back(temp);

	Save_Info(Obj);
	return;

}

void Delete_Info(vector<Shop>& Obj)
{
	system("cls");
	for (size_t i = 0; i < Obj.size(); i++)
	{
		cout << i;
		Obj[i].Display_Info();
		cout << endl;
	}
	int a = 0;
	cout << "\nSelect Item For Delete: (Input -1 To Back)\n\nInput: ";
	cin >> a;
	if (a == -1)
	{
		return;
	}
	try
	{
		Obj.at(a);
	}
	catch (out_of_range& ex)
	{
		cout << "Exception Occured ->\a " << ex.what() << endl;
		system("pause");
		return;
	}

	Obj.erase(Obj.begin() + a);
	Save_Info(Obj);
	cout << "Infomation Deleted Successfully.\a\n";
	system("pause");
	return;
}

void Search_Info(vector<Shop>& Obj)
{
	system("cls");
	cout << "\t\t\t\t           Search Info:\n\n";
	cout << "ID: ";
	cin >> ID;
	for (size_t i = 0; i < Obj.size(); i++)
	{
		if (ID == Obj[i].Get_ID())
		{
			Found = true;
			Obj[i].Display_Info();
		}
	}
	if (Found == false)
	{
		system("cls");
		cout << "No Product by ID: " << ID << " was found!\a\n";
	}

	cout << endl;
	system("pause");
	return;
}

void Buy(vector<Shop>& Obj)
{
	system("cls");
	Shop Cart;
	cout << "ID: ";
	cin >> ID;
	for (size_t i = 0; i < Obj.size(); i++)
	{
		if (ID == Obj[i].Get_ID())
		{
			Found = true;
			cout << "\nProduct \"";
			Obj[i].Display_Info();
			cout << " \" is available ...\a" << endl;
			cout << "\nHow many \" " << Obj[i].Get_Name() << " \" you want to buy (Input -1 To Back):\n\nInput: ";
			cin >> STOCK;
			if (STOCK == -1)
			{
				return;
			}
			if (STOCK <= Obj[i].Get_Stock())
			{
				Obj[i].Set_Stock(Obj[i].Get_Stock() - STOCK);
				Save_Info(Obj);
				Cart = Obj[i];
				system("cls");
				size_t Total_Purchase = 0;
				cout << "Your Sales Invoice ...\n\n";
				cout << "- Name: " << Cart.Get_Name() << " - ID: " << Cart.Get_ID() << " - Unit Price: " << Cart.Get_Price() << " - Stock: " << STOCK;
				Total_Purchase = STOCK * Cart.Get_Price();
				cout << "\n\nTotal Purchase: " << Total_Purchase << endl << endl;
				system("pause");
				return;
			}
			else if (STOCK > Obj[i].Get_Stock())
			{
				cout << "\nThe required number of products is not available ...\a\n" << endl;
				system("pause");
				return;
			}
		}
	}
	Found = false;
	if (Found == false)
	{
		system("cls");
		cout << "No Product by ID: " << ID << " was found!\a\n";
		system("pause");
		return;
	}

}

void Show_List(vector<Shop>& Obj)
{
	system("cls");
	for (size_t i = 0; i < Obj.size(); i++)
	{
		cout << i + 1;
		Obj[i].Display_Info();
		cout << endl;
	}
	system("pause");
	return;
}

void Menu_Controller(vector<Shop>& Obj, int select)
{
	switch (select)
	{
	case 1:Add_Info(Obj);
		break;
	case 2:Edit_Info(Obj);
		break;
	case 3:Delete_Info(Obj);
		break;
	case 4:Search_Info(Obj);
		break;
	case 5:Buy(Obj);
		break;
	case 6:Show_List(Obj);
		break;
	default:
		cout << "\t\t\t\t\t  Invalid Command!\a\n\n";
		system("pause");
		break;
	}
}