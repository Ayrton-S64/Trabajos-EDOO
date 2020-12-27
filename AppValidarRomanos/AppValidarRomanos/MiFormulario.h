#pragma once
#include "Operaciones.h"
namespace AppValidarRomanos {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MiFormulario
	/// </summary>
	public ref class MiFormulario : public System::Windows::Forms::Form
	{
		COperaciones *OP = new COperaciones();
	public:
		MiFormulario(void)
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
		~MiFormulario()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  txtRomano;
	protected:

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  txtDecimal;
	private: System::Windows::Forms::Button^  btnConvertir;
	private: System::Windows::Forms::Button^  btnNuevo;




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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtRomano = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtDecimal = (gcnew System::Windows::Forms::TextBox());
			this->btnConvertir = (gcnew System::Windows::Forms::Button());
			this->btnNuevo = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(14, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(121, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Ingresar numero romano";
			// 
			// txtRomano
			// 
			this->txtRomano->Location = System::Drawing::Point(187, 19);
			this->txtRomano->Name = L"txtRomano";
			this->txtRomano->Size = System::Drawing::Size(100, 20);
			this->txtRomano->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(14, 138);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(141, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Numero decimal equivalente";
			this->label2->Click += gcnew System::EventHandler(this, &MiFormulario::label2_Click);
			// 
			// txtDecimal
			// 
			this->txtDecimal->Enabled = false;
			this->txtDecimal->Location = System::Drawing::Point(187, 135);
			this->txtDecimal->Name = L"txtDecimal";
			this->txtDecimal->Size = System::Drawing::Size(100, 20);
			this->txtDecimal->TabIndex = 3;
			// 
			// btnConvertir
			// 
			this->btnConvertir->Location = System::Drawing::Point(111, 55);
			this->btnConvertir->Name = L"btnConvertir";
			this->btnConvertir->Size = System::Drawing::Size(100, 63);
			this->btnConvertir->TabIndex = 4;
			this->btnConvertir->Text = L"Convertir a decimal";
			this->btnConvertir->UseVisualStyleBackColor = true;
			this->btnConvertir->Click += gcnew System::EventHandler(this, &MiFormulario::btnConvertir_Click);
			// 
			// btnNuevo
			// 
			this->btnNuevo->Location = System::Drawing::Point(224, 173);
			this->btnNuevo->Name = L"btnNuevo";
			this->btnNuevo->Size = System::Drawing::Size(75, 23);
			this->btnNuevo->TabIndex = 5;
			this->btnNuevo->Text = L"Nuevo";
			this->btnNuevo->UseVisualStyleBackColor = true;
			this->btnNuevo->Click += gcnew System::EventHandler(this, &MiFormulario::btnNuevo_Click);
			// 
			// MiFormulario
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(311, 208);
			this->Controls->Add(this->btnNuevo);
			this->Controls->Add(this->btnConvertir);
			this->Controls->Add(this->txtDecimal);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->txtRomano);
			this->Controls->Add(this->label1);
			this->Name = L"MiFormulario";
			this->Text = L"MiFormulario";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void btnNuevo_Click(System::Object^  sender, System::EventArgs^  e) {
	txtRomano->Text = "";
	txtRomano->Focus();
	txtDecimal->Text = "";
}
private: System::Void btnConvertir_Click(System::Object^  sender, System::EventArgs^  e) {
	if (txtRomano->Text == "") {
		MessageBox::Show("No puedes convertir una cadena vacia");
	} else {
		if (OP->validarRomano(txtRomano->Text->ToUpper(), ' ', 0, 0, 4, true)) {
			txtDecimal->Text = Convert::ToString(OP->ADecimal((txtRomano->Text + " ")->ToUpper(), 0, txtRomano->Text->Length));
		} else {
			MessageBox::Show("El numero ingresado no es valido");
		}
	}
}
};
}
