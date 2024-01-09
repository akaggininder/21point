
#include "21.header file.h"

#define MAX_SCORE 21

struct Player {
    int score;
};



int main() {
    srand((unsigned int)time(NULL));

    struct Player player = { 0 };
    struct Player dealer = { 0 };

    printf("歡迎來到21點遊戲!\n");


    char ch;// 存放讀取的字元
    FILE* pfile;// 宣告指向檔案的結構指標
    if ((pfile = fopen("rule.txt", "r")) == NULL) {  // 判斷檔案是否開啟失敗
        printf("rule.txt 檔案無法開啟\n"); system("pause"); return(0);
    }


    while (!feof(pfile)) {	// 判斷是否讀到檔案尾
        ch = fgetc(pfile);	// 讀取一個字元
        putchar(ch);		// 輸出讀取的字元
    }

    fclose(pfile); // 關閉檔案
    printf("\n");



    FILE* file = fopen("game_log.txt", "w");
    fclose(file);

    playerTurn(&player);

    if (player.score > MAX_SCORE) {
        printf("你的分數超過21點，遊戲結束。\n");
        writeToFile("game_log.txt", "遊戲結束：玩家分數超過21點");
        writeToFile("game_result.txt", "你輸了！");
        system("pause");
        return 0;
    }

    dealerTurn(&dealer);

    printf("你的分數：%d點\n", player.score);
    printf("莊家的分數：%d點\n", dealer.score);

    const char* result;
    if (player.score > MAX_SCORE || (dealer.score <= MAX_SCORE && dealer.score >= player.score)) {
        result = "你輸了！";
        writeToFile("game_log.txt", "遊戲結束：你輸了");
    }
    else if (player.score == dealer.score) {
        result = "平手！";
        writeToFile("game_log.txt", "遊戲結束：平手");
    }
    else {
        result = "恭喜你贏了！";
        writeToFile("game_log.txt", "遊戲結束：你贏了");
    }

    printf("%s\n", result);
    writeToFile("game_result.txt", result);
    printf("遊戲結束！\n");
    system("pause");
    return 0;
}
