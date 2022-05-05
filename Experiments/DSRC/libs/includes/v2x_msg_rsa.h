
#ifndef __V2X_MSG_RSA_H__
#define __V2X_MSG_RSA_H__

#include <v2x_msg_common.h>

#define RSA_ITIS_DESCR_LEN_MAX 8

typedef struct _J2735_2016_RSA
{
    /**
     * msg count 0 - 127 and shall round back to 0 after 127
     */
    int msg_count;
    /**
     * minute of the year
     */
    int min_of_year;
    /**
     * type_event - main cause of the event
     */
    int type_event;  // itis code
    /**
     * event_descr_len - length of the list of events
     */
    int event_descr_len;
    /**
     * event_descr - event list
     */
    int event_descr[RSA_ITIS_DESCR_LEN_MAX];
    /**
     * event priority
     */
    int priority;  // optional
    /**
     * heading slice for which this message applies to
     */
    // J2735_2016_HeadingSlice_t     heading_slice; // optional
    int heading_slice;
    /**
     * extent of the area
     */
    int extent;
    // set to 1 if below full_posvec is valid and otherwise 0
    /**
     * set this to 1 if the full position vector is being filled
     */
    int valid_full_posvec;
    /**
     * full position vector
     */
    mde_FullPosVec_t full_posvec;  // optional
    /**
     * further info id
     */
    int further_id;
} v2x_msg_rsa_t;

#endif
