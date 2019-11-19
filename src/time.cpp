/****************************************************************************************************************************
*
*   文 件 名 ： time.cpp 
*   文件描述 ：  
*   创建日期 ：2019年10月8日
*   版本号 ：   
*   负责人 ： Zhangsheng 
*   其 他 ：
*   修改日志 ：
*
****************************************************************************************************************************/
#include <iostream>
#include <ctime>
#include <string>

#include "time.h"

Time::Time()
{
	TimeStamp = time(0);
}

Time::Time(std::string timeExp)
{
	TimeString = timeExp;
}

Time::Time(time_t utcTime)
{
	TimeStamp = utcTime;
}
