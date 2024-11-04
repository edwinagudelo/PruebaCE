#pragma once

#include "IExportService.h"
#include "NPOIExportService.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Text;
using namespace System::Windows::Forms;
using namespace Microsoft::Office::Interop;

using namespace Infrastructure;

namespace PruebaCE {

	/// <summary>
	/// Summary for ExportaTablaExcel
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class ExportaTablaExcel : public System::Windows::Forms::Form
	{
	public:
		ExportaTablaExcel(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			exportService = gcnew NPOIExportService();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ExportaTablaExcel()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ProgressBar^  pgbTotal;
	private: System::Windows::Forms::ProgressBar^  pgbParcial;
	protected: 


	private: System::Windows::Forms::Label^  label2;

	private: DataTable^ dt;
	private: bool EnTexto;
	private: bool EsUtf8;
	private: bool cancel;
	private: System::Windows::Forms::Button^  btnCancelar;
	private: System::ComponentModel::BackgroundWorker^ bgwExporter;
	private:
		IExportService^ exportService;
		String^ filename;
		String^ path;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ExportaTablaExcel::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pgbTotal = (gcnew System::Windows::Forms::ProgressBar());
			this->pgbParcial = (gcnew System::Windows::Forms::ProgressBar());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btnCancelar = (gcnew System::Windows::Forms::Button());
			this->bgwExporter = (gcnew System::ComponentModel::BackgroundWorker());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(321, 23);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(97, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Progreso Total";
			// 
			// pgbTotal
			// 
			this->pgbTotal->Location = System::Drawing::Point(67, 55);
			this->pgbTotal->Margin = System::Windows::Forms::Padding(4);
			this->pgbTotal->Name = L"pgbTotal";
			this->pgbTotal->Size = System::Drawing::Size(613, 47);
			this->pgbTotal->TabIndex = 1;
			// 
			// pgbParcial
			// 
			this->pgbParcial->Location = System::Drawing::Point(67, 110);
			this->pgbParcial->Margin = System::Windows::Forms::Padding(4);
			this->pgbParcial->Name = L"pgbParcial";
			this->pgbParcial->Size = System::Drawing::Size(613, 36);
			this->pgbParcial->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(321, 161);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(108, 16);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Progreso Parcial";
			// 
			// btnCancelar
			// 
			this->btnCancelar->Location = System::Drawing::Point(273, 186);
			this->btnCancelar->Margin = System::Windows::Forms::Padding(4);
			this->btnCancelar->Name = L"btnCancelar";
			this->btnCancelar->Size = System::Drawing::Size(207, 34);
			this->btnCancelar->TabIndex = 4;
			this->btnCancelar->Text = L"Cancelar";
			this->btnCancelar->UseVisualStyleBackColor = true;
			this->btnCancelar->Click += gcnew System::EventHandler(this, &ExportaTablaExcel::btnCancelar_Click);
			// 
			// bgwExporter
			// 
			this->bgwExporter->WorkerReportsProgress = true;
			this->bgwExporter->WorkerSupportsCancellation = true;
			this->bgwExporter->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &ExportaTablaExcel::bgwExporter_DoWork);
			this->bgwExporter->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &ExportaTablaExcel::bgwExporter_ProgressChanged);
			this->bgwExporter->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &ExportaTablaExcel::bgwExporter_RunWorkerCompleted);
			// 
			// ExportaTablaExcel
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(737, 255);
			this->Controls->Add(this->btnCancelar);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->pgbParcial);
			this->Controls->Add(this->pgbTotal);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"ExportaTablaExcel";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Exportando";
			this->Load += gcnew System::EventHandler(this, &ExportaTablaExcel::ExportaTablaExcel_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

#pragma region Properties
	public:
		property DataTable^ varTabla {
			void set(DataTable^ valor) {
				dt = valor;
				return;
			}
			DataTable^ get() {
				return dt;
			}
		}
		property bool varTexto {
			void set(bool valor) {
				EnTexto = valor;
				return;
			}
			bool get() {
				return EnTexto;
			}
		}
		property bool varUtf {
			void set(bool valor) {
				EsUtf8 = valor;
				return;
			}
			bool get() {
				return EsUtf8;
			}
		}
		property String^ FileName {
			void set(String^ val) {
				filename = val;
			}
			String^ get() {
				return filename;
			}
		}
		property String^ OutPath {
			void set(String^ val) {
				path = val;
			}
			String^ get() {
				return path;
			}
		}
#pragma endregion

	public:

		// Funcion que se encarga de exportar a Excel una tabla previamente cargada
		int Exportar(void)
		{
			this->Show();
			cancel = false;
			int totalRegs = 0;
			int iTransferidas = 0;
			// Arranco validando la informacion de la tabla
			if(dt->Rows->Count == 0){
				MessageBox::Show("No hay registros a exportar","Atencion",MessageBoxButtons::OK,MessageBoxIcon::Exclamation);
				Close();
				return 0;
			}
			totalRegs = dt->Rows->Count;
			// El progreso total
			pgbTotal->Minimum = 0;
			pgbTotal->Maximum = totalRegs;
			pgbTotal->Step = 1;
			pgbTotal->Value = 0;
			// El progreso parcial
			pgbParcial->Minimum = 0;
			pgbParcial->Maximum = dt->Columns->Count;
			pgbParcial->Step = 1;
			pgbParcial->Value = 0;
			// Ahora comienzo a configurar el objeto XLS
			Excel::Application^ xls = gcnew Excel::Application();
			Excel::Workbook^ libro = (Excel::Workbook^)xls->Workbooks->Add(Type::Missing);
			Excel::Worksheet^ hoja = (Excel::Worksheet^)libro->ActiveSheet;
			// Ahora arranco a escribir los encabezados de la tabla
			int i = 1;
			int j = 1;
			hoja->Range["1:1",Type::Missing]->Font->Bold = true;
			for each (DataColumn^ colum in dt->Columns){
				((Excel::Range^)hoja->Cells[i,j])->Value2 = colum->ColumnName;
				j++;
			}
			i++;
			// Ahora escribo los registros de la tabla
			for each (DataRow^ fila in dt->Rows){
				if(cancel)break;
				pgbParcial->Value = 1;
				j = 1;
				for each(DataColumn^ col in dt->Columns){
					if(EnTexto){
						((Excel::Range^)hoja->Cells[i,j])->NumberFormat = "@";
					}
					if(EsUtf8){
						((Excel::Range^)hoja->Cells[i,j])->Value2 = UTF82Ansi(fila[(j-1)]->ToString());
					}
					else{
						((Excel::Range^)hoja->Cells[i,j])->Value2 = fila[(j-1)]->ToString();
					}
					j++;
					pgbParcial->PerformStep();
				}
				i++;
				iTransferidas++;
				pgbTotal->PerformStep();
			}
			Close();
			hoja->Columns->AutoFit();
			xls->Visible = true;
			return iTransferidas;
		}

		// Esta funcion transfiere la tabla a Excel y al final guarda el libro en un path que se le indique
		int Exportar(String^ path,bool silencio)
		{
			if(!silencio)this->Show();
			cancel = false;
			int totalRegs = 0;
			int iTransferidas = 0;
			// Arranco validando la informacion de la tabla
			if(dt->Rows->Count == 0){
				MessageBox::Show("No hay registros a exportar","Atencion",MessageBoxButtons::OK,MessageBoxIcon::Exclamation);
				Close();
				return 0;
			}
			totalRegs = dt->Rows->Count;
			// El progreso total
			pgbTotal->Minimum = 0;
			pgbTotal->Maximum = totalRegs;
			pgbTotal->Step = 1;
			pgbTotal->Value = 0;
			// El progreso parcial
			pgbParcial->Minimum = 0;
			pgbParcial->Maximum = dt->Columns->Count;
			pgbParcial->Step = 1;
			pgbParcial->Value = 0;
			// Ahora comienzo a configurar el objeto XLS
			Excel::Application^ xls = gcnew Excel::Application();
			Excel::Workbook^ libro = (Excel::Workbook^)xls->Workbooks->Add(Type::Missing);
			Excel::Worksheet^ hoja = (Excel::Worksheet^)libro->ActiveSheet;
			// Ahora arranco a escribir los encabezados de la tabla
			int i = 1;
			int j = 1;
			hoja->Range["1:1",Type::Missing]->Font->Bold = true;
			for each (DataColumn^ colum in dt->Columns){
				((Excel::Range^)hoja->Cells[i,j])->Value2 = colum->ColumnName;
				j++;
			}
			i++;
			// Ahora escribo los registros de la tabla
			for each (DataRow^ fila in dt->Rows){
				if(cancel)break;
				pgbParcial->Value = 1;
				j = 1;
				for each(DataColumn^ col in dt->Columns){
					if(EnTexto){
						((Excel::Range^)hoja->Cells[i,j])->NumberFormat = "@";
					}
					if(EsUtf8){
						((Excel::Range^)hoja->Cells[i,j])->Value2 = UTF82Ansi(fila[(j-1)]->ToString());
					}
					else{
						((Excel::Range^)hoja->Cells[i,j])->Value2 = fila[(j-1)]->ToString();
					}
					j++;
					pgbParcial->PerformStep();
				}
				i++;
				iTransferidas++;
				pgbTotal->PerformStep();
			}
			Close();
			hoja->Columns->AutoFit();
			libro->Close(true,path,Type::Missing);
			delete hoja;
			delete libro;
			xls->Quit();
			delete xls;
			return iTransferidas;
		}


		public:

		// Convertir de Ansi a UTF8
		String^ Ansi2UTF8(String^ varCadena)
		{
			Encoding^ encoder1 = Encoding::ASCII;
			UTF8Encoding^ encoder2 = gcnew UTF8Encoding();
			ASCIIEncoding^ encoder3 = gcnew ASCIIEncoding();
			array<Byte>^ bascii = encoder1->GetBytes(varCadena);
			array<Byte>^ butf8 = encoder3->Convert(Encoding::ASCII,Encoding::UTF8,bascii);
			String^ retorno = encoder2->GetString(butf8);
			return retorno;
		}

		// Conversion UTF8 a Ansi
		String^ UTF82Ansi(String^ varCadena)
		{
			Encoding^ encoder1 = Encoding::UTF8;
			UTF8Encoding^ encoder2 = gcnew UTF8Encoding();
			ASCIIEncoding^ encoder3 = gcnew ASCIIEncoding();
			array<Byte>^ butf8 = encoder1->GetBytes(varCadena);
			array<Byte>^ bascii = encoder2->Convert(Encoding::UTF8,Encoding::ASCII,butf8);
			String^ retorno = encoder3->GetString(bascii);
			return retorno;
		}
private: System::Void ExportaTablaExcel_Load(System::Object^  sender, System::EventArgs^  e) {
			exportService->SetData(dt);
			exportService->SetFilename(filename);
			exportService->SetPath(path);
			exportService->ProgressReportEvent += gcnew Infrastructure::exportProgress(this, &ExportaTablaExcel::bgwExporter_ProgressChanged);
			bgwExporter->RunWorkerAsync();
		 }
private: System::Void btnCancelar_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(MessageBox::Show("¿Desea cancelar la transferencia?","Atencion",MessageBoxButtons::YesNo,MessageBoxIcon::Exclamation) == ::DialogResult::Yes){
				 cancel = true;
			 }
		 }
private: System::Void bgwExporter_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {
			int exported = exportService->Export();
}
private: System::Void bgwExporter_ProgressChanged(System::Object^ sender, System::ComponentModel::ProgressChangedEventArgs^ e) {
}
private: System::Void bgwExporter_RunWorkerCompleted(System::Object^ sender, System::ComponentModel::RunWorkerCompletedEventArgs^ e) {
}
};
}
