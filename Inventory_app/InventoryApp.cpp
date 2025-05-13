#include "InventoryApp.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int __clrcall main(cli::array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    InventoryApp::InventoryApp^ form = gcnew InventoryApp::InventoryApp();
    Application::Run(form);

    return 0;
}