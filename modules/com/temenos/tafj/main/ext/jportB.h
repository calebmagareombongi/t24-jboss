*
* This file was auto-created at Thu Jan 27 11:41:26 2011
* Created from /storage1/home/alan/src/TAFC/PB201014/port/Template/jportB.template
*
*
* Platform conditionals.
*
EQUATE	JBUILD_PORT_EXE			TO	""			;* File extension given to an executable file
EQUATE	JBUILD_PORT_SLIB		TO	".so"		;* File extension given to a shared library
EQUATE	JBUILD_PORT_ALIB		TO	".a"		;* File extension given to an archive library
EQUATE	JBUILD_PORT_OBJ			TO	".o"			;* File extension given to a compiled object
EQUATE	JBUILD_PORT_OBJ_PREFIX	TO	"$"	;* The character that prefixes an object
EQUATE	JBUILD_PORT_KEY			TO	"JAVA_1.8"		;* Platform name such as "AIX" or "HPUX" used by Updates
EQUATE	JBUILD_PORT_EL			TO	".el"			;* The suffix for shared library definitions
EQUATE	JBUILD_DELIM_CH			TO	"/"		;* The file name delimiter
EQUATE	JBUILD_SEP_CH			TO	":"		;* The separator typically used in PATH
EQUATE	JBUILD_DEFAULT_DIR		TO	"/opt/TAFC"	;* The default directory jBASE is loaded into.
EQUATE	JBUILD_COMODIR			TO	"&COMO&"		;* The directory name to put COMO data
EQUATE	JBUILD_CMD_MKDIR		TO	"mkdir -m 0755 "	;* The command to make a directory
EQUATE	JBUILD_CMD_MOVE			TO	"mv "	;* The command to move a file
EQUATE	JBUILD_CMD_COPY			TO	"cp "	;* The command to copy a file
EQUATE	JBUILD_CMD_RM			TO	"rm -f "		;* The command to remove a file
EQUATE	JBUILD_CMD_RMDIR		TO	"rm -rf "	;* The command to remove a directory
EQUATE	JBUILD_NULL_DEVICE		TO	"/dev/null"	;* Definition of a null file
EQUATE	JBUILD_TO_NULL			TO	"> /dev/null 2>&1"		;* Command extension to output to a null file
EQUATE	JBUILD_T24REL			TO	"PB201709"		;* The T24 Release
