#pragma once

#include "IExportService.h"
#include "NPOIExportService.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Data;
using namespace System::Diagnostics;
using namespace System::Drawing;
using namespace System::Text;
using namespace System::Windows::Forms;

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
		static ILog^ _logger = LogManager::GetLogger("ExportaTablaExcel");


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

private: System::Void ExportaTablaExcel_Load(System::Object^  sender, System::EventArgs^  e) {
	// Setup the export service
	exportService->SetData(dt);
	exportService->SetFilename(filename);
	exportService->SetPath(path);
	exportService->ProgressReportEvent += gcnew Infrastructure::exportProgress(this, &ExportaTablaExcel::bgwExporter_ProgressChanged);

	// Setup the progress bar
	pgbParcial->Minimum = 0;
	pgbParcial->Maximum = dt->Rows->Count;
	pgbParcial->Step = 1;

	pgbTotal->Minimum = 0;
	pgbTotal->Maximum = dt->Rows->Count;
	pgbTotal->Step = 1;

	// Execute the thread
	bgwExporter->RunWorkerAsync();
}

private: System::Void btnCancelar_Click(System::Object^  sender, System::EventArgs^  e) {
	if(MessageBox::Show("¿Desea cancelar la transferencia?","Atencion",MessageBoxButtons::YesNo,MessageBoxIcon::Exclamation) == ::DialogResult::Yes){
		exportService->CancelExport();
	}
}

private: System::Void bgwExporter_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {
	int exported = exportService->Export();
}
private: System::Void bgwExporter_ProgressChanged(System::Object^ sender, System::ComponentModel::ProgressChangedEventArgs^ e) {
	pgbParcial->PerformStep();
	pgbTotal->PerformStep();
}
private: System::Void bgwExporter_RunWorkerCompleted(System::Object^ sender, System::ComponentModel::RunWorkerCompletedEventArgs^ e) {
	Process::Start(path + Path::DirectorySeparatorChar + filename);
}
};
}
