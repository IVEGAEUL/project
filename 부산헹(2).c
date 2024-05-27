#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

//2-2
//�Ķ����
#define LEN_MIN 15 //��������
#define LEN_MAX 50
#define STM_MIN 0 //������ ü��
#define STM_MAX 5
#define PROB_MIN 10 //Ȯ��
#define PROB_MAX 90
#define AGGRO_MIN 0 //��׷� ����
#define AGGRO_MAX 5

//������ �̵� ����
#define MOVE_LEFT
#define MOVE_STAY

//������ ���� ���
#define ATK_NONE
#define ATK_CITIZEN 1
#define ATK_DONGSEOK 2

//������ �ൿ
#define ACTION_REST
#define ACTION_PROVOKE 1
#define ACTION_PULL 2

//2-1
//�������� ��� �Լ�
void print_line(int train_length) {
    for (int i = 0; i < train_length; i++) {
        printf("#");
    }
    printf("\n");
}

//�������� ��� �Լ�
void print_train(int train_length, int citizen, int zombie, int madongsuck) {
    print_line(train_length);
    printf("#");
    for (int i = 1; i <= train_length - 2; i++) {
        if (i == citizen) {
            printf("C");
        }
        else if (i == zombie) {
            printf("Z");
        }
        else if (i == madongsuck) {
            printf("M");
        }
        else {
            printf(" ");
        }
    }
    printf("#\n");
    print_line(train_length);
    printf("\n\n");
}

//���� ���� ��� �Լ�
void print_zombie_status(int move, int percentile_probability_p, int zombie, int turn, int zombie_pull) {
    if (zombie_pull == 1) {
        printf("zombie: stay %d (cannnot move)\n\n", zombie);
    }
    else {
        if (turn % 2 == 0) {
            if (move > 100 - percentile_probability_p) {
                printf("zombie: %d -> %d\n\n", zombie + 1, zombie);
            }
            else {
                printf("zombie: stay %d\n\n", zombie);
            }
        }
        else {
            printf("zombie: stay %d (cannnot move)\n\n", zombie);
        }
    }
}

int main() {
    int train_length, madongseok_stamina, percentile_probability_p, citizen, zombie, madongseok, move, aggro, madongseok_aggro, zombie_pull;
    int turn = 0;
    srand(time(0));

    //��Ʈ��
    printf("~....######. . . ######  . .          $$$$$     .   ######..   ......................    ...........\n");
    printf("~....######......###### ..    ..   $$$$$.$$$$$      ###### . .......................................\n");
    printf("~....######......######..   . .   $$$$$...$$$$$     ###### ............................             \n");
    printf("~....######=$#$########. . ..,,..$$$$$... ..$$$$$,,.$$$$$$####....................                  \n");
    printf("~....$$$$$$$$$$$$$$$$$$... ..  $$$$$$.....,.,###### $$$$$$####    .........................         \n");
    printf("~....$$$$$$$$$$$$$$$$$$     ,   ,.,.,.,.,...........#$$$$.,,,,,,,,,      .$$$$$$$$..................\n");
    printf(":....$$$$$$...,..$$$$$$. .      ...#####  ................................######## ..     ...    ...\n");
    printf(":....$$$$$$;.;...$$$$$$   . ;......#####!..........................................,.....  ,        \n");
    printf(":....##################..    . .. ;#####$################  ...........@@@@@@@@@@@@@@@... ,  ..      \n");
    printf(":... ##################   ..      !#####$$############### ............@@@@@@@@@@@@@@@......     ....\n");
    printf(":,...##################         ....................................................................\n");
    printf(":,......... ...,,,,,...   .     ,,,,,,,,,,,,,,,,,,,,,.,.....................$$$..........###. ##    \n");
    printf("!@#$$$=$$$$$$$##@@####$,         .........................................$$$.$$$..      ###  ##,,,,\n");
    printf("!@@@@@@@@@@@@@@@@@@@@@@~.               .........           ,....  ..... $$$..  $$$...######,,#:....\n");
    printf("!@@@@@@@@@@@@@@@@@@@@@@;           -::,   .,..             ,..............$$$.,$$$,,,,######,,@@!   \n");
    printf(":!;!~~~;!*=@@@@=!;;;::................        ,,,,,,,,,,,                   $$$. ........###..@@....\n");
    printf("~.........-@@@@-. .   ...............................................................###.###..@@   .\n");
    printf("~.......  ,@@@@- ............................................................,.,,,,###,,###,,,,,   .\n");
    printf("~.........-@@@@-.  ..   ...................................................      ### ,,,,###...  .  \n");
    printf("~.........,@@@@~. . .  . ....     ...............................       ...        ###  ###         \n");
    printf("~..........*$$$-. .    .........................................................  ....## ......... .\n");

    //2-2
    //���� �ʱ� ���� �Է�
    while (1) {
        printf("train length (15~50) >> ");
        scanf_s("%d", &train_length);
        if (train_length >= 15 && train_length <= 50) {
            break;
        }
    }

    //2-2
    //������ ü�� �Է�
    while (1) {
        printf("madongseok stamina(0~5) >> ");
        scanf_s("%d", &madongseok_stamina);
        if (madongseok_stamina >= 0 && madongseok_stamina <= 5) {
            break;
        }
    }

    while (1) {
        printf("percentile probability 'p' (10~90) >> ");
        scanf_s("%d", &percentile_probability_p);
        if (percentile_probability_p >= 10 && percentile_probability_p <= 90) {
            break;
        }
    }

    citizen = train_length - 6;
    zombie = train_length - 3;
    madongseok = train_length - 2;
    aggro = 1;

    //2-2
    //�ù�, ������ ��׷�
    madongseok_aggro = 1;
    zombie_pull = 0;

    print_train(train_length, citizen, zombie, madongseok);

    while (1) {
        move = rand() % 100 + 1;

        //2-3
        //�ù� �̵� ��Ģ
        if (move > percentile_probability_p) {
            citizen--;
        }

        //2-3
        //���� �̵� ��Ģ
        if (turn % 2 == 0) {
            if (move > 100 - percentile_probability_p) {
                if (aggro > madongseok_aggro) {
                    zombie--;
                }
                else if (madongseok == zombie + 1 && zombie == citizen + 1) {

                }
                else if (zombie == citizen + 1) {

                }
                else if (madongseok == zombie + 1) {

                }
                else if (aggro == madongseok_aggro) {
                    zombie--;
                }
                else {
                    zombie++;
                }
            }
        }
        //�ù� ���� ���
        print_train(train_length, citizen, zombie, madongseok);
        if (move > percentile_probability_p) {
            if (aggro >= 5) {
                printf("citizen: %d -> %d (aggro: %d)\n", citizen + 1, citizen, aggro);
            }
            else {
                printf("citizen: %d -> %d (aggro: %d -> %d)\n", citizen + 1, citizen, aggro++, aggro);
            }
        }
        else {
            if (aggro <= 0) {
                printf("citizen: stay %d (aggro: %d)\n", citizen, aggro);
            }
            else {
                printf("citizen: stay %d (aggro: %d -> %d)\n", citizen, aggro--, aggro);
            }
        }
        //���� ���� ���
        print_zombie_status(move, percentile_probability_p, zombie, turn, zombie_pull);
        printf("\n");

        if (citizen == 1) {
            break;
        }

        //2-3
        //������ �̵� ��Ģ
        int madongseok_move;
        while (1) {
            if (madongseok == zombie + 1) {
                printf("madongseok move(0:stay)>> ");
                scanf_s("%d", &madongseok_move);
                if (madongseok_move == 0) {
                    break;
                }
            }
            else {
                printf("madongseok move(0:stay, 1:left)>> ");
                scanf_s("%d", &madongseok_move);
                if (madongseok_move == 0 || madongseok_move == 1) {
                    break;
                }
            }
        }

        //2-3
        //������ �̵�
        if (madongseok_move == 1) {
            madongseok--;
        }

        print_train(train_length, citizen, zombie, madongseok);

        if (madongseok_move == 0) {
            if (madongseok_aggro <= 0) {
                printf("madongseok: stay %d (aggro: %d, stamina: %d)\n", madongseok, madongseok_aggro, madongseok_stamina);
            }
            else {
                printf("madongseok: stay %d (aggro: %d -> %d, stamina: %d)\n", madongseok, madongseok_aggro--, madongseok_aggro, madongseok_stamina);
            }
        }
        else {
            if (madongseok_aggro >= 5) {
                printf("madongseok: move %d (aggro: %d, stamina: %d)\n", madongseok, madongseok_aggro, madongseok_stamina);
            }
            else {
                printf("madongseok: move %d (aggro: %d -> %d, stamina: %d)\n", madongseok, madongseok_aggro++, madongseok_aggro, madongseok_stamina);
            }
        }

        //2-4
        //���� �ൿ ��Ģ
        printf("\nCitizen does nothing.\n");
        if (zombie == citizen + 1 && madongseok == zombie + 1) {
            if (aggro > madongseok_aggro) {
                break;
            }
            else if (aggro < madongseok_aggro) {
                if (madongseok_stamina <= 0) {
                    printf("zombie attacked madongseok (aggro: %d vs. %d madongseok: stamina: %d)\n", aggro, madongseok_aggro, madongseok_stamina);
                    break;
                }
                else {
                    printf("zombie attacked madongseok (aggro: %d vs. %d, madongseok: stamina: %d -> %d)\n", aggro, madongseok_aggro, madongseok_stamina--, madongseok_stamina);
                }
            }
            else {
                if (madongseok_stamina <= 0) {
                    printf("zombie attacked madongseok (aggro: %d vs. %d, madongseok: stamina: %d)\n", aggro, madongseok_aggro, madongseok_stamina);
                    break;
                }
                else {
                    printf("zombie attacked madongseok (aggro: %d vs. %d, madongseok: stamina: %d -> %d)\n", aggro, madongseok_aggro, madongseok_stamina--, madongseok_stamina);
                }
            }
        }
        else if (zombie == citizen + 1) {
            break;
        }
        else if (madongseok == zombie + 1) {
            if (madongseok_stamina <= 0) {
                printf("zombie attacked madongseok (aggro: %d, madongseok: stamina: %d)\n", madongseok_aggro, madongseok_stamina);
                break;
            }
            else {
                printf("zombie attacked madongseok (aggro: %d, madongseok: stamina: %d -> %d)\n", madongseok_aggro, madongseok_stamina--, madongseok_stamina);
            }
        }
        else {
            printf("zombie attacked nobody.\n");
        }

        //2-4
        //������ �ൿ ��Ģ
        int madongseok_action;
        if (madongseok = zombie + 1) {
            while (1) {
                printf("madongseok action(0.rest, 1.provoke, 2.pull)>> ");
                scanf_s("%d", &madongseok_action);
                if (madongseok_action == 0 || madongseok_action == 1 || madongseok_action == 2) {
                    break;
                }
            }
        }
        else {
            while (1) {
                printf("madongseok action(0.rest, 1.provoke)>> ");
                scanf_s("%d", &madongseok_action);
                if (madongseok_action == 0 || madongseok_action == 1) {
                    break;
                }
            }
        }
        printf("\n\n");

        //������ �޽�
        if (madongseok_action == 0) {
            printf("madongseok rests...\n");
            if (madongseok_stamina >= 5 && madongseok_aggro <= 0) {
                printf("madongseok: %d (aggro %d, stamina: %d)\n\n", madongseok, madongseok_aggro, madongseok_stamina);
            }
            else if (madongseok_stamina >= 5) {
                printf("madongseok: %d (aggro %d -> %d, stamina: %d)\n\n", madongseok, madongseok_aggro--, madongseok_aggro, madongseok_stamina);
            }
            else if (madongseok_aggro <= 0) {
                printf("madongseok: %d (aggro %d, stamina: %d -> %d)\n\n", madongseok, madongseok_aggro, madongseok_stamina++, madongseok_stamina);
            }
            else {
                printf("madongseok: %d (aggro %d -> %d, stamina: %d -> %d)\n\n", madongseok, madongseok_aggro--, madongseok_aggro, madongseok_stamina++, madongseok_stamina);
            }
        }
        //������ ����
        if (madongseok_action == 1) {
            printf("madongseok: %d (aggro: %d -> %d, stamina: %d)\n\n", madongseok, madongseok_aggro, 5, madongseok_stamina);
            madongseok_aggro = 5;
        }
        //������ �ٵ��
        if (madongseok_action == 2) {
            zombie_pull = 0;
            if (move > 100 - percentile_probability_p) {
                printf("madonogseok pulled zombie... Next turn, it can't move\n");
                if (madongseok_stamina >= 5 && madongseok_aggro >= 5) {
                    printf("madongseok: %d (aggro: %d, stamina: %d -> %d)\n\n", madongseok, madongseok_aggro, madongseok_stamina--, madongseok_stamina);
                }
                else  if (madongseok_aggro == 4 && madongseok_stamina <= 0) {
                    printf("madongseok: %d (aggro: %d -> %d, stamina: %d)\n\n", madongseok, madongseok_aggro++, madongseok_aggro, madongseok_stamina);
                }
                else  if (madongseok_aggro == 4) {
                    printf("madongseok: %d (aggro: %d -> %d, stamina: %d -> %d)\n\n", madongseok, madongseok_aggro++, madongseok_aggro, madongseok_stamina--, madongseok_stamina);
                }
                else if (madongseok_aggro >= 5 && madongseok_stamina <= 0) {
                    printf("madongseok: %d (aggro: %d, stamina: %d)\n\n", madongseok, madongseok_aggro, madongseok_stamina);
                }
                else if (madongseok_aggro >= 5) {
                    printf("madongseok: %d (aggro: %d, stamina: %d -> %d)\n\n", madongseok, madongseok_aggro, madongseok_stamina--, madongseok_stamina);
                }
                else if (madongseok_stamina >= 5) {
                    printf("madongseok: %d (aggro: %d", madongseok, madongseok_aggro);
                    madongseok_aggro++;
                    madongseok_aggro++;
                    printf(" -> %d, stamina: %d -> %d)\n\n", madongseok_aggro, madongseok_stamina--, madongseok_stamina);
                }
                else if (madongseok_stamina >= 5 && madongseok_aggro == 4) {
                    printf("madongseok: %d (aggro: %d -> %d, stamina: %d -> %d)\n\n", madongseok, madongseok_aggro++, madongseok_aggro, madongseok_stamina--, madongseok_stamina);
                }
                else if (madongseok_stamina <= 0) {
                    printf("madongseok: %d (aggro: %d", madongseok, madongseok_aggro);
                    madongseok_aggro++;
                    madongseok_aggro++;
                    printf(" -> %d, stamina: %d)\n\n", madongseok_aggro, madongseok_stamina);
                }
                else {
                    printf("madongseok: %d (aggro: %d", madongseok, madongseok_aggro);
                    madongseok_aggro++;
                    madongseok_aggro++;
                    printf(" -> %d, stamina: %d -> %d)\n\n", madongseok_aggro, madongseok_stamina--, madongseok_stamina);
                }
                zombie_pull++;
            }
            else {
                printf("madongseok failed to pull zombie\n");
                if (madongseok_stamina >= 5 && madongseok_aggro >= 5) {
                    printf("madongseok: %d (aggro: %d, stamina: %d -> %d)\n\n", madongseok, madongseok_aggro, madongseok_stamina--, madongseok_stamina);
                }
                else  if (madongseok_aggro == 4 && madongseok_stamina <= 0) {
                    printf("madongseok: %d (aggro: %d -> %d, stamina: %d)\n\n", madongseok, madongseok_aggro++, madongseok_aggro, madongseok_stamina);
                }
                else  if (madongseok_aggro == 4) {
                    printf("madongseok: %d (aggro: %d -> %d, stamina: %d -> %d)\n\n", madongseok, madongseok_aggro++, madongseok_aggro, madongseok_stamina--, madongseok_stamina);
                }
                else if (madongseok_aggro >= 5 && madongseok_stamina <= 0) {
                    printf("madongseok: %d (aggro: %d, stamina: %d)\n\n", madongseok, madongseok_aggro, madongseok_stamina);
                }
                else if (madongseok_aggro >= 5) {
                    printf("madongseok: %d (aggro: %d, stamina: %d -> %d)\n\n", madongseok, madongseok_aggro, madongseok_stamina--, madongseok_stamina);
                }
                else if (madongseok_stamina >= 5) {
                    printf("madongseok: %d (aggro: %d", madongseok, madongseok_aggro);
                    madongseok_aggro++;
                    madongseok_aggro++;
                    printf(" -> %d, stamina: %d -> %d)\n\n", madongseok_aggro, madongseok_stamina--, madongseok_stamina);
                }
                else if (madongseok_stamina >= 5 && madongseok_aggro == 4) {
                    printf("madongseok: %d (aggro: %d -> %d, stamina: %d -> %d)\n\n", madongseok, madongseok_aggro++, madongseok_aggro, madongseok_stamina--, madongseok_stamina);
                }
                else if (madongseok_stamina <= 0) {
                    printf("madongseok: %d (aggro: %d", madongseok, madongseok_aggro);
                    madongseok_aggro++;
                    madongseok_aggro++;
                    printf(" -> %d, stamina: %d)\n\n", madongseok_aggro, madongseok_stamina);
                }
                else {
                    printf("madongseok: %d (aggro: %d", madongseok, madongseok_aggro);
                    madongseok_aggro++;
                    madongseok_aggro++;
                    printf(" -> %d, stamina: %d -> %d)\n\n", madongseok_aggro, madongseok_stamina--, madongseok_stamina);
                }
            }
        }

        turn++;
    }
    //�ƿ�Ʈ��
    if (zombie == citizen + 1) {
        printf("GAME OVER! Citizen dead...\n");
    }
    else if (madongseok_stamina <= 0) {
        printf("GAME OVER! madongseok dead...\n");
    }
    else {
        printf("YOU WIN!\n");
    }

    return 0;
}