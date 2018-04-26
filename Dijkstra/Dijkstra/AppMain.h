#pragma once
#include "Parser.h"
#include "Processing.h"
#include <vector>

using namespace std;

ref class AppMain
{

public:
	Parser^ parser;
	Processing^ processing;
	AppMain();
};

