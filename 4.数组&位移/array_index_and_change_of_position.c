//
//  array_index_and_change_of_position.c
//  4.数组&位移
//
//  Created by 谭必清 on 2023/01/09.
//

/*
* 下列给定程序中，函数mov的功能是
* 将指定字符串中下标为奇数的字符右移到下一个奇数位置，
* 最右边被移出字符串的字符绕回放到第一个奇数位置，
* 下标为偶数的字符不动（注：字符串的长度大于等于2）。
*/

#include <stdio.h>

void move(char s[]){
    int index;	//交换时的下标
    int cnt;	//计数&位置
    char end;	//最后一个奇数的位置

    //计数
    for(cnt = 0; s[cnt]; cnt++);

    cnt--;
	if(cnt % 2 == 0)
		cnt--;

	//获取最后一个奇数的位置
	end = s[cnt];

    //从后往前覆盖
    for(index = cnt - 2; index >= 1; index -= 2){
        s[index + 2] = s[index];
    }
    s[1] = end;
}

int main(void) {
    char string[] = {"abcdefg"};
    printf("原始数据: %s\n", string);
    move(string);
    printf("移动后的: %s\n", string);
    return 0;
}
