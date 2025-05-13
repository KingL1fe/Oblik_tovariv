#pragma once

#include "../РГР/Product.h"
#include "../РГР/Inventory.h"
#include "../РГР/Category.h"
#include "AddEditProductForm.h"
#include "AddEditCategoryForm.h"
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
    private: System::Windows::Forms::DataGridView^ dataGridViewProducts;
    private: System::Windows::Forms::DataGridView^ dataGridViewCategories;
    private: System::Windows::Forms::TextBox^ txtSearch;
    private: System::Windows::Forms::Button^ btnSearch;
    private: System::Windows::Forms::Button^ btnAddSample;
    private: System::Windows::Forms::Button^ btnAddProduct;
    private: System::Windows::Forms::Button^ btnEditProduct;
    private: System::Windows::Forms::Button^ btnDeleteProduct;
    private: System::Windows::Forms::Button^ btnAddCategory;
    private: System::Windows::Forms::Button^ btnEditCategory;
    private: System::Windows::Forms::Button^ btnDeleteCategory;
    private: Inventory* inventory;
    private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
           void InitializeComponent(void)
           {
               this->tabControl = (gcnew System::Windows::Forms::TabControl());
               this->tabProducts = (gcnew System::Windows::Forms::TabPage());
               this->tabCategories = (gcnew System::Windows::Forms::TabPage());
               this->dataGridViewProducts = (gcnew System::Windows::Forms::DataGridView());
               this->dataGridViewCategories = (gcnew System::Windows::Forms::DataGridView());
               this->txtSearch = (gcnew System::Windows::Forms::TextBox());
               this->btnSearch = (gcnew System::Windows::Forms::Button());
               this->btnAddSample = (gcnew System::Windows::Forms::Button());
               this->btnAddProduct = (gcnew System::Windows::Forms::Button());
               this->btnEditProduct = (gcnew System::Windows::Forms::Button());
               this->btnDeleteProduct = (gcnew System::Windows::Forms::Button());
               this->btnAddCategory = (gcnew System::Windows::Forms::Button());
               this->btnEditCategory = (gcnew System::Windows::Forms::Button());
               this->btnDeleteCategory = (gcnew System::Windows::Forms::Button());
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewProducts))->BeginInit();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewCategories))->BeginInit();
               this->tabProducts->SuspendLayout();
               this->tabCategories->SuspendLayout();
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
               this->tabProducts->ResumeLayout(false);
               this->tabCategories->ResumeLayout(false);
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
            UpdateProductGrid();
            UpdateCategoryGrid();
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

            for (const auto& product : inventory->getAllProducts())
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

            for (const auto& category : inventory->getAllCategories())
            {
                dataGridViewCategories->Rows->Add(category.getId(), gcnew String(category.getName().c_str()));
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
            Product product(form->ProductId, msclr::interop::marshal_as<std::string>(form->ProductName), form->ProductQuantity, form->ProductPrice, form->ProductCategoryId);
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
                AddEditProductForm^ form = gcnew AddEditProductForm(id, gcnew String(product->getName().c_str()), product->getQuantity(), product->getPrice(), product->getCategoryId(), inventory);
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
            for (const auto& product : inventory->getAllProducts())
            {
                if (product.getCategoryId() == id)
                {
                    hasProducts = true;
                    break;
                }
            }
            if (hasProducts)
            {
                MessageBox::Show(L"Неможливо видалити категорію, оскільки до неї прив’язані продукти.", L"Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }
            if (MessageBox::Show(L"Ви впевнені, що хочете видалити цю категорію?", L"Підтвердження", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
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
    };
}