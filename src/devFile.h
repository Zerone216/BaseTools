/****************************************************************************************************************************
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
