#include "AppMain.h"
#include "Parser.h"


AppMain::AppMain()
{
	parser = gcnew Parser();
	parser->tr = new vector<triangle>;
	
	processing = gcnew Processing();
	processing->pts = new vector<point>;
	processing->all_paths = new all_paths_type();
}
