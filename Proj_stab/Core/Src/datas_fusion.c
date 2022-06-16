#include "motion_di.h"
#include "motion_di_manager.h"

//MOTION DI INIT AND COMPUTE
#define VERSION_STR_LENG 35
#define DECIMATION  1U

/*** Initialization ***/
char lib_version[VERSION_STR_LENG];
float freq = 100.0f;
static MDI_knobs_t iKnobs;
static MDI_knobs_t *ipKnobs = &iKnobs;





void Fusion_datas_init(void){
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


void Fusion_datas(void){

}
