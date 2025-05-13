#pragma once

#include "../РГР/Product.h"
#include "../РГР/Inventory.h"
#include "../РГР/Category.h"
#include "../РГР/Customer.h"
#include "../РГР/Supplier.h"
#include "AddEditProductForm.h"
#include "AddEditCategoryForm.h"
#include "AddEditCustomerForm.h"
#include "AddEditSupplierForm.h"
#include <msclr/marshal_cppstd.h>

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
            // Завантаження даних із файлу при запуску
            inventory->loadFromFile("inventory_data.txt");
            UpdateProductGrid();
            UpdateCategoryGrid();
            UpdateCustomerGrid();
            UpdateSupplierGrid();
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
    private: System::Windows::Forms::DataGridView^ dataGridViewProducts;
    private: System::Windows::Forms::DataGridView^ dataGridViewCategories;
    private: System::Windows::Forms::DataGridView^ dataGridViewCustomers;
    private: System::Windows::Forms::DataGridView^ dataGridViewSuppliers;
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
    private: System::Windows::Forms::Button^ btnSave;
    private: System::Windows::Forms::Button^ btnLoad;
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
               this->dataGridViewProducts = (gcnew System::Windows::Forms::DataGridView());
               this->dataGridViewCategories = (gcnew System::Windows::Forms::DataGridView());
               this->dataGridViewCustomers = (gcnew System::Windows::Forms::DataGridView());
               this->dataGridViewSuppliers = (gcnew System::Windows::Forms::DataGridView());
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
               this->btnSave = (gcnew System::Windows::Forms::Button());
               this->btnLoad = (gcnew System::Windows::Forms::Button());
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewProducts))->BeginInit();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewCategories))->BeginInit();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewCustomers))->BeginInit();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewSuppliers))->BeginInit();
               this->tabProducts->SuspendLayout();
               this->tabCategories->SuspendLayout();
               this->tabCustomers->SuspendLayout();
               this->tabSuppliers->SuspendLayout();
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
               this->btnAddSample->Location = System::Drawing::Point(249, 10);
               this->btnAddSample->Name = L"btnAddSample";
               this->btnAddSample->Size = System::Drawing::Size(75, 23);
               this->btnAddSample->TabIndex = 3;
               this->btnAddSample->Text = L"Додати зразок";
               this->btnAddSample->UseVisualStyleBackColor = true;
               this->btnAddSample->Click += gcnew System::EventHandler(this, &InventoryApp::btnAddSample_Click);

               // btnSave
               this->btnSave->Location = System::Drawing::Point(330, 10);
               this->btnSave->Name = L"btnSave";
               this->btnSave->Size = System::Drawing::Size(75, 23);
               this->btnSave->TabIndex = 4;
               this->btnSave->Text = L"Зберегти";
               this->btnSave->UseVisualStyleBackColor = true;
               this->btnSave->Click += gcnew System::EventHandler(this, &InventoryApp::btnSave_Click);

               // btnLoad
               this->btnLoad->Location = System::Drawing::Point(411, 10);
               this->btnLoad->Name = L"btnLoad";
               this->btnLoad->Size = System::Drawing::Size(75, 23);
               this->btnLoad->TabIndex = 5;
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
               this->tabProducts->ResumeLayout(false);
               this->tabCategories->ResumeLayout(false);
               this->tabCustomers->ResumeLayout(false);
               this->tabSuppliers->ResumeLayout(false);
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
            UpdateProductGrid();
            UpdateCategoryGrid();
            UpdateCustomerGrid();
            UpdateSupplierGrid();
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
        MessageBox::Show(L"Дані успішно завантажено.", L"Успіх", MessageBoxButtons::OK, MessageBoxIcon::Information);
    }
    };
}