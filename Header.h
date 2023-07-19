#pragma once
#include"MainClass.h"


int Main_Menu();
void Read_Data(vector<Shop>& Obj);
void Save_Info(vector<Shop>& Obj);
void Add_Info(vector<Shop>& Obj);
void Edit_Info(vector<Shop>& Obj);
void Delete_Info(vector<Shop>& Obj);
void Search_Info(vector<Shop>& Obj);
void Buy(vector<Shop>& Obj);
void Show_List(vector<Shop>& Obj);
void Menu_Controller(vector<Shop>& Obj, int select);