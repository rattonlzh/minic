/**
 * @file testGenTree4.mc
 * @author Liang Zehao
 * @brief 项目指导书要求的测试1
 * @version 0.1
 * @date 2020-04-23
 * 
 * @copyright Copyright (c) 2020
 * 
 */

/* A program to perform Euclid's
Algorithm to compute gcd. */
int gcd (int u, int v)
{ if (v == 0)return u;
else return gcd(v,u-u/v*v);
/* u-u/v*v == u mod v */
}

void main(void)
{ 
    int x;
    int y;
    x=input();
    y=input();
    output(gcd(x, y));
}