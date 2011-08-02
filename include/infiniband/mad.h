/*
 * Copyright (c) 2004-2009 Voltaire Inc.  All rights reserved.
 * Copyright (c) 2009 HNR Consulting.  All rights reserved.
 * Copyright (c) 2009-2011 Mellanox Technologies LTD.  All rights reserved.
 *
 * This software is available to you under a choice of one of two
 * licenses.  You may choose to be licensed under the terms of the GNU
 * General Public License (GPL) Version 2, available from the file
 * COPYING in the main directory of this source tree, or the
 * OpenIB.org BSD license below:
 *
 *     Redistribution and use in source and binary forms, with or
 *     without modification, are permitted provided that the following
 *     conditions are met:
 *
 *      - Redistributions of source code must retain the above
 *        copyright notice, this list of conditions and the following
 *        disclaimer.
 *
 *      - Redistributions in binary form must reproduce the above
 *        copyright notice, this list of conditions and the following
 *        disclaimer in the documentation and/or other materials
 *        provided with the distribution.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */
#ifndef _MAD_H_
#define _MAD_H_

#include <infiniband/mad_osd.h>

#ifdef __cplusplus
#  define BEGIN_C_DECLS extern "C" {
#  define END_C_DECLS   }
#else				/* !__cplusplus */
#  define BEGIN_C_DECLS
#  define END_C_DECLS
#endif				/* __cplusplus */

BEGIN_C_DECLS
#define IB_MAD_RPC_VERSION_MASK	0x0f00
#define IB_MAD_RPC_VERSION1	(1<<8)

#define IB_SUBNET_PATH_HOPS_MAX	64
#define IB_DEFAULT_SUBN_PREFIX	0xfe80000000000000ULL
#define IB_DEFAULT_QP1_QKEY	0x80010000
#define IB_MAD_SIZE		256
#define IB_SMP_DATA_OFFS	64
#define IB_SMP_DATA_SIZE	64
#define IB_VENDOR_RANGE1_DATA_OFFS	24
#define IB_VENDOR_RANGE1_DATA_SIZE	(IB_MAD_SIZE - IB_VENDOR_RANGE1_DATA_OFFS)
#define IB_VENDOR_RANGE2_DATA_OFFS	40
#define IB_VENDOR_RANGE2_DATA_SIZE	(IB_MAD_SIZE - IB_VENDOR_RANGE2_DATA_OFFS)
#define IB_SA_DATA_SIZE		200
#define IB_SA_DATA_OFFS		56
#define IB_PC_DATA_OFFS		64
#define IB_PC_DATA_SZ		(IB_MAD_SIZE - IB_PC_DATA_OFFS)
#define IB_SA_MCM_RECSZ		53
#define IB_SA_PR_RECSZ		64
#define IB_SA_GIR_RECSZ		72
#define IB_BM_DATA_OFFS		64
#define IB_BM_DATA_SZ		(IB_MAD_SIZE - IB_BM_DATA_OFFS)
#define IB_BM_BKEY_OFFS		24
#define IB_BM_BKEY_AND_DATA_SZ	(IB_MAD_SIZE - IB_BM_BKEY_OFFS)
#define IB_CC_DATA_OFFS         64
#define IB_CC_DATA_SZ           (IB_MAD_SIZE - IB_CC_DATA_OFFS)
#define IB_CC_LOG_DATA_OFFS     32 
#define IB_CC_LOG_DATA_SZ       (IB_MAD_SIZE - IB_CC_LOG_DATA_OFFS)

enum MAD_CLASSES {
	IB_SMI_CLASS = 0x1,
	IB_SMI_DIRECT_CLASS = 0x81,
	IB_SA_CLASS = 0x3,
	IB_PERFORMANCE_CLASS = 0x4,
	IB_BOARD_MGMT_CLASS = 0x5,
	IB_DEVICE_MGMT_CLASS = 0x6,
	IB_CM_CLASS = 0x7,
	IB_SNMP_CLASS = 0x8,
	IB_VENDOR_RANGE1_START_CLASS = 0x9,
	IB_VENDOR_RANGE1_END_CLASS = 0x0f,
	IB_CC_CLASS = 0x21,
	IB_VENDOR_RANGE2_START_CLASS = 0x30,
	IB_VENDOR_RANGE2_END_CLASS = 0x4f,
};

enum MAD_METHODS {
	IB_MAD_METHOD_GET = 0x1,
	IB_MAD_METHOD_SET = 0x2,
	IB_MAD_METHOD_GET_RESPONSE = 0x81,

	IB_MAD_METHOD_SEND = 0x3,
	IB_MAD_METHOD_TRAP = 0x5,
	IB_MAD_METHOD_TRAP_REPRESS = 0x7,

	IB_MAD_METHOD_REPORT = 0x6,
	IB_MAD_METHOD_REPORT_RESPONSE = 0x86,
	IB_MAD_METHOD_GET_TABLE = 0x12,
	IB_MAD_METHOD_GET_TABLE_RESPONSE = 0x92,
	IB_MAD_METHOD_GET_TRACE_TABLE = 0x13,
	IB_MAD_METHOD_GET_TRACE_TABLE_RESPONSE = 0x93,
	IB_MAD_METHOD_GETMULTI = 0x14,
	IB_MAD_METHOD_GETMULTI_RESPONSE = 0x94,
	IB_MAD_METHOD_DELETE = 0x15,
	IB_MAD_METHOD_DELETE_RESPONSE = 0x95,

	IB_MAD_RESPONSE = 0x80,
};

enum MAD_ATTR_ID {
	CLASS_PORT_INFO = 0x1,
	NOTICE = 0x2,
	INFORM_INFO = 0x3,
};

enum MAD_STATUS {
	IB_MAD_STS_OK = (0 << 2),
	IB_MAD_STS_BUSY = (1 << 0),
	IB_MAD_STS_REDIRECT = (1 << 1),
	IB_MAD_STS_BAD_BASE_VER_OR_CLASS = (1 << 2),
	IB_MAD_STS_METHOD_NOT_SUPPORTED = (2 << 2),
	IB_MAD_STS_METHOD_ATTR_NOT_SUPPORTED = (3 << 2),
	IB_MAD_STS_INV_ATTR_VALUE = (7 << 2),
};

enum SMI_ATTR_ID {
	IB_ATTR_NODE_DESC = 0x10,
	IB_ATTR_NODE_INFO = 0x11,
	IB_ATTR_SWITCH_INFO = 0x12,
	IB_ATTR_GUID_INFO = 0x14,
	IB_ATTR_PORT_INFO = 0x15,
	IB_ATTR_PKEY_TBL = 0x16,
	IB_ATTR_SLVL_TABLE = 0x17,
	IB_ATTR_VL_ARBITRATION = 0x18,
	IB_ATTR_LINEARFORWTBL = 0x19,
	IB_ATTR_MULTICASTFORWTBL = 0x1b,
	IB_ATTR_LINKSPEEDWIDTHPAIRSTBL = 0x1c,
	IB_ATTR_VENDORMADSTBL = 0x1d,
	IB_ATTR_SMINFO = 0x20,

	IB_ATTR_LAST,

	IB_ATTR_MLNX_EXT_PORT_INFO = 0xff90,
};

enum SA_ATTR_ID {
	IB_SA_ATTR_NOTICE = 0x02,
	IB_SA_ATTR_INFORMINFO = 0x03,
	IB_SA_ATTR_NODERECORD = 0x11,
	IB_SA_ATTR_PORTINFORECORD = 0x12,
	IB_SA_ATTR_SL2VLTABLERECORD = 0x13,
	IB_SA_ATTR_SWITCHINFORECORD = 0x14,
	IB_SA_ATTR_LFTRECORD = 0x15,
	IB_SA_ATTR_RFTRECORD = 0x16,
	IB_SA_ATTR_MFTRECORD = 0x17,
	IB_SA_ATTR_SMINFORECORD = 0x18,
	IB_SA_ATTR_LINKRECORD = 0x20,
	IB_SA_ATTR_GUIDINFORECORD = 0x30,
	IB_SA_ATTR_SERVICERECORD = 0x31,
	IB_SA_ATTR_PKEYTABLERECORD = 0x33,
	IB_SA_ATTR_PATHRECORD = 0x35,
	IB_SA_ATTR_VLARBTABLERECORD = 0x36,
	IB_SA_ATTR_MCRECORD = 0x38,
	IB_SA_ATTR_MULTIPATH = 0x3a,
	IB_SA_ATTR_INFORMINFORECORD = 0xf3,

	IB_SA_ATTR_LAST
};

enum GSI_ATTR_ID {
	IB_GSI_PORT_SAMPLES_CONTROL = 0x10,
	IB_GSI_PORT_SAMPLES_RESULT = 0x11,
	IB_GSI_PORT_COUNTERS = 0x12,
	IB_GSI_PORT_RCV_ERROR_DETAILS = 0x15,
	IB_GSI_PORT_XMIT_DISCARD_DETAILS = 0x16,
	IB_GSI_PORT_PORT_OP_RCV_COUNTERS = 0x17,
	IB_GSI_PORT_PORT_FLOW_CTL_COUNTERS = 0x18,
	IB_GSI_PORT_PORT_VL_OP_PACKETS = 0x19,
	IB_GSI_PORT_PORT_VL_OP_DATA = 0x1A,
	IB_GSI_PORT_PORT_VL_XMIT_FLOW_CTL_UPDATE_ERRORS = 0x1B,
	IB_GSI_PORT_PORT_VL_XMIT_WAIT_COUNTERS = 0x1C,
	IB_GSI_PORT_COUNTERS_EXT = 0x1D,
	IB_GSI_PORT_EXT_SPEEDS_COUNTERS = 0x1F,
	IB_GSI_SW_PORT_VL_CONGESTION = 0x30,
	IB_GSI_PORT_RCV_CON_CTRL = 0x31,
	IB_GSI_PORT_SL_RCV_FECN = 0x32,
	IB_GSI_PORT_SL_RCV_BECN = 0x33,
	IB_GSI_PORT_XMIT_CON_CTRL = 0x34,
	IB_GSI_PORT_VL_XMIT_TIME_CONG = 0x35,
	IB_GSI_PORT_XMIT_DATA_SL = 0x36,
	IB_GSI_PORT_RCV_DATA_SL = 0x37,
	IB_GSI_ATTR_LAST
};

enum BM_ATTR_ID {
	IB_BM_ATTR_BKEYINFO = 0x10,
	IB_BM_ATTR_WRITE_VPD = 0x20,
	IB_BM_ATTR_READ_VPD = 0x21,
	IB_BM_ATTR_RESET_IBML = 0x22,
	IB_BM_ATTR_SET_MODULE_PM_CONTROL = 0x23,
	IB_BM_ATTR_GET_MODULE_PM_CONTROL = 0x24,
	IB_BM_ATTR_SET_UNIT_PM_CONTROL = 0x25,
	IB_BM_ATTR_GET_UNIT_PM_CONTROL = 0x26,
	IB_BM_ATTR_SET_IOC_PM_CONTROL = 0x27,
	IB_BM_ATTR_GET_IOC_PM_CONTROL = 0x28,
	IB_BM_ATTR_SET_MODULE_STATE = 0x29,
	IB_BM_ATTR_SET_MODULE_ATTENTION = 0x2A,
	IB_BM_ATTR_GET_MODULE_STATUS = 0x2B,
	IB_BM_ATTR_IB2IBML = 0x2C,
	IB_BM_ATTR_IB2CME = 0x2D,
	IB_BM_ATTR_IB2MME = 0x2E,
	IB_BM_ATTR_OEM = 0x2F,

	IB_BM_ATTR_LAST
};

enum CC_ATTRI_ID {
	IB_CC_ATTR_CONGESTION_INFO = 0x11,
	IB_CC_ATTR_CONGESTION_KEY_INFO = 0x12,
	IB_CC_ATTR_CONGESTION_LOG = 0x13,
	IB_CC_ATTR_SWITCH_CONGESTION_SETTING = 0x14,
	IB_CC_ATTR_SWITCH_PORT_CONGESTION_SETTING = 0x15,
	IB_CC_ATTR_CA_CONGESTION_SETTING = 0x16,
	IB_CC_ATTR_CONGESTION_CONTROL_TABLE = 0x17,
	IB_CC_ATTR_TIMESTAMP = 0x18,
};

#define IB_VENDOR_OPENIB_PING_CLASS	(IB_VENDOR_RANGE2_START_CLASS + 2)
#define IB_VENDOR_OPENIB_SYSSTAT_CLASS	(IB_VENDOR_RANGE2_START_CLASS + 3)
#define IB_OPENIB_OUI			(0x001405)

typedef uint8_t ibmad_gid_t[16];
#ifdef USE_DEPRECATED_IB_GID_T
typedef ibmad_gid_t ib_gid_t __attribute__ ((deprecated));
#endif

typedef struct {
	int cnt;
	uint8_t p[IB_SUBNET_PATH_HOPS_MAX];
	uint16_t drslid;
	uint16_t drdlid;
} ib_dr_path_t;

typedef struct {
	unsigned id;
	unsigned mod;
} ib_attr_t;

typedef struct {
	int mgtclass;
	int method;
	ib_attr_t attr;
	uint32_t rstatus;	/* return status */
	int dataoffs;
	int datasz;
	uint64_t mkey;
	uint64_t trid;		/* used for out mad if nonzero, return real val */
	uint64_t mask;		/* for sa mads */
	unsigned recsz;		/* for sa mads (attribute offset) */
	int timeout;
	uint32_t oui;		/* for vendor range 2 mads */
} ib_rpc_t;

typedef struct {
	int mgtclass;
	int method;
	ib_attr_t attr;
	uint32_t rstatus;	/* return status */
	int dataoffs;
	int datasz;
	uint64_t mkey;
	uint64_t trid;		/* used for out mad if nonzero, return real val */
	uint64_t mask;		/* for sa mads */
	unsigned recsz;		/* for sa mads (attribute offset) */
	int timeout;
	uint32_t oui;		/* for vendor range 2 mads */
	int error;		/* errno */
} ib_rpc_v1_t;

typedef struct {
	int mgtclass;
	int method;
	ib_attr_t attr;
	uint32_t rstatus;       /* return status */
	int dataoffs;
	int datasz;
	uint64_t mkey;
	uint64_t trid;          /* used for out mad if nonzero, return real val */
	uint64_t mask;          /* for sa mads */
	unsigned recsz;         /* for sa mads (attribute offset) */
	int timeout;
	uint32_t oui;           /* for vendor range 2 mads */
	int error;		/* errno */
	uint64_t cckey;
} ib_rpc_cc_t;

typedef struct portid {
	int lid;		/* lid or 0 if directed route */
	ib_dr_path_t drpath;
	int grh_present;	/* flag */
	ibmad_gid_t gid;
	uint32_t qp;
	uint32_t qkey;
	uint8_t sl;
	unsigned pkey_idx;
} ib_portid_t;

typedef void (ib_mad_dump_fn) (char *buf, int bufsz, void *val, int valsz);

#define IB_FIELD_NAME_LEN	32

typedef struct ib_field {
	int bitoffs;
	int bitlen;
	char name[IB_FIELD_NAME_LEN];
	ib_mad_dump_fn *def_dump_fn;
} ib_field_t;

enum MAD_FIELDS {
	IB_NO_FIELD,

	IB_GID_PREFIX_F,
	IB_GID_GUID_F,

	/* first MAD word (0-3 bytes) */
	IB_MAD_METHOD_F,
	IB_MAD_RESPONSE_F,
	IB_MAD_CLASSVER_F,
	IB_MAD_MGMTCLASS_F,
	IB_MAD_BASEVER_F,

	/* second MAD word (4-7 bytes) */
	IB_MAD_STATUS_F,

	/* DRSMP only */
	IB_DRSMP_HOPCNT_F,
	IB_DRSMP_HOPPTR_F,
	IB_DRSMP_STATUS_F,
	IB_DRSMP_DIRECTION_F,

	/* words 3,4,5,6 (8-23 bytes) */
	IB_MAD_TRID_F,
	IB_MAD_ATTRID_F,
	IB_MAD_ATTRMOD_F,

	/* word 7,8 (24-31 bytes) */
	IB_MAD_MKEY_F,

	/* word 9 (32-37 bytes) */
	IB_DRSMP_DRDLID_F,
	IB_DRSMP_DRSLID_F,

	/* word 10,11 (36-43 bytes) */
	IB_SA_MKEY_F,

	/* word 12 (44-47 bytes) */
	IB_SA_ATTROFFS_F,

	/* word 13,14 (48-55 bytes) */
	IB_SA_COMPMASK_F,

	/* word 13,14 (56-255 bytes) */
	IB_SA_DATA_F,

	/* bytes 64 - 127 */
	IB_SM_DATA_F,

	/* bytes 64 - 256 */
	IB_GS_DATA_F,

	/* bytes 128 - 191 */
	IB_DRSMP_PATH_F,

	/* bytes 192 - 255 */
	IB_DRSMP_RPATH_F,

	/*
	 * PortInfo fields
	 */
	IB_PORT_FIRST_F,
	IB_PORT_MKEY_F = IB_PORT_FIRST_F,
	IB_PORT_GID_PREFIX_F,
	IB_PORT_LID_F,
	IB_PORT_SMLID_F,
	IB_PORT_CAPMASK_F,
	IB_PORT_DIAG_F,
	IB_PORT_MKEY_LEASE_F,
	IB_PORT_LOCAL_PORT_F,
	IB_PORT_LINK_WIDTH_ENABLED_F,
	IB_PORT_LINK_WIDTH_SUPPORTED_F,
	IB_PORT_LINK_WIDTH_ACTIVE_F,
	IB_PORT_LINK_SPEED_SUPPORTED_F,
	IB_PORT_STATE_F,
	IB_PORT_PHYS_STATE_F,
	IB_PORT_LINK_DOWN_DEF_F,
	IB_PORT_MKEY_PROT_BITS_F,
	IB_PORT_LMC_F,
	IB_PORT_LINK_SPEED_ACTIVE_F,
	IB_PORT_LINK_SPEED_ENABLED_F,
	IB_PORT_NEIGHBOR_MTU_F,
	IB_PORT_SMSL_F,
	IB_PORT_VL_CAP_F,
	IB_PORT_INIT_TYPE_F,
	IB_PORT_VL_HIGH_LIMIT_F,
	IB_PORT_VL_ARBITRATION_HIGH_CAP_F,
	IB_PORT_VL_ARBITRATION_LOW_CAP_F,
	IB_PORT_INIT_TYPE_REPLY_F,
	IB_PORT_MTU_CAP_F,
	IB_PORT_VL_STALL_COUNT_F,
	IB_PORT_HOQ_LIFE_F,
	IB_PORT_OPER_VLS_F,
	IB_PORT_PART_EN_INB_F,
	IB_PORT_PART_EN_OUTB_F,
	IB_PORT_FILTER_RAW_INB_F,
	IB_PORT_FILTER_RAW_OUTB_F,
	IB_PORT_MKEY_VIOL_F,
	IB_PORT_PKEY_VIOL_F,
	IB_PORT_QKEY_VIOL_F,
	IB_PORT_GUID_CAP_F,
	IB_PORT_CLIENT_REREG_F,
	IB_PORT_MCAST_PKEY_SUPR_ENAB_F,
	IB_PORT_SUBN_TIMEOUT_F,
	IB_PORT_RESP_TIME_VAL_F,
	IB_PORT_LOCAL_PHYS_ERR_F,
	IB_PORT_OVERRUN_ERR_F,
	IB_PORT_MAX_CREDIT_HINT_F,
	IB_PORT_LINK_ROUND_TRIP_F,
	IB_PORT_LAST_F,

	/*
	 * NodeInfo fields
	 */
	IB_NODE_FIRST_F,
	IB_NODE_BASE_VERS_F = IB_NODE_FIRST_F,
	IB_NODE_CLASS_VERS_F,
	IB_NODE_TYPE_F,
	IB_NODE_NPORTS_F,
	IB_NODE_SYSTEM_GUID_F,
	IB_NODE_GUID_F,
	IB_NODE_PORT_GUID_F,
	IB_NODE_PARTITION_CAP_F,
	IB_NODE_DEVID_F,
	IB_NODE_REVISION_F,
	IB_NODE_LOCAL_PORT_F,
	IB_NODE_VENDORID_F,
	IB_NODE_LAST_F,

	/*
	 * SwitchInfo fields
	 */
	IB_SW_FIRST_F,
	IB_SW_LINEAR_FDB_CAP_F = IB_SW_FIRST_F,
	IB_SW_RANDOM_FDB_CAP_F,
	IB_SW_MCAST_FDB_CAP_F,
	IB_SW_LINEAR_FDB_TOP_F,
	IB_SW_DEF_PORT_F,
	IB_SW_DEF_MCAST_PRIM_F,
	IB_SW_DEF_MCAST_NOT_PRIM_F,
	IB_SW_LIFE_TIME_F,
	IB_SW_STATE_CHANGE_F,
	IB_SW_OPT_SLTOVL_MAPPING_F,
	IB_SW_LIDS_PER_PORT_F,
	IB_SW_PARTITION_ENFORCE_CAP_F,
	IB_SW_PARTITION_ENF_INB_F,
	IB_SW_PARTITION_ENF_OUTB_F,
	IB_SW_FILTER_RAW_INB_F,
	IB_SW_FILTER_RAW_OUTB_F,
	IB_SW_ENHANCED_PORT0_F,
	IB_SW_MCAST_FDB_TOP_F,
	IB_SW_LAST_F,

	/*
	 * SwitchLinearForwardingTable fields
	 */
	IB_LINEAR_FORW_TBL_F,

	/*
	 * SwitchMulticastForwardingTable fields
	 */
	IB_MULTICAST_FORW_TBL_F,

	/*
	 * NodeDescription fields
	 */
	IB_NODE_DESC_F,

	/*
	 * Notice/Trap fields
	 */
	IB_NOTICE_IS_GENERIC_F,
	IB_NOTICE_TYPE_F,
	IB_NOTICE_PRODUCER_F,
	IB_NOTICE_TRAP_NUMBER_F,
	IB_NOTICE_ISSUER_LID_F,
	IB_NOTICE_TOGGLE_F,
	IB_NOTICE_COUNT_F,
	IB_NOTICE_DATA_DETAILS_F,
	IB_NOTICE_DATA_LID_F,
	IB_NOTICE_DATA_144_LID_F,
	IB_NOTICE_DATA_144_CAPMASK_F,

	/*
	 * GS Performance
	 */
	IB_PC_FIRST_F,
	IB_PC_PORT_SELECT_F = IB_PC_FIRST_F,
	IB_PC_COUNTER_SELECT_F,
	IB_PC_ERR_SYM_F,
	IB_PC_LINK_RECOVERS_F,
	IB_PC_LINK_DOWNED_F,
	IB_PC_ERR_RCV_F,
	IB_PC_ERR_PHYSRCV_F,
	IB_PC_ERR_SWITCH_REL_F,
	IB_PC_XMT_DISCARDS_F,
	IB_PC_ERR_XMTCONSTR_F,
	IB_PC_ERR_RCVCONSTR_F,
	IB_PC_COUNTER_SELECT2_F,
	IB_PC_ERR_LOCALINTEG_F,
	IB_PC_ERR_EXCESS_OVR_F,
	IB_PC_VL15_DROPPED_F,
	IB_PC_XMT_BYTES_F,
	IB_PC_RCV_BYTES_F,
	IB_PC_XMT_PKTS_F,
	IB_PC_RCV_PKTS_F,
	IB_PC_XMT_WAIT_F,
	IB_PC_LAST_F,

	/*
	 * SMInfo
	 */
	IB_SMINFO_GUID_F,
	IB_SMINFO_KEY_F,
	IB_SMINFO_ACT_F,
	IB_SMINFO_PRIO_F,
	IB_SMINFO_STATE_F,

	/*
	 * SA RMPP
	 */
	IB_SA_RMPP_VERS_F,
	IB_SA_RMPP_TYPE_F,
	IB_SA_RMPP_RESP_F,
	IB_SA_RMPP_FLAGS_F,
	IB_SA_RMPP_STATUS_F,

	/* data1 */
	IB_SA_RMPP_D1_F,
	IB_SA_RMPP_SEGNUM_F,
	/* data2 */
	IB_SA_RMPP_D2_F,
	IB_SA_RMPP_LEN_F,	/* DATA: Payload len */
	IB_SA_RMPP_NEWWIN_F,	/* ACK: new window last */

	/*
	 * SA Multi Path rec
	 */
	IB_SA_MP_NPATH_F,
	IB_SA_MP_NSRC_F,
	IB_SA_MP_NDEST_F,
	IB_SA_MP_GID0_F,

	/*
	 * SA Path rec
	 */
	IB_SA_PR_DGID_F,
	IB_SA_PR_SGID_F,
	IB_SA_PR_DLID_F,
	IB_SA_PR_SLID_F,
	IB_SA_PR_NPATH_F,
	IB_SA_PR_SL_F,

	/*
	 * MC Member rec
	 */
	IB_SA_MCM_MGID_F,
	IB_SA_MCM_PORTGID_F,
	IB_SA_MCM_QKEY_F,
	IB_SA_MCM_MLID_F,
	IB_SA_MCM_SL_F,
	IB_SA_MCM_MTU_F,
	IB_SA_MCM_RATE_F,
	IB_SA_MCM_TCLASS_F,
	IB_SA_MCM_PKEY_F,
	IB_SA_MCM_FLOW_LABEL_F,
	IB_SA_MCM_JOIN_STATE_F,
	IB_SA_MCM_PROXY_JOIN_F,

	/*
	 * Service record
	 */
	IB_SA_SR_ID_F,
	IB_SA_SR_GID_F,
	IB_SA_SR_PKEY_F,
	IB_SA_SR_LEASE_F,
	IB_SA_SR_KEY_F,
	IB_SA_SR_NAME_F,
	IB_SA_SR_DATA_F,

	/*
	 * ATS SM record - within SA_SR_DATA
	 */
	IB_ATS_SM_NODE_ADDR_F,
	IB_ATS_SM_MAGIC_KEY_F,
	IB_ATS_SM_NODE_TYPE_F,
	IB_ATS_SM_NODE_NAME_F,

	/*
	 * SLTOVL MAPPING TABLE
	 */
	IB_SLTOVL_MAPPING_TABLE_F,

	/*
	 * VL ARBITRATION TABLE
	 */
	IB_VL_ARBITRATION_TABLE_F,

	/*
	 * IB vendor class range 2
	 */
	IB_VEND2_OUI_F,
	IB_VEND2_DATA_F,

	/*
	 * PortCountersExtended
	 */
	IB_PC_EXT_FIRST_F,
	IB_PC_EXT_PORT_SELECT_F = IB_PC_EXT_FIRST_F,
	IB_PC_EXT_COUNTER_SELECT_F,
	IB_PC_EXT_XMT_BYTES_F,
	IB_PC_EXT_RCV_BYTES_F,
	IB_PC_EXT_XMT_PKTS_F,
	IB_PC_EXT_RCV_PKTS_F,
	IB_PC_EXT_XMT_UPKTS_F,
	IB_PC_EXT_RCV_UPKTS_F,
	IB_PC_EXT_XMT_MPKTS_F,
	IB_PC_EXT_RCV_MPKTS_F,
	IB_PC_EXT_LAST_F,

	/*
	 * GUIDInfo fields
	 */
	IB_GUID_GUID0_F, /* Obsolete, kept for compatibility
			    Use IB_GI_GUID0_F going forward */

	/*
	 * ClassPortInfo fields
	 */
	IB_CPI_BASEVER_F,
	IB_CPI_CLASSVER_F,
	IB_CPI_CAPMASK_F,
	IB_CPI_CAPMASK2_F,
	IB_CPI_RESP_TIME_VALUE_F,
	IB_CPI_REDIRECT_GID_F,
	IB_CPI_REDIRECT_TC_F,
	IB_CPI_REDIRECT_SL_F,
	IB_CPI_REDIRECT_FL_F,
	IB_CPI_REDIRECT_LID_F,
	IB_CPI_REDIRECT_PKEY_F,
	IB_CPI_REDIRECT_QP_F,
	IB_CPI_REDIRECT_QKEY_F,
	IB_CPI_TRAP_GID_F,
	IB_CPI_TRAP_TC_F,
	IB_CPI_TRAP_SL_F,
	IB_CPI_TRAP_FL_F,
	IB_CPI_TRAP_LID_F,
	IB_CPI_TRAP_PKEY_F,
	IB_CPI_TRAP_HL_F,
	IB_CPI_TRAP_QP_F,
	IB_CPI_TRAP_QKEY_F,

	/*
	 * PortXmitDataSL fields
	 */
	IB_PC_XMT_DATA_SL_FIRST_F,
	IB_PC_XMT_DATA_SL0_F = IB_PC_XMT_DATA_SL_FIRST_F,
	IB_PC_XMT_DATA_SL1_F,
	IB_PC_XMT_DATA_SL2_F,
	IB_PC_XMT_DATA_SL3_F,
	IB_PC_XMT_DATA_SL4_F,
	IB_PC_XMT_DATA_SL5_F,
	IB_PC_XMT_DATA_SL6_F,
	IB_PC_XMT_DATA_SL7_F,
	IB_PC_XMT_DATA_SL8_F,
	IB_PC_XMT_DATA_SL9_F,
	IB_PC_XMT_DATA_SL10_F,
	IB_PC_XMT_DATA_SL11_F,
	IB_PC_XMT_DATA_SL12_F,
	IB_PC_XMT_DATA_SL13_F,
	IB_PC_XMT_DATA_SL14_F,
	IB_PC_XMT_DATA_SL15_F,
	IB_PC_XMT_DATA_SL_LAST_F,

	/*
	 * PortRcvDataSL fields
	 */
	IB_PC_RCV_DATA_SL_FIRST_F,
	IB_PC_RCV_DATA_SL0_F = IB_PC_RCV_DATA_SL_FIRST_F,
	IB_PC_RCV_DATA_SL1_F,
	IB_PC_RCV_DATA_SL2_F,
	IB_PC_RCV_DATA_SL3_F,
	IB_PC_RCV_DATA_SL4_F,
	IB_PC_RCV_DATA_SL5_F,
	IB_PC_RCV_DATA_SL6_F,
	IB_PC_RCV_DATA_SL7_F,
	IB_PC_RCV_DATA_SL8_F,
	IB_PC_RCV_DATA_SL9_F,
	IB_PC_RCV_DATA_SL10_F,
	IB_PC_RCV_DATA_SL11_F,
	IB_PC_RCV_DATA_SL12_F,
	IB_PC_RCV_DATA_SL13_F,
	IB_PC_RCV_DATA_SL14_F,
	IB_PC_RCV_DATA_SL15_F,
	IB_PC_RCV_DATA_SL_LAST_F,

	/*
	 * PortXmitDiscardDetails fields
	 */
	IB_PC_XMT_INACT_DISC_F,
	IB_PC_XMT_NEIGH_MTU_DISC_F,
	IB_PC_XMT_SW_LIFE_DISC_F,
	IB_PC_XMT_SW_HOL_DISC_F,
	IB_PC_XMT_DISC_LAST_F,

	/*
	 * PortRcvErrorDetails fields
	 */
	IB_PC_RCV_LOCAL_PHY_ERR_F,
	IB_PC_RCV_MALFORMED_PKT_ERR_F,
	IB_PC_RCV_BUF_OVR_ERR_F,
	IB_PC_RCV_DLID_MAP_ERR_F,
	IB_PC_RCV_VL_MAP_ERR_F,
	IB_PC_RCV_LOOPING_ERR_F,
	IB_PC_RCV_ERR_LAST_F,

	/*
	 * PortSamplesControl fields
	 */
	IB_PSC_OPCODE_F,
	IB_PSC_PORT_SELECT_F,
	IB_PSC_TICK_F,
	IB_PSC_COUNTER_WIDTH_F,
	IB_PSC_COUNTER_MASK0_F,
	IB_PSC_COUNTER_MASKS1TO9_F,
	IB_PSC_COUNTER_MASKS10TO14_F,
	IB_PSC_SAMPLE_MECHS_F,
	IB_PSC_SAMPLE_STATUS_F,
	IB_PSC_OPTION_MASK_F,
	IB_PSC_VENDOR_MASK_F,
	IB_PSC_SAMPLE_START_F,
	IB_PSC_SAMPLE_INTVL_F,
	IB_PSC_TAG_F,
	IB_PSC_COUNTER_SEL0_F,
	IB_PSC_COUNTER_SEL1_F,
	IB_PSC_COUNTER_SEL2_F,
	IB_PSC_COUNTER_SEL3_F,
	IB_PSC_COUNTER_SEL4_F,
	IB_PSC_COUNTER_SEL5_F,
	IB_PSC_COUNTER_SEL6_F,
	IB_PSC_COUNTER_SEL7_F,
	IB_PSC_COUNTER_SEL8_F,
	IB_PSC_COUNTER_SEL9_F,
	IB_PSC_COUNTER_SEL10_F,
	IB_PSC_COUNTER_SEL11_F,
	IB_PSC_COUNTER_SEL12_F,
	IB_PSC_COUNTER_SEL13_F,
	IB_PSC_COUNTER_SEL14_F,
	IB_PSC_SAMPLES_ONLY_OPT_MASK_F,
	IB_PSC_LAST_F,

	/*
	 * GUIDInfo fields
	 */
	IB_GI_GUID0_F, /* a duplicate of IB_GUID_GUID0_F for backwards
			  compatibility */
	IB_GI_GUID1_F,
	IB_GI_GUID2_F,
	IB_GI_GUID3_F,
	IB_GI_GUID4_F,
	IB_GI_GUID5_F,
	IB_GI_GUID6_F,
	IB_GI_GUID7_F,

	/*
	 * GUID Info Record
	 */
	IB_SA_GIR_LID_F,
	IB_SA_GIR_BLOCKNUM_F,
	IB_SA_GIR_GUID0_F,
	IB_SA_GIR_GUID1_F,
	IB_SA_GIR_GUID2_F,
	IB_SA_GIR_GUID3_F,
	IB_SA_GIR_GUID4_F,
	IB_SA_GIR_GUID5_F,
	IB_SA_GIR_GUID6_F,
	IB_SA_GIR_GUID7_F,

	/*
	 * More PortInfo fields
	 */
	IB_PORT_CAPMASK2_F,
	IB_PORT_LINK_SPEED_EXT_ACTIVE_F,
	IB_PORT_LINK_SPEED_EXT_SUPPORTED_F,
	IB_PORT_LINK_SPEED_EXT_ENABLED_F,
	IB_PORT_LINK_SPEED_EXT_LAST_F,

	/*
	 * PortExtendedSpeedsCounters fields
	 */
	IB_PESC_PORT_SELECT_F,
	IB_PESC_COUNTER_SELECT_F,
	IB_PESC_SYNC_HDR_ERR_CTR_F,
	IB_PESC_UNK_BLOCK_CTR_F,
	IB_PESC_ERR_DET_CTR_LANE0_F,
	IB_PESC_ERR_DET_CTR_LANE1_F,
	IB_PESC_ERR_DET_CTR_LANE2_F,
	IB_PESC_ERR_DET_CTR_LANE3_F,
	IB_PESC_ERR_DET_CTR_LANE4_F,
	IB_PESC_ERR_DET_CTR_LANE5_F,
	IB_PESC_ERR_DET_CTR_LANE6_F,
	IB_PESC_ERR_DET_CTR_LANE7_F,
	IB_PESC_ERR_DET_CTR_LANE8_F,
	IB_PESC_ERR_DET_CTR_LANE9_F,
	IB_PESC_ERR_DET_CTR_LANE10_F,
	IB_PESC_ERR_DET_CTR_LANE11_F,
	IB_PESC_FEC_CORR_BLOCK_CTR_LANE0_F,
	IB_PESC_FEC_CORR_BLOCK_CTR_LANE1_F,
	IB_PESC_FEC_CORR_BLOCK_CTR_LANE2_F,
	IB_PESC_FEC_CORR_BLOCK_CTR_LANE3_F,
	IB_PESC_FEC_CORR_BLOCK_CTR_LANE4_F,
	IB_PESC_FEC_CORR_BLOCK_CTR_LANE5_F,
	IB_PESC_FEC_CORR_BLOCK_CTR_LANE6_F,
	IB_PESC_FEC_CORR_BLOCK_CTR_LANE7_F,
	IB_PESC_FEC_CORR_BLOCK_CTR_LANE8_F,
	IB_PESC_FEC_CORR_BLOCK_CTR_LANE9_F,
	IB_PESC_FEC_CORR_BLOCK_CTR_LANE10_F,
	IB_PESC_FEC_CORR_BLOCK_CTR_LANE11_F,
	IB_PESC_FEC_UNCORR_BLOCK_CTR_LANE0_F,
	IB_PESC_FEC_UNCORR_BLOCK_CTR_LANE1_F,
	IB_PESC_FEC_UNCORR_BLOCK_CTR_LANE2_F,
	IB_PESC_FEC_UNCORR_BLOCK_CTR_LANE3_F,
	IB_PESC_FEC_UNCORR_BLOCK_CTR_LANE4_F,
	IB_PESC_FEC_UNCORR_BLOCK_CTR_LANE5_F,
	IB_PESC_FEC_UNCORR_BLOCK_CTR_LANE6_F,
	IB_PESC_FEC_UNCORR_BLOCK_CTR_LANE7_F,
	IB_PESC_FEC_UNCORR_BLOCK_CTR_LANE8_F,
	IB_PESC_FEC_UNCORR_BLOCK_CTR_LANE9_F,
	IB_PESC_FEC_UNCORR_BLOCK_CTR_LANE10_F,
	IB_PESC_FEC_UNCORR_BLOCK_CTR_LANE11_F,
	IB_PESC_LAST_F,

	/*
	 * PortOpRcvCounters fields
	 */
	IB_PC_PORT_OP_RCV_COUNTERS_FIRST_F,
	IB_PC_PORT_OP_RCV_PKTS_F = IB_PC_PORT_OP_RCV_COUNTERS_FIRST_F,
	IB_PC_PORT_OP_RCV_DATA_F,
	IB_PC_PORT_OP_RCV_COUNTERS_LAST_F,

	/*
	 * PortFlowCtlCounters fields
	 */
	IB_PC_PORT_FLOW_CTL_COUNTERS_FIRST_F,
	IB_PC_PORT_XMIT_FLOW_PKTS_F = IB_PC_PORT_FLOW_CTL_COUNTERS_FIRST_F,
	IB_PC_PORT_RCV_FLOW_PKTS_F,
	IB_PC_PORT_FLOW_CTL_COUNTERS_LAST_F,

	/*
	 * PortVLOpPackets fields
	 */
	IB_PC_PORT_VL_OP_PACKETS_FIRST_F,
	IB_PC_PORT_VL_OP_PACKETS0_F = IB_PC_PORT_VL_OP_PACKETS_FIRST_F,
	IB_PC_PORT_VL_OP_PACKETS1_F,
	IB_PC_PORT_VL_OP_PACKETS2_F,
	IB_PC_PORT_VL_OP_PACKETS3_F,
	IB_PC_PORT_VL_OP_PACKETS4_F,
	IB_PC_PORT_VL_OP_PACKETS5_F,
	IB_PC_PORT_VL_OP_PACKETS6_F,
	IB_PC_PORT_VL_OP_PACKETS7_F,
	IB_PC_PORT_VL_OP_PACKETS8_F,
	IB_PC_PORT_VL_OP_PACKETS9_F,
	IB_PC_PORT_VL_OP_PACKETS10_F,
	IB_PC_PORT_VL_OP_PACKETS11_F,
	IB_PC_PORT_VL_OP_PACKETS12_F,
	IB_PC_PORT_VL_OP_PACKETS13_F,
	IB_PC_PORT_VL_OP_PACKETS14_F,
	IB_PC_PORT_VL_OP_PACKETS15_F,
	IB_PC_PORT_VL_OP_PACKETS_LAST_F,

	/*
	 * PortVLOpData fields
	 */
	IB_PC_PORT_VL_OP_DATA_FIRST_F,
	IB_PC_PORT_VL_OP_DATA0_F = IB_PC_PORT_VL_OP_DATA_FIRST_F,
	IB_PC_PORT_VL_OP_DATA1_F,
	IB_PC_PORT_VL_OP_DATA2_F,
	IB_PC_PORT_VL_OP_DATA3_F,
	IB_PC_PORT_VL_OP_DATA4_F,
	IB_PC_PORT_VL_OP_DATA5_F,
	IB_PC_PORT_VL_OP_DATA6_F,
	IB_PC_PORT_VL_OP_DATA7_F,
	IB_PC_PORT_VL_OP_DATA8_F,
	IB_PC_PORT_VL_OP_DATA9_F,
	IB_PC_PORT_VL_OP_DATA10_F,
	IB_PC_PORT_VL_OP_DATA11_F,
	IB_PC_PORT_VL_OP_DATA12_F,
	IB_PC_PORT_VL_OP_DATA13_F,
	IB_PC_PORT_VL_OP_DATA14_F,
	IB_PC_PORT_VL_OP_DATA15_F,
	IB_PC_PORT_VL_OP_DATA_LAST_F,

	/*
	 * PortVLXmitFlowCtlUpdateErrors fields
	 */
	IB_PC_PORT_VL_XMIT_FLOW_CTL_UPDATE_ERRORS_FIRST_F,
	IB_PC_PORT_VL_XMIT_FLOW_CTL_UPDATE_ERRORS0_F = IB_PC_PORT_VL_XMIT_FLOW_CTL_UPDATE_ERRORS_FIRST_F,
	IB_PC_PORT_VL_XMIT_FLOW_CTL_UPDATE_ERRORS1_F,
	IB_PC_PORT_VL_XMIT_FLOW_CTL_UPDATE_ERRORS2_F,
	IB_PC_PORT_VL_XMIT_FLOW_CTL_UPDATE_ERRORS3_F,
	IB_PC_PORT_VL_XMIT_FLOW_CTL_UPDATE_ERRORS4_F,
	IB_PC_PORT_VL_XMIT_FLOW_CTL_UPDATE_ERRORS5_F,
	IB_PC_PORT_VL_XMIT_FLOW_CTL_UPDATE_ERRORS6_F,
	IB_PC_PORT_VL_XMIT_FLOW_CTL_UPDATE_ERRORS7_F,
	IB_PC_PORT_VL_XMIT_FLOW_CTL_UPDATE_ERRORS8_F,
	IB_PC_PORT_VL_XMIT_FLOW_CTL_UPDATE_ERRORS9_F,
	IB_PC_PORT_VL_XMIT_FLOW_CTL_UPDATE_ERRORS10_F,
	IB_PC_PORT_VL_XMIT_FLOW_CTL_UPDATE_ERRORS11_F,
	IB_PC_PORT_VL_XMIT_FLOW_CTL_UPDATE_ERRORS12_F,
	IB_PC_PORT_VL_XMIT_FLOW_CTL_UPDATE_ERRORS13_F,
	IB_PC_PORT_VL_XMIT_FLOW_CTL_UPDATE_ERRORS14_F,
	IB_PC_PORT_VL_XMIT_FLOW_CTL_UPDATE_ERRORS15_F,
	IB_PC_PORT_VL_XMIT_FLOW_CTL_UPDATE_ERRORS_LAST_F,

	/*
	 * PortVLXmitWaitCounters fields
	 */
	IB_PC_PORT_VL_XMIT_WAIT_COUNTERS_FIRST_F,
	IB_PC_PORT_VL_XMIT_WAIT0_F = IB_PC_PORT_VL_XMIT_WAIT_COUNTERS_FIRST_F,
	IB_PC_PORT_VL_XMIT_WAIT1_F,
	IB_PC_PORT_VL_XMIT_WAIT2_F,
	IB_PC_PORT_VL_XMIT_WAIT3_F,
	IB_PC_PORT_VL_XMIT_WAIT4_F,
	IB_PC_PORT_VL_XMIT_WAIT5_F,
	IB_PC_PORT_VL_XMIT_WAIT6_F,
	IB_PC_PORT_VL_XMIT_WAIT7_F,
	IB_PC_PORT_VL_XMIT_WAIT8_F,
	IB_PC_PORT_VL_XMIT_WAIT9_F,
	IB_PC_PORT_VL_XMIT_WAIT10_F,
	IB_PC_PORT_VL_XMIT_WAIT11_F,
	IB_PC_PORT_VL_XMIT_WAIT12_F,
	IB_PC_PORT_VL_XMIT_WAIT13_F,
	IB_PC_PORT_VL_XMIT_WAIT14_F,
	IB_PC_PORT_VL_XMIT_WAIT15_F,
	IB_PC_PORT_VL_XMIT_WAIT_COUNTERS_LAST_F,

	/*
	 * SwPortVLCongestion fields
	 */
	IB_PC_SW_PORT_VL_CONGESTION_FIRST_F,
	IB_PC_SW_PORT_VL_CONGESTION0_F = IB_PC_SW_PORT_VL_CONGESTION_FIRST_F,
	IB_PC_SW_PORT_VL_CONGESTION1_F,
	IB_PC_SW_PORT_VL_CONGESTION2_F,
	IB_PC_SW_PORT_VL_CONGESTION3_F,
	IB_PC_SW_PORT_VL_CONGESTION4_F,
	IB_PC_SW_PORT_VL_CONGESTION5_F,
	IB_PC_SW_PORT_VL_CONGESTION6_F,
	IB_PC_SW_PORT_VL_CONGESTION7_F,
	IB_PC_SW_PORT_VL_CONGESTION8_F,
	IB_PC_SW_PORT_VL_CONGESTION9_F,
	IB_PC_SW_PORT_VL_CONGESTION10_F,
	IB_PC_SW_PORT_VL_CONGESTION11_F,
	IB_PC_SW_PORT_VL_CONGESTION12_F,
	IB_PC_SW_PORT_VL_CONGESTION13_F,
	IB_PC_SW_PORT_VL_CONGESTION14_F,
	IB_PC_SW_PORT_VL_CONGESTION15_F,
	IB_PC_SW_PORT_VL_CONGESTION_LAST_F,

	/*
	 * PortRcvConCtrl fields
	 */
	IB_PC_RCV_CON_CTRL_FIRST_F,
	IB_PC_RCV_CON_CTRL_PKT_RCV_FECN_F = IB_PC_RCV_CON_CTRL_FIRST_F,
	IB_PC_RCV_CON_CTRL_PKT_RCV_BECN_F,
	IB_PC_RCV_CON_CTRL_LAST_F,

	/*
	 * PortSLRcvFECN fields
	 */
	IB_PC_SL_RCV_FECN_FIRST_F,
	IB_PC_SL_RCV_FECN0_F = IB_PC_SL_RCV_FECN_FIRST_F,
	IB_PC_SL_RCV_FECN1_F,
	IB_PC_SL_RCV_FECN2_F,
	IB_PC_SL_RCV_FECN3_F,
	IB_PC_SL_RCV_FECN4_F,
	IB_PC_SL_RCV_FECN5_F,
	IB_PC_SL_RCV_FECN6_F,
	IB_PC_SL_RCV_FECN7_F,
	IB_PC_SL_RCV_FECN8_F,
	IB_PC_SL_RCV_FECN9_F,
	IB_PC_SL_RCV_FECN10_F,
	IB_PC_SL_RCV_FECN11_F,
	IB_PC_SL_RCV_FECN12_F,
	IB_PC_SL_RCV_FECN13_F,
	IB_PC_SL_RCV_FECN14_F,
	IB_PC_SL_RCV_FECN15_F,
	IB_PC_SL_RCV_FECN_LAST_F,

	/*
	 * PortSLRcvBECN fields
	 */
	IB_PC_SL_RCV_BECN_FIRST_F,
	IB_PC_SL_RCV_BECN0_F = IB_PC_SL_RCV_BECN_FIRST_F,
	IB_PC_SL_RCV_BECN1_F,
	IB_PC_SL_RCV_BECN2_F,
	IB_PC_SL_RCV_BECN3_F,
	IB_PC_SL_RCV_BECN4_F,
	IB_PC_SL_RCV_BECN5_F,
	IB_PC_SL_RCV_BECN6_F,
	IB_PC_SL_RCV_BECN7_F,
	IB_PC_SL_RCV_BECN8_F,
	IB_PC_SL_RCV_BECN9_F,
	IB_PC_SL_RCV_BECN10_F,
	IB_PC_SL_RCV_BECN11_F,
	IB_PC_SL_RCV_BECN12_F,
	IB_PC_SL_RCV_BECN13_F,
	IB_PC_SL_RCV_BECN14_F,
	IB_PC_SL_RCV_BECN15_F,
	IB_PC_SL_RCV_BECN_LAST_F,

	/*
	 * PortXmitConCtrl fields
	 */
	IB_PC_XMIT_CON_CTRL_FIRST_F,
	IB_PC_XMIT_CON_CTRL_TIME_CONG_F = IB_PC_XMIT_CON_CTRL_FIRST_F,
	IB_PC_XMIT_CON_CTRL_LAST_F,

	/*
	 * PortVLXmitTimeCong fields
	 */
	IB_PC_VL_XMIT_TIME_CONG_FIRST_F,
	IB_PC_VL_XMIT_TIME_CONG0_F = IB_PC_VL_XMIT_TIME_CONG_FIRST_F,
	IB_PC_VL_XMIT_TIME_CONG1_F,
	IB_PC_VL_XMIT_TIME_CONG2_F,
	IB_PC_VL_XMIT_TIME_CONG3_F,
	IB_PC_VL_XMIT_TIME_CONG4_F,
	IB_PC_VL_XMIT_TIME_CONG5_F,
	IB_PC_VL_XMIT_TIME_CONG6_F,
	IB_PC_VL_XMIT_TIME_CONG7_F,
	IB_PC_VL_XMIT_TIME_CONG8_F,
	IB_PC_VL_XMIT_TIME_CONG9_F,
	IB_PC_VL_XMIT_TIME_CONG10_F,
	IB_PC_VL_XMIT_TIME_CONG11_F,
	IB_PC_VL_XMIT_TIME_CONG12_F,
	IB_PC_VL_XMIT_TIME_CONG13_F,
	IB_PC_VL_XMIT_TIME_CONG14_F,
	IB_PC_VL_XMIT_TIME_CONG_LAST_F,

	/*
	 * Mellanox ExtendedPortInfo fields
	 */
	IB_MLNX_EXT_PORT_STATE_CHG_ENABLE_F,
	IB_MLNX_EXT_PORT_LINK_SPEED_SUPPORTED_F,
	IB_MLNX_EXT_PORT_LINK_SPEED_ENABLED_F,
	IB_MLNX_EXT_PORT_LINK_SPEED_ACTIVE_F,
	IB_MLNX_EXT_PORT_LAST_F,

	/*
	 * Congestion Control Mad fields
	 * bytes 24-31 of congestion control mad
	 */
	IB_CC_CCKEY_F,

	/*
	 * CongestionInfo fields
	 */
	IB_CC_CONGESTION_INFO_FIRST_F,
	IB_CC_CONGESTION_INFO_F = IB_CC_CONGESTION_INFO_FIRST_F,
	IB_CC_CONGESTION_INFO_CONTROL_TABLE_CAP_F,
	IB_CC_CONGESTION_INFO_LAST_F,

	/*
	 * CongestionKeyInfo fields
	 */
	IB_CC_CONGESTION_KEY_INFO_FIRST_F,
	IB_CC_CONGESTION_KEY_INFO_CC_KEY_F = IB_CC_CONGESTION_KEY_INFO_FIRST_F,
	IB_CC_CONGESTION_KEY_INFO_CC_KEY_PROTECT_BIT_F,
	IB_CC_CONGESTION_KEY_INFO_CC_KEY_LEASE_PERIOD_F,
	IB_CC_CONGESTION_KEY_INFO_CC_KEY_VIOLATIONS_F,
	IB_CC_CONGESTION_KEY_INFO_LAST_F,

	/*
	 * CongestionLog (common) fields
	 */
	IB_CC_CONGESTION_LOG_FIRST_F,
	IB_CC_CONGESTION_LOG_LOGTYPE_F = IB_CC_CONGESTION_LOG_FIRST_F,
	IB_CC_CONGESTION_LOG_CONGESTION_FLAGS_F,
	IB_CC_CONGESTION_LOG_LAST_F,

	/*
	 * CongestionLog (Switch) fields
	 */
	IB_CC_CONGESTION_LOG_SWITCH_FIRST_F,
	IB_CC_CONGESTION_LOG_SWITCH_LOG_EVENTS_COUNTER_F = IB_CC_CONGESTION_LOG_SWITCH_FIRST_F,
	IB_CC_CONGESTION_LOG_SWITCH_CURRENT_TIME_STAMP_F,
	IB_CC_CONGESTION_LOG_SWITCH_PORTMAP_F,
	IB_CC_CONGESTION_LOG_SWITCH_LAST_F,

	/*
	 * CongestionLogEvent (Switch) fields
	 */
	IB_CC_CONGESTION_LOG_ENTRY_SWITCH_FIRST_F,
	IB_CC_CONGESTION_LOG_ENTRY_SWITCH_SLID_F = IB_CC_CONGESTION_LOG_ENTRY_SWITCH_FIRST_F,
	IB_CC_CONGESTION_LOG_ENTRY_SWITCH_DLID_F,
	IB_CC_CONGESTION_LOG_ENTRY_SWITCH_SL_F,
	IB_CC_CONGESTION_LOG_ENTRY_SWITCH_TIMESTAMP_F,
	IB_CC_CONGESTION_LOG_ENTRY_SWITCH_LAST_F,

	/*
	 * CongestionLog (CA) fields
	 */
	IB_CC_CONGESTION_LOG_CA_FIRST_F,
	IB_CC_CONGESTION_LOG_CA_THRESHOLD_EVENT_COUNTER_F = IB_CC_CONGESTION_LOG_CA_FIRST_F,
	IB_CC_CONGESTION_LOG_CA_THRESHOLD_CONGESTION_EVENT_MAP_F,
	IB_CC_CONGESTION_LOG_CA_CURRENT_TIMESTAMP_F,
	IB_CC_CONGESTION_LOG_CA_LAST_F,

	/*
	 * CongestionLogEvent (CA) fields
	 */
	IB_CC_CONGESTION_LOG_ENTRY_CA_FIRST_F,
	IB_CC_CONGESTION_LOG_ENTRY_CA_LOCAL_QP_CN_ENTRY_F = IB_CC_CONGESTION_LOG_ENTRY_CA_FIRST_F,
	IB_CC_CONGESTION_LOG_ENTRY_CA_SL_CN_ENTRY_F,
	IB_CC_CONGESTION_LOG_ENTRY_CA_SERVICE_TYPE_CN_ENTRY_F,
	IB_CC_CONGESTION_LOG_ENTRY_CA_REMOTE_QP_NUMBER_CN_ENTRY_F,
	IB_CC_CONGESTION_LOG_ENTRY_CA_LOCAL_LID_CN_F,
	IB_CC_CONGESTION_LOG_ENTRY_CA_REMOTE_LID_CN_ENTRY_F,
	IB_CC_CONGESTION_LOG_ENTRY_CA_TIMESTAMP_CN_ENTRY_F,
	IB_CC_CONGESTION_LOG_ENTRY_CA_LAST_F,

	/*
	 * SwitchCongestionSetting fields
	 */
	IB_CC_SWITCH_CONGESTION_SETTING_FIRST_F,
	IB_CC_SWITCH_CONGESTION_SETTING_CONTROL_MAP_F = IB_CC_SWITCH_CONGESTION_SETTING_FIRST_F,
	IB_CC_SWITCH_CONGESTION_SETTING_VICTIM_MASK_F,
	IB_CC_SWITCH_CONGESTION_SETTING_CREDIT_MASK_F,
	IB_CC_SWITCH_CONGESTION_SETTING_THRESHOLD_F,
	IB_CC_SWITCH_CONGESTION_SETTING_PACKET_SIZE_F,
	IB_CC_SWITCH_CONGESTION_SETTING_CS_THRESHOLD_F,
	IB_CC_SWITCH_CONGESTION_SETTING_CS_RETURN_DELAY_F,
	IB_CC_SWITCH_CONGESTION_SETTING_MARKING_RATE_F,
	IB_CC_SWITCH_CONGESTION_SETTING_LAST_F,

	/*
	 * SwitchPortCongestionSettingElement fields
	 */
	IB_CC_SWITCH_PORT_CONGESTION_SETTING_ELEMENT_FIRST_F,
	IB_CC_SWITCH_PORT_CONGESTION_SETTING_ELEMENT_VALID_F = IB_CC_SWITCH_PORT_CONGESTION_SETTING_ELEMENT_FIRST_F,
	IB_CC_SWITCH_PORT_CONGESTION_SETTING_ELEMENT_CONTROL_TYPE_F,
	IB_CC_SWITCH_PORT_CONGESTION_SETTING_ELEMENT_THRESHOLD_F,
	IB_CC_SWITCH_PORT_CONGESTION_SETTING_ELEMENT_PACKET_SIZE_F,
	IB_CC_SWITCH_PORT_CONGESTION_SETTING_ELEMENT_CONG_PARM_MARKING_RATE_F,
	IB_CC_SWITCH_PORT_CONGESTION_SETTING_ELEMENT_LAST_F,

	/*
	 * CACongestionSetting fields
	 */
	IB_CC_CA_CONGESTION_SETTING_FIRST_F,
	IB_CC_CA_CONGESTION_SETTING_PORT_CONTROL_F = IB_CC_CA_CONGESTION_SETTING_FIRST_F,
	IB_CC_CA_CONGESTION_SETTING_CONTROL_MAP_F,
	IB_CC_CA_CONGESTION_SETTING_LAST_F,

	/*
	 * CACongestionEntry fields
	 */
	IB_CC_CA_CONGESTION_ENTRY_FIRST_F,
	IB_CC_CA_CONGESTION_ENTRY_CCTI_TIMER_F = IB_CC_CA_CONGESTION_ENTRY_FIRST_F,
	IB_CC_CA_CONGESTION_ENTRY_CCTI_INCREASE_F,
	IB_CC_CA_CONGESTION_ENTRY_TRIGGER_THRESHOLD_F,
	IB_CC_CA_CONGESTION_ENTRY_CCTI_MIN_F,
	IB_CC_CA_CONGESTION_ENTRY_LAST_F,

	/*
	 * CongestionControlTable fields
	 */
	IB_CC_CONGESTION_CONTROL_TABLE_FIRST_F,
	IB_CC_CONGESTION_CONTROL_TABLE_CCTI_LIMIT_F = IB_CC_CONGESTION_CONTROL_TABLE_FIRST_F,
	IB_CC_CONGESTION_CONTROL_TABLE_LAST_F,

	/*
	 * CongestionControlTableEntry fields
	 */
	IB_CC_CONGESTION_CONTROL_TABLE_ENTRY_FIRST_F,
	IB_CC_CONGESTION_CONTROL_TABLE_ENTRY_CCT_SHIFT_F = IB_CC_CONGESTION_CONTROL_TABLE_ENTRY_FIRST_F,
	IB_CC_CONGESTION_CONTROL_TABLE_ENTRY_CCT_MULTIPLIER_F,
	IB_CC_CONGESTION_CONTROL_TABLE_ENTRY_LAST_F,

	/*
	 * Timestamp fields
	 */
	IB_CC_TIMESTAMP_FIRST_F,
	IB_CC_TIMESTAMP_F = IB_CC_TIMESTAMP_FIRST_F,
	IB_CC_TIMESTAMP_LAST_F,

	IB_FIELD_LAST_		/* must be last */
};

/*
 * SA RMPP section
 */
enum RMPP_TYPE_ENUM {
	IB_RMPP_TYPE_NONE,
	IB_RMPP_TYPE_DATA,
	IB_RMPP_TYPE_ACK,
	IB_RMPP_TYPE_STOP,
	IB_RMPP_TYPE_ABORT,
};

enum RMPP_FLAGS_ENUM {
	IB_RMPP_FLAG_ACTIVE = 1 << 0,
	IB_RMPP_FLAG_FIRST = 1 << 1,
	IB_RMPP_FLAG_LAST = 1 << 2,
};

typedef struct {
	int type;
	int flags;
	int status;
	union {
		uint32_t u;
		uint32_t segnum;
	} d1;
	union {
		uint32_t u;
		uint32_t len;
		uint32_t newwin;
	} d2;
} ib_rmpp_hdr_t;

enum SA_SIZES_ENUM {
	SA_HEADER_SZ = 20,
};

typedef struct ib_sa_call {
	unsigned attrid;
	unsigned mod;
	uint64_t mask;
	unsigned method;

	uint64_t trid;		/* used for out mad if nonzero, return real val */
	unsigned recsz;		/* return field */
	ib_rmpp_hdr_t rmpp;
} ib_sa_call_t;

typedef struct ib_vendor_call {
	unsigned method;
	unsigned mgmt_class;
	unsigned attrid;
	unsigned mod;
	uint32_t oui;
	unsigned timeout;
	ib_rmpp_hdr_t rmpp;
} ib_vendor_call_t;

typedef struct ib_bm_call {
	unsigned method;
	unsigned attrid;
	unsigned mod;
	unsigned timeout;
	uint64_t bkey;
} ib_bm_call_t;

#define IB_MIN_UCAST_LID	1
#define IB_MAX_UCAST_LID	(0xc000-1)
#define IB_MIN_MCAST_LID	0xc000
#define IB_MAX_MCAST_LID	(0xffff-1)

#define IB_LID_VALID(lid)	((lid) >= IB_MIN_UCAST_LID && lid <= IB_MAX_UCAST_LID)
#define IB_MLID_VALID(lid)	((lid) >= IB_MIN_MCAST_LID && lid <= IB_MAX_MCAST_LID)

#define MAD_DEF_RETRIES		3
#define MAD_DEF_TIMEOUT_MS	1000

enum MAD_DEST {
	IB_DEST_LID,
	IB_DEST_DRPATH,
	IB_DEST_GUID,
	IB_DEST_DRSLID,
	IB_DEST_GID
};

enum MAD_NODE_TYPE {
	IB_NODE_CA = 1,
	IB_NODE_SWITCH,
	IB_NODE_ROUTER,
	NODE_RNIC,

	IB_NODE_MAX = NODE_RNIC
};

/******************************************************************************/

/* portid.c */
MAD_EXPORT char *portid2str(ib_portid_t * portid);
MAD_EXPORT int portid2portnum(ib_portid_t * portid);
MAD_EXPORT int str2drpath(ib_dr_path_t * path, char *routepath, int drslid,
			  int drdlid);
MAD_EXPORT char *drpath2str(ib_dr_path_t * path, char *dstr, size_t dstr_size);

static inline int ib_portid_set(ib_portid_t * portid, int lid, int qp, int qkey)
{
	portid->lid = lid;
	portid->qp = qp;
	portid->qkey = qkey;
	portid->grh_present = 0;

	return 0;
}

/* fields.c */
MAD_EXPORT uint32_t mad_get_field(void *buf, int base_offs,
				  enum MAD_FIELDS field);
MAD_EXPORT void mad_set_field(void *buf, int base_offs, enum MAD_FIELDS field,
			      uint32_t val);
/* field must be byte aligned */
MAD_EXPORT uint64_t mad_get_field64(void *buf, int base_offs,
				    enum MAD_FIELDS field);
MAD_EXPORT void mad_set_field64(void *buf, int base_offs, enum MAD_FIELDS field,
				uint64_t val);
MAD_EXPORT void mad_set_array(void *buf, int base_offs, enum MAD_FIELDS field,
			      void *val);
MAD_EXPORT void mad_get_array(void *buf, int base_offs, enum MAD_FIELDS field,
			      void *val);
MAD_EXPORT void mad_decode_field(uint8_t * buf, enum MAD_FIELDS field,
				 void *val);
MAD_EXPORT void mad_encode_field(uint8_t * buf, enum MAD_FIELDS field,
				 void *val);
MAD_EXPORT int mad_print_field(enum MAD_FIELDS field, const char *name,
			       void *val);
MAD_EXPORT char *mad_dump_field(enum MAD_FIELDS field, char *buf, int bufsz,
				void *val);
MAD_EXPORT char *mad_dump_val(enum MAD_FIELDS field, char *buf, int bufsz,
			      void *val);
MAD_EXPORT const char *mad_field_name(enum MAD_FIELDS field);

/* mad.c */
MAD_EXPORT void *mad_encode(void *buf, ib_rpc_t * rpc, ib_dr_path_t * drpath,
			    void *data);
MAD_EXPORT uint64_t mad_trid(void);
MAD_EXPORT int mad_build_pkt(void *umad, ib_rpc_t * rpc, ib_portid_t * dport,
			     ib_rmpp_hdr_t * rmpp, void *data);

/* New interface */
MAD_EXPORT void madrpc_show_errors(int set);
MAD_EXPORT int madrpc_set_retries(int retries);
MAD_EXPORT int madrpc_set_timeout(int timeout);
MAD_EXPORT struct ibmad_port *mad_rpc_open_port(char *dev_name, int dev_port,
						int *mgmt_classes,
						int num_classes);
MAD_EXPORT void mad_rpc_close_port(struct ibmad_port *srcport);

/*
 * On redirection, the dport argument is updated with the redirection target,
 * so subsequent MADs will not go through the redirection process again but
 * reach the target directly.
 */
MAD_EXPORT void *mad_rpc(const struct ibmad_port *srcport, ib_rpc_t * rpc,
			 ib_portid_t * dport, void *payload, void *rcvdata);

MAD_EXPORT void *mad_rpc_rmpp(const struct ibmad_port *srcport, ib_rpc_t * rpc,
			      ib_portid_t * dport, ib_rmpp_hdr_t * rmpp,
			      void *data);
MAD_EXPORT int mad_rpc_portid(struct ibmad_port *srcport);
MAD_EXPORT void mad_rpc_set_retries(struct ibmad_port *port, int retries);
MAD_EXPORT void mad_rpc_set_timeout(struct ibmad_port *port, int timeout);
MAD_EXPORT int mad_rpc_class_agent(struct ibmad_port *srcport, int cls);

MAD_EXPORT int mad_get_timeout(const struct ibmad_port *srcport,
			       int override_ms);
MAD_EXPORT int mad_get_retries(const struct ibmad_port *srcport);

/* register.c */
MAD_EXPORT int mad_register_port_client(int port_id, int mgmt,
					uint8_t rmpp_version);
MAD_EXPORT int mad_register_client(int mgmt, uint8_t rmpp_version) DEPRECATED;
MAD_EXPORT int mad_register_server(int mgmt, uint8_t rmpp_version,
				   long method_mask[16 / sizeof(long)],
				   uint32_t class_oui) DEPRECATED;
/* register.c new interface */
MAD_EXPORT int mad_register_client_via(int mgmt, uint8_t rmpp_version,
				       struct ibmad_port *srcport);
MAD_EXPORT int mad_register_server_via(int mgmt, uint8_t rmpp_version,
				       long method_mask[16 / sizeof(long)],
				       uint32_t class_oui,
				       struct ibmad_port *srcport);
MAD_EXPORT int mad_class_agent(int mgmt) DEPRECATED;

/* serv.c */
MAD_EXPORT int mad_send(ib_rpc_t * rpc, ib_portid_t * dport,
			ib_rmpp_hdr_t * rmpp, void *data) DEPRECATED;
MAD_EXPORT void *mad_receive(void *umad, int timeout) DEPRECATED;
MAD_EXPORT int mad_respond(void *umad, ib_portid_t * portid, uint32_t rstatus)
    DEPRECATED;

/* serv.c new interface */
MAD_EXPORT int mad_send_via(ib_rpc_t * rpc, ib_portid_t * dport,
			    ib_rmpp_hdr_t * rmpp, void *data,
			    struct ibmad_port *srcport);
MAD_EXPORT void *mad_receive_via(void *umad, int timeout,
				 struct ibmad_port *srcport);
MAD_EXPORT int mad_respond_via(void *umad, ib_portid_t * portid,
			       uint32_t rstatus, struct ibmad_port *srcport);
MAD_EXPORT void *mad_alloc(void);
MAD_EXPORT void mad_free(void *umad);

/* vendor.c */
MAD_EXPORT uint8_t *ib_vendor_call(void *data, ib_portid_t * portid,
				   ib_vendor_call_t * call) DEPRECATED;

/* vendor.c new interface */
MAD_EXPORT uint8_t *ib_vendor_call_via(void *data, ib_portid_t * portid,
				       ib_vendor_call_t * call,
				       struct ibmad_port *srcport);

static inline int mad_is_vendor_range1(int mgmt)
{
	return mgmt >= 0x9 && mgmt <= 0xf;
}

static inline int mad_is_vendor_range2(int mgmt)
{
	return mgmt >= 0x30 && mgmt <= 0x4f;
}

/* rpc.c */
MAD_EXPORT int madrpc_portid(void) DEPRECATED;
void *madrpc(ib_rpc_t * rpc, ib_portid_t * dport, void *payload, void *rcvdata)
    DEPRECATED;
void *madrpc_rmpp(ib_rpc_t * rpc, ib_portid_t * dport, ib_rmpp_hdr_t * rmpp,
		  void *data) DEPRECATED;
MAD_EXPORT void madrpc_init(char *dev_name, int dev_port, int *mgmt_classes,
			    int num_classes) DEPRECATED;
void madrpc_save_mad(void *madbuf, int len) DEPRECATED;

/* smp.c */
MAD_EXPORT uint8_t *smp_query(void *buf, ib_portid_t * id, unsigned attrid,
			      unsigned mod, unsigned timeout) DEPRECATED;
MAD_EXPORT uint8_t *smp_set(void *buf, ib_portid_t * id, unsigned attrid,
			    unsigned mod, unsigned timeout) DEPRECATED;

/* smp.c new interface */
MAD_EXPORT uint8_t *smp_query_via(void *buf, ib_portid_t * id, unsigned attrid,
				  unsigned mod, unsigned timeout,
				  const struct ibmad_port *srcport);
MAD_EXPORT uint8_t *smp_set_via(void *buf, ib_portid_t * id, unsigned attrid,
				unsigned mod, unsigned timeout,
				const struct ibmad_port *srcport);
MAD_EXPORT uint8_t *smp_query_status_via(void *rcvbuf, ib_portid_t * portid,
					 unsigned attrid, unsigned mod,
					 unsigned timeout, int *rstatus,
					 const struct ibmad_port *srcport);
MAD_EXPORT uint8_t *smp_set_status_via(void *data, ib_portid_t * portid,
				       unsigned attrid, unsigned mod,
				       unsigned timeout, int *rstatus,
				       const struct ibmad_port *srcport);

/* cc.c */
MAD_EXPORT void *cc_query_status_via(void *rcvbuf, ib_portid_t * portid,
				     unsigned attrid, unsigned mod, unsigned timeout,
				     int *rstatus, const struct ibmad_port * srcport,
				     uint64_t cckey);

/* sa.c */
uint8_t *sa_call(void *rcvbuf, ib_portid_t * portid, ib_sa_call_t * sa,
		 unsigned timeout) DEPRECATED;
MAD_EXPORT int ib_path_query(ibmad_gid_t srcgid, ibmad_gid_t destgid,
			     ib_portid_t * sm_id, void *buf) DEPRECATED;

/* sa.c new interface */
MAD_EXPORT uint8_t *sa_rpc_call(const struct ibmad_port *srcport, void *rcvbuf,
				ib_portid_t * portid, ib_sa_call_t * sa,
				unsigned timeout);
MAD_EXPORT int ib_path_query_via(const struct ibmad_port *srcport,
				 ibmad_gid_t srcgid, ibmad_gid_t destgid,
				 ib_portid_t * sm_id, void *buf);
	/* returns lid */

/* resolve.c */
MAD_EXPORT int ib_resolve_smlid(ib_portid_t * sm_id, int timeout) DEPRECATED;
MAD_EXPORT int ib_resolve_portid_str(ib_portid_t * portid, char *addr_str,
				     enum MAD_DEST dest, ib_portid_t * sm_id)
    DEPRECATED;
MAD_EXPORT int ib_resolve_self(ib_portid_t * portid, int *portnum,
			       ibmad_gid_t * gid) DEPRECATED;

/* resolve.c new interface */
MAD_EXPORT int ib_resolve_smlid_via(ib_portid_t * sm_id, int timeout,
				    const struct ibmad_port *srcport);
MAD_EXPORT int ib_resolve_guid_via(ib_portid_t * portid, uint64_t * guid,
				   ib_portid_t * sm_id, int timeout,
				   const struct ibmad_port *srcport);
MAD_EXPORT int ib_resolve_gid_via(ib_portid_t * portid, ibmad_gid_t gid,
				  ib_portid_t * sm_id, int timeout,
				  const struct ibmad_port *srcport);
MAD_EXPORT int ib_resolve_portid_str_via(ib_portid_t * portid, char *addr_str,
					 enum MAD_DEST dest,
					 ib_portid_t * sm_id,
					 const struct ibmad_port *srcport);
MAD_EXPORT int ib_resolve_self_via(ib_portid_t * portid, int *portnum,
				   ibmad_gid_t * gid,
				   const struct ibmad_port *srcport);

/* gs.c new interface */
MAD_EXPORT uint8_t *pma_query_via(void *rcvbuf, ib_portid_t * dest, int port,
				  unsigned timeout, unsigned id,
				  const struct ibmad_port *srcport);
MAD_EXPORT uint8_t *performance_reset_via(void *rcvbuf, ib_portid_t * dest,
					  int port, unsigned mask,
					  unsigned timeout, unsigned id,
					  const struct ibmad_port *srcport);

/* bm.c */
MAD_EXPORT uint8_t *bm_call_via(void *data, ib_portid_t * portid,
				ib_bm_call_t * call,
				struct ibmad_port *srcport);

/* dump.c */
MAD_EXPORT ib_mad_dump_fn
    mad_dump_int, mad_dump_uint, mad_dump_hex, mad_dump_rhex,
    mad_dump_bitfield, mad_dump_array, mad_dump_string,
    mad_dump_linkwidth, mad_dump_linkwidthsup, mad_dump_linkwidthen,
    mad_dump_linkdowndefstate,
    mad_dump_linkspeed, mad_dump_linkspeedsup, mad_dump_linkspeeden,
    mad_dump_linkspeedext, mad_dump_linkspeedextsup, mad_dump_linkspeedexten,
    mad_dump_portstate, mad_dump_portstates,
    mad_dump_physportstate, mad_dump_portcapmask,
    mad_dump_mtu, mad_dump_vlcap, mad_dump_opervls,
    mad_dump_node_type, mad_dump_sltovl, mad_dump_vlarbitration,
    mad_dump_nodedesc, mad_dump_nodeinfo, mad_dump_portinfo,
    mad_dump_switchinfo, mad_dump_perfcounters, mad_dump_perfcounters_ext,
    mad_dump_perfcounters_xmt_sl, mad_dump_perfcounters_rcv_sl,
    mad_dump_perfcounters_xmt_disc, mad_dump_perfcounters_rcv_err,
    mad_dump_portsamples_control, mad_dump_port_ext_speeds_counters,
    mad_dump_perfcounters_port_op_rcv_counters, mad_dump_perfcounters_port_flow_ctl_counters,
    mad_dump_perfcounters_port_vl_op_packet, mad_dump_perfcounters_port_vl_op_data,
    mad_dump_perfcounters_port_vl_xmit_flow_ctl_update_errors, mad_dump_perfcounters_port_vl_xmit_wait_counters,
    mad_dump_perfcounters_sw_port_vl_congestion, mad_dump_perfcounters_rcv_con_ctrl,
    mad_dump_perfcounters_sl_rcv_fecn, mad_dump_perfcounters_sl_rcv_becn,
    mad_dump_perfcounters_xmit_con_ctrl, mad_dump_perfcounters_vl_xmit_time_cong,
    mad_dump_mlnx_ext_port_info, mad_dump_cc_congestioninfo, mad_dump_cc_congestionkeyinfo,
    mad_dump_cc_congestionlog, mad_dump_cc_congestionlogswitch,
    mad_dump_cc_congestionlogentryswitch, mad_dump_cc_congestionlogca,
    mad_dump_cc_congestionlogentryca, mad_dump_cc_switchcongestionsetting,
    mad_dump_cc_switchportcongestionsettingelement, mad_dump_cc_cacongestionsetting,
    mad_dump_cc_cacongestionentry, mad_dump_cc_congestioncontroltable,
    mad_dump_cc_congestioncontroltableentry, mad_dump_cc_timestamp;

MAD_EXPORT void mad_dump_fields(char *buf, int bufsz, void *val, int valsz,
				int start, int end);

extern MAD_EXPORT int ibdebug;

#if __BYTE_ORDER == __LITTLE_ENDIAN
#ifndef ntohll
static inline uint64_t ntohll(uint64_t x)
{
	return bswap_64(x);
}
#endif
#ifndef htonll
static inline uint64_t htonll(uint64_t x)
{
	return bswap_64(x);
}
#endif
#elif __BYTE_ORDER == __BIG_ENDIAN
#ifndef ntohll
static inline uint64_t ntohll(uint64_t x)
{
	return x;
}
#endif
#ifndef htonll
static inline uint64_t htonll(uint64_t x)
{
	return x;
}
#endif
#endif				/* __BYTE_ORDER == __BIG_ENDIAN */

/* Misc. macros: */
/** align value \a l to \a size (ceil) */
#define ALIGN(l, size) (((l) + ((size) - 1)) / (size) * (size))

/** printf style warning MACRO, includes name of function and pid */
#define IBWARN(fmt, ...) fprintf(stderr, "ibwarn: [%d] %s: " fmt "\n", getpid(), __func__, ## __VA_ARGS__)

#define IBDEBUG(fmt, ...) fprintf(stdout, "ibdebug: [%d] %s: " fmt "\n", getpid(), __func__, ## __VA_ARGS__)

#define IBVERBOSE(fmt, ...) fprintf(stdout, "[%d] %s: " fmt "\n", getpid(), __func__, ## __VA_ARGS__)

#define IBPANIC(fmt, ...) do { \
	fprintf(stderr, "ibpanic: [%d] %s: " fmt ": %m\n", getpid(), __func__, ## __VA_ARGS__); \
	exit(-1); \
} while(0)

MAD_EXPORT void xdump(FILE * file, char *msg, void *p, int size);

END_C_DECLS
#endif				/* _MAD_H_ */
