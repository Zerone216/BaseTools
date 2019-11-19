/****************************************************************************************************************************
*   文 件 名 ： devFile.cpp 
*   文件描述 ：  
*   创建日期 ：2019年9月27日
*   版本号 ：   
*   负责人 ： Zhangsheng 
*   其 他 ：
*   修改日志 ：
*
****************************************************************************************************************************/

#include <iostream>
#include <string>

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include "devFile.h"

#if !defined(_LARGEFILE64_SOURCE)
#define devseek(fd, offset, whence) lseek(fd, offset, whence)
#else
#define devseek(fd, offset, whence) lseek64(fd, offset, whence)
#endif

DevFile::DevFile(std::string devname) :
	devName(devname), rwMode(O_RDWR), sectorSize(512)
{
}


DevFile::DevFile(std::string devname, int rwmode) :
	devName(devname), rwMode(rwmode), sectorSize(512)
{
}


DevFile::DevFile(std::string devname, int rwmode, int sectorsize):
	devName(devname), rwMode(rwmode), sectorSize(sectorsize)
{
}

void DevFile::devOpen()
{
	devfd = open(devName.c_str(), rwMode);
}

void DevFile::devClose()
{
	close(devfd);
}


unsigned long long DevFile::devLseek(unsigned long long offset)
{
	curPosition = devseek(devfd, defaultOffset + offset, SEEK_SET);
	return curPosition;
}

unsigned long long DevFile::devLseek(unsigned long long offset, int whence)
{
	if(whence == SEEK_SET)
		curPosition = devseek(devfd, defaultOffset + offset, SEEK_SET);
	else
		curPosition = devseek(devfd, offset, whence);
	
	return curPosition;
}

unsigned long long DevFile::devTell()
{
	return curPosition;
}

int DevFile::devRead(unsigned long long offset, unsigned int size, unsigned char * buf)
{
	if(devLseek(offset) < 0)
		return -1;

	return read(devfd, buf, size);
}

int DevFile::devWrite(unsigned long long offset, unsigned int size, unsigned char * buf)
{
	if(devLseek(offset) < 0)
		return -1;
	
	return write(devfd, buf, size);
}

int DevFile::devReadSector(unsigned long long startSec, unsigned int secNum, unsigned char * buf)
{
	return devRead(startSec * sectorSize, secNum * sectorSize, buf);
}

int DevFile::devWriteSector(unsigned long long startSec, unsigned int secNum, unsigned char * buf)
{
	return devWrite(startSec * sectorSize, secNum * sectorSize, buf);
}

int DevFile::devInit(unsigned long long offset)
{
	defaultOffset = offset;
	devOpen();
	devSize = devLseek( 0 , SEEK_END); //获取设备大小
	devLseek(0 , SEEK_SET);

	return 0;
}

void DevFile::devRelease()
{
	devClose();
}
