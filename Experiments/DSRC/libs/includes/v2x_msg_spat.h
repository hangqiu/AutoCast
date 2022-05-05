/*
 * Copyright (c) 2018 Huali ismartways,
 * All Rights Reserved.
 *
 * Author Name: Arshad Khan
 * Description:
 * Contains necessary structures and macros to encode/decode
 * SPAT message.
 */

#ifndef __V2X_SPAT_H__
#define __V2X_SPAT_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef enum intersection_status
{
    /**
     * Manual control is activated
     */
    Mde_ISEC_STATUS_MANUAL_CONTROL_IS_ON = 0x0001,
    /**
     * Stop time is activated
     */
    Mde_ISEC_STATUS_STOP_TIME_IS_ACTIVE = 0x0002,
    /**
     * Failure flash is active
     */
    Mde_ISEC_STATUS_FAILURE_FLASH = 0x0004,
    /**
     * Preempt is active
     */
    Mde_ISEC_STATUS_PREEMPT_IS_ACTIVE = 0x0008,
    /**
     * TSP is active
     */
    Mde_ISEC_STATUS_TSP_IS_ACTIVE = 0x0010,
    /**
     * Fixed time operation
     */
    Mde_ISEC_STATUS_FIXED_TIME_OPERATION = 0x0020,
    /**
     * Traffic dependent operation
     */
    Mde_ISEC_STATUS_TRAFFIC_DEPENDENT_OPERATION = 0x0040,
    /**
     * Standby operation
     */
    Mde_ISEC_STATUS_STAND_BY_OPERATION = 0x0080,
    /**
     * Failure mode
     */
    Mde_ISEC_STATUS_FAILURE_MODE = 0x0100,
    /**
     * Intersection status off
     */
    Mde_ISEC_STATUS_OFF = 0x0200,
    /**
     * Recent MAP message in update
     */
    Mde_ISEC_STATUS_RECENT_MAP_MESSAGE_UPDATE = 0x0400,
    /**
     * Recent change in MAP assigned lanes is in use
     */
    Mde_ISEC_STATUS_RECENT_CHANGE_IN_MAP_ASSIGNED_LANEIDS_USED = 0x0800,
    /**
     * No valid MAP is available
     */
    Mde_ISEC_STATUS_NOVALID_MAP_IS_AVAILABLE = 0x1000,
    /**
     * No valid SPaT is available
     */
    Mde_ISEC_STATUS_NOVALID_SPAT_IS_AVAILABLE = 0x2000,
} Mde_IntersectionStatus_t;

/**
 * Mde_MovementPhaseState_t - Movement phase state values. They are used
                                       to describe the phase states that are
                                       coming out of the traffic controller
 */
typedef enum _Mde_MovementPhaseState_t
{
    /**
     * Mde_PHASE_STATE_UNKNOWN - sate is unknown or error
     */
    Mde_PHASE_STATE_UNKNOWN = 0,
    /**
     * Mde_PHASE_STATE_DARK - The signal head is dark.
     */
    Mde_PHASE_STATE_DARK,
    /**
     * Mde_PHASE_STATE_STOP_THEN_PROCEED - flashing red
                    - Stop vehicle at stop line.
                    - Do not proceed unless it is safe.
     */
    Mde_PHASE_STATE_STOP_THEN_PROCEED,
    /**
     * Mde_PHASE_STATE_STOP_AND_REMAIN - 'red light'
                    - Stop vehicle at stop line.
                    - Do not proceed.
     */
    Mde_PHASE_STATE_STOP_AND_REMAIN,
    /**
     * Mde_PHASE_STATE_PRE_MOVEMENT - red + yellow (Not used in the US)
     */
    Mde_PHASE_STATE_PRE_MOVEMENT,
    /**
     * Mde_PHASE_STATE_PERMISSIVE_MOVEMENT_ALLOWED - 'permissive green'
                    - Proceed with caution,
                    - must yield to all conflicting traffic
     */
    Mde_PHASE_STATE_PERMISSIVE_MOVEMENT_ALLOWED,
    /**
     * Mde_PHASE_STATE_PROTECTED_MOVEMENT_ALLOWED - 'protected green'
                    - Proceed, tossing caution to the wind,
                    - in indicated (allowed) direction.
     */
    Mde_PHASE_STATE_PROTECTED_MOVEMENT_ALLOWED,
    /**
     * Mde_PHASE_STATE_PERMISSIVE_CLEARANCE - 'permissive yellow'
                    - Prepare to stop.
                    - Proceed if unable to stop,
                    - Clear Intersection.
     */
    Mde_PHASE_STATE_PERMISSIVE_CLEARANCE,
    /**
     * Mde_PHASE_STATE_PROTECTED_CLEARANCE - 'protected yellow'
                    - Prepare to stop.
                    - Proceed if unable to stop,
                    - in indicated direction (to connected lane)
                    - Clear Intersection.
     */
    Mde_PHASE_STATE_PROTECTED_CLEARANCE,
    /**
     * Mde_PHASE_STATE_CAUTION_CONFLICTING_TRAFFIC - 'flashing yellow'
                    - Proceed with caution
     */
    Mde_PHASE_STATE_CAUTION_CONFLICTING_TRAFFIC,
} __attribute__((packed)) Mde_MovementPhaseState_t;

/**
 * Mde_ManeuverAssistList_t - Contains information about the the dynamic
                                        flow of traffic for the lane(s) and
                                        maneuvers in question (as determined by
                                        the LaneConnectionID). Note that this
                                        information can be sent regarding
                                        any lane-to-lane movement; it need not
                                        be limited to the lanes with active
                                        (non-red) phases when sent.
    XXX: NOTE FOR NYC DEMO WE ARE USING SIGNAL GROUP IDs FOR LaneConnectionID
 */
typedef struct _Mde_ManeuverAssistList_t
{
    /**
     * connection_id - connection identifer indexed from the MAP
     */
    long connection_id;

/**
 * ped_bicycle_detect - 1 if a pedestrian is in the intersection, 0 if
                        its fairly certain a ped is not. NAV if uncertain.
 */
#define J2735_PED_DETECT_TRUE 1
#define J2735_PED_DETECT_FALSE 0
#define J2735_PED_DETECT_NAV 2
    long ped_bicycle_detect;
} mde_ManeuverAssistList_t;

/**
 * Mde_TimeChange_t - Timechange describing each phase time active and
                               remaining values. Likely change is reported in
                               the likely_time. The confidence value indicates
                               the quality of the likely_time.
 */
typedef struct _Mde_TimeChange_t
{
    /**
     * start_time - start of the phase
     */
    long start_time;
    /**
     * min_end_time - minimum guaranteed phase timing
     */
    long min_end_time;
    /**
     * max_end_time - maximum guaranteed phase timing
     */
    long max_end_time;
    /**
     * likely_time - likely time of the phase
     */
    long likely_time;
    /**
     * confidence - confidence value of the likely_time
     */
    long confidence;
    /**
     * next_time - the future timing information
     */
    long next_time;
} mde_TimeChange_t;

/**
 * Mde_MovementEventList_t - a movement event describing the phase and
                                       the time information of the phase or
                                       the future phase
 */
typedef struct _mde_MovementEventList_t
{
    /**
     * phase_state - phase state of the movement
     */
    Mde_MovementPhaseState_t phase_state;
    /**
     * time_change_info - timing information of the phase
     */
    mde_TimeChange_t time_change_info;
} mde_MovementEventList_t;

/**
 * Mde_MovementState_t - movement state enclosure describing the signal
                                  group id and a set of movement events.
 */
typedef struct _mde_MovementState_t
{
    /**
     * signal_group_id - signal group id of the movement. Obtained from MAP
     */
    long signal_group_id;
    /**
     * num_movement_event - number of movement events (1 to 16)
     */
    int num_movement_event;
    /**
     * movement_event - movement event list
     */
    mde_MovementEventList_t* movement_event;
} mde_MovementState_t;

/**
 * Mde_EnableLaneList_t - Enabled Lanes that are advertised in SPaT
 */
typedef struct _mde_EnableLaneList_t
{
    /**
     * lane_id - lane ID
     */
    long lane_id;
} mde_EnableLaneList_t;

/**
 * Mde_Intersection_t - Intersection information
 */
    typedef struct intersection_data
{
    // long road_reg_id;
    /**
     * intersection_id - intersection id
     */
    long intersection_id;
    /**
     * msgCount - message count of the SPaT. Increment only when there is
                    an information change in the message (0 - 127)
     */
    long msgCount;
    /**
     * intersection_status - status of the intersection
     */
    Mde_IntersectionStatus_t intersection_status;
    /**
     * min_of_the_year - minute of the year
     */
    int min_of_the_year;
#define Mde_TIMESTAMP_MS_MIN 0
#define Mde_TIMESTAMP_MS_MAX 65535
#define Mde_TIMESTAMP_MS_UNAVAIL 65535
#define Mde_TIMESTAMP_MS_NAV J2735_NAV
    /**
     * timestamp_ms - msec timestamp of the message
     */
    long long timestamp_ms;
    /**
     * n_lane_list - number of lanes if needed to send enabled_lanes
     */
    int n_lane_list;
    /**
     * num_movement_states - number of movement states
     */
    int num_movement_states;
    /**
     * num_maneuver_assist - number of maneuver assist frames
     */
    int num_maneuver_assist;
    /**
     * enabled_lanes - enabled lanes. If  set they will be transmitted over the
                        air. (0 - 16)
     */
    mde_EnableLaneList_t* enabled_lanes;
    /**
     * movement_states - set of movements describing the intersection
     */
    mde_MovementState_t* movement_states;
    /**
     * maneuver_assist - maneuver assist list
     */
    mde_ManeuverAssistList_t* maneuver_assist;
} mde_Intersection_t;

/**
 * @ingroup v2x_message
 * SPAT message structure
 */
typedef struct v2x_msg_spat
{
    /**
     * minute_of_the_year - minute of the year
     */
    int minute_of_the_year;
    /**
     * n_intersections - number of intersections (1 - 16)
     */
    int n_intersections;
    /**
     * intersection_list - intersection list
     */
    mde_Intersection_t* Intersection_list;
} v2x_msg_spat_t;

#ifdef __cplusplus
}
#endif

#endif
