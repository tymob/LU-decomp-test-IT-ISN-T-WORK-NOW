#include <iostream>
#include <vector>
#include "mynumerical.h"
#include "glm\glm.hpp"
#include <algorithm>


int main()
{



	mynumerical my;
	//-----------------input area------------------------------//
	my.lit(3, 3, 6);
	my.v.push_back(1); my.v.push_back(2); my.v.push_back(1); my.v.push_back(1); my.v.push_back(1); my.v.push_back(3); my.v.push_back(2); my.v.push_back(2); my.v.push_back(1);
	my.b.push_back(6);	my.b.push_back(6);	my.b.push_back(5);
	my.U_ajast(3);
	//pivot
	struct pivota
	{
		glm::vec2 pivot = glm::vec2 (0, 0);
		int pivot_num = 0;
	};
	pivota p;
	int calc_num=0;
	std::vector <float> pivot_s;
	glm::vec2 fromto;
	bool check_ans;
	for (calc_num = 0; calc_num <= my.iwidth; calc_num++)
	{
		check_ans = false;
		for (int check = calc_num; check >= 0; check--)
		{
			if (my.v.at(my.place_one_pc(check_ans,calc_num)) == 0)check_ans = true;
			else { check_ans = false; break; }
		}
		if (check_ans == true)
		{
			my.myswap_h(calc_num, my.v.size()-1, calc_num);
			my.myswap_b(calc_num, my.v.size() - 1);
		}
		p.pivot = glm::vec2(calc_num , calc_num);
		for (int i = calc_num; i <= my.iheight; i++)pivot_s.push_back(fabs(my.v.at(my.place_one_pc(calc_num, i))));//比較リスト
	std::sort(pivot_s.begin(), pivot_s.end());//sort
	for (int i = 0; i < pivot_s.size(); i++)//endを拾ってくる<-ソートにキーをつけるのがめんどくさかった。＆値だぶってもいいので気にしない。
	{
		if (pivot_s.back() == my.v.at(my.place_one_pc(calc_num,i)))
		{
			fromto = glm::vec2(calc_num,i);
			break;
		}
	}
	
	my.myswap_h(fromto.x, fromto.y,calc_num);
	my.myswap_b(calc_num, p.pivot.y);

	my.forward_calc(calc_num, 0);

	std::cout << "i" << std::endl;
	//pivot
	p.pivot_num++;
	std::vector <int> check_zero;
	check_zero.reserve(my.iwidth+1);
	check_zero.resize(my.iwidth+1);
	for (int k = 0; k <my.iheight + 1; k++)
		{
			for (int check = 0; check <= my.iwidth; check++)
			{
				if (my.v.at(my.place_one_pc(check, k)) == 0)check_zero.at(k)++;
				if (check == my.iwidth && k > 0)
				{
					my.myswap_h(check_zero.at(k), k, calc_num);
					my.myswap_b(check_zero.at(k), k);

				}
			}
		}
	my.before_z.clear();
	my.before_z = check_zero; //後で使う
	std::sort(check_zero.begin(), check_zero.end());
	check_zero.erase(std::unique(check_zero.begin(), check_zero.end()), check_zero.end());
	for (int check_zero_i = 0; check_zero_i < check_zero.size(); check_zero_i++)
	{
		if (check_zero_i == check_zero.at(check_zero_i)){ if (check_zero_i > check_zero.size() - 1) calc_num = my.iwidth + 1; goto skip; }
		else { break; }
	}



	}

	skip:std::cout << "後退代入" << std::endl;
	std::cout << my.U.at(0) << std::endl;
	//-----------------input area------------------------------//
	std::vector <float> back;
	std::vector <float> ans_l;
	float temp;
	back = my.v;

	calc_num = back.size()/my.iwidth - 2;

	for (int i = calc_num; i >= 0; i--)
	{
		temp = (back.at(my.place_one_pc(i, i))) / my.b.at(my.place_one_pc(i, 0));
		ans_l.push_back(temp);
				for (int j = calc_num-1; j >= 0; j--)
				{
					back.at(my.place_one_pc(i, j)) = back.at(my.place_one_pc(i, j))*temp;
					back.at(my.b.at(my.place_one_pc(j, 0)) =my.b.at(my.place_one_pc(j, 0)))- back.at(my.place_one_pc(i, j));
				}
			
	}

}