
/* DEVICE STUFF */

#define DEVNAME             "usbbluetooth.device"

#define DEVBASETYPEPTR struct NepBTDevBase *

/* local protos */

AROS_UFP3(DEVBASETYPEPTR, devInit,
          AROS_UFPA(DEVBASETYPEPTR, base, D0),
          AROS_UFPA(BPTR, seglist, A0),
          AROS_UFPA(struct ExecBase *, SysBase, A6));

AROS_LD3(DEVBASETYPEPTR, devOpen,
         AROS_LDA(struct IOBTHCIReq *, ioreq, A1),
         AROS_LDA(ULONG, unitnum, D0),
         AROS_LDA(ULONG, flags, D1),
         DEVBASETYPEPTR, base, 1, dev);

AROS_LD1(BPTR, devClose,
         AROS_LDA(struct IOBTHCIReq *, ioreq, A1),
         DEVBASETYPEPTR, base, 2, dev);

AROS_LD1(BPTR, devExpunge,
         AROS_LDA(DEVBASETYPEPTR, extralh, D0),
         DEVBASETYPEPTR, base, 3, dev);

AROS_LD0(DEVBASETYPEPTR, devReserved,
         DEVBASETYPEPTR, base, 4, dev);

AROS_LD1(void, devBeginIO,
         AROS_LDA(struct IOBTHCIReq *, ioreq, A1),
         DEVBASETYPEPTR, base, 5, dev);

AROS_LD1(LONG, devAbortIO,
         AROS_LDA(struct IOBTHCIReq *, ioreq, A1),
         DEVBASETYPEPTR, base, 6, dev);

/* Device stuff */

/* Reply the iorequest with success
*/
#define RC_OK         0

/* Magic cookie, don't set error fields & don't reply the ioreq
*/
#define RC_DONTREPLY  -1

struct Unit *Open_Unit(struct IOBTHCIReq *ioreq,
                       LONG unitnr,
                       struct NepBTDevBase *base);
void Close_Unit(struct NepBTDevBase *base, struct NepClassBT *ncp,
                struct IOBTHCIReq *ioreq);

WORD cmdNSDeviceQuery(struct IOStdReq *ioreq, struct NepClassBT *ncp, struct NepBTDevBase *base);

WORD cmdQueryDevice(struct IOBTHCIReq *ioreq, struct NepClassBT *ncp, struct NepBTDevBase *base);


void TermIO(struct IOBTHCIReq *ioreq, struct NepBTDevBase *base);

struct my_NSDeviceQueryResult
{
    ULONG   DevQueryFormat;         /* this is type 0               */
    ULONG   SizeAvailable;          /* bytes available              */
    UWORD   DeviceType;             /* what the device does         */
    UWORD   DeviceSubType;          /* depends on the main type     */
    const UWORD *SupportedCommands; /* 0 terminated list of cmd's   */
};
