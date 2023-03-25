#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace PruebaCE {

	/// <summary>
	/// Summary for Login1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Login1 : public System::Windows::Forms::Form
	{
	public:
		Login1(void)
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
		~Login1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	protected: 
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  txbUsuario;
	private: System::Windows::Forms::TextBox^  txbContrasena;
	private: System::Windows::Forms::Button^  btnAceptar;
	private: System::Windows::Forms::Button^  btnCancelar;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Login1::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txbUsuario = (gcnew System::Windows::Forms::TextBox());
			this->txbContrasena = (gcnew System::Windows::Forms::TextBox());
			this->btnAceptar = (gcnew System::Windows::Forms::Button());
			this->btnCancelar = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(25, 27);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(170, 170);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(289, 34);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(72, 22);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Usuario";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(278, 127);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(103, 22);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Contrasena";
			// 
			// txbUsuario
			// 
			this->txbUsuario->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->txbUsuario->Location = System::Drawing::Point(258, 69);
			this->txbUsuario->Name = L"txbUsuario";
			this->txbUsuario->Size = System::Drawing::Size(143, 27);
			this->txbUsuario->TabIndex = 3;
			this->txbUsuario->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// txbContrasena
			// 
			this->txbContrasena->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->txbContrasena->Location = System::Drawing::Point(258, 161);
			this->txbContrasena->Name = L"txbContrasena";
			this->txbContrasena->PasswordChar = '#';
			this->txbContrasena->Size = System::Drawing::Size(143, 27);
			this->txbContrasena->TabIndex = 4;
			this->txbContrasena->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// btnAceptar
			// 
			this->btnAceptar->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->btnAceptar->Location = System::Drawing::Point(66, 236);
			this->btnAceptar->Name = L"btnAceptar";
			this->btnAceptar->Size = System::Drawing::Size(129, 43);
			this->btnAceptar->TabIndex = 5;
			this->btnAceptar->Text = L"&Aceptar";
			this->btnAceptar->UseVisualStyleBackColor = true;
			this->btnAceptar->Click += gcnew System::EventHandler(this, &Login1::btnAceptar_Click);
			// 
			// btnCancelar
			// 
			this->btnCancelar->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->btnCancelar->Location = System::Drawing::Point(252, 236);
			this->btnCancelar->Name = L"btnCancelar";
			this->btnCancelar->Size = System::Drawing::Size(129, 43);
			this->btnCancelar->TabIndex = 6;
			this->btnCancelar->Text = L"&Cancelar";
			this->btnCancelar->UseVisualStyleBackColor = true;
			this->btnCancelar->Click += gcnew System::EventHandler(this, &Login1::btnCancelar_Click);
			// 
			// Login1
			// 
			this->AcceptButton = this->btnAceptar;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->btnCancelar;
			this->ClientSize = System::Drawing::Size(431, 328);
			this->Controls->Add(this->btnCancelar);
			this->Controls->Add(this->btnAceptar);
			this->Controls->Add(this->txbContrasena);
			this->Controls->Add(this->txbUsuario);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"Login1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Login";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		public:
			property String^ varUsuario{
				void set(String^ valor){
					txbUsuario->Text = valor;
					return;
				}
				String^ get(){
					return txbUsuario->Text;
				}
			}
			property String^ varContrasena{
				void set(String^ valor){
					txbContrasena->Text = valor;
					return;
				}
				String^ get(){
					return txbContrasena->Text;
				}
			}
#pragma endregion
	private: System::Void btnAceptar_Click(System::Object^  sender, System::EventArgs^  e) {
				 Close();
			 }
private: System::Void btnCancelar_Click(System::Object^  sender, System::EventArgs^  e) {
			 Close();
		 }
};
}
