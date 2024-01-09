#include "21.header file.h"

struct Player {
    int score;
};

void playerTurn(struct Player* player) {
    while (1) {
        int card = drawCard();
        printf("�A���F�@�i�P�G%d�I\n", card);

        char cardInfo[50];
        sprintf(cardInfo, "���a���F�@�i�P�G%d�I", card);
        writeToFile("game_log.txt", cardInfo);

        if (card == 1) {
            int choice;
            printf("�A���FA�A�n�NA����1�I�٬O11�I�H(1/11)�G");
            scanf("%d", &choice);

            if (choice == 1) {
                player->score += 1; // A����1�I
            }
            else if (choice == 11) {
                player->score += 11; // A����11�I
            }
            else {
                printf("�L�Ī���ܡA�C�������C\n");
                break;
            }
        }
        else {
            player->score += card;
        }

        printf("�A�ثe�����ơG%d�I\n", player->score);

        if (player->score > MAX_SCORE) {
            printf("�A�����ƶW�L21�I�C\n");
            break;
        }

        char continueChoice;
        printf("�O�_�~���P�H(y/n)�G");
        scanf(" %c", &continueChoice);

        if (continueChoice != 'y') {
            break;
        }
    }
}