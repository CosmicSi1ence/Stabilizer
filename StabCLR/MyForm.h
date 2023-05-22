#pragma once

#include "stabMain.h"
#include <string>
#include <cstring>

#include <msclr\marshal_cppstd.h>
#include <shellapi.h>

bool* closeProc = new bool[1];
double* timeRem = new double[1];
bool* stopTimer = new bool[1];

namespace StabCLR {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ txtBoxSourcePath;
	protected:


	private: System::Windows::Forms::Label^ lblPath;
	private: System::Windows::Forms::Label^ lblFillPath;
	private: System::Windows::Forms::Label^ lblResultPath;



	private: System::Windows::Forms::TextBox^ txtBoxResultPath;
	private: System::Windows::Forms::Label^ lblFillResultPath;




	private: System::Windows::Forms::Button^ btnGo;
	private: System::Windows::Forms::Button^ btnSourceExpl;
	private: System::Windows::Forms::Button^ btnResultExpl;
	private: System::Windows::Forms::CheckBox^ chBoxSaveSamePath;
	private: System::Windows::Forms::GroupBox^ gBoxInfo;
	private: System::Windows::Forms::RadioButton^ rBtnNone;
	private: System::Windows::Forms::RadioButton^ rBtnFPS;
	private: System::Windows::Forms::RadioButton^ rBtnFrametime;


	private: System::Windows::Forms::Label^ lblFilter;
	private: System::Windows::Forms::Label^ lblDelta;
	private: System::Windows::Forms::GroupBox^ gBoxMethod;
	private: System::Windows::Forms::RadioButton^ rBtnFull;
	private: System::Windows::Forms::RadioButton^ rBtnXY;
	private: System::Windows::Forms::NumericUpDown^ numFilter;
	private: System::Windows::Forms::NumericUpDown^ numDelta;
	private: System::Windows::Forms::GroupBox^ gBoxProc;
	private: System::Windows::Forms::RadioButton^ rBtnGPU;
	private: System::Windows::Forms::RadioButton^ rBtnCPU;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ btnOpenSource;
	private: System::Windows::Forms::Button^ btnOpenResult;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ lblTime;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Label^ lblTimeRem;
	private: System::Windows::Forms::CheckBox^ chBoxConsole;
	private: System::Windows::Forms::Button^ btnConsole;

	private: System::ComponentModel::IContainer^ components;





	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->txtBoxSourcePath = (gcnew System::Windows::Forms::TextBox());
			this->lblPath = (gcnew System::Windows::Forms::Label());
			this->lblFillPath = (gcnew System::Windows::Forms::Label());
			this->lblResultPath = (gcnew System::Windows::Forms::Label());
			this->txtBoxResultPath = (gcnew System::Windows::Forms::TextBox());
			this->lblFillResultPath = (gcnew System::Windows::Forms::Label());
			this->btnGo = (gcnew System::Windows::Forms::Button());
			this->btnSourceExpl = (gcnew System::Windows::Forms::Button());
			this->btnResultExpl = (gcnew System::Windows::Forms::Button());
			this->chBoxSaveSamePath = (gcnew System::Windows::Forms::CheckBox());
			this->gBoxInfo = (gcnew System::Windows::Forms::GroupBox());
			this->rBtnNone = (gcnew System::Windows::Forms::RadioButton());
			this->rBtnFPS = (gcnew System::Windows::Forms::RadioButton());
			this->rBtnFrametime = (gcnew System::Windows::Forms::RadioButton());
			this->lblFilter = (gcnew System::Windows::Forms::Label());
			this->lblDelta = (gcnew System::Windows::Forms::Label());
			this->gBoxMethod = (gcnew System::Windows::Forms::GroupBox());
			this->rBtnFull = (gcnew System::Windows::Forms::RadioButton());
			this->rBtnXY = (gcnew System::Windows::Forms::RadioButton());
			this->numFilter = (gcnew System::Windows::Forms::NumericUpDown());
			this->numDelta = (gcnew System::Windows::Forms::NumericUpDown());
			this->gBoxProc = (gcnew System::Windows::Forms::GroupBox());
			this->rBtnGPU = (gcnew System::Windows::Forms::RadioButton());
			this->rBtnCPU = (gcnew System::Windows::Forms::RadioButton());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->btnOpenSource = (gcnew System::Windows::Forms::Button());
			this->btnOpenResult = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->lblTime = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->lblTimeRem = (gcnew System::Windows::Forms::Label());
			this->chBoxConsole = (gcnew System::Windows::Forms::CheckBox());
			this->btnConsole = (gcnew System::Windows::Forms::Button());
			this->gBoxInfo->SuspendLayout();
			this->gBoxMethod->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numFilter))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numDelta))->BeginInit();
			this->gBoxProc->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// txtBoxSourcePath
			// 
			this->txtBoxSourcePath->Location = System::Drawing::Point(51, 396);
			this->txtBoxSourcePath->Name = L"txtBoxSourcePath";
			this->txtBoxSourcePath->Size = System::Drawing::Size(271, 20);
			this->txtBoxSourcePath->TabIndex = 1;
			this->txtBoxSourcePath->TextChanged += gcnew System::EventHandler(this, &MyForm::txtBoxSourcePath_TextChanged);
			// 
			// lblPath
			// 
			this->lblPath->AutoSize = true;
			this->lblPath->Location = System::Drawing::Point(12, 399);
			this->lblPath->Name = L"lblPath";
			this->lblPath->Size = System::Drawing::Size(34, 13);
			this->lblPath->TabIndex = 2;
			this->lblPath->Text = L"Путь:";
			// 
			// lblFillPath
			// 
			this->lblFillPath->AutoSize = true;
			this->lblFillPath->Location = System::Drawing::Point(12, 370);
			this->lblFillPath->Name = L"lblFillPath";
			this->lblFillPath->Size = System::Drawing::Size(249, 13);
			this->lblFillPath->TabIndex = 3;
			this->lblFillPath->Text = L"Укажите расположение исходного видеофайла";
			// 
			// lblResultPath
			// 
			this->lblResultPath->AutoSize = true;
			this->lblResultPath->Enabled = false;
			this->lblResultPath->Location = System::Drawing::Point(12, 481);
			this->lblResultPath->Name = L"lblResultPath";
			this->lblResultPath->Size = System::Drawing::Size(34, 13);
			this->lblResultPath->TabIndex = 7;
			this->lblResultPath->Text = L"Путь:";
			// 
			// txtBoxResultPath
			// 
			this->txtBoxResultPath->Enabled = false;
			this->txtBoxResultPath->Location = System::Drawing::Point(51, 478);
			this->txtBoxResultPath->Name = L"txtBoxResultPath";
			this->txtBoxResultPath->Size = System::Drawing::Size(271, 20);
			this->txtBoxResultPath->TabIndex = 6;
			this->txtBoxResultPath->TextChanged += gcnew System::EventHandler(this, &MyForm::txtBoxResultPath_TextChanged);
			// 
			// lblFillResultPath
			// 
			this->lblFillResultPath->AutoSize = true;
			this->lblFillResultPath->Enabled = false;
			this->lblFillResultPath->Location = System::Drawing::Point(12, 453);
			this->lblFillResultPath->Name = L"lblFillResultPath";
			this->lblFillResultPath->Size = System::Drawing::Size(249, 13);
			this->lblFillResultPath->TabIndex = 8;
			this->lblFillResultPath->Text = L"Укажите расположение исходного видеофайла";
			// 
			// btnGo
			// 
			this->btnGo->Enabled = false;
			this->btnGo->FlatAppearance->BorderColor = System::Drawing::Color::DeepSkyBlue;
			this->btnGo->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnGo->Location = System::Drawing::Point(269, 698);
			this->btnGo->Name = L"btnGo";
			this->btnGo->Size = System::Drawing::Size(83, 23);
			this->btnGo->TabIndex = 9;
			this->btnGo->Text = L"Начать";
			this->btnGo->UseVisualStyleBackColor = true;
			this->btnGo->Click += gcnew System::EventHandler(this, &MyForm::btnGo_Click);
			// 
			// btnSourceExpl
			// 
			this->btnSourceExpl->Location = System::Drawing::Point(328, 394);
			this->btnSourceExpl->Name = L"btnSourceExpl";
			this->btnSourceExpl->Size = System::Drawing::Size(24, 23);
			this->btnSourceExpl->TabIndex = 11;
			this->btnSourceExpl->Text = L"...";
			this->btnSourceExpl->UseVisualStyleBackColor = true;
			this->btnSourceExpl->Click += gcnew System::EventHandler(this, &MyForm::btnSourceExpl_Click);
			// 
			// btnResultExpl
			// 
			this->btnResultExpl->Enabled = false;
			this->btnResultExpl->Location = System::Drawing::Point(328, 476);
			this->btnResultExpl->Name = L"btnResultExpl";
			this->btnResultExpl->Size = System::Drawing::Size(24, 23);
			this->btnResultExpl->TabIndex = 12;
			this->btnResultExpl->Text = L"...";
			this->btnResultExpl->UseVisualStyleBackColor = true;
			this->btnResultExpl->Click += gcnew System::EventHandler(this, &MyForm::btnResultExpl_Click);
			// 
			// chBoxSaveSamePath
			// 
			this->chBoxSaveSamePath->AutoSize = true;
			this->chBoxSaveSamePath->Checked = true;
			this->chBoxSaveSamePath->CheckState = System::Windows::Forms::CheckState::Checked;
			this->chBoxSaveSamePath->Enabled = false;
			this->chBoxSaveSamePath->Location = System::Drawing::Point(15, 422);
			this->chBoxSaveSamePath->Name = L"chBoxSaveSamePath";
			this->chBoxSaveSamePath->Size = System::Drawing::Size(265, 17);
			this->chBoxSaveSamePath->TabIndex = 13;
			this->chBoxSaveSamePath->Text = L"Сохранить обработанное видео в той же папке";
			this->chBoxSaveSamePath->UseVisualStyleBackColor = true;
			this->chBoxSaveSamePath->CheckedChanged += gcnew System::EventHandler(this, &MyForm::chBoxSaveSamePath_CheckedChanged);
			// 
			// gBoxInfo
			// 
			this->gBoxInfo->Controls->Add(this->rBtnNone);
			this->gBoxInfo->Controls->Add(this->rBtnFPS);
			this->gBoxInfo->Controls->Add(this->rBtnFrametime);
			this->gBoxInfo->Location = System::Drawing::Point(12, 560);
			this->gBoxInfo->Name = L"gBoxInfo";
			this->gBoxInfo->Size = System::Drawing::Size(160, 88);
			this->gBoxInfo->TabIndex = 16;
			this->gBoxInfo->TabStop = false;
			this->gBoxInfo->Text = L"Отображение информации";
			// 
			// rBtnNone
			// 
			this->rBtnNone->AutoSize = true;
			this->rBtnNone->Location = System::Drawing::Point(3, 62);
			this->rBtnNone->Name = L"rBtnNone";
			this->rBtnNone->Size = System::Drawing::Size(44, 17);
			this->rBtnNone->TabIndex = 2;
			this->rBtnNone->Text = L"Нет";
			this->rBtnNone->UseVisualStyleBackColor = true;
			// 
			// rBtnFPS
			// 
			this->rBtnFPS->AutoSize = true;
			this->rBtnFPS->Location = System::Drawing::Point(3, 39);
			this->rBtnFPS->Name = L"rBtnFPS";
			this->rBtnFPS->Size = System::Drawing::Size(45, 17);
			this->rBtnFPS->TabIndex = 1;
			this->rBtnFPS->Text = L"FPS";
			this->rBtnFPS->UseVisualStyleBackColor = true;
			// 
			// rBtnFrametime
			// 
			this->rBtnFrametime->AutoSize = true;
			this->rBtnFrametime->Checked = true;
			this->rBtnFrametime->Location = System::Drawing::Point(3, 16);
			this->rBtnFrametime->Name = L"rBtnFrametime";
			this->rBtnFrametime->Size = System::Drawing::Size(73, 17);
			this->rBtnFrametime->TabIndex = 0;
			this->rBtnFrametime->TabStop = true;
			this->rBtnFrametime->Text = L"Frametime";
			this->rBtnFrametime->UseVisualStyleBackColor = true;
			// 
			// lblFilter
			// 
			this->lblFilter->AutoSize = true;
			this->lblFilter->Location = System::Drawing::Point(48, 522);
			this->lblFilter->Name = L"lblFilter";
			this->lblFilter->Size = System::Drawing::Size(90, 13);
			this->lblFilter->TabIndex = 19;
			this->lblFilter->Text = L"Размер фильра:";
			// 
			// lblDelta
			// 
			this->lblDelta->AutoSize = true;
			this->lblDelta->Location = System::Drawing::Point(215, 522);
			this->lblDelta->Name = L"lblDelta";
			this->lblDelta->Size = System::Drawing::Size(48, 13);
			this->lblDelta->TabIndex = 20;
			this->lblDelta->Text = L"Дельта:";
			// 
			// gBoxMethod
			// 
			this->gBoxMethod->Controls->Add(this->rBtnFull);
			this->gBoxMethod->Controls->Add(this->rBtnXY);
			this->gBoxMethod->Location = System::Drawing::Point(178, 560);
			this->gBoxMethod->Name = L"gBoxMethod";
			this->gBoxMethod->Size = System::Drawing::Size(174, 88);
			this->gBoxMethod->TabIndex = 21;
			this->gBoxMethod->TabStop = false;
			this->gBoxMethod->Text = L"Алгоритм";
			// 
			// rBtnFull
			// 
			this->rBtnFull->AutoSize = true;
			this->rBtnFull->Location = System::Drawing::Point(3, 39);
			this->rBtnFull->Name = L"rBtnFull";
			this->rBtnFull->Size = System::Drawing::Size(82, 17);
			this->rBtnFull->TabIndex = 1;
			this->rBtnFull->Text = L"Полностью";
			this->rBtnFull->UseVisualStyleBackColor = true;
			// 
			// rBtnXY
			// 
			this->rBtnXY->AutoSize = true;
			this->rBtnXY->Checked = true;
			this->rBtnXY->Location = System::Drawing::Point(3, 16);
			this->rBtnXY->Name = L"rBtnXY";
			this->rBtnXY->Size = System::Drawing::Size(148, 17);
			this->rBtnXY->TabIndex = 0;
			this->rBtnXY->TabStop = true;
			this->rBtnXY->Text = L"X - Y последовательный";
			this->rBtnXY->UseVisualStyleBackColor = true;
			// 
			// numFilter
			// 
			this->numFilter->Location = System::Drawing::Point(144, 520);
			this->numFilter->Name = L"numFilter";
			this->numFilter->Size = System::Drawing::Size(50, 20);
			this->numFilter->TabIndex = 22;
			this->numFilter->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 11, 0, 0, 0 });
			this->numFilter->ValueChanged += gcnew System::EventHandler(this, &MyForm::numFilter_ValueChanged);
			// 
			// numDelta
			// 
			this->numDelta->Location = System::Drawing::Point(269, 520);
			this->numDelta->Name = L"numDelta";
			this->numDelta->Size = System::Drawing::Size(50, 20);
			this->numDelta->TabIndex = 23;
			this->numDelta->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 20, 0, 0, 0 });
			this->numDelta->ValueChanged += gcnew System::EventHandler(this, &MyForm::numDelta_ValueChanged);
			// 
			// gBoxProc
			// 
			this->gBoxProc->Controls->Add(this->rBtnGPU);
			this->gBoxProc->Controls->Add(this->rBtnCPU);
			this->gBoxProc->Location = System::Drawing::Point(12, 654);
			this->gBoxProc->Name = L"gBoxProc";
			this->gBoxProc->Size = System::Drawing::Size(160, 67);
			this->gBoxProc->TabIndex = 24;
			this->gBoxProc->TabStop = false;
			this->gBoxProc->Text = L"Фильтрация";
			// 
			// rBtnGPU
			// 
			this->rBtnGPU->AutoSize = true;
			this->rBtnGPU->Checked = true;
			this->rBtnGPU->Location = System::Drawing::Point(6, 42);
			this->rBtnGPU->Name = L"rBtnGPU";
			this->rBtnGPU->Size = System::Drawing::Size(48, 17);
			this->rBtnGPU->TabIndex = 1;
			this->rBtnGPU->TabStop = true;
			this->rBtnGPU->Text = L"GPU";
			this->rBtnGPU->UseVisualStyleBackColor = true;
			// 
			// rBtnCPU
			// 
			this->rBtnCPU->AutoSize = true;
			this->rBtnCPU->Location = System::Drawing::Point(6, 19);
			this->rBtnCPU->Name = L"rBtnCPU";
			this->rBtnCPU->Size = System::Drawing::Size(47, 17);
			this->rBtnCPU->TabIndex = 0;
			this->rBtnCPU->Text = L"CPU";
			this->rBtnCPU->UseVisualStyleBackColor = true;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(340, 340);
			this->pictureBox1->TabIndex = 25;
			this->pictureBox1->TabStop = false;
			// 
			// btnOpenSource
			// 
			this->btnOpenSource->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnOpenSource.Image")));
			this->btnOpenSource->Location = System::Drawing::Point(266, 654);
			this->btnOpenSource->Name = L"btnOpenSource";
			this->btnOpenSource->Size = System::Drawing::Size(40, 35);
			this->btnOpenSource->TabIndex = 26;
			this->btnOpenSource->UseVisualStyleBackColor = true;
			this->btnOpenSource->Click += gcnew System::EventHandler(this, &MyForm::btnOpenSource_Click);
			// 
			// btnOpenResult
			// 
			this->btnOpenResult->AllowDrop = true;
			this->btnOpenResult->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnOpenResult.Image")));
			this->btnOpenResult->Location = System::Drawing::Point(312, 654);
			this->btnOpenResult->Name = L"btnOpenResult";
			this->btnOpenResult->Size = System::Drawing::Size(40, 35);
			this->btnOpenResult->TabIndex = 27;
			this->btnOpenResult->UseVisualStyleBackColor = true;
			this->btnOpenResult->Click += gcnew System::EventHandler(this, &MyForm::btnOpenResult_Click);
			// 
			// button1
			// 
			this->button1->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Location = System::Drawing::Point(188, 698);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 28;
			this->button1->Text = L"Стоп";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// lblTime
			// 
			this->lblTime->AutoSize = true;
			this->lblTime->Location = System::Drawing::Point(185, 682);
			this->lblTime->Name = L"lblTime";
			this->lblTime->Size = System::Drawing::Size(13, 13);
			this->lblTime->TabIndex = 29;
			this->lblTime->Text = L"0";
			this->lblTime->Visible = false;
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// lblTimeRem
			// 
			this->lblTimeRem->AutoSize = true;
			this->lblTimeRem->Location = System::Drawing::Point(185, 665);
			this->lblTimeRem->Name = L"lblTimeRem";
			this->lblTimeRem->Size = System::Drawing::Size(59, 13);
			this->lblTimeRem->TabIndex = 30;
			this->lblTimeRem->Text = L"Осталось:";
			this->lblTimeRem->Visible = false;
			// 
			// chBoxConsole
			// 
			this->chBoxConsole->AutoSize = true;
			this->chBoxConsole->Location = System::Drawing::Point(348, 32);
			this->chBoxConsole->Name = L"chBoxConsole";
			this->chBoxConsole->Size = System::Drawing::Size(15, 14);
			this->chBoxConsole->TabIndex = 31;
			this->chBoxConsole->UseVisualStyleBackColor = true;
			this->chBoxConsole->Visible = false;
			// 
			// btnConsole
			// 
			this->btnConsole->Location = System::Drawing::Point(337, 3);
			this->btnConsole->Name = L"btnConsole";
			this->btnConsole->Size = System::Drawing::Size(23, 23);
			this->btnConsole->TabIndex = 32;
			this->btnConsole->Text = L">";
			this->btnConsole->UseVisualStyleBackColor = true;
			this->btnConsole->Click += gcnew System::EventHandler(this, &MyForm::btnConsole_Click);
			// 
			// MyForm
			// 
			this->AllowDrop = true;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(364, 733);
			this->Controls->Add(this->btnConsole);
			this->Controls->Add(this->chBoxConsole);
			this->Controls->Add(this->lblTimeRem);
			this->Controls->Add(this->lblTime);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->btnOpenResult);
			this->Controls->Add(this->btnOpenSource);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->gBoxProc);
			this->Controls->Add(this->numDelta);
			this->Controls->Add(this->numFilter);
			this->Controls->Add(this->gBoxMethod);
			this->Controls->Add(this->lblDelta);
			this->Controls->Add(this->lblFilter);
			this->Controls->Add(this->gBoxInfo);
			this->Controls->Add(this->chBoxSaveSamePath);
			this->Controls->Add(this->btnResultExpl);
			this->Controls->Add(this->btnSourceExpl);
			this->Controls->Add(this->btnGo);
			this->Controls->Add(this->lblFillResultPath);
			this->Controls->Add(this->lblResultPath);
			this->Controls->Add(this->txtBoxResultPath);
			this->Controls->Add(this->lblFillPath);
			this->Controls->Add(this->lblPath);
			this->Controls->Add(this->txtBoxSourcePath);
			this->ForeColor = System::Drawing::SystemColors::ControlText;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"Stabilizer";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->gBoxInfo->ResumeLayout(false);
			this->gBoxInfo->PerformLayout();
			this->gBoxMethod->ResumeLayout(false);
			this->gBoxMethod->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numFilter))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numDelta))->EndInit();
			this->gBoxProc->ResumeLayout(false);
			this->gBoxProc->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	*closeProc = false;
	*stopTimer = false;
	*timeRem = 0;
}

private: System::Void btnSourceExpl_Click(System::Object^ sender, System::EventArgs^ e) {
	OpenFileDialog^ sfd = gcnew OpenFileDialog();
	sfd->Filter = "Video files|*.mp4|All Files|*.*";
	if (sfd->ShowDialog() != System::Windows::Forms::DialogResult::OK)
	{
		return;
	}
	txtBoxSourcePath->Text = sfd->FileName;
	if (chBoxSaveSamePath->Checked == true) {
		auto getDot = txtBoxSourcePath->Text->LastIndexOf(".");
		txtBoxResultPath->Text = txtBoxSourcePath->Text->Insert(getDot, "_Stabilized");
	}

	chBoxSaveSamePath->Enabled = true;
	btnGo->Enabled = true;
}

private: System::Void btnResultExpl_Click(System::Object^ sender, System::EventArgs^ e) {
	FolderBrowserDialog^ fbd = gcnew FolderBrowserDialog();
	if (fbd->ShowDialog() != System::Windows::Forms::DialogResult::OK)
	{
		return;
	}
	txtBoxResultPath->Text = fbd->SelectedPath;
	btnGo->Enabled = true;
}

private: System::Void chBoxSaveSamePath_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	btnResultExpl->Enabled = !btnResultExpl->Enabled;
	txtBoxResultPath->Enabled = !txtBoxResultPath->Enabled;
	lblFillResultPath->Enabled = !lblFillResultPath->Enabled;
	lblResultPath->Enabled = !lblResultPath->Enabled;
	if (chBoxSaveSamePath->Checked == true) {
		auto getDot = txtBoxSourcePath->Text->LastIndexOf(".");
		txtBoxResultPath->Text = txtBoxSourcePath->Text->Insert(getDot, "_Stabilized");
	}
}
private: System::Void txtBoxSourcePath_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	if (txtBoxSourcePath->Text == "") {
		btnGo->Enabled = false;
	}
	else {
		btnGo->Enabled = true;
	}
	if (chBoxSaveSamePath->Checked == true) {
		auto getDot = txtBoxSourcePath->Text->LastIndexOf(".");
		txtBoxResultPath->Text = txtBoxSourcePath->Text->Insert(getDot, "_Stabilized");
	}
}
private: uint8_t getAlg(void) {		//	XY: 0;			Full: 1;
	if (rBtnXY->Checked) {
		return 0;
	}
	else if (rBtnFull->Checked) {
		return 1;
	}
}
private: uint8_t getProc(void) {	//	CPU: 0;			GPU: 1;
	if (rBtnCPU->Checked) {
		return 0;
	}
	else if (rBtnGPU->Checked) {
		return 1;
	}
}
private: uint8_t getInfo(void) {	//	Frametime: 0;	FPS: 1;		None: 2;
	if (rBtnFrametime->Checked) {
		return 0;
	}
	else if (rBtnFPS->Checked) {
		return 1;
	}
	else if (rBtnNone->Checked) {
		return 2;
	}
}
private: System::Void btnGo_Click(System::Object^ sender, System::EventArgs^ e) {/////////////////////////////////////////////////////////////////////////
	string sourcePath = msclr::interop::marshal_as<std::string>(txtBoxSourcePath->Text);
	string resultPath = msclr::interop::marshal_as<std::string>(txtBoxResultPath->Text);
	*timeRem = 0;
	*closeProc = false;
	lblTime->Visible = true;
	timer1->Enabled = true;
	*timeRem = 0;
	*stopTimer = false;
	lblTimeRem->Visible = true;
	stabMain(sourcePath, resultPath, (uint8_t)numFilter->Value, (uint8_t)numDelta->Value, getAlg(), getProc(), getInfo(), closeProc, timeRem, stopTimer);
}
private: System::Void txtBoxResultPath_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	if (txtBoxResultPath->Text == "") {
		btnGo->Enabled = false;
	}
	else {
		btnGo->Enabled = true;
	}
}
private: System::Void numFilter_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	if (numFilter->Value == 0) {
		numFilter->Value = 1;
	}
	if (numFilter->Value > 40) {
		numFilter->Value = 40;
	}
}
private: System::Void numDelta_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	if (numDelta->Value == 0) {
		numDelta->Value = 1;
	}
	if (numDelta->Value > 100) {
		numDelta->Value = 100;
	}
}
private: System::Void btnOpenResult_Click(System::Object^ sender, System::EventArgs^ e) {
	if (txtBoxResultPath->Text != "") {
		auto getSlash = txtBoxResultPath->Text->LastIndexOf("\\");
		string out = msclr::interop::marshal_as<std::string>(txtBoxResultPath->Text->Remove(getSlash));
		ShellExecuteA(NULL, "open", out.c_str(), NULL, NULL, SW_SHOWDEFAULT);
	}
}
private: System::Void btnOpenSource_Click(System::Object^ sender, System::EventArgs^ e) {
	if (txtBoxSourcePath->Text != "") {
		auto getSlash = txtBoxSourcePath->Text->LastIndexOf("\\");
		string out = msclr::interop::marshal_as<std::string>(txtBoxSourcePath->Text->Remove(getSlash));
		ShellExecuteA(NULL, "open", out.c_str(), NULL, NULL, SW_SHOWDEFAULT);
	}
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	*closeProc = true;
}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	lblTime->Text = (*timeRem).ToString();
	if (*stopTimer) {
		*stopTimer = false;
		*timeRem = 0;
		lblTime->Visible = false;
		timer1->Enabled = false;
		lblTimeRem->Visible = false;
	}
}
private: System::Void btnConsole_Click(System::Object^ sender, System::EventArgs^ e) {
	if (!chBoxConsole->Checked) {
		ShowWindow(GetConsoleWindow(), SW_SHOW);
	}
	else {
		ShowWindow(GetConsoleWindow(), SW_HIDE);
	}
	chBoxConsole->Checked = !chBoxConsole->Checked;
}
};
}
