/**
 * @file testGenTree3.mc
 * @author Liang Zehao
 * @brief minic的声明必须在放在作用域的开头，这里尝试放在表达式语句后面
 * @version 0.1
 * @date 2020-04-23
 * 
 * @copyright Copyright (c) 2020
 * 
 */
int main(void)
{

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
    int i;
    int max;
    return 0;
}