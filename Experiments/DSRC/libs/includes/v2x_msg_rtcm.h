/**
 * Copyright (c) 2017 Huali ismartways,
 * All rights reserved.
 *
 * Description:
 * This header contains the necessary APIs and data structures that are
 * -losstoed and -lm
 */
#ifndef __V2X_MSG_RTCM_DS_H__
#define __V2X_MSG_RTCM_DS_H__

#include <v2x_msg_common.h>
/**
 * @addtogroup v2x_message The V2X Message API
 *
 * @ingroup v2x_message
 *
 * @file    v2x_msg_rtcm.h
 * @brief   RTCM message API definitions and functions
 *
 * This header file contains the APIs and data structures
 * used to encode or decode a RTCM.
 */

#define RTCM_MSG_LIST_MIN 1
#define RTCM_MSG_LIST_MAX 5

typedef enum
{
    J2735_RTCM_UNKNOWN,
    J2735_RTCM_REV2,
    J2735_RTCM_REV3,
    J2735_RTCM_RESERVED
} Mde_rtcm_revision_t;

typedef struct
{
    int rtcm_msg_len;
    unsigned char rtcm_msg[1023];
} mde_rtcm_msg_List_t;

/*
 * @ingroup v2x_message
 * RTCM message
 */
typedef struct
{
    /*
     * msg count 0 - 127 and shall round back to 0 after 127
     */
    int msg_count;
    /*
     * the specific edition of the standard
     */
    Mde_rtcm_revision_t rev;
    /*
     * minute of the year
     */
    int min_of_year;
    /*
     * RTCM msg list count (1, 5)
     */
    int rtcm_msg_list_count;
    /*
     * RTCM msg list
     */
    mde_rtcm_msg_List_t rtcm_msg_list[RTCM_MSG_LIST_MAX];
} v2x_msg_rtcm_t;

#endif
