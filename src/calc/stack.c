#include <stdio.h>

// 最大栈深度
#define MAXVAL 100
// 下一个空闲栈位置
static int sp = 0;
// 用数组实现的栈
static double var[MAXVAL];

// push函数:将d压栈
void push(double d){
    if(sp < MAXVAL){
        var[sp++] = d;
    }else{
        printf("错误:栈溢出,入栈失败 %g\n",d);
    }
}

// pop函数:弹出并返回栈顶的值
double pop(void){
    if(sp > 0 ){
        return var[--sp];
    }else{
        printf("栈空间为空,无法弹出栈");
        return 0.0;
    }
}

//stacktop函数:返回栈顶元素，不会弹出，为空时返回-1
double stacktop(void){
    if(sp > 0 ){
        return var[sp - 1];
    }else{
        printf("栈空间为空,获取失败");
        return -1;
    }
}

// copytop函数:复制栈顶元素
void copytop(void){
    double t;
    if(sp > 0){
        t = var[sp - 1];
        push(t);
    }
}

// swaptop函数: 交换栈顶的两个元素
void swaptop(void){
    double tmp;
    if(sp > 1){
        tmp = var[sp - 1];
        var[sp - 1] = var[sp - 2];
        var[sp - 2] = tmp;
    }
}

//clearstack函数: 清空栈
void clearstack(void){
    while(sp > 0){
        var[--sp] = 0;
    }
}