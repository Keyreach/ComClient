#pragma once
#include <windows.h>
#include <vcclr.h>
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
	private: System::Windows::Forms::TextBox^  TxInput;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  RxOutput;
	private: System::Windows::Forms::Button^  button1;
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
			this->TxInput = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->RxOutput = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
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
			// TxInput
			// 
			this->TxInput->Location = System::Drawing::Point(13, 30);
			this->TxInput->Multiline = true;
			this->TxInput->Name = L"TxInput";
			this->TxInput->Size = System::Drawing::Size(275, 109);
			this->TxInput->TabIndex = 1;
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
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(300, 319);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->RxOutput);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->TxInput);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"COMPort Client";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 //HANDLE Port;
				 //const char* PortName = "\\\\.\\COM10";
				 //Port = CreateFileA(
					//PortName,
					//GENERIC_READ | GENERIC_WRITE,
					//0,
					//NULL,
					//OPEN_EXISTING,
					//0,
					//NULL
					//);
					//// CHECK
				 //if(Port == INVALID_HANDLE_VALUE){
					// MessageBox::Show("Cannot open serial port", "Erreur", MessageBoxButtons::OK, MessageBoxIcon::Stop);
					//ExitProcess(1);
				 //}
				 //MessageBox::Show("Successfully opened port", "COM Client", MessageBoxButtons::OK, MessageBoxIcon::Information);
				 //// Setting stuff
				 //COMMTIMEOUTS CommTimeOuts;
				 //CommTimeOuts.ReadIntervalTimeout = 0xFFFFFFFF;
				 //CommTimeOuts.ReadTotalTimeoutMultiplier = 0;
				 //CommTimeOuts.ReadTotalTimeoutConstant = 1000;
				 //CommTimeOuts.WriteTotalTimeoutMultiplier = 0;
				 //CommTimeOuts.WriteTotalTimeoutConstant = 1000;
				 // Sending stuff
				 char* dat;
				 long int responsebytes;
				 IntPtr initialStringPtr = Marshal::StringToHGlobalAnsi(TxInput->Text);
				 char* converted = static_cast<char*>(initialStringPtr.ToPointer());
				 unsigned int datasize = strlen(converted);
				 MessageBox::Show("Sending "+datasize+" bytes", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
				 /*WriteFile(Port, converted, datasize, &written, 0);
				 ReadFile(Port, &dat, 1, &written, 0);*/
				 SerialPort port1("\\\\.\\COM10");
				 port1.Write(converted, datasize);
				 dat = port1.Read(responsebytes);
				 dat[responsebytes] = '\0';
				 String^ ds = gcnew String(dat);
				 RxOutput->Text = ds;
				 Marshal::FreeHGlobal(initialStringPtr);
				 // Close
				 //CloseHandle(Port);
			 }
};
}
