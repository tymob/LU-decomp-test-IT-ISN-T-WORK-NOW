#include "mynumerical.h"


mynumerical::mynumerical()
{
}
int mynumerical::lit(int width, int height, int all)
{
	lit_value = height - 1;
	iwidth = width - 1;
	iheight = height - 1;
	return 0;
}
int  mynumerical::place_one(int w, int h)
{
	w--; h--;
	return w + h*iheight;
}
int  mynumerical::place_one_pc(int w, int h)
{
	return w + h*(iheight+1);
}
void mynumerical::myswap_h(int from, int to,int calc_num)
{
	//from--; to--;
	std::vector <float> temp;
	for (int i = 0; i <= iwidth; i++)
	{
		temp.clear();
		temp.push_back(v.at(place_one_pc(i, to)));
		v.at(place_one_pc(i, to)) = v.at(place_one_pc(i, from));
		v.at(place_one_pc(i, from)) = temp.at(0);

	}
}
void mynumerical::myswap_b(int from, int to)
{
	std::vector <float> temp;
	temp.push_back(place_one(0, to));
	v.at(place_one_pc(0, to)) = v.at(place_one_pc(0, from));
	v.at(place_one_pc(0, from)) = v.at(place_one_pc(0, to));

}
void mynumerical::forward_calc(int remain, int calc_num)
{
	std::vector <float> change_values;

	for (int i = remain + 1; i <= iheight; i++)
	{
		change_values = v;
		int first = remain;
		int second = i;
		//float multiply_value1 = v.at(place_one_pc(calc_num, second));
		float multiply_value2 = v.at(place_one_pc(calc_num, first))/ v.at(place_one_pc(calc_num, second));
		U.at(place_one_pc(calc_num, second)) = multiply_value2;
		for (int k = 0; k <= iwidth; k++)
		{
			change_values.at(place_one_pc(k, first)) = change_values.at(place_one_pc(k, first));
			change_values.at(place_one_pc(k, second)) = change_values.at(place_one_pc(k, second))*multiply_value2;
			change_values.at(place_one_pc(k, second)) = change_values.at(place_one_pc(k, second)) - change_values.at(place_one_pc(k, first));
			v.at(place_one_pc(k, second)) = change_values.at(place_one_pc(k, second));
			
		}

	}
}
void mynumerical::U_ajast(int ajast)
{
	U.reserve(ajast*ajast);
	U.resize(ajast*ajast);
	for (int i = 0; i < ajast; i++)
		U.at(place_one_pc(i, i)) = 1;
}
void mynumerical::U_calc(int size)
{
	
}
mynumerical::~mynumerical()
{
}
