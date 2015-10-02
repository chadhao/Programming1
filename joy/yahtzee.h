#define COLOR_RED "\x1b[31m"
#define COLOR_GREEN "\x1b[32m"
#define COLOR_RESET "\x1b[0m"

struct dice
{
	int point;
	int is_hold;
};

struct board
{
	int ones;
	int twos;
	int threes;
	int fours;
	int fives;
	int sixes;
	int sum;
	int bonus;
	int threeofakind;
	int fourofakind;
	int fullhouse;
	int small;
	int large;
	int chance;
	int yahtzee;
	int total;
};

int get_random(int low, int high);
void dice_random(struct dice* a);
void print_dice(struct dice* a);
void print_board(int type, struct dice* a, struct board* b);
int upper(int which, struct dice* a);
void change_hold(int which, struct dice* a);
void check_upper(struct board* b);