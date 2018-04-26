#include "Parser.h"
#include <vector>
#include <Windows.h>
#include <fstream>
#include <msclr\marshal_cppstd.h>


using namespace System::Windows::Forms;

Parser::Parser()
{
	tr = new vector<triangle>;
}

Parser::~Parser()
{
	delete tr;
}

vector<triangle> Parser::parseSTL(string path) {
	char buff[50];
	vector<triangle> tr;
	int i, j;
	triangle curr_tr;
	string curr_state;
	ifstream file;

	curr_state = "init";

	file.open(path);
	if (file.is_open()) {
		while (!file.eof()) {
			if (curr_state == "init") {
				file >> buff;
				if (strcmp(buff, "solid") == 0) {
					curr_state = "model";
				}
			}
			else if (curr_state == "model") {
				file >> buff;
				if (strcmp(buff, "facet") == 0) {
					curr_state = "facet";
					file >> buff;
				}

			}
			else if ((strcmp(buff, "normal") == 0) && (curr_state == "facet")) {
				curr_state = "normal";
			}
			else if (curr_state == "normal") {
				file >> buff;
				curr_tr.n.x = strtof(buff, NULL);
				file >> buff;
				curr_tr.n.y = strtof(buff, NULL);
				file >> buff;
				curr_tr.n.z = strtof(buff, NULL);
				file >> buff;
				if (strcmp(buff, "outer") == 0) {
					file >> buff;
					if (strcmp(buff, "loop") == 0) {
						file >> buff;
						if (strcmp(buff, "vertex") == 0) {
							curr_state = "vertex1";
						}
					}
				}
			}
			else if (curr_state == "vertex1") {
				file >> buff;
				curr_tr.v1.x = strtof(buff, NULL);
				file >> buff;
				curr_tr.v1.y = strtof(buff, NULL);
				file >> buff;
				curr_tr.v1.z = strtof(buff, NULL);
				file >> buff;
				if (strcmp(buff, "vertex") == 0) {
					curr_state = "vertex2";
				}
			}
			else if (curr_state == "vertex2") {
				file >> buff;
				curr_tr.v2.x = strtof(buff, NULL);
				file >> buff;
				curr_tr.v2.y = strtof(buff, NULL);
				file >> buff;
				curr_tr.v2.z = strtof(buff, NULL);
				file >> buff;
				if (strcmp(buff, "vertex") == 0) {
					curr_state = "vertex3";
				}
			}
			else if (curr_state == "vertex3") {
				file >> buff;
				curr_tr.v3.x = strtof(buff, NULL);
				file >> buff;
				curr_tr.v3.y = strtof(buff, NULL);
				file >> buff;
				curr_tr.v3.z = strtof(buff, NULL);
				file >> buff;
				if (strcmp(buff, "endloop") == 0) {
					curr_state = "endloop";
				}
			}
			else if (curr_state == "endloop") {
				file >> buff;
				if (strcmp(buff, "endfacet") == 0) {
					curr_state = "endfacet";
					tr.push_back(curr_tr);
				}
			}
			else if (curr_state == "endfacet") {
				file >> buff;
				if (strcmp(buff, "facet") == 0) {
					curr_state = "facet";
					file >> buff;
				}
			}

		}

		file.close();
	}
	else {
		System::Windows::Forms::MessageBox::Show("Can't open file.");
	}
	return tr;
}


void Parser::writeResults(vector<vector<vector<int>>>* all_paths, System::String^ curr_point, vector<double> dists) {
	System::IO::Stream^ myStream;
	int k;
	ofstream file;
	std::string out_data;
	SaveFileDialog^ fd = gcnew SaveFileDialog;
	fd->Filter = "txt files (*.txt)|*.txt";
	fd->RestoreDirectory = true;
	int src_pt_index = std::stoi(msclr::interop::marshal_as<std::string>(curr_point));
	if (fd->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		if ((myStream = fd->OpenFile()) != nullptr) {
			myStream->Close();
			file.open(msclr::interop::marshal_as<std::string>(fd->FileName));
			for (int i = 0; i < all_paths->size(); i++) {
				k = i + 1;
				out_data += std::to_string(k);
				out_data += ") ";
				for (int j = 0; j < all_paths->at(src_pt_index - 1).at(i).size(); j++) {
					out_data += std::to_string(all_paths->at(src_pt_index - 1).at(i).at(j) + 1);
					out_data += " ";
				}
				out_data += "d ";
				out_data += std::to_string(dists.at(i));
				out_data += '\n';
			}
		}
		file << out_data;
		file.close();
	}
}
