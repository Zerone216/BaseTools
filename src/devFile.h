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
*   文 件 名 ： devFile.h 
*   文件描述 ：  
*   创建日期 ：2019年9月27日
*   版本号 ：   
*   负责人 ： Zhangsheng 
*   其 他 ：
*   修改日志 ：
*
****************************************************************************************************************************/

#ifndef __DEVFILE_H__
#define __DEVFILE_H__

#pragma once
#include <iostream>
#include <string>

#include <map>

class DevFile
{	
public:
	DevFile(std::string devname);
	
	DevFile(std::string devname, int rwmode);
	
	DevFile(std::string devname, int rwmode, int sectorsize);

	~DevFile();
	
	std::string getDevName(){return devName;}
	int getDevfd(){return devfd;}
	
	void devOpen();
	
	void devClose();
	
	unsigned long long devLseek(unsigned long long offset);
	
	unsigned long long devLseek(unsigned long long offset, int whence);

	unsigned long long devTell();
	
	int devRead(unsigned long long offset, unsigned int size, unsigned char * buf);
	
	int devWrite(unsigned long long offset, unsigned int size, unsigned char * buf);
	
	int devReadSector(unsigned long long startSec, unsigned int secNum, unsigned char * buf);
	
	int devWriteSector(unsigned long long startSec, unsigned int secNum, unsigned char * buf);
	
	int devInit(unsigned long long offset);
	
	void devRelease();
	
private:
	std::string devName;
	int rwMode;
	int sectorSize;
	
	int devfd;
	unsigned long long defaultOffset;
	unsigned long long devSize;
	unsigned long long curPosition;
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


#endif /* __DEVFILE_H__ */
