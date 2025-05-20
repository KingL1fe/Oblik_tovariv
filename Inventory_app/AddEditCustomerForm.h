#include "../RGR/Customer.h"
#include <msclr/marshal_cppstd.h>

namespace InventoryApp {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::Text::RegularExpressions;

    public ref class AddEditCustomerForm : public System::Windows::Forms::Form
    {
    public:
        AddEditCustomerForm(int id)
        {
            InitializeComponent();
            this->CustomerId = id;
            this->Text = L"Додати клієнта";
        }

        AddEditCustomerForm(int id, String^ name, String^ contactInfo, String^ address)
        {
            InitializeComponent();
            this->CustomerId = id;
            this->txtName->Text = name;
            this->txtContactInfo->Text = contactInfo;
            this->txtAddress->Text = address;
            this->Text = L"Редагувати клієнта";
        }

        property int CustomerId;
        property String^ CustomerName {
            String^ get() { return txtName->Text; }
        }
        property String^ CustomerContactInfo {
            String^ get() { return txtContactInfo->Text; }
        }
        property String^ CustomerAddress {
            String^ get() { return txtAddress->Text; }
        }

    private:
        System::Windows::Forms::Label^ lblName;
        System::Windows::Forms::Label^ lblContactInfo;
        System::Windows::Forms::Label^ lblAddress;
        System::Windows::Forms::TextBox^ txtName;
        System::Windows::Forms::TextBox^ txtContactInfo;
        System::Windows::Forms::TextBox^ txtAddress;
        System::Windows::Forms::Button^ btnSave;
        System::Windows::Forms::Button^ btnCancel;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->lblName = (gcnew System::Windows::Forms::Label());
            this->lblContactInfo = (gcnew System::Windows::Forms::Label());
            this->lblAddress = (gcnew System::Windows::Forms::Label());
            this->txtName = (gcnew System::Windows::Forms::TextBox());
            this->txtContactInfo = (gcnew System::Windows::Forms::TextBox());
            this->txtAddress = (gcnew System::Windows::Forms::TextBox());
            this->btnSave = (gcnew System::Windows::Forms::Button());
            this->btnCancel = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();

            // lblName
            this->lblName->AutoSize = true;
            this->lblName->Location = System::Drawing::Point(12, 15);
            this->lblName->Name = L"lblName";
            this->lblName->Size = System::Drawing::Size(35, 13);
            this->lblName->TabIndex = 0;
            this->lblName->Text = L"Назва:";

            // lblContactInfo
            this->lblContactInfo->AutoSize = true;
            this->lblContactInfo->Location = System::Drawing::Point(12, 41);
            this->lblContactInfo->Name = L"lblContactInfo";
            this->lblContactInfo->Size = System::Drawing::Size(90, 13);
            this->lblContactInfo->TabIndex = 1;
            this->lblContactInfo->Text = L"Контактна інформація:";

            // lblAddress
            this->lblAddress->AutoSize = true;
            this->lblAddress->Location = System::Drawing::Point(12, 67);
            this->lblAddress->Name = L"lblAddress";
            this->lblAddress->Size = System::Drawing::Size(45, 13);
            this->lblAddress->TabIndex = 2;
            this->lblAddress->Text = L"Адреса:";

            // txtName
            this->txtName->Location = System::Drawing::Point(110, 12);
            this->txtName->Name = L"txtName";
            this->txtName->Size = System::Drawing::Size(200, 20);
            this->txtName->TabIndex = 3;

            // txtContactInfo
            this->txtContactInfo->Location = System::Drawing::Point(110, 38);
            this->txtContactInfo->Name = L"txtContactInfo";
            this->txtContactInfo->Size = System::Drawing::Size(200, 20);
            this->txtContactInfo->TabIndex = 4;

            // txtAddress
            this->txtAddress->Location = System::Drawing::Point(110, 64);
            this->txtAddress->Name = L"txtAddress";
            this->txtAddress->Size = System::Drawing::Size(200, 20);
            this->txtAddress->TabIndex = 5;

            // btnSave
            this->btnSave->Location = System::Drawing::Point(110, 100);
            this->btnSave->Name = L"btnSave";
            this->btnSave->Size = System::Drawing::Size(75, 23);
            this->btnSave->TabIndex = 6;
            this->btnSave->Text = L"Зберегти";
            this->btnSave->UseVisualStyleBackColor = true;
            this->btnSave->Click += gcnew System::EventHandler(this, &AddEditCustomerForm::btnSave_Click);

            // btnCancel
            this->btnCancel->Location = System::Drawing::Point(191, 100);
            this->btnCancel->Name = L"btnCancel";
            this->btnCancel->Size = System::Drawing::Size(75, 23);
            this->btnCancel->TabIndex = 7;
            this->btnCancel->Text = L"Скасувати";
            this->btnCancel->UseVisualStyleBackColor = true;
            this->btnCancel->Click += gcnew System::EventHandler(this, &AddEditCustomerForm::btnCancel_Click);

            // AddEditCustomerForm
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(324, 135);
            this->Controls->Add(this->btnCancel);
            this->Controls->Add(this->btnSave);
            this->Controls->Add(this->txtAddress);
            this->Controls->Add(this->txtContactInfo);
            this->Controls->Add(this->txtName);
            this->Controls->Add(this->lblAddress);
            this->Controls->Add(this->lblContactInfo);
            this->Controls->Add(this->lblName);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
            this->MaximizeBox = false;
            this->MinimizeBox = false;
            this->Name = L"AddEditCustomerForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion

    private: System::Void btnSave_Click(System::Object^ sender, System::EventArgs^ e) {
        if (String::IsNullOrWhiteSpace(txtName->Text)) {
            MessageBox::Show(L"Назва клієнта не може бути порожньою.", L"Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        if (String::IsNullOrWhiteSpace(txtContactInfo->Text)) {
            MessageBox::Show(L"Контактна інформація не може бути порожньою.", L"Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        // Валідація контактної інформації (телефон або email)
        String^ contactInfo = txtContactInfo->Text;
        Regex^ phoneRegex = gcnew Regex("^[\\+]?[0-9]{10,13}$");
        Regex^ emailRegex = gcnew Regex("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
        if (!phoneRegex->IsMatch(contactInfo) && !emailRegex->IsMatch(contactInfo)) {
            MessageBox::Show(L"Введіть коректний номер телефону (10-13 цифр) або email.", L"Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        this->DialogResult = System::Windows::Forms::DialogResult::OK;
        this->Close();
    }

    private: System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e) {
        this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
        this->Close();
    }
    };
}
