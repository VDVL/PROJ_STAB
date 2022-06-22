#include "motion_di.h"
#include "motion_di_manager.h"
#include "lsm6dso.h"
#include "main.h"

//MOTION DI INIT AND COMPUTE
#define VERSION_STR_LENG 35
#define DECIMATION  1U
#define FROM_MG_TO_G  0.001f
#define FROM_G_TO_MG  1000.0f
#define FROM_MDPS_TO_DPS  0.001f
#define FROM_DPS_TO_MDPS  1000.0f
#define ALGO_FREQ  100U /* Algorithm frequency 100Hz */
#define ALGO_PERIOD  (1000000U / ALGO_FREQ) /* Algorithm period [us] */

/*** Initialization ***/
char lib_version[VERSION_STR_LENG];
float freq = 100.0f;
static MDI_knobs_t iKnobs;
static MDI_knobs_t *ipKnobs = &iKnobs;

MDI_input_t data_in;
MDI_output_t data_out;

static int64_t Timestamp = 0;

LSM6DSO_Axes_t acc_IMU;
LSM6DSO_Axes_t gyro_IMU;

void Fusion_datas_init(void){

	INIT_IMU();

	/* Dynamic Inclinometer API initialization function */
	MotionDI_Initialize(&freq);
	/* Optional: Get version */
	MotionDI_GetLibVersion(lib_version);

	/* Optional: Modify knobs settings & set the knobs */
	MotionDI_getKnobs(ipKnobs);

	ipKnobs->AccKnob.CalType = MDI_CAL_CONTINUOUS;
	ipKnobs->GyrKnob.CalType = MDI_CAL_CONTINUOUS;

	BSP_SENSOR_ACC_GetOrientation(ipKnobs->AccOrientation);
	BSP_SENSOR_GYR_GetOrientation(ipKnobs->GyroOrientation);

	ipKnobs->SFKnob.output_type = MDI_ENGINE_OUTPUT_ENU;
	ipKnobs->SFKnob.modx = DECIMATION;

	MotionDI_setKnobs(ipKnobs);
}


MDI_output_t Fusion_datas(void){


	if(Flag_compute_fusion ==1){

		Flag_compute_fusion =0;
		Flag_compute_PID =1; //activate computation for PID

		/* Get acceleration X/Y/Z in g */
		acc_IMU = Get_AXIS_ACC__IMU();
		/* Get angular velocity  X/Y/Z in mdps */
		gyro_IMU =   Get_AXIS_GYRO__IMU();

		/* Convert acceleration from [mg] to [g] */
		data_in.Acc[0] = (float)acc_IMU.x * FROM_MG_TO_G;
		data_in.Acc[1] = (float)acc_IMU.y * FROM_MG_TO_G;
		data_in.Acc[2] = (float)acc_IMU.z * FROM_MG_TO_G;

		/* Convert angular velocity from [mdps] to [dps] */
		data_in.Gyro[0] = (float)gyro_IMU.x * FROM_MG_TO_G;
		data_in.Gyro[1] = (float)gyro_IMU.y * FROM_MDPS_TO_DPS;
		data_in.Gyro[2] = (float)gyro_IMU.z * FROM_MDPS_TO_DPS;

		//Increment sample time
		data_in.Timestamp = Timestamp;
		Timestamp += ALGO_PERIOD;

		/* Run Dynamic Inclinometer algorithm */
		MotionDI_update(&data_out, &data_in);


	}
	return data_out;
}

// Change scale in degrees of roll, from [-90 +90] to [-180 +180]
float from_90_to_180(float roll_90,float gravity){
	float roll_180=0;

	if(roll_90 < 0){
		if(gravity < 0){		//zone A
			roll_180 = roll_90;
		}
		else{ 					//zone D
			roll_180 = -90 - (90 + roll_90);
		}
	}
	else
	{
		if(gravity < 0){		//zone B
			roll_180 = roll_90;
		}
		else{					//zone C
			roll_180 = 90 + (90 -roll_90);
		}
	}

	return roll_180;
}
