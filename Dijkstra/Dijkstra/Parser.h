#pragma once
#include <vector>
//#include "AppMain.h"
//#include "Processing.h"

using namespace std;

typedef struct normal {
public:	float x;
public:	float y;
public:	float z;
};

typedef struct vertex {
public:	float x;
public:	float y;
public:	float z;
};


typedef struct triangle {
public: normal n;
public: vertex v1;
public:	vertex v2;
public:	vertex v3;
};

ref class Parser
{
public:
	Parser();
	~Parser();
	vector<triangle>* tr;
	vector<triangle> parseSTL(string path);
	void writeResults(vector<vector<vector<int>>>* all_paths, System::String^ curr_point, vector<double> dists);
};

