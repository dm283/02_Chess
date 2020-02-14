#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, field[8][8], fY = 1, fX, tY, tX, dffY, dffX;
    int cY = 6, cX = 3;

    // ПЕРВИЧНОЕ ЗАПОЛНЕНИЕ КЛЕТОК ПОЛЯ 0-ЗНАЧЕНИЯМИ
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            field[i][j] = 0;
        }
    }

    // KING=6 QUEEN=5 ROOK=4 KNIGHT=2 BISHOP=3 PAWN=1 
    field[cY][cX] = 1; // start position

while (fY != 100) {
    field[cY][cX] = 1;

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
    // ПРОВЕРКА ВВОДА fY, fX
    if (field[fY][fX] == 0){
        printf("Error! Selected cell is empty!");
        printf("\nInput value to continue"); scanf("%d", &tX);
        continue;
    }
    printf("\n[toY, toX]: "); scanf("%d, %d", &tY, &tX);
    // ПРОВЕРКА ВВОДА tY, tX
    if ((tY > 7 || tY < 0) || (tX > 7 || tX < 0))
        {
        printf("Error! Unboundary number of cell!");
        printf("\nInput value to continue"); scanf("%d", &tX);
        continue;
        }
    

    // ФУНКЦИЯ ПРОВЕРКИ КОРРЕКТНОСТИ ХОДА
    dffY = abs(tY - fY); dffX = abs(tX - fX);

    if (
        (fY - tY == 1) && (dffX == 0) // для "цвета" нижней стороны поля
        //(tY - fY == 1) && (dffX == 0) // для "цвета" верхней стороны поля
    )
    {
        printf("Correct move");
    }
    else{
        printf("Uncorrect move!");
        printf("\nInput value to continue"); scanf("%d", &tX);
        continue;
    }

    // ПЕРЕМЕЩЕНИЕ ОБЪЕКТА
    field[cY][cX] = 0;
    cY = tY; cX = tX;
    }

}
