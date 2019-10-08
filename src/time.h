/****************************************************************************************************************************
*
*	Copyright (c) 1998-2019  XI'AN SAMING TECHNOLOGY Co., Ltd
*	西安三茗科技股份有限公司  版权所有 1998-2019 
*
*   PROPRIETARY RIGHTS of XI'AN SAMING TECHNOLOGY Co., Ltd are involved in  the subject matter of this material.       
*   All manufacturing, reproduction,use, and sales rights pertaining to this subject matter are governed bythe license            
*   agreement. The recipient of this software implicitly accepts the terms of the license.	
*
*   本软件文档资料是西安三茗科技股份有限公司的资产,任何人士阅读和使用本资料必须获得相应的书面
*   授权,承担保密责任和接受相应的法律约束. 								     
*
*----------------------------------------------------------------------------------------------------------------------------
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
