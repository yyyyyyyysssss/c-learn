#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <string.h>
#include <ctype.h>

// 温度上限
#define LOWER 0
// 温度下线
#define UPPER 300
// 步长
#define STEP 20
// 在单词内
#define IN 1
// 在单词外
#define OUT 0

#define MAXLINE 1000

// 制表符终止位
#define TABSTOPBIT 8

int global = 10;

//300以内华氏温度转摄氏温度 T （°C） =（5/9） * （ T （°F） -32）
void fahrToCelsius(){
    float fahr,celsius;
    fahr = LOWER;
    printf("以下为300以内华氏温度与摄氏温度的对照表:\n");
    while (fahr <= UPPER){
        celsius = (5.0/9.0) * (fahr -32.0);
        printf("%3.0f\t%6.1f\n",fahr,celsius);
        fahr += STEP;
    }
}

//300以内摄氏温度转华氏温度T （°F） = T （°C） / （5/9） + 32
void celsiusToFahr(){
    int celsius;
    printf("以下为300以内摄氏温度与华氏温度的对照表:\n");
    for (celsius = UPPER; celsius >= LOWER; celsius = celsius - STEP){
        printf("%3d\t%6.1f\n",celsius,celsius / (5.0 / 9.0) + 32.0);
    }
}

void inout(){
    int c;
    while((c = getchar()) != EOF){
        putchar(c);
    }
}

// 统计空格 制表符 行数
void incount(){
    long c,spacec,tablec,linec;
    spacec = 0;
    tablec = 0;
    linec = 0;
    while( (c = getchar()) != EOF){
        if(c == '\n'){
            ++linec;
        }else if(c == '\t'){
            ++tablec;
        }else if(c == ' '){
            ++spacec;
        }
    }
    printf("空格统计:%ld\n制表符统计:%ld\n行统计:%ld\n",spacec,tablec,linec);
}

// 将连续空格替换为一个空格
void incount2(){
    int c,nc;
    nc = 0;
    while((c = getchar()) != EOF){
        if(c == ' ' && nc == 1){
            continue;
        }
        if(c == ' '){
            putchar(c);
            nc = 1;
        }else{
            nc = 0;
            putchar(c);
        }
        // if(c == ' '){
        //     putchar(c);
        //     while((c = getchar()) == ' '){

        //     }
        // }
        // if(c != EOF){
        //     putchar(c);
        // }else{
        //     break;
        // }
    }
}

//单词计数 统计行数、单词数与字符数以及数字出现的次数
void wordcount(){
    int c,nl,wc,nc,state;
    int ndigit[10];
    state = OUT;
    nl = wc = nc = 0;
    // 初始化数组
    for (int i = 0; i < 10; i++){
        ndigit[i] = 0;
    }
    
    while((c = getchar()) != EOF){
        ++nc;
        if(c == '\n'){
            ++nl;
        }
        if(c >= '0' && c <= '9'){
            // 对应数组下标的值递增
            ++ndigit[c - '0'];
        }else if(c == ' ' || c == '\t' || c == '\n'){
            state = OUT;
        }else if(state == OUT){
            state = IN;
            ++wc;
        }
    }
    printf("digits =");
    for (int i = 0; i < 10; i++){
        printf(" %d",ndigit[i]);
    }
    printf("行数:%d 单词数:%d 字符数:%d\n",nl,wc,nc);
}

// 单词长度垂直直方图
void wordcount2(){
    int c,index,state;
    int array[10];
    index = 0;
    state = IN;
    for(int i=0;i<10;++i){
        array[i] = 0;
    }
    while((c = getchar()) != EOF){
        if(c == ' ' || c == '\t' || c == '\n'){
            state = OUT;
        }else if(state == OUT){
            state = IN;
            ++array[index];
        }else{
             ++array[index];
            while((c = getchar()) != ' ' && c != '\t' && c!= '\n' && c != EOF){
                 ++array[index];
            }
            state = OUT;
            ++index;
        }
    }
    printf("\n");
    for(int i=0;i<10;++i){
        printf("第%d个单词:",i+1);
        for(int j=0;j<array[i];++j){
            printf(" *");
        }
        printf("\n");
    }
}

// 求整数 m 的 n 次幂
unsigned long power(int base,int n){
    if(n == 0){
        return 1;
    }
    if(n == 1){
        return base;
    }
    return power(base,n-1) * base;
}

// 返回字符串长度
int strlength(const char str[]){
    int i = 0;
    char c;
    while((c = str[i++]) != '\0' && c != '\n');
    return i-1;
}

//反转字符串
void reverse(char str[]){
    int len = strlength(str);
    int i,j,tmp;
    for(i=0,j=len-1; i < j;i++,j--){
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
    }
}

void swapchars(char c[],int s,int e){
    if(s > e){
        return;
    }
    char tmp = c[s];
    c[s] = c[e];
    c[e] = tmp;
    swapchars(c,++s,--e);
}

// 递归反转字符串  比如  hello
void reverse_recursion(char str[]){
    int len = strlen(str);
    swapchars(str,0,len-1);
    printf("%s\n",str);
}




// 返回给定行长度
int getlinelen(char s[],int lim){
    int c,i;
    for(i=0;i<lim - 1 && (c = getchar()) != EOF && c != '\n';++i){
        s[i] = c;
    }
    if(c == '\n'){
        s[i] = c;
        ++i;
    }
    // 作为字符串的结束符
    s[i] = '\0';
    return i;
}

// 将from复制到to
void copy(char to[],char from[]){
    int i;
    i = 0;
    while(from[i] != '\0'){
        to[i] = from[i];
        ++i;
    }
}

void a(){
    extern int global;
    global = global * 2;
}

void b(){
    extern int global;
    global = global * 3;
}

//将输入的\t替换为适当数目的空格，填充到下一个制表符终止位的地方，制表符终止位的位置固定，每隔TABSTOP出现一个
void detab(){
    int nc,c,offset;
    offset = 0;
    while((c = getchar()) != EOF){
        if(c == '\t'){
            nc = TABSTOPBIT - offset;
            for(int i=0;i<nc;++i){
                putchar(' ');
            }
            offset = 0;
        }else if(c == '\n'){
            offset = 0;
        }else {
            ++offset;
            putchar(c);
        }
    }
}

// 将空格串替换为最少数量的制表符和空格，保持单词间隔不变，制表符终止位与detab一致
void entab(){
    int nc,c,offset;
    offset = 0;
    while((c = getchar()) != EOF){
        if(c == ' '){
            while((c = getchar()) == ' ');
            nc = TABSTOPBIT - offset;
            for(int i=0;i<nc;++i){
                putchar(' ');
            }
            offset = 0;
        }else if(c == '\n'){
            offset = 0;
        }else {
            ++offset;
            putchar(c);
        }
    }
}

// 将较长的输入行在第n列之前的最后一个非空格之后进行拆分多行
void spitline(int n){
    int c,i;
    i = 0;
    while((c = getchar()) != EOF){
        if(i < n){
            ++i;
            putchar(c);
            if(c == ' ' || c == '\t'){
                while((c = getchar()) == ' ' || c == '\t'){
                    ++i;
                    putchar(c);
                }
                putchar(c);
                if(i == n-1){
                    putchar('\n');
                    i = 0;
                }
            }
        }else{
            putchar(c);
            i = 1;
        }
    }
}


//删除c语言中的注释  单行注释: //  多行注释: /**/
void delcomment(){
    int c;
    while((c = getchar()) != EOF){
        if(c == '/'){
            c = getchar();
            // 单行注释
            if(c == '/'){
                while((c = getchar()) != '\n');
            }else if(c == '*'){
                while((c = getchar()) != '/');
            }else{
                putchar(c);
            }
        }else {
            putchar(c);
        }
    }
}

int findendmark(char c,char end){
    if(c == end){
        return 0;
    }
    if(c == EOF){
        return -1;
    }
    if(c == '('){
        return findendmark(getchar(),')'); 
    }else if (c == '['){
        return findendmark(getchar(),']'); 
    }else if (c == '{'){
        return findendmark(getchar(),'}'); 
    }
    return findendmark(getchar(),end);
}

//语法检查 () [] {} 这几种括号配对检查
void syntaxcheck(){
    int c,tmp;
    while((c = getchar()) != EOF){
        if(c == '('){
            tmp = findendmark(getchar(),')'); 
        }else if (c == '['){
            tmp = findendmark(getchar(),']'); 
        }else if (c == '{'){
            tmp = findendmark(getchar(),'}'); 
        }
        
    }
    if(tmp == 0){
        printf("检查成功!\n");
    }else{
        printf("检查失败!您的程序存在语法错误\n");
    }
}

void data_type(){
    // 有符号整型
    signed char sc;
    signed short ss;
    signed int si;
    signed long sl;
    // 无符号整型
    unsigned char uc;
    unsigned short us;
    unsigned int ui;
    unsigned long ul;

    printf("%d\n",SCHAR_MAX);
    printf("%d\n",UCHAR_MAX);

}

//计算无符号数据类型最大值
unsigned long unsigned_data_type_max(int bit){

    return power(2,bit) - 1;
}

//枚举 未指定枚举名值则从0递增 依此类推，指定则从指定处开始往后依此类推
void enum_demo(){
    enum boolean {NO,YES};

    enum escapes {BEAL='\a', BACKSPACE='\b', TAB='\t', VTAB='\v'};

    enum months {JAN,FEB=7,MAR,AP=20,MAY,JUN};

    printf("%d\n",JUN);
}

// const限定符 该限定符指定的变量的值不能被修改。对于数组而言，const限定符指定数组所有元素的值都不能被修改
void const_demo(){
    const double d = 2.435435213;
    const char msg[] = "hello";
    printf("%f\n",d);
}

// 算符运算符
void arith_oper(){
    int x = 10;
    int y = 2;
    printf("%d\n",x + y);
    printf("%d\n",x - y);
    printf("%d\n",x * y);
    printf("%d\n",x / y);
    printf("%d\n",x % y);
}

void leap_year(int year){
    if((year % 4 == 0 && year % 100 != 0) || year % 400 ==0){
        printf("闰年\n");
    }else{
        printf("平年\n");
    }
}

// 将字符串转对应的整型数
int atoi(char s[]){
    int i,n;
    n = 0;
    for(i=0;s[i] >= '0' && s[i] <= '9';++i){
        n = 10 * n + (s[i] - '0');
    }
    return n;
}

// 将字符转为数字
int coverlower(char c){
    if(c >= '0' && c <= '9' ){
        return c - '0';
    }

    if(c >= 'a' && c <= 'f' ){
        return c - ('a' - 10);
    }

    if(c >= 'A' && c <= 'F' ){
        return c - ('A' - 10);
    }
    return -1;
}

int htoi(char s[]){
    int len,i,j,cl,n,p;
    len = strlength(s);
    n = 0;
    for(i=len - 1,j=0;i >= 0;--i,++j){
        cl = coverlower(s[i]);
        n = n + power(16,j) * cl;
    }
    return n;
}

// 字符串s1中任何与字符串s2中字符匹配的字符都删除
void squeeze(char s1[],char s2[]){
    int i,j,c,state;
    state = 0;
    c = 0;
    for(i=0; s1[i] != '\0';i++){
        for(j=0;s2[j] != '\0';j++){
            if(s1[i] == s2[j]){
                state = 1;
                break;
            }
        }
        if(state == 0){
            s1[c++] = s1[i];
        }else{
            state = 0;
        }
        
    }
    s1[c] = '\0';
    printf("%s\n",s1);
}

void any(char s1[],char s2[]){
    int i,j,c,state;
    state = 0;
    c = 0;
    for(i=0; s2[i] != '\0';i++){
        for(j=0;s1[j] != '\0';j++){
            if(s2[i] == s1[j]){
                state = 1;
                break;
            }
        }
        if(state == 0){
            s2[i] = '-'; 
            // printf("%d\n",-1);
        }else{
            s2[i] = j + '0';
            state = 0;
            // printf("%d\n",j);
        }
        
    }
    s2[i] = '\0';
    printf("%s\n",s2);
}

// 返回x从第p位开始的n个二进制位设置为y中最右边n位的值，x的其余各位保持不变  暂未实现
unsigned setbits(int x,int p,int n,int y){
    // 求出y最右边n位的值 并左移p位保持需要和x替换的部分对齐
    return x | ( (y & ~(~0 << n)) << (p+1-n));
}

// 求整数包含二进制1的个数
int bitcount(unsigned x){
    int c;
    // for(c=0;x != 0;x >>= 1){
    //     if(x & 01){
    //         c++;
    //     }
    // }
    while(x){
       c++;
       //该表达式可以删除最右边值为1的二进制 
       x &= (x-1);
    }
    return c;
}

// 将大写字母转为小写
void lower(char s[]){
    int i;
    for(i=0;s[i] != '\0';++i){
        s[i] = s[i] >= 'A' && s[i] <= 'Z' ? s[i] + 32 : s[i];
    }
    printf("%s\n",s);
}

// 折半查找 v数组有序 查找v数组中和x值相同的数组下标  n表示数组长度
int binsearch(int x,int v[],int n){
    int low,high,mid;
    low = 0;
    high = n-1;
    mid = (low + high) / 2;
    while(low <= high){
        if(v[mid] > x){
            high = mid - 1;
        }else if(v[mid] < x){
            low = mid + 1;
        }else{
            return mid;
        }
    }
    return -1;
}

void switch_demo(char s[]){
    int i;
    for(i=0;s[i] != '\0';++i){
        switch(s[i]){
            case '0': case '1':
                printf("数字\n");
                break;
            case ' ':
                printf("空格\n");
                break;
            default:
                printf("啥也不是\n");
                break;
        }
    }
    
}

// 数字转为字符串
void itoa(int n,char s[]){
    int i,c;
    if( (c = n) < 0){
        n = ~n;
    }
    i = 0;
    do{
        s[i++] = n % 10 + '0';
    }while((n /= 10) > 0);
    reverse(s);
    printf("%s\n",s);
}

int itoai = 0;
// 递归数字转字符串 123456
void itoa_recursio(int n,char s[]){
    if(n / 10 > 0){
        itoa_recursio(n/10,s);
    }
    s[itoai++] = n % 10 + '0';
}

void itob(int n,char s[],int b){
    char e[32];
    int i,m;
    i = 0;
    do{
        m = n % 2; 
        e[i++] = m + '0';
    }while((n /= 2) != 0);
    e[i] = '\0';
    reverse(e);
    printf("%s\n",e);
}

int trim(char s[]){
    int n;
    for(n=strlen(s)-1;n>=0;--n){
        if(s[n] != '\t' && s[n] != '\n' && s[n] != ' '){
            break;
        }
    }
    s[n+1] = '\0';
    printf("%s\n",s);
    return n;
}

void goto_demo(){
    for(int i=0;i<10;++i){
        if(i == 4){
            goto test;
        }
    }
    test:
    printf("goto测试\n");
}

// 读取一行
int getline2(char s[],int lim){
    int c,i;
    i = 0;
    while(--lim > 0 && (c = getchar()) != EOF && c != '\n'){
        s[i++] = c;
    }
    if(c == '\n'){
        s[i++]  = c;
    }
    s[i] = '\0';
    return i;
}

//返回字符串t在字符串s出现的其实位置或索引，当s不包含t时返回-1
int strindex2(char s[],char t[]){
    int i,j,k;
    for(i=0;s[i] != '\0';++i){
        for(j=i,k=0;t[k] != '\0' && s[j] == t[k];++j,++k)
            ;
        if(t[k] == '\0' && k > 0){
            return j-1;
        }
    }
    return -1;
}

// 将字符串转double  例如    -6345.2387e-6
double aotf(char s[]){
    int i,sign,k;
    double var,power;
    //跳过空格
    for(i=0;s[i]==' ';i++)
        ;
    // 正负
    sign = s[i] == '-' ? -1 : 1;
    if(s[i] == '+' || s[i] == '-'){
        i++;
    }
    for(var = 0.0;isdigit(s[i]);i++){
        var = 10.0 * var + (s[i] - '0');
    }
    if(s[i] == '.'){
        i++;
    }
    for(power = 1.0;isdigit(s[i]);i++){
        var = 10.0 * var + (s[i] - '0');
        power *= 10.0;
    }
    //兼容科学计数
    if(s[i] == 'e'){
        i++;
    }
    if(s[i] == '-'){
        i++;
        k = s[i] - '0';
        for(;k > 0;k--){
            power *= 10.0;
        }
    }else{
        i++;
        k = s[i] - '0';
        for(;k > 0;k--){
            power /= 10.0;
        }
    }
    return sign * var / power;
}

// 静态变量
void static_demo(int x){
    static int i;
    if(i == 0){
        i = 10;
    }
    char c[] = {'a','b'};
    
    printf("%d\n",i);
}

// 寄存器变量
void register_demo(register int x){
    register char c = 'd';
    printf("%d %c\n",x,c);
}

// 打印十进制 比如123 打印 1  2  3
void printd(int n){
    if(n < 0){
        putchar('-');
        n = -n;
    }
    if(n / 10 > 0){
        printd(n/10);
    }
    putchar(n % 10 + '0');
    putchar('\t');
}

// 交换两个元素
void swap(int v[],int x,int y){
    int tmp =  v[x];
    v[x] = v[y];
    v[y] = tmp;
}

void qsort2(int v[],int left,int right){
    if(left >= right){
        return;
    }
    // 取数组第一个元素作为基准数
    int p = v[left];
    int i = left;
    int j = right;
    while(i < j){
        /**
         * 从右往左找到第一个比基准数小的  如果选取的基准数是最左边  则必须先从右往左开始，可以确保找到的数肯定比基准数小
         * 比如 1 2 4 9  如果先从左边开始则找到第一个比基准数大的为4 那么右边因为有i<j的限制也会指向4 这样右边找到的数就不比基准数小了
        */
        while(v[j] >= p && i<j){
            j--;
        }
        // 从左往右找到第一个比基准数大的
        while(v[i] <= p && i<j ){
            i++;
        }
        //找到后交换
        swap(v,i,j);
    }
    //将基准数转移 使左边都比基准数小  右边都比基准数大
    swap(v,left,i);
    // 重复左侧
    qsort2(v,left,i-1);
    // 重复右侧
    qsort2(v,i+1,right);

}


// int main(){
//     // printf("Hello Word\n");

//     // fahrToCelsius();

//     // celsiusToFahr();

//     // int m = power(2,30);

//     // char line[MAXLINE];
//     // char longset[MAXLINE];
//     // int len,max;
//     // max = 0;
//     // while((len = getlinelen(line,MAXLINE)) > 0){
//     //     if(len > max){
//     //         max = len;
//     //         copy(longset,line);
//     //     }
//     // }
//     // if(max > 0){
//     //     printf("%s",longset);
//     // }

//     // printf("%d\n",global);
//     // a();
//     // printf("%d\n",global);
//     // b();
//     // printf("%d\n",global);

//     // entab();

//     // spitline(3);

//     // syntaxcheck();

//     // long max = unsigned_data_type_max(32);
//     // printf("%u\n",max);
//     // printf("%u\n",UINT_MAX);
//     // printf("%u\n",ULONG_MAX);

//     // arith_oper();

//     // leap_year(2025);

//     // int valid = 0;
//     // if(!valid){
//     //     printf("真\n");
//     // }

//     // char s[] = "345123";
//     // int ai = atoi(s);
//     // printf("%d\n",ai);

//     // int d,c;
//     // c = 'a';
//     // d = c >= '0' && c <= '9';
//     // printf("%d\n",d);

//     // while(0){
//     //     printf("循环\n");
//     // }

//     // int i = 200;
//     // char c = 100;
//     // c = i;
//     // i = c;
//     // char c = (char) i;
//     // printf("%d\n",c);

//     // char s[] = "ff";
//     // int h = htoi(s);
//     // printf("%d\n",h);

//     // int i = 0;
//     // char s[] = "123";
//     // printf("%d\n",s[i++] - '0');

//     // char s1[] = "abgcdefg";
//     // char s2[] = "kogap";
//     // any(s1,s2);

//     // int i = setbits(73,5,3,23);

//     // int c=bitcount(15);
//     // printf("%d\n",c);

//     // char s[] = "AbasdDASDasd";
//     // lower(s);

//     // int v[10];
//     // for(int i=0;i<10;++i){
//     //     v[i] = i;
//     // }
//     // int b = binsearch(4,v,10);
//     // printf("%d\n",b);

//     // char s[] ="1sad 0dsad";

//     // switch_demo(s);

//     // char s[] = "1229";
//     // int a = atoi(s);
//     // printf("%d\n",a);

//     // int min = -power(2,31);
//     // printf("%d\n",min);
//     // char s[10];
//     // itoa(min,s);

//     // char s[32];
//     // itob(10,s,16);
    
//     // char s[]= "abchasd    sad ad     \
//     // ";
//     // int l = trim(s);
//     // printf("%d\n",l);

//     // goto_demo();
//     // char t[] = "ys";
//     // int i;
//     // int lim = 1000;
//     // char s[lim];
//     // while(getline2(s,lim) > 0){
//     //     if((i=strindex2(s,t)) > 0){
//     //         printf("%s",s);
//     //         printf("出现的位置: %d\n",i);
//     //     }
//     // }
//     // double aotf(char []);

//     // char s[]="123.456e+3";
//     // double d = aotf(s);

//     // for(int i=0;i<2;++i){
//     //     static_demo(i);
//     // }

//     int x[8] = {32,91,4,76,45,123,9,76};
//     qsort2(x,0,7);
//     for(int i=0;i<8;++i){
//         printf("%d\t",x[i]);
//     }
//     printf("\n");

//     // char c[] ="yanshuai hello";
//     // reverse_recursion(c);
//     // int x = 123456;
//     // char s[100];
//     // itoa_recursio(x,s);
//     // printf("%s\n",s);
    
//     return 0;
// }