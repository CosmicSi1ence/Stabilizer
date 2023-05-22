#pragma once

namespace StabCLR {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для FormExplorer
	/// </summary>
	public ref class FormExplorer : public System::Windows::Forms::Form
	{
	public:
		FormExplorer(void)
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
		~FormExplorer()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnBack;
	private: System::Windows::Forms::Button^ btnForward;
	private: System::Windows::Forms::TextBox^ txtBoxPath;
	private: System::Windows::Forms::WebBrowser^ browser;
	private: System::Windows::Forms::Button^ btnGoConfirm;
	protected:




	private: System::Windows::Forms::Button^ btnGoBack;

	protected:


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnBack = (gcnew System::Windows::Forms::Button());
			this->btnForward = (gcnew System::Windows::Forms::Button());
			this->txtBoxPath = (gcnew System::Windows::Forms::TextBox());
			this->browser = (gcnew System::Windows::Forms::WebBrowser());
			this->btnGoConfirm = (gcnew System::Windows::Forms::Button());
			this->btnGoBack = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnBack
			// 
			this->btnBack->Enabled = false;
			this->btnBack->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnBack->Location = System::Drawing::Point(12, 12);
			this->btnBack->Name = L"btnBack";
			this->btnBack->Size = System::Drawing::Size(25, 25);
			this->btnBack->TabIndex = 2;
			this->btnBack->Text = L"<";
			this->btnBack->UseVisualStyleBackColor = true;
			// 
			// btnForward
			// 
			this->btnForward->Enabled = false;
			this->btnForward->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnForward->Location = System::Drawing::Point(43, 12);
			this->btnForward->Name = L"btnForward";
			this->btnForward->Size = System::Drawing::Size(25, 25);
			this->btnForward->TabIndex = 3;
			this->btnForward->Text = L">";
			this->btnForward->UseVisualStyleBackColor = true;
			// 
			// txtBoxPath
			// 
			this->txtBoxPath->Location = System::Drawing::Point(75, 16);
			this->txtBoxPath->Name = L"txtBoxPath";
			this->txtBoxPath->ReadOnly = true;
			this->txtBoxPath->Size = System::Drawing::Size(697, 20);
			this->txtBoxPath->TabIndex = 4;
			// 
			// browser
			// 
			this->browser->Location = System::Drawing::Point(12, 58);
			this->browser->MinimumSize = System::Drawing::Size(20, 20);
			this->browser->Name = L"browser";
			this->browser->Size = System::Drawing::Size(760, 452);
			this->browser->TabIndex = 5;
			// 
			// btnGoConfirm
			// 
			this->btnGoConfirm->Enabled = false;
			this->btnGoConfirm->Location = System::Drawing::Point(697, 527);
			this->btnGoConfirm->Name = L"btnGoConfirm";
			this->btnGoConfirm->Size = System::Drawing::Size(75, 23);
			this->btnGoConfirm->TabIndex = 6;
			this->btnGoConfirm->Text = L"Открыть";
			this->btnGoConfirm->UseVisualStyleBackColor = true;
			this->btnGoConfirm->Click += gcnew System::EventHandler(this, &FormExplorer::btnGoConfirm_Click);
			// 
			// btnGoBack
			// 
			this->btnGoBack->Location = System::Drawing::Point(616, 527);
			this->btnGoBack->Name = L"btnGoBack";
			this->btnGoBack->Size = System::Drawing::Size(75, 23);
			this->btnGoBack->TabIndex = 7;
			this->btnGoBack->Text = L"Назад";
			this->btnGoBack->UseVisualStyleBackColor = true;
			this->btnGoBack->Click += gcnew System::EventHandler(this, &FormExplorer::btnGoBack_Click);
			// 
			// FormExplorer
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 562);
			this->Controls->Add(this->btnGoBack);
			this->Controls->Add(this->btnGoConfirm);
			this->Controls->Add(this->browser);
			this->Controls->Add(this->txtBoxPath);
			this->Controls->Add(this->btnForward);
			this->Controls->Add(this->btnBack);
			this->Name = L"FormExplorer";
			this->Text = L"Укажите путь к файлу";
			this->Load += gcnew System::EventHandler(this, &FormExplorer::FormExplorer_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnGoBack_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void btnGoConfirm_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void FormExplorer_Load(System::Object^ sender, System::EventArgs^ e) {
	OpenFileDialog^ sfd = gcnew OpenFileDialog();
	sfd->Filter = "Text Files|*.txt|All Files|*.*";
	if (sfd->ShowDialog() != System::Windows::Forms::DialogResult::OK)
	{
		return;
	}
	//MessageBox::Show( sfd->FileName );
	MessageBox::Show("OK");
}
};
}
