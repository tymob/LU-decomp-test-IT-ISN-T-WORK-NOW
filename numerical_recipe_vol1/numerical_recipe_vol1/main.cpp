#include <iostream>
#include <vector>
#include "mynumerical.h"
#include "glm\glm.hpp"
#include <algorithm>


int main()
{



	mynumerical my;
	//-----------------input area------------------------------//
	my.lit(3,3, 6);
	/*my.v.push_back(1); my.v.push_back(2); my.v.push_back(1);
	my.v.push_back(1); my.v.push_back(1); my.v.push_back(3); 
	my.v.push_back(2); my.v.push_back(2); my.v.push_back(1);
	my.b.push_back(6);	my.b.push_back(6);	my.b.push_back(5);
	my.U_ajast(3);*/
	
		my.v.push_back(1); my.v.push_back(1); my.v.push_back(1);
	my.v.push_back(2); my.v.push_back(3); my.v.push_back(-2);
	my.v.push_back(3); my.v.push_back(-1); my.v.push_back(1);
	my.b.push_back(9);	my.b.push_back(5);	my.b.push_back(7);
	my.U_ajast(3);

	
	/*my.v.push_back(2); my.v.push_back(1); my.v.push_back(2);
	my.v.push_back(1); my.v.push_back(1); my.v.push_back(-1);
	my.v.push_back(1); my.v.push_back(-2); my.v.push_back(3);
	my.b.push_back(1);	my.b.push_back(4);	my.b.push_back(-1);
	my.U_ajast(3);*/
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
		p.pivot = glm::vec2(calc_num , calc_num);
		for (int i = calc_num; i <= my.iheight; i++)pivot_s.push_back(fabs(my.v.at(my.place_one_pc(calc_num, i))));//比較リスト
	std::sort(pivot_s.begin(), pivot_s.end());//sort
	int point_cc=0;
	for (int i = 0; i < pivot_s.size(); i++)//endを拾ってくる<-ソートにキーをつけるのがめんどくさかった。＆値だぶってもいいので気にしない。
	{
		if (pivot_s.back() == my.v.at(i))
		{
			while (calc_num >= my.iheight){ calc_num = calc_num / my.iheight; point_cc++; }
			fromto = glm::vec2(calc_num, point_cc);
			break;
		}
	}
	
	//my.myswap_h(fromto.x, fromto.y,calc_num);
	//my.myswap_b(fromto.x, fromto.y);

	my.forward_calc(calc_num, calc_num);

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
	for (int check_zero_i = 0; check_zero_i < check_zero.size()-1; check_zero_i++)
	{
		if (check_zero_i == check_zero.at(check_zero_i)){ if (check_zero_i == my.iwidth){ calc_num = my.iwidth + 1; goto skip; } }
		else { break; }
	}



	}

	/*------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------*/
	skip:std::cout << "前進代入" << std::endl;
	std::cout << my.U.at(0) << std::endl;
	//-----------------input area------------------------------//
	std::vector <float> forward=my.U;
	std::vector <float> f_b = my.b;
	std::vector <float> ans_l;
	std::vector <float> ans_temp;
	std::vector <float>::iterator it;
	float temp;
	std::vector <float> back = my.v;
	std::vector <float> b_b = my.b;

	calc_num = forward.size()/my.iwidth - 2;



	std::vector <int> check_zero2;
	for (int i = 0; i <= calc_num; i++)
	{
		temp = f_b.at(my.place_one_pc(i, 0)) / (forward.at(my.place_one_pc(i, i)));//先頭/b
		ans_l.push_back(temp);
		for (int j =i+1 ; j <= calc_num; j++)
		{
			forward.at(my.place_one_pc(i, j)) = forward.at(my.place_one_pc(i, j))*temp;//
			f_b.at(my.place_one_pc(j, 0)) = f_b.at(my.place_one_pc(j, 0)) - forward.at(my.place_one_pc(i, j));
		}
	
	}

	/*------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------*/
	calc_num = forward.size() / my.iwidth - 2;
	ans_temp = ans_l;
	for (int i = calc_num; i >= 0; i--)
	{
		temp = ans_temp.at(i) / (back.at(my.place_one_pc(i, i)));
		
		ans_l.insert(ans_l.begin(),temp);
				for (int j = calc_num-1; j >= 0; j--)
				{
					back.at(my.place_one_pc(i, j)) = back.at(my.place_one_pc(i, j))*temp;
					ans_temp.at(j) = ans_l.at(j) - back.at(my.place_one_pc(i, j));
				}
			
	}
	std::cout << "y1:" << ans_l.at(3) << "y2:" << ans_l.at(4) << "y3:" << ans_l.at(5) << "x1:" << ans_l.at(2) << "x2:" << ans_l.at(1) << "x3:" << ans_l.at(0) << std::endl;

}