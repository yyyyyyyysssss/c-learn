/* 
    指针
 */
#include <stdio.h>
#include <ctype.h>
#include "../include/calc.h"

#define SIZE 10

static void swap(int *x,int *y){
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int main(){
    // char c = 'a';
    // char *p = &c;

    // printf("%p\n",p);

    // int x,y,z[10];
    // z[0] = 100;
    // x = 1;
    // y = 2;
    // int *ip;
    // ip = &x;
    // *ip += 10;
    // 该处圆括号必须，否则，该表达式对ip进行加1运算，而不是对ip指向的对象进行加1运算。
    // (*ip)++;
    // ++*ip;
    // y = *ip;
    // 重新指向z[0]的内存地址
    // ip = &z[0];

    // int *iq = ip;
    // *iq = 130;
    // int *xp,*yp;
    // xp = ip;
    // yp = &y;
    // swap(xp,yp);

    // int ii[] = {100,200};
    // xp = &ii[0];
    // yp = &ii[1];
    // swap(xp,yp);

    // printf("%d\n",ii[0]);


    // int n,c,array[SIZE],getint(int *pn);
    // for(n = 0;n < SIZE && (c = getint(&array[n])) != EOF;n++)
    //     ;
    
    int n,c,getdouble(double *pn);
    double array[SIZE];
    for(n = 0;n < SIZE && (c = getdouble(&array[n])) != EOF;n++)
        ;
    

    for(int i=0;i < SIZE;++i){
        printf("%f\t",array[i]);
    }
    printf("\n");
    return 0;
}

int getint(int *pn){
    int c,sign,power;
    // 跳过空格
    while(isspace(c = getch()))
        ;
    if(!isdigit(c) && c != EOF && c != '+' && c != '-'){
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if(c == '-' || c == '+'){
        int tmp = c;
        c = getch();
        if(!isdigit(c)){
            ungetch(tmp);
        }

    }
    // 整数部分
    for(*pn = 0;isdigit(c);c = getch()){
        *pn = 10 * (*pn) + (c - '0');
    }
    if(c == '.'){
        c = getch();
        power = 1;
        for(*pn = 0;isdigit(c);c = getch()){
            *pn = 10 * (*pn) + (c - '0');
            power *= 10;
        }
    }
    *pn *= sign;
    if(c != EOF){
        ungetch(c);
    }
    return c;
}

int getdouble(double *pn){
    int c,sign;
    double power = 1.0;
    // 跳过空格
    while(isspace(c = getch()))
        ;
    if(!isdigit(c) && c != EOF && c != '+' && c != '-'){
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if(c == '-' || c == '+'){
        int tmp = c;
        c = getch();
        if(!isdigit(c)){
            ungetch(tmp);
        }

    }
    // 整数部分
    for(*pn = 0.0;isdigit(c);c = getch()){
        *pn = 10.0 * (*pn) + (c - '0');
    }
    if(c == '.'){
        c = getch();
        for(;isdigit(c);c = getch()){
            *pn = 10.0 * (*pn) + (c - '0');
            power *= 10.0;
        }
    }
    *pn = *pn * sign / power;
    if(c != EOF){
        ungetch(c);
    }
    return c;
}