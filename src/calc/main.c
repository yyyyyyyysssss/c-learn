#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// 包含自定义头文件
#include "../../include/calc.h"

// 操作数或运算符最大长度
#define MAXOPS 100


/**
 * 逆波兰计算器
 * 逆波兰表示法中，所有运算符都在操作数后面。比如
 * (1-2) * (4+5)
 * 采用逆波兰表示为：
 * 1 2 - 4 5 + *
 * 
*/
// int main(){
//     int type,opsi;
//     char ops[MAXOPS];
//     double ops2;
//     while((type = getops(ops)) != EOF){
//         switch(type){
//             // 如果是数字 执行入栈
//             case NUMBER:
//                 push(atof(ops));
//                 break;
//             // 如果是 运算符 + 则出栈两个操作数相加并将结果入栈
//             case '+':
//                 push(pop() + pop());
//                 break;
//             // 如果是 运算符 -  则出栈两个操作数相加并将结果入栈  - 需要注意操作数顺序
//             case '-':
//                 ops2 = pop();
//                 push(pop() - ops2);
//                 break;
//             // 如果是 运算符 *  则出栈两个操作数相加并将结果入栈
//             case '*':
//                 push(pop() * pop());
//                 break;
//             // 如果是 运算符 /  则出栈两个操作数相加并将结果入栈  / 需要注意操作数顺序
//             case '/':
//                 ops2 = pop();
//                 push(pop() / ops2);
//                 break;
//             case '%':
//                 opsi = pop();
//                 push((int)pop() % opsi);
//                 break;
//             // 指数
//             case 'p' : case 'P':
//                 opsi = pop();
//                 push(pow(pop(),opsi));
//                 break;
//             //sin正弦函数
//             case 's':case 'S':
//                 push(sin(pop()));
//                 break;
//             //exp 返回e的x次幂
//             case 'e':case 'E':
//                 push(exp(pop()));
//                 break;
//             //  换行则输出计算结果，对应栈顶的操作数
//             case '\n':
//                 printf("=%.8g\n",pop());
//                 break;
//             default:
//                 printf("错误:不支持的操作类型 %s\n",ops);
//                 break;
//         }
//     }
// }