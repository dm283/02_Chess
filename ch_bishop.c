#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, field[8][8], fY = 1, fX, tY, tX, dffY, dffX;
    int cY = 7, cX = 2;

    // ПЕРВИЧНОЕ ЗАПОЛНЕНИЕ КЛЕТОК ПОЛЯ 0-ЗНАЧЕНИЯМИ
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            field[i][j] = 0;
        }
    }

    // KING=6 QUEEN=5 ROOK=4 KNIGHT=2 BISHOP=3 PAWN=1 
    field[cY][cX] = 3; // start position

while (fY != 100) {
    field[cY][cX] = 3;

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
    // if (abs(inp_ty - inp_fy) + abs(inp_tx - inp_fx) != 3) {
    //     printf("Uncorrect move!");
    //     printf("\nInput value to continue"); scanf("%d", &inp_ty);
    //     continue;
    // }

// для слона - посчитать разницу diffY и проверять не все возможные значения,  а только точки в углах квадрата со стороной diffY !!!
    dffY = abs(tY - fY);

    printf("dffY=%d tY=%d tX=%d fY=%d fX=%d", dffY, tY, tX, fY, fX);

    if (
        (((fY + dffY) == tY) && ((fX + dffY) == tX)) ||
        (((fY - dffY) == tY) && ((fX - dffY) == tX)) ||
        (((fY + dffY) == tY) && ((fX - dffY) == tX)) ||
        (((fY - dffY) == tY) && ((fX + dffY) == tX))
    ){
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
