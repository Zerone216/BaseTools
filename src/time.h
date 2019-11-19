/****************************************************************************************************************************
*
*   文 件 名 ： time.h 
*   文件描述 ：  
*   创建日期 ：2019年10月8日
*   版本号 ：   
*   负责人 ： Zhangsheng 
*   其 他 ：
*   修改日志 ：
*
****************************************************************************************************************************/

#ifndef __TIME_H__
#define __TIME_H__

#include <iostream>
#include <ctime>
#include <string>

class Time
{
private:
	struct tm TimeStruct;
	std::string TimeString;
	time_t TimeStamp;
	
public:
	Time();
	Time(std::string timeExp);
	Time(time_t utcTime);
	
	~Time();
};


#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __TIME_H__ */
