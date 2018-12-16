#include "stdafx.h"
#include "blackjack.h"

void Blackjack::shuffle_cards(std::vector<std::string> &vec)
{
	unsigned ms = std::chrono::system_clock::now().time_since_epoch().count();
	shuffle(vec.begin(), vec.end(), std::default_random_engine(ms));
}

void Blackjack::deal_hand(int x)
{
	shuffle_cards(cards);

	if (x == 1)
	{
		player_hand.push_back(cards[0]);
		player_hand.push_back(cards[1]);
	}
	else if (x == 2)
	{
		dealer_hand.push_back(cards[0]);
		dealer_hand.push_back(cards[1]);
	}

}

bool Blackjack::hit_or_stay()
{
	std::regex valid_input("[12]{1}");

	int answer = 1;

	while (true)
	{
		std::string input_str = "0";
		std::cout << "[1] Hit me!\n";
		std::cout << "[2] I'll stay.\n";
		std::cin >> input_str;
		if (regex_match(input_str, valid_input) == false)
		{
			std::cout << "\nInvalid input.\n";
		}
		else
		{
			answer = stoi(input_str);
			break;
		}
	}
	
	if (answer == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Blackjack::deal_card(int x)
{
	shuffle_cards(cards);

	if (x == 1)
	{
		player_hand.push_back(cards[0]);
	}
	else if (x == 2)
	{
		dealer_hand.push_back(cards[0]);
	}
}

void Blackjack::display_hand(std::vector<std::string> &vec, int x)
{
	std::cout << "\n\n";
	if (x == 1)
	{
		std::cout << "You:\t";
	}
	else if (x == 2)
	{
		std::cout << "Dealer:\t";
	}
	for (auto elem : vec)
	{
		std::cout << elem << " ";
	}
}

void Blackjack::display_money()
{
	std::cout << std::fixed;
	std::cout << "\n\nYour money: $" << std::setprecision(2) << player_money << "\n";
}

void Blackjack::show_1(std::vector<std::string> &vec)
{
	std::cout << "\n\n";
	std::cout << "Dealer:\t";
	std::cout << vec[0] << " X\n";
}

void Blackjack::check_hand(std::vector<std::string> &vec, int &score)
{
	score = 0;

	std::regex face_card("[AJQK]{1}");

	std::map<std::string, int> card_values;
	card_values["A"] = 11;
	card_values["J"] = 10;
	card_values["Q"] = 10;
	card_values["K"] = 10;

	for (auto elem : vec)
	{
		if (regex_match(elem, face_card))
		{
			score += card_values[elem];
		}
		else
		{
			score += std::stoi(elem);
		}
	}
}

void Blackjack::check_aces(std::vector<std::string> &vec, int &score)
{
	int num_aces;
	int *num_aces_ptr = &num_aces;
	*num_aces_ptr = 0;

	for (auto elem : vec)
	{
		if (elem == "A")
		{
			*num_aces_ptr += 1;
		}
	}

	for (int i = 0; i < num_aces; i++)
	{
		if (score > 21)
		{
			score -= 10;
		}
		else 
		{
			return;
		}
	}
}

void Blackjack::display_score(int &score)
{
	if (score > 21)
	{
		std::cout << "\n\nYou bust! Dealer wins no matter what!\n";
	}

	else
	{
		std::cout << "\n\nPlayer shows " << score << "\n";
	}
}

void Blackjack::check_who_wins(int pscore, int dscore, double &money, double &bet)
{
	if (pscore > 21)
	{
		*pot_ptr = 0;
		return;
	}
	else if (dscore > 21)
	{
		money += *pot_ptr;
		std::cout << "Dealer busts. You win\n";
		*pot_ptr = 0;
	}
	else if (pscore > dscore)
	{
		money += *pot_ptr;
		std::cout << "You win\n";
		*pot_ptr = 0;
	}
	else if (dscore > pscore)
	{
		std::cout << "Dealer wins\n";
		*pot_ptr = 0;
	}
	else
	{
		tie = true;
		std::cout << "It's a tie. Money in the pot carries over to next hand.\n";
		std::cout << "Money in the pot: " << pot << "\n";
		//Pot is not set to zero in this case. It remains what it was
	}
}

void Blackjack::clear_screen()
{
	std::cout << std::string(20, '\n');
}

void Blackjack::clear_hands(std::vector<std::string> &vec1, std::vector<std::string> &vec2)
{
	vec1.clear();
	vec2.clear();
}

void Blackjack::place_bets(double &money, double &bet)
{
	std::regex valid_bet("[1-5]{1}");

	int input = 1;
	
	while (true)
	{
		std::string input_str = "";
		std::cout << "Place your bets: \n[1]: $0.50\n[2]: $1.00\n[3]: $2.50\n[4]: $5:00\n[5]: All in!\n";
		std::cin >> input_str;
		if (regex_match(input_str, valid_bet) == false)
		{
			std::cout << "\nInvalid input.\n";
		}
		else
		{
			input = stoi(input_str);
			break;
		}
	}

	switch (input)
	{
	case 1: 
		bet = 0.50;
		*pot_ptr += (bet * 2);
		money -= bet;
		break;
	case 2:
		bet = 1.00;
		*pot_ptr += (bet * 2);
		money -= bet;
		break;
	case 3:
		bet = 2.50;
		*pot_ptr += (bet * 2);
		money -= bet;
		break;
	case 4:
		bet = 5.00;
		*pot_ptr += (bet * 2);
		money -= bet;
		break;
	case 5:
		bet = money;
		*pot_ptr += (bet * 2);
		money -= bet;
		break;
	default:
		std::cout << "\n\nInvalid bet.\n\n";
	}
}


