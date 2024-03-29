#include "stdafx.h"
#include "blackjack.h"


int main()
{
	

	Blackjack game1;
	
	while (game1.player_money > 0 || game1.tie == true)
	{
		game1.tie = false;
		game1.place_bets(game1.player_money, game1.player_bet);

		game1.clear_screen();
		game1.clear_hands(game1.player_hand, game1.dealer_hand);

		game1.deal_hand(1);
		game1.deal_hand(2);
		game1.show_1(game1.dealer_hand);
		game1.display_hand(game1.player_hand, 1);
		game1.check_hand(game1.player_hand, game1.player_score);
		game1.display_score(game1.player_score);
		game1.display_money();

		while (game1.hit_or_stay() == true)
		{
			game1.deal_card(1);
			game1.clear_screen();
			game1.show_1(game1.dealer_hand);
			game1.display_hand(game1.player_hand, 1);
			game1.check_hand(game1.player_hand, game1.player_score);
			game1.check_aces(game1.player_hand, game1.player_score);
			game1.display_score(game1.player_score);
			game1.display_money();
		}

		game1.clear_screen();
		game1.display_hand(game1.dealer_hand, 2);
		game1.display_hand(game1.player_hand, 1);
		game1.display_score(game1.player_score);
		game1.display_money();

		game1.check_hand(game1.dealer_hand, game1.dealer_score);
		game1.check_aces(game1.dealer_hand, game1.dealer_score);

		while (game1.player_score <= 21 && game1.dealer_score <= game1.player_score)
		{
			if (game1.dealer_score == game1.player_score && game1.dealer_score >= 17)
			{
				break;
			}
			else
			{
				game1.deal_card(2);
				game1.clear_screen();
				game1.display_hand(game1.dealer_hand, 2);
				game1.display_hand(game1.player_hand, 1);
				game1.display_score(game1.player_score);
				game1.display_money();
				game1.check_hand(game1.dealer_hand, game1.dealer_score);
				game1.check_aces(game1.dealer_hand, game1.dealer_score);
			}
			
		}

		game1.check_who_wins(game1.player_score, game1.dealer_score, game1.player_money, game1.player_bet);
		game1.display_money();
	}

	

	
    return 0;
}

