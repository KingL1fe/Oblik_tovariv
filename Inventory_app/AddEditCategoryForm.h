#pragma once

namespace InventoryApp {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class AddEditCategoryForm : public System::Windows::Forms::Form
    {
    public:
        AddEditCategoryForm(int id)
        {
            InitializeComponent();
            this->CategoryId = id;
            //this->Text = L"Додати категорію";
        }

        AddEditCategoryForm(int id, String^ name)
        {
            InitializeComponent();
            this->CategoryId = id;
            this->txtName->Text = name;
            this->Text = L"Редагувати категорію";
        }

        property int CategoryId;
        property String^ CategoryName {
            String^ get() { return txtName->Text; }
        }

    private:
        System::Windows::Forms::Label^ lblName;
        System::Windows::Forms::TextBox^ txtName;
        System::Windows::Forms::Button^ btnSave;
        System::Windows::Forms::Button^ btnCancel;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->lblName = (gcnew System::Windows::Forms::Label());
            this->txtName = (gcnew System::Windows::Forms::TextBox());
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

            // txtName
            this->txtName->Location = System::Drawing::Point(80, 12);
            this->txtName->Name = L"txtName";
            this->txtName->Size = System::Drawing::Size(200, 20);
            this->txtName->TabIndex = 1;

            // btnSave
            this->btnSave->Location = System::Drawing::Point(80, 50);
            this->btnSave->Name = L"btnSave";
            this->btnSave->Size = System::Drawing::Size(75, 23);
            this->btnSave->TabIndex = 2;
            this->btnSave->Text = L"Зберегти";
            this->btnSave->UseVisualStyleBackColor = true;
            this->btnSave->Click += gcnew System::EventHandler(this, &AddEditCategoryForm::btnSave_Click);

            // btnCancel
            this->btnCancel->Location = System::Drawing::Point(161, 50);
            this->btnCancel->Name = L"btnCancel";
            this->btnCancel->Size = System::Drawing::Size(75, 23);
            this->btnCancel->TabIndex = 3;
            this->btnCancel->Text = L"Скасувати";
            this->btnCancel->UseVisualStyleBackColor = true;
            this->btnCancel->Click += gcnew System::EventHandler(this, &AddEditCategoryForm::btnCancel_Click);

            // AddEditCategoryForm
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(294, 85);
            this->Controls->Add(this->btnCancel);
            this->Controls->Add(this->btnSave);
            this->Controls->Add(this->txtName);
            this->Controls->Add(this->lblName);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
            this->MaximizeBox = false;
            this->MinimizeBox = false;
            this->Name = L"AddEditCategoryForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion

    private: System::Void btnSave_Click(System::Object^ sender, System::EventArgs^ e) {
        if (String::IsNullOrWhiteSpace(txtName->Text))
        {
            MessageBox::Show(L"Назва категорії не може бути порожньою.", L"Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
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
