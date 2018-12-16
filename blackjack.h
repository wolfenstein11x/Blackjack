#pragma once
#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <random>
#include <chrono>
#include <map>
#include <regex>

struct Blackjack
{
	std::vector<std::string> cards = { "A","2","3","4","5","6","7","8","9","10","J","Q","K" };
	bool tie = false;
	double player_money = 20.00;
	double player_bet;
	double pot = 0;
	double *pot_ptr = &pot;
	std::vector<std::string> player_hand;
	std::vector<std::string> dealer_hand;
	int player_score;
	int dealer_score;
	void shuffle_cards(std::vector<std::string> &vec);
	void deal_hand(int x);
	bool hit_or_stay();
	void deal_card(int x);
	void display_hand(std::vector<std::string> &vec, int x);
	void display_money();
	void show_1(std::vector<std::string> &vec);
	void check_hand(std::vector<std::string> &vec, int &score);
	void check_aces(std::vector<std::string> &vec, int &score);
	void display_score(int &score);
	void check_who_wins(int pscore, int dscore, double &money, double &bet);
	void clear_screen();
	void clear_hands(std::vector<std::string> &vec1, std::vector<std::string> &vec2);
	void place_bets(double &, double &);
	
	

};
