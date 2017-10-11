//
//  main.cpp
//  StringConvert
//
//  Created by apple on 2017/10/11.
//  Copyright © 2017年 apple. All rights reserved.
//
/*
 
 题目:
 
 给定字符串，要求字符串前面的若干个字符移动到字符串的尾部，例如 abcdef 前三个字符 abc 一到尾部。变成 defabc
 
 */

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}



#pragma mark - 蛮力移位

/*
 
 假设需要移动 m 个字符 总共需要 m *n 次操作。同时设立一个变量保存第一个字符。因此，时间复杂度 O(mn), 空间复杂度 O(1)
 
 */

// 移动一位
void LeftShiftOne(char* s, int n) {
    char t = s[0];
    for (int i = 1; i < n; i++) {
        s[i - 1] = s[i];
    }
    s[n - 1] = t;
}

// 调用移动一位的 m 次
void LeftRotateString(char* s, int n, int m) {
    while (m--) {
        LeftShiftOne(s, n);
    }
}



#pragma mark - 三步反转

/*
 
 1. 将字符串分为 X, Y 两部分。 X abc, Y def
 2. 将 X 的所有字符反转 abc 得到 cba, Y 的所有字符反转 def 得到 fed
 3. 最后将上述得到的结果在整体反转。 cbafed 得到 defabc
 
 时间复杂度 O(n), 空间复杂度 O(1)
 */

void ReverseString(char* s, int from, int to) {
    while (from < to) {
        char t = s[from];
        s[from++] = s[to];
        s[to--] = t;
    }
}

void LeftRotateString2(char* s, int n, int m) {
    m %= n;
    ReverseString(s, 0, m - 1);
    ReverseString(s, m, n - 1);
    ReverseString(s, 0, n - 1);
}
