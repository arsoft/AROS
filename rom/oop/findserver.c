/*
    (C) 1995-96 AROS - The Amiga Replacement OS
    $Id$

    Desc: Add a class to the list of puvlic classes
    Lang: english
*/
#define AROS_ALMOST_COMPATIBLE
#include <exec/lists.h>
#include <proto/exec.h>
#include "intern.h"

#include <aros/debug.h>

/*****************************************************************************

    NAME */
#include <proto/oop.h>

	AROS_LH1(Object *, FindServer,

/*  SYNOPSIS */
	AROS_LHA(STRPTR , serverID, A0),

/*  LOCATION */
	struct Library *, OOPBase, 14, OOP)

/*  FUNCTION
	Find a public server object previously installed with
	AddServer(). You can use the obtained object to
	access objects that server is responsible for.

    INPUTS
    	serverID	- The servers public identifier.

    RESULT
    	Pointer to the server object.

    NOTES
    	Probably not a good API. Implemented
	just to show how one can call methods
	across process-borders.

    EXAMPLE

    BUGS

    SEE ALSO
    	AddServer(), RemoveServer()

    INTERNALS

    HISTORY
	29-10-95    digulla automatically created from
			    intuition_lib.fd and clib/intuition_protos.h

*****************************************************************************/
{
    AROS_LIBFUNC_INIT
    AROS_LIBBASE_EXT_DECL(struct Library*,OOPBase)
    
    Object *server = NULL;
    
    EnterFunc(bug("FindServer(serverID=%s)\n", serverID));
    
    if (serverID)
    {
    	struct ServerNode *sn;
	
	D(bug("Obtaining semahore\n"));
    
    	ObtainSemaphoreShared( &GetOBase(OOPBase)->ob_ServerListLock );

	D(bug("Finding ID\n"));
	
	sn = (struct ServerNode *)FindName(
		(struct List *)&GetOBase(OOPBase)->ob_ServerList,
		serverID);
	
	if (sn)
	{
	    D(bug("Found node: %p\n", sn));
	    server = sn->sn_Server;
	}

	D(bug("Releasing semaphore\n"));
    
    
    	ReleaseSemaphore( &GetOBase(OOPBase)->ob_ServerListLock );
    }
    
    ReturnPtr ("FindServer", Object *, server);
    
    AROS_LIBFUNC_EXIT
} /* NewObjectA */
