//
//  numpyramid_for.c
//  3.数字金字塔1
//
//  Created by 谭必清 on 2022/11/20.
//

/*
实现打印一个数宇金字塔。
例如：输入5，图形如下图所示
    1*
   12**
  123***
 1234****
12345*****
*/

#include <stdio.h>

int main(int argc, char const *argv[]) {
	int User_in;
	int num;
	char ch = '*';
	int cnt;
	int tmp;

	do {
		printf("%s", "Please input a num[1,9]:");
		scanf("%d", &User_in);
	} while(User_in <= 0 || User_in >= 10);

	for(cnt = 1; cnt <= User_in; cnt++) {
		for(tmp = 1; tmp <= User_in - cnt; tmp++)
			printf(" ");
		for(num = 1; num <= cnt; num++)
			printf("%d", num);
		for(tmp = 1; tmp <= cnt; tmp++)
			printf("%c", ch);
		printf("\n");
	}

	return 0;
}
