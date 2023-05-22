#include "MyForm.h"
#include "FormExplorer.h"

#include <Windows.h>
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(cli::array<String^>^ args) {
	ShowWindow(GetConsoleWindow(), SW_HIDE);
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	StabCLR::MyForm form;
	Application::Run(% form);
}