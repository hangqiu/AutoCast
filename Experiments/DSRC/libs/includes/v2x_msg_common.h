#ifndef _V2X_MSG_COMMON_H_
#define _V2X_MSG_COMMON_H_

typedef unsigned int uint32_t;
typedef int int32_t;
typedef unsigned long long  uint64_t;
typedef long long int64_t;
typedef unsigned short uint16_t;
typedef short int16_t;

typedef struct
{
    /**
     * latitude from -90.000000 to 90.000000
     */
    double latitude; /* degs -90.000000..90.000000 */
    /**
     * longitude from -180.000000 to 180.000000
     */
    double longitude; /* degs -180.000000..180.000000 */
    /**
     * elevation in cms
     */
    double elevation; /*  in cms */
}mde_pos_3d_t;

typedef enum
{
    MDE_EXTENT_USEINSTANTLYONLY     = 0,
    MDE_EXTENT_USEFOR3METERS        = 1,
    MDE_EXTENT_USEFOR10METERS       = 2,
    MDE_EXTENT_USEFOR50METERS       = 3,
    MDE_EXTENT_USEFOR100METERS      = 4,
    MDE_EXTENT_USEFOR500METERS      = 5,
    MDE_EXTENT_USEFOR1000METERS     = 6,
    MDE_EXTENT_USEFOR5000METERS     = 7,
    MDE_EXTENT_USEFOR10000METERS    = 8,
    MDE_EXTENT_USEFOR50000METERS    = 9,
    MDE_EXTENT_USEFOR100000METERS   = 10,
    MDE_EXTENT_USEFOR500000METERS   = 11,
    MDE_EXTENT_USEFOR1000000METERS  = 12,
    MDE_EXTENT_USEFOR5000000METERS  = 13,
    MDE_EXTENT_USEFOR10000000METERS = 14,
    MDE_EXTENT_FOREVER              = 15,
} Mde_Extent_t;

typedef enum{
    mde_useInstantlyOnly = 0,
    mde_useFor3meters = 1,
    mde_useFor10meters = 2,
    mde_useFor50meters = 3,
    mde_useFor100meters = 4,
    mde_useFor500meters = 5,
    mde_useFor1000meters = 6,
    mde_useFor5000meters = 7,
    mde_useFor10000meters = 8,
    mde_useFor50000meters = 9,
    mde_useFor100000meters = 10,
    mde_useFor500000meters = 11,
    mde_useFor1000000meters = 12,
    mde_useFor5000000meters = 13,
    mde_useFor10000000meters = 14,
    mde_forever = 15  /* very wide area */
} Mde_Extent;  

typedef struct
{
    int lane_id;
    int approach_id;
    int lane_conn_id;
} mde_IsecAccessPoint_t;

typedef struct
{
    int pos_conf;
    int elv_conf;
}mde_PosConf_t;

typedef struct
{
    mde_pos_3d_t            pos3d;
    double                  heading;  // optional
    double                  prndl;    // optional
    double                  speed;    // optional
    struct utcTimeFrame*    utctime;
    mde_PosConf_t           posconf;
}mde_FullPosVec_t;

struct utcTimeFrame
{
    /**
     * year - Year
     */
    long year;
    /**
     * month - Month
     */
    long month;
    /**
     * day - Day
     */
    long day;
    /**
     * hour - hour
     */
    long hour;
    /**
     * minute - minute
     */
    long minute;
    /**
     * second - second
     */
    long second;
};

typedef enum
{
    BASIC_VEHICLE_TYPE_BASIC_VEHICLE,
    BASIC_VEHICLE_TYPE_PUBLIC_TRANSPORT,
    BASIC_VEHICLE_TYPE_SPECIAL_TRANSPORT,
    BASIC_VEHICLE_TYPE_DANGEROUS_GOODS,
    BASIC_VEHICLE_TYPE_ROAD_WORKS,
    BASIC_VEHICLE_TYPE_ROAD_RESCUE,
    BASIC_VEHICLE_TYPE_EMERGENCY,
    BASIC_VEHICLE_TYPE_SAFETYCAR,
    BASIC_VEHICLE_TYPE_NONE_OR_UNKNOWN,
    BASIC_VEHICLE_TYPE_TRUCK,
    BASIC_VEHICLE_TYPE_MOTORCYCLE,
    BASIC_VEHICLE_TYPE_ROADSIDE_SOURCE,
    BASIC_VEHICLE_TYPE_POLICE,
    BASIC_VEHICLE_TYPE_FIRE,
    BASIC_VEHICLE_TYPE_AMBULANCE,
    BASIC_VEHICLE_TYPE_DOT,
    BASIC_VEHICLE_TYPE_TRANSIT,
    BASIC_VEHICLE_TYPE_SLOW_MOVING,
    BASIC_VEHICLE_TYPE_STOP_AND_GO,
    BASIC_VEHICLE_TYPE_CYCLIST,
    BASIC_VEHICLE_TYPE_PEDESTRIAN,
    BASIC_VEHICLE_TYPE_NON_MOTORIZED,
    BASIC_VEHICLE_TYPE_MILLITARY,
} Mde_BasicVehicleRole_t;

typedef enum
{
    VEHICLE_TYPE_NONE,
    VEHICLE_TYPE_UNKNOWN,
    VEHICLE_TYPE_SPECIAL,
    VEHICLE_TYPE_MOTO,
    VEHICLE_TYPE_CAR,
    VEHICLE_TYPE_CAR_OTHER,
    VEHICLE_TYPE_BUS,
    VEHICLE_TYPE_AXEL_CNT_2,
    VEHICLE_TYPE_AXEL_CNT_3,
    VEHICLE_TYPE_AXEL_CNT_4,
    VEHICLE_TYPE_AXEL_CNT_4_TRAILER,
    VEHICLE_TYPE_AXEL_CNT_5_TRAILER,
    VEHICLE_TYPE_AXEL_CNT_6_TRAILER,
    VEHICLE_TYPE_AXEL_CNT_5_MULTI_TRAILER,
    VEHICLE_TYPE_AXEL_CNT_6_MULTI_TRAILER,
    VEHICLE_TYPE_AXEL_CNT_7_MULTI_TRAILER,
} Mde_VehicleType_t;

typedef struct
{
    Mde_BasicVehicleRole_t        role;
    int                           req_subrole;            // optional
    int                           req_importance_level;   // optional
    int                           iso_3833_vehicle_type;  // optional
    Mde_VehicleType_t             hpms_vehicle_type;      // optional
    // FIXME: TBD: XXX: add support for the transit operations
} mde_RequestorType_t;

typedef struct
{
    int64_t temp_id;
    int64_t station_id;
} mde_VehicleID_t;

typedef enum
{
    Mde_PRIORITIZATION_RESPONSE_UNKNOWN = 0,
    Mde_PRIORITIZATION_RESPONSE_REQUESTED,
    Mde_PRIORITIZATION_RESPONSE_PROCESSING,
    Mde_PRIORITIZATION_RESPONSE_WATCH_OTHER_TRAFFIC,
    Mde_PRIORITIZATION_RESPONSE_GRANTED,
    Mde_PRIORITIZATION_RESPONSE_REJECTED,
    Mde_PRIORITIZATION_RESPONSE_MAX_PRESENCE,
    Mde_PRIORITIZATION_RESPONSE_RESERVICE_LOCKED,
}Mde_PrioritizationResponseStatus_t;
#endif