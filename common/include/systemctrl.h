/*
 * This file is part of PRO CFW.

 * PRO CFW is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * PRO CFW is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with PRO CFW. If not, see <http://www.gnu.org/licenses/ .
 */

#ifndef _SYSTEMCTRL_H_
#define _SYSTEMCTRL_H_

#ifdef __cplusplus
extern "C"{
#endif

#include <pspsdk.h>
#include <psploadexec_kernel.h>
#include <pspiofilemgr_kernel.h>
#include <pspthreadman_kernel.h>
#include <psploadcore.h>
#include <globals.h>
#include <pspkernel.h>
#include <pspinit.h>
#include "module2.h"

#define GAME_ID_MINIMUM_BUFFER_SIZE 10

// Function Name Clones (of old but gold times)
//#define sctrlKernelQuerySystemCall sceKernelQuerySystemCall

// Prologue Module Start Handler
typedef void (* STMOD_HANDLER)(SceModule2 *);

// Thread Context
typedef struct SceThreadContext SceThreadContext;

// Find Import Library Stub Table
SceLibraryStubTable * findImportLib(SceModule2 * pMod, char * library);

// Find Import Function Stub Address
unsigned int findImportByNID(SceModule2 * pMod, char * library, unsigned int nid);

// Replace Import Function Stub
int hookImportByNID(SceModule2 * pMod, char * library, unsigned int nid, void * func);

// Set User Level
int sctrlKernelSetUserLevel(int level);

// Set System Firmware Version
int sctrlKernelSetDevkitVersion(int version);

// Get HEN Version
int sctrlHENGetVersion();

// Get HEN Minor Version
int sctrlHENGetMinorVersion();

// Find Filesystem Driver
PspIoDrv * sctrlHENFindDriver(char * drvname);

// Replace Function in Syscall Table
void sctrlHENPatchSyscall(void * addr, void * newaddr);

// Load Execute Module via Kernel Internal Function
int sctrlKernelLoadExecVSHWithApitype(int apitype, const char * file, struct SceKernelLoadExecVSHParam * param);

/**
 * Restart the vsh.
 *
 * @param param - Pointer to a ::SceKernelLoadExecVSHParam structure, or NULL
 *
 * @returns < 0 on some errors.
 *
*/
int sctrlKernelExitVSH(struct SceKernelLoadExecVSHParam *param);

// Register Prologue Module Start Handler
STMOD_HANDLER sctrlHENSetStartModuleHandler(STMOD_HANDLER new_handler);

// Return Reboot Configuration UMD File
char * sctrlSEGetUmdFile(void);

// Set Reboot Configuration UMD File
void sctrlSESetUmdFile(char * file);

// Calculate Random Number via KIRK
unsigned int sctrlKernelRand(void);

// Set Init Apitype
int sctrlKernelSetInitApitype(int apitype);

// Set Init Filename
int sctrlKernelSetInitFileName(char * filename);

// Register Custom init.prx sceKernelStartModule Handler, returns previous handler (if any)
void sctrlSetCustomStartModule(int (* func)(int modid, SceSize argsize, void * argp, int * modstatus, SceKernelSMOption * opt));

// Return Game Product ID of currently running Game
int sctrlKernelGetGameID(char gameid[GAME_ID_MINIMUM_BUFFER_SIZE]);

// EBOOT.PBP Parameter Getter
int sctrlGetInitPARAM(const char * paramName, u16 * paramType, u32 * paramLength, void * paramBuffer);

// Find UID of the specified Thread
int sctrlGetThreadUIDByName(const char * name);

// Return Thread Context of specified Thread (Search by UID)
int sctrlGetThreadContextByUID(int uid, SceKernelThreadKInfo * ctx);

// Return Thread Context of specified Thread (Search by Name)
int sctrlGetThreadContextByName(const char * name, SceKernelThreadKInfo * ctx);

// Flush Instruction and Data Cache
void flushCache(void);

// Missing PSPSDK Functions
u32 sceKernelQuerySystemCall(void * function);

// Get ARK's execution environment configuration
void* sctrlHENGetArkConfig(ARKConfig* conf);

// Register the default VRAM handler for PSX exploit, returns the previous handler
void* sctrlHENSetPSXVramHandler(void (*handler)(u32* psp_vram, u16* ps1_vram));

// Enable Custom PEOPS configuration
void sctrlHENEnableCustomPeopsConfig(void* config);

// Disable Custom PEOPS configuration (use database config)
void sctrlHENDisableCustomPeopsConfig();

// GZIP decompress
int sctrlDeflateDecompress(void* dest, void* src, int size);
int sctrlGzipDecompress(void* dest, void* src, int size);

// LZ4 decompress
int LZ4_decompress_fast(const char* source, char* dest, int outputSize);

// LZO decompress
int lzo1x_decompress(void* source, unsigned src_len, void* dest, unsigned* dst_len, void*);

int sctrlKernelMsIsEf();

int sctrlKernelLoadExecVSHDisc(const char *file, struct SceKernelLoadExecVSHParam *param);

/**
 * Restart the vsh.
 *
 * @param param - Pointer to a ::SceKernelLoadExecVSHParam structure, or NULL
 *
 * @returns < 0 on some errors.
 *
*/
int sctrlKernelExitVSH(struct SceKernelLoadExecVSHParam *param);

/**
 * Executes a new executable from a disc.
 * It is the function used by the firmware to execute the EBOOT.BIN from a disc.
 *
 * @param file - The file to execute.
 * @param param - Pointer to a ::SceKernelLoadExecVSHParam structure, or NULL.
 *
 * @returns < 0 on some errors. 
*/

/**
 * Executes a new executable from a disc.
 * It is the function used by the firmware to execute an updater from a disc.
 *
 * @param file - The file to execute.
 * @param param - Pointer to a ::SceKernelLoadExecVSHParam structure, or NULL.
 *
 * @returns < 0 on some errors. 
*/
int sctrlKernelLoadExecVSHDiscUpdater(const char *file, struct SceKernelLoadExecVSHParam *param);

/**
 * Executes a new executable from a memory stick.
 * It is the function used by the firmware to execute an updater from a memory stick.
 *
 * @param file - The file to execute.
 * @param param - Pointer to a ::SceKernelLoadExecVSHParam structure, or NULL.
 *
 * @returns < 0 on some errors. 
*/
int sctrlKernelLoadExecVSHMs1(const char *file, struct SceKernelLoadExecVSHParam *param);

/**
 * Executes a new executable from a memory stick.
 * It is the function used by the firmware to execute games (and homebrew :P) from a memory stick.
 *
 * @param file - The file to execute.
 * @param param - Pointer to a ::SceKernelLoadExecVSHParam structure, or NULL.
 *
 * @returns < 0 on some errors. 
*/
int sctrlKernelLoadExecVSHMs2(const char *file, struct SceKernelLoadExecVSHParam *param);
int sctrlKernelLoadExecVSHEf2(const char *file, struct SceKernelLoadExecVSHParam *param);

/**
 * Executes a new executable from a memory stick.
 * It is the function used by the firmware to execute ... ?
 *
 * @param file - The file to execute.
 * @param param - Pointer to a ::SceKernelLoadExecVSHParam structure, or NULL.
 *
 * @returns < 0 on some errors. 
*/
int sctrlKernelLoadExecVSHMs3(const char *file, struct SceKernelLoadExecVSHParam *param);

/**
 * Executes a new executable from a memory stick.
 * It is the function used by the firmware to execute psx games
 *
 * @param file - The file to execute.
 * @param param - Pointer to a ::SceKernelLoadExecVSHParam structure, or NULL.
 *
 * @returns < 0 on some errors. 
*/
int sctrlKernelLoadExecVSHMs4(const char *file, struct SceKernelLoadExecVSHParam *param);


/**
 * Executes a new executable with the specified apitype
 *
 * @param apitype - The apitype
 * @param file - The file to execute.
 * @param param - Pointer to a ::SceKernelLoadExecVSHParam structure, or NULL.
 *
 * @returns < 0 on some errors. 
*/
int sctrlKernelLoadExecVSHWithApitype(int apitype, const char *file, struct SceKernelLoadExecVSHParam *param);

/**
 * Sets the api type 
 *
 * @param apitype - The apitype to set
 * @returns the previous apitype
 *
 * @Note - this will modify also the value of sceKernelBootFrom, since the value of
 * bootfrom is calculated from the apitype
*/

/**
 * Sets the filename of the launched executable.
 *
 * @param filename - The filename to set
 * @returns 0 on success
*/

/**
 * Sets the init key config
 *
 * @param key - The key code
 * @returns the previous key config
*/
int sctrlKernelSetInitKeyConfig(int key);

/**
 * Sets the user level of the current thread
 *
 * @param level - The user level
 * @return the previous user level on success
 */
int sctrlKernelSetUserLevel(int level);

/**
 * Sets the devkit version
 * 
 * @param version - The devkit version to set
 * @return the previous devkit version
 * 
*/
int sctrlKernelSetDevkitVersion(int version);

/**
 * Checks if we are in SE.
 *
 * @returns 1 if we are in SE-C or later, 0 if we are in HEN-D or later,
 * and < 0 (a kernel error code) in any other case
*/
int    sctrlHENIsSE();

/**
 * Checks if we are in Devhook.
 *
 * @returns 1 if we are in SE-C/HEN-D for devhook  or later, 0 if we are in normal SE-C/HEN-D or later,
 * and < 0 (a kernel error code) in any other case
*/
int    sctrlHENIsDevhook();

/**
 * Gets the HEN version
 *
 * @returns - The HEN version
 *
 * HEN D / SE-C :  0x00000400
 */
int sctrlHENGetVersion();

/**
 * Gets the HEN minor version
 *
 * @returns - The HEN minor version
 */
int sctrlHENGetMinorVersion();

/**
 * Finds a driver
 *
 * @param drvname - The name of the driver (without ":" or numbers)
 *
 * @returns the driver if found, NULL otherwise
 *
 */
PspIoDrv *sctrlHENFindDriver(char *drvname);

/** 
 * Finds a function.
 *
 * @param modname - The module where to search the function
 * @param libname - The library name
 * @nid - The nid of the function
 *
 * @returns - The function address or 0 if not found
 *
*/
unsigned int sctrlHENFindFunction(char *modname, char *libname, unsigned int nid);


/**
 * Sets a function to be called just before module_start of a module is gonna be called (useful for patching purposes)
 *
 * @param handler - The function, that will receive the module structure before the module is started.
 *
 * @returns - The previous set function (NULL if none);
 * @Note: because only one handler function is handled by HEN, you should
 * call the previous function in your code.
 *
 * @Example: 
 *
 * STMOD_HANDLER previous = NULL;
 *
 * int OnModuleStart(SceModule2 *mod);
 *
 * void somepointofmycode()
 * {
 *        previous = sctrlHENSetStartModuleHandler(OnModuleStart);
 * }
 *
 * int OnModuleStart(SceModule2 *mod)
 * {
 *        if (strcmp(mod->modname, "vsh_module") == 0)
 *        {
 *            // Do something with vsh module here
 *        }
 *
 *        if (!previous)
 *            return 0;
 *
 *        // Call previous handler
 *
 *        return previous(mod);
 * }
 *
 * @Note2: The above example should be compiled with the flag -fno-pic
 *            in order to avoid problems with gp register that may lead to a crash.
 *
*/

typedef int (* KDEC_HANDLER)(u32 *buf, int size, int *retSize, int m);
typedef int (* MDEC_HANDLER)(u32 *tag, u8 *keys, u32 code, u32 *buf, int size, int *retSize, int m, void *unk0, int unk1, int unk2, int unk3, int unk4);

/**
 * Sets the speed (only for kernel usage)
 *
 * @param cpu - The cpu speed
 * @param bus - The bus speed
*/
void sctrlHENSetSpeed(int cpu, int bus);

/**
 * Sets the partition 2 and 8  memory for next loadexec.
 *
 * @param p2 - The size in MB for the user partition. Must be > 0
 * @param p8 - The size in MB for partition 8. Can be 0.
 *
 * @returns 0 on success, < 0 on error.
 * This function is only available in the slim. The function will fail
 * if p2+p8 > 52 or p2 == 0
*/
int sctrlHENSetMemory(u32 p2, u32 p8);

void sctrlHENPatchSyscall(void *addr, void *newaddr);

int sctrlKernelQuerySystemCall(void *func_addr);

int sctrlKernelBootFrom(void);


// ################# SAVESTATE USER ##############

enum BootLoadFlags
{
    BOOTLOAD_VSH = 1,
    BOOTLOAD_GAME = 2,
    BOOTLOAD_UPDATER = 4,
    BOOTLOAD_POPS = 8,
    BOOTLOAD_UMDEMU = 64, /* for original NP9660 */
};

/**
 * Restart the vsh.
 *
 * @param param - Pointer to a ::SceKernelLoadExecVSHParam structure, or NULL
 *
 * @returns < 0 on some errors.
 *
*/
int sctrlKernelExitVSH(struct SceKernelLoadExecVSHParam *param);

/**
 * Executes a new executable from a disc.
 * It is the function used by the firmware to execute the EBOOT.BIN from a disc.
 *
 * @param file - The file to execute.
 * @param param - Pointer to a ::SceKernelLoadExecVSHParam structure, or NULL.
 *
 * @returns < 0 on some errors. 
*/
int sctrlKernelLoadExecVSHDisc(const char *file, struct SceKernelLoadExecVSHParam *param);

/**
 * Executes a new executable from a disc.
 * It is the function used by the firmware to execute an updater from a disc.
 *
 * @param file - The file to execute.
 * @param param - Pointer to a ::SceKernelLoadExecVSHParam structure, or NULL.
 *
 * @returns < 0 on some errors. 
*/

/**
 * Executes a new executable from a memory stick.
 * It is the function used by the firmware to execute an updater from a memory stick.
 *
 * @param file - The file to execute.
 * @param param - Pointer to a ::SceKernelLoadExecVSHParam structure, or NULL.
 *
 * @returns < 0 on some errors. 
*/

/**
 * Executes a new executable from a memory stick.
 * It is the function used by the firmware to execute games (and homebrew :P) from a memory stick.
 *
 * @param file - The file to execute.
 * @param param - Pointer to a ::SceKernelLoadExecVSHParam structure, or NULL.
 *
 * @returns < 0 on some errors. 
*/

/**
 * Executes a new executable from a memory stick.
 * It is the function used by the firmware to execute ... ?
 *
 * @param file - The file to execute.
 * @param param - Pointer to a ::SceKernelLoadExecVSHParam structure, or NULL.
 *
 * @returns < 0 on some errors. 
*/

/**
 * Executes a new executable from a memory stick.
 * It is the function used by the firmware to execute psx games
 *
 * @param file - The file to execute.
 * @param param - Pointer to a ::SceKernelLoadExecVSHParam structure, or NULL.
 *
 * @returns < 0 on some errors. 
*/


/**
 * Executes a new executable with the specified apitype
 *
 * @param apitype - The apitype
 * @param file - The file to execute.
 * @param param - Pointer to a ::SceKernelLoadExecVSHParam structure, or NULL.
 *
 * @returns < 0 on some errors. 
*/

/**
 * Sets the api type 
 *
 * @param apitype - The apitype to set
 * @returns the previous apitype
 *
 * @Note - this will modify also the value of sceKernelBootFrom, since the value of
 * bootfrom is calculated from the apitype
*/
int sctrlKernelSetInitApitype(int apitype);

/**
 * Sets the filename of the launched executable.
 *
 * @param filename - The filename to set
 * @returns 0 on success
*/

/**
 * Sets the init key config
 *
 * @param key - The key code
 * @returns the previous key config
*/

/**
 * Sets the user level of the current thread
 *
 * @param level - The user level
 * @return the previous user level on success
 */
int sctrlKernelSetUserLevel(int level);

/**
 * Sets the devkit version
 * 
 * @param version - The devkit version to set
 * @return the previous devkit version
 * 
*/
int sctrlKernelSetDevkitVersion(int version);

/**
 * Sets a function to be called just before module_start of a module is gonna be called (useful for patching purposes)
 *
 * @param handler - The function, that will receive the module structure before the module is started.
 *
 * @returns - The previous set function (NULL if none);
 * @Note: because only one handler function is handled by HEN, you should
 * call the previous function in your code.
 *
 * @Example: 
 *
 * STMOD_HANDLER previous = NULL;
 *
 * int OnModuleStart(SceModule2 *mod);
 *
 * void somepointofmycode()
 * {
 *        previous = sctrlHENSetStartModuleHandler(OnModuleStart);
 * }
 *
 * int OnModuleStart(SceModule2 *mod)
 * {
 *        if (strcmp(mod->modname, "vsh_module") == 0)
 *        {
 *            // Do something with vsh module here
 *        }
 *
 *        if (!previous)
 *            return 0;
 *
 *        // Call previous handler
 *
 *        return previous(mod);
 * }
 *
 * @Note2: The above example should be compiled with the flag -fno-pic
 *            in order to avoid problems with gp register that may lead to a crash.
 *
*/
STMOD_HANDLER sctrlHENSetStartModuleHandler(STMOD_HANDLER handler);

/**
 * Sets the speed (only for kernel usage)
 *
 * @param cpu - The cpu speed
 * @param bus - The bus speed
*/

/**
 * Sets the partition 2 and 8  memory for next loadexec.
 *
 * @param p2 - The size in MB for the user partition. Must be > 0
 * @param p8 - The size in MB for partition 8. Can be 0.
 *
 * @returns 0 on success, < 0 on error.
 * This function is only available in the slim. The function will fail
 * if p2+p8 > 52 or p2 == 0
*/

void sctrlHENPatchSyscall(void *addr, void *newaddr);



/**
 * Patch module by offset
 *
 * @param modname - module name
 * @param inst  - instruction
 * @param offset - module patch offset
 *
 * @return < 0 on error
 */
int sctrlPatchModule(char *modname, u32 inst, u32 offset);

/**
 * Get module text address
 *
 * @param modname - module name
 * 
 * @return text address, or 0 if not found
 */
u32 sctrlModuleTextAddr(char *modname);

/**
 * Get sceInit module text address
 *
 * @note Only useful before sceInit exits
 *
 * @return text address, or 0 if not found
 */
u32 sctrlGetInitTextAddr(void);

/**
 * Set custom start module handler
 * It can be used to replace a system module
 *
 * @note: func returns -1 to ignore the module and load the original module. Or new modid if replace is done.
 */
void sctrlSetCustomStartModule(int (*func)(int modid, SceSize argsize, void *argp, int *modstatus, SceKernelSMOption *opt));

/**
 * Loads a module on next reboot. Only kernel mode.
 *
 * @param module_after - The path of the module which is loaded after the module to be loaded.
   The module passed to this function will be loaded just before that module.
 * @param buf - The buffer containing the module - Don't deallocate this one. It has to reside in kernel memory.
 * @param size - The size of the module
 * @param flags - The modes in which the module should be loaded, one of BootLoadFlags
 *
 * @Example:
 * sctrlHENLoadModuleOnReboot("/kd/usersystemlib.prx", module_buffer, module_size, BOOTLOAD_GAME | BOOTLOAD_POPS | BOOTLOAD_UMDEMU); 
 *
 * This will load the module contained in module_buffer just before /kd/usersystemlib.prx in the next reboot, if the mode of next reboot is game, pops or umdemu
 *
 * @Remarks: Don't use too early modules in first param like "/kd/init.prx" or "/kd/systemctrl.prx", or your module may not load properly
 * Only one module will be loaded on reboot with this function. 
 * If this function is called many times, only the last one will be considered.
 * By making a module to load itself using this function, and calling 
 * sctrlHENLoadModuleOnReboot on module_start, a prx can cause itself to be resident in the modes choosen by flags.
 * If all flags are selected, the module will stay resident until a psp shutdown, or until sctrlHENLoadModuleOnReboot is not called.
*/

void sctrlHENLoadModuleOnReboot(char *module_after, void *buf, int size, int flags);

/**
 * Enable/disable NID Resolver on particular library
 *
 * @param libname the name of the library to be enabled/disabled
 * @param enabled 0 - disabled, != 0 - enabled
 *
 * @Example:
 * sctrlKernelSetNidResolver("sceImpose_driver", 0); // disable sceImpose_driver resolving
 *
 * @return previous value if set, < 0 on error
 */
int sctrlKernelSetNidResolver(char *libname, u32 enabled);

/**
 * Get the real unspoofed Ethernet (MAC) Address of the systems WLAN chip
 *
 * @param mac Out-Buffer (6B) for real MAC Address
 *
 * @return 0 on success, < 0 on error
 */
int sctrlGetRealEthernetAddress(uint8_t * mac);

/**
 * Wrapper for sceKernelDeflateDecompress
 *
 * @param dest out buffer where the decompressed data will be
 * @param src source buffer with the compressed data
 * @param size size of the decompressed data
 *
 */
int sctrlDeflateDecompress(void* dest, void* src, int size);

/**
 * Copy the exploited game ID into dest.
 *
 * @param dest pointer to where to copy the game ID, maximum of 10 characters (including the null terminating byte)
 *
 */
void sctrlGetExploitID(char* dest);

#ifdef __cplusplus
}
#endif

#endif
