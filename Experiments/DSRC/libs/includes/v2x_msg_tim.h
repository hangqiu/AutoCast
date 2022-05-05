/*
 * Copyright (c) 2018 Huali ismartways,
 * All Rights Reserved.
 *
 *
 * Description:
 * This header contains the necessary APIs and data structures that are
 * needed to encode/decode the BSM. link with -lj2735_2016 and -lsae_2016 and -lm
 */

#ifndef __TIM_H__
#define __TIM_H__

#include <v2x_msg_common.h>

#ifdef __cplusplus
extern "C" {
#endif

#define ASN1_MAX_HOP_SEG         32
#define MDE_NODE_OFF_MAX         63
#define MDE_REG_OFFSET_MAX       64
#define MDE_NODE_OFF_MAX         63


/**
 * TIM content types
 */
typedef enum Mde_ContentType
{
    /**
     * Advisory Content type
     */
    Mde_CONTENT_ADVISORY = 1,
    /**
     * WorkZone Content type
     */
    Mde_CONTENT_WORKZONES,
    /**
     * Generic Sign Content type
     */
    Mde_CONTENT_GENERIC_SIGNS,
    /**
     * SpeedLimit Content type
     */
    Mde_CONTENT_SPEED_LIMITS,
    /**
     * Exit service Content type
     */
    Mde_CONTENT_EXIT_SERVICES
} Mde_ContentType_t;

typedef enum Mde_TravelerInfoType
{
    /** TIM type is unknown */
    Mde_TIM_TYPE_UNKNOWN,
    /** TIM type is advisory */
    Mde_TIM_TYPE_ADVISORY,
    /** TIM type is road signage */
    Mde_TIM_TYPE_ROAD_SIGNAGE,
    /** TIM type is commercial signage */
    Mde_TIM_TYPE_COMMERCIAL_SIGNAGE,
} Mde_TravelerInfoType_t;

/**
 * Heading slice information.
 * Refer to DE_HeadingSlice object in SAE J735 for details.
 */
typedef enum Mde_HeadingSlice
{
    Mde_HS_NO_HEADING              = 0x0,    /**< No Heading */
    Mde_HS_ALL_HEADINGS            = 0xffff, /**< All Heading values */
    Mde_HS_FROM000_0TO022_5DEGREES = 0x0001, /**< Heading range 0 - 22.5 deg */
    Mde_HS_FROM022_5TO045_0DEGREES = 0x0002, /**< Heading range 22.5 - 45 deg */
    Mde_HS_FROM045_0TO067_5DEGREES = 0x0004, /**< Heading range 45 - 67.5 deg */
    Mde_HS_FROM067_5TO090_0DEGREES = 0x0008, /**< Heading range 67.5 - 90 deg */
    Mde_HS_FROM090_0TO112_5DEGREES = 0x0010, /**< Heading range 90 - 112.5 deg */
    Mde_HS_FROM112_5TO135_0DEGREES = 0x0020, /**< Heading range 112.5 - 135 deg */
    Mde_HS_FROM135_0TO157_5DEGREES = 0x0040, /**< Heading range 135 - 157.5 deg */
    Mde_HS_FROM157_5TO180_0DEGREES = 0x0080, /**< Heading range 157.5 - 180 deg */
    Mde_HS_FROM180_0TO202_5DEGREES = 0x0100, /**< Heading range 180 - 202.5 deg */
    Mde_HS_FROM202_5TO225_0DEGREES = 0x0200, /**< Heading range 202.5 - 225 deg */
    Mde_HS_FROM225_0TO247_5DEGREES = 0x0400, /**< Heading range 225 - 247.5 deg */
    Mde_HS_FROM247_5TO270_0DEGREES = 0x0800, /**< Heading range 247.5 - 270 deg */
    Mde_HS_FROM270_0TO292_5DEGREES = 0x1000, /**< Heading range 270 - 292.5 deg */
    Mde_HS_FROM292_5TO315_0DEGREES = 0x2000, /**< Heading range 292.5 - 315 deg */
    Mde_HS_FROM315_0TO337_5DEGREES = 0x4000, /**< Heading range 315 - 337.5 deg */
    Mde_HS_FROM337_5TO360_0DEGREES = 0x8000, /**< Heading range 337.5 - 360 deg */
} __attribute__((packed)) Mde_HeadingSlice_t;

/**
 * MUTCD Code information.
 */
typedef enum Mde_MUTCDCode
{
    /**
     * No MUTCD information.
     */
    Mde_MUTCD_CODE_NONE,
    /**
     * Regulatory signs.
     */
    Mde_MUTCD_CODE_REGULATORY,
    /**
     * Warning signs.
     */
    Mde_MUTCD_CODE_WARNING,
    /**
     * Maintenance and construction.
     */
    Mde_MUTCD_CODE_MAINTENANCE,
    /**
     * Motorist Services.
     */
    Mde_MUTCD_CODE_MOTORIST_SERVICE,
    /**
     * Guide signs.
     */
    Mde_MUTCD_CODE_GUIDE,
    /**
     * Recreation and Cultural Interest.
     */
    Mde_MUTCD_CODE_REC,
} Mde_MUTCDCode_t;

/**
 * RoadSign ID
 */
typedef struct Mde_RoadSignID
{
    /**
     * Position 3d object
     */
    mde_pos_3d_t position;
    /**
     * Heading slice. Value should be one of HeadingSlice_t enum values.
     */
    Mde_HeadingSlice_t heading_slice;
    /**
     * MUTCD Code
     */
    Mde_MUTCDCode_t mutcd_code;
} mde_RoadSignID_t;

/**
 * DirectionOfUse_t - direction of use
 */
typedef enum Mde_DirectionOfUse
{
    /**
     * Direction unavailable
     */
    Mde_DIRECTION_UNAVAIL = 0,

    /**
     * Forward direction case
     */
    Mde_DIRECTION_FORWARD,
    /**
     * Reverse direction case
     */
    Mde_DIRECTION_REVERSE,
    /**
     * Both the cases
     */
    Mde_DIRECTION_BOTH,
} Mde_DirectionOfUse_t;
/**
 * Mde_RegionsList_t - region of use
 */
typedef enum Mde_Regions
{
    /**
     * No Region
     */
    Mde_REGION_NOTHING,
    /**
     * Shapepoint region
     */
    Mde_REGION_SHAPEPT,
    /**
     * Circular region
     */
    Mde_REGION_CIRCLE,
    /**
     * Polygon region
     */
    Mde_REGION_POLYGON,
} Mde_RegionsList_t;

/**
 * ShapePoints_t - shapepoint set region
 *          the shapepoint region is a region
                formed by connecting the lat, long and
                elevation points. these are found by adding
                offsets to the anchor point.
 */
typedef struct Mde_ShapePointSet
{
    /**
     * position - anchor point to tell the base position
     */
    mde_pos_3d_t          position;
    /**
     * lanewidth - common lanewidth for the described shape points at the wplist
     */
    double                lanewidth;
    Mde_DirectionOfUse_t directionofuse;
    /**
     * num_nodelist - no of nodes
     */
    int num_wp;
    /**
     * nodelist -set of nodes conforming to this shapepoint region
     */
    mde_pos_3d_t* wplist;
} Mde_ShapePoints_t;

/**
 * RadiusType_t - Radius type enums
 */
typedef enum Mde_RadiusType
{
    /**
     * RadiusSteps range 0 - 32767, in steps of 2.5 cm. the library
     * takes care of converting the value in to steps of 2.5 cm and
     * if the value is less than 0 it sets it back to 0 and if its
     * more than 32767 it sets it to 32767
     */
    /**
     * Centimeters unit
     */
    RADIUS_TYPE_CENTIMETER,
    /**
     * In steps of 2.5 cms
     */
    RADIUS_TYPE_CM_2_5,
    /**
     * In steps of decimeters
     */
    RADIUS_TYPE_DECIMETER,
    /**
     * In steps of meters
     */
    RADIUS_TYPE_METER,
    /**
     * In steps of kilometers
     */
    RADIUS_TYPE_KILOMETER,
    /**
     * In steps of foot
     */
    RADIUS_TYPE_FOOT,
    /**
     * In steps of yard
     */
    RADIUS_TYPE_YARD,
    /**
     * In steps of mile
     */
    RADIUS_TYPE_MILE,
} Mde_RadiusType_t;

/**
 * CircularRegion_t - Cicular region
 *
 * denotes the valid region in the
 * form of a circle.
 */
typedef struct Mde_CircularRegion
{
    /**
     * position - positon 3d point with lat, long and elev
     */
    mde_pos_3d_t position;
    /**
     * radius_type - one of RadiusType_t types
     */
    Mde_RadiusType_t radius_type;  // 0 to 4095 in the radius units
    /**
     * value - value of the radius, the value should be filled based on type
     */
    double value;
} mde_CircularRegion_t;

/**
 * Mde RegionPointSet_t - Region pointset
 *
 * This is used to represent or describe an enclosed region.  It is typically employed to define a region where signs or
 * advisories would be valid.
 */

typedef struct
{
    mde_pos_3d_t pos3d;
} mde_RegionOffsets;

typedef struct
{
    /**
     * position - positon 3d point with lat, long and elev
     * if non null this will be filled into the region points
     * of TIM
     */
    mde_pos_3d_t* position;
    /**
     * zoom_level - zoom level to scale the offsets. Zoom level reduces the precision of the offsets while increasing
     * the range
     */
    int zoom_level;
    /**
     * region_offset_len - length of the region offsets (1 to 64)
     */
    int region_offset_len;
    /**
     * reg_offsets - region offsets of type position3d which are then converted back into offsets per 2016
     */
    mde_RegionOffsets reg_offsets[MDE_REG_OFFSET_MAX];
    /**
     * num_reg - number of region point offsets that are in the
     * regions pointer below
     */
    int num_wp;
    /**
     * regions - region offsets from the positon point if present
     * otherwise the offsets are from the common anchor point
     */
    mde_pos_3d_t* wplist;
} mde_RegionPointSet_t;

typedef struct
{
    /**
     * heading_slice. Value should be one of HeadingSlice_t enum values
     */
    Mde_HeadingSlice_t heading_slice;
    /**
     * extent - extent a value in meters
     *          a value of 0 implies the use of
     *          extent instantaneously
     */
    double extent;
    /**
     * region_flag - region type
     */
    Mde_RegionsList_t region_flag;
    /**
     * shape_points - shape point data
     */
    Mde_ShapePoints_t shape_points;
    /**
     * circle - circular region data
     */
    mde_CircularRegion_t circle;
    /**
     * regionpoint - region point set data
     */
    mde_RegionPointSet_t regionpoint;
} mde_ValidRegion_t;

/**
 * RoadSegmentRefId_t - RoadSegment ID is unique to a particular region of road segment
 */
typedef struct RoadSegmentRefId
{
    /**
     * region_id - unique regional ID
     */
    int region_id;
    /**
     * roadsegment_id - ID of the particular road segment
     */
    int roadsegment_id;
} RoadSegmentRefId_t;

/**
 * ProjectionType_t - Projection type
 */
typedef enum
{
    /**
     * Offset system
     */
    Mde_PROJECTION_OFFSET_SYSTEM,
    /**
     * Geometric projection
     */
    Mde_PROJECTION_GEO_PROJECTION,
    /**
     * Valid region - Legacy valid region
     */
    Mde_PROJECTION_VALID_REGION,
} Mde_ProjectionType_t;

typedef enum
{
    /**
     * XY offsets
     */
    Mde_OFFSET_TYPE_XY,
    /**
     * LL offsets - not supported
     */
    Mde_OFFSET_TYPE_LL,
} Mde_OffsetSystemType_t;

typedef enum
{
    /**
     * Node XY
     */
    Mde_NODESET_XY,
    /**
     * Computed Lanes - not supported
     */
    Mde_COMPUTED_LANES,
} Mde_NodeXY_type_t;

/**
 * Mde_NodeSet_XY_t - NodeSet list used to describe a set of nodes
 */
typedef struct Mde_NodeSet_XY
{
    /**
     * n_node_offsets - number of node offsets (2 to 64)
     */
    int n_node_offsets;
    /**
     * node_offsets - number of node offsets described using lat and long
     */
    mde_pos_3d_t node_offsets[MDE_NODE_OFF_MAX];
} mde_NodeSet_XY_t;

// TBD: FIXME: no support for computed lanes
/**
 * Computed_Lanes_t - not supported
 */
typedef struct mde_Computed_Lanes
{
} mde_Computed_Lanes_t;

/**
 * NodeXY_t - Node XY data structure enclosing the nodes
 */
typedef struct
{
    /**
     * node_xy_type - one of XY or LL
     */
    Mde_NodeXY_type_t node_xy_type;
    /**
     * nodeset - set of nodes describing the region
     */
    mde_NodeSet_XY_t nodeset;
    /**
     * computed_lanes - set of computed lanes
     */
    mde_Computed_Lanes_t computed_lanes;
} mde_NodeXY_t;


typedef struct
{
    mde_pos_3d_t latlong_offsets[MDE_NODE_OFF_MAX];
} mde_LatLong_t;

/**
 * OffsetSystem_t - offset system describing the nodes in detail either in xy or ll
 */
typedef struct
{
    /**
     * zoom_level - zoom level to scale the offsets. Zoom level reduces the precision of the offsets while increasing
     * the range
     */
    int zoom_level;  // 0 to 15
    /**
     * off_sys_type - offset system type in use - only xy are supported
     */
    Mde_OffsetSystemType_t off_sys_type;
    /**
     * - node_set_xy - enclosed structure for the set of xy node offset points
     */
    mde_NodeXY_t node_set_xy;
    /**
     * - node_set_ll - enclosed structure for the set of ll node offset points
     */
    mde_LatLong_t node_set_ll;
} mde_OffsetSystem_t;

/**
 * GeometricProjection_t - geometric projection structure
                                      The geometric projection is used to define
                                      simple geometric shapes.
 */
typedef struct
{
    /**
     * heading_slice - direction that is valid to this message
     */
    Mde_HeadingSlice_t heading_slice;
    /**
     * extent - the range to which the message is valid
     */
    Mde_Extent_t extent;
    /**
     * lane_width - width of the lane if any that is useful for the geometry shape
     */
    double lane_width;
    /**
     * circle - circular geometric shape
     */
    mde_CircularRegion_t circle;
} mde_GeometricProjection_t;

typedef struct
{
    /**
     * id - unique roadsegment that this message refers to
     */
    RoadSegmentRefId_t id;
    /**
     * valid_pos3d - a bit to inform if the pos3d is valid. set to 1 if pos3d is valid, 0 otherwise
     */
    int valid_pos3d;
    /**
     * pos3d - anchor point to describe the regions with node offsets from here.
     */
    mde_pos_3d_t pos3d;
    /**
     * lane_width - common lanewidth of the node points
     */
    double lane_width;
    /**
     * directionality - direction of this message. A car going in opposite direction will ignore this message
     */
    Mde_DirectionOfUse_t directionality;
    /**
     * closedpath - when set the last point closes to first.
     */
    int closedpath;  // 1 or 0
    /**
     * heading_slice - field of view of this message
     */
    Mde_HeadingSlice_t heading_slice;
    /**
     * projection_type - type of the projection in use.
                            one of the offset_system, geometric_projection or
                            valid_region.
     */
    Mde_ProjectionType_t projection_type;
    /**
     * offset_system - offset system describing the precise node points
     */
    mde_OffsetSystem_t offset_system;
    /**
     * geometric_projection - geometric projection describing different set of
                                 geometric areas
     */
    mde_GeometricProjection_t geometric_projection;
    /**
     * valid_region - older valid region defined in 2009.
                         Not to be used in 2016.
     */
    mde_ValidRegion_t valid_region;
} Mde_TIMGeoPath_t;

typedef struct
{
    /**
     * ssp_tim_rights - ssp bits that are set in 1609.2 of this message and
                            for this header
     */
    int ssp_tim_rights;
    /**
     * type  - type is one of Mde TravelerInfoType_t type.
     * \n\n if its further info id , the further_info_id field
     * should be populated
     * \n\n if its roadsign id, then the road_sign_id field
     * should be populated
     */
    Mde_TravelerInfoType_t type;
    // uint32_t                  msgid_type; // 0 - further_info_id,
    // 1 - road_sign_id
    /**
     * further_info_id - further info ID of the TIM message
     */
    uint32_t further_info_id;
    /**
     * road_sign_id - roadsign ID of the TIM message
     */
    mde_RoadSignID_t road_sign_id;
    /**
     * start_year - the year at which the message started transmitting
     */
    int32_t start_year;  // 0 - 9999, -1 if not present
    /**
     * start_minute_of_year - start minute of the year, it is from JAN1 at 00:00
       hrs and mins, and at current year to the present date, hrs:mins.
     */
    uint32_t start_minute_of_year;  // 0 - 525960
    /**
     * duration - the duration of each TIM message
     * 0 - min
     * 32000 - max
     * the duration is in minutes
     */
    int32_t duration;  // 0 - 32000 in minutes
    /**
     * priority - TIM message priority
     */
    int32_t priority;  // 0 - 7, 0 - least 7 - highest

    /**
     * ssp_loc_rights - ssp bits that are set in 1609.2 of this message and
                          for this content
     */
    int ssp_loc_rights;
    /**
     * n_geo_path - number of geographic path points (1 to 16)
     */
    // int                         n_geo_paths;
    /**
     * geographical_path - geographical path representing the TIM region
     */
    int               valid_pos3d;
    mde_pos_3d_t      pos3d;
    Mde_Extent        extent;

    unsigned char heading;
    /**
     * ssp_msg_rights1 - ssp bits that are set in 1609.2 of this message and
                           for this content
     */
    int ssp_msg_rights1;
    /**
     * ssp_msg_rights2 - ssp bits that are set in 1609.2 of this message and
                           for this content
     */
    int ssp_msg_rights2;
    // only one of the following groups should have atleast one code
    // and the remaining groups should have 0 codes
    /**
     * content_type - one of Mde ContentType_t. Only one of the all
                      codes should be specified. at a time ORing or ANDing
                      of two content types is invalid or wrong assignment
                      and the remaining groups should have 0 codes.
     */
    uint32_t content_type;
    /**
     * num_advisories - number of advisory codes to encode
     */
    uint32_t num_advisories;  // 0 - 100

    /**
     * advisory_codes - the advisory codes set
     * it is allocated to a num_advisories size
     */
    uint32_t* advisory_codes;
    /**
     * num_workzones - number of workzone codes to encode
     */
    uint32_t num_workzones;  // 0 - 10
    /**
     * workzone_codes - the workzone codes set
     * this pointer is allocated to num_workzones size
     */
    uint32_t* workzone_codes;
    /**
     * num_genericsigns - number of generic sign codes to encode
     */
    uint32_t num_genericsigns;  // 0 - 10
    /**
     * genericsign_codes - the genericsigns codes set
     * this pointer is allocated to num_genericsigns size.
     */
    uint32_t* genericsign_codes;
    /**
     * num_speedlimits - number of speed limit codes to encode
     */
    uint32_t num_speedlimits;  // 0 - 10
    /**
     * speedlimit_codes - the speedlimits codes set
     * this pointer is allocated to num_speedlimits size.
     */
    uint32_t* speedlimit_codes;
    /**
     * num_exiteservices - number of exit service codes to encode
     */
    uint32_t num_exitservices;  // 0 - 10
    /**
     * exitservice_codes - the exit service codes set
     * this pointer is allocated to num_exitservices size.
     */
    uint32_t* exitservice_codes;
} mde_DATAFRAME_t;

typedef struct rec_points
{
    mde_pos_3d_t    p1;
    mde_pos_3d_t    p2;
    uint32_t        width;
} rec_points_t;

typedef struct wz_hop_info
{

    /*
     * timestamp - Note, this is in milliseconds of a second percision, and is automatically
     *              filled in by the library on both encode and decode. UNIX timestamp
    */
    uint64_t timestamp;

    /**
    * common_anchor_point - contains lat, long and elevation information
    *                       elevation is not used
    */
    mde_pos_3d_t common_anchor_point;

    // XXX: Always set to 0 for now
    /**
     *    zoom -     A zoom scale applied in units of 2^N
     *    A value of 0 is a 1:1 zoom (no zoom)
     *    A value of 1 is a 2:1 zoom
     *    A value of 2 is a 4:1 zoom, etc.
     *    The zoom value is applied to one or more offsets
     *    increase the span or range while reducing its precision
     *    The absence of a zoom, any element in a data frame implies a 1:1 zoom
    **/
    uint32_t zoom;

    /**
        num_rectangles - number of rectangles
    **/
    int num_rectangles;

    /**
        rectangles - hopping algoirthm rectangles
    **/
    rec_points_t rectangles[ASN1_MAX_HOP_SEG];

} wz_hop_info_t;

typedef struct v2x_msg_tim
{
    /**
     * DSRC Messsage ID -> 0x10 for TIM
     */
    uint32_t message_id;
    int      msg_count;
    int      unique_id_len;
    /**
     * Packet ID must be a unique value
     */
    char unique_id[18];
    /**
     * Number of dataframes that the TIM has. Min is 1 and max is 8.
     */
    uint32_t num_dataframes; /* 1 - 8 */
    /**
     * Dataframes in the TIM message
     */
    mde_DATAFRAME_t* dataframes; /* 1 - 8 DATAFRAME structs */

    /**
     * Optional workzone addition : for hopping
     */
    struct wz_hop_info* hopinfo;

    /**
     * Message CRC. - obsolete, do not use this CRC field in 2016
     */
    uint16_t msg_crc;
} v2x_msg_tim_t;

#ifdef __cplusplus
}
#endif

#endif
