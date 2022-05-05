/**
 * Copyright (c) 2017 Huali ismartways,
 * All rights reserved.
 *
 * Description:
 * This header contains the necessary APIs and data structures that are
 * needed to encode / decode the SRM. Link with -lj2735_2016 -lsae_2016,
 * -losstoed and -lm
 */
#ifndef __V2X_MSG_SRM_DS_H__
#define __V2X_MSG_SRM_DS_H__

#include <stdio.h>
#include <v2x_msg_common.h>
/**
 * @addtogroup v2x_message The V2X Message API
 *
 * @ingroup v2x_message
 *
 * @file    v2x_msg_srm.h
 * @brief   SRM message API definitions and functions
 *
 * This header file contains the APIs and data structures
 * used to encode or decode a SRM.
 *
 * Include libj2735.h. Link with -lj2735_2016 -lsae_2016 -losstoed -lm.
 */

#define SRM_DSECOND_MIN 0
#define SRM_DSECOND_MAX 65535
#define SRM_DSECOND_NAV J2735_NAV

#define SRM_MSG_COUNT_MIN 0
#define SRM_MSG_COUNT_MAX 127
#define SRM_MSG_COUNT_NAV J2735_NAV

#define SRM_MSG_LIST_MIN 1
#define SRM_MSG_LIST_MAX 32
#define SRM_MSG_LIST_NAV J2735_NAV

#define SRM_MSG_IID_MIN 0
#define SRM_MSG_IID_MAX 65535
#define SRM_MSG_IID_NAV J2735_NAV

#define SRM_MSG_REQID_MIN 0
#define SRM_MSG_REQID_MAX 255
#define SRM_MSG_REQID_NAV J2735_NAV

#define SRM_MSG_PRIO_REQ_TYPE_MIN 0
#define SRM_MSG_PRIO_REQ_TYPE_MAX 3
#define SRM_MSG_PRIO_REQ_TYPE_NAV J2735_NAV

/**
 * Priority request type
 */
typedef enum
{
    /**
     * Reserved
     */
    SRM_PRIO_REQ_TYPE_RESERVED,
    /**
     * Request
     */
    SRM_PRIO_REQ_TYPE_REQ,
    /**
     * Update
     */
    SRM_PRIO_REQ_TYPE_UPDATE,
    /**
     * Cancel
     */
    SRM_PRIO_REQ_TYPE_CANCEL,
} J2735_2016_PriorityReqType_t;

/**
 * Signal request description for each lane / particular lane
 */
typedef struct
{
    unsigned char bit_mask;
    unsigned char id_bit_mask;
    /**
     * intersection id
     */
    int iid;
    /**
     * request id = tempid
     */
    int request_id;
    /**
     * request type
     */
    J2735_2016_PriorityReqType_t req_type;
    unsigned short               inbound_accesspoint_choice;
    /**
     * inbound accesspoint (lane, approach)
     */
    mde_IsecAccessPoint_t in_bound_access_point;
    /**
     * outbound accesspoint (lane, approach)
     */
    mde_IsecAccessPoint_t out_bound_access_point;  // optional
} J2735_2016_SignalRequest_t;

/**
 * SRM set
 */
typedef struct srm_list
{
    unsigned char bit_mask;
    /**
     * signal request description
     */
    J2735_2016_SignalRequest_t signal_request;
    /**
     * minute of the year
     */
    uint32_t min_of_year;  // optional
    /**
     * seconds
     */
    int second;  // optional
    /**
     * duration
     */
    int duration;  // optional
} J2735SRMList_t;

/**
 * SRM requestor
 */
typedef struct srm_requestor
{
    unsigned char  bit_mask;
    unsigned short second;
    unsigned short id_choice;
    /**
     * Vehicle ID
     */
    mde_VehicleID_t id;
    // set to 1 if req_pos_vector contains
    // valid positional information
    /**
     * set to 1, if the req_pos_vector is being filled
     */
    int full_pos_valid;
    /**
     * full position vector
     */
    mde_FullPosVec_t req_pos_vector;  // optional
    // set to 1 if requestor_type contains
    // valid requestor information
    /**
     * set to 1 if requestor_type is being filled
     */
    int requestor_type_valid;
    /**
     * requestor type
     */
    unsigned char              requestor_type_bit_mask;
    mde_RequestorType_t requestor_type;
} J2735SRMRequestor_t;

/**
 * @ingroup v2x_message
 * SRM message
 */
typedef struct j2735_2016_srm
{
    unsigned char  bit_mask;
    unsigned short second;

    /**
     * SRM list count (1, 32)
     */
    int srm_list_count;
    /**
     * SRM list
     */
    J2735SRMList_t srmlist[SRM_MSG_LIST_MAX];
    /**
     * requestor
     */
    J2735SRMRequestor_t requestor;
} v2x_msg_srm_t;

#endif
