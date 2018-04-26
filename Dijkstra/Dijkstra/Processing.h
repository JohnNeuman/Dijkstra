#pragma once
#include "Parser.h"
#include <vector>

using namespace std;

typedef	vector<int> path_type;
typedef vector<path_type> paths_type;
typedef vector<paths_type> all_paths_type;

typedef struct point {
	float x;
	float y;
	float z;
	vector<bool> attainability;
	vector<float> distance;
};


ref class Processing
{
public:
	vector<point>* pts;
	all_paths_type* all_paths;
	vector<point> create_points(vector<triangle> tr);
	int find_pt(vector<point> pts, vertex v);
	vector<point> calculate_distances(vector<point> pts);
	static paths_type Dijkstra(vector<point> pts, int num);
	all_paths_type Processing::CalculateAllPaths(vector<point> pts);
};
