#ifndef game_h_
#define game_h_
const int SCREEN_WIDTH  = 500;
const int SCREEN_HEIGHT = 500;
const int numCell = 5;
class Game
{
    bool quit = false;
    bool restart = true;
    bool played = false;
    int player = 0;
    int winner = -1;
    int board[numCell][numCell];
    int selected[2];
    int rx,ry;
    public:
        void init();
        void run();
    private:
        void updateTouch(int mouseX, int mouseY);
        void update();
        void render();
        int terminalState3();
        int terminalState5();
        int minimax(int turn);
        void computerAns();
};
#endif game_h_h;

