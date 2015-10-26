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

	float temp=b.at(place_one_pc(to, 0));
	b.at(place_one_pc(to, 0)) = b.at(place_one_pc(from,0 ));
	b.at(place_one_pc(from, 0)) = temp;

}
void mynumerical::forward_calc(int remain, int calc_num)
{
	std::vector <float> change_values;

	change_values = v;
	int first = remain;



	for (int i = remain + 1; i <= iheight; i++)
	{
		change_values = v;
		first = remain;
		int second = i;
		//float multiply_value1 = v.at(place_one_pc(calc_num, second));

		float multiply_value2 = v.at(place_one_pc(calc_num, first))/ v.at(place_one_pc(calc_num, second));
		b.at(place_one_pc(second, 0)) = b.at(place_one_pc(second, 0))*multiply_value2 - b.at(place_one_pc(first, 0));
		U.at(place_one_pc(calc_num, second)) = multiply_value2;
		for (int k = 0; k <= iwidth; k++)
		{
			change_values.at(place_one_pc(k, first)) = change_values.at(place_one_pc(k, first));
			change_values.at(place_one_pc(k, second)) = change_values.at(place_one_pc(k, second))*multiply_value2;
			change_values.at(place_one_pc(k, second)) = change_values.at(place_one_pc(k, second)) - change_values.at(place_one_pc(k, first));
			v.at(place_one_pc(k, second)) = change_values.at(place_one_pc(k, second));
			
		}
	
	}
	calcT1(first, calc_num);

}
void mynumerical::U_ajast(int ajast)
{
	U.reserve(ajast*ajast);
	U.resize(ajast*ajast);
	for (int i = 0; i < ajast; i++)
		U.at(place_one_pc(i, i)) = 1;
}
void mynumerical::calcT1(int height,int width)
{
	float To1value = v.at(place_one_pc(width,height));
	std::vector <float> values;
	values.push_back(b.at(place_one_pc(height, 0)));
	for (int i = 0; i <= iwidth; i++)
	{
		values.push_back(v.at(place_one_pc(i, height)));
	}
	for (int i = 0; i < values.size(); i++)
	{
		values.at(i) = values.at(i) / To1value;
	}
	b.at(place_one_pc(height, 0)) = values.at(0);
	for (int i = 0; i <= iwidth; i++)
	{
		v.at(place_one_pc(i, height)) = values.at(i + 1);
	}

}
void mynumerical::U_calc(int size)
{
	
}
mynumerical::~mynumerical()
{
}
