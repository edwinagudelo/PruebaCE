#pragma once

#include "ExportaTablaExcel.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Data;


namespace PruebaCE {

	/// <summary>
	/// Summary for VerTabla
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class VerTabla : public System::Windows::Forms::Form
	{
	public:
		VerTabla(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~VerTabla()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  dgvPrincipal;
	protected: 
	private: System::Windows::Forms::Button^  btnAceptar;
	private: System::Windows::Forms::Button^  btnExportar;

	private: DataTable^ dt;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(VerTabla::typeid));
			this->dgvPrincipal = (gcnew System::Windows::Forms::DataGridView());
			this->btnAceptar = (gcnew System::Windows::Forms::Button());
			this->btnExportar = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvPrincipal))->BeginInit();
			this->SuspendLayout();
			// 
			// dgvPrincipal
			// 
			this->dgvPrincipal->AllowUserToAddRows = false;
			this->dgvPrincipal->AllowUserToDeleteRows = false;
			this->dgvPrincipal->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvPrincipal->Location = System::Drawing::Point(27, 53);
			this->dgvPrincipal->Name = L"dgvPrincipal";
			this->dgvPrincipal->ReadOnly = true;
			this->dgvPrincipal->Size = System::Drawing::Size(548, 170);
			this->dgvPrincipal->TabIndex = 0;
			// 
			// btnAceptar
			// 
			this->btnAceptar->Location = System::Drawing::Point(58, 239);
			this->btnAceptar->Name = L"btnAceptar";
			this->btnAceptar->Size = System::Drawing::Size(124, 30);
			this->btnAceptar->TabIndex = 1;
			this->btnAceptar->Text = L"&Aceptar";
			this->btnAceptar->UseVisualStyleBackColor = true;
			this->btnAceptar->Click += gcnew System::EventHandler(this, &VerTabla::btnAceptar_Click);
			// 
			// btnExportar
			// 
			this->btnExportar->Location = System::Drawing::Point(409, 239);
			this->btnExportar->Name = L"btnExportar";
			this->btnExportar->Size = System::Drawing::Size(124, 30);
			this->btnExportar->TabIndex = 2;
			this->btnExportar->Text = L"&Exportar";
			this->btnExportar->UseVisualStyleBackColor = true;
			this->btnExportar->Click += gcnew System::EventHandler(this, &VerTabla::btnExportar_Click);
			// 
			// VerTabla
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(607, 301);
			this->Controls->Add(this->btnExportar);
			this->Controls->Add(this->btnAceptar);
			this->Controls->Add(this->dgvPrincipal);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"VerTabla";
			this->Text = L"Ver Tabla";
			this->Load += gcnew System::EventHandler(this, &VerTabla::VerTabla_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvPrincipal))->EndInit();
			this->ResumeLayout(false);

		}
	public:
		property DataTable^ varTabla{
			void set(DataTable^ valor){
				dt = valor;
				return;
			}
			DataTable^ get(){
				return dt;
			}
		}
#pragma endregion
	private: System::Void VerTabla_Load(System::Object^  sender, System::EventArgs^  e) {
				 this->Text = "Ver Tabla >> " + dt->TableName;
				 dgvPrincipal->DataSource = dt->DefaultView;
				 return;
			 }
	private: System::Void btnExportar_Click(System::Object^  sender, System::EventArgs^  e) {
				 ExportaTablaExcel^ dlgExp = gcnew ExportaTablaExcel();
				 dlgExp->varTabla = dt;
				 dlgExp->varTexto = false;
				 dlgExp->Exportar();
			 }
private: System::Void btnAceptar_Click(System::Object^  sender, System::EventArgs^  e) {
			 Close();
		 }
};
}
