#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace PruebaCE {

	/// <summary>
	/// Summary for SelFecha
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class SelFecha : public System::Windows::Forms::Form
	{
	public:
		SelFecha(void)
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
		~SelFecha()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::DateTimePicker^  dtpInicial;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::DateTimePicker^  dtpFinal;

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	protected: 

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(SelFecha::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dtpInicial = (gcnew System::Windows::Forms::DateTimePicker());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->dtpFinal = (gcnew System::Windows::Forms::DateTimePicker());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(29, 41);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(67, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Fecha Inicial";
			// 
			// dtpInicial
			// 
			this->dtpInicial->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dtpInicial->Location = System::Drawing::Point(102, 35);
			this->dtpInicial->Name = L"dtpInicial";
			this->dtpInicial->Size = System::Drawing::Size(85, 20);
			this->dtpInicial->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(29, 69);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(62, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Fecha Final";
			// 
			// dtpFinal
			// 
			this->dtpFinal->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dtpFinal->Location = System::Drawing::Point(102, 63);
			this->dtpFinal->Name = L"dtpFinal";
			this->dtpFinal->Size = System::Drawing::Size(85, 20);
			this->dtpFinal->TabIndex = 3;
			// 
			// button1
			// 
			this->button1->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->button1->Location = System::Drawing::Point(31, 99);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(59, 30);
			this->button1->TabIndex = 4;
			this->button1->Text = L"&Aceptar";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->button2->Location = System::Drawing::Point(128, 99);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(59, 30);
			this->button2->TabIndex = 5;
			this->button2->Text = L"&Cancelar";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// SelFecha
			// 
			this->AcceptButton = this->button1;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->button2;
			this->ClientSize = System::Drawing::Size(228, 156);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dtpFinal);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->dtpInicial);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"SelFecha";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Seleccione Fecha";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		public:
			property DateTime varInicio{
				void set(DateTime valor){
					dtpInicial->Value = valor;
					return;
				}
				DateTime get(){
					return dtpInicial->Value;
				}
			}
			property DateTime varFinal{
				void set(DateTime valor){
					dtpFinal->Value = valor;
					return;
				}
				DateTime get(){
					return dtpFinal->Value;
				}
			}
#pragma endregion
	};
}
