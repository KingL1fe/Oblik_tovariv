#pragma once

#include "../РГР/Inventory.h"
#include <msclr/marshal_cppstd.h>

namespace InventoryApp {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class AddEditProductForm : public System::Windows::Forms::Form
    {
    public:
        AddEditProductForm(int id, Inventory* inv)
        {
            inventory = inv;
            InitializeComponent();
            this->ProductId = id;
            this->Text = L"Додати продукт";
            LoadCategories();
        }

        AddEditProductForm(int id, String^ name, int quantity, double price, int categoryId, Inventory* inv)
        {
            inventory = inv;
            InitializeComponent();
            this->ProductId = id;
            this->txtName->Text = name;
            this->txtQuantity->Text = quantity.ToString();
            this->txtPrice->Text = price.ToString();
            this->Text = L"Редагувати продукт";
            LoadCategories();
            this->cmbCategory->SelectedValue = categoryId;
        }

        property int ProductId;
        property String^ ProductName {
            String^ get() { return txtName->Text; }
        }
        property int ProductQuantity {
            int get() { return Convert::ToInt32(txtQuantity->Text); }
        }
        property double ProductPrice {
            double get() { return Convert::ToDouble(txtPrice->Text); }
        }
        property int ProductCategoryId {
            int get() { return Convert::ToInt32(cmbCategory->SelectedValue); }
        }

    private:
        System::Windows::Forms::Label^ lblName;
        System::Windows::Forms::Label^ lblQuantity;
        System::Windows::Forms::Label^ lblPrice;
        System::Windows::Forms::Label^ lblCategory;
        System::Windows::Forms::TextBox^ txtName;
        System::Windows::Forms::TextBox^ txtQuantity;
        System::Windows::Forms::TextBox^ txtPrice;
        System::Windows::Forms::ComboBox^ cmbCategory;
        System::Windows::Forms::Button^ btnSave;
        System::Windows::Forms::Button^ btnCancel;
        Inventory* inventory;

        void LoadCategories()
        {
            DataTable^ dt = gcnew DataTable();
            dt->Columns->Add("Id", int::typeid);
            dt->Columns->Add("Name", String::typeid);

            // Додаємо опцію "Без категорії"
            DataRow^ defaultRow = dt->NewRow();
            defaultRow["Id"] = 0;
            defaultRow["Name"] = L"Без категорії";
            dt->Rows->Add(defaultRow);

            for (const Category& category : inventory->getAllCategories())
            {
                DataRow^ row = dt->NewRow();
                row["Id"] = category.getId();
                row["Name"] = gcnew String(category.getName().c_str());
                dt->Rows->Add(row);
            }

            cmbCategory->DataSource = dt;
            cmbCategory->DisplayMember = "Name";
            cmbCategory->ValueMember = "Id";
        }

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->lblName = (gcnew System::Windows::Forms::Label());
            this->lblQuantity = (gcnew System::Windows::Forms::Label());
            this->lblPrice = (gcnew System::Windows::Forms::Label());
            this->lblCategory = (gcnew System::Windows::Forms::Label());
            this->txtName = (gcnew System::Windows::Forms::TextBox());
            this->txtQuantity = (gcnew System::Windows::Forms::TextBox());
            this->txtPrice = (gcnew System::Windows::Forms::TextBox());
            this->cmbCategory = (gcnew System::Windows::Forms::ComboBox());
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

            // lblQuantity
            this->lblQuantity->AutoSize = true;
            this->lblQuantity->Location = System::Drawing::Point(12, 41);
            this->lblQuantity->Name = L"lblQuantity";
            this->lblQuantity->Size = System::Drawing::Size(55, 13);
            this->lblQuantity->TabIndex = 1;
            this->lblQuantity->Text = L"Кількість:";

            // lblPrice
            this->lblPrice->AutoSize = true;
            this->lblPrice->Location = System::Drawing::Point(12, 67);
            this->lblPrice->Name = L"lblPrice";
            this->lblPrice->Size = System::Drawing::Size(35, 13);
            this->lblPrice->TabIndex = 2;
            this->lblPrice->Text = L"Ціна:";

            // lblCategory
            this->lblCategory->AutoSize = true;
            this->lblCategory->Location = System::Drawing::Point(12, 93);
            this->lblCategory->Name = L"lblCategory";
            this->lblCategory->Size = System::Drawing::Size(55, 13);
            this->lblCategory->TabIndex = 3;
            this->lblCategory->Text = L"Категорія:";

            // txtName
            this->txtName->Location = System::Drawing::Point(80, 12);
            this->txtName->Name = L"txtName";
            this->txtName->Size = System::Drawing::Size(200, 20);
            this->txtName->TabIndex = 4;

            // txtQuantity
            this->txtQuantity->Location = System::Drawing::Point(80, 38);
            this->txtQuantity->Name = L"txtQuantity";
            this->txtQuantity->Size = System::Drawing::Size(200, 20);
            this->txtQuantity->TabIndex = 5;

            // txtPrice
            this->txtPrice->Location = System::Drawing::Point(80, 64);
            this->txtPrice->Name = L"txtPrice";
            this->txtPrice->Size = System::Drawing::Size(200, 20);
            this->txtPrice->TabIndex = 6;

            // cmbCategory
            this->cmbCategory->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->cmbCategory->Location = System::Drawing::Point(80, 90);
            this->cmbCategory->Name = L"cmbCategory";
            this->cmbCategory->Size = System::Drawing::Size(200, 21);
            this->cmbCategory->TabIndex = 7;

            // btnSave
            this->btnSave->Location = System::Drawing::Point(80, 126);
            this->btnSave->Name = L"btnSave";
            this->btnSave->Size = System::Drawing::Size(75, 23);
            this->btnSave->TabIndex = 8;
            this->btnSave->Text = L"Зберегти";
            this->btnSave->UseVisualStyleBackColor = true;
            this->btnSave->Click += gcnew System::EventHandler(this, &AddEditProductForm::btnSave_Click);

            // btnCancel
            this->btnCancel->Location = System::Drawing::Point(161, 126);
            this->btnCancel->Name = L"btnCancel";
            this->btnCancel->Size = System::Drawing::Size(75, 23);
            this->btnCancel->TabIndex = 9;
            this->btnCancel->Text = L"Скасувати";
            this->btnCancel->UseVisualStyleBackColor = true;
            this->btnCancel->Click += gcnew System::EventHandler(this, &AddEditProductForm::btnCancel_Click);

            // AddEditProductForm
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(294, 161);
            this->Controls->Add(this->btnCancel);
            this->Controls->Add(this->btnSave);
            this->Controls->Add(this->cmbCategory);
            this->Controls->Add(this->txtPrice);
            this->Controls->Add(this->txtQuantity);
            this->Controls->Add(this->txtName);
            this->Controls->Add(this->lblCategory);
            this->Controls->Add(this->lblPrice);
            this->Controls->Add(this->lblQuantity);
            this->Controls->Add(this->lblName);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
            this->MaximizeBox = false;
            this->MinimizeBox = false;
            this->Name = L"AddEditProductForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion

    private: System::Void btnSave_Click(System::Object^ sender, System::EventArgs^ e) {
        if (String::IsNullOrWhiteSpace(txtName->Text))
        {
            MessageBox::Show(L"Назва продукту не може бути порожньою.", L"Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        int quantity;
        double price;
        try
        {
            quantity = Convert::ToInt32(txtQuantity->Text);
            if (quantity < 0)
            {
                MessageBox::Show(L"Кількість не може бути від’ємною.", L"Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }
        }
        catch (FormatException^)
        {
            MessageBox::Show(L"Введіть коректне число для кількості.", L"Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        try
        {
            price = Convert::ToDouble(txtPrice->Text);
            if (price < 0)
            {
                MessageBox::Show(L"Ціна не може бути від’ємною.", L"Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }
        }
        catch (FormatException^)
        {
            MessageBox::Show(L"Введіть коректне число для ціни.", L"Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
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
