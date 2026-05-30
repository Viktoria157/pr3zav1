#pragma once
#pragma once

#using <Microsoft.VisualBasic.dll>

using namespace System;
using namespace System::Windows::Forms;
using namespace Microsoft::VisualBasic;

int a[100], n;

public ref class MyForm : public System::Windows::Forms::Form
{
public:
    MyForm(void)
    {
        InitializeComponent();
    }

protected:
    ~MyForm()
    {
        if (components)
        {
            delete components;
        }
    }

private: System::Windows::Forms::Button^ button1;
private: System::Windows::Forms::Button^ button2;
private: System::Windows::Forms::RichTextBox^ richTextBox1;
private: System::Windows::Forms::Label^ label1;
private: System::Windows::Forms::Label^ label2;

private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
       void InitializeComponent(void)
       {
           this->button1 = (gcnew System::Windows::Forms::Button());
           this->button2 = (gcnew System::Windows::Forms::Button());
           this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
           this->label1 = (gcnew System::Windows::Forms::Label());
           this->label2 = (gcnew System::Windows::Forms::Label());
           this->SuspendLayout();
           // 
           // button1
           // 
           this->button1->Location = System::Drawing::Point(309, 104);
           this->button1->Name = L"button1";
           this->button1->Size = System::Drawing::Size(120, 40);
           this->button1->TabIndex = 0;
           this->button1->Text = L"Заповнити масив";
           this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
           // 
           // button2
           // 
           this->button2->Location = System::Drawing::Point(309, 239);
           this->button2->Name = L"button2";
           this->button2->Size = System::Drawing::Size(120, 40);
           this->button2->TabIndex = 1;
           this->button2->Text = L"Обчислити";
           this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
           // 
           // richTextBox1
           // 
           this->richTextBox1->Location = System::Drawing::Point(584, 140);
           this->richTextBox1->Name = L"richTextBox1";
           this->richTextBox1->Size = System::Drawing::Size(100, 200);
           this->richTextBox1->TabIndex = 2;
           this->richTextBox1->Text = L"";
           // 
           // label1
           // 
           this->label1->Location = System::Drawing::Point(387, 381);
           this->label1->Name = L"label1";
           this->label1->Size = System::Drawing::Size(200, 30);
           this->label1->TabIndex = 3;
           this->label1->Text = L"0";
           this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
           // 
           // label2
           // 
           this->label2->AutoSize = true;
           this->label2->Location = System::Drawing::Point(67, 369);
           this->label2->Name = L"label2";
           this->label2->Size = System::Drawing::Size(44, 16);
           this->label2->TabIndex = 4;
           this->label2->Text = L"label2";
           // 
           // MyForm
           // 
           this->ClientSize = System::Drawing::Size(924, 535);
           this->Controls->Add(this->label2);
           this->Controls->Add(this->button1);
           this->Controls->Add(this->button2);
           this->Controls->Add(this->richTextBox1);
           this->Controls->Add(this->label1);
           this->Name = L"MyForm";
           this->Text = L"MyForm";
           this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
           this->ResumeLayout(false);
           this->PerformLayout();

       }
#pragma endregion


       // Заповнення масиву
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    int i;

    richTextBox1->Clear();

    n = Convert::ToInt32(
        Interaction::InputBox(
            "n=", "Введіть розмірність масиву", "", -1, -1));

    for (i = 0; i < n; i++)
    {
        a[i] = Convert::ToInt32(
            Interaction::InputBox(
                "Введення значення " + Convert::ToString(i) + " елемента масиву",
                "Заповнити масив", "", -1, -1));

        richTextBox1->AppendText(Convert::ToString(a[i]) + "\n");
    }
}


       // Обчислення добутку
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
{
    int i;
    int d = 1;

    for (i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
            d *= a[i];
    }

    label1->Text = Convert::ToString(d);
}

private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
};