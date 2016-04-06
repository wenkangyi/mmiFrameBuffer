

#ifndef __APOLLO_PROTOCOL__
#define __APOLLO_PROTOCOL__

#define APOLLO_ID		0x15090001
#define AREA_NUMBER	0x0086
#define TELE_NUMBER	0x188741874290
#define PHONE_AREA_NUMBER	0x0086
#define PHONE_TELE_NUMBER		0x135098767890


#define HIGH_HEXTOSTRING(x)		(((x & 0xF0) >> 4)+0x30)
#define LOW_HEXTOSTRING(x)		((x & 0x0F) + 0x30)
#define STRINGTOHEX(x, y)			((((x  - 0x30)  & 0xFF )<< 4)| ((y - 0x30) & 0xFF) )

#define APOLLO_HEART_PACKAGE_LENGTH		16
#define APOLLO_UPLOAD_HEART_LENGTH		32
#define APOLLO_UPLOAD_GPS_LENGTH			48


#define HEART_PACKAGE_HEADER_CMD	'C'
#define HEART_PACKAGE_HEADER_REQUEST	'B'
#define HEADER_VOICE_PACKET			'V'


#define CMD_DEFAULT						0x00
#define CMD_NULL							0xFF
#define CMD_BT_SETON						0x01
#define CMD_BT_SETOFF						0x02
#define CMD_REMOTE_SHUTDOWN				0x03
#define CMD_SELECT_FARE					0x04
#define CMD_REALTIME_GPS					0x05
#define CMD_SEARCH_WATCH					0x06
#define CMD_ELECTIRC_FENCE					0x07
#define CMD_REFUSE_CALL_SETON				0x08
#define CMD_REFUSE_CALL_SETOFF			0x09
#define CMD_AUTO_CONNECT_SETON			0x10
#define CMD_AUTO_CONNECT_SETOFF			0x11
#define CMD_SHAKE_CONNECT_SETON			0x12	
#define CMD_SHAKE_CONNECT_SETOFF			0x13
#define CMD_HANDON_RECOGNITION_SETON	0x14
#define CMD_HANDON_RECOGNITION_SETOFF	0x15


#define CMD_LANGUAGE_CHINSES				0x20
#define CMD_LANGUAGE_ENGLISH				0x21
#define CMD_LANGUAGE_RESSION				0x22

#define CMD_TIMEZONE_1						0x41
#define CMD_TIMEZONE_2						0x42

#define CMD_VOICE_PACKET					0x60
#define CMD_REQUEST_VOICE					0x61


#define HEART_HEADER_INDEX			0
#define HEART_TELE_INDEX				1
#define HEART_CMD_INDEX				3
#define HEART_APOLOO_ID_START		9
#define HEART_RESPONSE_CMD_INDEX		13


#define HEART_RESPONSE_RES_START		14
#define HEART_RESPONSE_TEL_START		17

#define TELE_NUMBER_LENGTH	16
#define TELE_FARE_LENGTH		4

#define VOICE_PACKET_SIZE		1024
#define VOICE_HEADER_SIZE		32


U8 voiceHeader[APOLLO_UPLOAD_HEART_LENGTH] = {
	'V', 0x0,  0x86, 0x18,  0x87, 0x41,  0x87, 0x42,
	 0x90, 0x15, 0x10, 0x00, 0x02, 0x00, 0x1, 0x0,
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
};
	
U8 requestHeader[APOLLO_HEART_PACKAGE_LENGTH] = {
	'D', 0x0,  0x86, 0x18,  0x87, 0x41,  0x87, 0x42,
	 0x90, 0x15, 0x10, 0x00, 0x02, 0x61, 0x0, '%'
};


U8 heartHeader[APOLLO_UPLOAD_HEART_LENGTH] = {
	'H', 0x20,0x16,0x01,0x14,0x00,0x00,0x00,
	0x02, 0x60, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0,
	0x0, 0x1, 0x0, 0x0, '%', '%', '%', '%',
	'%', '%', '%', '%', '%', '%', '%', '%',	
};

U8 gpsHeader[APOLLO_UPLOAD_GPS_LENGTH] = {
	'G', 0x0,  0x86, 0x18,  0x87, 0x41,  0x87, 0x42,
	 0x90, 0x15, 0x10, 0x00, 0x02, 0x61, 0x0, 0x0,
	0x0,0x0,0x0,0x0,0x0,0x0, 0x0, 0x0,
	0x0,0x0,0x0,0x0,0x0,0x0, 0x0, 0x0,
	0x0,0x0,0x0,0x0,0x0,0x0, 0x0, 0x0,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0
};
#if (APOLLO_PROTOCOL_VERSION == APOLLO_SMART_WATCH)
typedef enum _control_command {
	COMMAND_NULL = 0x00,
	BLUETOOTH_POWERDOWN = 0x01,
	BLUETOOTH_SETUP = 0x02,
	WATCH_POWERDOWN = 0x03,
	TELEPHONEFARE_SELECT = 0x04,
	REALTIME_GPS_LOCATION = 0x05,
	SEATCH_WATCH = 0x06,	
	ELECTIRC_FENCE = 0x07,
	REFUSE_CALL_SETON = 0x08,
	REFUSE_CALL_SETOFF = 0x09,
	AUTO_CONNECT_SETON = 0x10,
	AUTO_CONNECT_SETOFF = 0x11,
	SHAKE_CONNECT_SETON = 0x12,
	SHAKE_CONNECT_SETOFF = 0x13,
	HANDON_RECOGNITION_SETON = 0x14,
	HANDON_RECOGNITION_SETOFF = 0x15,

	MUTE_SETON = 0x16,
	MUTE_SETOFF = 0x17,

	LISTEN_MODE = 0x18,
	
	LANGUAGE_CHINESE = 0x20,
	LANGUAGE_ENGLISH = 0x21,
	LANGUAGE_RESSION = 0x22,

	TIMEZONE_1 = 0x41,
	TIMEZONE_2 = 0x42,

	VOICE_PACKET = 0x60,
	REQUEST_VOICE = 0x61,
	COMMAND_DEFAULT = 0xFF,
} control_command;

#else

typedef enum _control_command {
	COMMAND_NULL = 0x00,
	COMMAND_REALTIME_POS = 0x01,
	COMMAND_VOICE_RECV	= 0x02,
	COMMAND_COUNTSTEP_SETON = 0x03,
	COMMAND_COUNTSTEP_SETOFF = 0x04,
	COMMAND_SLEEPQUALITY_SETON = 0x05,
	COMMAND_SLEEPQUALITY_SETOFF = 0x06,
	COMMAND_SET_PHONENUMBER = 0x07,
	COMMAND_ALARM	= 0x08,
	COMMAND_SAFEZONE_ALARM = 0x09,
	COMMAND_LONGSAT_ALARM = 0x0A,
	COMMAND_LOWPOWER_ALARM = 0x0B,

	COMMAND_FAMILYNUMBER_SET = 0x41,
	COMMAND_CONTRACT_SET = 0x42,
	COMMAND_PHONEBOOK_SET = 0x43,
	COMMAND_FREQ_SET = 0x44,

	COMMAND_SOS_MSGREMAINER_OPEN = 0x51,
	COMMAND_SOS_MSGREMAINER_CLOSE = 0x52,
	COMMAND_POWER_MSGREMAINDER_OPEN = 0x53,
	COMMAND_POWER_MSGREMAINDER_CLOSE = 0x54,

	COMMAND_ALARMMUSIC_OPEN = 0x61,
	COMMAND_ALARMMUSIC_CLOSE = 0x62,
	COMMAND_SAFEZONEMUSIC_OPEN = 0x63,
	COMMAND_SAFEZONEMUSIC_CLOSE = 0x64,

	COMMAND_SOS_CLEAR = 0x21,
	COMMAND_PHONEFARE_SELECT = 0x2A,
	COMMAND_AGPS_DOWNLOAD = 0x2B,

	COMMAND_BUZZER_DEVICE_OPEN = 0x81,
	COMMAND_BUZZER_DEVICE_CLOSE = 0x82,
	COMMAND_LIGHT1_DEVICE_OPEN = 0x83,
	COMMAND_LIGHT1_DEVICE_CLOSE = 0x84,
	COMMAND_LIGHT2_DEVICE_OPEN = 0x85,
	COMMAND_LIGHT2_DEVICE_CLOSE = 0x86,
	
	COMMAND_DEFAULT = 0xFF,
} control_command;

#endif


typedef struct _heart_package_data {
	char tele_number[TELE_NUMBER_LENGTH+4];
	char cmd;
} heart_package_data;

heart_package_data heart_info = {0};
char tele_fare[TELE_FARE_LENGTH] = {0};



#endif


