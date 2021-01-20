#pragma once

#include "src.h"

bool toggle = false;
bool running = false;

namespace CppCLRWinformsProjekt {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Threading;

	/// <summary>
	/// Zusammenfassung f? Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzuf?en.
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ saveBtn;



	private: System::Windows::Forms::TrackBar^ afterValueBar;
	private: System::Windows::Forms::TrackBar^ beforeValueBar;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Label^ jackCountLabel;

	private: System::Windows::Forms::Button^ runBtn;
	private: System::Windows::Forms::NumericUpDown^ afterValueBox;
	private: System::Windows::Forms::NumericUpDown^ beforeValueBox;
	private: System::Windows::Forms::CheckBox^ applyOnceCb;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	private: System::Windows::Forms::NumericUpDown^ delayTime;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ stopBtn;

	protected:

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode f? die Designerunterst?zung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor ge?dert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->afterValueBox = (gcnew System::Windows::Forms::NumericUpDown());
			this->beforeValueBox = (gcnew System::Windows::Forms::NumericUpDown());
			this->saveBtn = (gcnew System::Windows::Forms::Button());
			this->afterValueBar = (gcnew System::Windows::Forms::TrackBar());
			this->beforeValueBar = (gcnew System::Windows::Forms::TrackBar());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->jackCountLabel = (gcnew System::Windows::Forms::Label());
			this->runBtn = (gcnew System::Windows::Forms::Button());
			this->applyOnceCb = (gcnew System::Windows::Forms::CheckBox());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->delayTime = (gcnew System::Windows::Forms::NumericUpDown());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->stopBtn = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->afterValueBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->beforeValueBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->afterValueBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->beforeValueBar))->BeginInit();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->delayTime))->BeginInit();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->afterValueBox);
			this->groupBox1->Controls->Add(this->beforeValueBox);
			this->groupBox1->Controls->Add(this->saveBtn);
			this->groupBox1->Controls->Add(this->afterValueBar);
			this->groupBox1->Controls->Add(this->beforeValueBar);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(317, 182);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Settings";
			// 
			// afterValueBox
			// 
			this->afterValueBox->Location = System::Drawing::Point(247, 95);
			this->afterValueBox->Name = L"afterValueBox";
			this->afterValueBox->Size = System::Drawing::Size(41, 21);
			this->afterValueBox->TabIndex = 6;
			this->afterValueBox->ValueChanged += gcnew System::EventHandler(this, &Form1::afterValueBox_Changed);
			// 
			// beforeValueBox
			// 
			this->beforeValueBox->Location = System::Drawing::Point(247, 44);
			this->beforeValueBox->Name = L"beforeValueBox";
			this->beforeValueBox->Size = System::Drawing::Size(41, 21);
			this->beforeValueBox->TabIndex = 5;
			this->beforeValueBox->ValueChanged += gcnew System::EventHandler(this, &Form1::beforeValueBox_Changed);
			// 
			// saveBtn
			// 
			this->saveBtn->Location = System::Drawing::Point(94, 146);
			this->saveBtn->Name = L"saveBtn";
			this->saveBtn->Size = System::Drawing::Size(118, 24);
			this->saveBtn->TabIndex = 1;
			this->saveBtn->Text = L"Settings Save";
			this->saveBtn->UseVisualStyleBackColor = true;
			this->saveBtn->Click += gcnew System::EventHandler(this, &Form1::saveBtn_Click);
			// 
			// afterValueBar
			// 
			this->afterValueBar->Location = System::Drawing::Point(94, 95);
			this->afterValueBar->Maximum = 100;
			this->afterValueBar->Name = L"afterValueBar";
			this->afterValueBar->Size = System::Drawing::Size(147, 45);
			this->afterValueBar->TabIndex = 4;
			this->afterValueBar->TickFrequency = 5;
			this->afterValueBar->ValueChanged += gcnew System::EventHandler(this, &Form1::afterValueBar_Changed);
			// 
			// beforeValueBar
			// 
			this->beforeValueBar->Location = System::Drawing::Point(94, 44);
			this->beforeValueBar->Maximum = 100;
			this->beforeValueBar->Name = L"beforeValueBar";
			this->beforeValueBar->Size = System::Drawing::Size(147, 45);
			this->beforeValueBar->TabIndex = 3;
			this->beforeValueBar->TickFrequency = 5;
			this->beforeValueBar->ValueChanged += gcnew System::EventHandler(this, &Form1::beforeValueBar_Changed);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"±¼¸²", 11));
			this->label2->Location = System::Drawing::Point(22, 95);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(36, 15);
			this->label2->TabIndex = 2;
			this->label2->Text = L"After";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"±¼¸²", 11));
			this->label1->Location = System::Drawing::Point(22, 44);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(50, 15);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Before";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->jackCountLabel);
			this->groupBox2->Location = System::Drawing::Point(335, 12);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(239, 65);
			this->groupBox2->TabIndex = 5;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Detected Audio Jack";
			// 
			// jackCountLabel
			// 
			this->jackCountLabel->AutoSize = true;
			this->jackCountLabel->Font = (gcnew System::Drawing::Font(L"±¼¸²", 11));
			this->jackCountLabel->Location = System::Drawing::Point(103, 30);
			this->jackCountLabel->Name = L"jackCountLabel";
			this->jackCountLabel->Size = System::Drawing::Size(41, 15);
			this->jackCountLabel->TabIndex = 6;
			this->jackCountLabel->Text = L"None";
			// 
			// runBtn
			// 
			this->runBtn->Location = System::Drawing::Point(394, 171);
			this->runBtn->Name = L"runBtn";
			this->runBtn->Size = System::Drawing::Size(61, 33);
			this->runBtn->TabIndex = 6;
			this->runBtn->Text = L"Run";
			this->runBtn->UseVisualStyleBackColor = true;
			this->runBtn->Click += gcnew System::EventHandler(this, &Form1::runBtn_Click);
			// 
			// applyOnceCb
			// 
			this->applyOnceCb->AutoSize = true;
			this->applyOnceCb->Font = (gcnew System::Drawing::Font(L"±¼¸²", 9));
			this->applyOnceCb->Location = System::Drawing::Point(394, 136);
			this->applyOnceCb->Name = L"applyOnceCb";
			this->applyOnceCb->Size = System::Drawing::Size(137, 16);
			this->applyOnceCb->TabIndex = 7;
			this->applyOnceCb->Text = L"Apply once and exit";
			this->applyOnceCb->UseVisualStyleBackColor = true;
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->WorkerSupportsCancellation = true;
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &Form1::backgroundWorker1_DoWork);
			this->backgroundWorker1->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &Form1::backgroundWorker1_RunWorkerCompleted);
			// 
			// delayTime
			// 
			this->delayTime->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
			this->delayTime->Location = System::Drawing::Point(470, 99);
			this->delayTime->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->delayTime->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 500, 0, 0, 0 });
			this->delayTime->Name = L"delayTime";
			this->delayTime->Size = System::Drawing::Size(61, 21);
			this->delayTime->TabIndex = 8;
			this->delayTime->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 500, 0, 0, 0 });
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(362, 101);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(93, 12);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Detection Delay";
			// 
			// stopBtn
			// 
			this->stopBtn->Location = System::Drawing::Point(470, 171);
			this->stopBtn->Name = L"stopBtn";
			this->stopBtn->Size = System::Drawing::Size(61, 33);
			this->stopBtn->TabIndex = 10;
			this->stopBtn->Text = L"Stop";
			this->stopBtn->UseVisualStyleBackColor = true;
			this->stopBtn->Click += gcnew System::EventHandler(this, &Form1::stopBtn_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(586, 216);
			this->Controls->Add(this->stopBtn);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->delayTime);
			this->Controls->Add(this->applyOnceCb);
			this->Controls->Add(this->runBtn);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Name = L"Form1";
			this->Text = L"VolumeSwitcher";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->afterValueBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->beforeValueBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->afterValueBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->beforeValueBar))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->delayTime))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
		runBtn->Enabled = true;
		stopBtn->Enabled = false;

		String^ savepath = "vcsave.txt";
		try {
			StreamReader^ sr = gcnew StreamReader(savepath);
			String^ line;
			int cnt = 0;

			while ((line = sr->ReadLine()) != nullptr) {
				if (cnt == 0)
					afterValueBar->Value = Convert::ToInt32(line);
				else if (cnt == 1){
					afterValueBox->Value = Convert::ToInt32(line);
				}
				else if (cnt == 2){
					delayTime->Value = Convert::ToInt32(line);
				}
				else if (cnt == 3) {
					if (line == "Checked")
						applyOnceCb->Checked = true;
					else
						applyOnceCb->Checked = false;
				}
				else {
					break;
				}
				cnt++;
			}

			sr->Close();
		}
		catch (Exception^ e){
			if (!dynamic_cast<FileNotFoundException^>(e))
				MessageBox::Show(L"Problem reading file : " + savepath);
		}
		

		/* First, Get the number of jacks connected to the computer
			on green slot when program start */
		int greenJackCnt = GetGreenJackCount();
		if (greenJackCnt == -1)
		{
			MessageBox::Show(L"Get Jack info failed\nCheck your audio output, and restart this program.");
			return;
		}

		/* Second, Get current speaker volume */
		int volume = GetVolume();

		beforeValueBar->Value = volume;
		beforeValueBox->Value = volume;
		jackCountLabel->Text = greenJackCnt.ToString();
	}

	/* Save value settings */
	private: System::Void saveBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ savepath = "vcsave.txt";
		StreamWriter^ sw = gcnew StreamWriter(savepath);
		sw->WriteLine(afterValueBar->Value);
		sw->WriteLine(afterValueBox->Value);
		sw->WriteLine(delayTime->Value);
		sw->WriteLine(applyOnceCb->CheckState);

		sw->Close();

		MessageBox::Show("Save complete");
		return;
	}

	/* Synchronizing Value bar with Value box */
	private: System::Void beforeValueBar_Changed(System::Object^ sender, System::EventArgs^ e) {
		beforeValueBox->Value = Convert::ToInt32(beforeValueBar->Value);
	}

	private: System::Void beforeValueBox_Changed(System::Object^ sender, System::EventArgs^ e) {
		beforeValueBar->Value = Convert::ToInt32(beforeValueBox->Value);
	}

	private: System::Void afterValueBar_Changed(System::Object^ sender, System::EventArgs^ e) {
		afterValueBox->Value = Convert::ToInt32(afterValueBar->Value);
	}

	private: System::Void afterValueBox_Changed(System::Object^ sender, System::EventArgs^ e) {
		afterValueBar->Value = Convert::ToInt32(afterValueBox->Value);
	}

	/* Run grogram */
	private: System::Void runBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		runBtn->Enabled = false;
		stopBtn->Enabled = true;
		backgroundWorker1->RunWorkerAsync();
	}

	private: System::Void backgroundWorker1_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {
		int initCnt = GetGreenJackCount();

		while (initCnt == GetGreenJackCount()) {
			if (backgroundWorker1->CancellationPending) {
				e->Cancel = true;
				return;
			}
			Thread::Sleep(Convert::ToInt32(delayTime->Value));
		}

		double volume;
		if (!toggle)
			volume = Convert::ToInt32(afterValueBox->Value);
		else
			volume = Convert::ToInt32(beforeValueBox->Value);

		toggle = !toggle;

		SetVolume(volume);

	}

	private: System::Void backgroundWorker1_RunWorkerCompleted(System::Object^ sender, System::ComponentModel::RunWorkerCompletedEventArgs^ e) {
		if (!applyOnceCb->Checked) {
			jackCountLabel->Text = GetGreenJackCount().ToString();
			if (e->Cancelled) {
				return;
			}
			else
				backgroundWorker1->RunWorkerAsync();
		}
		else
			Environment::Exit(Environment::ExitCode);
	}
	private: System::Void stopBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		backgroundWorker1->CancelAsync();
		runBtn->Enabled = true;
		stopBtn->Enabled = false;
	}
};
}
