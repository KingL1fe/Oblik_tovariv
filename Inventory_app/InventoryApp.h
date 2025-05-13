#pragma once

#include "../РГР/Product.h"
#include "../РГР/Inventory.h"
#include "../РГР/Customer.h"
#include "../РГР/Category.h"
#include "../РГР/Discount.h"
#include "../РГР/Invoice.h"
#include "../РГР/Order.h"
#include "../РГР/Payment.h"
#include "../РГР/SalesReport.h"
#include "../РГР/Stock.h"
#include "../РГР/Supplier.h"
#include "../РГР/Warehouse.h"

namespace InventoryApp {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace std;

    public ref class InventoryApp : public System::Windows::Forms::Form
    {
    public:
        InventoryApp(void)
        {
            InitializeComponent();
            inventory = new Inventory();
            LoadSampleData();
        }

    protected:
        ~InventoryApp()
        {
            if (components)
                delete components;

            delete inventory;
        }

    private: System::Windows::Forms::DataGridView^ dataGridView1;
    private: System::Windows::Forms::TextBox^ txtSearch;
    private: System::Windows::Forms::Button^ btnSearch;
    private: System::Windows::Forms::Button^ btnAddSample;
    private: Inventory* inventory;
    private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
           void InitializeComponent(void)
           {
               this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
               this->txtSearch = (gcnew System::Windows::Forms::TextBox());
               this->btnSearch = (gcnew System::Windows::Forms::Button());
               this->btnAddSample = (gcnew System::Windows::Forms::Button());
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
               this->SuspendLayout();

               // dataGridView1
               this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
               this->dataGridView1->Location = System::Drawing::Point(12, 41);
               this->dataGridView1->Name = L"dataGridView1";
               this->dataGridView1->Size = System::Drawing::Size(560, 300);
               this->dataGridView1->TabIndex = 0;

               // txtSearch
               this->txtSearch->Location = System::Drawing::Point(12, 12);
               this->txtSearch->Name = L"txtSearch";
               this->txtSearch->Size = System::Drawing::Size(150, 20);
               this->txtSearch->TabIndex = 1;

               // btnSearch
               this->btnSearch->Location = System::Drawing::Point(168, 10);
               this->btnSearch->Name = L"btnSearch";
               this->btnSearch->Size = System::Drawing::Size(75, 23);
               this->btnSearch->TabIndex = 2;
               this->btnSearch->Text = L"Search";
               this->btnSearch->UseVisualStyleBackColor = true;
               this->btnSearch->Click += gcnew System::EventHandler(this, &InventoryApp::btnSearch_Click);

               // btnAddSample
               this->btnAddSample->Location = System::Drawing::Point(497, 10);
               this->btnAddSample->Name = L"btnAddSample";
               this->btnAddSample->Size = System::Drawing::Size(75, 23);
               this->btnAddSample->TabIndex = 3;
               this->btnAddSample->Text = L"Add Sample";
               this->btnAddSample->UseVisualStyleBackColor = true;
               this->btnAddSample->Click += gcnew System::EventHandler(this, &InventoryApp::btnAddSample_Click);

               // InventoryApp
               this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
               this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
               this->ClientSize = System::Drawing::Size(584, 361);
               this->Controls->Add(this->btnAddSample);
               this->Controls->Add(this->btnSearch);
               this->Controls->Add(this->txtSearch);
               this->Controls->Add(this->dataGridView1);
               this->Name = L"InventoryApp";
               this->Text = L"Inventory Application";
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
               this->ResumeLayout(false);
               this->PerformLayout();
           }
#pragma endregion

    private:
        void LoadSampleData()
        {
            inventory->addProduct(Product(1, "Laptop", 10, 999.99));
            inventory->addProduct(Product(2, "Mouse", 50, 19.99));
            inventory->addProduct(Product(3, "Keyboard", 20, 49.99));
            UpdateGrid();
        }

        void UpdateGrid()
        {
            dataGridView1->Rows->Clear();
            dataGridView1->Columns->Clear();

            dataGridView1->Columns->Add("ID", "ID");
            dataGridView1->Columns->Add("Name", "Name");
            dataGridView1->Columns->Add("Quantity", "Quantity");
            dataGridView1->Columns->Add("Price", "Price");

            for (const auto& product : inventory->getAllProducts())
            {
                dataGridView1->Rows->Add(product.getId(), gcnew String(product.getName().c_str()), product.getQuantity(), product.getPrice());
            }
        }

    private: System::Void btnSearch_Click(System::Object^ sender, System::EventArgs^ e) {
        String^ keyword = txtSearch->Text->ToLower();
        dataGridView1->Rows->Clear();

        for (const auto& product : inventory->getAllProducts())
        {
            String^ name = gcnew String(product.getName().c_str());
            if (name->ToLower()->Contains(keyword))
            {
                dataGridView1->Rows->Add(product.getId(), name, product.getQuantity(), product.getPrice());
            }
        }
    }

    private: System::Void btnAddSample_Click(System::Object^ sender, System::EventArgs^ e) {
        LoadSampleData();
    }
    };
}