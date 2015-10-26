#pragma once
#include <iostream>
#include <vector>
class mynumerical
{
public:
	mynumerical();
	~mynumerical();
	std::vector <float> v;
	std::vector <float> b;
	//width:ïù
	//height:çÇÇ≥
	//all:ëSïîÇ≈âΩóvëfÇ©ÅB
	int lit(int width, int height, int all);
	int  place_one(int w, int h);
	int  place_one_pc(int w, int h);
	void myswap_h(int from, int to, int calc_num);
	void myswap_b(int from, int to);
	void forward_calc (int remain, int calc_num);
	void U_calc(int size);
	std::vector <float> record;
	int lit_value = 0;
	int iwidth = 0;
	int iheight = 0;
	std::vector <float> U;
	void U_ajast(int ajast);
	std::vector <int> before_z;
	void calcT1(int height, int width);
	
};

