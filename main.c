#include "include/add.h"

int main()
{
    int flag=1;
    while(flag){
    int item;
    printf("----------------------------------\n");
    printf("*******菜单选择********\n");
    printf("*******1.课程模块*******\n");
    printf("*******2.学生模块*******\n");
    printf("*******3.退  出*********\n");
    printf("-----------------------------\n");
    printf("输入你想要选择的菜单:");
        scanf("%d",&item);
    switch(item){
    case 1: 
            course(); 
            break;
    case 2:
            student();
            break;
    case 3:
           flag=0;
           printf("退出成功!!\n");
             break;
    }
   
    }
    return 0;
}

