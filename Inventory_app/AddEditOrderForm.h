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
    using namespace System::Collections::Generic;

    public ref class AddEditOrderForm : public System::Windows::Forms::Form
    {
    public:
        AddEditOrderForm(int orderId, Inventory* inv)
        {
            InitializeComponent();
            inventory = inv;
            OrderId = orderId;
            ProductQuantities = gcnew List<Dictionary<String^, Object^>^>();
            InitializeComboBoxes();
        }

        AddEditOrderForm(int orderId, int customerId, String^ orderDate, String^ status,
            List<Dictionary<String^, Object^>^>^ productQuantities, double totalAmount, Inventory* inv)
        {
            InitializeComponent();
            inventory = inv;
            OrderId = orderId;
            CustomerId = customerId;
            OrderDate = orderDate;
            OrderStatus = status;
            ProductQuantities = productQuantities;
            TotalAmount = totalAmount;
            InitializeComboBoxes();
            PopulateFields();
        }

        property int OrderId;
        property int CustomerId;
        property String^ OrderDate;
        property String^ OrderStatus;
        property List<Dictionary<String^, Object^>^>^ ProductQuantities;
        property double TotalAmount;

    private:
        Inventory* inventory;
        System::Windows::Forms::ComboBox^ comboBoxCustomers;
        System::Windows::Forms::ComboBox^ comboBoxProducts;
        System::Windows::Forms::TextBox^ txtOrderDate;
        System::Windows::Forms::ComboBox^ comboBoxStatus;
        System::Windows::Forms::TextBox^ txtQuantity;
        System::Windows::Forms::TextBox^ txtTotalAmount;
        System::Windows::Forms::DataGridView^ dataGridViewProducts;
        System::Windows::Forms::Button^ btnAddProduct;
        System::Windows::Forms::Button^ btnRemoveProduct;
        System::Windows::Forms::Button^ btnOK;
        System::Windows::Forms::Button^ btnCancel;

        void InitializeComboBoxes()
        {
            // Ініціалізація клієнтів
            comboBoxCustomers->Items->Clear();
            for (const Customer& customer : inventory->getAllCustomers())
            {
                comboBoxCustomers->Items->Add(gcnew String(customer.getName().c_str()));
            }
            if (comboBoxCustomers->Items->Count > 0)
                comboBoxCustomers->SelectedIndex = 0;

            // Ініціалізація продуктів
            comboBoxProducts->Items->Clear();
            for (const Product& product : inventory->getAllProducts())
            {
                comboBoxProducts->Items->Add(gcnew String(product.getName().c_str()));
            }
            if (comboBoxProducts->Items->Count > 0)
                comboBoxProducts->SelectedIndex = 0;

            // Ініціалізація статусів
            comboBoxStatus->Items->Clear();
            comboBoxStatus->Items->Add(L"Нове");
            comboBoxStatus->Items->Add(L"Виконане");
            comboBoxStatus->Items->Add(L"Скасоване");
            comboBoxStatus->SelectedIndex = 0;
        }

        void PopulateFields()
        {
            // Заповнення полів для редагування
            for (int i = 0; i < comboBoxCustomers->Items->Count; i++)
            {
                Customer* customer = inventory->findCustomerById(CustomerId);
                if (customer && comboBoxCustomers->Items[i]->ToString() == gcnew String(customer->getName().c_str()))
                {
                    comboBoxCustomers->SelectedIndex = i;
                    break;
                }
            }
            txtOrderDate->Text = OrderDate;
            comboBoxStatus->SelectedItem = OrderStatus;
            txtTotalAmount->Text = TotalAmount.ToString();

            // Заповнення таблиці продуктів
            dataGridViewProducts->Rows->Clear();
            for each (Dictionary<String^, Object^> ^ item in ProductQuantities)
            {
                int productId = Convert::ToInt32(item["ProductId"]);
                Product* product = inventory->findProductById(productId);
                if (product)
                {
                    dataGridViewProducts->Rows->Add(productId, gcnew String(product->getName().c_str()), item["Quantity"]);
                }
            }
        }

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->comboBoxCustomers = (gcnew System::Windows::Forms::ComboBox());
            this->comboBoxProducts = (gcnew System::Windows::Forms::ComboBox());
            this->txtOrderDate = (gcnew System::Windows::Forms::TextBox());
            this->comboBoxStatus = (gcnew System::Windows::Forms::ComboBox());
            this->txtQuantity = (gcnew System::Windows::Forms::TextBox());
            this->txtTotalAmount = (gcnew System::Windows::Forms::TextBox());
            this->dataGridViewProducts = (gcnew System::Windows::Forms::DataGridView());
            this->btnAddProduct = (gcnew System::Windows::Forms::Button());
            this->btnRemoveProduct = (gcnew System::Windows::Forms::Button());
            this->btnOK = (gcnew System::Windows::Forms::Button());
            this->btnCancel = (gcnew System::Windows::Forms::Button());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewProducts))->BeginInit();
            this->SuspendLayout();

            // comboBoxCustomers
            this->comboBoxCustomers->FormattingEnabled = true;
            this->comboBoxCustomers->Location = System::Drawing::Point(150, 12);
            this->comboBoxCustomers->Name = L"comboBoxCustomers";
            this->comboBoxCustomers->Size = System::Drawing::Size(200, 21);
            this->comboBoxCustomers->TabIndex = 0;

            // comboBoxProducts
            this->comboBoxProducts->FormattingEnabled = true;
            this->comboBoxProducts->Location = System::Drawing::Point(150, 70);
            this->comboBoxProducts->Name = L"comboBoxProducts";
            this->comboBoxProducts->Size = System::Drawing::Size(200, 21);
            this->comboBoxProducts->TabIndex = 1;

            // txtOrderDate
            this->txtOrderDate->Location = System::Drawing::Point(150, 40);
            this->txtOrderDate->Name = L"txtOrderDate";
            this->txtOrderDate->Size = System::Drawing::Size(200, 20);
            this->txtOrderDate->TabIndex = 2;

            // comboBoxStatus
            this->comboBoxStatus->FormattingEnabled = true;
            this->comboBoxStatus->Location = System::Drawing::Point(150, 98);
            this->comboBoxStatus->Name = L"comboBoxStatus";
            this->comboBoxStatus->Size = System::Drawing::Size(200, 21);
            this->comboBoxStatus->TabIndex = 3;

            // txtQuantity
            this->txtQuantity->Location = System::Drawing::Point(360, 70);
            this->txtQuantity->Name = L"txtQuantity";
            this->txtQuantity->Size = System::Drawing::Size(50, 20);
            this->txtQuantity->TabIndex = 4;

            // txtTotalAmount
            this->txtTotalAmount->Location = System::Drawing::Point(150, 126);
            this->txtTotalAmount->Name = L"txtTotalAmount";
            this->txtTotalAmount->Size = System::Drawing::Size(200, 20);
            this->txtTotalAmount->TabIndex = 5;
            this->txtTotalAmount->ReadOnly = true;

            // dataGridViewProducts
            this->dataGridViewProducts->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridViewProducts->Columns->Add("ProductId", "ID");
            this->dataGridViewProducts->Columns->Add("ProductName", "Назва");
            this->dataGridViewProducts->Columns->Add("Quantity", "Кількість");
            this->dataGridViewProducts->Location = System::Drawing::Point(12, 152);
            this->dataGridViewProducts->Name = L"dataGridViewProducts";
            this->dataGridViewProducts->Size = System::Drawing::Size(398, 150);
            this->dataGridViewProducts->TabIndex = 6;
            this->dataGridViewProducts->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
            this->dataGridViewProducts->MultiSelect = false;

            // btnAddProduct
            this->btnAddProduct->Location = System::Drawing::Point(416, 152);
            this->btnAddProduct->Name = L"btnAddProduct";
            this->btnAddProduct->Size = System::Drawing::Size(75, 23);
            this->btnAddProduct->TabIndex = 7;
            this->btnAddProduct->Text = L"Додати";
            this->btnAddProduct->UseVisualStyleBackColor = true;
            this->btnAddProduct->Click += gcnew System::EventHandler(this, &AddEditOrderForm::btnAddProduct_Click);

            // btnRemoveProduct
            this->btnRemoveProduct->Location = System::Drawing::Point(416, 181);
            this->btnRemoveProduct->Name = L"btnRemoveProduct";
            this->btnRemoveProduct->Size = System::Drawing::Size(75, 23);
            this->btnRemoveProduct->TabIndex = 8;
            this->btnRemoveProduct->Text = L"Видалити";
            this->btnRemoveProduct->UseVisualStyleBackColor = true;
            this->btnRemoveProduct->Click += gcnew System::EventHandler(this, &AddEditOrderForm::btnRemoveProduct_Click);

            // btnOK
            this->btnOK->Location = System::Drawing::Point(335, 308);
            this->btnOK->Name = L"btnOK";
            this->btnOK->Size = System::Drawing::Size(75, 23);
            this->btnOK->TabIndex = 9;
            this->btnOK->Text = L"OK";
            this->btnOK->UseVisualStyleBackColor = true;
            this->btnOK->Click += gcnew System::EventHandler(this, &AddEditOrderForm::btnOK_Click);

            // btnCancel
            this->btnCancel->Location = System::Drawing::Point(416, 308);
            this->btnCancel->Name = L"btnCancel";
            this->btnCancel->Size = System::Drawing::Size(75, 23);
            this->btnCancel->TabIndex = 10;
            this->btnCancel->Text = L"Скасувати";
            this->btnCancel->UseVisualStyleBackColor = true;
            this->btnCancel->Click += gcnew System::EventHandler(this, &AddEditOrderForm::btnCancel_Click);

            // Form
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(504, 341);
            this->Controls->Add(this->btnCancel);
            this->Controls->Add(this->btnOK);
            this->Controls->Add(this->btnRemoveProduct);
            this->Controls->Add(this->btnAddProduct);
            this->Controls->Add(this->dataGridViewProducts);
            this->Controls->Add(this->txtTotalAmount);
            this->Controls->Add(this->txtQuantity);
            this->Controls->Add(this->comboBoxStatus);
            this->Controls->Add(this->txtOrderDate);
            this->Controls->Add(this->comboBoxProducts);
            this->Controls->Add(this->comboBoxCustomers);
            this->Name = L"AddEditOrderForm";
            this->Text = L"Додати/Редагувати замовлення";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewProducts))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion

    private:
        System::Void btnAddProduct_Click(System::Object^ sender, System::EventArgs^ e) {
            if (comboBoxProducts->SelectedIndex == -1 || String::IsNullOrEmpty(txtQuantity->Text))
            {
                MessageBox::Show(L"Будь ласка, виберіть продукт і вкажіть кількість.", L"Помилка",
                    MessageBoxButtons::OK, MessageBoxIcon::Warning);
                return;
            }

            int quantity;
            if (!Int32::TryParse(txtQuantity->Text, quantity) || quantity <= 0)
            {
                MessageBox::Show(L"Вкажіть коректну кількість.", L"Помилка",
                    MessageBoxButtons::OK, MessageBoxIcon::Warning);
                return;
            }

            int productIndex = comboBoxProducts->SelectedIndex;
            Product* product = inventory->findProductById(productIndex + 1);
            if (product)
            {
                Dictionary<String^, Object^>^ item = gcnew Dictionary<String^, Object^>();
                item->Add("ProductId", product->getId());
                item->Add("Quantity", quantity);
                ProductQuantities->Add(item);

                dataGridViewProducts->Rows->Add(product->getId(), comboBoxProducts->SelectedItem->ToString(), quantity);

                // Оновлення загальної суми
                double price = product->getPrice();
                TotalAmount += price * quantity;
                txtTotalAmount->Text = TotalAmount.ToString();
            }
        }

        System::Void btnRemoveProduct_Click(System::Object^ sender, System::EventArgs^ e) {
            if (dataGridViewProducts->SelectedRows->Count > 0)
            {
                int index = dataGridViewProducts->SelectedRows[0]->Index;
                int productId = Convert::ToInt32(dataGridViewProducts->Rows[index]->Cells[0]->Value);
                int quantity = Convert::ToInt32(dataGridViewProducts->Rows[index]->Cells[2]->Value);
                Product* product = inventory->findProductById(productId);
                if (product)
                {
                    TotalAmount -= product->getPrice() * quantity;
                    txtTotalAmount->Text = TotalAmount.ToString();
                }
                ProductQuantities->RemoveAt(index);
                dataGridViewProducts->Rows->RemoveAt(index);
            }
            else
            {
                MessageBox::Show(L"Будь ласка, виберіть продукт для видалення.", L"Помилка",
                    MessageBoxButtons::OK, MessageBoxIcon::Warning);
            }
        }

        System::Void btnOK_Click(System::Object^ sender, System::EventArgs^ e) {
            if (comboBoxCustomers->SelectedIndex == -1 || String::IsNullOrEmpty(txtOrderDate->Text) ||
                ProductQuantities->Count == 0)
            {
                MessageBox::Show(L"Заповніть усі обов’язкові поля та додайте хоча б один продукт.", L"Помилка",
                    MessageBoxButtons::OK, MessageBoxIcon::Warning);
                return;
            }

            CustomerId = inventory->getAllCustomers()[comboBoxCustomers->SelectedIndex].getId();
            OrderDate = txtOrderDate->Text;
            OrderStatus = comboBoxStatus->SelectedItem->ToString();
            this->DialogResult = System::Windows::Forms::DialogResult::OK;
            this->Close();
        }

        System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e) {
            this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
            this->Close();
        }
    };
}
