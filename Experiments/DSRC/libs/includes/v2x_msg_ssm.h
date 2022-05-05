/**
 * Copyright (c) 2017 Huali ismartways.
 * All rights reserved.
 *
 * Description:
 * This header contains the necessary APIs and data structures that are
 * needed to encode / decode the SSM. Link with -lj2735_2016, -lsae_2016,
 * -losstoed and -lm.
 */
#ifndef __V2X_MSG_SSM_DS_H__
#define __V2X_MSG_SSM_DS_H__

#include <v2x_msg_common.h>

/**
 * @addtogroup v2x_message The V2X Message API
 *
 * @ingroup v2x_message
 *
 * @file        v2x_msg_ssm.h
 * @brief       SSM message API definitions and functions.
 *
 * This header file contains the necessary APIs and data structures
 * used to encode and decode a SSM.
 *
 * Include libj2735.h. Link with -lj2735_2016 -lsae_2016 -losstoed -lm.
 */
#define SSM_SIGNAL_STATUS_LIST_MIN 1
#define SSM_SIGNAL_STATUS_LIST_MAX 16

#define SSM_SS_PKG_LIST_MIN 1
#define SSM_SS_PKG_LIST_MAX 2

/**
 * Signal request info
 */
typedef struct
{
    /**
     * Vehicle ID - unique number
     */
    mde_VehicleID_t vehicle_id;
    /**
     * request ID - unique number
     */
    int request_id;
    /**
     * msg count
     */
    int msgcount;
    /**
     * basic vehicl role
     */
    Mde_BasicVehicleRole_t basic_vehicle_role;
    /**
     * set to 1, if requestor_type is being filled
     */
    int requestor_type_present;
    /**
     * requestor type
     */
    mde_RequestorType_t requestor_type;
} mde_SignalRequesterInfo_t;

/**
 * Signal status package list
 */
typedef struct
{
    unsigned char bit_mask;
    /**
     * Requestor info
     */
    mde_SignalRequesterInfo_t       signal_request;
    unsigned short                  in_bound_on_choice;
    /**
     * inbound access point (lane, approach)
     */
    mde_IsecAccessPoint_t           in_bound_access_point;
    /**
     * set to 1, if outbound access point is available
     */
    int valid_out_bound_access_point;
    /**
     * outbound access point (lane, approach)
     */
    mde_IsecAccessPoint_t out_bound_access_point;
    /**
     * minute of the year
     */
    int min_of_year;  // optional
    /**
     * second
     */
    int second;  // optional
    /**
     * duration
     */
    int duration;  // optional
    /**
     * priority response status
     */
    Mde_PrioritizationResponseStatus_t prio_resp;
} mde_SignalStatusPackageList_t;

typedef struct
{
    unsigned char bit_mask;

    unsigned short region; /* optional; set in bit_mask
                             * IntersectionReferenceID_region_present if
                             * present */
    /* a globally unique regional assignment value */
    /* typical assigned to a regional DOT authority */
    /* the value zero shall be used for testing needs */
    unsigned short id;
    /* a unique mapping to the intersection */
    /* in question within the above region of use */
} IntReferenceID;

/**
 * Signal status list
 */
typedef struct
{
    unsigned char  bit_mask;
    unsigned short sequenceNumber;
    IntReferenceID id;
    /**
     * signal status package list count
     */
    int ss_pkg_list_len;
    /**
     * signal status package list
     */
    mde_SignalStatusPackageList_t ss_pkg_list[SSM_SS_PKG_LIST_MAX];
}mde_SignalStatusList_t;

/**
 * @ingroup v2x_message
 * SSM message
 */
typedef struct
{
    unsigned char  bit_mask;
    unsigned short second;
    unsigned short sequenceNumber;
    /**
     * signal status list count (1 .. 32)
     */
    int sslist_len;
    /**
     * signal status list
     */
    mde_SignalStatusList_t sslist[SSM_SIGNAL_STATUS_LIST_MAX];
} v2x_msg_ssm_t;

#endif
