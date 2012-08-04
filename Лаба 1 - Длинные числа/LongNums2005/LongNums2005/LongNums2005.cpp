// Программа для умножения длинных чисел, 8 Вариант
// ИУ7-32, Исаев Денис

#include "stdafx.h"
#include "Form1.h"

using namespace LongNums2005;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew Form1());
	return 0;
}
