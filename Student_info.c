/*
说明：
    - 程序中使用了结构体 `struct student` 存储每个学生的信息，包括姓名、各门课程的成绩、总分和平均分。
    - `NUM_OF_COURSES` 定义了本学期的课程数目，`NUM_OF_CORE_COURSES` 定义了核心课程数目，`NUM_OF_PRIZE_A`、`NUM_OF_PRIZE_B` 和 `NUM_OF_PRIZE_C` 分别定义了获得甲等奖学金、乙等奖学金和丙等奖学金的人数。
    - `display_menu` 函数输出程序的主界面。
    - `read_scores` 函数从文件中读取全班同学的成绩，并存储到结构体数组中。
    - `calculate_scores` 函数计算每个学生的总分和平均分，并将结果存储到结构体数组中。
    - `select_prize` 函数根据总分和核心课程总分高低选出获得奖学金的学生，并输出评选结果。
    - `debug_tools` 函数，是用来测试结构体的数据是否正常，目前根据所需功能定义为输出结构体全部信息。可根据需要自定义
    - 程序通过循环实现交互性，用户输入选项后调用相应的函数执行对应的功能。

注意事项：
    - 为了保证程序正确性和可读性，建议在实现具体函数时添加适当的注释。
    - 程序中使用了 `scanf` 函数读取用户输入，需要注意输入的格式和数据类型，以避免程序崩溃或出现意外结果。
    - 在实际使用中，需要根据具体情况修改程序中的常量和变量。例如，可以将文件名和路径设置为参数，提高程序的通用性。
    - 文件读写操作需要注意文件打开和关闭的时机，以避免文件被其他程序占用或损坏。
    - 文件严格按照如下格式:[姓名,核心课程1,核心课程2,核心课程3,核心课程4,成绩5,成绩6,成绩7,成绩8,成绩9]
    - 在计算总分和平均分时，可以使用循环结构遍历数组元素，但这样的效率较低。如果数据量较大，可以考虑使用并行计算或优化算法，提高程序的效率。
    - 在排序学生信息时，可以使用更高效的排序算法，如快速排序或归并排序，以提高程序的效率。
    - 在输出获奖学生信息时，可以按照总分从高到低输出，这样更符合奖学金评选的实际情况。
    - 在编写程序时，需要注意代码的可读性和可维护性，尽量使用清晰简洁的代码风格和命名规范，以方便自己和他人的理解和修改。

关于文件的读取:
    - 其中，第一行为数据的表头，第一个字段为姓名，后面8个字段为各门课程的成绩。
    - 每行数据以逗号分隔，行末不要有多余的空格或逗号。
    - 文件名可以自己定义，但是需要在程序中正确设置文件路径和文件名，以确保程序可以正确读取和写入文件。

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_OF_COURSES 8        // 本学期的课程数目
#define NUM_OF_CORE_COURSES 4   // 核心课程数目
#define NUM_OF_PRIZE_A 2        // 获得甲等奖学金
#define NUM_OF_PRIZE_B 3        // 获得乙等奖学金
#define NUM_OF_PRIZE_C 5        // 获得丙等奖学金的学生人数

//定义一个结构体,去保存学生的信息
struct student {
    int uid;                    // 学生学号
    char name[20];              // 学生姓名
    int scores[NUM_OF_COURSES]; // 学生所有课程的成绩
    int total_score;            // 通过'calculate_scores'函数计算出的总成绩
    float avg_score;            // 通过'calculate_scores'函数计算出的平均分
};

void display_menu();                                                    // 显示目录
void read_scores(struct student students[], int num_of_students);       // 从文件读取成绩
void calculate_scores(struct student students[], int num_of_students);  // 计算成绩和平均分
void select_prize(struct student students[], int num_of_students);      // 排序和输出获奖人数
void debug_tools(struct student student[]);                             // debug接口，用于检查数据测试

int main() {
    int num_of_students;
    printf("该班级有多少名学生: ");
    scanf("%d", &num_of_students);

    struct student students[num_of_students];               //构建一个结构体数组，保存全班的信息

    int option;
    do {
        system("cls");
        display_menu();                                     //显示目录
        printf("请选择目录: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                system("cls");
                read_scores(students, num_of_students);
                break;
            case 2:
                system("cls");
                calculate_scores(students, num_of_students);
                break;
            case 3:
                system("cls");
                select_prize(students, num_of_students);
                break;
            case 4:
                system("cls");
                printf("欢迎您的下次使用!\n");
                break;
            default:
                system("cls");
                printf("输入有误.\n");
                break;
        }
    } while (option != 4);

    return 0;
}

void display_menu() {
    printf("1. 从文件读取学生信息\n");
    printf("2. 计算总成绩和平均成绩\n");
    printf("3. 计算和输出获奖人数\n");
    printf("4. 退出'奖学金评选系统'\n");
}

void read_scores(struct student students[], int num_of_students) {
    char filename[20];
    printf("输入文件名: ");
    scanf("%s", filename);

    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("无法打开文件或者文件不存在.\n");
        return;
    }

    for (int i = 0; i < num_of_students; i++) {
        fscanf(fp, "%s", students[i].name);
        for (int j = 0; j < NUM_OF_COURSES; j++) {
            fscanf(fp, "%d", &students[i].scores[j]);
        }
    }

    fclose(fp);

    printf("成功读取文件. \n");
}

void calculate_scores(struct student students[], int num_of_students) {
    for (int i = 0; i < num_of_students; i++) {
        int total_score = 0;
        for (int j = 0; j < NUM_OF_COURSES; j++) {
            total_score += students[i].scores[j];
        }
        students[i].total_score = total_score;
        students[i].avg_score = (float) total_score / NUM_OF_COURSES;
    }

    printf("计算完成.\n");
}

void select_prize(struct student students[], int num_of_students) {
    // 按照总分排序已有的学生
    for (int i = 0; i < num_of_students - 1; i++) {
        for (int j = i + 1; j < num_of_students; j++) {
            if (students[j].total_score > students[i].total_score) {
                struct student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            } else if (students[j].total_score == students[i].total_score &&
                       students[j].scores[NUM_OF_CORE_COURSES] > students[i].scores[NUM_OF_CORE_COURSES]) {
                // 如果所有成绩一样，就看核心课程
                // 通过循环，依次比较该学生的四门核心课程
                struct student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }

    // 输出甲乙丙三类学生
    printf("下列获奖学生[学号]:[姓名] - [分数]:\n");
    printf("A:\n");
    for (int i = 0; i < NUM_OF_PRIZE_A; i++) {
        printf("\t%d:%s - %d\n", students[i].uid, students[i].name, students[i].total_score);
    }
    printf("B:\n");
    for (int i = NUM_OF_PRIZE_A; i < NUM_OF_PRIZE_A + NUM_OF_PRIZE_B; i++) {
        printf("\t%d:%s - %d\n", students[i].uid, students[i].name, students[i].total_score);
    }
    printf("C:\n");
    for (int i = NUM_OF_PRIZE_A + NUM_OF_PRIZE_B; i < NUM_OF_PRIZE_A + NUM_OF_PRIZE_B + NUM_OF_PRIZE_C; i++) {
        printf("\t%d:%s - %d\n", students[i].uid, students[i].name, students[i].total_score);
    }
}
