#ifndef  CLIB_AROSSUPPORT_PROTOS_H
#define  CLIB_AROSSUPPORT_PROTOS_H

/*
    (C) 1995-97 AROS - The Amiga Research OS
    $Id$

    Desc: Prototypes for aros.lib
    Lang: english
*/

#ifndef  EXEC_TYPES_H
#   include <exec/types.h>
#endif
#ifndef AROS_AROSBASE_H
#   include <aros/arossupportbase.h>
#endif
#ifndef EXEC_EXECBASE_H
#   include <exec/execbase.h>
#endif
#ifndef  DOS_DOS_H
#   include <dos/dos.h>
#endif
#ifndef  UTILITY_HOOKS_H
#   include <utility/hooks.h>
#endif

#ifdef DEBUG_FreeMem
#   ifndef PROTO_EXEC_H
#       include <proto/exec.h>
#   endif
#   if DEBUG_FreeMem
#       undef FreeMem
#       define FreeMem NastyFreeMem
#   endif
#endif

extern struct ExecBase * Sysbase;

/*
    Prototypes
*/
ULONG   CalcChecksum (APTR mem, ULONG size);
int     kprintf      (const UBYTE * fmt, ...);
void    NastyFreeMem (APTR mem, ULONG size);
APTR    RemoveSList  (APTR * list, APTR node);
void    hexdump      (const void * data, IPTR offset, ULONG count);
int     strrncasecmp (const char *, const char *, int);
void    RawPutChars  (const UBYTE * string, int len);
BOOL    IsDosEntryA  (char *Name, ULONG Flags);

/* AROS enhancements */
BOOL ReadByte    (struct Hook *, UBYTE  * dataptr, void * stream);
BOOL ReadWord    (struct Hook *, UWORD  * dataptr, void * stream);
BOOL ReadLong    (struct Hook *, ULONG  * dataptr, void * stream);
BOOL ReadFloat   (struct Hook *, FLOAT  * dataptr, void * stream);
BOOL ReadDouble  (struct Hook *, DOUBLE * dataptr, void * stream);
BOOL ReadString  (struct Hook *, STRPTR * dataptr, void * stream);
BOOL ReadStruct  (struct Hook *, APTR   * dataptr, void * stream, const IPTR * desc);
BOOL WriteByte   (struct Hook *, UBYTE  data, void * stream);
BOOL WriteWord   (struct Hook *, UWORD  data, void * stream);
BOOL WriteLong   (struct Hook *, ULONG  data, void * stream);
BOOL WriteFloat  (struct Hook *, FLOAT  data, void * stream);
BOOL WriteDouble (struct Hook *, DOUBLE data, void * stream);
BOOL WriteString (struct Hook *, STRPTR data, void * stream);
BOOL WriteStruct (struct Hook *, APTR   data, void * stream, const IPTR * desc);
void FreeStruct  (APTR s,  const IPTR * desc);


/* don't use SysBase->DebugData on AmigaOS */
#ifndef __amigaos__
#define kprintf     (((struct AROSSupportBase *)(SysBase->DebugData))->kprintf)
#endif

#endif /* CLIB_AROSSUPPORT_PROTOS_H */
