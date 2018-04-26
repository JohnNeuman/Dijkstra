#include "Processing.h"



int Processing::find_pt(vector<point> pts, vertex v) {
	for (int i = 0; i < pts.size(); i++) {
		if ((pts[i].x == v.x) && (pts[i].y == v.y) && (pts[i].z == v.z)) return i;
	}
	return -1;
}

vector<point> Processing::create_points(vector<triangle> tr){
	vector<point> pts;
	point curr_point;
	int curr_num, v1_num, v2_num, v3_num, vertex_index;
	curr_num = 0;

	for (int i = 0; i < tr.size(); i++) {
		curr_point.attainability.clear();
		vertex_index = find_pt(pts, tr[i].v1);
		if (vertex_index == -1) {
			curr_point.x = tr[i].v1.x;
			curr_point.y = tr[i].v1.y;
			curr_point.z = tr[i].v1.z;

			for (int j = 0; j < pts.size(); j++) {
				curr_point.attainability.push_back(false);
			}

			curr_point.attainability.push_back(true);
			//initialize attainability for previous points
			for (int i = 0; i < pts.size(); i++) {
				for (int k = pts[i].attainability.size(); k < curr_point.attainability.size(); k++){
					pts[i].attainability.push_back(false);
				}
			}

			v1_num = curr_num;
			curr_num++;
			pts.push_back(curr_point);
		}
		else {
			v1_num = vertex_index;
		}

		curr_point.attainability.clear();
		vertex_index = find_pt(pts, tr[i].v2);
		if (vertex_index == -1) {
			curr_point.x = tr[i].v2.x;
			curr_point.y = tr[i].v2.y;
			curr_point.z = tr[i].v2.z;
			for (int j = 0; j < pts.size(); j++) {
				curr_point.attainability.push_back(false);
			}

			curr_point.attainability.push_back(true);
			//initialize attainability for previous points
			for (int i = 0; i < pts.size(); i++) {
				for (int k = pts[i].attainability.size(); k < curr_point.attainability.size(); k++){
					pts[i].attainability.push_back(false);
				}
			}

			v2_num = curr_num;
			curr_num++;
			pts.push_back(curr_point);
		}
		else {
			v2_num = vertex_index;
		}

		curr_point.attainability.clear();
		vertex_index = find_pt(pts, tr[i].v3);
		if (vertex_index == -1) {
			curr_point.x = tr[i].v3.x;
			curr_point.y = tr[i].v3.y;
			curr_point.z = tr[i].v3.z;
			for (int j = 0; j < pts.size(); j++) {
				curr_point.attainability.push_back(false);
			}

			curr_point.attainability.push_back(true);
			//initialize attainability for previous points
			for (int i = 0; i < pts.size(); i++) {
				for (int k = pts[i].attainability.size(); k < curr_point.attainability.size(); k++){
					pts[i].attainability.push_back(false);
				}
			}

			v3_num = curr_num;
			curr_num++;
			pts.push_back(curr_point);
		}
		else {
			v3_num = vertex_index;
		}

		pts[v1_num].attainability[v2_num] = true;
		pts[v1_num].attainability[v3_num] = true;
		pts[v2_num].attainability[v1_num] = true;
		pts[v2_num].attainability[v3_num] = true;
		pts[v3_num].attainability[v1_num] = true;
		pts[v3_num].attainability[v2_num] = true;

	}

	return pts;
}

vector<point> Processing::calculate_distances(vector<point> pts){
	for (int i = 0; i < pts.size(); i++) {
		for (int j = 0; j < pts.size(); j++) {
			pts[i].distance.push_back(-1);
		}
	}
	for (int i = 0; i < pts.size(); i++) {
		for (int j = 0; j < pts.size(); j++) {
			if (pts[i].attainability[j]) {
				pts[i].distance[j] = sqrt((pts[i].x - pts[j].x)*(pts[i].x - pts[j].x) + (pts[i].y - pts[j].y)*(pts[i].y - pts[j].y) + (pts[i].z - pts[j].z)*(pts[i].z - pts[j].z));
				pts[j].distance[i] = pts[i].distance[j];
			}
		}
	}
	return pts;
}

paths_type Processing::Dijkstra(vector<point> pts, int num){
	paths_type paths;
	bool* visit_labels = new bool[pts.size()];
	bool* not_visited_labels = new bool[pts.size()];
	bool dijkstra_end = false;
	bool first_vertex_found;
	int k;
	float* weights = new float[pts.size()];
	int curr_num = num;
	int min_num;
	int prev_curr_num;
	int prev_vertex = -1;
	float min_weight;

	prev_curr_num = -1;
	paths.reserve(pts.size());
	for (int i = 0; i < pts.size(); i++) {
		paths.push_back(path_type());
	}

	for (int i = 0; i < pts.size(); i++) {
		weights[i] = -1;
	}

	for (int i = 0; i < pts.size(); i++) {
		visit_labels[i] = false;
	}
	for (int i = 0; i < pts.size(); i++) {
		not_visited_labels[i] = true;
	}
	visit_labels[num] = true;
	weights[num] = 0;
	//paths[num][0] = num;
	while (!dijkstra_end) {
		visit_labels[curr_num] = true;

		//calc path
		if (curr_num == num) {
			paths[curr_num].push_back(curr_num);
		}

		for (int i = 0; i < pts.size(); i++) {
			if ((pts[curr_num].attainability[i]) && (!visit_labels[i])){
				if (((weights[curr_num] + pts[curr_num].distance[i]) < weights[i]) || (not_visited_labels[i])) {
					not_visited_labels[i] = false;
					weights[i] = weights[curr_num] + pts[curr_num].distance[i];

					paths[i].clear();
					for (int j = 0; j < paths[curr_num].size(); j++) {
						paths[i].push_back(paths[curr_num][j]);
					}
					paths[i].push_back(i);
				}
			}
		}

		//initialize next current vertex
		first_vertex_found = false;
		k = 0;
		min_num = curr_num;
		while ((!first_vertex_found) && (k < pts.size())) {
			if ((curr_num != k) && (pts[curr_num].attainability[k]) && (!visit_labels[k])) {
				min_num = k;
				if ((curr_num != k) && (!visit_labels[k]) && (weights[k] != -1)) {
					min_weight = weights[min_num];
					first_vertex_found = true;
				}
				
			}
			k++;
		}

		//if all neighbour vertexes are visited find another vertex
		if (min_num == curr_num) {

			//init visited vertex with unvisited neighbour vertex
			k = 0;
			first_vertex_found = false;
			while ((!first_vertex_found) && (k < pts.size())) {
				for (int j = 0; j < pts.size(); j++) {
					if ((visit_labels[k]) && (pts[k].attainability[j]) && (j != k) && (!visit_labels[j])) {
						curr_num = k;
					}
				}
				k++;
			}

			//find optimal visited vertex with unvisited neighbour vertex
			for (int i = 0; i < pts.size(); i++) {
				if (visit_labels[i]) {
					for (int j = 0; j < pts.size(); j++) {
						if ((i != j) && (pts[i].attainability[j]) && (!visit_labels[j]) && (weights[i] < weights[curr_num])) {
							curr_num = i;
						}
					}
				}
			}
			//calc ending criteria - all vertexes are visited
			dijkstra_end = true;
			for (int i = 0; i < pts.size(); i++) {
				if (!visit_labels[i]) {
					dijkstra_end = false;
				};
			}
			if (prev_curr_num == curr_num) {
				dijkstra_end = true;
			}
			prev_curr_num = curr_num;
			continue;
		}

		prev_curr_num = curr_num;
		//find next current vertex
		for (int i = 0; i < pts.size(); i++) {
			//if ((curr_num != i) && (pts[curr_num].attainability[i]) && (!visit_labels[i])) {
			if ((curr_num != i) && (!visit_labels[i]) && (weights[i] != -1)) {
				if (min_weight > weights[i]) {
					min_num = i;
					min_weight = weights[min_num];
				}
			}
		}
		prev_vertex = curr_num;
		curr_num = min_num;

		//calc ending criteria - all vertexes are visited
		dijkstra_end = true;
		for (int i = 0; i < pts.size(); i++) {
			if (!visit_labels[i]) {
				dijkstra_end = false;
			};
		}
		//if (prev_curr_num = curr_num) {
		//	dijkstra_end = true;
		//}

	}
	delete[] visit_labels;
	delete[] not_visited_labels;
	delete[] weights;
	paths[num].clear();
	paths[num].push_back(num);
	return paths;
}

all_paths_type Processing::CalculateAllPaths(vector<point> pts) {
	all_paths_type all_paths;
	for (int i = 0; i < pts.size(); i++) {
		all_paths.push_back(Processing::Dijkstra(pts, i));
	}
	return all_paths;
}
