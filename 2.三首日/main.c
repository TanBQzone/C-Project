//
//  main.c
//  2.三首日
//
//  Created by 谭必清 on 2022/9/16.
//

#include <stdio.h>

int main(int argc, char const *argv[]) {
	int year = 2017;		//开始的时间
	int times = 5;			//次数
	int sum = 0;			//计数 -> 找与2017年第一天相同的条件
	while(times > 0) {
		if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
			sum += 366;
		else
			sum += 365;
		if(sum % 7 == 0) {
			printf("%d\n", year + 1);
			times--;
		}
		year++;
	}
	return 0;
}
