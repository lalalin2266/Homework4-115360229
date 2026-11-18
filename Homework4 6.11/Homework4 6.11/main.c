#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

void BubbleSort(int array[], int size);

int main()
{
    // 測試陣列（放一些隨機的數字）
    int a[SIZE] = { 25, 17, 39, 12, 48, 8, 55, 33, 19, 41 };
    int i;
    printf("Array before sorting：\n");
    for (i = 0; i < SIZE; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n\n");

    // 呼叫優化後的氣泡排序
    BubbleSort(a, SIZE);

    printf("Array after sorting:\n");
    for (i = 0; i < SIZE; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    system("pause");
    return 0;
}

void BubbleSort(int array[], int size)
{   int pass, i, hold;
    int swapped; // 用來記錄這一輪是否有發生元素交換 (對應題目 b)
    // 外層迴圈控制總共要進行幾輪 (最多 size - 1 輪)
    for (pass = 0; pass < size - 1; pass++)
    {
        swapped = 0; // 每一輪剛開始時，先假設沒有發生交換
        // 內層迴圈：隨著 pass 增加，後面已排序好的元素不用再比較 (對應題目 a)
        // 也就是每一輪只要比較到 size - 1 - pass 即可
        for (i = 0; i < size - 1 - pass; i++)
        {
            // 如果前面的數字大於後面的數字，則進行交換
            if (array[i] > array[i + 1])
            {
                hold = array[i];
                array[i] = array[i + 1];
                array[i + 1] = hold;

                swapped = 1; // 發生了交換，將旗標設為 1
            }
        }

        // 如果這一輪跑完，完全沒有發生任何交換 (swapped 仍為 0)
        // 代表陣列已經完全排好順序，直接跳出迴圈終止程式 (對應題目 b)
        if (swapped == 0)
        {
            printf("--- Early termination! Fully sorted at pass %d ---\n\n", pass + 1);
            break;
        }
    }
}