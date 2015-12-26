#pragma once
#include <windows.h>
#include <vcclr.h>
#include <cstdio>
#include <sstream>
#include "SerialPort.h"

using namespace System;
using namespace System::Runtime::InteropServices;

namespace ComClient {

	

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  RxOutput;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::ComboBox^  mb_Function;
	private: System::Windows::Forms::TextBox^  mb_Address;
	private: System::Windows::Forms::TextBox^  mb_Quantity;



	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->RxOutput = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->mb_Function = (gcnew System::Windows::Forms::ComboBox());
			this->mb_Address = (gcnew System::Windows::Forms::TextBox());
			this->mb_Quantity = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(19, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Tx";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 146);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(20, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Rx";
			// 
			// RxOutput
			// 
			this->RxOutput->AutoSize = true;
			this->RxOutput->Location = System::Drawing::Point(13, 163);
			this->RxOutput->Name = L"RxOutput";
			this->RxOutput->Size = System::Drawing::Size(16, 13);
			this->RxOutput->TabIndex = 3;
			this->RxOutput->Text = L"---";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(213, 284);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 4;
			this->button1->Text = L"SEND";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// mb_Function
			// 
			this->mb_Function->FormattingEnabled = true;
			this->mb_Function->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"Read Coil Status", L"Read Discrete Inputs", 
				L"Read Holding Registers", L"Read Input Registers"});
			this->mb_Function->Location = System::Drawing::Point(100, 29);
			this->mb_Function->Name = L"mb_Function";
			this->mb_Function->Size = System::Drawing::Size(188, 21);
			this->mb_Function->TabIndex = 5;
			// 
			// mb_Address
			// 
			this->mb_Address->Location = System::Drawing::Point(100, 57);
			this->mb_Address->Name = L"mb_Address";
			this->mb_Address->Size = System::Drawing::Size(188, 20);
			this->mb_Address->TabIndex = 6;
			// 
			// mb_Quantity
			// 
			this->mb_Quantity->Location = System::Drawing::Point(100, 84);
			this->mb_Quantity->Name = L"mb_Quantity";
			this->mb_Quantity->Size = System::Drawing::Size(188, 20);
			this->mb_Quantity->TabIndex = 7;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 32);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(53, 13);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Функция";
			this->label3->Click += gcnew System::EventHandler(this, &MyForm::label3_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 60);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(38, 13);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Адрес";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(13, 87);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(66, 13);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Количество";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(300, 319);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->mb_Quantity);
			this->Controls->Add(this->mb_Address);
			this->Controls->Add(this->mb_Function);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->RxOutput);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"COMPort Client";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 char* dat;
				 long int responsebytes;
				 char mbReqFunction = mb_Function->SelectedIndex + 1;
				 short mbReqAddress = Convert::ToInt16(mb_Address->Text);
				 short mbReqQuantity = Convert::ToInt16(mb_Quantity->Text);
				 char *converted = new char[5];
				 converted[0] = mbReqFunction;
				 converted[1] = (unsigned char)(mbReqAddress >> 8);
				 converted[2] = (unsigned char)(mbReqAddress);
				 converted[3] = (unsigned char)(mbReqQuantity >> 8);
				 converted[4] = (unsigned char)(mbReqQuantity);
				 SerialPort port1("\\\\.\\COM10");
				 port1.Write(converted, 5);
				 dat = port1.Read(responsebytes);
				 std::stringstream ss;
				 ss << "Received " << responsebytes << " bytes" << std::endl;
				 for(int i=0; i<responsebytes; i++){
					ss << (int)(dat[i]) << " ";
				 }
				 String^ ds = gcnew String(ss.str().c_str());
				 RxOutput->Text = ds;
				 //Marshal::FreeHGlobal(initialStringPtr);
				 // Close
				 //CloseHandle(Port);
			 }
private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}
