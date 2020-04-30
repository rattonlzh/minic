/**
 * @file testGenTree3.mc
 * @author Liang Zehao
 * @brief 检查if语句，while语句,关系表达式
 * @version 0.1
 * @date 2020-04-23
 * 
 * @copyright Copyright (c) 2020
 * 
 */
int main(void)
{
    int i;
    int max;
    if (2 > 3) max = 2;
    else {
        max = 3;
    }
    while (i < max)
    {
        i = i + 1;
    } 
    if (i == max) {
        output(i);
    }
    if (max >= 10) {
        output(max);
    }
    if (max <= 10) {
        output(10);
    }
    if (max != 233) {
        output(0);
    }
    
    return 0;
}