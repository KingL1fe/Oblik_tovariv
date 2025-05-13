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
#include "AddEditProductForm.h"
#include <msclr/marshal_cppstd.h> // Додано для marshal_as

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

    private: System::Windows::Forms::TabControl^ tabControl;
    private: System::Windows::Forms::TabPage^ tabProducts;
    private: System::Windows::Forms::TabPage^ tabCategories;
    private: System::Windows::Forms::TabPage^ tabCustomers;
    private: System::Windows::Forms::TabPage^ tabSuppliers;
    private: System::Windows::Forms::TabPage^ tabOrders;
    private: System::Windows::Forms::TabPage^ tabInvoices;
    private: System::Windows::Forms::TabPage^ tabDiscounts;
    private: System::Windows::Forms::TabPage^ tabPayments;
    private: System::Windows::Forms::TabPage^ tabSalesReports;
    private: System::Windows::Forms::TabPage^ tabStocks;
    private: System::Windows::Forms::TabPage^ tabWarehouses;
    private: System::Windows::Forms::DataGridView^ dataGridViewProducts;
    private: System::Windows::Forms::DataGridView^ dataGridViewCategories;
    private: System::Windows::Forms::DataGridView^ dataGridViewCustomers;
    private: System::Windows::Forms::DataGridView^ dataGridViewSuppliers;
    private: System::Windows::Forms::DataGridView^ dataGridViewOrders;
    private: System::Windows::Forms::DataGridView^ dataGridViewInvoices;
    private: System::Windows::Forms::DataGridView^ dataGridViewDiscounts;
    private: System::Windows::Forms::DataGridView^ dataGridViewPayments;
    private: System::Windows::Forms::DataGridView^ dataGridViewSalesReports;
    private: System::Windows::Forms::DataGridView^ dataGridViewStocks;
    private: System::Windows::Forms::DataGridView^ dataGridViewWarehouses;
    private: System::Windows::Forms::TextBox^ txtSearch;
    private: System::Windows::Forms::Button^ btnSearch;
    private: System::Windows::Forms::Button^ btnAddSample;
    private: System::Windows::Forms::Button^ btnAddProduct;
    private: System::Windows::Forms::Button^ btnEditProduct;
    private: System::Windows::Forms::Button^ btnDeleteProduct;
    private: Inventory* inventory;
    private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
           void InitializeComponent(void)
           {
               this->tabControl = (gcnew System::Windows::Forms::TabControl());
               this->tabProducts = (gcnew System::Windows::Forms::TabPage());
               this->tabCategories = (gcnew System::Windows::Forms::TabPage());
               this->tabCustomers = (gcnew System::Windows::Forms::TabPage());
               this->tabSuppliers = (gcnew System::Windows::Forms::TabPage());
               this->tabOrders = (gcnew System::Windows::Forms::TabPage());
               this->tabInvoices = (gcnew System::Windows::Forms::TabPage());
               this->tabDiscounts = (gcnew System::Windows::Forms::TabPage());
               this->tabPayments = (gcnew System::Windows::Forms::TabPage());
               this->tabSalesReports = (gcnew System::Windows::Forms::TabPage());
               this->tabStocks = (gcnew System::Windows::Forms::TabPage());
               this->tabWarehouses = (gcnew System::Windows::Forms::TabPage());
               this->dataGridViewProducts = (gcnew System::Windows::Forms::DataGridView());
               this->dataGridViewCategories = (gcnew System::Windows::Forms::DataGridView());
               this->dataGridViewCustomers = (gcnew System::Windows::Forms::DataGridView());
               this->dataGridViewSuppliers = (gcnew System::Windows::Forms::DataGridView());
               this->dataGridViewOrders = (gcnew System::Windows::Forms::DataGridView());
               this->dataGridViewInvoices = (gcnew System::Windows::Forms::DataGridView());
               this->dataGridViewDiscounts = (gcnew System::Windows::Forms::DataGridView());
               this->dataGridViewPayments = (gcnew System::Windows::Forms::DataGridView());
               this->dataGridViewSalesReports = (gcnew System::Windows::Forms::DataGridView());
               this->dataGridViewStocks = (gcnew System::Windows::Forms::DataGridView());
               this->dataGridViewWarehouses = (gcnew System::Windows::Forms::DataGridView());
               this->txtSearch = (gcnew System::Windows::Forms::TextBox());
               this->btnSearch = (gcnew System::Windows::Forms::Button());
               this->btnAddSample = (gcnew System::Windows::Forms::Button());
               this->btnAddProduct = (gcnew System::Windows::Forms::Button());
               this->btnEditProduct = (gcnew System::Windows::Forms::Button());
               this->btnDeleteProduct = (gcnew System::Windows::Forms::Button());
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewProducts))->BeginInit();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewCategories))->BeginInit();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewCustomers))->BeginInit();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewSuppliers))->BeginInit();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewOrders))->BeginInit();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewInvoices))->BeginInit();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewDiscounts))->BeginInit();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewPayments))->BeginInit();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewSalesReports))->BeginInit();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewStocks))->BeginInit();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewWarehouses))->BeginInit();
               this->tabProducts->SuspendLayout();
               this->tabCategories->SuspendLayout();
               this->tabCustomers->SuspendLayout();
               this->tabSuppliers->SuspendLayout();
               this->tabOrders->SuspendLayout();
               this->tabInvoices->SuspendLayout();
               this->tabDiscounts->SuspendLayout();
               this->tabPayments->SuspendLayout();
               this->tabSalesReports->SuspendLayout();
               this->tabStocks->SuspendLayout();
               this->tabWarehouses->SuspendLayout();
               this->tabControl->SuspendLayout();
               this->SuspendLayout();

               // tabControl
               this->tabControl->Location = System::Drawing::Point(12, 41);
               this->tabControl->Name = L"tabControl";
               this->tabControl->SelectedIndex = 0;
               this->tabControl->Size = System::Drawing::Size(560, 300);
               this->tabControl->TabIndex = 0;
               this->tabControl->Controls->Add(this->tabProducts);
               this->tabControl->Controls->Add(this->tabCategories);
               this->tabControl->Controls->Add(this->tabCustomers);
               this->tabControl->Controls->Add(this->tabSuppliers);
               this->tabControl->Controls->Add(this->tabOrders);
               this->tabControl->Controls->Add(this->tabInvoices);
               this->tabControl->Controls->Add(this->tabDiscounts);
               this->tabControl->Controls->Add(this->tabPayments);
               this->tabControl->Controls->Add(this->tabSalesReports);
               this->tabControl->Controls->Add(this->tabStocks);
               this->tabControl->Controls->Add(this->tabWarehouses);

               // tabProducts
               this->tabProducts->Controls->Add(this->btnDeleteProduct);
               this->tabProducts->Controls->Add(this->btnEditProduct);
               this->tabProducts->Controls->Add(this->btnAddProduct);
               this->tabProducts->Controls->Add(this->dataGridViewProducts);
               this->tabProducts->Location = System::Drawing::Point(4, 22);
               this->tabProducts->Name = L"tabProducts";
               this->tabProducts->Padding = System::Windows::Forms::Padding(3);
               this->tabProducts->Size = System::Drawing::Size(552, 274);
               this->tabProducts->TabIndex = 0;
               this->tabProducts->Text = L"Продукти";

               // tabCategories
               this->tabCategories->Controls->Add(this->dataGridViewCategories);
               this->tabCategories->Location = System::Drawing::Point(4, 22);
               this->tabCategories->Name = L"tabCategories";
               this->tabCategories->Padding = System::Windows::Forms::Padding(3);
               this->tabCategories->Size = System::Drawing::Size(552, 274);
               this->tabCategories->TabIndex = 1;
               this->tabCategories->Text = L"Категорії";

               // tabCustomers
               this->tabCustomers->Controls->Add(this->dataGridViewCustomers);
               this->tabCustomers->Location = System::Drawing::Point(4, 22);
               this->tabCustomers->Name = L"tabCustomers";
               this->tabCustomers->Padding = System::Windows::Forms::Padding(3);
               this->tabCustomers->Size = System::Drawing::Size(552, 274);
               this->tabCustomers->TabIndex = 2;
               this->tabCustomers->Text = L"Клієнти";

               // tabSuppliers
               this->tabSuppliers->Controls->Add(this->dataGridViewSuppliers);
               this->tabSuppliers->Location = System::Drawing::Point(4, 22);
               this->tabSuppliers->Name = L"tabSuppliers";
               this->tabSuppliers->Padding = System::Windows::Forms::Padding(3);
               this->tabSuppliers->Size = System::Drawing::Size(552, 274);
               this->tabSuppliers->TabIndex = 3;
               this->tabSuppliers->Text = L"Постачальники";

               // tabOrders
               this->tabOrders->Controls->Add(this->dataGridViewOrders);
               this->tabOrders->Location = System::Drawing::Point(4, 22);
               this->tabOrders->Name = L"tabOrders";
               this->tabOrders->Padding = System::Windows::Forms::Padding(3);
               this->tabOrders->Size = System::Drawing::Size(552, 274);
               this->tabOrders->TabIndex = 4;
               this->tabOrders->Text = L"Замовлення";

               // tabInvoices
               this->tabInvoices->Controls->Add(this->dataGridViewInvoices);
               this->tabInvoices->Location = System::Drawing::Point(4, 22);
               this->tabInvoices->Name = L"tabInvoices";
               this->tabInvoices->Padding = System::Windows::Forms::Padding(3);
               this->tabInvoices->Size = System::Drawing::Size(552, 274);
               this->tabInvoices->TabIndex = 5;
               this->tabInvoices->Text = L"Рахунки";

               // tabDiscounts
               this->tabDiscounts->Controls->Add(this->dataGridViewDiscounts);
               this->tabDiscounts->Location = System::Drawing::Point(4, 22);
               this->tabDiscounts->Name = L"tabDiscounts";
               this->tabDiscounts->Padding = System::Windows::Forms::Padding(3);
               this->tabDiscounts->Size = System::Drawing::Size(552, 274);
               this->tabDiscounts->TabIndex = 6;
               this->tabDiscounts->Text = L"Знижки";

               // tabPayments
               this->tabPayments->Controls->Add(this->dataGridViewPayments);
               this->tabPayments->Location = System::Drawing::Point(4, 22);
               this->tabPayments->Name = L"tabPayments";
               this->tabPayments->Padding = System::Windows::Forms::Padding(3);
               this->tabPayments->Size = System::Drawing::Size(552, 274);
               this->tabPayments->TabIndex = 7;
               this->tabPayments->Text = L"Платежі";

               // tabSalesReports
               this->tabSalesReports->Controls->Add(this->dataGridViewSalesReports);
               this->tabSalesReports->Location = System::Drawing::Point(4, 22);
               this->tabSalesReports->Name = L"tabSalesReports";
               this->tabSalesReports->Padding = System::Windows::Forms::Padding(3);
               this->tabSalesReports->Size = System::Drawing::Size(552, 274);
               this->tabSalesReports->TabIndex = 8;
               this->tabSalesReports->Text = L"Звіти про продажі";

               // tabStocks
               this->tabStocks->Controls->Add(this->dataGridViewStocks);
               this->tabStocks->Location = System::Drawing::Point(4, 22);
               this->tabStocks->Name = L"tabStocks";
               this->tabStocks->Padding = System::Windows::Forms::Padding(3);
               this->tabStocks->Size = System::Drawing::Size(552, 274);
               this->tabStocks->TabIndex = 9;
               this->tabStocks->Text = L"Запаси";

               // tabWarehouses
               this->tabWarehouses->Controls->Add(this->dataGridViewWarehouses);
               this->tabWarehouses->Location = System::Drawing::Point(4, 22);
               this->tabWarehouses->Name = L"tabWarehouses";
               this->tabWarehouses->Padding = System::Windows::Forms::Padding(3);
               this->tabWarehouses->Size = System::Drawing::Size(552, 274);
               this->tabWarehouses->TabIndex = 10;
               this->tabWarehouses->Text = L"Склади";

               // dataGridViewProducts
               this->dataGridViewProducts->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
               this->dataGridViewProducts->Location = System::Drawing::Point(6, 6);
               this->dataGridViewProducts->Name = L"dataGridViewProducts";
               this->dataGridViewProducts->Size = System::Drawing::Size(540, 200);
               this->dataGridViewProducts->TabIndex = 0;
               this->dataGridViewProducts->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
               this->dataGridViewProducts->MultiSelect = false;

               // dataGridViewCategories
               this->dataGridViewCategories->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
               this->dataGridViewCategories->Location = System::Drawing::Point(6, 6);
               this->dataGridViewCategories->Name = L"dataGridViewCategories";
               this->dataGridViewCategories->Size = System::Drawing::Size(540, 262);
               this->dataGridViewCategories->TabIndex = 0;

               // dataGridViewCustomers
               this->dataGridViewCustomers->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
               this->dataGridViewCustomers->Location = System::Drawing::Point(6, 6);
               this->dataGridViewCustomers->Name = L"dataGridViewCustomers";
               this->dataGridViewCustomers->Size = System::Drawing::Size(540, 262);
               this->dataGridViewCustomers->TabIndex = 0;

               // dataGridViewSuppliers
               this->dataGridViewSuppliers->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
               this->dataGridViewSuppliers->Location = System::Drawing::Point(6, 6);
               this->dataGridViewSuppliers->Name = L"dataGridViewSuppliers";
               this->dataGridViewSuppliers->Size = System::Drawing::Size(540, 262);
               this->dataGridViewSuppliers->TabIndex = 0;

               // dataGridViewOrders
               this->dataGridViewOrders->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
               this->dataGridViewOrders->Location = System::Drawing::Point(6, 6);
               this->dataGridViewOrders->Name = L"dataGridViewOrders";
               this->dataGridViewOrders->Size = System::Drawing::Size(540, 262);
               this->dataGridViewOrders->TabIndex = 0;

               // dataGridViewInvoices
               this->dataGridViewInvoices->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
               this->dataGridViewInvoices->Location = System::Drawing::Point(6, 6);
               this->dataGridViewInvoices->Name = L"dataGridViewInvoices";
               this->dataGridViewInvoices->Size = System::Drawing::Size(540, 262);
               this->dataGridViewInvoices->TabIndex = 0;

               // dataGridViewDiscounts
               this->dataGridViewDiscounts->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
               this->dataGridViewDiscounts->Location = System::Drawing::Point(6, 6);
               this->dataGridViewDiscounts->Name = L"dataGridViewDiscounts";
               this->dataGridViewDiscounts->Size = System::Drawing::Size(540, 262);
               this->dataGridViewDiscounts->TabIndex = 0;

               // dataGridViewPayments
               this->dataGridViewPayments->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
               this->dataGridViewPayments->Location = System::Drawing::Point(6, 6);
               this->dataGridViewPayments->Name = L"dataGridViewPayments";
               this->dataGridViewPayments->Size = System::Drawing::Size(540, 262);
               this->dataGridViewPayments->TabIndex = 0;

               // dataGridViewSalesReports
               this->dataGridViewSalesReports->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
               this->dataGridViewSalesReports->Location = System::Drawing::Point(6, 6);
               this->dataGridViewSalesReports->Name = L"dataGridViewSalesReports";
               this->dataGridViewSalesReports->Size = System::Drawing::Size(540, 262);
               this->dataGridViewSalesReports->TabIndex = 0;

               // dataGridViewStocks
               this->dataGridViewStocks->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
               this->dataGridViewStocks->Location = System::Drawing::Point(6, 6);
               this->dataGridViewStocks->Name = L"dataGridViewStocks";
               this->dataGridViewStocks->Size = System::Drawing::Size(540, 262);
               this->dataGridViewStocks->TabIndex = 0;

               // dataGridViewWarehouses
               this->dataGridViewWarehouses->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
               this->dataGridViewWarehouses->Location = System::Drawing::Point(6, 6);
               this->dataGridViewWarehouses->Name = L"dataGridViewWarehouses";
               this->dataGridViewWarehouses->Size = System::Drawing::Size(540, 262);
               this->dataGridViewWarehouses->TabIndex = 0;

               // btnAddProduct
               this->btnAddProduct->Location = System::Drawing::Point(6, 212);
               this->btnAddProduct->Name = L"btnAddProduct";
               this->btnAddProduct->Size = System::Drawing::Size(100, 23);
               this->btnAddProduct->TabIndex = 1;
               this->btnAddProduct->Text = L"Додати";
               this->btnAddProduct->UseVisualStyleBackColor = true;
               this->btnAddProduct->Click += gcnew System::EventHandler(this, &InventoryApp::btnAddProduct_Click);

               // btnEditProduct
               this->btnEditProduct->Location = System::Drawing::Point(112, 212);
               this->btnEditProduct->Name = L"btnEditProduct";
               this->btnEditProduct->Size = System::Drawing::Size(100, 23);
               this->btnEditProduct->TabIndex = 2;
               this->btnEditProduct->Text = L"Редагувати";
               this->btnEditProduct->UseVisualStyleBackColor = true;
               this->btnEditProduct->Click += gcnew System::EventHandler(this, &InventoryApp::btnEditProduct_Click);

               // btnDeleteProduct
               this->btnDeleteProduct->Location = System::Drawing::Point(218, 212);
               this->btnDeleteProduct->Name = L"btnDeleteProduct";
               this->btnDeleteProduct->Size = System::Drawing::Size(100, 23);
               this->btnDeleteProduct->TabIndex = 3;
               this->btnDeleteProduct->Text = L"Видалити";
               this->btnDeleteProduct->UseVisualStyleBackColor = true;
               this->btnDeleteProduct->Click += gcnew System::EventHandler(this, &InventoryApp::btnDeleteProduct_Click);

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
               this->btnSearch->Text = L"Пошук";
               this->btnSearch->UseVisualStyleBackColor = true;
               this->btnSearch->Click += gcnew System::EventHandler(this, &InventoryApp::btnSearch_Click);

               // btnAddSample
               this->btnAddSample->Location = System::Drawing::Point(497, 10);
               this->btnAddSample->Name = L"btnAddSample";
               this->btnAddSample->Size = System::Drawing::Size(75, 23);
               this->btnAddSample->TabIndex = 3;
               this->btnAddSample->Text = L"Додати зразок";
               this->btnAddSample->UseVisualStyleBackColor = true;
               this->btnAddSample->Click += gcnew System::EventHandler(this, &InventoryApp::btnAddSample_Click);

               // InventoryApp
               this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
               this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
               this->ClientSize = System::Drawing::Size(584, 361);
               this->Controls->Add(this->btnAddSample);
               this->Controls->Add(this->btnSearch);
               this->Controls->Add(this->txtSearch);
               this->Controls->Add(this->tabControl);
               this->Name = L"InventoryApp";
               this->Text = L"Додаток для інвентаризації";
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewProducts))->EndInit();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewCategories))->EndInit();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewCustomers))->EndInit();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewSuppliers))->EndInit();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewOrders))->EndInit();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewInvoices))->EndInit();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewDiscounts))->EndInit();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewPayments))->EndInit();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewSalesReports))->EndInit();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewStocks))->EndInit();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewWarehouses))->EndInit();
               this->tabProducts->ResumeLayout(false);
               this->tabCategories->ResumeLayout(false);
               this->tabCustomers->ResumeLayout(false);
               this->tabSuppliers->ResumeLayout(false);
               this->tabOrders->ResumeLayout(false);
               this->tabInvoices->ResumeLayout(false);
               this->tabDiscounts->ResumeLayout(false);
               this->tabPayments->ResumeLayout(false);
               this->tabSalesReports->ResumeLayout(false);
               this->tabStocks->ResumeLayout(false);
               this->tabWarehouses->ResumeLayout(false);
               this->tabControl->ResumeLayout(false);
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
            UpdateProductGrid();
        }

        void UpdateProductGrid()
        {
            dataGridViewProducts->Rows->Clear();
            dataGridViewProducts->Columns->Clear();

            dataGridViewProducts->Columns->Add("ID", "ID");
            dataGridViewProducts->Columns->Add("Name", "Назва");
            dataGridViewProducts->Columns->Add("Quantity", "Кількість");
            dataGridViewProducts->Columns->Add("Price", "Ціна");

            for (const auto& product : inventory->getAllProducts())
            {
                dataGridViewProducts->Rows->Add(product.getId(), gcnew String(product.getName().c_str()), product.getQuantity(), product.getPrice());
            }
        }

    private: System::Void btnSearch_Click(System::Object^ sender, System::EventArgs^ e) {
        String^ keyword = txtSearch->Text->ToLower();
        dataGridViewProducts->Rows->Clear();

        for (const auto& product : inventory->getAllProducts())
        {
            String^ name = gcnew String(product.getName().c_str());
            if (name->ToLower()->Contains(keyword))
            {
                dataGridViewProducts->Rows->Add(product.getId(), name, product.getQuantity(), product.getPrice());
            }
        }
    }

    private: System::Void btnAddSample_Click(System::Object^ sender, System::EventArgs^ e) {
        LoadSampleData();
    }

    private: System::Void btnAddProduct_Click(System::Object^ sender, System::EventArgs^ e) {
        AddEditProductForm^ form = gcnew AddEditProductForm(inventory->getAllProducts().size() + 1);
        if (form->ShowDialog() == System::Windows::Forms::DialogResult::OK)
        {
            Product product(form->ProductId, msclr::interop::marshal_as<std::string>(form->ProductName), form->ProductQuantity, form->ProductPrice);
            inventory->addProduct(product);
            UpdateProductGrid();
        }
    }

    private: System::Void btnEditProduct_Click(System::Object^ sender, System::EventArgs^ e) {
        if (dataGridViewProducts->SelectedRows->Count > 0)
        {
            int id = Convert::ToInt32(dataGridViewProducts->SelectedRows[0]->Cells[0]->Value);
            Product* product = inventory->findProductById(id);
            if (product)
            {
                AddEditProductForm^ form = gcnew AddEditProductForm(id, gcnew String(product->getName().c_str()), product->getQuantity(), product->getPrice());
                if (form->ShowDialog() == System::Windows::Forms::DialogResult::OK)
                {
                    product->setName(msclr::interop::marshal_as<std::string>(form->ProductName));
                    product->setQuantity(form->ProductQuantity);
                    product->setPrice(form->ProductPrice);
                    UpdateProductGrid();
                }
            }
        }
        else
        {
            MessageBox::Show(L"Будь ласка, виберіть продукт для редагування.", L"Помилка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        }
    }

    private: System::Void btnDeleteProduct_Click(System::Object^ sender, System::EventArgs^ e) {
        if (dataGridViewProducts->SelectedRows->Count > 0)
        {
            int id = Convert::ToInt32(dataGridViewProducts->SelectedRows[0]->Cells[0]->Value);
            if (MessageBox::Show(L"Ви впевнені, що хочете видалити цей продукт?", L"Підтвердження", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
            {
                inventory->removeProductById(id);
                UpdateProductGrid();
            }
        }
        else
        {
            MessageBox::Show(L"Будь ласка, виберіть продукт для видалення.", L"Помилка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        }
    }
    };
}