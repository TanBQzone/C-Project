//
//  line_up_for_water.c
//  6.取水问题
//
//  Created by 谭必清 on 2023/07/18.
//

/* ============================================================================
 * 题目描述
 *  - 有n个人在一个水龙头前排队接水，假如每个人接水的时间为Ti，
 *  - 请编程找出这n个人排队的一种顺序，使得n个人的平均等待时间最小。
 *
 * 输入格式[共两行]:
 *      第一行为n(1 ≤ n ≤ 1000)；
 *      第二行分别表示第1个人到第n个人每人的接水时间T1，T2，…，Tn，每个数据之间有1个空格。
 *
 * 输出格式[有两行]:
 *      第一行为一种排队顺序，即1到n的一种排列；
 *      第二行为这种排列方案下的平均等待时间(输出结果精确到小数点后两位)。
 *
 * 样例输入
 *      请输入排队人数: 5
 *      请输入每个人的接水时间: 10 5 1 7 2
 * 样例输出
 *      最优接水顺序: 3 5 2 4 1
 *      一共要等待: 27s
 *      平均等待时间: 5.40s
 *
 * 实现思路：
 *  1. 首先，我们定义一个结构体 `Person`，用于存储每个人的接水时间和编号。
 *  2. 接下来，读取输入的人数 `n`，并创建一个大小为 `n` 的结构体数组 `people[]`，用于存储每个人的接水时间和编号。
 *  3. 然后，使用一个循环读取每个人的接水时间，并将其保存在对应的结构体中。
 *  4. 接下来，实现一个排序函数 `sort()`，用于按照接水时间从小到大对结构体数组进行排序，并记录对应的编号序列。
 *  5. 调用 `sort()` 函数对结构体数组进行排序。
 *  6. 输出排序后的编号序列。
 * ============================================================================*/

# include "stdio.h"

typedef struct {
    int id;
    int time;
} Person;

void sort(Person person[], int order[], int pN) {
    for (int i = 0; i < pN; i++) {
        order[i] = i + 1;
    }

    for (int i = 0; i < pN - 1; i++) {
        for (int j = 0; j < pN - i - 1; j++) {
            if (person[order[j] - 1].time > person[order[j + 1] - 1].time) {
                int temp = order[j];
                order[j] = order[j + 1];
                order[j + 1] = temp;
            }
        }
    }
}

void printPeople(Person person[], int order[], int pN) {
    printf("======Person Info======\n");
    for (int i = 0; i < pN; i++) {
        printf("    第%d位：%d[s]\n", person[i].id, person[i].time);
    }
    printf("=======================\n\n");
    printf("最优接水顺序: ");
    for (int i = 0; i < pN; i++) {
        printf("%d ", order[i]);
    }
    printf("\n");
}

int main() {
    int peopleNum;
    printf("请输入排队人数: ");
    scanf("%d", &peopleNum);

    int time[peopleNum];
    Person person[peopleNum];

    printf("请输入每个人的接水时间[单位/s]: ");
    for (int i = 0; i < peopleNum; i++) {
        person[i].id = i + 1;
        scanf("%d", &person[i].time);
    }

    int order[peopleNum];
    sort(person, order, peopleNum);

    printPeople(person, order, peopleNum);

    double sum = 0.0;
    for (int i = 0; i < peopleNum; i++) {
        sum += (peopleNum - i - 1) * person[order[i] - 1].time;
    }
    double average = sum / peopleNum;
    printf("所有人一共要等待: %.0fs\n", sum);
    printf("平均等待时间: %.2lfs\n", average);

    return 0;
}
