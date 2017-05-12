#include <wiiu/os.h>
#include <wiiu/fs.h>
#include <wiiu/gx2.h>
#include <wiiu/sys.h>
#include <wiiu/vpad.h>
#include <wiiu/syshid.h>
#include <wiiu/padscore.h>
#include <wiiu/socket.h>
#include <wiiu/curl.h>
#include <wiiu/ax.h>
#include <fs/fs_utils.h>
#include <fs/sd_fat_devoptab.h>
#include <system/memory.h>
#include <utils/logger.h>
#include <utils/utils.h>
#include <common/common.h>
#include <screen/tty.h>
#include "main.h"

int __entry_menu(int argc, char **argv)
{
	// Initialize dynamic libs
	InitOSFunctionPointers();
	InitSocketFunctionPointers();
	//InitAXFunctionPointers();
	InitCurlFunctionPointers();
	InitFSFunctionPointers();
	//InitGX2FunctionPointers();
	//InitPadScoreFunctionPointers();
	InitSysFunctionPointers();
	//InitSysHIDFunctionPointers();
	InitVPadFunctionPointers();
	
	// Initialize memory management
	memoryInitialize();
	
	// Init SD devoptab
	mount_sd_fat("sd");
	
	// Init screen devoptab
	tty_init();
	
	printf("test\n\n");
	
	int ret = Menu_Main();
	
	// Deinitialize screen devoptab
	tty_end();
	
	// Deinitialize SD devoptab
	unmount_sd_fat("sd");
	
	// Deinitialize memory management
	memoryRelease();
	
	return ret;
}
