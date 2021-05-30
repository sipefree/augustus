#ifndef EVENTS_H
#define EVENTS_H

#include <stdint.h>
#include "core/lang.h"
#include "city/message.h"

#define MAX_CUSTOM_EVENTS 180
#define MAX_CONDITIONS 9

uint8_t MESSAGE_TEXT_OVERRIDE[512];

typedef enum {
	CONDITION_VALUE_MONTHS_PASSED,
	CONDITION_VALUE_RATING_CULTURE,
	CONDITION_VALUE_RATING_PEACE,
	CONDITION_VALUE_RATING_PROSPERITY,
	CONDITION_VALUE_RATING_FAVOR,
	CONDITION_VALUE_MONEY,
	CONDITION_VALUE_POPULATION,
	CONDITION_VALUE_TRADE_CITY_OPEN,
	CONDITION_VALUE_CITY_SENTIMENT,
	CONDITION_VALUE_PATRICIANS,
	CONDITION_VALUE_PERCENT_IN_TENTS,
	CONDITION_VALUE_PERCENT_PATRICIANS,
	CONDITION_VALUE_PERCENT_UNEMPLOYED,
	CONDITION_VALUE_ARMY_STRENGTH,
	CONDITION_VALUE_MAX_KEY
} condition_key;

typedef void (*EventActivationFunction)();
typedef int (*GetValueFunction)();

typedef enum {
	EVENT_TYPE_INVALID,
	EVENT_TYPE_DEMAND_CHANGE,
	EVENT_TYPE_PRICE_CHANGE,
	EVENT_TYPE_REQUEST,
	EVENT_TYPE_INVASION,
	EVENT_TYPE_UPRISING,
	EVENT_TYPE_DISTANT_BATTLE,
	EVENT_TYPE_WAGE_CHANGE,
	EVENT_TYPE_CITY_NOW_TRADES,
	EVENT_TYPE_MESSAGE,
	EVENT_TYPE_FESTIVAL,
	EVENT_TYPE_VICTORY,
	EVENT_TYPE_TRADE_INTERRUPTION,
	EVENT_TYPE_RIOTS,
	EVENT_TYPE_MAX_KEY
} event_key;

typedef struct {
	condition_key key;
	char value_type_string[24];
	GetValueFunction actual_value_function;

} condition_value;

typedef struct {
	char value[24];
	int requirement;
} event_condition;

typedef struct {
	event_key key;
	uint8_t event_type_string[24];
	EventActivationFunction activation_function;
	city_message_type city_message_type;
} custom_event_type;

typedef struct {
	char god_string[10];
	int god_id;
} god_mapping;

typedef struct {
	char text[1024];
	char header[128];
	char signature[128];
	char title[128];
	char sound[24];
	int advisor_id;
	int resource_id;
	int amount;
	int deadline_months;
	int favor_gained;
	char city_name[24];
	char type[24];
	int months_warning;
	int entrypoint_id;
	int message_id;
	int size;
	char god[10];
	int duration;
	int is_sea;
	int figures;

} custom_event_data;

typedef struct {
	custom_event_data event_data;
	event_condition conditions[MAX_CONDITIONS];
	int in_use;
	int fired;
	int chance_to_fire;
} custom_event;

custom_event custom_events[MAX_CUSTOM_EVENTS];

void custom_events_process();

void load_all_custom_messages();

#endif