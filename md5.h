/*
函数使用说明：
先调用MD5Init初始化一个MD5_CTX类型结构体，再使用MD5Update计算MD5码，最后调用MD5Final获取
使用示例见最下面的main函数。
*/
#ifndef _MD5_H_
#define _MD5_H_

#include<string.h>
#include<stdio.h>
#include <stdlib.h>
typedef unsigned char *POINTER; //指针类型定义
typedef struct {
  unsigned int state[4];                                   /* A,B,C,D四个常数 */
  unsigned int count[2];        /* 数据的bit数计数器(对2^64取余) */
  unsigned char buffer[64];                         /* 输入数据缓冲区 */
} MD5_CTX; //存放MD5算法相关信息的结构体定义

void MD5Init (MD5_CTX *);
void MD5Update(MD5_CTX *, unsigned char *, unsigned int);
void MD5Final(unsigned char [16], MD5_CTX *);
void MD5Transform(unsigned int [4], unsigned char [64]);
void Encode(unsigned char *, unsigned int *, unsigned int);
void Decode(unsigned int *, unsigned char *, unsigned int);
void cal_md5(const char *str,unsigned char *md5sum);

//循环左移的位数
#define S11 7
#define S12 12
#define S13 17
#define S14 22
#define S21 5
#define S22 9
#define S23 14
#define S24 20
#define S31 4
#define S32 11
#define S33 16
#define S34 23
#define S41 6
#define S42 10
#define S43 15
#define S44 21



//F,G,H,I四个非线性变换函数
#define F(x, y, z) (((x) & (y)) | ((~x) & (z)))
#define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
#define H(x, y, z) ((x) ^ (y) ^ (z))
#define I(x, y, z) ((y) ^ ((x) | (~z)))

//x循环左移n位的操作
#define ROTATE_LEFT(x, n) (((x) << (n)) | ((x) >> (32-(n))))

//FF,GG,HH,II是四轮循环变换分别用到的变换函数
#define FF(a, b, c, d, x, s, ac) { \
 (a) += F ((b), (c), (d)) + (x) + (unsigned int)(ac); \
 (a) = ROTATE_LEFT ((a), (s)); \
 (a) += (b); \
  }
#define GG(a, b, c, d, x, s, ac) { \
 (a) += G ((b), (c), (d)) + (x) + (unsigned int)(ac); \
 (a) = ROTATE_LEFT ((a), (s)); \
 (a) += (b); \
  }
#define HH(a, b, c, d, x, s, ac) { \
 (a) += H ((b), (c), (d)) + (x) + (unsigned int)(ac); \
 (a) = ROTATE_LEFT ((a), (s)); \
 (a) += (b); \
  }
#define II(a, b, c, d, x, s, ac) { \
 (a) += I ((b), (c), (d)) + (x) + (unsigned int)(ac); \
 (a) = ROTATE_LEFT ((a), (s)); \
 (a) += (b); \
  }
#endif