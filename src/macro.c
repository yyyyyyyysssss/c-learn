/**
 * 宏
*/

#include <stdio.h>
#include "../include/hdr.h"

#define forever for(;;)
// 对于自增变量可能会出现问题 比如 max(i++,j++)
#define max(a,b) ((a) > (b) ? (a) : (b))
// 定义计算平方的宏函数  可以简化代码 必须用括号括起来 不然就会出错，比如计算x+1时  宏展开为 x+1 * x+1 结果就为错的了
#define square(x) ((x) * (x))
// 定义有问题的宏函数
#define maxsquare(a,b) ((a) + (b))
// 取消maxsquare定义，并在后续重新定义该宏
#undef maxsquare
// 宏函数可以包含另一个宏函数
#define maxsquare(a,b) square(max(a,b))

// #作为前缀则结果将被扩展为实际参数替换该参数的带引号的字符串
#define dprint(expr) printf(#expr"=%g\n",expr)

// ##作为前缀，将两个宏参数连接到一起
#define paste(a,b) a##b

#define CONCAT(x,y) x##y

#define SWAP(t,x,y) \
typeof(t[x]) tmp = t[x];\
t[x]=t[y];\
t[y]=tmp;

// 如果该 HDR 宏已经定义了则定义一个变量 cx 否则定义cz
#ifdef HDR
    char cx = 'a';
#else
    char cz = 'b';
#endif

// 宏条件判断 非0表示真
#define ENABLE_FEATURE 4
#if ENABLE_FEATURE == 0
#define SUM(x,y) ((x) + (y))
#elif ENABLE_FEATURE == 1
#define SUM(x,y) ((x) - (y))
#elif ENABLE_FEATURE == 2
#define SUM(x,y) ((x) * (y))
#else
#define SUM(x,y) ((x) / (y))
#endif








// int main(){
//     // forever{
//     //     printf("hello macro\n");
//     // }
//     int x,y;
//     x = 1;
//     y = 2;
//     int z = maxsquare(x,y);
//     dprint(x/y);
//     int num1 = 10;
//     int num2 = 20;
//     CONCAT(num,1) = 30;
//     CONCAT(num,2) = 40;

//     char v[] ={'a','b'};
//     SWAP(v,0,1);
//     printf("%c\n",cx);
// }