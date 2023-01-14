//
//  show_file_info.c
//  5.布尔类型&主调函数参数
//
//  Created by 谭必清 on 2023/01/14.
//

#include <stdio.h>
#include <stdbool.h>

int main(int argc, char const *argv[]) {
    void print_help();
    void print_info(int argc, char const *argv[]);
    bool is_true_arg(char const *argv[]);

    //printf("%d\n", argc);

    if (argc == 1 || argc == 2){
        printf("该程序需要附加参数:\n");
        print_help(argc, argv);
    }
    else if(is_true_arg(argv))
        print_info(argc, argv);
    else{
        printf("输入参数有误!\n");
        print_help();
    }

    return 0;
}

void print_help() {
    printf("  [file_name -p -*s]\n");
    printf("    - [-p]是打印所有参数\n");
    printf("    - [-*s]可输入多个字符串\n");
}

void print_info(int argc, char const *argv[]) {
    printf("文件名[%s]\n", argv[0]);
    for(int i = 2; i < argc; i++)
        printf("第%d个字符串: %s\n", i - 1, argv[i]);
}

bool is_true_arg(char const *argv[]) {
    //is_true_arguments
    //检查打印参数是否正确
    if(argv[1][1] == 'p' || argv[1][1] == 'P')
        return true;
    else
        return false;
}
