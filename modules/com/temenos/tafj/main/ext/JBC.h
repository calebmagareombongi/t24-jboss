*
* Miscellaneous definitions for the run-time for jBASE
*
*
* Define the IOCTL statements that can be used.
* The definition of IOCTL() function is :
*
* IOCTL(FileVariable , Command , Parameters)
*
*   The function returns a true or false to test with an IF statement.
*
* The FileVariable is either a file descriptor opened with the OPEN command,
*      or a numeric value from 0 to 9 describing the tape channel number.
*   The Command value is usually a numeric to describe what action is
*  to be taken. The values for Command are given below.
* The Parameters value depends upon the 'Command' value. Note that if
*  a simple Variable name is specified, then depending upon the
*  Command value and whether it works or not, the variable may be
*  updated with a new value.
*
* Command: Can be one of the following --
*
    EQUATE JIOCTL_COMMAND_GETLABEL              TO 4        ;* Returns details of the last label read in for this file.
* Will return an empty string if not a labelled tape.
* Return a string such as "R83" , "ROS" and so on. See documentation for latest list
* of supported labels.
    EQUATE JIOCTL_COMMAND_FLUSH                 TO 5        ;* Simply flushes any data currently in the internal tape cache buffers.
* Note that if the tape hardware itself has cache buffers, these will NOT be flushed.
    EQUATE JIOCTL_COMMAND_GETSTATUS             TO 6        ;* Get details of the current driver (see JIOCTL_STATUS_xxx attributes returned below)
    EQUATE JIOCTL_COMMAND_SETSTATUS             TO 7        ;* Set details of the current driver (see JIOCTL_STATUS_xxx attributes returned below)
* Note that only some of the attributes may be ammended.
    EQUATE JIOCTL_COMMAND_IGNORELABEL           TO 8        ;* Pass next tape record as data e.g. Pass label
    EQUATE JIOCTL_COMMAND_CONVERT               TO 9        ;* Set or reset the flags that determine if converted/binary records/record keys
    EQUATE JIOCTL_COMMAND_FILESTATUS            TO 10       ;* Get details about the file itself
    EQUATE JIOCTL_COMMAND_FINDRECORD            TO 11       ;* Test whether record exists
    EQUATE JIOCTL_COMMAND_ATTACH                TO 12       ;* Attach a device to a single user.
    EQUATE JIOCTL_COMMAND_DETACH                TO 13       ;* Detach an attached device
    EQUATE JIOCTL_COMMAND_HASH_RECORD           TO 15       ;* Get the hash value for a record read/write and the bucket number
    EQUATE JIOCTL_COMMAND_GETLABELPARMS         TO 16       ;* Get the parsed details of last label read in.
    EQUATE JIOCTL_COMMAND_SETPARM1              TO 17       ;* Set the parameter 1 field of a label BEFORE first write
    EQUATE JIOCTL_COMMAND_SETREEL               TO 18       ;* Set the reel number to any value required.
    EQUATE JIOCTL_COMMAND_SETLABELTYPE          TO 19       ;* Set the label type to any valid value required or none.
    EQUATE JIOCTL_COMMAND_CHMOD                 TO 21       ;* Set / display the current flags such as if to be logged or not.
    EQUATE JIOCTL_COMMAND_CACHE_WRITE           TO 22       ;* Cache writes to the database if possible.
    EQUATE JIOCTL_COMMAND_SETBLOCKSIZE          TO 23       ;* Set blocksize
    EQUATE JIOCTL_COMMAND_FINDRECORD_EXTENDED   TO 24       ;* Extended information (length and update time)
*
* SCSI tape device commands.
*
    EQUATE JIOCTL_COMMAND_REWIND                TO 30       ;* Rewind the device.
    EQUATE JIOCTL_COMMAND_UNLOAD                TO 31       ;* Unload the device.
    EQUATE JIOCTL_COMMAND_WEOF                  TO 32       ;* Writes and end of file mark. Parameter is EOF count between 1 and 100
    EQUATE JIOCTL_COMMAND_BACK                  TO 33       ;* Backspace. Parameter is number of records, or null to previous EOF mark
    EQUATE JIOCTL_COMMAND_FORWARD               TO 34       ;* Forward space Parameter is number of records, or null to next EOF mark
    EQUATE JIOCTL_COMMAND_CHECK                 TO 35       ;* Check the file to next EOF mark for parity errors.
    EQUATE JIOCTL_COMMAND_ERASE                 TO 36       ;* Erase entire contents of tape
    EQUATE JIOCTL_COMMAND_RETENSION             TO 37       ;* Retension a QIC device
    EQUATE JIOCTL_COMMAND_FASTSCAN              TO 38       ;* Return fast scan details if supported.

    EQUATE JIOCTL_COMMAND_REMOTE_EXEC           TO 40       ;* Remote execute statement
    EQUATE JIOCTL_COMMAND_REMOTE_GETFILENAME    TO 41       ;* Get Remote File Name
    EQUATE JIOCTL_COMMAND_REMOTE_GETENV         TO 42       ;* Get Remote environment variable
    EQUATE JIOCTL_COMMAND_REMOTE_GETHOSTNAME    TO 43       ;* Get Remote host

    EQUATE JIOCTL_COMMAND_REMOTE_GETUSER        TO 44       ;* Get Remote username
    EQUATE JIOCTL_COMMAND_REMOTE_FORK           TO 45       ;* Fork and execute command
    EQUATE JIOCTL_COMMAND_REMOTE_PUTENV         TO 46       ;* Update environment variables
    EQUATE JIOCTL_COMMAND_REMOTE_CLOSEALL       TO 47       ;* Close all files.
    EQUATE JIOCTL_COMMAND_REMOTE_UNLOCKALL      TO 48       ;* Release all locks.

* the following are used by OPENSEQ to a device
*
    EQUATE JIOCTL_COMMAND_SERIAL_SET_TIMEOUT    TO 53       ;* Set the timeout
    EQUATE JIOCTL_COMMAND_SERIAL_GET_TIMEOUT    TO 54       ;* Get the Timeout

*
* Arguments "BaudeRate,Parity,Bits"
*            Parity 0- None; 1- Even; 2- Odd; 3- Mark
*
    EQUATE JIOCTL_COMMAND_SERIAL_SET_STATE      TO 55       ;* Set the Serial line state
    EQUATE JIOCTL_COMMAND_SERIAL_GET_STATE      TO 56       ;* Get the Serial Line State
    EQUATE JIOCTL_COMMAND_SERIAL_SET_RAW        TO 57       ;* Set the serial lini into Raw mode
    EQUATE JIOCTL_COMMAND_SERIAL_SET_CRLF       TO 58       ;* Append CRLF to Writes
    EQUATE JIOCTL_COMMAND_SERIAL_READ_LEN       TO 59       ;* Amount of data to read

    EQUATE JIOCTL_COMMAND_SEQ_NO_DELIMITER      TO 60       ;* Amount of data to read
    EQUATE JIOCTL_COMMAND_SEQ_CHANGE_DELIMITER  TO 61       ;* Amount of data to read
    EQUATE JIOCTL_COMMAND_SEQ_CHANGE_RECORDSIZE TO 62       ;* Change SEQ RecSz
    EQUATE JIOCTL_COMMAND_SEQ_CHANGE_PADCHAR    TO 63       ;* Change SEQ Pad char
    EQUATE JIOCTL_COMMAND_SERIAL_FLUSH          TO 65       ;* Force flush of serial device
*
    EQUATE JIOCTL_COMMAND_SEEK                  TO 66       ;* Seek to position
    EQUATE JIOCTL_COMMAND_GENERATE_VIEWS        TO 67       ;* Generate SQL views for driver
    EQUATE JIOCTL_COMMAND_SQL_SELECT_PREPARE    TO 68       ;* Prepare SQL select for SELECT FileVar statement
    EQUATE JIOCTL_COMMAND_SQL_SELECT_FETCH      TO 69       ;* Execute SQL select and fetch results
    EQUATE JIOCTL_COMMAND_SQL_SELECT_CLOSE      TO 70       ;* Close select cursor before exhausted
    EQUATE JIOCTL_COMMAND_SQL_EXECUTE_DIRECT    TO 71       ;* Execute SQL direct
    EQUATE JIOCTL_COMMAND_SQL_SET_READ_CURSOR   TO 72       ;* Set cursor for read with criteria
    EQUATE JIOCTL_COMMAND_SQL_SET_JOIN_CURSOR   TO 73       ;* Set cursor for join used with above
    EQUATE JIOCTL_COMMAND_SETCODEPAGE		TO 74	    ;* Set codepage
    EQUATE JIOCTL_COMMAND_REMOTE_CREATEFILE     TO 75       ;* create a remote file
    EQUATE JIOCTL_COMMAND_OPTION_AVAILABLE      TO 76       ;* Driver cmd to return true if specified option available
	EQUATE JIOCTL_COMMAND_JBASE_STAT            TO 77       ;* jstat output to stdout
    EQUATE JIOCTL_COMMAND_JR_CHMOD              TO 78       ;* JR files own flag setter
*
* These IOCTL functions are process in the run-time, rather than in the jedi drivers for each file.
*
    EQUATE JBC_COMMAND_GETFILENAME              TO 100      ;* Get the name of the file associated with a file variable.
    EQUATE JBC_COMMAND_CHANGEFLAGS              TO 101      ;* Get and change the file flags for Indexes, Schemas and Triggers.
*
* The following are special case values of 'errno' to define an error that can not
* be easily identified by normal errno values.
*
* Note there are the equivalents in JBC.h
*
    EQUATE JEDI_ERRNO_MIN                       TO 2000
    EQUATE JEDI_ERRNO_DEVICE_QUIT               TO 2000
    EQUATE JEDI_ERRNO_LOCK_TAKEN                TO 2001
    EQUATE JEDI_ERRNO_INV_FILE_TYPE             TO 2002
    EQUATE JEDI_ERRNO_RETRY_OPERATION           TO 2004
    EQUATE JEDI_ERRNO_NOT_APPROPRIATE           TO 2005
*
* IOCTL for RO Database
*
    EQUATE JEDI_IOCTL_ASSOCIATE_FILE            TO 2300
    EQUATE JEDI_IOCTL_RODB_CONNECTION_STATUS	TO 2400		;* Provide the status of Database associated with file descriptor

*
* During a JIOCTL_COMMAND_GETSTATUS or JIOCTL_COMMAND_SETSTATUS operation, the following are the
* attribute numbers for setting/returning data.
*
    EQUATE JIOCTL_STATUS_BLOCKSIZE              TO 1        ;* The current tape block size
    EQUATE JIOCTL_STATUS_REELNUMBER             TO 2        ;* The current reel number we are on
    EQUATE JIOCTL_STATUS_FILE_TYPE              TO 3        ;* Type of file (i.e. tape driver) we are reading/writing .
*
* Define the maximum number of printer queues.
*
	EQUATE	JBASE_MAX_PTR_ASSIGN				TO	128
*
* Equates so you can decide exactly what sort of release we are.
*
	EQUATE	JBASE_RELEASE_4						TO 1		;* Shows at LEAST release 4.0 of jBASE
	EQUATE	JBASE_RELEASE_4_1					TO 1		;* Shows at LEAST release 4.1 of jBASE
	EQUATE	JBASE_RELEASE_5						TO 1		;* Shows at LEAST release 5.0 of jBASE
*
* This char used to be '*' for compatibity reasons.  However, this char is not
* legal on Windows in a filename.
*
* This is now redundant on 4.0 onwards, but we'll leave it there so that
* we can choose to ignore these records that the customer hasn't
* deleted (as they should do with the upgrade path).
*
    EQUATE ELD_FILE_PREFIX_DEBUG                TO "!"
*
* Define the different events that can be signalled to database triggers.
*
    EQUATE TRIGGER_TYPE_PREWRITE                TO 1        ;* Before a WRITE occured
    EQUATE TRIGGER_TYPE_PRE_WRITE               TO TRIGGER_TYPE_PREWRITE

    EQUATE TRIGGER_TYPE_POSTWRITE               TO 2        ;* After a WRITE occured
    EQUATE TRIGGER_TYPE_POST_WRITE              TO TRIGGER_TYPE_POSTWRITE

    EQUATE TRIGGER_TYPE_PREDELETE               TO 3        ;* Before a DELETE occured
    EQUATE TRIGGER_TYPE_PRE_DELETE              TO TRIGGER_TYPE_PREDELETE

    EQUATE TRIGGER_TYPE_POSTDELETE              TO 4        ;* After a DELETE occured
    EQUATE TRIGGER_TYPE_POST_DELETE             TO TRIGGER_TYPE_POSTDELETE

    EQUATE TRIGGER_TYPE_PRECLEAR                TO 5        ;* Before a CLEARFILE occured
    EQUATE TRIGGER_TYPE_PRE_CLEAR               TO TRIGGER_TYPE_PRECLEAR

    EQUATE TRIGGER_TYPE_POSTCLEAR               TO 6        ;* After a CLEARFILE occured
    EQUATE TRIGGER_TYPE_POST_CLEAR              TO TRIGGER_TYPE_POSTCLEAR

    EQUATE TRIGGER_TYPE_PREREAD                 TO 7        ;* Before a READ occured
    EQUATE TRIGGER_TYPE_PRE_READ                TO TRIGGER_TYPE_PREREAD

    EQUATE TRIGGER_TYPE_POSTREAD                TO 8        ;* After a READ occured
    EQUATE TRIGGER_TYPE_POST_READ               TO TRIGGER_TYPE_POSTREAD

    EQUATE TRIGGER_TYPE_POSTOPEN                TO 9        ;* After an OPEN occured
    EQUATE TRIGGER_TYPE_POST_OPEN               TO TRIGGER_TYPE_POSTOPEN
*
* These are the definitions for the ability to user customise
* of the commands such as WHERE , LISTU , SHOW-ITEM-LOCKS.
*
    EQUATE CUSTOM_TYPE_PORT_NUMBER              TO 1        ;* The value contains the user's port number
    EQUATE CUSTOM_TYPE_DEVICE_NAME              TO 2        ;* The value contains the terminal device name
    EQUATE CUSTOM_TYPE_ACCOUNT_NAME             TO 3        ;* The value contains the user's account name
    EQUATE CUSTOM_TYPE_PROCESS_ID               TO 4        ;* The value contains the command process id
    EQUATE CUSTOM_TYPE_COMMAND                  TO 5        ;* The value contains the command executed
    EQUATE CUSTOM_TYPE_LANGUAGE                 TO 6        ;* The value contains the language in use
    EQUATE CUSTOM_TYPE_LOCATION                 TO 7        ;* The value contains the location of the terminal
    EQUATE CUSTOM_TYPE_DATE                     TO 8        ;* The value contains the date they logged on
    EQUATE CUSTOM_TYPE_TIME                     TO 9        ;* The value contains the time they logged on
    EQUATE CUSTOM_TYPE_LOCK_NUMBER              TO 10       ;* The value contains the lock number identifier
    EQUATE CUSTOM_TYPE_LOCK_BY_PID              TO 11       ;* The value contains the process id holding the lock
    EQUATE CUSTOM_TYPE_FILENAME                 TO 12       ;* The value contains the name of the file with the lock
    EQUATE CUSTOM_TYPE_RECORD_KEY               TO 13       ;* The value contains the record key
*
* Define the definitions for the Fast Scan method.
*
    DEFC JBASEScanfileInit(VAR , VAR , VAR , VAR , VAR , VAR )
    DEFC JBASEScanfileRead(VAR)
    DEFC JBASEScanfileEnd(VAR)
    EQUATE JEDI_SCANFILE_FLAGS_NOLOCK           TO 1        ;* No group locks taken, assume read only
    EQUATE JEDI_SCANFILE_FLAGS_KEYONLY          TO 2        ;* Return only the record key
    EQUATE JEDI_SCANFILE_FLAGS_LOCKGROUP        TO 4        ;* Keep group locked while scanning.
    EQUATE JEDI_SCANFILE_FLAGS_MODIFY           TO 8        ;* Ensure data returned is modifyable
    EQUATE JEDI_SCANFILE_FLAGS_SKIP_READS       TO 16       ;* Skip subsequent record reads
*
* Check for environment settings
*
    DEFC INT JBASECheckRemote(VAR)

*
* Function to call C functions
*
    DEFC VAR JBASECALLC(STRING, VAR)
*
* Get Inode for file
*
	DEFC INT JBASEGetInode(VAR)
*
* Get Dev & Inode for file
*
	DEFC VAR JBASEGetDevInode(VAR)
*
* Returning lists of jRLA locks.
*
	DEFC INT JBASEReturnLockInfo(INT , VAR)
*
* jDP Build File List function
*
	DEFC INT BuildFileList(STRING, VAR)
*
* Function to get the Pid of the process running on a specified port
*
	DEFC INT JBASEGetPidFromPort(INT)
*
* Function to get the Port number of a specified Pid
*
	DEFC INT JBASEGetPortFromPid(INT)
*
* Function to determine file access parameters
*
	DEFC INT JBASEAccess(VAR, INT)
*
* Function to obtain canonical input
*
	DEFC VAR JBASECanonicalInput(VAR)
*
* Functions to determine assertion
*
	DEFC INT JBASEAssertTrue(VAR)
	EQUATE ASSERTTRUE TO JBASEAssertTrue

	DEFC INT JBASEAssertEquals(VAR,VAR)
	EQUATE ASSERTEQUALS TO JBASEAssertEquals

*
* Controlling threads from a jBC program.
*
	EQUATE		JBASETHREAD_FLAGS_PROGRAM		TO 1		;* Start a program rather than a subroutine
	DEFC INT	JBASEThreadSendMessage(INT , STRING )
	DEFC INT    JBASEUserProfile(INT)
    DEFC VAR	JBASEThreadGetRootStatus(INT,INT)
    DEFC INT	JBASEThreadSetRootStatus(VAR , INT )
	DEFC INT	JBASETHREADCreate(VAR, VAR, VAR, VAR)
	DEFC INT	JBASETHREADStatus(VAR)

*
* Functions to connect to enterprise applications
*
	DEFC VAR CALLJEE(VAR,VAR)
	DEFC VAR JEEOpen(VAR,VAR)
	DEFC VAR JEEOpenSSL(VAR,VAR,VAR,VAR)
	DEFC VAR JEEClose(VAR)
	DEFC VAR JEEActivate(VAR,VAR,VAR)
*
* In-memory cache functions
*
	DEFC VAR CachePut(VAR, VAR, VAR)
	DEFC VAR CacheGet(VAR, VAR)
	DEFC VAR CacheDelete(VAR, VAR)
	DEFC VAR CacheExists(VAR, VAR)
	DEFC VAR CacheClear(VAR)
	DEFC VAR CacheClearAll()
	DEFC VAR CacheKeyList(VAR, VAR)
	DEFC VAR CacheBucketList(VAR)
*
	EQUATE CACHE_HITS          TO  1   ;* Number of successful hits to the cache.
	EQUATE CACHE_GETS          TO  2   ;* Number of reads from the cache.
	EQUATE CACHE_PUTS          TO  3   ;* Number of writes to the cache.
	EQUATE CACHE_SIZE          TO  4   ;* Total size of a bucket in bytes.
	EQUATE CACHE_NB_ITEMS      TO  5   ;* Number of items of the bucket.
	DEFC VAR CacheStats(VAR, VAR)
	DEFC VAR CacheClearStats(VAR)
*
	EQUATE CACHE_MAX_SIZE        TO  1   ;* Maximum bucket size (default: 1M)
	EQUATE CACHE_PURGE_THRESHOLD TO  2   ;* Bucket purging threshold (default: 90)
	DEFC VAR CacheSetOption(VAR, VAR, VAR)
	DEFC VAR CacheGetOption(VAR, VAR)

*
	DEFC VAR GetProperty(VAR, VAR);
	DEFC VAR PutProperty(VAR, VAR, VAR);

*
* New Logger library functions
* 
    EQUATE TAFC_LOG_INFO     TO  0
    EQUATE TAFC_LOG_WARNING  TO  1
    EQUATE TAFC_LOG_ERROR    TO  2
    EQUATE TAFC_LOG_FATAL    TO  3

    DEFC VAR Logger(VAR, VAR, VAR);

*
* Update Performance Counter from jBC
*
	DEFC VAR CounterUpdate(VAR, VAR, VAR);
	DEFC VAR CounterSnapshot(VAR);
	DEFC VAR CounterDelta(VAR);

*
* Deprecated Logger functions.
*
* We need to leave these in as they are used in existing T24 code, however the funtionality has been removed.
* The Logger() API, has also changed, however the new routine will check for the old format (Second arg is an Int that
* specifies the Logger Level in the new API)
*	DEFC Logger(VAR, VAR, INT)
* These can be removed when all the old referenced from T24 have been removed.
*
	EQUATE LOGGER_SEVERITY_CUSTOM   TO  10
	EQUATE LOGGER_SEVERITY_INFO     TO  20
	EQUATE LOGGER_SEVERITY_WARNING  TO  30
	EQUATE LOGGER_SEVERITY_ERROR    TO  40

	DEFC VAR LoggerDescribe(VAR, VAR)
	DEFC VAR LoggerPrint(VAR, VAR, VAR);

*
*	Monitoring Functions
*	Below 2 functions removed from TAFC but T24 people required these two functions
*
	DEFC VAR MONStartUnitOfWork(VAR);
	DEFC VAR MONEndUnitOfWork();

*
*
* Include definitions for platform-dependent conditionals.
*
	INCLUDE jportB.h

*
* Extend Dictionary array definitions, data types and status values
*
    EQUATE  EDict_Ok 		TO 0
    EQUATE  EDict_InfoNotFound	TO -1
    EQUATE  EDict_ItemNotFound	TO -2
    EQUATE  EDict_ItemNotValid	TO -3
    EQUATE  EDict_WriteFail TO -4

    EQUATE  EDict_DataType	TO EDICTARRAY<1>		;* Extended Dictionary Data Types (See below)
    EQUATE  EDict_Length	TO EDICTARRAY<2>		;* Length of string type column
    EQUATE  EDict_Scale 	TO EDICTARRAY<3>		;* Scaling factor for scaled type
    EQUATE  EDict_Description 	TO EDICTARRAY<4>		;* Text description of column
    EQUATE  EDict_ColumnName 	TO EDICTARRAY<5>		;* Column name used for access if not null
    EQUATE  EDict_MVGroupName 	TO EDICTARRAY<6>		;* Name of dictionary for Multivalued Group
    EQUATE  EDict_SVGroupName 	TO EDICTARRAY<7>		;* Name of dictionary for Subvalued Group
    EQUATE  EDict_MaxMV 	TO EDICTARRAY<8>		;* Not null then Maximum no of Multivalues, hence controlling attr
    EQUATE  EDict_MaxSV 	TO EDICTARRAY<9>		;* Not null then Maximum no of Subvalues, hence controlling attr
    EQUATE  EDict_Visible 	TO EDICTARRAY<10>		;* Flag column as visible, flags override file options default
    EQUATE  EDict_NotVisible 	TO EDICTARRAY<11>		;* Flag column as not visible
    EQUATE  EDict_Updateable 	TO EDICTARRAY<12>		;* Flag column updateable
    EQUATE  EDict_NotUpdateable TO EDICTARRAY<13>		;* Flag column not updateable
    EQUATE  EDict_Nullable 	TO EDICTARRAY<14>		;* Flag column nullable
    EQUATE  EDict_NotNullable 	TO EDICTARRAY<15>		;* Flag column not nullable
    EQUATE  EDict_SQLNulls 	TO EDICTARRAY<16>		;* Flag column may contain SQL Null type
    EQUATE  EDict_NotSQLNulls 	TO EDICTARRAY<17>		;* Flag column may not contain SQL Null type
    EQUATE  EDict_UseAttr7 	TO EDICTARRAY<18>		;* Flag column should use conversion if provided on attr 7
    EQUATE  EDict_NotUseAttr7 	TO EDICTARRAY<19>		;* Flag column should not use conversin on attr 7
    EQUATE  EDict_s3 		TO EDICTARRAY<20>		;*
    EQUATE  EDict_s4 		TO EDICTARRAY<21>		;*
    EQUATE  EDict_StorageFormat TO EDICTARRAY<22>		;* Storage format for data (See below)
    EQUATE  EDict_ForeignKeyTable TO EDICTARRAY<23>		;* Table name of foreign key
    EQUATE  EDict_ForeignKeyColumns TO EDICTARRAY<24>		;* Columns names of foreign key
    EQUATE  EDict_NextRowID	TO EDICTARRAY<25>		;* Auto increment ItemID - next available number
    EQUATE  EDict_MV_SV_Pos 	TO EDICTARRAY<26>		;* Specify positional multivalue and subvalue
    EQUATE  EDict_XrefName	TO EDICTARRAY<27>		;* Specify cross reference dict entry for synonym type
    EQUATE  EDict_ValidBit 	TO EDICTARRAY<28>		;* Flag options are valid only on read

*
* Data types. Cross reference to DTYPEID.h as used by JDP
*

    EQUATE  EDict_DT_STRING		TO 108  	  	;* DT_TYPE_CSTRING A null terminated string
    EQUATE  EDict_DT_UNICODE            TO 132                  ;* DT_TYPE_UNICODE A null terminated utf8 (unicode) string
    EQUATE  EDict_DT_UINT32		TO 4 			;* DT_TYPE_LU_ longword logical;  32-bit unsigned quantity
    EQUATE  EDict_DT_INT32		TO 8			;* DT_TYPE_L_  longword integer;  32-bit signed 2's-complement
    EQUATE  EDict_DT_DATE		TO 123 			;* DT_TYPE_ODBC_DATE_ ODBC Date format
    EQUATE  EDict_DT_TIME		TO 124			;* DT_TYPE_ODBC_TIME_ ODBC Time format
    EQUATE  EDict_DT_SCALEDINT32 	TO 101			;* DT_TYPE_LS_  32-bit signed scaled longword integer
    EQUATE  EDict_DT_DECIMAL	 	TO 101 			;* DT_TYPE_LS_	32-bit signed handles embedded decimal
    EQUATE  EDict_DT_LONGDECIMAL 	TO 104 			;* DT_TYPE_QS_	64-bit signed handles embedded decimal

*
* Storage formats dependent on data type i.e can be used to convert from storage format to datatype specified
*
    EQUATE  EDict_SF_DEFAULT		TO 0			;* Use default for this data type
    EQUATE  EDict_SF_STRING  		TO 1			;* Data stored as a string (default/valid for DT_TYPE_CSTRING_)
    EQUATE  EDict_SF_SCALED_NUMBER 	TO 2			;* Number stored as scaled integer (default/valid  for DT_TYPE_LS_)
    EQUATE  EDict_SF_INTERNAL_DATE 	TO 3			;* Number as pick date (default/valid  for DT_TYPE_ODBC_DATE_)
    EQUATE  EDict_SF_INTERNAL_TIME	TO 4			;* Number as pick time (default/valid  for DT_TYPE_ODBC_TIME_)
    EQUATE  EDict_SF_SIGNED_INTEGER	TO 5 			;* Number stored as signed integer (default/valid  for DT_TYPE_L_ )
    EQUATE  EDict_SF_UNSIGNED_INTEGER 	TO 6			;* Number as unsigned integer (default/valid  for DT_TYPE_LU_)
    EQUATE  EDict_SF_EMBEDDED_DECIMAL	TO 10			;* Stored with embedded dec point - valid for DT_TYPE_LS_
    EQUATE  EDict_SF_AUTOINCREMENT_INTEGER	TO 11		;* Use to specify value should contain next integer
    EQUATE  EDict_SF_STRING_DATE_YYYYMMDD	TO 20 		;* String date stored as YYYYMMDD format
    EQUATE  EDict_SF_UNICODE TO 21 				;* Unicode string

*
* Extended dictionary Column and General Files definitions
*

    EQUATE  EDict_ColDefault_Visible 		TO OPTIONSARRAY<1>	;* Default all columns to be visible
    EQUATE  EDict_ColDefault_NotVisible 	TO OPTIONSARRAY<2>	;* Default all columns to not be visible
    EQUATE  EDict_ColDefault_Updateable 	TO OPTIONSARRAY<3>	;* Default all columns to be updateable
    EQUATE  EDict_ColDefault_NotUpdateable 	TO OPTIONSARRAY<4>	;* Default all columns to not be updateable
    EQUATE  EDict_ColDefault_Nullable 		TO OPTIONSARRAY<5>	;* Default all columns to be nullable
    EQUATE  EDict_ColDefault_NotNullable 	TO OPTIONSARRAY<6>	;* Default all columns to not be nullable
    EQUATE  EDict_ColDefault_SQLNulls 		TO OPTIONSARRAY<7>	;* Default all columns to all SQL null type
    EQUATE  EDict_ColDefault_NotSQLNulls 	TO OPTIONSARRAY<8>	;* Default all columns to not allow SQL null type
    EQUATE  EDict_ColDefault_UseAttr7 		TO OPTIONSARRAY<9>	;* Default all columns to use conversion on attr 7
    EQUATE  EDict_ColDefault_NotUseAttr7 	TO OPTIONSARRAY<10>	;* Default all columns to not use conversion

    EQUATE  EDict_Option_Visible 			TO OPTIONSARRAY<11>	;* Flag file/table to be visibile
    EQUATE  EDict_Option_NotVisible 		TO OPTIONSARRAY<12>	;* Flag file/table to not be visible
    EQUATE  EDict_Option_Insertable 		TO OPTIONSARRAY<13>	;* Flag file/table to alloow row insert
    EQUATE  EDict_Option_NotInsertable 		TO OPTIONSARRAY<14>	;* Flag file/table to not allow row insert
    EQUATE  EDict_Option_Deleteable 		TO OPTIONSARRAY<15>	;* Flag file/table to allow row delete
    EQUATE  EDict_Option_NotDeleteable 		TO OPTIONSARRAY<16>	;* Flag file/table to not allow row delete
    EQUATE  EDict_Option_Description 		TO OPTIONSARRAY<17>	;* Text description for file/table/table
    EQUATE  EDict_ColDefault_ValidBit 		TO OPTIONSARRAY<18>	;* Flag options are valid only on read

*
* Encryption flag
*
	EQUATE	JBASE_CRYPT_GENERAL				TO 0			;* General purpose
	EQUATE	JBASE_CRYPT_ROT13				TO 1			;* Simple rotation
	EQUATE	JBASE_CRYPT_XOR11				TO 2			;* XOR.MOD11 algorithm
	EQUATE	JBASE_CRYPT_RC2					TO 3			;* RC2 algorithm
	EQUATE	JBASE_CRYPT_BASE64				TO 4			;* BASE64 algorithm
	EQUATE	JBASE_CRYPT_DES					TO 5			;* DES algorithm
	EQUATE	JBASE_CRYPT_3DES				TO 6			;* Three key, Triple DES algorithm
	EQUATE	JBASE_CRYPT_BLOWFISH			TO 7			;* Blowfish algorithm
	EQUATE	JBASE_CRYPT_AES					TO 8			;* AES algorithm

    EQUATE	JBASE_SECUREHASH_SHA256			TO 32			;* SHA-256 hash algorithm

	EQUATE	JBASE_CRYPT_BASE64_MASK			TO XTD( 40000000 )	;* BASE64 mask to be used with other algorithms
	EQUATE	JBASE_CRYPT_RC2_BASE64			TO BITOR( JBASE_CRYPT_RC2, JBASE_CRYPT_BASE64_MASK )
	EQUATE	JBASE_CRYPT_DES_BASE64			TO BITOR( JBASE_CRYPT_DES, JBASE_CRYPT_BASE64_MASK )
	EQUATE	JBASE_CRYPT_3DES_BASE64			TO BITOR( JBASE_CRYPT_3DES, JBASE_CRYPT_BASE64_MASK )
	EQUATE	JBASE_CRYPT_BLOWFISH_BASE64		TO BITOR( JBASE_CRYPT_BLOWFISH, JBASE_CRYPT_BASE64_MASK )
	EQUATE	JBASE_CRYPT_AES_BASE64			TO BITOR( JBASE_CRYPT_AES, JBASE_CRYPT_BASE64_MASK )

    EQUATE  JBASE_SECUREHASH_SHA256_BASE64  TO BITOR( JBASE_SECUREHASH_SHA256, JBASE_CRYPT_BASE64_MASK )
*
* Definitions for the data returned from the @USERSTATS variable or from
* the record read in from the PROC file (using SYSTEM(1027) as file name)
*
	EQUATE	USER_PROC_PORT_NUMBER			TO 1			;* The port number
	EQUATE	USER_PROC_NUM_PROGRAMS			TO 2			;* Number of programs running in this port
	EQUATE	USER_PROC_START_TIME			TO 3			;* Time user started in UTC format
	EQUATE	USER_PROC_PID					TO 4			;* Process ID
	EQUATE	USER_PROC_ACCOUNT				TO 5			;* Name of the account
	EQUATE	USER_PROC_USER					TO 6			;* Name of the user
	EQUATE	USER_PROC_TERMINAL_JBASE		TO 7			;* Name of terminal according to jBASE
	EQUATE	USER_PROC_TERMINAL_OS			TO 8			;* Name of terminal as seen by OS
	EQUATE	USER_PROC_DATABASE				TO 9			;* Name of database connected to
	EQUATE	USER_PROC_TTY					TO 10			;* Name of TTY device
	EQUATE	USER_PROC_LANGUAGE				TO 11			;* Language
	EQUATE	USER_PROC_LISTENING_TIME		TO 12			;* Time in UTC the listening thread last worked
	EQUATE	USER_PROC_MEM_FREE				TO 13			;* Amount of memory in heap space free chain
	EQUATE	USER_PROC_MEM_USED				TO 14			;* Amount of heap space memory in use
	EQUATE	USER_PROC_THREAD_TYPE_INT		TO 15			;* Thread type expressed as an integer
	EQUATE	USER_PROC_THREAD_TYPE_TXT		TO 16			;* Thread type expressed as a text string
	EQUATE	USER_PROC_LICENSE				TO 17			;* License counters
	EQUATE	USER_PROC_STATS_OPEN			TO 18			;* Number of OPEN's performed.
	EQUATE	USER_PROC_STATS_READ			TO 19			;* Number of READ's performed.
	EQUATE	USER_PROC_STATS_WRITE			TO 20			;* Number of WRITE's performed.
	EQUATE	USER_PROC_STATS_DELETE			TO 21			;* Number of DELETE's performed.
	EQUATE	USER_PROC_STATS_CLEARFILE		TO 22			;* Number of CLEARFILE's performed.
	EQUATE	USER_PROC_STATS_PERFORM			TO 23			;* Number of PERFORM's / EXECUTE's performed.
	EQUATE	USER_PROC_STATS_INPUT			TO 24			;* Number of INPUT's performed.
	EQUATE	USER_PROC_UNUSED_1				TO 25			;* Was 'Unused' - contains details of 'SPOOLER' assignments
	EQUATE	USER_PROC_ASSIGNMENTS			TO 25			;* Contains details of spooler channels assigned
	EQUATE	USER_PROC_SPOOLER_ASSIGNED_OFFSET TO 20			;* Channel zero spooler assignment starts in multivalue 20
	EQUATE	USER_PROC_OPEN_FILES_VIRTUAL	TO 26			;* Number of files application thinks open
	EQUATE	USER_PROC_OPEN_FILES_REAL		TO 27			;* Number of files really open by OS
	EQUATE	USER_PROC_USER_ROOT				TO 28			;* Application data set by @USER.ROOT
	EQUATE	USER_PROC_PROCESS_TXT			TO 29			;* Text string to identify process
	EQUATE  USER_PROC_STATS_READFRM			TO 32			;* Number of frames read for IO operation
	EQUATE  USER_PROC_STATS_WRITEFRM		TO 33			;* Number of frames written for IO operation
	EQUATE  USER_PROC_STATS_TOTALFRM		TO 34			;* Total number of frames for IO operation
	EQUATE  USER_PROC_STATS_LOCKRETRY		TO 35			;* Number of lock retries for IO operation

	EQUATE	USER_PROC_PROGRAM				TO 41			;* Program name and command line arguments
	EQUATE	USER_PROC_LINE_NUMBER			TO 42			;* Line number currently being executed.
	EQUATE	USER_PROC_SOURCE_NAME			TO 43			;* Name of source currently being executed.
	EQUATE	USER_PROC_UNUSED_2				TO 44			;* Unused
	EQUATE	USER_PROC_UNUSED_3				TO 45			;* Unused
	EQUATE	USER_PROC_STATUS_TXT			TO 46			;* Status of program as a readable text
	EQUATE	USER_PROC_STATUS_INT			TO 47			;* Status of program as an integer
	EQUATE	USER_PROC_CPU_USR				TO 48			;* User CPU time
	EQUATE	USER_PROC_CPU_SYS				TO 49			;* System CPU time
	EQUATE	USER_PROC_CPU_USR_CHILD			TO 50			;* User CPU time used by child processes
	EQUATE	USER_PROC_CPU_SYS_CHILD			TO 51			;* System CPU time used by child processes
	EQUATE	USER_PROC_USER_THREAD			TO 52			;* Application data set by @USER.THREAD

*
* Set up some system dependent global definitions
*
#ifdef WIN32
	DIR_DELIM_CH		=	"\"
	DIR_SEP_CH			=	";"
	MKDIR_CMD			=	"mkdir "
	MOVE_CMD			=	"move "
	COPY_CMD			=	"copy "
	RM_CMD				=	"del "
	RMDIR_CMD			=	"del /s "
	NULL_DEVICE			=	"nul"
	TO_NULL				= 	"> null"
	FILE_SUFFIX_LIB		=	".lib"
	FILE_SUFFIX_OBJ		=	".obj"
	FILE_SUFFIX_OBJ_LEN	=	4
	FILE_SUFFIX_SO		=	".dll"
	FILE_SUFFIX_EL		=	".def"
	FILE_SUFFIX_DEBUG	=	".d"
	FILE_SUFFIX_DEBUG_LEN	=	2
	JBC_COMODIR			=	"COMO"
#else
	DIR_DELIM_CH		=	"/"
	DIR_SEP_CH			=	":"
	MKDIR_CMD			=	"mkdir -m 0755 "
	MOVE_CMD			=	"mv "
	COPY_CMD			=	"cp "
	RM_CMD				=	"rm -f "
	RMDIR_CMD			=	"rm -rf "
	NULL_DEVICE			=	"/dev/null"
	TO_NULL				= 	"> /dev/null 2>&1"
	FILE_SUFFIX_LIB		=	".a"
	FILE_SUFFIX_OBJ		=	".o"
	FILE_SUFFIX_OBJ_LEN	=	2
	FILE_SUFFIX_SO		=	".so"
	FILE_SUFFIX_EL		=	".el"
	FILE_SUFFIX_DEBUG	=	".d"
	FILE_SUFFIX_DEBUG_LEN	=	2
	JBC_COMODIR			=	"&COMO&"
#endif
