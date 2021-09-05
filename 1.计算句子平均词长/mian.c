//
//  main.c
//  1.计算句子平均词长
//
//  Created by 谭必清 on 2021/9/5.
//

#include "stdio.h"

int main(int argc, char *argv[]){
    float count = 1.0, number = 0.0, other = 0.0;
    char input;
    
    while((input = getchar()) != '\n'){
        if(input == ' ')
            count++;
        else if('a' <= input && input <= 'z' || 'A' <= input && input <= 'Z')
            number++;
        else
            other++;
    }
    printf("\n这个句子有%.0f个单词\n有%.0f个字符「不含标点」\n有%.0f个字符「含标点」\n平均词长是%.2f「不含标点」\n平均词长是%.2f「含标点」\n", count, number, number + other, number / count, (number + other) / count);
    return 0;
}
