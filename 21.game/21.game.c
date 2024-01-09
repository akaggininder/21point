
#include "21.header file.h"

#define MAX_SCORE 21

struct Player {
    int score;
};



int main() {
    srand((unsigned int)time(NULL));

    struct Player player = { 0 };
    struct Player dealer = { 0 };

    printf("�w��Ө�21�I�C��!\n");


    char ch;// �s��Ū�����r��
    FILE* pfile;// �ŧi���V�ɮת����c����
    if ((pfile = fopen("rule.txt", "r")) == NULL) {  // �P�_�ɮ׬O�_�}�ҥ���
        printf("rule.txt �ɮ׵L�k�}��\n"); system("pause"); return(0);
    }


    while (!feof(pfile)) {	// �P�_�O�_Ū���ɮק�
        ch = fgetc(pfile);	// Ū���@�Ӧr��
        putchar(ch);		// ��XŪ�����r��
    }

    fclose(pfile); // �����ɮ�
    printf("\n");



    FILE* file = fopen("game_log.txt", "w");
    fclose(file);

    playerTurn(&player);

    if (player.score > MAX_SCORE) {
        printf("�A�����ƶW�L21�I�A�C�������C\n");
        writeToFile("game_log.txt", "�C�������G���a���ƶW�L21�I");
        writeToFile("game_result.txt", "�A��F�I");
        system("pause");
        return 0;
    }

    dealerTurn(&dealer);

    printf("�A�����ơG%d�I\n", player.score);
    printf("���a�����ơG%d�I\n", dealer.score);

    const char* result;
    if (player.score > MAX_SCORE || (dealer.score <= MAX_SCORE && dealer.score >= player.score)) {
        result = "�A��F�I";
        writeToFile("game_log.txt", "�C�������G�A��F");
    }
    else if (player.score == dealer.score) {
        result = "����I";
        writeToFile("game_log.txt", "�C�������G����");
    }
    else {
        result = "���ߧAĹ�F�I";
        writeToFile("game_log.txt", "�C�������G�AĹ�F");
    }

    printf("%s\n", result);
    writeToFile("game_result.txt", result);
    printf("�C�������I\n");
    system("pause");
    return 0;
}
