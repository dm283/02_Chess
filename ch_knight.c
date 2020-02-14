#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, field[8][8], fY = 1, fX, tY, tX, dffY, dffX;
    int cY = 7, cX = 1;

    // ПЕРВИЧНОЕ ЗАПОЛНЕНИЕ КЛЕТОК ПОЛЯ 0-ЗНАЧЕНИЯМИ
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            field[i][j] = 0;
        }
    }

    // KING QUEEN ROOK KNIGHT BISHOP PAWN 
    field[cY][cX] = 7; // start position

while (fY != 100) {
    field[cY][cX] = 7;

    // ВИЗУАЛЬНОЕ ОТОБРАЖЕНИЕ
    system("cls");
    printf("* * 0|1|2|3|4|5|6|7 * *\n");
    printf("-----+-+-+-+-+-+-+-----\n");
    for (i = 0; i < 8; i++) {
        printf("%d | ", i);
        for (j = 0; j < 8; j++) {
            printf("%d ", field[i][j]);
        }
        printf("| %d\n", i);
    }
    printf("-----+-+-+-+-+-+-+-----\n");
    printf("* * 0|1|2|3|4|5|6|7 * *\n");

    // ВВОД ХОДОВ
    printf("\n[fromY, fromX]: "); scanf("%d, %d", &fY, &fX);
    printf("\n[toY, toX]: "); scanf("%d, %d", &tY, &tX);

    // ФУНКЦИЯ ПРОВЕРКИ КОРРЕКТНОСТИ ХОДА
    dffY = abs(tY - fY); dffX = abs(tX - fX);

    if (
        (dffY + dffX == 3) && (dffY != 0 && dffX != 0)
    )
    {
        printf("Correct move");
    }
    else{
        printf("Uncorrect move!");
        printf("\nInput value to continue"); scanf("%d", &tX);
        continue;
    }


    // if ((dffY + dffX != 3) || (dffY == 0 || dffX == 0)) {
    //     printf("Uncorrect move!");
    //     printf("\nInput value to continue"); scanf("%d", &tY);
    //     continue;
    // }

    // ПЕРЕМЕЩЕНИЕ ОБЪЕКТА
    field[cY][cX] = 0;
    cY = tY; cX = tX;
}

}
