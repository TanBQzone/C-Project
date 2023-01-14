//
//  bool_is_prime.c
//  5.布尔类型&主调函数参数
//
//  Created by 谭必清 on 2023/01/14.
//

/*
* 输入一个数，判断是否为素数
* 使用bool类型创建一个函数
*/

#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int n;
    bool is_prime(int n);

    printf("输入一个数: ");
    scanf("%d", &n);
    if (is_prime(n))
        printf("%d 是一个素数。\n", n);
    else
        printf("%d 不是一个素数。\n", n);

    return 0;
}

bool is_prime(int n) {
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) 
            return false;
    return true;
}
