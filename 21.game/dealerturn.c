
#include "21.header file.h"

struct Player {
    int score;
};


#define MAX_SCORE 21
void dealerTurn(struct Player* dealer) {
    while (1) {
        int card = drawCard();
        printf("莊家抽到了一張牌：%d點\n", card);

        char cardInfo[50];
        sprintf(cardInfo, "莊家抽到了一張牌：%d點", card);
        writeToFile("game_log.txt", cardInfo);

        if (card == 1) {
            int choice;
            printf("你抽到了A，要將A視為1點還是11點？(1/11)：");
            scanf("%d", &choice);

            if (choice == 1) {
                dealer->score += 1; // A視為1點
            }
            else if (choice == 11) {
                dealer->score += 11; // A視為11點
            }
            else {
                printf("無效的選擇，遊戲結束。\n");
                break;
            }
        }
        else {
            dealer->score += card;
        }

        printf("莊家目前的分數：%d點\n", dealer->score);

        if (dealer->score > MAX_SCORE) {
            printf("莊家的分數超過21點。\n");
            break;
        }

        char continueChoice;
        printf("是否繼續抽牌？(y/n)：");
        scanf(" %c", &continueChoice);

        if (continueChoice != 'y') {
            break;
        }
    }
}