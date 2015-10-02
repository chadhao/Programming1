struct card
{
	char rank[10];
	char suit[10];
	int value;
};

struct deck
{
	struct card oneCard[208];
	int cardNow;
};

struct player
{
	char* name;
	unsigned long chip;
	int win;
	int lose;
	int push;
};

struct game
{
	int dealer_inhand[12];
	int player_inhand[12];
	unsigned long bet;
	int is_insured;
	int is_doubled;
};

char ranks[13][10] = {"Ace", "King", "Queen", "Jack", "Ten", "Nine", "Eight", "Seven", "Six", "Five", "Four", "Three", "Two"};
char suits[4][10] = {"Spade", "Heart", "Club", "Diamond"};
int value[13] = {11, 10, 10, 10, 10, 9, 8, 7, 6, 5, 4, 3, 2};

//card.c
int card_get_random(int low, int high);
void card_init_deck(struct deck* tempDeck);
void card_shuffle(struct deck* tempDeck);

//player.c
void player_name(struct player* tempPlayer);
void player_chip(struct player* tempPlayer);
void player_save(struct player* tempPlayer);
char* player_load_read_string(FILE* file);
void player_load(struct player* tempPlayer);
void player_status(struct player* tempPlayer);

//game.c
void game_init(struct game* tempGame);
void game_bet(int betType, struct player* tempPlayer, struct game* tempGame);
void game_deal_card(int dealType, struct game* tempGame, struct deck* tempDeck);
int game_howmanyace(int who, struct game* tempGame, struct deck* tempDeck);
int game_totalvalue(int who, struct game* tempGame, struct deck* tempDeck);
int game_judge(struct game* tempGame, struct deck* tempDeck);
void game_print_card(int who, struct game* tempGame, struct deck* tempDeck);
int game_end();
void game_dealer(struct game* tempGame, struct deck* tempDeck);
void game_play(struct player* tempPlayer, struct deck* tempDeck, struct game* tempGame);