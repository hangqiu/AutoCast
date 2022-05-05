/*
 * Copyright (c) 2018 Huali ismartways,
 * All Rights Reserved.
 *
 * Description:
 * This header contains the necessary APIs and data structures
 * needed to encode/decode MAP message
 */
#ifndef _V2X_MSG_MAP_H__
#define _V2X_MSG_MAP_H__

#include <v2x_msg_common.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
    /**
     * straight maneuver allowed
     */
    MDE_MAN_STRAIGHT_ALLOWED = 0x0001,
    /**
     * left maneuver allowed
     */
    MDE_MAN_LEFT_ALLOWED = 0x0002,
    /**
     * right maneuver allowed
     */
    MDE_MAN_RIGHT_ALLOWED = 0x0004,
    /**
     * uturn allowed
     */
    MDE_MAN_UTURN_ALLOWED = 0x0008,
    /**
     * left turn on red allowed
     */
    MDE_MAN_LEFT_TURN_ON_RED_ALLOWED = 0x0010,
    /**
     * right turn on red allowed
     */
    MDE_MAN_RIGHT_TURN_ON_RED_ALLOWED = 0x0020,
    /**
     * lane change allowed
     */
    MDE_MAN_LANE_CHANGE_ALLOWED = 0x0040,
    /**
     * no stopping allowed
     */
    MDE_MAN_NO_STOPPING_ALLOWED = 0x0080,
    /**
     * all ways yield
     */
    MDE_MAN_YIELD_ALLWAYS_REQUIRED = 0x0100,
    /**
     * go with halt
     */
    MDE_MAN_GOWITH_HALT = 0x0200,
    /**
     * caution
     */
    MDE_MAN_CAUTION   = 0x0400,
    MDE_MAN_RESERVED1 = 0x0800,
} Mde_AllowedManeuvers_t;

typedef enum
{
    /**
     * unavailable
     */
    MDE_LANE_DIRECTION_UNAVAIL = 0x00,
    /**
     * ingress lane
     */
    MDE_LANE_DIRECTION_INGRESS = 0x01,
    /**
     * egress lane
     */
    MDE_LANE_DIRECTION_EGRESS = 0x02,
}Mde_LaneDir_t;

typedef enum
{
    /**
     * over lapping lane description provided
     */
    MDE_OVERLAP_LANE_DESCR = 0x0001,
    /**
     * multiple lanes treated as one
     */
    MDE_MULTI_LANE_TREATED_AS_ONE = 0x0002,
    /**
     * other non motorized traffic
     */
    MDE_OTHER_NON_MOTORIZED = 0x0004,
    /**
     * individual motor traffic
     */
    MDE_INDIVIDUAL_MOTOR_TRAFFIC = 0x0008,
    /**
     * bus vehicle traffic
     */
    MDE_BUS_VEHICLE_TRAFFIC = 0x0010,
    /**
     * taxi vehicle traffic
     */
    MDE_TAXI_VEHICLE_TRAFFIC = 0x0020,
    /**
     * pedestrian traffic
     */
    MDE_PED_TRAFFIC = 0x0040,
    /**
     * cyclist traffic
     */
    MDE_CYCLIST_TRAFFIC = 0x0080,
    /**
     * tracked vehicle traffic
     */
    MDE_TRACKED_VEHICLE_TRAFFIC = 0x0100,
    MDE_PED_TRAFFIC_2           = 0x0200,
}Mde_SharedLaneType_t;

typedef enum
{
    /**
     * vehicle revocable lanes
     */
    MDE_VEH_IS_VEHICLE_REVOCABLE_LANE = 0x01,
    /**
     * vehicle flyover lanes
     */
    MDE_VEH_IS_VEHICLE_FLYOVER_LANE = 0x02,
    /**
     * vehicle hov useonly lanes
     */
    MDE_VEH_HOV_USE_ONLY = 0x04,
    /**
     * bus restricted lanes
     */
    MDE_VEH_RESTRICTED_TO_BUS_USE = 0x08,
    /**
     * taxi restricted lanes
     */
    MDE_VEH_RESTRICTED_TO_TAXI_USE = 0x10,
    /**
     * restricted from public use
     */
    MDE_VEH_RESTRICTED_FROM_PUBLIC_USE = 0x20,
    MDE_VEH_HAS_IR_BEACON_COVERAGE     = 0x40,
    MDE_VEH_PERMISSION_ON_REQUEST      = 0x80,
} Mde_LaneTypeAttrVeh_t;

typedef enum
{
    /**
     * crosswalk revocable lane
     */
    MDE_CRW_CRW_REVOCABLE_LANE = 0x0001,
    /**
     * bicycle use only
     */
    MDE_CRW_BICYCLE_USE_ONLY = 0x0002,
    /**
     * crosswalk flyover lane
     */
    MDE_CRW_IS_FLYOVER_CRW_LANE = 0x0004,
    /**
     * fixed cycle time in use
     */
    MDE_CRW_FIXED_CYCLE_TIME = 0x0008,
    /**
     * bidirectional cycle time
     */
    MDE_CRW_BIDIRECTIONAL_CYCLE_TIME = 0x0010,
    /**
     * the crosswalk has a push to talk button
     */
    MDE_CRW_HAS_PUSH_TO_WALK_BUTTON = 0x0020,
    /**
     * the crosswalk has the audio support
     */
    MDE_CRW_AUDIO_SUPPORT = 0x0040,
    /**
     * the cross walk has the RF signal request
     */
    MDE_CRW_RFSIGNAL_REQ_PRESENT = 0x0080,
    /**
     * unsignallized segments are present
     */
    MDE_CRW_UNSIGNALIZED_SEGMENTS_PRESENT = 0x0100,
} Mde_LaneTypeAttrCrossWk_t;

typedef struct
{
    /**
     * direction - lane direction
     */
    Mde_LaneDir_t direction;
    /**
     * sharedlane - shared with any other traffic such as motor, car, cycle etc
     */
    Mde_SharedLaneType_t sharedlane;
    /**
     * vehattr - vehicle attributes
     */
    Mde_SharedLaneType_t* vehattr;
    /**
     * crwattr - crosswalk attributes
     */
    Mde_LaneTypeAttrCrossWk_t* crwattr;
}Mde_LaneAttribute_t;

typedef struct
{
    /**
     * node - position3d of a node point
     */
    mde_pos_3d_t node;
    /**
     * lanewidth - unused, place holder
     */
    double lanewidth;
}mde_node_list_t;

typedef enum
{
    /**
     * node attirbute
     */
    MDE_NODEATTR_NODEATTR = 0x01,
    /**
     * disabled segment
     */
    MDE_NODEATTR_DISABLED_SEGMENTS = 0x02,
    /**
     * enabled segment
     */
    MDE_NODEATTR_ENABLED_SEGMENTS = 0x04,
    /**
     * lanedata
     */
    MDE_NODEATTR_LANEDATA = 0x08,
    /**
     * unavailable
     */
    MDE_NODEATTR_UNAVAIL = 0x00,
} Mde_NodeAttrType_t;

typedef enum
{
    MDE_SPDLIM_TYPE_UNKNOWN                          = 0,
    MDE_SPDLIM_TYPE_MAXSPEED_IN_SCHOOLZONE           = 1,
    MDE_SPDLIM_TYPE_MAXSPEED_IN_SCHOOL_WITH_CHILDREN = 2,
    MDE_SPDLIM_TYPE_CONSTRUCTION                     = 3,
    MDE_SPDLIM_TYPE_VEH_MIN_SPD                      = 4,
    MDE_SPDLIM_TYPE_VEH_MAX_SPD                      = 5,
    MDE_SPDLIM_TYPE_VEH_NIGHT_MAX_SPD                = 6,
    MDE_SPDLIM_TYPE_TRUCK_MIN_SPD                    = 7,
    MDE_SPDLIM_TYPE_TRUCK_MAX_SPD                    = 8,
    MDE_SPDLIM_TYPE_TRUCK_NIGHT_MAX_SPD              = 9,
    MDE_SPDLIM_TYPE_VEH_WITH_TRAILER_MIN_SPEED       = 10,
    MDE_SPDLIM_TYPE_VEH_WITH_TRAILER_MAX_SPEED       = 11,
    MDE_SPDLIM_TYPE_VEH_WITH_TRAILER_NIGHT_MAX_SPEED = 12,
}Mde_SpeedlimitType_t;

typedef struct spedelimits
{
    Mde_SpeedlimitType_t        type;
    double                      speed;
}mde_speedlimit_t;

typedef struct
{
    double                   path_end_point_angle;
    double                   lane_crown_point_center;
    double                   lane_crown_point_left;
    double                   lane_crown_point_right;
    double                   lane_angle;
    int                      n_splim;
    mde_speedlimit_t*        splim;
}mde_lane_data_attributes_t;

typedef struct
{
    /**
     * type - node attribute types
     */
    Mde_NodeAttrType_t type;
    /**
     * n_lane_data_attr - number of lane data attributes
     */
    int n_lane_data_attr;
    /**
     * lane_data_attr - lane data attribute list
     */
    mde_lane_data_attributes_t* lane_data_attr;
    /**
     * dWidth - delta lanewidth
     */
    double dWidth;
    /**
     * dElev - delta elevation
     */
    double dElev;
} mde_node_attr_t;


typedef struct
{
    /**
     * node_id - node expressed in pos3d form
     */
    mde_node_list_t node_id;
    /**
     * nodeattr - attributes of a node
     */
    mde_node_attr_t nodeattr;
}mde_node_point_t;

typedef struct
{
    /**
     * id - lane id
     */
    int id;
    /**
     * signal_group_id - signal group ID
     */
    int signal_group_id;
}mde_connectsto_lanes_t;

typedef struct
{
    /**
     * lane_id - lane id
     */
    unsigned int lane_id;
    /**
     * phase - phase that is valid for this lane
     */
    int phase;  // phase number not to be sent over the air
    /**
     * man - allowed manuvers
     */
    Mde_AllowedManeuvers_t man;
    /**
     * signal_group_id - signal group ID mapping with the corresponding SPAT
     */
    int signal_group_id;  // this will go directly into the SPAT
    /**
     * lane_attr - lane attributes
     */
    Mde_LaneAttribute_t lane_attr;
    /**
     * n_nodepoint - number of nodes 2 - 63
     */
    int n_nodepoint;
    /**
     * node_point - node point list describing the lane
     */
    mde_node_point_t* node_point;
    /**
     * n_connect - number of connects to list
     */
    int n_connect;
    /**
     * connects_to - connection list from this lane
     */
    mde_connectsto_lanes_t* connects_to;
} mde_lanelist_t;


typedef struct intersection_geodescr
{
    /**
     * intersection_id - intersection ID of this intersection
     */
    unsigned int intersection_id;
    /**
     * msg_revision - message revision
     */
    int msg_revision;
    /**
     * reference_point - intersection reference point.
     */
    mde_pos_3d_t ref_pt;
    /**
     * lanewidth - lane width of all the lanes. The different lanewidths are
     *               represented using the dElev and dWidth of the nodeList
     */
    double lanewidth;
    /**
     * n_lanelist - number of lanes (1 - 64)
     */
    int n_lanelist;
    /**
     * lanelist - lane list
     */
    mde_lanelist_t* lanelist;
} mde_isec_geo_descr_t;

/**
 * @ingroup v2x_message
 *
 * MAP message structure
 */
typedef struct v2x_msg_map
{
    /**
     * msg_revision - message revision
     */
    unsigned short  msg_revision;
    /**
     * n_geo_descr - number of geographic descriptions
     */
    int n_geo_descr;
    /**
     * isec_geo_descr - intersection geometric description list
     */
    mde_isec_geo_descr_t* isec_geo_descr;
} v2x_msg_map_t;

#ifdef __cplusplus
}
#endif

#endif
