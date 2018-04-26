#pragma once
#include "AppMain.h"
#include <string>
#include <iostream>
#include <fstream>
#include <msclr\marshal_cppstd.h>

using namespace std;

namespace Dijkstra {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Dijkstra;
	using namespace System::Runtime::InteropServices;
	using namespace std;

	/// <summary>
	/// Summary for MainWindow
	/// </summary>
	public ref class MainWindow : public System::Windows::Forms::Form
	{
	public:
		AppMain^ Main;
		
		MainWindow(void)
		{
			InitializeComponent();
			MainWindow::Main = gcnew AppMain();
			this->SourcePoint->Text = "1";
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainWindow()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  OpenFile;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  menuToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  N;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Point;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  X;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Y;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Z;
	private: System::Windows::Forms::ToolStripMenuItem^  calculatePathsToolStripMenuItem;
	private: System::Windows::Forms::DataGridView^  dataGridResults;
	private: System::Windows::Forms::TextBox^  SourcePoint;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ToolStripMenuItem^  saveToolStripMenuItem;
	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
	

		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->OpenFile = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->menuToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->calculatePathsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->N = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Point = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->X = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Y = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Z = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->dataGridResults = (gcnew System::Windows::Forms::DataGridView());
			this->SourcePoint = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->contextMenuStrip1->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridResults))->BeginInit();
			this->SuspendLayout();
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->OpenFile });
			this->contextMenuStrip1->LayoutStyle = System::Windows::Forms::ToolStripLayoutStyle::HorizontalStackWithOverflow;
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(123, 26);
			// 
			// OpenFile
			// 
			this->OpenFile->Name = L"OpenFile";
			this->OpenFile->Size = System::Drawing::Size(122, 22);
			this->OpenFile->Text = L"Open file";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->menuToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(692, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// menuToolStripMenuItem
			// 
			this->menuToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->fileToolStripMenuItem,
					this->calculatePathsToolStripMenuItem, this->saveToolStripMenuItem
			});
			this->menuToolStripMenuItem->Name = L"menuToolStripMenuItem";
			this->menuToolStripMenuItem->Size = System::Drawing::Size(50, 20);
			this->menuToolStripMenuItem->Text = L"Menu";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(155, 22);
			this->fileToolStripMenuItem->Text = L"File";
			this->fileToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::fileToolStripMenuItem_Click);
			// 
			// calculatePathsToolStripMenuItem
			// 
			this->calculatePathsToolStripMenuItem->Name = L"calculatePathsToolStripMenuItem";
			this->calculatePathsToolStripMenuItem->Size = System::Drawing::Size(155, 22);
			this->calculatePathsToolStripMenuItem->Text = L"Calculate paths";
			this->calculatePathsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::calculatePathsToolStripMenuItem_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// tabControl1
			// 
			this->tabControl1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Location = System::Drawing::Point(0, 28);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(692, 403);
			this->tabControl1->TabIndex = 2;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->dataGridView1);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(684, 377);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Input data";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// dataGridView1
			// 
			this->dataGridView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->N, this->Point,
					this->X, this->Y, this->Z
			});
			this->dataGridView1->Location = System::Drawing::Point(3, 3);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(678, 368);
			this->dataGridView1->TabIndex = 0;
			// 
			// N
			// 
			this->N->HeaderText = L"N";
			this->N->Name = L"N";
			// 
			// Point
			// 
			this->Point->HeaderText = L"Point";
			this->Point->Name = L"Point";
			// 
			// X
			// 
			this->X->HeaderText = L"X";
			this->X->Name = L"X";
			// 
			// Y
			// 
			this->Y->HeaderText = L"Y";
			this->Y->Name = L"Y";
			// 
			// Z
			// 
			this->Z->HeaderText = L"Z";
			this->Z->Name = L"Z";
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->dataGridResults);
			this->tabPage2->Controls->Add(this->SourcePoint);
			this->tabPage2->Controls->Add(this->label1);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(684, 377);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Paths";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// dataGridResults
			// 
			this->dataGridResults->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridResults->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridResults->Location = System::Drawing::Point(0, 33);
			this->dataGridResults->Name = L"dataGridResults";
			this->dataGridResults->Size = System::Drawing::Size(676, 332);
			this->dataGridResults->TabIndex = 2;
			// 
			// SourcePoint
			// 
			this->SourcePoint->Location = System::Drawing::Point(81, 7);
			this->SourcePoint->Name = L"SourcePoint";
			this->SourcePoint->Size = System::Drawing::Size(100, 20);
			this->SourcePoint->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(7, 7);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(67, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Source point";
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(155, 22);
			this->saveToolStripMenuItem->Text = L"Save";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::saveToolStripMenuItem_Click);
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(692, 427);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MainWindow";
			this->Text = L"MainWindow";
			this->contextMenuStrip1->ResumeLayout(false);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridResults))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		*Main->parser->tr = Main->parser->parseSTL("box.stl");
	}
	
private: System::Void fileToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		string path;
		int s;
		if ((openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) || 
			(openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::Yes)){
			SourcePoint->Text = "1";
			for (int i = 0; i < openFileDialog1->FileName->Length; i++) {
				path += (char)openFileDialog1->FileName[i];
			}
			*Main->parser->tr = Main->parser->parseSTL(path); 
		}
		
		s = Main->parser->tr->size();
		for (int i = 0; i < s; i++) {
			dataGridView1->Rows->Add(i+1,"normal",Main->parser->tr->at(i).n.x, Main->parser->tr->at(i).n.y, Main->parser->tr->at(i).n.z);
			dataGridView1->Rows->Add("", "vertex", Main->parser->tr->at(i).v1.x, Main->parser->tr->at(i).v1.y, Main->parser->tr->at(i).v1.z);
			dataGridView1->Rows->Add("", "vertex", Main->parser->tr->at(i).v2.x, Main->parser->tr->at(i).v2.y, Main->parser->tr->at(i).v2.z);
			dataGridView1->Rows->Add("", "vertex", Main->parser->tr->at(i).v3.x, Main->parser->tr->at(i).v3.y, Main->parser->tr->at(i).v3.z);
		}

}
private: System::Void calculatePathsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		int src_pt_index;
		try {
			src_pt_index = std::stoi(msclr::interop::marshal_as<std::string>(SourcePoint->Text));
		}
		catch (std::exception) {
			System::Windows::Forms::MessageBox::Show("Invalid source point.");
			return;
		}
		
		vector<string> path;
		double dist;
		int k;
		if (Main->parser->tr->size() == 0) return;

		*Main->processing->pts = Main->processing->create_points(*Main->parser->tr);
		*Main->processing->pts = Main->processing->calculate_distances(*Main->processing->pts);
		*Main->processing->all_paths = Main->processing->CalculateAllPaths(*Main->processing->pts);
		dataGridResults->Rows->Clear();
		dataGridResults->ColumnCount = Main->processing->pts->size() + 1;
		dataGridResults->ColumnHeadersVisible = true;
		for (int i = 0; i < Main->processing->pts->size(); i++) {
			dataGridResults->Columns[i]->Name = gcnew String(std::to_string(i + 1).c_str());
			dataGridResults->Columns[i]->HeaderText = gcnew String(std::to_string(i + 1).c_str());
		}
		dataGridResults->Columns[Main->processing->pts->size()]->Name = "Distance";
		dataGridResults->Columns[Main->processing->pts->size()]->HeaderText = "Distance";
		all_paths_type all_paths = *Main->processing->all_paths;
		if (!((src_pt_index >= 1) && (src_pt_index <= all_paths.size()))) return;
		if (SourcePoint->Text != "") {
			for (int i = 0; i < all_paths.at(src_pt_index - 1).size(); i++) {
				path.clear();
				for (int j = 0; j < all_paths.at(src_pt_index - 1).size(); j++) {
					path.push_back("");
				}
				k = 1;
				
				for (int j = 0; j < all_paths.at(src_pt_index - 1).at(i).size(); j++) {
					path[all_paths.at(src_pt_index - 1).at(i).at(j)] = std::to_string(k);
					k++;
				}
				array<String^>^ arr = gcnew array<String^>(all_paths.at(src_pt_index - 1).size() + 1);				
				for (int j = 0; j < all_paths.at(src_pt_index - 1).size(); j++) {
					arr[j] = gcnew String(path.at(j).c_str());
				}
				dist = 0;
				for (int j = 1; j < all_paths.at(src_pt_index - 1).at(i).size(); j++){
					dist += Main->processing->pts->at(all_paths.at(src_pt_index - 1).at(i).at(j - 1)).distance[all_paths.at(src_pt_index - 1).at(i).at(j)];
				}
				arr[all_paths.at(src_pt_index - 1).size()] = gcnew String(std::to_string(dist).c_str());
				dataGridResults->Rows->Add(arr);
			}
		}
}

		private: System::Void saveToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			vector<double> dists;
			double dist;
			if (Main->processing->all_paths->size() == 0) return;
			int src_pt_index = std::stoi(msclr::interop::marshal_as<std::string>(SourcePoint->Text));
			all_paths_type all_paths = *Main->processing->all_paths;
			for (int i = 0; i < all_paths.at(src_pt_index - 1).size(); i++) {
				dist = 0;
				for (int j = 1; j < all_paths.at(src_pt_index - 1).at(i).size(); j++) {
					dist += Main->processing->pts->at(all_paths.at(src_pt_index - 1).at(i).at(j - 1)).distance[all_paths.at(src_pt_index - 1).at(i).at(j)];
				}
				dists.push_back(dist);
			}
			Main->parser->writeResults(Main->processing->all_paths, SourcePoint->Text, dists);
		}
};
}
