#pragma once

#include "../RGR/Product.h"
#include "../RGR/Inventory.h"
#include "../RGR/Category.h"
#include "../RGR/Customer.h"
#include "../RGR/Supplier.h"
#include "../RGR/Order.h"
#include "../RGR/Warehouse.h"
#include "../RGR/Invoice.h"
#include "AddEditProductForm.h"
#include "AddEditCategoryForm.h"
#include "AddEditCustomerForm.h"
#include "AddEditSupplierForm.h"
#include "AddEditOrderForm.h"
#include "WarehouseForm.h"
#include <msclr/marshal_cppstd.h>

namespace InventoryApp {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::Collections::Generic;
    using namespace System::Drawing::Printing;
    using namespace std;

    public ref class InventoryApp : public System::Windows::Forms::Form
    {
    public:
        InventoryApp(void)
        {
            InitializeComponent();
            inventory = new Inventory();
            // Завантаження даних із файлу при запуску
            inventory->loadFromFile("inventory_data.txt");
            UpdateProductGrid();
            UpdateCategoryGrid();
            UpdateCustomerGrid();
            UpdateSupplierGrid();
            UpdateOrderGrid();
            UpdateInvoiceGrid();
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
    private: System::Windows::Forms::DataGridView^ dataGridViewProducts;
    private: System::Windows::Forms::DataGridView^ dataGridViewCategories;
    private: System::Windows::Forms::DataGridView^ dataGridViewCustomers;
    private: System::Windows::Forms::DataGridView^ dataGridViewSuppliers;
    private: System::Windows::Forms::DataGridView^ dataGridViewOrders;
    private: System::Windows::Forms::TextBox^ txtSearch;
    private: System::Windows::Forms::Button^ btnSearch;
    private: System::Windows::Forms::Button^ btnAddSample;
    private: System::Windows::Forms::Button^ btnAddProduct;
    private: System::Windows::Forms::Button^ btnEditProduct;
    private: System::Windows::Forms::Button^ btnDeleteProduct;
    private: System::Windows::Forms::Button^ btnAddCategory;
    private: System::Windows::Forms::Button^ btnEditCategory;
    private: System::Windows::Forms::Button^ btnDeleteCategory;
    private: System::Windows::Forms::Button^ btnAddCustomer;
    private: System::Windows::Forms::Button^ btnEditCustomer;
    private: System::Windows::Forms::Button^ btnDeleteCustomer;
    private: System::Windows::Forms::Button^ btnAddSupplier;
    private: System::Windows::Forms::Button^ btnEditSupplier;
    private: System::Windows::Forms::Button^ btnDeleteSupplier;
    private: System::Windows::Forms::Button^ btnAddOrder;
    private: System::Windows::Forms::Button^ btnEditOrder;
    private: System::Windows::Forms::Button^ btnDeleteOrder;
    private: System::Windows::Forms::Button^ btnSave;
    private: System::Windows::Forms::Button^ btnLoad;
    private: System::Windows::Forms::TabPage^ tabInvoices;
    private: System::Windows::Forms::DataGridView^ dataGridViewInvoices;
    private: System::Windows::Forms::Button^ btnViewInvoice;
    private: Inventory* inventory;
    private: System::ComponentModel::Container^ components;
    private: System::Windows::Forms::Button^ btnWarehouse;


#pragma region Windows Form Designer generated code
           void InitializeComponent(void)
           {
               this->tabControl = (gcnew System::Windows::Forms::TabControl());
               this->tabProducts = (gcnew System::Windows::Forms::TabPage());
               this->tabCategories = (gcnew System::Windows::Forms::TabPage());
               this->tabCustomers = (gcnew System::Windows::Forms::TabPage());
               this->tabSuppliers = (gcnew System::Windows::Forms::TabPage());
               this->tabOrders = (gcnew System::Windows::Forms::TabPage());
               this->dataGridViewProducts = (gcnew System::Windows::Forms::DataGridView());
               this->dataGridViewCategories = (gcnew System::Windows::Forms::DataGridView());
               this->dataGridViewCustomers = (gcnew System::Windows::Forms::DataGridView());
               this->dataGridViewSuppliers = (gcnew System::Windows::Forms::DataGridView());
               this->dataGridViewOrders = (gcnew System::Windows::Forms::DataGridView());
               this->txtSearch = (gcnew System::Windows::Forms::TextBox());
               this->btnSearch = (gcnew System::Windows::Forms::Button());
               this->btnAddSample = (gcnew System::Windows::Forms::Button());
               this->btnAddProduct = (gcnew System::Windows::Forms::Button());
               this->btnEditProduct = (gcnew System::Windows::Forms::Button());
               this->btnDeleteProduct = (gcnew System::Windows::Forms::Button());
               this->btnAddCategory = (gcnew System::Windows::Forms::Button());
               this->btnEditCategory = (gcnew System::Windows::Forms::Button());
               this->btnDeleteCategory = (gcnew System::Windows::Forms::Button());
               this->btnAddCustomer = (gcnew System::Windows::Forms::Button());
               this->btnEditCustomer = (gcnew System::Windows::Forms::Button());
               this->btnDeleteCustomer = (gcnew System::Windows::Forms::Button());
               this->btnAddSupplier = (gcnew System::Windows::Forms::Button());
               this->btnEditSupplier = (gcnew System::Windows::Forms::Button());
               this->btnDeleteSupplier = (gcnew System::Windows::Forms::Button());
               this->btnAddOrder = (gcnew System::Windows::Forms::Button());
               this->btnEditOrder = (gcnew System::Windows::Forms::Button());
               this->btnDeleteOrder = (gcnew System::Windows::Forms::Button());
               this->btnSave = (gcnew System::Windows::Forms::Button());
               this->btnLoad = (gcnew System::Windows::Forms::Button());
               this->btnWarehouse = gcnew System::Windows::Forms::Button();
               this->btnWarehouse->Location = System::Drawing::Point(20, 540); // Змінити координати при потребі
               this->btnWarehouse->Name = L"btnWarehouse";
               this->btnWarehouse->Size = System::Drawing::Size(150, 30);
               this->btnWarehouse->TabIndex = 10;
               this->btnWarehouse->Text = L"Склади";
               this->btnWarehouse->UseVisualStyleBackColor = true;
               this->btnWarehouse->Click += gcnew System::EventHandler(this, &InventoryApp::btnWarehouse_Click);
               this->Controls->Add(this->btnWarehouse);
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewProducts))->BeginInit();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewCategories))->BeginInit();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewCustomers))->BeginInit();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewSuppliers))->BeginInit();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewOrders))->BeginInit();
               this->tabProducts->SuspendLayout();
               this->tabCategories->SuspendLayout();
               this->tabCustomers->SuspendLayout();
               this->tabSuppliers->SuspendLayout();
               this->tabOrders->SuspendLayout();
               this->tabControl->SuspendLayout();
               this->SuspendLayout();

               this->tabInvoices = (gcnew System::Windows::Forms::TabPage());
               this->dataGridViewInvoices = (gcnew System::Windows::Forms::DataGridView());
               this->btnViewInvoice = (gcnew System::Windows::Forms::Button());
               this->tabControl->Controls->Add(this->tabInvoices);


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
               this->tabCategories->Controls->Add(this->btnDeleteCategory);
               this->tabCategories->Controls->Add(this->btnEditCategory);
               this->tabCategories->Controls->Add(this->btnAddCategory);
               this->tabCategories->Controls->Add(this->dataGridViewCategories);
               this->tabCategories->Location = System::Drawing::Point(4, 22);
               this->tabCategories->Name = L"tabCategories";
               this->tabCategories->Padding = System::Windows::Forms::Padding(3);
               this->tabCategories->Size = System::Drawing::Size(552, 274);
               this->tabCategories->TabIndex = 1;
               this->tabCategories->Text = L"Категорії";

               // tabCustomers
               this->tabCustomers->Controls->Add(this->btnDeleteCustomer);
               this->tabCustomers->Controls->Add(this->btnEditCustomer);
               this->tabCustomers->Controls->Add(this->btnAddCustomer);
               this->tabCustomers->Controls->Add(this->dataGridViewCustomers);
               this->tabCustomers->Location = System::Drawing::Point(4, 22);
               this->tabCustomers->Name = L"tabCustomers";
               this->tabCustomers->Padding = System::Windows::Forms::Padding(3);
               this->tabCustomers->Size = System::Drawing::Size(552, 274);
               this->tabCustomers->TabIndex = 2;
               this->tabCustomers->Text = L"Клієнти";

               // tabSuppliers
               this->tabSuppliers->Controls->Add(this->btnDeleteSupplier);
               this->tabSuppliers->Controls->Add(this->btnEditSupplier);
               this->tabSuppliers->Controls->Add(this->btnAddSupplier);
               this->tabSuppliers->Controls->Add(this->dataGridViewSuppliers);
               this->tabSuppliers->Location = System::Drawing::Point(4, 22);
               this->tabSuppliers->Name = L"tabSuppliers";
               this->tabSuppliers->Padding = System::Windows::Forms::Padding(3);
               this->tabSuppliers->Size = System::Drawing::Size(552, 274);
               this->tabSuppliers->TabIndex = 3;
               this->tabSuppliers->Text = L"Постачальники";

               // tabOrders
               this->tabOrders->Controls->Add(this->btnDeleteOrder);
               this->tabOrders->Controls->Add(this->btnEditOrder);
               this->tabOrders->Controls->Add(this->btnAddOrder);
               this->tabOrders->Controls->Add(this->dataGridViewOrders);
               this->tabOrders->Location = System::Drawing::Point(4, 22);
               this->tabOrders->Name = L"tabOrders";
               this->tabOrders->Padding = System::Windows::Forms::Padding(3);
               this->tabOrders->Size = System::Drawing::Size(552, 274);
               this->tabOrders->TabIndex = 4;
               this->tabOrders->Text = L"Замовлення";

               // tabInvoices
               this->tabInvoices->Controls->Add(this->btnViewInvoice);
               this->tabInvoices->Controls->Add(this->dataGridViewInvoices);
               this->tabInvoices->Location = System::Drawing::Point(4, 22);
               this->tabInvoices->Name = L"tabInvoices";
               this->tabInvoices->Padding = System::Windows::Forms::Padding(3);
               this->tabInvoices->Size = System::Drawing::Size(552, 274);
               this->tabInvoices->TabIndex = 5;
               this->tabInvoices->Text = L"Рахунки";
               this->tabInvoices->UseVisualStyleBackColor = true;

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
               this->dataGridViewCategories->Size = System::Drawing::Size(540, 200);
               this->dataGridViewCategories->TabIndex = 0;
               this->dataGridViewCategories->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
               this->dataGridViewCategories->MultiSelect = false;

               // dataGridViewCustomers
               this->dataGridViewCustomers->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
               this->dataGridViewCustomers->Location = System::Drawing::Point(6, 6);
               this->dataGridViewCustomers->Name = L"dataGridViewCustomers";
               this->dataGridViewCustomers->Size = System::Drawing::Size(540, 200);
               this->dataGridViewCustomers->TabIndex = 0;
               this->dataGridViewCustomers->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
               this->dataGridViewCustomers->MultiSelect = false;

               // dataGridViewSuppliers
               this->dataGridViewSuppliers->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
               this->dataGridViewSuppliers->Location = System::Drawing::Point(6, 6);
               this->dataGridViewSuppliers->Name = L"dataGridViewSuppliers";
               this->dataGridViewSuppliers->Size = System::Drawing::Size(540, 200);
               this->dataGridViewSuppliers->TabIndex = 0;
               this->dataGridViewSuppliers->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
               this->dataGridViewSuppliers->MultiSelect = false;

               // dataGridViewOrders
               this->dataGridViewOrders->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
               this->dataGridViewOrders->Location = System::Drawing::Point(6, 6);
               this->dataGridViewOrders->Name = L"dataGridViewOrders";
               this->dataGridViewOrders->Size = System::Drawing::Size(540, 200);
               this->dataGridViewOrders->TabIndex = 0;
               this->dataGridViewOrders->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
               this->dataGridViewOrders->MultiSelect = false;

               // dataGridViewInvoices
               this->dataGridViewInvoices->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
               this->dataGridViewInvoices->Location = System::Drawing::Point(6, 6);
               this->dataGridViewInvoices->Name = L"dataGridViewInvoices";
               this->dataGridViewInvoices->Size = System::Drawing::Size(540, 200);
               this->dataGridViewInvoices->TabIndex = 0;
               this->dataGridViewInvoices->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
               this->dataGridViewInvoices->MultiSelect = false;

               // btnViewInvoice
               this->btnViewInvoice->Location = System::Drawing::Point(6, 212);
               this->btnViewInvoice->Name = L"btnViewInvoice";
               this->btnViewInvoice->Size = System::Drawing::Size(100, 23);
               this->btnViewInvoice->TabIndex = 1;
               this->btnViewInvoice->Text = L"Переглянути";
               this->btnViewInvoice->UseVisualStyleBackColor = true;
               this->btnViewInvoice->Click += gcnew System::EventHandler(this, &InventoryApp::btnViewInvoice_Click);

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

               // btnAddCategory
               this->btnAddCategory->Location = System::Drawing::Point(6, 212);
               this->btnAddCategory->Name = L"btnAddCategory";
               this->btnAddCategory->Size = System::Drawing::Size(100, 23);
               this->btnAddCategory->TabIndex = 1;
               this->btnAddCategory->Text = L"Додати";
               this->btnAddCategory->UseVisualStyleBackColor = true;
               this->btnAddCategory->Click += gcnew System::EventHandler(this, &InventoryApp::btnAddCategory_Click);

               // btnEditCategory
               this->btnEditCategory->Location = System::Drawing::Point(112, 212);
               this->btnEditCategory->Name = L"btnEditCategory";
               this->btnEditCategory->Size = System::Drawing::Size(100, 23);
               this->btnEditCategory->TabIndex = 2;
               this->btnEditCategory->Text = L"Редагувати";
               this->btnEditCategory->UseVisualStyleBackColor = true;
               this->btnEditCategory->Click += gcnew System::EventHandler(this, &InventoryApp::btnEditCategory_Click);

               // btnDeleteCategory
               this->btnDeleteCategory->Location = System::Drawing::Point(218, 212);
               this->btnDeleteCategory->Name = L"btnDeleteCategory";
               this->btnDeleteCategory->Size = System::Drawing::Size(100, 23);
               this->btnDeleteCategory->TabIndex = 3;
               this->btnDeleteCategory->Text = L"Видалити";
               this->btnDeleteCategory->UseVisualStyleBackColor = true;
               this->btnDeleteCategory->Click += gcnew System::EventHandler(this, &InventoryApp::btnDeleteCategory_Click);

               // btnAddCustomer
               this->btnAddCustomer->Location = System::Drawing::Point(6, 212);
               this->btnAddCustomer->Name = L"btnAddCustomer";
               this->btnAddCustomer->Size = System::Drawing::Size(100, 23);
               this->btnAddCustomer->TabIndex = 1;
               this->btnAddCustomer->Text = L"Додати";
               this->btnAddCustomer->UseVisualStyleBackColor = true;
               this->btnAddCustomer->Click += gcnew System::EventHandler(this, &InventoryApp::btnAddCustomer_Click);

               // btnEditCustomer
               this->btnEditCustomer->Location = System::Drawing::Point(112, 212);
               this->btnEditCustomer->Name = L"btnEditCustomer";
               this->btnEditCustomer->Size = System::Drawing::Size(100, 23);
               this->btnEditCustomer->TabIndex = 2;
               this->btnEditCustomer->Text = L"Редагувати";
               this->btnEditCustomer->UseVisualStyleBackColor = true;
               this->btnEditCustomer->Click += gcnew System::EventHandler(this, &InventoryApp::btnEditCustomer_Click);

               // btnDeleteCustomer
               this->btnDeleteCustomer->Location = System::Drawing::Point(218, 212);
               this->btnDeleteCustomer->Name = L"btnDeleteCustomer";
               this->btnDeleteCustomer->Size = System::Drawing::Size(100, 23);
               this->btnDeleteCustomer->TabIndex = 3;
               this->btnDeleteCustomer->Text = L"Видалити";
               this->btnDeleteCustomer->UseVisualStyleBackColor = true;
               this->btnDeleteCustomer->Click += gcnew System::EventHandler(this, &InventoryApp::btnDeleteCustomer_Click);

               // btnAddSupplier
               this->btnAddSupplier->Location = System::Drawing::Point(6, 212);
               this->btnAddSupplier->Name = L"btnAddSupplier";
               this->btnAddSupplier->Size = System::Drawing::Size(100, 23);
               this->btnAddSupplier->TabIndex = 1;
               this->btnAddSupplier->Text = L"Додати";
               this->btnAddSupplier->UseVisualStyleBackColor = true;
               this->btnAddSupplier->Click += gcnew System::EventHandler(this, &InventoryApp::btnAddSupplier_Click);

               // btnEditSupplier
               this->btnEditSupplier->Location = System::Drawing::Point(112, 212);
               this->btnEditSupplier->Name = L"btnEditSupplier";
               this->btnEditSupplier->Size = System::Drawing::Size(100, 23);
               this->btnEditSupplier->TabIndex = 2;
               this->btnEditSupplier->Text = L"Редагувати";
               this->btnEditSupplier->UseVisualStyleBackColor = true;
               this->btnEditSupplier->Click += gcnew System::EventHandler(this, &InventoryApp::btnEditSupplier_Click);

               // btnDeleteSupplier
               this->btnDeleteSupplier->Location = System::Drawing::Point(218, 212);
               this->btnDeleteSupplier->Name = L"btnDeleteSupplier";
               this->btnDeleteSupplier->Size = System::Drawing::Size(100, 23);
               this->btnDeleteSupplier->TabIndex = 3;
               this->btnDeleteSupplier->Text = L"Видалити";
               this->btnDeleteSupplier->UseVisualStyleBackColor = true;
               this->btnDeleteSupplier->Click += gcnew System::EventHandler(this, &InventoryApp::btnDeleteSupplier_Click);

               // btnAddOrder
               this->btnAddOrder->Location = System::Drawing::Point(6, 212);
               this->btnAddOrder->Name = L"btnAddOrder";
               this->btnAddOrder->Size = System::Drawing::Size(100, 23);
               this->btnAddOrder->TabIndex = 1;
               this->btnAddOrder->Text = L"Додати";
               this->btnAddOrder->UseVisualStyleBackColor = true;
               this->btnAddOrder->Click += gcnew System::EventHandler(this, &InventoryApp::btnAddOrder_Click);

               // btnEditOrder
               this->btnEditOrder->Location = System::Drawing::Point(112, 212);
               this->btnEditOrder->Name = L"btnEditOrder";
               this->btnEditOrder->Size = System::Drawing::Size(100, 23);
               this->btnEditOrder->TabIndex = 2;
               this->btnEditOrder->Text = L"Редагувати";
               this->btnEditOrder->UseVisualStyleBackColor = true;
               this->btnEditOrder->Click += gcnew System::EventHandler(this, &InventoryApp::btnEditOrder_Click);

               // btnDeleteOrder
               this->btnDeleteOrder->Location = System::Drawing::Point(218, 212);
               this->btnDeleteOrder->Name = L"btnDeleteOrder";
               this->btnDeleteOrder->Size = System::Drawing::Size(100, 23);
               this->btnDeleteOrder->TabIndex = 3;
               this->btnDeleteOrder->Text = L"Видалити";
               this->btnDeleteOrder->UseVisualStyleBackColor = true;
               this->btnDeleteOrder->Click += gcnew System::EventHandler(this, &InventoryApp::btnDeleteOrder_Click);

               // txtSearch
               this->txtSearch->Location = System::Drawing::Point(12, 12);
               this->txtSearch->Name = L"txtSearch";
               this->txtSearch->Size = System::Drawing::Size(150, 20);
               this->txtSearch->TabIndex = 4;

               // btnSearch
               this->btnSearch->Location = System::Drawing::Point(168, 10);
               this->btnSearch->Name = L"btnSearch";
               this->btnSearch->Size = System::Drawing::Size(75, 23);
               this->btnSearch->TabIndex = 5;
               this->btnSearch->Text = L"Пошук";
               this->btnSearch->UseVisualStyleBackColor = true;
               this->btnSearch->Click += gcnew System::EventHandler(this, &InventoryApp::btnSearch_Click);

               // btnAddSample
               this->btnAddSample->Location = System::Drawing::Point(249, 10);
               this->btnAddSample->Name = L"btnAddSample";
               this->btnAddSample->Size = System::Drawing::Size(75, 23);
               this->btnAddSample->TabIndex = 6;
               this->btnAddSample->Text = L"Додати зразок";
               this->btnAddSample->UseVisualStyleBackColor = true;
               this->btnAddSample->Click += gcnew System::EventHandler(this, &InventoryApp::btnAddSample_Click);

               // btnSave
               this->btnSave->Location = System::Drawing::Point(330, 10);
               this->btnSave->Name = L"btnSave";
               this->btnSave->Size = System::Drawing::Size(75, 23);
               this->btnSave->TabIndex = 7;
               this->btnSave->Text = L"Зберегти";
               this->btnSave->UseVisualStyleBackColor = true;
               this->btnSave->Click += gcnew System::EventHandler(this, &InventoryApp::btnSave_Click);

               // btnLoad
               this->btnLoad->Location = System::Drawing::Point(411, 10);
               this->btnLoad->Name = L"btnLoad";
               this->btnLoad->Size = System::Drawing::Size(75, 23);
               this->btnLoad->TabIndex = 8;
               this->btnLoad->Text = L"Завантажити";
               this->btnLoad->UseVisualStyleBackColor = true;
               this->btnLoad->Click += gcnew System::EventHandler(this, &InventoryApp::btnLoad_Click);

               // InventoryApp
               this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
               this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
               this->ClientSize = System::Drawing::Size(584, 361);
               this->Controls->Add(this->btnLoad);
               this->Controls->Add(this->btnSave);
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
               this->tabProducts->ResumeLayout(false);
               this->tabCategories->ResumeLayout(false);
               this->tabCustomers->ResumeLayout(false);
               this->tabSuppliers->ResumeLayout(false);
               this->tabOrders->ResumeLayout(false);
               this->tabControl->ResumeLayout(false);
               this->ResumeLayout(false);
               this->PerformLayout();

           }
#pragma endregion

    private:
        void LoadSampleData()
        {
            inventory->addCategory(Category(1, std::string("Електроніка")));
            inventory->addCategory(Category(2, std::string("Периферія")));
            inventory->addProduct(Product(1, std::string("Laptop"), 10, 999.99, 1));
            inventory->addProduct(Product(2, std::string("Mouse"), 50, 19.99, 2));
            inventory->addProduct(Product(3, std::string("Keyboard"), 20, 49.99, 2));
            inventory->addCustomer(Customer(1, std::string("ТОВ Клієнт"), std::string("+380671234567"), std::string("вул. Шевченка, Київ")));
            inventory->addSupplier(Supplier(1, std::string("ТОВ Постачальник"), std::string("supplier@example.com"), std::string("вул. Лесі Українки, Львів")));
            vector<pair<int, int>> orderProducts = { {1, 2}, {2, 5} }; // 2 laptops, 5 mice
            inventory->addOrder(Order(1, 1, "2025-05-13", "Нове", orderProducts, 2099.93));
            UpdateProductGrid();
            UpdateCategoryGrid();
            UpdateCustomerGrid();
            UpdateSupplierGrid();
            UpdateOrderGrid();
        }

        void UpdateProductGrid()
        {
            dataGridViewProducts->Rows->Clear();
            dataGridViewProducts->Columns->Clear();

            dataGridViewProducts->Columns->Add("ID", "ID");
            dataGridViewProducts->Columns->Add("Name", "Назва");
            dataGridViewProducts->Columns->Add("Quantity", "Кількість");
            dataGridViewProducts->Columns->Add("Price", "Ціна");
            dataGridViewProducts->Columns->Add("CategoryId", "ID Категорії");

            for (const Product& product : inventory->getAllProducts())
            {
                dataGridViewProducts->Rows->Add(product.getId(), gcnew String(product.getName().c_str()), product.getQuantity(), product.getPrice(), product.getCategoryId());
            }
        }

        void UpdateCategoryGrid()
        {
            dataGridViewCategories->Rows->Clear();
            dataGridViewCategories->Columns->Clear();

            dataGridViewCategories->Columns->Add("ID", "ID");
            dataGridViewCategories->Columns->Add("Name", "Назва");

            for (const Category& category : inventory->getAllCategories())
            {
                dataGridViewCategories->Rows->Add(category.getId(), gcnew String(category.getName().c_str()));
            }
        }

        void UpdateCustomerGrid()
        {
            dataGridViewCustomers->Rows->Clear();
            dataGridViewCustomers->Columns->Clear();

            dataGridViewCustomers->Columns->Add("ID", "ID");
            dataGridViewCustomers->Columns->Add("Name", "Назва");
            dataGridViewCustomers->Columns->Add("ContactInfo", "Контактна інформація");
            dataGridViewCustomers->Columns->Add("Address", "Адреса");

            for (const Customer& customer : inventory->getAllCustomers())
            {
                dataGridViewCustomers->Rows->Add(customer.getId(), gcnew String(customer.getName().c_str()),
                    gcnew String(customer.getContactInfo().c_str()), gcnew String(customer.getAddress().c_str()));
            }
        }

        void UpdateSupplierGrid()
        {
            dataGridViewSuppliers->Rows->Clear();
            dataGridViewSuppliers->Columns->Clear();

            dataGridViewSuppliers->Columns->Add("ID", "ID");
            dataGridViewSuppliers->Columns->Add("Name", "Назва");
            dataGridViewSuppliers->Columns->Add("ContactInfo", "Контактна інформація");
            dataGridViewSuppliers->Columns->Add("Address", "Адреса");

            for (const Supplier& supplier : inventory->getAllSuppliers())
            {
                dataGridViewSuppliers->Rows->Add(supplier.getId(), gcnew String(supplier.getName().c_str()),
                    gcnew String(supplier.getContactInfo().c_str()), gcnew String(supplier.getAddress().c_str()));
            }
        }

        void UpdateOrderGrid()
        {
            dataGridViewOrders->Rows->Clear();
            dataGridViewOrders->Columns->Clear();

            dataGridViewOrders->Columns->Add("ID", "ID");
            dataGridViewOrders->Columns->Add("CustomerName", "Клієнт");
            dataGridViewOrders->Columns->Add("OrderDate", "Дата");
            dataGridViewOrders->Columns->Add("Status", "Статус");
            dataGridViewOrders->Columns->Add("TotalAmount", "Сума");

            for (const Order& order : inventory->getAllOrders())
            {
                Customer* customer = inventory->findCustomerById(order.getCustomerId());
                String^ customerName = customer ? gcnew String(customer->getName().c_str()) : L"Невідомий";
                dataGridViewOrders->Rows->Add(order.getId(), customerName,
                    gcnew String(order.getOrderDate().c_str()), gcnew String(order.getStatus().c_str()), order.getTotalAmount());
            }
        }

        void UpdateInvoiceGrid()
        {
            dataGridViewInvoices->Rows->Clear();
            dataGridViewInvoices->Columns->Clear();

            dataGridViewInvoices->Columns->Add("InvoiceNumber", "Номер рахунку");
            dataGridViewInvoices->Columns->Add("CustomerName", "Клієнт");
            dataGridViewInvoices->Columns->Add("OrderDate", "Дата замовлення");
            dataGridViewInvoices->Columns->Add("TotalAmount", "Сума");

            for (const Order& order : inventory->getAllOrders())
            {
                Customer* customer = inventory->findCustomerById(order.getCustomerId());
                String^ customerName = customer ? gcnew String(customer->getName().c_str()) : L"Невідомий";

                // Створюємо тимчасовий інвойс для відображення
                Invoice invoice(order.getId(), *customer, order, order.getOrderDate());

                dataGridViewInvoices->Rows->Add(
                    invoice.getInvoiceNumber(),
                    customerName,
                    gcnew String(order.getOrderDate().c_str()),
                    invoice.calculateTotal()
                );
            }
        }

    private: System::Void btnSearch_Click(System::Object^ sender, System::EventArgs^ e) {
        String^ keyword = txtSearch->Text->ToLower();
        dataGridViewProducts->Rows->Clear();

        for (const Product& product : inventory->getAllProducts())
        {
            String^ name = gcnew String(product.getName().c_str());
            if (name->ToLower()->Contains(keyword))
            {
                dataGridViewProducts->Rows->Add(product.getId(), name, product.getQuantity(), product.getPrice(), product.getCategoryId());
            }
        }
    }

    private: System::Void btnAddSample_Click(System::Object^ sender, System::EventArgs^ e) {
        LoadSampleData();
    }

    private: System::Void btnAddProduct_Click(System::Object^ sender, System::EventArgs^ e) {
        AddEditProductForm^ form = gcnew AddEditProductForm(inventory->getAllProducts().size() + 1, inventory);
        if (form->ShowDialog() == System::Windows::Forms::DialogResult::OK)
        {
            Product product(form->ProductId, msclr::interop::marshal_as<std::string>(form->ProductName),
                form->ProductQuantity, form->ProductPrice, form->ProductCategoryId);
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
                AddEditProductForm^ form = gcnew AddEditProductForm(id, gcnew String(product->getName().c_str()),
                    product->getQuantity(), product->getPrice(), product->getCategoryId(), inventory);
                if (form->ShowDialog() == System::Windows::Forms::DialogResult::OK)
                {
                    product->setName(msclr::interop::marshal_as<std::string>(form->ProductName));
                    product->setQuantity(form->ProductQuantity);
                    product->setPrice(form->ProductPrice);
                    product->setCategoryId(form->ProductCategoryId);
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
            bool isUsedInOrders = false;
            for (const Order& order : inventory->getAllOrders()) {
                for (const auto& productQty : order.getProductQuantities()) {
                    if (productQty.first == id) {
                        isUsedInOrders = true;
                        break;
                    }
                }
                if (isUsedInOrders) break;
            }
            if (isUsedInOrders) {
                MessageBox::Show(L"Неможливо видалити продукт, оскільки він використовується в замовленнях.",
                    L"Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }
            if (MessageBox::Show(L"Ви впевнені, що хочете видалити цей продукт?", L"Підтвердження",
                MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
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

    private: System::Void btnAddCategory_Click(System::Object^ sender, System::EventArgs^ e) {
        AddEditCategoryForm^ form = gcnew AddEditCategoryForm(inventory->getAllCategories().size() + 1);
        if (form->ShowDialog() == System::Windows::Forms::DialogResult::OK)
        {
            Category category(form->CategoryId, msclr::interop::marshal_as<std::string>(form->CategoryName));
            inventory->addCategory(category);
            UpdateCategoryGrid();
        }
    }

    private: System::Void btnEditCategory_Click(System::Object^ sender, System::EventArgs^ e) {
        if (dataGridViewCategories->SelectedRows->Count > 0)
        {
            int id = Convert::ToInt32(dataGridViewCategories->SelectedRows[0]->Cells[0]->Value);
            Category* category = inventory->findCategoryById(id);
            if (category)
            {
                AddEditCategoryForm^ form = gcnew AddEditCategoryForm(id, gcnew String(category->getName().c_str()));
                if (form->ShowDialog() == System::Windows::Forms::DialogResult::OK)
                {
                    category->setName(msclr::interop::marshal_as<std::string>(form->CategoryName));
                    UpdateCategoryGrid();
                }
            }
        }
        else
        {
            MessageBox::Show(L"Будь ласка, виберіть категорію для редагування.", L"Помилка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        }
    }

    private: System::Void btnDeleteCategory_Click(System::Object^ sender, System::EventArgs^ e) {
        if (dataGridViewCategories->SelectedRows->Count > 0)
        {
            int id = Convert::ToInt32(dataGridViewCategories->SelectedRows[0]->Cells[0]->Value);
            bool hasProducts = false;
            for (const Product& product : inventory->getAllProducts())
            {
                if (product.getCategoryId() == id)
                {
                    hasProducts = true;
                    break;
                }
            }
            if (hasProducts)
            {
                MessageBox::Show(L"Неможливо видалити категорію, оскільки до неї прив’язані продукти.",
                    L"Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }
            if (MessageBox::Show(L"Ви впевнені, що хочете видалити цю категорію?", L"Підтвердження",
                MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
            {
                inventory->removeCategoryById(id);
                UpdateCategoryGrid();
            }
        }
        else
        {
            MessageBox::Show(L"Будь ласка, виберіть категорію для видалення.", L"Помилка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        }
    }

    private: System::Void btnAddCustomer_Click(System::Object^ sender, System::EventArgs^ e) {
        AddEditCustomerForm^ form = gcnew AddEditCustomerForm(inventory->getAllCustomers().size() + 1);
        if (form->ShowDialog() == System::Windows::Forms::DialogResult::OK)
        {
            Customer customer(form->CustomerId, msclr::interop::marshal_as<std::string>(form->CustomerName),
                msclr::interop::marshal_as<std::string>(form->CustomerContactInfo),
                msclr::interop::marshal_as<std::string>(form->CustomerAddress));
            inventory->addCustomer(customer);
            UpdateCustomerGrid();
        }
    }

    private: System::Void btnEditCustomer_Click(System::Object^ sender, System::EventArgs^ e) {
        if (dataGridViewCustomers->SelectedRows->Count > 0)
        {
            int id = Convert::ToInt32(dataGridViewCustomers->SelectedRows[0]->Cells[0]->Value);
            Customer* customer = inventory->findCustomerById(id);
            if (customer)
            {
                AddEditCustomerForm^ form = gcnew AddEditCustomerForm(id, gcnew String(customer->getName().c_str()),
                    gcnew String(customer->getContactInfo().c_str()), gcnew String(customer->getAddress().c_str()));
                if (form->ShowDialog() == System::Windows::Forms::DialogResult::OK)
                {
                    customer->setName(msclr::interop::marshal_as<std::string>(form->CustomerName));
                    customer->setContactInfo(msclr::interop::marshal_as<std::string>(form->CustomerContactInfo));
                    customer->setAddress(msclr::interop::marshal_as<std::string>(form->CustomerAddress));
                    UpdateCustomerGrid();
                    UpdateOrderGrid(); // Оновлюємо замовлення, бо ім’я клієнта могло змінитися
                }
            }
        }
        else
        {
            MessageBox::Show(L"Будь ласка, виберіть клієнта для редагування.", L"Помилка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        }
    }

    private: System::Void btnDeleteCustomer_Click(System::Object^ sender, System::EventArgs^ e) {
        if (dataGridViewCustomers->SelectedRows->Count > 0)
        {
            int id = Convert::ToInt32(dataGridViewCustomers->SelectedRows[0]->Cells[0]->Value);
            bool hasOrders = false;
            for (const Order& order : inventory->getAllOrders()) {
                if (order.getCustomerId() == id) {
                    hasOrders = true;
                    break;
                }
            }
            if (hasOrders) {
                MessageBox::Show(L"Неможливо видалити клієнта, оскільки до нього прив’язані замовлення.",
                    L"Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }
            if (MessageBox::Show(L"Ви впевнені, що хочете видалити цього клієнта?", L"Підтвердження",
                MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
            {
                inventory->removeCustomerById(id);
                UpdateCustomerGrid();
            }
        }
        else
        {
            MessageBox::Show(L"Будь ласка, виберіть клієнта для видалення.", L"Помилка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        }
    }

    private: System::Void btnAddSupplier_Click(System::Object^ sender, System::EventArgs^ e) {
        AddEditSupplierForm^ form = gcnew AddEditSupplierForm(inventory->getAllSuppliers().size() + 1);
        if (form->ShowDialog() == System::Windows::Forms::DialogResult::OK)
        {
            Supplier supplier(form->SupplierId, msclr::interop::marshal_as<std::string>(form->SupplierName),
                msclr::interop::marshal_as<std::string>(form->SupplierContactInfo),
                msclr::interop::marshal_as<std::string>(form->SupplierAddress));
            inventory->addSupplier(supplier);
            UpdateSupplierGrid();
        }
    }

    private: System::Void btnEditSupplier_Click(System::Object^ sender, System::EventArgs^ e) {
        if (dataGridViewSuppliers->SelectedRows->Count > 0)
        {
            int id = Convert::ToInt32(dataGridViewSuppliers->SelectedRows[0]->Cells[0]->Value);
            Supplier* supplier = inventory->findSupplierById(id);
            if (supplier)
            {
                AddEditSupplierForm^ form = gcnew AddEditSupplierForm(id, gcnew String(supplier->getName().c_str()),
                    gcnew String(supplier->getContactInfo().c_str()), gcnew String(supplier->getAddress().c_str()));
                if (form->ShowDialog() == System::Windows::Forms::DialogResult::OK)
                {
                    supplier->setName(msclr::interop::marshal_as<std::string>(form->SupplierName));
                    supplier->setContactInfo(msclr::interop::marshal_as<std::string>(form->SupplierContactInfo));
                    supplier->setAddress(msclr::interop::marshal_as<std::string>(form->SupplierAddress));
                    UpdateSupplierGrid();
                }
            }
        }
        else
        {
            MessageBox::Show(L"Будь ласка, виберіть постачальника для редагування.", L"Помилка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        }
    }

    private: System::Void btnDeleteSupplier_Click(System::Object^ sender, System::EventArgs^ e) {
        if (dataGridViewSuppliers->SelectedRows->Count > 0)
        {
            int id = Convert::ToInt32(dataGridViewSuppliers->SelectedRows[0]->Cells[0]->Value);
            if (MessageBox::Show(L"Ви впевнені, що хочете видалити цього постачальника?", L"Підтвердження",
                MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
            {
                inventory->removeSupplierById(id);
                UpdateSupplierGrid();
            }
        }
        else
        {
            MessageBox::Show(L"Будь ласка, виберіть постачальника для видалення.", L"Помилка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        }
    }

    private: System::Void btnAddOrder_Click(System::Object^ sender, System::EventArgs^ e) {
        AddEditOrderForm^ form = gcnew AddEditOrderForm(inventory->getAllOrders().size() + 1, inventory);
        if (form->ShowDialog() == System::Windows::Forms::DialogResult::OK)
        {
            vector<pair<int, int>> productQuantities;
            for each (Dictionary<String^, Object^> ^ item in form->ProductQuantities)
            {
                int productId = Convert::ToInt32(item["ProductId"]);
                int quantity = Convert::ToInt32(item["Quantity"]);
                productQuantities.push_back({ productId, quantity });
            }
            Order order(form->OrderId, form->CustomerId, msclr::interop::marshal_as<std::string>(form->OrderDate),
                msclr::interop::marshal_as<std::string>(form->OrderStatus), productQuantities, form->TotalAmount);
            inventory->addOrder(order);
            UpdateOrderGrid();
        }
    }

    private: System::Void btnEditOrder_Click(System::Object^ sender, System::EventArgs^ e) {
        if (dataGridViewOrders->SelectedRows->Count > 0)
        {
            int id = Convert::ToInt32(dataGridViewOrders->SelectedRows[0]->Cells[0]->Value);
            Order* order = inventory->findOrderById(id);
            if (order)
            {
                List<Dictionary<String^, Object^>^>^ productQuantities = gcnew List<Dictionary<String^, Object^>^>();
                for (const auto& pq : order->getProductQuantities())
                {
                    Dictionary<String^, Object^>^ item = gcnew Dictionary<String^, Object^>();
                    item->Add("ProductId", pq.first);
                    item->Add("Quantity", pq.second);
                    productQuantities->Add(item);
                }
                AddEditOrderForm^ form = gcnew AddEditOrderForm(id, order->getCustomerId(),
                    gcnew String(order->getOrderDate().c_str()), gcnew String(order->getStatus().c_str()),
                    productQuantities, order->getTotalAmount(), inventory);
                if (form->ShowDialog() == System::Windows::Forms::DialogResult::OK)
                {
                    vector<pair<int, int>> newProductQuantities;
                    for each (Dictionary<String^, Object^> ^ item in form->ProductQuantities)
                    {
                        int productId = Convert::ToInt32(item["ProductId"]);
                        int quantity = Convert::ToInt32(item["Quantity"]);
                        newProductQuantities.push_back({ productId, quantity });
                    }
                    order->setCustomerId(form->CustomerId);
                    order->setOrderDate(msclr::interop::marshal_as<std::string>(form->OrderDate));
                    order->setStatus(msclr::interop::marshal_as<std::string>(form->OrderStatus));
                    order->setProductQuantities(newProductQuantities);
                    order->setTotalAmount(form->TotalAmount);
                    UpdateOrderGrid();
                }
            }
        }
        else
        {
            MessageBox::Show(L"Будь ласка, виберіть замовлення для редагування.", L"Помилка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        }
    }

    private: System::Void btnDeleteOrder_Click(System::Object^ sender, System::EventArgs^ e) {
        if (dataGridViewOrders->SelectedRows->Count > 0)
        {
            int id = Convert::ToInt32(dataGridViewOrders->SelectedRows[0]->Cells[0]->Value);
            if (MessageBox::Show(L"Ви впевнені, що хочете видалити це замовлення?", L"Підтвердження",
                MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
            {
                inventory->removeOrderById(id);
                UpdateOrderGrid();
            }
        }
        else
        {
            MessageBox::Show(L"Будь ласка, виберіть замовлення для видалення.", L"Помилка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        }
    }
           private:
               RichTextBox^ invoiceRichTextBox; // Поле для зберігання RichTextBox

               // Метод для обробки події Click кнопки Print
               void OnPrintButtonClick(Object^ sender, EventArgs^ e) {
                   PrintDocument^ pd = gcnew PrintDocument();
                   pd->PrintPage += gcnew PrintPageEventHandler(this, &InventoryApp::OnPrintPage);
                   PrintDialog^ printDialog = gcnew PrintDialog();
                   printDialog->Document = pd;
                   if (printDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
                   {
                       pd->Print();
                   }
               }

               // Метод для обробки події PrintPage
               void OnPrintPage(Object^ sender, PrintPageEventArgs^ e) {
                   e->Graphics->DrawString(invoiceRichTextBox->Text, invoiceRichTextBox->Font, Brushes::Black, 50, 50);
               }

           private:
               RichTextBox^ invoiceRichTextBox; // Поле для зберігання RichTextBox

               // Метод для обробки події Click кнопки Print
               void OnPrintButtonClick(Object^ sender, EventArgs^ e) {
                   PrintDocument^ pd = gcnew PrintDocument();
                   pd->PrintPage += gcnew PrintPageEventHandler(this, &InventoryApp::OnPrintPage);
                   PrintDialog^ printDialog = gcnew PrintDialog();
                   printDialog->Document = pd;
                   if (printDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
                   {
                       pd->Print();
                   }
               }

               // Метод для обробки події PrintPage
               void OnPrintPage(Object^ sender, PrintPageEventArgs^ e) {
                   e->Graphics->DrawString(invoiceRichTextBox->Text, invoiceRichTextBox->Font, Brushes::Black, 50, 50);
               }

    private: System::Void btnViewInvoice_Click(System::Object^ sender, System::EventArgs^ e) {
        if (dataGridViewInvoices->SelectedRows->Count > 0)
        {
            int invoiceNumber = Convert::ToInt32(dataGridViewInvoices->SelectedRows[0]->Cells[0]->Value);
            Order* order = inventory->findOrderById(invoiceNumber);
            if (order)
            {
                Customer* customer = inventory->findCustomerById(order->getCustomerId());
                if (customer)
                {
                    Invoice invoice(invoiceNumber, *customer, *order, order->getOrderDate());

                    // Створюємо форму для відображення інвойсу
                    Form^ invoiceForm = gcnew Form();
                    invoiceForm->Text = L"Рахунок-фактура #" + invoiceNumber;
                    invoiceForm->Size = System::Drawing::Size(500, 600);
                    invoiceForm->StartPosition = FormStartPosition::CenterParent;
                    invoiceForm->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
                    invoiceForm->MaximizeBox = false;

                    invoiceRichTextBox = gcnew RichTextBox(); // Зберігаємо в поле класу
                    invoiceRichTextBox->Dock = DockStyle::Fill;
                    invoiceRichTextBox->ReadOnly = true;
                    invoiceRichTextBox->Font = gcnew System::Drawing::Font("Arial", 10);

                    // Формуємо текст рахунку
                    String^ invoiceText = String::Format(
                        L"Рахунок-фактура #{0}\n\n"
                        L"Дата: {1}\n\n"
                        L"Клієнт: {2}\n"
                        L"Контакт: {3}\n"
                        L"Адреса: {4}\n\n"
                        L"Замовлення #{0}\n"
                        L"Дата замовлення: {1}\n"
                        L"Статус: {5}\n\n"
                        L"Товари:\n",
                        invoiceNumber,
                        gcnew String(order->getOrderDate().c_str()),
                        gcnew String(customer->getName().c_str()),
                        gcnew String(customer->getContactInfo().c_str()),
                        gcnew String(customer->getAddress().c_str()),
                        gcnew String(order->getStatus().c_str())
                    );

                    // Додаємо товари
                    double total = 0;
                    for (const auto& item : order->getProductQuantities())
                    {
                        Product* product = inventory->findProductById(item.first);
                        if (product)
                        {
                            double itemTotal = product->getPrice() * item.second;
                            total += itemTotal;
                            invoiceText += String::Format(
                                L"- {0} x {1} @ {2:C} = {3:C}\n",
                                item.second,
                                gcnew String(product->getName().c_str()),
                                product->getPrice(),
                                itemTotal
                            );
                        }
                    }

                    invoiceText += String::Format(L"\nЗагальна сума: {0:C}", total);

                    invoiceRichTextBox->Text = invoiceText;
                    invoiceForm->Controls->Add(invoiceRichTextBox);

                    Button^ btnPrint = gcnew Button();
                    btnPrint->Text = L"Друкувати";
                    btnPrint->Dock = DockStyle::Bottom;
                    btnPrint->Click += gcnew EventHandler(this, &InventoryApp::OnPrintButtonClick); // Використовуємо метод класу

                    invoiceForm->Controls->Add(btnPrint);
                    invoiceForm->ShowDialog();
                }
            }
        }
        else
        {
            MessageBox::Show(L"Будь ласка, виберіть рахунок для перегляду.", L"Помилка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        }
    }

    private: System::Void btnSave_Click(System::Object^ sender, System::EventArgs^ e) {
        inventory->saveToFile("inventory_data.txt");
        MessageBox::Show(L"Дані успішно збережено.", L"Успіх", MessageBoxButtons::OK, MessageBoxIcon::Information);
    }

    private: System::Void btnLoad_Click(System::Object^ sender, System::EventArgs^ e) {
        inventory->loadFromFile("inventory_data.txt");
        UpdateProductGrid();
        UpdateCategoryGrid();
        UpdateCustomerGrid();
        UpdateSupplierGrid();
        UpdateOrderGrid();
        MessageBox::Show(L"Дані успішно завантажено.", L"Успіх", MessageBoxButtons::OK, MessageBoxIcon::Information);
    }
           private: System::Void btnWarehouse_Click(System::Object^ sender, System::EventArgs^ e) {
               WarehouseForm^ form = gcnew WarehouseForm(inventory);
               form->ShowDialog();
           }

    };
}