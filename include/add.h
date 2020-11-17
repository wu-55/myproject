#ifndef _ADD_H
#define _ADD_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 50
struct course{
char bianhao[20];
char name[20];
int time;
int score;
int pickp;
int numpeople;
}cour[N];

struct student{
char id[20];
char name[20];
char list[20];
int score;
}stu[N];
int m=0,n=0;//学生人数
int a=0,b=0;//课程数
void add(){
  int flag,j,i=b;
    printf("输入添加的课程数:\n");
    scanf("%d",&a);
    if(a>0){ 
    do{
            flag=1;
            while(flag)
            {   flag=0;
                printf("输入第%d课程编号:\n",i+1);
                scanf("%s",cour[i].bianhao);
                for(j=0;j<i;j++){
                    if(strcmp(cour[j].bianhao,cour[i].bianhao)==0){
                        printf("该课程已经存在,重新输入\n");
                        flag=1;
                        break;
                }
            }       
        }
            printf("输入第%d门课程名：\n",i+1);
            scanf("%s",cour[i].name);
            printf("输入第%d课程学时:\n",i+1);
            scanf("%d",&cour[i].time);
            printf("输入第%d门课程学分：\n",i+1);
            scanf("%d",&cour[i].score);
            printf("输入第%d门人数上限：\n",i+1);
            scanf("%d",&cour[i].numpeople);
            if(flag==0){
                i++;
            }
        }while(i<a+b);
    }
    b=b+a;
    printf("课程信息增加完毕!\n");
}
void display(){
    int i;
    printf("共有%d位学生信息:\n",b);
    if(b!=0){
        printf("课程编号\t课程名称\t学时\t学分\t人数上限\n");
       printf("--------------------------------------------------------\n");
       for(i=0;i<b;i++){
           printf("  %s\t\t%s\t\t%d\t%d\t%d\n",cour[i].bianhao,cour[i].name,cour[i].time,cour[i].score,cour[i].numpeople);
       }
       printf("---------------------------------------------------------\n");
    }
}
void seek(){
    int i,item,flag;
    char s1[20];
    printf("------------------\n");
	printf("-----1.按课程编号查询-----\n");
	printf("-----2.按课程名称查询-----\n");
	printf("-----3.退出本菜单-----\n");
	printf("------------------\n");
    printf("输入编号：");
    scanf("%d",&item);
    switch(item){
    case 1:
        printf("输入你想查找的课程编号:\n");
        scanf("%s",s1);
        for(i=0;i<b;i++){
            if(strcmp(cour[i].bianhao,s1)==0){
            flag = 1;
				printf("课程编号\t课程名\t学时\t学分\t已选人数\t人数上限\n");
				printf("--------------------------------------------------------------------\n");
				printf("  %s\t\t%s\t\t%d\t\t%d\t%d\t%d\n", cour[i].bianhao,cour[i].name,cour[i].time,cour[i].score,cour[i].pickp,cour[i].numpeople);
			}
			if (0 == flag)
				printf("该课程不存在！\n"); break;
		case 2:
			printf("请输入要查询的课程名:\n");
			scanf("%s", s1);
			for (i = 0; i<b; i++)
			if (strcmp(cour[i].name, s1) == 0)
			{
				flag = 1;
			    printf("课程编号\t课程名\t学时\t学分\t已选人数\t人数上限\n");
                printf("--------------------------------------------------------------------\n");
                printf("  %s\t\t%s\t\t%d\t\t%d\t%d\t%d\n", cour[i].bianhao,cour[i].name,cour[i].time,cour[i].score,cour[i].pickp,cour[i].numpeople);

            }
			if (0 == flag)
				printf("该课程名不存在！\n"); break;
		case 3:return;
        }
    }
}
void modify(){
    int i,num,item;
    char s1[20];
    int newtime=0,newscore=0,newnumpeople=0;
    FILE *fp=fopen("../build/studentmodify.log","a+");
    printf("请输入你想修改的课程编号:\n");
    scanf("%s",s1);
    for(i=0;i<b;i++){
        if(strcmp(cour[i].bianhao,s1)==0){
            num=i;
            printf("欢迎进入修该系统！\n");
            printf(" 1.修改课程学时\n 2.修改课程学分\n 3.修改人数上限\n 4.返回菜单\n");
        while(1)
        {
            printf("输入菜单选项:\n");
            scanf("%d",&item);
            switch(item){
            case 1:
                  printf("输入新的学时:\n");
                  scanf("%d",&newtime);
                  cour[num].time=newtime;
                  fprintf(fp,"你修改了课程号为 %s 的学时\n",cour[num].bianhao);
                  fclose(fp);
                  break;
            case 2:
                 printf("输入新的学分：\n");
                 scanf("%d",&newscore);
                 cour[num].score=newscore;
                 fprintf(fp,"你修改了课程号为 %s 的学分\n",cour[num].bianhao);
                 fclose(fp);
                 break;
        case 3:
            printf("输入新的人选上限:\n");
            scanf("%d",&newnumpeople);
            cour[num].numpeople=newnumpeople;
            fprintf(fp,"你修改了课程号为 %s 的人选上限\n",cour[num].bianhao);
            fclose(fp);
            break;
        case 4:
            return;                    
            }
}
printf("修改完毕!\n");
}else{
    printf("没有该课程号!\n");
}
}
}

void del(){
    int i,j,flag=0;
    char s1[20];
    printf("输入想要删除的课程号:\n");
    scanf("%s",s1);
    for(i=0;i<b;i++){
        if(strcmp(cour[i].bianhao,s1)==0){
            flag=1;
            for(j=i;j<b-1;j++){
                cour[j]=cour[j+1];
            }
        }
    }
    if(flag==0){
        printf("该课程号不存在!\n");
    }
    if(flag==1){
        printf("删除成功！\n");
        n--;
    }
}
void save(){
    int i;
    FILE *fp;
    fp=fopen("course.txt","a+");
    for(i=0;i<b;i++){
        fprintf(fp,"%s\t%s\t%d\t%d\t%d\t%d\n",cour[i].bianhao,cour[i].name,cour[i].time,cour[i].score,cour[i].pickp,cour[i].numpeople);
    }
    printf("保存成功!\n");
    fclose(fp);
}
void readcourse(){
  char str[1024];
  int len;
  FILE *fp=fopen("course.txt","r");
  printf("课程编号\t课程名称\t学时\t学分\t已选人数\t人数上限\n");
  while(fgets(str,1024,fp)!=NULL){
    len=strlen(str);
    str[len-1]='\0';
    printf("%s\n",str);
  }
  printf("--------------------------------------\n");
  fclose(fp);
}
void course(){
int flag=1,num;
   while(flag){
    printf("     * 1.查询课程信息    * *  2.修改课程信息   *     \n");
	printf("     *********************************************     \n");
	printf("     * 3.增加课程信息    * *  4.删除课程 *     \n");
	printf("     *********************************************     \n");
	printf("     * 5.显示当前信息    * *  6.保存信息*     \n");
	printf("     ********************** **********************     \n");
	printf("     * 7.文本读取        * *  8.退出系统*      \n");
    printf("     **********************                            \n");
	printf("     ----------------------   ---------------------- \n");
	printf("请选择菜单编号:");
     scanf("%d",&num);
    switch(num){
     case 1:seek();break;
     case 2:modify();break;
     case 3:add();break;
     case 4:del();break;
     case 5:display();break;
     case 6:save();break;
     case 7:readcourse();break;
     case 8:
         flag=0;
         printf("退出系统!\n");
         break;
    }
   }

}
void insert(){
    int i=n,j,flag;
    printf("请输入增加的学生数:\n");
    scanf("%d",&m);
    if(m>0){
        do{
            flag=1;
            while(flag){
                flag=0;
                printf("请输入第%d位学生的学号:\n",i+1);
                scanf("%s",stu[i].id);
                for(j=0;j<i;j++){
                    if(strcmp(stu[i].id,stu[j].id)==0){
                        printf("该学号已经存在，请重新输入！\n");
                        flag=1;
                        break;
                    }
                }
            }
            printf("请输入第%d 个学生的姓名:\n", i+1);
			scanf("%s", stu[i].name);
            printf("请输入第%d个学生选课列表:\n",i+1);
            scanf("%s",stu[i].list);
            printf("请输入第%d个学生的学分:\n",i+1);
            scanf("%d",&stu[i].score);
            if(flag==0){
                i++;
            }
        }while(i<n+m);
    }
    n+=m;
    printf("添加完毕!!\n");
}
void save1(){
    int i;
    FILE *fp;
    fp=fopen("student.txt","a+");
    for(i=0;i<n;i++){    
        fprintf(fp,"%s\t%s\t%s\t%d\n",stu[i].id,stu[i].name,stu[i].list,stu[i].score);
    }
    printf("\n");
    printf("保存成功!\n");
    fclose(fp);
}

void display1(){
    int i;
    printf("共有%d位学生信息：\n",n);
    if(n!=0){
        printf("学号\t姓名\t选课列表\t学分\n");
        for(i=0;i<n;i++){
            printf("  %s\t%s\t%s\t%d\n",stu[i].id,stu[i].name,stu[i].list,stu[i].score);
        }
        printf("---------------------------------------------------------------------\n");
    }
}
void seek1(){
    int i,item,flag;
    char s1[20];
    printf("------------------\n");
	printf("-----1.按学号查询-----\n");
	printf("-----2.按姓名查询-----\n");
	printf("-----3.退出本菜单-----\n");
	printf("------------------\n");
	while (1)
	{
		printf("请选择子菜单编号:");
		scanf("%d", &item);
		flag = 0;
		switch (item)
		{
		case 1:
			printf("请输入要查询的学生的学号:\n");
			scanf("%s", s1);
			for (i = 0; i<n; i++)
            {
			    if (strcmp(s1,stu[i].id) == 0)
			    {
				    flag = 1;
                    printf("学号\t姓名\t选课列表\t学分\n");
                    printf("----------------------------------\n");
                    printf("  %s\t%s\t%s\t%d\n",stu[i].id,stu[i].name,stu[i].list,stu[i].score);
                }
            
                if(flag==0){
                    printf("该学号不存在!\n");break;
                    }    
            };break;
        
        case 2:
            printf("输入想要查询的学生姓名:\n");
            scanf("%s",s1);
            for(i=0;i<n;i++)
            {
                if(strcmp(stu[i].name,s1)==0)
                {
                    flag=1;
                    printf("学号\t姓名\t选课列表\t学分\n");
                    printf("----------------------------------\n");
                    printf("  %s\t%s\t%s\t%d\n",stu[i].id,stu[i].name,stu[i].list,stu[i].score);
                }
                if(flag==0){
                    printf("该姓名不存在!\n");break;
                    }
                };break;
        case 3:return;
            }
}
}
void modify1(){
    int i,num,item;
    char s1[20],s2[20],s3[20];
    int newscore;
    FILE *fp=fopen("../build/studentmodify.log","a+");
    printf("输入要修改的学生的学号:\n");
    scanf("%s",s1);
    for(i=0;i<n;i++){
        if(strcmp(stu[i].id,s1)==0){
                num=i;
               printf("欢迎进入修改系统!\n");
               printf("1.修改姓名\n");
               printf("2.修改已选课程列表\n");
               printf("3.修改学分\n");
               printf("4.返回菜单\n");
               while(1){
                   printf("输入菜单选项:\n");
                   scanf("%d",&item);
                   switch(item){
                   case 1:
                       printf("输入新的姓名:\n");
                       scanf("%s",s2);
                       strcpy(stu[num].name,s2);
                       fprintf(fp,"你修改了学号为%s学生的姓名\n",stu[num].id);
                       fclose(fp);
                       break;
                   case 2:
                       printf("输入新的已选课程列表:\n");
                       scanf("%s",s3);
                       strcpy(stu[num].list,s3);
                       fprintf(fp,"你修改了学号为%s学生的已选课程列表\n",stu[num].id);
                       fclose(fp);
                        break;
                   case 3:
                        printf("输入新的学分:\n");
                        scanf("%d",&newscore);
                        stu[num].score=newscore;
                        fprintf(fp,"你修改了学号为%s学生的学分\n",stu[num].id);
                        fclose(fp);
                        break;
                   case 4:
                        return;
                   }
               }
               printf("修改完毕!\n");
        }
        else{
            printf("没有该学号！\n");
        }
    }
}



void del1(){
    int i,j,flag=0;
    char s1[20];
    printf("输入想要删除的学号:\n");
    scanf("%s",s1);
    for(i=0;i<n;i++){
        if(strcmp(stu[i].id,s1)==0){
            flag=1;
            for(j=i;j<n-1;j++){
                stu[j]=stu[j+1];
            }
        }
    }
    if(flag==0)
    {
        printf("该学生不存在!\n");
    }
    if(flag==1){
        printf("删除成功!");
        n--;
    }
}
void readstudent(){
    char str1[1024];
    FILE *fp=fopen("student.txt","r");
    int len;
    printf("学号\t姓名\t已选课程列表\t学分\n");
    while(fgets(str1,1024,fp)!=NULL){
            len=strlen(str1);
            str1[len-1]='\0';
            printf("%s\n",str1);
    }
    printf("------------------------------------\n");
    fclose(fp);
}
void student(){
int flag=1,num;
   while(flag){
    printf("     * 1.查询学生信息    * *  2.修改学生信息   *     \n");
	printf("     *********************************************   \n");
	printf("     * 3.增加学生信息    * *  4.按学号删除信息 *     \n");
	printf("     *********************************************   \n");
	printf("     * 5.显示当前信息    * *  6.保存当前学生信息*    \n");
	printf("     ********************** **********************   \n");
	printf("     * 7.文件读取        * *  8.退出系统       *     \n");
    printf("     *********************************************   \n");
	printf("     ----------------------   ---------------------- \n");
	printf("请选择菜单编号:");
     scanf("%d",&num);
    switch(num){
     case 1:seek1();break;
     case 2:modify1();break;
     case 3:insert();break;
     case 4:del1();break;
     case 5:display1();break;
     case 6:save1();break;
     case 7:readstudent();break;
     case 8:
         flag=0;
         printf("退出系统!\n");
         break;
    }
   }
}

#endif

