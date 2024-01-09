#include "21.header file.h"

struct Player {
    int score;
};

void playerTurn(struct Player* player) {
    while (1) {
        int card = drawCard();
        printf("你抽到了一張牌：%d點\n", card);

        char cardInfo[50];
        sprintf(cardInfo, "玩家抽到了一張牌：%d點", card);
        writeToFile("game_log.txt", cardInfo);

        if (card == 1) {
            int choice;
            printf("你抽到了A，要將A視為1點還是11點？(1/11)：");
            scanf("%d", &choice);

            if (choice == 1) {
                player->score += 1; // A視為1點
            }
            else if (choice == 11) {
                player->score += 11; // A視為11點
            }
            else {
                printf("無效的選擇，遊戲結束。\n");
                break;
            }
        }
        else {
            player->score += card;
        }

        printf("你目前的分數：%d點\n", player->score);

        if (player->score > MAX_SCORE) {
            printf("你的分數超過21點。\n");
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