
#define N 9

int player1[N][N];
int player2[N][N];

void inicializar(int player[N][N]);
void print_campo(int player[N][N], int num_player);
void add_barco1x1(int player[N][N], int num_player);
int game(int player1[N][N], int num_player);
