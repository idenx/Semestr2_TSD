// TSD-2.cpp: главный файл проекта.
#include "stdafx.h"
#include "Form1.h"
//#include <locale.h>
using namespace TSD2;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	//setlocale( LC_CTYPE, "Russian_Russia.1251" );

	// Включение визуальных эффектов Windows XP до создания каких-либо элементов управления
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Создание главного окна и его запуск
	Application::Run(gcnew Form1());
	return 0;
}
