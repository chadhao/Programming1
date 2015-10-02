#define COLOR_RED "\x1b[31m"
#define COLOR_GREEN "\x1b[32m"
#define COLOR_YELLOW "\x1b[33m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_RESET "\x1b[0m"

struct game
{
	int score;
	int best;
	int is_started;
};

int get_random(int low, int high);
void print_board(int board[16]);

void random_tile(int* board);
void start(int* board, struct game* a);

void move_up(int* board, struct game* a);
void move_down(int* board, struct game* a);
void move_left(int* board, struct game* a);
void move_right(int* board, struct game* a);

int check_game(int* board);

void save(struct game* a);
void load(struct game* a);