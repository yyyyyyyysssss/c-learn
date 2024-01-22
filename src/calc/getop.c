#include <stdio.h>
#include <ctype.h>
#include "../../include/calc.h"

// 是否在数字内
#define IN_NUMBER 1
// 在数字外
#define OUT_NUMBER 0

//获取下一个运算符或操作数
int getops(char s[]){
    int c,i,state;
    i = 0;
    char back;
    state = IN_NUMBER;
    // 跳过空格或制表符
    while((c = getch()) == ' ' || c == '\t')
        ;
    if(state && c == '-'){
        s[i++] = c;
        c = getch();
        if(c == '\n'){
            back = s[--i];
            ungetch(c);
            return back;
        }
        state = OUT_NUMBER;
    }
    // 运算符直接返回
    if(!isdigit(c) && c != '.'){
        state = IN_NUMBER;
        return c;
    }
    if(isdigit(c)){
        s[i++] = c;
        while(isdigit(c = getch()) ){
            s[i++] = c;
        }
    }
    if(c == '.'){
        s[i++] = c;
        while(isdigit(c = getch()) ){
            s[i++] = c;
        }
    }
    s[i] = '\0';
    if(c != EOF){
        ungetch(c);
    }
    return NUMBER;

}