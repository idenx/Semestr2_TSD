// TSD-2.cpp: ������� ���� �������.
#include "stdafx.h"
#include "Form1.h"
//#include <locale.h>
using namespace TSD2;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	//setlocale( LC_CTYPE, "Russian_Russia.1251" );

	// ��������� ���������� �������� Windows XP �� �������� �����-���� ��������� ����������
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// �������� �������� ���� � ��� ������
	Application::Run(gcnew Form1());
	return 0;
}
