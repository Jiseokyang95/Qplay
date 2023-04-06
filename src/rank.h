#define MAX_PLAYERS 10     // 최대 플레이어 수
#define MAX_NAME_LENGTH 20 // 플레이어 이름 최대 길이

typedef struct
{
    char name[MAX_NAME_LENGTH];
    int score;
} Player;

// 순위 정보 구조체
typedef struct
{
    Player players[MAX_PLAYERS];
    int num_players;
} Leaderboard;

typedef struct
{
    char ntmp_name[MAX_NAME_LENGTH];
    int nTmp;
} ntmp_Player;

// 순위 정보 구조체
typedef struct
{
    Player ntmp_players[MAX_PLAYERS];
    int ntmp_num_players;
} ntmp;

void load_leaderboard(Leaderboard *leaderboard);
void save_leaderboard(Leaderboard leaderboard);
void add_player(Leaderboard *leaderboard, char *name, int score);
void print_leaderboard(Leaderboard leaderboard);