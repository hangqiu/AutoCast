#ifndef V2X_MSG_BSM_DS_H__
#define V2X_MSG_BSM_DS_H__

#define MAX_PH_POINTS 23
#define BSM_CORE_DATA 1
#define BSM_VEHICLE_SAFETY_EXTN 2
#define BSM_SPECIAL_VEHICLE_EXTN 4
#define BSM_SUPPLEMENTAL_VEHICLE_EXTN 8

/* to two ds to be changed in later version */
struct pathhistoryframe
{
    double lat_offset;
    double long_offset;
    double elev_offset;
    int    time_offset;
    double positional_accuracy;
    double heading;
};

typedef struct v2x_msg_bsm
{
    /*
     *  element: MsgCount 
     *  desc: Provide a sequence number within a stream of messages with the same DSRCmsgID and from the same sender.
     *  range: 0...127
     */
    unsigned int                msgcount;

    /*
     *  element: TemporaryID 
     *  desc: This is the 4 octet random device identifier, called the TemporaryID.
     *  size: 4 byte
     */    
    unsigned int                temp_id;

    /*
     *  element: Longitude 
     *  desc: The geographic longitude of an object.
     *  range: -180...180 degrees
     *  lsb: 0.1 micro degree
     */ 
    double                  longitude;

    /*
     *  element: Latitude 
     *  desc: The geographic latitude of an object.
     *  range: -90...90 degrees
     *  lsb: 0.1 micro degree
     */    
    double                  latitude;

    /*
     *  element: Elevation 
     *  desc: The geographic position above or below the reference ellipsoid (typically WGS-84).
     *  range: -409.5...6143.9 m
     *  lsb: 0.1m
     */   
    double                  elevation;

    /*
     *  element: positionalaccuracy[0]: SemiMajorAxisAccuracy 
     *  desc: The element is used to express the radius (length) of the semi-major axis of an ellipsoid representing the 
     *        accuracy which can be expected from a GNSS system in 5cm steps, typically at a one sigma level of confidence.
     *  range: 0...12.7 m
     *  lsb: 0.05m
     */
    /*
     *  element: positionalaccuracy[1]: SemiMinorAxisAccuracy 
     *  desc: The element is used to express the radius of the semi-minor axis of an ellipsoid representing the accuracy 
     *        which can be expected from a GNSS system in 5cm steps, typically at a one sigma level of confidence.
     *  range: 0...12.7 m
     *  lsb: 0.05m
     */ 
    /*
     *  element: positionalaccuracy[2]: SemiMajorAxisOrientation 
     *  desc: The element is used to orientate the angle of the semi-major axis of an ellipsoid representing the accuracy 
     *        which can be expected from a GNSS system with respect to the coordinate system.
     *  range: 0...359.9945078786 degrees
     *  lsb: 360/65535 deg
     */   
    double                  positionalaccuracy[3];

    /*
     *  element: TransmissionState 
     *  desc: The element is used to provide the current state of the vehicle transmission.
     *  range: 0...7
     *  neutral (0), -- Neutral
     *  park (1), -- Park
     *  forwardGears (2), -- Forward gears
     *  reverseGears (3), -- Reverse gears
     *  reserved1 (4),
     *  reserved2 (5),
     *  reserved3 (6),
     *  unavailable (7) -- not-equipped or unavailable value
     */      
    unsigned int                transmissionstate;

    /*
     *  element: Speed 
     *  desc: The vehicle speed expressed in unsigned units of 0.072 km/h. 
     *  range: 0...163.82 km/h
     *  lsb: 0.072 km/h
     */ 
    double                  speed;

    /*
     *  element: Heading 
     *  desc: The element provides the current heading of the sending device, expressed in unsigned units of
     *        0.0125 degrees from North such that 28799 such degrees represent 359.9875 degrees. 
     *  range: 0...359.9875 degrees
     *  lsb: 0.0125 degree
     */ 
    double                  heading;

    /*
     *  element: SteeringWheelAngle 
     *  desc: The angle of the driver’s steering wheel, expressed in a signed (to the right being positive) value with LSB 
     *        units of 1.5 degrees.
     *  range: -189...189 degrees
     *  lsb: 1.5 degrees
     */ 
    double                  angle;

    /*
     *  element: LongAcceleration
     *  desc: The element represents the signed acceleration of the vehicle along the Vehicle Longitudinal axis in units of 
     *        0.01 meters per second squared.
     *  range: -20...20 m/s^2
     *  lsb: 0.01 m/s^2
     */  
    double                  longaccel;

    /*
     *  element: LatAcceleration
     *  desc: The element represents the signed acceleration of the vehicle along the Vehicle Lateral axis in units of 
     *        0.01 meters per second squared.
     *  range: -20...20 m/s^2
     *  lsb: 0.01 m/s^2
     */ 
    double                  lataccel;

    /*
     *  element: VerticalAcceleration
     *  desc: The element representing the signed vertical acceleration of the vehicle along the vertical axis in units of 
     *        0.02 G (where 9.80665 meters per second squared is one G, i.e., 0.02 G = 0.1962 meters per second squared).
     *  range: -24.7...24.9 m/s^2
     *  lsb: 0.1962 m/s^2
     */ 
    double                  vertaccel;

    /*
     *  element: YawRate
     *  desc: The element provides the Yaw Rate of the vehicle, a signed value (to the right being positive) expressed in 
     *        0.01 degrees per second. 
     *  range: -327.67...327.67 deg/s
     *  lsb: 0.01 deg/s
     */ 
    double                  yawrate;
    
    unsigned int                secmark;
    double                  unix_time;
    unsigned int                wheelbrake;
    unsigned int                wheelbrakeavailable;
    unsigned int                sparebit;
    int                     traction;
    int                     abs;
    int                     stabilitycontrol;
    unsigned int                brakeboost;
    unsigned int                auxbrakes;

    /*
     *  element: VehicleWidth 
     *  desc: The width of the vehicle expressed in centimeters, unsigned. The width shall be the widest point of the vehicle 
     *        with all factory installed equipment. The value zero shall be sent when data is unavailable.
     *  range: 0...10.23 m
     *  lsb: 0.01m
     */
    double                  width;

    /*
     *  element: VehicleLength 
     *  desc: The length of the vehicle measured from the edge of the front bumper to the edge of the rear bumper expressed in
     *        centimeters, unsigned. It should be noted that this value is often combined with a vehicle width value to form a 
     *        data frame.The value zero shall be sent when data is unavailable.
     *  range: 0...40.95 m
     *  lsb: 0.01m
     */ 
    double                  length;

    unsigned int                event_hazardlights;  // bsm part2 start here //
    unsigned int                event_absactivate;
    unsigned int                event_tractionctrlloss;
    unsigned int                event_stabilityctrlactivated;
    unsigned int                event_hazardbraking;
    unsigned int                event_airbag;
    unsigned int                count;
    struct pathhistoryframe phf[23];
    unsigned int                lowbeam;
    unsigned int                highbeam;
    unsigned int                leftturnsignal;
    unsigned int                rightturnsignal;
    unsigned int                hazardlights;
    unsigned int                autolightcontrol;
    unsigned int                dtimerunlights;
    unsigned int                foglights;
    unsigned int                parkinglights;

    /*
     *  element: WiperStatusFront
     *  desc: The current status of a wiper system on the subject vehicle.
     *  range: 0...6
     *  unavailable (0), -- Not Equipped with wiper status or wiper status is unavailable
     *  off (1),
     *  intermittent (2),
     *  low (3),
     *  high (4),
     *  washerInUse (5), -- washing solution being used
     *  automaticPresent (6), -- Auto wiper equipped
     */ 
    int                     wipers_swfnt;

    /*
     *  element: WiperRateFront
     *  desc: The current rate at which wiper sweeps are taking place on the subject vehicle, in units of sweeps per minute. 
     *        A value of 1 is used for any sweep rate with a period greater than 60 seconds.
     *  range: 0...127
     *  lsb: 1 sweeps per minute
     */ 
    int                     wipers_rtfnt;

    /*
     *  element: WiperStatusRear
     *  desc: The current status of a wiper system on the subject vehicle.
     *  range: 0...6
     *  unavailable (0), -- Not Equipped with wiper status or wiper status is unavailable
     *  off (1),
     *  intermittent (2),
     *  low (3),
     *  high (4),
     *  washerInUse (5), -- washing solution being used
     *  automaticPresent (6), -- Auto wiper equipped
     */ 
    int                     wipers_swrear;

    /*
     *  element: WiperRateRear
     *  desc: The current rate at which wiper sweeps are taking place on the subject vehicle, in units of sweeps per minute. 
     *        A value of 1 is used for any sweep rate with a period greater than 60 seconds.
     *  range: 0...127 sweeps per minute
     *  lsb: 1 sweeps per minute
     */ 
    int                     wipers_rtrear;

    /*
     *  element: VehicleHeight
     *  desc: The height of the vehicle, measured from the ground to the highest surface, excluding any antenna(s).
     *  range: 0...6.35 m
     *  lsb: 0.05 m
     */ 
    double                  vehicleheight;

    /*
     *  element: BumperHeightFront
     *  desc: The element conveys the height of front bumpers of the vehicle or object. 
     *  range: 0...1.27 m
     *  lsb: 0.01 m
     */  
    double                  bumperheight_front;

    /*
     *  element: BumperHeightRear
     *  desc: The element conveys the height of rear bumpers of the vehicle or object. 
     *  range: 0...1.27 m
     *  lsb: 0.01 m
     */ 
    double                  bumperheight_rear;

    /*
     *  element: VehicleMass
     *  desc: The element represents the estimated weight of the vehicle.
     *  range: 0... 170000 kg
     *  lsb: Values 0kg to 4000kg in steps of 50kg
     *       Values 4000kg to 64000kg in steps of 500kg     
     *       Values 64000kg to 170000kg in steps of 2000kg   
     */ 
    int                     vehiclemass;

    /*
     *  element: VehicleType 
     *  desc: The element is a type list (i.e., a classification list) of the vehicle in terms of overall size. 
     *  range: 0...15
     *  none (0), -- Not Equipped, Not known or unavailable
     *  unknown (1), -- Does not fit any other category
     *  special (2), -- Special use
     *  moto (3), -- Motorcycle
     *  car (4), -- Passenger car
     *  carOther (5), -- Four tire single units
     *  bus (6), -- Buses
     *  axleCnt2 (7), -- Two axle, six tire single units
     *  axleCnt3 (8), -- Three axle, single units
     *  axleCnt4 (9), -- Four or more axle, single unit
     *  axleCnt4Trailer (10), -- Four or less axle, single trailer
     *  axleCnt5Trailer (11), -- Five or less axle, single trailer
     *  axleCnt6Trailer (12), -- Six or more axle, single trailer
     *  axleCnt5MultiTrailer (13), -- Five or less axle, multi-trailer
     *  axleCnt6MultiTrailer (14), -- Six axle, multi-trailer
     *  axleCnt7MultiTrailer (15), -- Seven or more axle, multi-trailer
     */
    unsigned int                vehicletype;

    /*
     *  element: Extent 
     *  desc: The spatial distance over which this message applies and should be presented to the driver.
     *  range: 0...15
     *  useInstantlyOnly (0),
     *  useFor3meters (1),
     *  useFor10meters (2),
     *  useFor50meters (3),
     *  useFor100meters (4),
     *  useFor500meters (5),
     *  useFor1000meters (6),
     *  useFor5000meters (7),
     *  useFor10000meters (8),
     *  useFor50000meters (9),
     *  useFor100000meters (10),
     *  useFor500000meters (11),
     *  useFor1000000meters (12),
     *  useFor5000000meters (13),
     *  useFor10000000meters (14),
     *  forever (15) -- very wide area
     */ 
    unsigned int                sve_evdsc_extent;
} v2x_msg_bsm_t;

typedef struct PH_offsets
{
    int latoffset;
    int longoffset;
    int elevoffset;
    int timeoffset;
} PHPointOffsets;

#endif
