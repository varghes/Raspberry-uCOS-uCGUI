/******************************************************************************
*	configuration.h
*	 by Alex Chadwick
*
*	A light weight implementation of the USB protocol stack fit for a simple
*	driver.
*
*	configuration.h contains definitions for all optional components
*	The makefile defines three main categories of definitions:
*		CONFIG: Whether or not this is a DEBUG driver
*		TARGET: The target system
*		TYPE:	What sort of driver to compile (e.g. standalone)
*****************************************************************************/

// Check we have a CONFIG. Valid choices are DEBUG and FINAL. If neither of
// of these are specified, CONFIG_ERROR will be. If not, the haven't used the
// makefile.
//#define FINAL

#define LIB_ARM_V6 1
#define LIB_BCM2835 1
#define LIB_DWC 1
#define LIB_HID 1
#define LIB_HUB 1
#define LIB_MOUSE 1


#	define ARM
#	define ARM_V6
#	define ENDIAN_LITTLE
#	define BROADCOM_2835
#	define HCD_DESIGNWARE_20
#	define HCD_DESIGNWARE_BASE ((void*)0x20980000)

	// Disables all logging
//#	define NO_LOG
	// Disables external memory management
#	define MEM_INTERNAL_MANAGER
	// Disables external memory reservation
#	define MEM_NO_RESERVE
