/*
 * @Copyright: Copyright (c) 2020 SCNU authors. All right reserved.
 * @FilePath: /minic2/minic/test/gcd.mc
 * @Description: ????????????????????1
 * @Version: 1.0
 * @Author: Liang Zehao, Zhang Yongbiao
 * @Date: 2020-06-20 00:13:14
 * @LastEditTime: 2020-06-20 02:18:40
 * @LastEditors: Liang Zehao
 */ 

/* A Program to perform Euclid`s
   Algorithm to computer gcd */

int gcd (int u, int v)
{
    if (v == 0) return u;
    else return gcd(v,u-u/v*v);
    /* u-u/v*v == u mod v */
}

void main(void)
{
    int x; int y;
    x = input(); y = input();
    output(gcd(x,y));
}
