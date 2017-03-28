#include "MyForm.h"
#include "MyForm1.h"
#include "MyForm21.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace CppWinForm1;


[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);





	CppWinForm1::MyForm form;
	Application::Run(%form);

	
}

