#include <stdio.h>

// 读取字符缓冲区大小
#define BUFFSIZE 100
// 下一个缓冲区空闲位置
static int bs = 0;
//缓冲区
static char buff[BUFFSIZE];


// 取一个字符，可能是缓冲区中的
int getch(void){

    return (bs > 0) ? buff[--bs] : getchar();
}

// 将字符放回缓冲区
void ungetch(char c){
    if(bs >= BUFFSIZE){
        printf("错误：缓冲区已满，无法放回字符\n");
    }else{
        buff[bs++] = c;
    }
}

// 将整个字符串压入输入中
void ungets(char s[]){
    int i =0;
    for(;s[i] != '\0';i++){
        ungetch(s[i]);
    }
}