/**
* 实例chapter2501
* 源文件chapter2501.cpp
* 共享内存创建应用实例
*/
#include <iostream>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
using namespace std;
#ifndef 	SHM_FAILED					//定义方法调用出错常量符号
#define 	SHM_FAILED -1
#endif
#define FLAG IPC_CREAT|IPC_EXCL|SHM_R|SHM_W 		       //定义共享内存创建标志
//内存数据记录结构定义
typedef struct
{
	int id;							//数据编号
	char data[100];						//具体数据空间定义
}recordData;

int main()
{
	int shmid;						//共享内存描述符
	recordData *memoryAddr;					//记录结构指针对象
	shmid = shmget(0x00000003,10*1024,FLAG);		//共享内存创建方法调用，返回值初始化描述符
	if(shmid == SHM_FAILED)					//判断创建工作是否成功
	{
		cout<<"share memory create fail!"<<endl;	//不成功则打印输出提示信息
		exit(1);					//退出进程
	}
	memoryAddr = (recordData*)shmat(shmid,NULL,0);		//进程attach到共享内存，获取其操作首地址
	char temp;						//定义字符临时变量
	temp = 65;						//为该变量初始化ASCII值
	for(int i = 0;i < 5;i++)				//循环写入数据
	{
		memcpy((*(memoryAddr+i)).data,&temp,1);		//拷贝数据进入共享内存
		(*(memoryAddr+i)).id = i;					//数据id赋值
		++temp;								//递增temp值
	}
	if(shmdt(memoryAddr) !=0)						//操作完毕后detach共享内存
	{
		cout<<"share memory detach fail!"<<endl;			//执行失败提示信息
		exit(1);  							//退出进程
	}
	return 0;
}
