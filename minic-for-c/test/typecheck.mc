/*
 * @Copyright: Copyright (c) 2020 SCNU authors. All right reserved.
 * @FilePath: /minic2/minic/test/typecheck.mc
 * @Description: 测试类型检查功能，包含有语义错误，同时打印符号表
 * @Version: 1.0
 * @Author: Liang Zehao, Zhang Yongbiao
 * @Date: 2020-06-20 02:11:15
 * @LastEditTime: 2020-06-20 02:19:35
 * @LastEditors: Liang Zehao
 */ 

/* A Program to perform Euclid`s
   Algorithm to computer gcd */

int gcd (int u, int v)
{
    if (v == 0) return u;
    else return gcd(v,u-u/v*v);
    return 1;
    /* u-u/v*v == u mod v */
}

void main(void)
{
    void x; int y;
    x = input(); y[1] = input();
    gcd(1);
    c = 3;
    output(gcd(x,y));
}
