#!/bin/bash
tar -zcvf studentmodify.log.tar.gz  studentmodify.log
cp studentmodify.log.tar.gz /home/wu/test
read -p "输入选择:1.统计用户修改信息   2.统计课程修改信息"  id
if [ $id -eq 1 ]
then
    read -p "输入学号:" num
    a=$(grep "${num}" studentmodify.log | wc -l)
    echo "此用户修改了$a 次!"
else
    read -p "输入课程号:" cournum
    b=$(grep "${cournum}" studentmodify.log| wc -l)
    echo "该课程被修改了 $b 次！"
fi



echo "********************************************"
echo "********************************************"
echo "查看修改记录"

read -p "输入选择:1.输入学号查看修改记录 2.输入课程号查看修改记录 "  modify
if [ $modify -eq 1 ]
then
   read -p "输入学号" schoolnum
   grep "${schoolnum}" studentmodify.log
else
    read -p "输入课程号" coursenum
    grep "${coursenum}" studentmodify.log
    
fi

