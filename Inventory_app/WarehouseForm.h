#pragma once

#include "../RGR/Inventory.h"
#include "../RGR/Warehouse.h"

#include <msclr/marshal_cppstd.h>

namespace InventoryApp {

    using namespace System;
    using namespace System::Windows::Forms;
    using namespace System::Drawing;
    using namespace msclr::interop;

    public ref class WarehouseForm : public Form {
    private:
        Inventory* inventory;
        DataGridView^ dataGridView;
        TextBox^ txtId;
        TextBox^ txtLocation;
        Button^ btnAdd;

    public:
        WarehouseForm(Inventory* inv) {
            inventory = inv;
            InitializeComponent();
            LoadWarehouses();
        }

    private:
        void InitializeComponent() {
            this->Text = "Warehouses";
            this->Size = Drawing::Size(600, 400);

            dataGridView = gcnew DataGridView();
            dataGridView->Location = Point(10, 10);
            dataGridView->Size = Drawing::Size(560, 200);
            dataGridView->ReadOnly = true;
            dataGridView->AllowUserToAddRows = false;
            dataGridView->ColumnCount = 2;
            dataGridView->Columns[0]->Name = "ID";
            dataGridView->Columns[1]->Name = "Location";
            this->Controls->Add(dataGridView);

            Label^ lblId = gcnew Label();
            lblId->Text = "ID:";
            lblId->Location = Point(10, 230);
            this->Controls->Add(lblId);

            txtId = gcnew TextBox();
            txtId->Location = Point(150, 225);
            this->Controls->Add(txtId);

            Label^ lblLocation = gcnew Label();
            lblLocation->Text = "Location:";
            lblLocation->Location = Point(10, 260);
            this->Controls->Add(lblLocation);

            txtLocation = gcnew TextBox();
            txtLocation->Location = Point(150, 255);
            txtLocation->Width = 200;
            this->Controls->Add(txtLocation);

            btnAdd = gcnew Button();
            btnAdd->Text = "Add Warehouse";
            btnAdd->Location = Point(10, 290);
            btnAdd->Click += gcnew EventHandler(this, &WarehouseForm::btnAdd_Click);
            this->Controls->Add(btnAdd);
        }

        void LoadWarehouses() {
            dataGridView->Rows->Clear();
            std::vector<Warehouse> warehouses = inventory->getAllWarehouses();
            for (const auto& wh : warehouses) {
                String^ idStr = wh.getId().ToString();
                String^ locationStr = marshal_as<String^>(wh.getLocation());
                dataGridView->Rows->Add(idStr, locationStr);
            }
        }

        void btnAdd_Click(Object^ sender, EventArgs^ e) {
            try {
                int id = Int32::Parse(txtId->Text);
                std::string location = marshal_as<std::string>(txtLocation->Text);
                inventory->addWarehouse(Warehouse(id, location));
                LoadWarehouses();
                txtId->Clear();
                txtLocation->Clear();
            }
            catch (Exception^ ex) {
                MessageBox::Show("Error: " + ex->Message);
            }
        }
    };
}
